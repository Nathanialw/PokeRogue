from diffusers import AuraFlowPipeline, AuraFlowTransformer2DModel, GGUFQuantizationConfig
import torch

MODEL_ALIAS = "AuraFlow-v0.3"
STEPS = 5
HEIGHT = 1024
WIDTH = 1024
GUIDANCE_SCALE = 3.5

prompts = ["a wheat field", "a corn field", "a rice paddy"]

# Load transformer with GGUF
transformer = AuraFlowTransformer2DModel.from_single_file(
    "/mnt/BED0BFC1D0BF7DE9/ggufs/aura_flow_0.3-Q6_K.gguf",
    quantization_config=GGUFQuantizationConfig(compute_dtype=torch.bfloat16),
    torch_dtype=torch.bfloat16,
)

# Load pipeline
pipe = AuraFlowPipeline.from_pretrained(
    "fal/AuraFlow-v0.3",
    transformer=transformer,
    torch_dtype=torch.bfloat16,
    variant="fp16",
)

# Enable CPU offloading to save VRAM
pipe.enable_model_cpu_offload(gpu_id=1)

# Set device
device = f"cuda:1"
torch.cuda.set_device(1)

# Or with different seeds
seeds = [42, 43, 44]
generators = [torch.Generator(device=device).manual_seed(s) for s in seeds]


# Generate
result = pipe(
    prompts,
    generator=generators,
    height=HEIGHT,
    width=WIDTH,
    num_inference_steps=STEPS,
    guidance_scale=GUIDANCE_SCALE
)

# Save all
for i, img in enumerate(result.images):
    img.save(f"field_{i}.png")



