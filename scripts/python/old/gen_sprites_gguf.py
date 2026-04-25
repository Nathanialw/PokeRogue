import hashlib

from diffusers import AuraFlowPipeline, AuraFlowTransformer2DModel, GGUFQuantizationConfig
import torch
import multiprocessing as mp

from _data import VARIANTS, BASE_PROMPT, CreaturesDict
import argparse
import os

from _settings import OUT_ROOT

MODEL_ALIAS = "AuraFlow-v0.3"
STEPS = 50
HEIGHT = 1024
WIDTH = 1024
GUIDANCE_SCALE = 3.5


def parse_args():
    parser = argparse.ArgumentParser(description='AuraFlow image generation')
    # parser.add_argument('--gpu', type=int, default=0, help='GPU ID to use (default: 0)')
    # parser.add_argument('--height', type=int, default=1024, help='Image height (default: 1024)')
    # parser.add_argument('--width', type=int, default=1024, help='Image width (default: 1024)')
    # parser.add_argument('--steps', type=int, default=50, help='Number of inference steps (default: 50)')
    # parser.add_argument('--guidance', type=float, default=3.5, help='Guidance scale (default: 3.5)')
    # parser.add_argument('--seed', type=int, default=42, help='Random seed (default: 42)')
    # parser.add_argument('--output', type=str, default="auraflow_output.png", help='Output filename (default: auraflow_output.png)')
    return parser.parse_args()


def build_prompt(creature: dict, v: int) -> str:
    variant = VARIANTS[v % len(VARIANTS)]
    return f"{BASE_PROMPT}, {creature['prompt']}, {variant}"

def count_existing_pngs(out_dir: str) -> int:
    try:
        return sum(1 for f in os.listdir(out_dir) if f.endswith(".png"))
    except FileNotFoundError:
        return 0

def stable_seed(name: str) -> int:
    h = hashlib.sha256(name.encode("utf-8")).hexdigest()
    return int(h[:8], 16)

def get_batch_size(gpu_index):
    props = torch.cuda.get_device_properties(gpu_index)
    vram_gb = props.total_memory / (1024**3)

    if vram_gb >= 15:
        return 6   # 4060 Ti 16GB
    else:
        return 4   # 4070 Super 12GB / 3060 12GB


def worker(gpu_index: int, job_queue):
    args = parse_args()

    # Set up GPU-specific logging
    import sys
    print(f"\n=== GPU {gpu_index} started ===\n", flush=True)

    # Set the GPU device
    if torch.cuda.is_available():
        if gpu_index < torch.cuda.device_count():
            device = f"cuda:{gpu_index}"
            torch.cuda.set_device(gpu_index)
            print(f"[GPU {gpu_index}] Using: {torch.cuda.get_device_name(gpu_index)}", flush=True)
        else:
            print(f"[GPU {gpu_index}] Warning: GPU not available. Using GPU 0 instead.", flush=True)
            device = "cuda:0"
            torch.cuda.set_device(0)
    else:
        print("[GPU {gpu_index}] CUDA not available, using CPU", flush=True)
        device = "cpu"

    # Load transformer with GGUF
    transformer = AuraFlowTransformer2DModel.from_single_file(
        "/mnt/BED0BFC1D0BF7DE9/ggufs/aura_flow_0.3-Q6_K.gguf",
        quantization_config=GGUFQuantizationConfig(compute_dtype=torch.bfloat16),
        torch_dtype=torch.bfloat16,
    )

    # Load pipeline with progress bars disabled
    pipe = AuraFlowPipeline.from_pretrained(
        "fal/AuraFlow-v0.3",
        transformer=transformer,
        torch_dtype=torch.bfloat16,
        variant="fp16",
    )

    # Disable progress bars to prevent console interference
    pipe.set_progress_bar_config(disable=True)

    # Enable offloading to save VRAM
    pipe.enable_model_cpu_offload(gpu_id=gpu_index)

    device = f"cuda:{gpu_index}"
    torch.cuda.set_device(gpu_index)

    batch_size = get_batch_size(gpu_index)
    print(f"[GPU {gpu_index}] Batch size: {batch_size}", flush=True)

    while True:
        job = job_queue.get()

        if job is None:
            print(f"[GPU {gpu_index}] Shutting down", flush=True)
            break

        creature = CreaturesDict[job]
        cn = creature["name"]
        out_dir = os.path.join(OUT_ROOT, cn)
        os.makedirs(out_dir, exist_ok=True)

        existing = count_existing_pngs(out_dir)
        remaining = len(VARIANTS)

        print(f"[GPU {gpu_index}] Processing {cn}: {remaining} variants", flush=True)

        seed_offset = existing
        base_seed = stable_seed(cn) & 0xFFFFFFFF

        while remaining > 0:
            batch = min(batch_size, remaining)
            current_seeds = [base_seed + seed_offset + i for i in range(batch)]

            prompts = [build_prompt(creature, current_seeds[i]) for i in range(batch)]

            generators = [torch.Generator(device=device).manual_seed(current_seeds[i]) for i in range(batch)]

            print(f"[GPU {gpu_index}] Generating batch of {batch} images...", flush=True)
            max_retries = 3
            retry_count = 0
            current_batch = batch

            while retry_count < max_retries:
                try:
                    result = pipe(
                        prompts,
                        generator=generators,
                        height=HEIGHT,
                        width=WIDTH,
                        num_inference_steps=STEPS,
                        guidance_scale=GUIDANCE_SCALE
                    )

                    # If successful, process images and break retry loop
                    for i, img in enumerate(result.images):
                        save_index = existing + (len(VARIANTS) - remaining) + i
                        filename = f"{cn}_{MODEL_ALIAS}_{save_index:03d}_s{current_seeds[i]}.png"
                        img.save(os.path.join(out_dir, filename))
                        print(f"[GPU {gpu_index}] Saved: {filename}", flush=True)

                    # Success - update remaining and break retry loop
                    remaining -= current_batch
                    seed_offset += current_batch
                    break

                except torch.cuda.OutOfMemoryError as e:
                    print(f"[GPU {gpu_index}] CUDA OOM: {e}", flush=True)
                    if current_batch > 1:
                        # Reduce batch size and retry
                        current_batch = max(1, current_batch // 2)
                        retry_count += 1
                        print(f"[GPU {gpu_index}] Reducing batch to {current_batch} and retrying...", flush=True)

                        # Recalculate prompts and generators for smaller batch
                        current_seeds = current_seeds[:current_batch]
                        prompts = prompts[:current_batch]
                        generators = generators[:current_batch]
                    else:
                        print(f"[GPU {gpu_index}] Cannot reduce batch further, skipping", flush=True)
                        remaining -= current_batch
                        seed_offset += current_batch
                        break

                except Exception as e:
                    print(f"[GPU {gpu_index}] Unexpected error: {e}", flush=True)
                    retry_count += 1
                    if retry_count >= max_retries:
                        print(f"[GPU {gpu_index}] Max retries reached, skipping batch", flush=True)
                        remaining -= current_batch
                        seed_offset += current_batch
                        break

                    # Wait a bit before retrying
                    import time
                    time.sleep(2)



def main(num_gpus=None):
    ctx = mp.get_context("spawn")

    if num_gpus is None:
        num_gpus = torch.cuda.device_count()

    print(f"Using {num_gpus} GPU(s)")

    job_queue = ctx.Queue()

    # enqueue jobs
    for i in range(len(CreaturesDict)):
        job_queue.put((len(CreaturesDict) - 1) - i)

    # send shutdown signals
    for _ in range(num_gpus):
        job_queue.put(None)

    workers = []

    for gpu in range(num_gpus):
        p = ctx.Process(target=worker, args=(gpu, job_queue))
        p.start()
        workers.append(p)

    for p in workers:
        p.join()



if __name__ == "__main__":
    main(2)