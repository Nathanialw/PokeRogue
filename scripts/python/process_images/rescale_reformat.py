#!/usr/bin/env python3
"""
batch_indexed_converter.py

Recursively processes all images in a folder, converting them to indexed color
with transparency converted to magenta, and resizing based on input dimensions.
Maintains the same folder structure in the output directory.
"""

import os
import sys
from PIL import Image
from settings import NUM_COLORS, CUSTOM_PALETTE_565
import time
from pathlib import Path

# ---------------- Keep your existing config ----------------

MODE = "optimum"      # "custom" or "optimum"
# MODE = "custom"  # "custom" or "optimum"

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
    (1024, 1024): (112, 112),  # If input is 1024x1024, scale down to 112x112
    # Add more mappings as needed
}

# Image extensions to process
IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.bmp', '.tiff', '.webp'}


# ---------------- Keep ALL your existing helper functions exactly as they were ----------------

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


def get_target_size(input_size):
    """
    Determine target dimensions based on input image size
    """
    if input_size in INPUT_SIZE_TARGET_MAP:
        return INPUT_SIZE_TARGET_MAP[input_size]
    else:
        print(f"Warning: Input size {input_size} not in predefined map. Using default {DEFAULT_TARGET_WIDTH}x{DEFAULT_TARGET_HEIGHT}")
        return DEFAULT_TARGET_WIDTH, DEFAULT_TARGET_HEIGHT


def make_palette_from_565(palette565):
    palette_rgb = []

    for p in palette565:
        palette_rgb.extend(rgb565_to_rgb888(p))

    while len(palette_rgb) < 256 * 3:
        palette_rgb.extend((0, 0, 0))

    return palette_rgb


# ---------------- New batch processing function ----------------

def process_folder(input_folder, output_folder):
    """
    Recursively process all images in input_folder and save to output_folder
    """
    input_folder = os.path.abspath(input_folder)
    output_folder = os.path.abspath(output_folder)

    # Count total images first
    total_images = 0
    for root, dirs, files in os.walk(input_folder):
        for file in files:
            if os.path.splitext(file)[1].lower() in IMAGE_EXTENSIONS:
                total_images += 1

    print(f"Found {total_images} images to process in {input_folder}")
    print(f"Output folder: {output_folder}")
    print(f"Mode: {MODE}, Colors: {NUM_COLORS}, Scale enabled: {SCALE_ENABLED}")
    print("-" * 60)

    processed = 0
    skipped = 0
    failed = 0

    for root, dirs, files in os.walk(input_folder):
        # Calculate relative path from input folder
        rel_path = os.path.relpath(root, input_folder)
        if rel_path == '.':
            rel_path = ''

        # Process each image in current folder
        for file in files:
            if os.path.splitext(file)[1].lower() not in IMAGE_EXTENSIONS:
                continue

            input_path = os.path.join(root, file)

            # Create output path maintaining folder structure
            if rel_path:
                output_path = os.path.join(output_folder, rel_path, file)
            else:
                output_path = os.path.join(output_folder, file)

            # Check if output already exists and is newer than input
            if os.path.exists(output_path):
                input_mtime = os.path.getmtime(input_path)
                output_mtime = os.path.getmtime(output_path)
                if output_mtime > input_mtime:
                    print(f"⏩ Skipping (up to date): {rel_path}/{file}")
                    skipped += 1
                    continue

            print(f"\n▶ Processing: {rel_path}/{file}")

            try:
                # --- Your original image processing code, adapted to use input_path and output_path ---

                # Open image
                img = Image.open(input_path)

                # Check if image has transparency and convert fully transparent pixels to magenta
                if img.mode in ('RGBA', 'LA', 'P') or (img.mode == 'P' and 'transparency' in img.info):
                    print(f"  Transparency detected. Converting to magenta...")
                    try:
                        # Try using numpy version (faster)
                        img = alpha_to_magenta(img)
                    except ImportError:
                        # Fall back to pure PIL version if numpy not available
                        print("  Numpy not available, using slower method...")
                        img = process_alpha_without_numpy(img)
                else:
                    # If no transparency, just convert to RGB
                    img = img.convert("RGB")

                if SCALE_ENABLED:
                    input_size = img.size
                    print(f"  Input size: {input_size[0]}x{input_size[1]}")
                    TARGET_WIDTH, TARGET_HEIGHT = get_target_size(input_size)
                    img = img.resize((TARGET_WIDTH, TARGET_HEIGHT), Image.NEAREST)

                # Convert to RGB mode for quantization (required by PIL)
                img_rgb = img.convert("RGB")

                if MODE == "optimum":
                    # Pillow median-cut palette
                    img_p = img_rgb.convert("P", palette=Image.ADAPTIVE, colors=NUM_COLORS)

                    # Optional: print palette info if needed
                    # palette = img_p.getpalette()
                    # rgb565_palette = []
                    # for i in range(NUM_COLORS):
                    #     r = palette[i * 3]
                    #     g = palette[i * 3 + 1]
                    #     b = palette[i * 3 + 2]
                    #     rgb565_palette.append(rgb888_to_rgb565(r, g, b))

                elif MODE == "custom":
                    pal_img = Image.new("P", (1, 1))
                    pal_img.putpalette(make_palette_from_565(CUSTOM_PALETTE_565))

                    # Use RGB image for quantization
                    img_p = img_rgb.quantize(palette=pal_img, dither=Image.NONE)

                # Create output directory if it doesn't exist
                os.makedirs(os.path.dirname(output_path), exist_ok=True)

                # Save the result
                img_p.save(output_path)
                print(f"  Saved to: {output_path}")
                processed += 1

            except Exception as e:
                print(f"  Error: {e}")
                failed += 1

    return processed, skipped, failed


# ---------------- Keep your original single-file processing for backward compatibility ----------------

def process_single_file():
    """
    Your original single-file processing logic
    """
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


# ---------------- Main entry point ----------------

def main():
    """
    Main function - processes command line arguments and runs either batch or single mode
    """
    if len(sys.argv) < 2:
        print("Usage:")
        print("  Single file mode: python batch_indexed_converter.py")
        print("  Batch mode:       python batch_indexed_converter.py <input_folder> [output_folder]")
        print("\nExamples:")
        print("  python batch_indexed_converter.py ./images")
        print("  python batch_indexed_converter.py ./images ./converted")
        sys.exit(1)

    input_path = sys.argv[1]

    # Check if input is a directory (batch mode) or file (should use single mode)
    if os.path.isdir(input_path):
        # Batch mode
        output_folder = sys.argv[2] if len(sys.argv) > 2 else "./indexed_output"

        start_time = time.time()
        processed, skipped, failed = process_folder(input_path, output_folder)
        elapsed = time.time() - start_time

        print("\n" + "=" * 60)
        print("Batch processing complete!")
        print(f"  Processed: {processed} images")
        print(f"  Skipped:   {skipped} images (up to date)")
        print(f"  Failed:    {failed} images")
        print(f"  Time:      {elapsed:.1f} seconds")
        print(f"  Output:    {os.path.abspath(output_folder)}")
    else:
        # Single file mode (your original behavior)
        print("Single file mode - processing one image")
        process_single_file()


if __name__ == "__main__":
    main()