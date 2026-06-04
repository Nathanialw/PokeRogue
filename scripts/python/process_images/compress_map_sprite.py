#!/usr/bin/env python3
"""
Compress all PNG images in a folder into square map sprites of a given size.
Each sprite is stored as a single tile with RLE compression, using a
palette of up to 16 colors (no special transparency index).

Usage:
    python compress_map_sprite.py <input_folder> <size>

Allowed sizes: 16, 20, 24, 32, 64

For every image found (recursively), a .json file is created next to it.
"""

import sys
import os
import json
from pathlib import Path

import numpy as np
from PIL import Image


# ----------------------------------------------------------------------
#  RLE encoding for a row of arbitrary length (max run = 15 pixels)
# ----------------------------------------------------------------------
def rle_encode_row(row):
    """
    Encode a row (list of pixel indices 0..15) into RLE bytes.
    Each byte: high nibble = run length (1..15), low nibble = pixel index.
    Returns list of ints (0..255).
    """
    if not row:
        return []
    rle = []
    i = 0
    length = len(row)
    while i < length:
        color = row[i]
        run = 1
        i += 1
        # Extend run while same color and run < 15
        while i < length and row[i] == color and run < 15:
            run += 1
            i += 1
        byte = (run << 4) | (color & 0x0F)
        rle.append(byte)
    return rle


# ----------------------------------------------------------------------
#  Compress a single image to a square sprite of given size
# ----------------------------------------------------------------------
def compress_sprite_single(input_path, size, output_path):
    """
    Compress an image to a square sprite of given size, store as one tile.
    Alpha channel is completely ignored – the image is treated as opaque.
    """
    if size not in (16, 20, 24, 32, 64):
        raise ValueError(f"Size must be one of 16,20,24,32,64 (got {size})")

    print(f"\nProcessing: {input_path} -> {size}x{size} sprite")

    # 1. Load image and resize (alpha discarded)
    img = Image.open(input_path).convert('RGB')   # no alpha
    if img.size != (size, size):
        print(f"  Resizing from {img.size} to {size}x{size}")
        img = img.resize((size, size), Image.NEAREST)

    # 2. Quantize to exactly 16 colors (indices 0..15)
    try:
        quantized = img.quantize(colors=16,
                                 method=Image.Quantize.MEDIANCUT,
                                 dither=Image.Dither.NONE)
    except AttributeError:
        # Fallback for older Pillow versions
        quantized = img.quantize(colors=16, method=0, dither=Image.Dither.NONE)

    # 3. Extract the 16‑color palette as RGB888 and RGB565
    # --- after quantize, count colour usage and reorder ---
    quant_pixels = np.array(quantized, dtype=np.uint8)
    raw_pal = quantized.getpalette()  # 768 bytes
    num_colors = max(quantized.getcolors())[0] + 1  # actual number of colours used

    # Frequency of each original index
    freq = [0] * 256
    for p in quant_pixels.flat:
        freq[p] += 1

    # Build list of (original_index, rgb888, rgb565, frequency)
    entries = []
    for idx in range(num_colors):
        r = raw_pal[3 * idx]
        g = raw_pal[3 * idx + 1]
        b = raw_pal[3 * idx + 2]
        r5, g6, b5 = r >> 3, g >> 2, b >> 3
        rgb565 = (r5 << 11) | (g6 << 5) | b5
        entries.append((idx, (r, g, b), rgb565, freq[idx]))

    # Sort: most frequent first → new index 0
    entries.sort(key=lambda x: x[3], reverse=True)

    # Build final palette (exactly 16 entries) and remap array
    palette_rgb565 = []
    remap = np.zeros(256, dtype=np.uint8)
    for new_idx, (old_idx, rgb888, rgb565, _) in enumerate(entries):
        remap[old_idx] = new_idx
        palette_rgb565.append(rgb565)

    # Pad to 16 colours if necessary (with last colour or black)
    while len(palette_rgb565) < 16:
        fallback = palette_rgb565[-1] if palette_rgb565 else 0x0000
        palette_rgb565.append(fallback)

    # Remap the quantized image: background now becomes index 0
    indexed = remap[quant_pixels]

    # 5. Encode whole sprite as a single tile: RLE per row
    rle_bytes = []
    for y in range(size):
        row = indexed[y, :].tolist()
        rle_bytes.extend(rle_encode_row(row))

    # 6. Prepare JSON output (no transparent_index)
    result = {
        "file": os.path.basename(input_path),
        "width": size,
        "height": size,
        "palette_rgb565": [f"0x{c:04x}" for c in palette_rgb565],
        "rle_data": rle_bytes,
        "rle_byte_count": len(rle_bytes)
    }

    os.makedirs(os.path.dirname(os.path.abspath(output_path)), exist_ok=True)
    with open(output_path, 'w', encoding='utf-8') as f:
        json.dump(result, f, indent=2)

    print(f"  Saved: {output_path}")
    print(f"  RLE data size: {len(rle_bytes)} bytes")
    print(f"  Palette colours: {len(palette_rgb565)}")


# ----------------------------------------------------------------------
#  Process a whole folder recursively
# ----------------------------------------------------------------------
def process_folder(input_folder, size):
    """Recursively process all PNG images in folder and subfolders."""
    input_path = Path(input_folder)

    if not input_path.exists():
        print(f"Error: Folder '{input_folder}' does not exist!")
        return

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
            output_json = png_file.parent / f"{png_file.stem}_{size}.json"
            compress_sprite_single(str(png_file), size, str(output_json))
            processed += 1
        except Exception as e:
            print(f"❌ Failed to process {png_file}: {e}")
            failed += 1

    print("\n" + "=" * 60)
    print(f"PROCESSING COMPLETE")
    print(f"Successfully processed: {processed}")
    print(f"Failed: {failed}")
    print(f"Total: {len(png_files)}")


# ----------------------------------------------------------------------
#  Command line interface
# ----------------------------------------------------------------------
def main():
    if len(sys.argv) != 3:
        print(__doc__)
        print("Example:")
        print("  python compress_map_sprite.py ./map_sprites 32")
        sys.exit(1)

    input_folder = sys.argv[1]
    try:
        size = int(sys.argv[2])
    except ValueError:
        print(f"Error: size must be an integer (16,20,24,32,64), got '{sys.argv[2]}'")
        sys.exit(1)

    if size not in (16, 20, 24, 32, 64):
        print(f"Error: size must be one of 16,20,24,32,64 (got {size})")
        sys.exit(1)

    process_folder(input_folder, size)


if __name__ == "__main__":
    main()