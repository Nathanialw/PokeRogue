from PIL import Image
from python.data import NUM_COLORS, CUSTOM_PALETTE_565

# ---------------- CONFIG ----------------



# MODE = "optimum"      # "custom" or "optimum"
MODE = "custom"      # "custom" or "optimum"

# ---------------- SCALE CONFIG ----------------

SCALE_ENABLED = True

DEFAULT_TARGET_WIDTH = 112
DEFAULT_TARGET_HEIGHT = 112

INPUT_IMAGE  = "trans_output.png"
OUTPUT_IMAGE = f"col_indexed_output-{MODE}-{NUM_COLORS}.png"

INPUT_SIZE_TARGET_MAP = {
    (112, 112): (112, 112),  # If input is 112x112, keep as-is
    (160, 112): (160, 112),  # If input is 160x112, keep as-is
    (256, 256): (112, 112),  # If input is 256x256, scale down to 112x112
    (512, 512): (112, 112),  # If input is 512x512, scale down to 112x112
    (728, 512): (160, 112),  # If input is 728x512, scale to 160x112
    (736, 512): (160, 112),  # If input is 768x512, scale to 160x112
    (768, 512): (160, 112),  # If input is 768x512, scale to 160x112
    # Add more mappings as needed
}


# ---------------- RGB565 helpers ----------------

def rgb888_to_rgb565(r, g, b):
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

def rgb565_to_rgb888(v):
    r = (v >> 11) & 0x1F
    g = (v >> 5) & 0x3F
    b = v & 0x1F

    r = (r << 3) | (r >> 2)
    g = (g << 2) | (g >> 4)
    b = (b << 3) | (b >> 2)

    return (r, g, b)

# ---------------- Target size detection ----------------

def get_target_size(input_size):
    """
    Determine target dimensions based on input image size
    """
    if input_size in INPUT_SIZE_TARGET_MAP:
        return INPUT_SIZE_TARGET_MAP[input_size]
    else:
        print(f"Warning: Input size {input_size} not in predefined map. Using default {DEFAULT_TARGET_WIDTH}x{DEFAULT_TARGET_HEIGHT}")
        return DEFAULT_TARGET_WIDTH, DEFAULT_TARGET_HEIGHT


# ---------------- palette generation ----------------

def make_palette_from_565(palette565):

    palette_rgb = []

    for p in palette565:
        palette_rgb.extend(rgb565_to_rgb888(p))

    while len(palette_rgb) < 256*3:
        palette_rgb.extend((0,0,0))

    return palette_rgb

# ---------------- main ----------------

img = Image.open(INPUT_IMAGE).convert("RGB")


if SCALE_ENABLED:
    input_size = img.size
    print(f"Input image size: {input_size[0]}x{input_size[1]}")
    TARGET_WIDTH, TARGET_HEIGHT = get_target_size(input_size)
    img = img.resize((TARGET_WIDTH, TARGET_HEIGHT), Image.NEAREST)

if MODE == "optimum":

    # Pillow median-cut palette
    img_p = img.convert("P", palette=Image.ADAPTIVE, colors=NUM_COLORS)

    palette = img_p.getpalette()

    # convert palette to rgb565
    rgb565_palette = []
    for i in range(NUM_COLORS):
        r = palette[i*3]
        g = palette[i*3+1]
        b = palette[i*3+2]
        rgb565_palette.append(rgb888_to_rgb565(r,g,b))

    print("Generated RGB565 palette:")
    for i,p in enumerate(rgb565_palette):
        print(f"{i}: 0x{p:04X}")

    img_p.save(OUTPUT_IMAGE)

elif MODE == "custom":

    pal_img = Image.new("P", (1,1))
    pal_img.putpalette(make_palette_from_565(CUSTOM_PALETTE_565))

    img_p = img.quantize(palette=pal_img, dither=Image.NONE)

    img_p.save(OUTPUT_IMAGE)


print("Done.")