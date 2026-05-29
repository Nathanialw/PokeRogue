DOWNLOAD_ADDRESS = [
    "",
    "",
    "",
    "",
    "",
    "",
    "",
]

MODEL_ADDRESS = [
    "models/aura_flow_0.3-Q2_K.gguf",  #                ok not great                768x512
    "SG161222/Realistic_Vision_V5.1_noVAE",  #          ok not great                768x512
    "SG161222/Realistic_Vision_V6.0_B1_noVAE",  #       3.7gb vram NSFW PROTECTION  512x512
    "CompVis/stable-diffusion-v1-4",  #                 2.6gb vram                  768x512
    "stabilityai/stable-diffusion-xl-base-1.0",  # //   needs its own code          1024x512
    "black-forest-labs/FLUX.1-schnell",  #              needs own code
    "black-forest-labs/FLUX.1-dev",  # //               needs own code              1024x1024
]

MODEL_ALIAS = [
    "AuraFlow-v0.3",
    "Realistic_Vision_V5",
    "Realistic_Vision_V6",
    "stable_diffusion_v1_4",
    "stable_diffusion_xl_base",
    "FLUX_schnell",
    "FLUX1_dev",
]

DEFAULT_IMAGE_SIZE = [
    {'x': 1024, 'y': 1024},
    {'x': 768, 'y': 512},
    {'x': 512, 'y': 512},
    {'x': 768, 'y': 512},
    {'x': 1024, 'y': 512},
    {'x': 1024, 'y': 1024},
]

DEFAULT_GUIDANCE_SCALE = [
    3.5,
    9,
    5.5,
    3.5,
    3.5,
    3.5,
]

DEFAULT_STEPS = [
    100,
    50,
    100,
    50,
    50,
    50,
]

OUT_ROOTS = [
    "",
    "",
    "",
    "",
    "",
    "",
    "",
]

MAX_IMAGES = 1
MODEL_IDX = 0
OUT_ROOT = "./images"

SVR_ADDRESS = 'http://192.168.0.119:5000'
# SVR_ADDRESS = 'http://0.0.0.0:5000'
DOWNLOAD_FOLDER = '../assets_raw/sprites'

# NUM_VARIATIONS = 10   # images per creature
