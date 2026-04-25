#!/usr/bin/env python3

import os
import hashlib

import torch
import multiprocessing as mp
from diffusers import StableDiffusionPipeline


import _settings


from _data import VARIANTS, BASE_PROMPT, NEGATIVE_PROMPT, CreaturesDict

# ---------------- CONFIG ----------------


torch.backends.cuda.matmul.allow_tf32 = True
torch.backends.cudnn.allow_tf32 = True

GPU_INDEX = 0

def stable_seed(name: str) -> int:
    h = hashlib.sha256(name.encode("utf-8")).hexdigest()
    return int(h[:8], 16)

def get_batch_size(gpu_index):
    props = torch.cuda.get_device_properties(gpu_index)
    vram_gb = props.total_memory / (1024**3)

    if vram_gb >= 15:
        return 6   # 4060 Ti 16GB
    else:
        return 4   # 4070 Super 12GB

def build_prompt(creature: dict, v: int) -> str:
    variant = VARIANTS[v % len(VARIANTS)]
    return f"{BASE_PROMPT}, {creature['prompt']}, {variant}"


def count_existing_pngs(out_dir: str) -> int:
    try:
        return sum(1 for f in os.listdir(out_dir) if f.endswith(".png"))
    except FileNotFoundError:
        return 0

def generate(pipe, device: str, creature: dict, v: int, existing: int):
    cn = creature["name"]
    out_dir = os.path.join(_settings.OUT_ROOT, cn)
    os.makedirs(out_dir, exist_ok=True)

    base = stable_seed(cn)
    idx = existing + v
    seed = (base + idx) & 0xFFFFFFFF

    if idx > _settings.MAX_IMAGES-1:
        return

    print(f"{cn}: #{idx} -- {_settings.MODEL_ALIAS[_settings.MODEL_IDX]}")

    generator = torch.Generator(device=device).manual_seed(seed)
    prompt = build_prompt(creature, v)

    with torch.inference_mode():
        image = pipe(
            prompt=prompt,
            negative_prompt=NEGATIVE_PROMPT,
            height=_settings.HEIGHT,
            width=_settings.WIDTH,
            guidance_scale=_settings.GUIDANCE_SCALE,
            num_inference_steps=_settings.STEPS,
            generator=generator,
        ).images[0]

    image.save(os.path.join(out_dir, f"{cn}_{_settings.MODEL_ALIAS[_settings.MODEL_IDX]}_{idx:03d}_s{seed}.png"))


def worker(gpu_index: int, job_queue):

    device = f"cuda:{gpu_index}"
    torch.cuda.set_device(gpu_index)

    batch_size = get_batch_size(gpu_index)

    print(f"GPU {gpu_index} loading model on {device} (batch={batch_size})")

    pipe = StableDiffusionPipeline.from_pretrained(
        _settings.MODEL_ID,
        torch_dtype=torch.float16,
        safety_checker=None,
        requires_safety_checker=False
    ).to(device)

    pipe.enable_attention_slicing()

    print(f"GPU {gpu_index} ready.")

    while True:
        job = job_queue.get()

        if job is None:
            break

        creature = CreaturesDict[job]

        cn = creature["name"]
        out_dir = os.path.join(_settings.OUT_ROOT, cn)
        os.makedirs(out_dir, exist_ok=True)

        existing = count_existing_pngs(out_dir)

        if existing > _settings.MAX_IMAGES - 1:
            continue

        remaining = _settings.NUM_VARIATIONS
        seed_offset = existing  # This is the starting offset
        base_seed = stable_seed(cn) & 0xFFFFFFFF

        while remaining > 0:
            batch = min(batch_size, remaining)

            # Calculate seeds for this batch
            current_seeds = [
                base_seed + seed_offset + i
                for i in range(batch)
            ]

            prompts = [
                build_prompt(creature, current_seeds[i])
                for i in range(batch)
            ]

            generators = [
                torch.Generator(device=device).manual_seed(current_seeds[i])
                for i in range(batch)
            ]

            result = pipe(
                prompts,
                generator=generators,
                height=_settings.HEIGHT,
                width=_settings.WIDTH,
                num_inference_steps=_settings.STEPS,
                guidance_scale=_settings.GUIDANCE_SCALE
            )

            for i, img in enumerate(result.images):
                save_index = existing + (_settings.NUM_VARIATIONS - remaining) + i
                filename = f"{cn}_{_settings.MODEL_ALIAS[_settings.MODEL_IDX]}_{save_index:03d}_s{current_seeds[i]}.png"
                print(f"saving image: {filename}")
                img.save(os.path.join(out_dir, filename))

            remaining -= batch
            seed_offset += batch  # Increment offset for next batc

    print(f"GPU {gpu_index} exiting")

def main(num_gpus=None):
    ctx = mp.get_context("spawn")

    if num_gpus is None:
        num_gpus = torch.cuda.device_count()

    print(f"Using {num_gpus} GPU(s)")

    job_queue = ctx.Queue()

    # enqueue jobs
    for i in range(len(CreaturesDict)):
        job_queue.put(i)

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