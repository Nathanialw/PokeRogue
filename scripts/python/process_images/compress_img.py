#!/usr/bin/env python3
import sys
import os
from pathlib import Path
import json

import numpy as np
from PIL import Image

# ------------------------------------------------------------
#  Grid dimensions (always 7×7 as requested)
# ------------------------------------------------------------
GRID_X = 7
GRID_Y = 7

TRANSPARENT_INDEX = 0   # palette index used for fully transparent pixels

# ------------------------------------------------------------
def rle_encode_row(row):
    """
    RLE encode a single row of palette indices (0–15).
    Each byte = (run_length-1) << 4 | colour_index.
    Maximum run length = 15.
    """
    rle = []
    i = 0
    L = len(row)
    while i < L:
        colour = row[i]
        count = 1
        i += 1
        while i < L and row[i] == colour and count < 15:
            count += 1
            i += 1
        rle.append((count << 4) | (colour & 0x0F))
    return rle


def process_sprite(input_path, output_json, tile_w, tile_h):
    # Total image size
    w = tile_w * GRID_X
    h = tile_h * GRID_Y

    print(f"\nProcessing: {input_path}")

    img = Image.open(input_path).convert('RGBA')
    if img.size != (w, h):
        print(f"  Resizing from {img.size} to {w}x{h}")
        img = img.resize((w, h), Image.NEAREST)

    # ---------- 1. Quantize RGB to exactly 16 colours ----------
    rgb_img = img.convert("RGB")
    try:
        quantized = rgb_img.quantize(colors=16, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
    except AttributeError:
        quantized = rgb_img.quantize(colors=16, method=0, dither=Image.Dither.NONE)

    # Extract the 16‑colour palette
    raw_pal = quantized.getpalette()
    palette_rgb565 = []
    for i in range(16):
        r = int(raw_pal[3 * i])
        g = int(raw_pal[3 * i + 1])
        b = int(raw_pal[3 * i + 2])
        r5 = r >> 3
        g6 = g >> 2
        b5 = b >> 3
        palette_rgb565.append((r5 << 11) | (g6 << 5) | b5)

    # ---------- 2. Build indexed image (0‑15), respecting alpha ----------
    alpha = np.array(img.split()[-1])
    quant_data = np.array(quantized)

    indexed = [[0] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            if alpha[y, x] < 128:
                indexed[y][x] = TRANSPARENT_INDEX
            else:
                indexed[y][x] = int(quant_data[y, x])

    # ---------- 3. 7×7 tile processing ----------
    total_tiles = GRID_X * GRID_Y
    mask_bytes = (total_tiles + 7) // 8
    empty_mask = [0] * mask_bytes
    tiles_rle = []
    non_empty_count = 0

    for ty in range(GRID_Y):
        for tx in range(GRID_X):
            tile_idx = ty * GRID_X + tx
            tile = []
            for dy in range(tile_h):
                row_start_x = tx * tile_w
                row_y = ty * tile_h + dy
                tile.extend(indexed[row_y][row_start_x: row_start_x + tile_w])

            non_trans = sum(1 for p in tile if p != TRANSPARENT_INDEX)

            if non_trans > 0:
                byte_idx = tile_idx // 8
                bit_idx = tile_idx % 8
                empty_mask[byte_idx] |= (1 << bit_idx)

                rle_tile = []
                for row_start in range(0, tile_w * tile_h, tile_w):
                    row = tile[row_start: row_start + tile_w]
                    rle_tile.extend(rle_encode_row(row))
                tiles_rle.append(rle_tile)
                non_empty_count += 1
                print(f"  Tile ({ty},{tx}): {non_trans} coloured pixels")
            else:
                tiles_rle.append(None)
                print(f"  Tile ({ty},{tx}): EMPTY")

    # ---------- 4. JSON output ----------
    result = {
        "file": os.path.basename(input_path),
        "image_size": [w, h],
        "tile_size": [tile_w, tile_h],
        "grid_size": [GRID_X, GRID_Y],
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


def process_folder(input_folder, tile_w, tile_h):
    input_path = Path(input_folder)
    if not input_path.exists():
        print(f"Error: Folder '{input_folder}' does not exist!")
        return

    png_files = list(input_path.rglob("*.png"))
    if not png_files:
        print(f"No PNG files found in {input_folder}")
        return

    expected_w = tile_w * GRID_X
    expected_h = tile_h * GRID_Y
    print(f"Found {len(png_files)} PNG files to process")
    print(f"Image size: {expected_w}×{expected_h}  (7×7 tiles of {tile_w}×{tile_h})")
    print("=" * 60)

    processed = 0
    failed = 0
    for png_file in png_files:
        try:
            output_json = png_file.parent / f"{png_file.stem}_battler_{tile_w}x{tile_h}.json"
            process_sprite(str(png_file), str(output_json), tile_w, tile_h)
            processed += 1
        except Exception as e:
            print(f"❌ Failed to process {png_file}: {e}")
            failed += 1

    print("\n" + "=" * 60)
    print(f"PROCESSING COMPLETE")
    print(f"Successfully: {processed} | Failed: {failed} | Total: {len(png_files)}")


def main():
    if len(sys.argv) != 4:
        print("Usage: python compress_img.py <input_folder> <tile_width> <tile_height>")
        print()
        print("  Always produces a 7×7 tile grid.")
        print("  Input images are expected to be (7*tile_w) × (7*tile_h),")
        print("  but will be resized if they don't match exactly.")
        print()
        print("Example (64×64 tiles → 448×448 images):")
        print("  python compress_img.py ./sprites 64 64")
        sys.exit(1)

    input_folder = sys.argv[1]
    tile_w = int(sys.argv[2])
    tile_h = int(sys.argv[3])

    process_folder(input_folder, tile_w, tile_h)


if __name__ == "__main__":
    main()