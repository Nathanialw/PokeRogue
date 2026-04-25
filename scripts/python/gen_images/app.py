# deploy on local network server

from flask import Flask, request, jsonify, send_file
from diffusers import AuraFlowPipeline, AuraFlowTransformer2DModel, GGUFQuantizationConfig
import torch
import multiprocessing as mp
import threading
import hashlib
import os
import time
import uuid
from typing import Optional, Dict, List
import atexit
import argparse
from dataclasses import dataclass
from enum import Enum
import logging

from data._item_img_data import VARIANTS, BASE_PROMPT, ItemsDict
from data._spell_img_data import VARIANTS, BASE_PROMPT, SpellsDict
from data._creature_img_data import VARIANTS, BASE_PROMPT, CreaturesDict
from data._skill_img_data import VARIANTS, BASE_PROMPT, SkillsDict
from data._object_img_data import VARIANTS, BASE_PROMPT, ObjectsDict
from config.settings import OUT_ROOT
import config.settings as settings

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

app = Flask(__name__)

MODEL_IDX = 0
MODEL_ALIAS = settings.MODEL_ALIAS[MODEL_IDX]
DEFAULT_STEPS = settings.DEFAULT_STEPS[MODEL_IDX]
DEFAULT_HEIGHT = settings.DEFAULT_IMAGE_SIZE[MODEL_IDX]['x']
DEFAULT_WIDTH = settings.DEFAULT_IMAGE_SIZE[MODEL_IDX]['y']
DEFAULT_GUIDANCE_SCALE = settings.DEFAULT_GUIDANCE_SCALE[MODEL_IDX]
MODEL_PATH = settings.MODEL_ADDRESS[MODEL_IDX]

# Map object types to their dictionaries
OBJECT_TYPE_DICT = {
    'creature': CreaturesDict,
    'spell': SpellsDict,
    'skill': SkillsDict,
    'item': ItemsDict,
    'object': ObjectsDict
}


# Job status tracking
class JobStatus(Enum):
    PENDING = "pending"
    PROCESSING = "processing"
    COMPLETED = "completed"
    FAILED = "failed"


@dataclass
class GenerationJob:
    id: str
    object_type: str
    object_name: str
    num_variants: int
    gpu_id: int
    status: JobStatus
    progress: int
    output_files: List[str]
    error: Optional[str] = None
    created_at: float = time.time()
    completed_at: Optional[float] = None
    params: dict = None


# Global state - will be initialized in main()
job_queue = None
workers = []
jobs: Dict[str, GenerationJob] = {}
jobs_lock = threading.Lock()
num_gpus = 0


# GPU worker functions
def build_prompt(object_data: dict, variant_index: int) -> str:
    variant = VARIANTS[variant_index % len(VARIANTS)]
    return f"{BASE_PROMPT}, {object_data['prompt']}, {variant}"


def count_existing_pngs(out_dir: str) -> int:
    try:
        return sum(1 for f in os.listdir(out_dir) if f.endswith(".png"))
    except FileNotFoundError:
        return 0


def stable_seed(name: str) -> int:
    h = hashlib.sha256(name.encode("utf-8")).hexdigest()
    return int(h[:8], 16)


def get_batch_size(gpu_index: int) -> int:
    props = torch.cuda.get_device_properties(gpu_index)
    vram_gb = props.total_memory / (1024 ** 3)

    if vram_gb >= 15:
        return 6  # 16GB cards
    else:
        return 4  # 12GB cards


def worker_process(gpu_index: int, job_queue_, model_path, out_root):
    """Worker process that handles generation jobs"""
    logger.info(f"GPU {gpu_index} worker started")

    # Set device
    if torch.cuda.is_available() and gpu_index < torch.cuda.device_count():
        device = f"cuda:{gpu_index}"
        torch.cuda.set_device(gpu_index)
        logger.info(f"GPU {gpu_index}: {torch.cuda.get_device_name(gpu_index)}")
    else:
        logger.error(f"GPU {gpu_index} not available")
        return

    # Load model once per worker
    try:
        transformer = AuraFlowTransformer2DModel.from_single_file(
            model_path,
            quantization_config=GGUFQuantizationConfig(compute_dtype=torch.bfloat16),
            torch_dtype=torch.bfloat16,
        )

        pipe = AuraFlowPipeline.from_pretrained(
            "fal/AuraFlow-v0.3",
            transformer=transformer,
            torch_dtype=torch.bfloat16,
            variant="fp16",
        )

        pipe.set_progress_bar_config(disable=True)
        pipe.enable_model_cpu_offload(gpu_id=gpu_index)

        batch_size = get_batch_size(gpu_index)
        logger.info(f"GPU {gpu_index} batch size: {batch_size}")

    except Exception as e:
        logger.error(f"GPU {gpu_index} failed to load model: {e}")
        return

    # Process jobs
    while True:
        try:
            job_data = job_queue_.get()
            if job_data is None:  # Shutdown signal
                break

            job_id, object_type, object_name, params = job_data

            # Update job status
            with jobs_lock:
                if job_id in jobs:
                    jobs[job_id].status = JobStatus.PROCESSING
                    jobs[job_id].gpu_id = gpu_index

            # Process the job
            # Find the object in the appropriate dictionary
            object_dict = OBJECT_TYPE_DICT.get(object_type)
            if not object_dict:
                logger.error(f"Invalid object type: {object_type}")
                with jobs_lock:
                    if job_id in jobs:
                        jobs[job_id].status = JobStatus.FAILED
                        jobs[job_id].error = f"Invalid object type: {object_type}"
                continue

            object_info = None
            for obj in object_dict:
                if obj["name"] == object_name:
                    object_info = obj
                    break

            if not object_info:
                logger.error(f"{object_type} {object_name} not found in dictionary")
                with jobs_lock:
                    if job_id in jobs:
                        jobs[job_id].status = JobStatus.FAILED
                        jobs[job_id].error = f"{object_type} {object_name} not found"
                continue

            # Create output directory
            out_dir = os.path.join(out_root, object_type, object_name)
            os.makedirs(out_dir, exist_ok=True)

            existing = count_existing_pngs(out_dir)
            num_variants = params.get('num_variants', len(VARIANTS))
            remaining = num_variants

            seed_offset = existing
            base_seed = stable_seed(f"{object_type}_{object_name}") & 0xFFFFFFFF

            output_files = []

            # Generation parameters
            height = params.get('height', DEFAULT_HEIGHT)
            width = params.get('width', DEFAULT_WIDTH)
            steps = params.get('steps', DEFAULT_STEPS)
            guidance_scale = params.get('guidance_scale', DEFAULT_GUIDANCE_SCALE)

            while remaining > 0:
                batch = min(batch_size, remaining)
                current_seeds = [base_seed + seed_offset + i for i in range(batch)]
                prompts = [build_prompt(object_info, current_seeds[i]) for i in range(batch)]
                generators = [torch.Generator(device=device).manual_seed(current_seeds[i]) for i in range(batch)]

                logger.info(f"GPU {gpu_index} generating batch of {batch} for {object_type}/{object_name}")

                max_retries = 3
                retry_count = 0
                current_batch = batch

                while retry_count < max_retries:
                    try:
                        result = pipe(
                            prompts,
                            generator=generators,
                            height=height,
                            width=width,
                            num_inference_steps=steps,
                            guidance_scale=guidance_scale
                        )

                        for i, img in enumerate(result.images):
                            save_index = existing + (num_variants - remaining) + i
                            filename = f"{object_name}_{MODEL_ALIAS}_{save_index:03d}_s{current_seeds[i]}.png"
                            filepath = os.path.join(out_dir, filename)
                            img.save(filepath)
                            output_files.append(filepath)
                            logger.info(f"GPU {gpu_index} saved: {filename}")

                        remaining -= current_batch
                        seed_offset += current_batch

                        # Update progress
                        with jobs_lock:
                            if job_id in jobs:
                                jobs[job_id].progress = int(((num_variants - remaining) / num_variants) * 100)
                                jobs[job_id].output_files = output_files

                        break

                    except torch.cuda.OutOfMemoryError:
                        logger.warning(f"GPU {gpu_index} OOM, reducing batch")
                        if current_batch > 1:
                            current_batch = max(1, current_batch // 2)
                            retry_count += 1
                            current_seeds = current_seeds[:current_batch]
                            prompts = prompts[:current_batch]
                            generators = generators[:current_batch]
                        else:
                            remaining -= current_batch
                            seed_offset += current_batch
                            break

                    except Exception as e:
                        logger.error(f"GPU {gpu_index} error: {e}")
                        retry_count += 1
                        if retry_count >= max_retries:
                            remaining -= current_batch
                            seed_offset += current_batch
                            break
                        time.sleep(2)

            # Job complete
            with jobs_lock:
                if job_id in jobs:
                    jobs[job_id].status = JobStatus.COMPLETED
                    jobs[job_id].completed_at = time.time()
                    jobs[job_id].output_files = output_files

        except Exception as e:
            logger.error(f"Worker {gpu_index} crashed: {e}")
            with jobs_lock:
                if job_id in jobs:
                    jobs[job_id].status = JobStatus.FAILED
                    jobs[job_id].error = str(e)


def init_workers(gpu_count=None):
    """Initialize the worker processes"""
    global job_queue, workers, num_gpus

    num_gpus = gpu_count if gpu_count else torch.cuda.device_count()

    ctx = mp.get_context("spawn")
    job_queue = ctx.Queue()

    # Start workers
    for gpu in range(num_gpus):
        p = ctx.Process(
            target=worker_process,
            args=(gpu, job_queue, MODEL_PATH, OUT_ROOT)
        )
        p.start()
        workers.append(p)

    logger.info(f"Started {num_gpus} worker processes")
    return num_gpus


def shutdown_workers():
    """Clean shutdown of workers"""
    global job_queue, workers

    if job_queue:
        for _ in range(len(workers)):
            job_queue.put(None)

    for p in workers:
        p.join(timeout=5)
        if p.is_alive():
            p.terminate()

    logger.info("All workers shut down")


# Flask routes
@app.route('/health', methods=['GET'])
def health_check():
    """Health check endpoint"""
    return jsonify({
        'status': 'healthy',
        'gpus': num_gpus,
        'workers_alive': sum(1 for p in workers if p.is_alive()),
        'queue_size': job_queue.qsize() if job_queue else 0
    })


@app.route('/gpus', methods=['GET'])
def list_gpus():
    """List available GPUs"""
    gpus = []
    for i in range(num_gpus):
        props = torch.cuda.get_device_properties(i)
        gpus.append({
            'id': i,
            'name': props.name,
            'vram_gb': round(props.total_memory / (1024 ** 3), 1),
            'batch_size': get_batch_size(i)
        })
    return jsonify(gpus)


@app.route('/objects', methods=['GET'])
def list_objects():
    """List all available objects (creatures, spells, skills, items)"""
    result = {}
    for obj_type, obj_dict in OBJECT_TYPE_DICT.items():
        result[obj_type] = [{
            'name': obj['name'],
            'prompt': obj['prompt']
        } for obj in obj_dict]
    return jsonify(result)


@app.route('/objects/<object_type>', methods=['GET'])
def list_objects_by_type(object_type):
    """List objects by type"""
    if object_type not in OBJECT_TYPE_DICT:
        return jsonify({'error': f'Unknown object type: {object_type}'}), 400

    return jsonify([{
        'name': obj['name'],
        'prompt': obj['prompt']
    } for obj in OBJECT_TYPE_DICT[object_type]])


@app.route('/generate', methods=['POST'])
def generate():
    """Submit a generation job"""
    data = request.json

    # Validate required fields
    if 'object_type' not in data:
        return jsonify({'error': 'Missing object_type parameter'}), 400

    if 'object_name' not in data:
        return jsonify({'error': 'Missing object_name parameter'}), 400

    object_type = data['object_type']
    object_name = data['object_name']

    if object_type not in OBJECT_TYPE_DICT:
        return jsonify({'error': f'Unknown object type: {object_type}'}), 400

    # Check if object exists
    object_dict = OBJECT_TYPE_DICT[object_type]
    if object_name not in [obj['name'] for obj in object_dict]:
        return jsonify({'error': f'Unknown {object_type}: {object_name}'}), 400

    # Optional parameters with defaults
    params = {
        'num_variants': data.get('num_variants', len(VARIANTS)),
        'height': data.get('height', DEFAULT_HEIGHT),
        'width': data.get('width', DEFAULT_WIDTH),
        'steps': data.get('steps', DEFAULT_STEPS),
        'guidance_scale': data.get('guidance_scale', DEFAULT_GUIDANCE_SCALE),
    }

    # Validate parameters
    if params['num_variants'] < 1 or params['num_variants'] > len(VARIANTS):
        return jsonify({'error': f'num_variants must be between 1 and {len(VARIANTS)}'}), 400

    # Create job
    job_id = str(uuid.uuid4())

    with jobs_lock:
        jobs[job_id] = GenerationJob(
            id=job_id,
            object_type=object_type,
            object_name=object_name,
            num_variants=params['num_variants'],
            gpu_id=-1,
            status=JobStatus.PENDING,
            progress=0,
            output_files=[],
            params=params
        )

    # Queue the job
    if job_queue:
        job_queue.put((job_id, object_type, object_name, params))
        logger.info(f"Queued job {job_id} for {object_type}/{object_name}")
    else:
        return jsonify({'error': 'Worker queue not initialized'}), 500

    return jsonify({
        'job_id': job_id,
        'status': 'pending',
        'message': f'Generation job queued for {object_type}/{object_name}'
    }), 202


@app.route('/jobs/<job_id>', methods=['GET'])
def get_job(job_id):
    """Get job status"""
    with jobs_lock:
        job = jobs.get(job_id)

    if not job:
        return jsonify({'error': 'Job not found'}), 404

    return jsonify({
        'id': job.id,
        'object_type': job.object_type,
        'object_name': job.object_name,
        'status': job.status.value,
        'progress': job.progress,
        'gpu_id': job.gpu_id,
        'output_files': job.output_files,
        'error': job.error,
        'created_at': job.created_at,
        'completed_at': job.completed_at,
        'params': job.params
    })


@app.route('/jobs', methods=['GET'])
def list_jobs():
    """List all jobs"""
    with jobs_lock:
        job_list = [{
            'id': j.id,
            'object_type': j.object_type,
            'object_name': j.object_name,
            'status': j.status.value,
            'progress': j.progress,
            'created_at': j.created_at,
            'completed_at': j.completed_at
        } for j in jobs.values()]

    return jsonify(job_list)


@app.route('/download/<object_type>/<object_name>/<filename>', methods=['GET'])
def download_file(object_type, object_name, filename):
    """Download a generated image"""
    # Construct path with object type
    file_path = os.path.join(object_type, object_name, filename)
    full_path = os.path.abspath(os.path.join(OUT_ROOT, file_path))

    if not full_path.startswith(os.path.abspath(OUT_ROOT)):
        return jsonify({'error': 'Access denied'}), 403

    if not os.path.exists(full_path):
        return jsonify({'error': 'File not found'}), 404

    return send_file(full_path, as_attachment=True)


@app.route('/cancel/<job_id>', methods=['POST'])
def cancel_job(job_id):
    """Cancel a pending job"""
    with jobs_lock:
        job = jobs.get(job_id)
        if not job:
            return jsonify({'error': 'Job not found'}), 404

        if job.status == JobStatus.PENDING:
            job.status = JobStatus.FAILED
            job.error = "Cancelled by user"
            return jsonify({'message': 'Job cancelled'})
        elif job.status == JobStatus.PROCESSING:
            return jsonify({'error': 'Cannot cancel a running job'}), 400
        else:
            return jsonify({'error': f'Job is already {job.status.value}'}), 400


@app.route('/files/', methods=['GET'])
@app.route('/files/<path:subpath>', methods=['GET'])
def list_files(subpath=""):
    """List files in a directory on the server"""
    try:
        target_dir = os.path.join(OUT_ROOT, subpath) if subpath else OUT_ROOT
        abs_target = os.path.abspath(target_dir)

        if not abs_target.startswith(os.path.abspath(OUT_ROOT)):
            return jsonify({'error': 'Access denied'}), 403

        if not os.path.exists(abs_target):
            return jsonify({'error': 'Directory not found'}), 404

        if not os.path.isdir(abs_target):
            return jsonify({'error': 'Not a directory'}), 400

        files = []
        directories = []

        for item in os.listdir(abs_target):
            item_path = os.path.join(abs_target, item)
            stat = os.stat(item_path)

            if os.path.isdir(item_path):
                # Count PNG files in this directory
                file_count = 0
                try:
                    file_count = sum(1 for f in os.listdir(item_path) if f.endswith('.png'))
                except:
                    pass

                directories.append({
                    'name': item,
                    'path': os.path.join(subpath, item) if subpath else item,
                    'modified': stat.st_mtime,
                    'file_count': file_count
                })
            else:
                files.append({
                    'name': item,
                    'path': os.path.join(subpath, item) if subpath else item,
                    'size': stat.st_size,
                    'modified': stat.st_mtime
                })

        # Sort directories and files alphabetically by name
        directories.sort(key=lambda x: x['name'])
        files.sort(key=lambda x: x['name'])

        return jsonify({
            'files': files,
            'directories': directories
        })

    except Exception as e:
        return jsonify({'error': str(e)}), 500


if __name__ == '__main__':
    mp.freeze_support()  # For Windows compatibility, doesn't hurt on Linux

    parser = argparse.ArgumentParser(description='AuraFlow Flask Server')
    parser.add_argument('--host', type=str, default='0.0.0.0', help='Host to bind to')
    parser.add_argument('--port', type=int, default=5000, help='Port to bind to')
    parser.add_argument('--debug', action='store_true', help='Enable debug mode')
    parser.add_argument('--gpus', type=int, default=None, help='Number of GPUs to use')

    args = parser.parse_args()

    # Initialize workers here, inside the main guard
    num_gpus = init_workers(args.gpus)

    # Register shutdown handler
    atexit.register(shutdown_workers)

    # Run Flask
    app.run(host=args.host, port=args.port, debug=args.debug, threaded=True)
