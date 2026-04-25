from PIL import Image
from _data import NUM_COLORS, CUSTOM_PALETTE_565

# ---------------- CONFIG ----------------

# MODE = "optimum"      # "custom" or "optimum"
MODE = "custom"  # "custom" or "optimum"

# ---------------- SCALE CONFIG ----------------

SCALE_ENABLED = True

DEFAULT_TARGET_WIDTH = 112
DEFAULT_TARGET_HEIGHT = 112

INPUT_IMAGE = "trans_output.png"
OUTPUT_IMAGE = f"col_indexed_output-{MODE}-{NUM_COLORS}.png"

INPUT_SIZE_TARGET_MAP = {
    (112, 112): (112, 112),  # If input is 112x112, keep as-is
    (160, 112): (160, 112),  # If input is 160x112, keep as-is
    (256, 256): (112, 112),  # If input is 256x256, scale down to 112x112
    (512, 512): (112, 112),  # If input is 512x512, scale down to 112x112
    (728, 512): (160, 112),  # If input is 728x512, scale to 160x112
    (736, 512): (160, 112),  # If input is 768x512, scale to 160x112
    (768, 512): (160, 112),  # If input is 768x512, scale to 160x112
    (1024, 1024): (112, 112),  # If input is 512x512, scale down to 112x112

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


# ---------------- Alpha to Magenta conversion ----------------

def alpha_to_magenta(img):
    """
    Convert fully transparent pixels (alpha=0) to magenta (255,0,255)
    Keep other pixels as-is
    """
    # Convert to RGBA if not already
    if img.mode != 'RGBA':
        if img.mode == 'P' or img.mode == 'L':
            img = img.convert('RGBA')
        else:
            img = img.convert('RGBA')

    # Get data as numpy array for faster processing
    import numpy as np
    data = np.array(img)

    # Find pixels with alpha = 0 (fully transparent)
    alpha_zero_mask = data[:, :, 3] == 0

    # Set those pixels to magenta (255,0,255) with full opacity
    data[alpha_zero_mask, 0] = 255  # R
    data[alpha_zero_mask, 1] = 0  # G
    data[alpha_zero_mask, 2] = 255  # B
    data[alpha_zero_mask, 3] = 255  # A (fully opaque)

    # Convert back to PIL Image
    return Image.fromarray(data)


def process_alpha_without_numpy(img):
    """
    Alternative version that doesn't require numpy
    Slower but no dependencies
    """
    # Convert to RGBA if not already
    if img.mode != 'RGBA':
        img = img.convert('RGBA')

    # Create a new image
    new_img = Image.new('RGBA', img.size)
    pixels = new_img.load()
    orig_pixels = img.load()

    width, height = img.size

    for y in range(height):
        for x in range(width):
            r, g, b, a = orig_pixels[x, y]
            if a == 0:  # Fully transparent
                pixels[x, y] = (255, 0, 255, 255)  # Magenta, fully opaque
            else:
                pixels[x, y] = (r, g, b, 255)  # Keep original RGB, make opaque

    return new_img


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

    while len(palette_rgb) < 256 * 3:
        palette_rgb.extend((0, 0, 0))

    return palette_rgb


# ---------------- main ----------------

# Open image
img = Image.open(INPUT_IMAGE)

# Check if image has transparency and convert fully transparent pixels to magenta
if img.mode in ('RGBA', 'LA', 'P') or (img.mode == 'P' and 'transparency' in img.info):
    print("Image has transparency. Converting fully transparent pixels to magenta...")
    try:
        # Try using numpy version (faster)
        img = alpha_to_magenta(img)
    except ImportError:
        # Fall back to pure PIL version if numpy not available
        print("Numpy not available, using slower method...")
        img = process_alpha_without_numpy(img)
else:
    # If no transparency, just convert to RGB
    print("No transparency detected.")
    img = img.convert("RGB")

if SCALE_ENABLED:
    input_size = img.size
    print(f"Input image size: {input_size[0]}x{input_size[1]}")
    TARGET_WIDTH, TARGET_HEIGHT = get_target_size(input_size)
    img = img.resize((TARGET_WIDTH, TARGET_HEIGHT), Image.NEAREST)

# Convert to RGB mode for quantization (required by PIL)
print("Converting to RGB mode for quantization...")
img_rgb = img.convert("RGB")

if MODE == "optimum":
    # Pillow median-cut palette
    img_p = img_rgb.convert("P", palette=Image.ADAPTIVE, colors=NUM_COLORS)

    palette = img_p.getpalette()

    # convert palette to rgb565
    rgb565_palette = []
    for i in range(NUM_COLORS):
        r = palette[i * 3]
        g = palette[i * 3 + 1]
        b = palette[i * 3 + 2]
        rgb565_palette.append(rgb888_to_rgb565(r, g, b))

    print("Generated RGB565 palette:")
    for i, p in enumerate(rgb565_palette):
        print(f"{i}: 0x{p:04X}")

    img_p.save(OUTPUT_IMAGE)

elif MODE == "custom":
    pal_img = Image.new("P", (1, 1))
    pal_img.putpalette(make_palette_from_565(CUSTOM_PALETTE_565))

    # Use RGB image for quantization
    img_p = img_rgb.quantize(palette=pal_img, dither=Image.NONE)

    img_p.save(OUTPUT_IMAGE)

print(f"Done. Saved to {OUTPUT_IMAGE}")