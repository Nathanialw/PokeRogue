#!/usr/bin/env python3
import sys
import os
from pathlib import Path
import numpy as np
from PIL import Image
import json


# ================== ADD YOUR REAL PALETTE HERE ==================

def create_palette_direct(image_path):
    img = Image.open(image_path).convert("RGB")   # always 8‑bit RGB
    pixels = np.array(img)

    # unique rows of shape (N, 3)
    unique_rgb = np.unique(pixels.reshape(-1, 3), axis=0)

    palette_565 = []
    for r, g, b in unique_rgb:
        r5 = r >> 3
        g6 = g >> 2
        b5 = b >> 3
        rgb565 = (r5 << 11) | (g6 << 5) | b5
        palette_565.append(rgb565)

    print(f"Unique colors: {len(palette_565)}")
    return palette_565


# Your 16 RGB565 colors as list of uint16_t integers (like in your C example)
WIDTH = 112
HEIGHT = 112

PALETTE_RGB565 = []
PALETTE_RGB888 = []


# Helper: convert RGB565 → RGB888 tuple for distance calculation
def rgb565_to_rgb888(c):
    r = ((c >> 11) & 0x1F) * 255 // 31
    g = ((c >> 5) & 0x3F) * 255 // 63
    b = (c & 0x1F) * 255 // 31
    return (r, g, b)


# Precompute RGB888 versions once (faster)

# Your transparent color index (change if not 15)
TRANSPARENT_INDEX = 0  # or 0, or whatever is background in your indexed images


# Distance function (simple Euclidean in RGB space)
def nearest_color_index(r, g, b):
    if r == g == b == 0 and False:  # optional: treat pure black as trans if you want
        return TRANSPARENT_INDEX

    min_dist = float('inf')
    best_idx = 0
    for i, (pr, pg, pb) in enumerate(PALETTE_RGB888):
        dist = (pr - r) ** 2 + (pg - g) ** 2 + (pb - b) ** 2
        if dist < min_dist:
            min_dist = dist
            best_idx = i
    return best_idx


def rle_encode_row(row):
    rle = []
    i = 0
    while i < 16:
        color = row[i]
        count = 1
        i += 1

        while i < 16 and row[i] == color and count < 15:
            count += 1
            i += 1

        byte = (count << 4) | (color & 0x0F)
        rle.append(byte)

    return rle


import numpy as np
from PIL import Image

def process_sprite(input_path, output_json):
    print(f"\nProcessing: {input_path}")

    img = Image.open(input_path).convert('RGBA')
    if img.size != (WIDTH, HEIGHT):
        print(f"  Resizing from {img.size} to {WIDTH}x{HEIGHT}")
        img = img.resize((WIDTH, HEIGHT), Image.NEAREST)

    # ---------- 1. Quantize RGB part to exactly 16 colours ----------
    rgb_img = img.convert("RGB")
    # Pillow 9+ : method=Image.Quantize.MEDIANCUT, for older: method=0
    try:
        quantized = rgb_img.quantize(colors=16, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
    except AttributeError:
        quantized = rgb_img.quantize(colors=16, method=0, dither=Image.Dither.NONE)  # fallback for older Pillow

    # Extract the 16-colour palette as plain Python ints
    raw_pal = quantized.getpalette()
    palette_rgb888 = []
    palette_rgb565 = []
    for i in range(16):
        r = int(raw_pal[3*i])
        g = int(raw_pal[3*i+1])
        b = int(raw_pal[3*i+2])
        palette_rgb888.append((r, g, b))
        # Convert to RGB565 (all Python ints)
        r5 = r >> 3
        g6 = g >> 2
        b5 = b >> 3
        palette_rgb565.append((r5 << 11) | (g6 << 5) | b5)

    # ---------- 2. Build indexed image (0‑15), respecting alpha ----------
    alpha = np.array(img.split()[-1])          # uint8
    quant_data = np.array(quantized)           # uint8, values 0‑15

    indexed = [[0]*WIDTH for _ in range(HEIGHT)]  # list of lists of ints
    for y in range(HEIGHT):
        for x in range(WIDTH):
            if alpha[y, x] < 128:
                indexed[y][x] = TRANSPARENT_INDEX
            else:
                indexed[y][x] = int(quant_data[y, x])   # ensure Python int

    # ---------- 3. Build tiles and RLE (same as before) ----------
    tiles_rle = []
    empty_mask = [0] * 7
    non_empty_count = 0

    for ty in range(7):
        for tx in range(7):
            tile = []
            for dy in range(16):
                row_start_x = tx * 16
                row_y = ty * 16 + dy
                row = indexed[row_y][row_start_x: row_start_x + 16]
                tile.extend(row)

            non_trans = sum(1 for p in tile if p != TRANSPARENT_INDEX)
            tile_idx = ty * 7 + tx
            byte_idx = tile_idx // 8
            bit_idx = tile_idx % 8

            if non_trans > 0:
                empty_mask[byte_idx] |= (1 << bit_idx)

                rle_tile = []
                for row_start in range(0, 256, 16):
                    row = tile[row_start: row_start + 16]
                    rle_tile.extend(rle_encode_row(row))   # rle_encode_row returns list of ints

                tiles_rle.append(rle_tile)
                non_empty_count += 1
                print(f"  Tile {ty:1d},{tx:1d}: {non_trans} colored pixels")
            else:
                tiles_rle.append(None)
                print(f"  Tile {ty:1d},{tx:1d}: EMPTY")

    # ---------- 4. Prepare JSON-safe output ----------
    result = {
        "file": os.path.basename(input_path),
        "palette_rgb565": [f"0x{c:04x}" for c in palette_rgb565],
        "empty_mask": [f"0x{b:02x}" for b in empty_mask],
        "num_nonempty": non_empty_count,
        "rle_tiles": [t for t in tiles_rle if t is not None],
        "rle_lengths": [len(t) for t in tiles_rle if t is not None]
    }

    os.makedirs(os.path.dirname(output_json), exist_ok=True)
    with open(output_json, 'w') as f:
        json.dump(result, f, indent=2)

    print(f"  Saved: {output_json}")
    print(f"  Non-empty tiles: {result['num_nonempty']}")
    print(f"  Total RLE bytes: {sum(result['rle_lengths'])}")


def process_folder(input_folder):
    """Recursively process all PNG images in folder and subfolders"""
    input_path = Path(input_folder)

    if not input_path.exists():
        print(f"Error: Folder '{input_folder}' does not exist!")
        return

    # Find all PNG files recursively
    png_files = list(input_path.rglob("*.png"))

    if not png_files:
        print(f"No PNG files found in {input_folder}")
        return

    print(f"Found {len(png_files)} PNG files to process")
    print("=" * 60)

    processed = 0
    failed = 0

    for png_file in png_files:
        try:
            # Generate output JSON path alongside the image
            output_json = png_file.with_suffix('.json')

            process_sprite(str(png_file), str(output_json))
            processed += 1

        except Exception as e:
            print(f"❌ Failed to process {png_file}: {e}")
            failed += 1

    # Print summary
    print("\n" + "=" * 60)
    print(f"PROCESSING COMPLETE")
    print(f"Successfully processed: {processed}")
    print(f"Failed: {failed}")
    print(f"Total: {len(png_files)}")


def main():
    if len(sys.argv) != 2:
        print("Usage: python compress_img.py <input_folder>")
        print("")
        print("This script will recursively find all .png files in the input folder")
        print("and generate .json files alongside each image.")
        print("")
        print("Example:")
        print("  python tile_and_rle.py ./sprites")
        print("  → Creates ./sprites/character/hero.json from ./sprites/character/hero.png")
        sys.exit(1)



    input_folder = sys.argv[1]
    process_folder(input_folder)


if __name__ == "__main__":
    main()
