import torch
import os
from ffcount import ffcount
from diffusers import DiffusionPipeline

tiles_folder = "../assets_raw/sprites/tile"

prompts = {
    "ACID": "smlstxtr, A pattern of bubbling acid in green, white and black, seamless texture",
    "CRYSTAL": "smlstxtr, A pattern of crystalline formations in amethyst purple, seamless texture",
    "FLOOR_CASTLE": "smlstxtr, A pattern of ancient castle floor with stones in gray and green, seamless texture",
    "FLOOR_WOOD": "smlstxtr, A pattern of wooden floor with long planks and wood grain in dark-brown and brown, seamless texture",
    "GROUND": "smlstxtr, A pattern of cave dirt ground in black and brown, seamless texture",
    "LAVA": "smlstxtr, A pattern of flowing lava in orange, red and black, seamless texture",
    "MEADOW": "smlstxtr, A pattern of flowered meadow grass in green yellow and purple, seamless texture",
    "RIVER_FROZEN": "smlstxtr, A pattern of frozen river surface with ice layers in blue, white and gray, seamless texture",
    "SNOW": "smlstxtr, A pattern of frozen tundra in white and gray, seamless texture",
    "VOLCANIC": "smlstxtr, A pattern of volcanic ground in black red and gray, seamless texture",
    "WALL_BRICK": "smlstxtr, A pattern of old brick wall in red and brown with mortar lines, seamless texture",
    "WALL_CASTLE": "smlstxtr, A pattern of ancient castle wall with moss and stones in gray and green, seamless texture",
    "WALL_ICE": "smlstxtr, A pattern of icy wall with frost and cracks in white and pale blue, seamless texture",
    "WALL_STONE": "smlstxtr, A pattern of a Stone Wall in Gray and Brown, seamless texture",
    "WALL_WOOD": "smlstxtr, A pattern of wooden wall with long planks and wood grain in brown and black, seamless texture",
    "WATER": "smlstxtr, A pattern of river water in water blue, seamless texture",
}


def main():
    # 1. Load in bfloat16 (saves memory) – the model stays on CPU initially
    pipe = DiffusionPipeline.from_pretrained(
        "black-forest-labs/FLUX.1-dev",
        torch_dtype=torch.bfloat16,
    )

    # 2. Enable sequential CPU offloading (NO pipe.to('cuda') !)
    pipe.enable_sequential_cpu_offload()

    # 3. Load the LoRA weights (offloader handles device placement)
    pipe.load_lora_weights("gokaygokay/Flux-Seamless-Texture-LoRA")

    if not os.path.exists(tiles_folder):
        os.mkdir(tiles_folder)

    # 4. Generate
    while True:
        for prompt_key, prompt_text in prompts.items():
            d = f"{tiles_folder}/{prompt_key}"
            if not os.path.exists(d):
                os.mkdir(d)

            files, dirs = ffcount(d)
            print(f"Generating texture for '{prompt_key}': {prompt_text}")
            image = pipe(prompt_text).images[0]
            image.save(f"{d}/{prompt_key}_{files}.png")


if __name__ == "__main__":
    main()
