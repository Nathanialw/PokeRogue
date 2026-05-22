#!/usr/bin/env python3
"""
Convert a TrueType font (.ttf) into a packed uint8_t bit array,
with an intermediate PNG step for visual verification.

Usage:
    # Standard (row‑padded) mode – every row padded to byte boundary
    python ttf_to_font.py myfont.ttf --size 16 --chars "ABC" --char-width 20 --char-height 20

    # Tight (contiguous) packing – bits packed sequentially across all rows
    python ttf_to_font.py myfont.ttf --size 16 --chars "ABC" --char-width 20 --char-height 20 --tight

    # Use a file for the character list (avoids shell escaping issues)
    python ttf_to_font.py myfont.ttf --size 16 --chars-file chars.txt --char-width 20 --char-height 20 --tight
"""

import argparse
from PIL import Image, ImageFont, ImageDraw


def draw_text_strip(font, chars, cell_w, cell_h, align_h='center', align_v='center'):
    total_width = cell_w * len(chars)
    img = Image.new('1', (total_width, cell_h), 1)
    draw = ImageDraw.Draw(img)

    for i, ch in enumerate(chars):
        try:
            bbox = font.getbbox(ch)
        except AttributeError:
            tmp = Image.new('1', (1, 1))
            draw_tmp = ImageDraw.Draw(tmp)
            w, h = draw_tmp.textsize(ch, font=font)
            bbox = (0, 0, w, h)

        glyph_w = bbox[2] - bbox[0]
        glyph_h = bbox[3] - bbox[1]

        offset_x = (cell_w - glyph_w) // 2 - bbox[0]
        offset_y = (cell_h - glyph_h) // 2 - bbox[1]

        x = i * cell_w
        draw.text((x + offset_x, offset_y), ch, font=font, fill=0)

    return img


def draw_text_tight(font, text):
    try:
        bbox = font.getbbox(text)
    except AttributeError:
        draw = ImageDraw.Draw(Image.new('1', (1, 1)))
        w, h = draw.textsize(text, font=font)
        bbox = (0, 0, w, h)
    width = bbox[2] - bbox[0]
    height = bbox[3] - bbox[1]
    img = Image.new('1', (width, height), 1)
    draw = ImageDraw.Draw(img)
    draw.text((-bbox[0], -bbox[1]), text, font=font, fill=0)
    return img


def png_to_bitarray(img, cell_w=None, cell_h=None, chars=None, tight_packing=False):
    """
    Convert a '1'‑mode image to a list of uint8 values.
    If cell_w and cell_h are given, the image is split into N equal cells.
    tight_packing: if True, pack bits across rows without per‑row padding.
    """
    width, height = img.size
    pixels = img.load()

    if cell_w is not None and cell_h is not None:
        if chars is None:
            raise ValueError("Must provide chars list in cell mode")
        if width % cell_w != 0 or height != cell_h:
            raise ValueError(f"Image size {width}x{height} does not match cell dimensions {cell_w}x{cell_h}")
        num_chars = width // cell_w
        if len(chars) != num_chars:
            raise ValueError(f"Number of characters ({len(chars)}) does not match cells in image ({num_chars})")

        # Determine bytes per char based on packing mode
        if tight_packing:
            bytes_per_char = (cell_w * cell_h + 7) // 8  # e.g., 20*20=400 bits -> 50 bytes
        else:
            bytes_per_char = ((cell_w + 7) // 8) * cell_h  # row‑padded

        all_bytes = []
        for i in range(num_chars):
            x0 = i * cell_w
            x1 = x0 + cell_w

            if tight_packing:
                # Pack all bits sequentially (row‑major, no per‑row padding)
                bits = []
                for y in range(cell_h):
                    for x in range(x0, x1):
                        bits.append(1 if pixels[x, y] == 0 else 0)
                # Pad to byte boundary at the end
                while len(bits) % 8 != 0:
                    bits.append(0)
                cell_bytes = []
                for j in range(0, len(bits), 8):
                    byte = 0
                    for k in range(8):
                        byte |= (bits[j + k] << (7 - k))
                    cell_bytes.append(byte)
            else:
                # Row‑padded packing: each row padded to a full byte
                cell_bytes = []
                for y in range(cell_h):
                    row_bits = []
                    for x in range(x0, x1):
                        row_bits.append(1 if pixels[x, y] == 0 else 0)
                    while len(row_bits) % 8 != 0:
                        row_bits.append(0)
                    for j in range(0, len(row_bits), 8):
                        byte = 0
                        for k in range(8):
                            byte |= (row_bits[j + k] << (7 - k))
                        cell_bytes.append(byte)

            # Ensure exact byte count (should already be exact, but safety trim/pad)
            if len(cell_bytes) > bytes_per_char:
                cell_bytes = cell_bytes[:bytes_per_char]
            elif len(cell_bytes) < bytes_per_char:
                cell_bytes.extend([0] * (bytes_per_char - len(cell_bytes)))

            all_bytes.extend(cell_bytes)

        first_char = chars[0]
        return all_bytes, first_char, cell_w, cell_h, bytes_per_char
    else:
        # full image mode (no fixed cells)
        bitarray = []
        for y in range(height):
            row_bits = []
            for x in range(width):
                bit = 1 if pixels[x, y] == 0 else 0
                row_bits.append(bit)
            while len(row_bits) % 8 != 0:
                row_bits.append(0)
            for i in range(0, len(row_bits), 8):
                byte = 0
                for j in range(8):
                    byte |= (row_bits[i + j] << (7 - j))
                bitarray.append(byte)
        return bitarray, None, width, height, None


def write_header(bitarray, first_char, cell_w, cell_h, bytes_per_char, output_path, font_path, size, chars_str, tight_packing=False):
    header = f"// Font bitmap generated from {font_path}\n"
    header += f"// Size: {size} pt, characters: \"{chars_str}\"\n"
    if cell_w and cell_h:
        packing_note = " (tight/contiguous)" if tight_packing else " (row‑padded)"
        header += f"// Cell dimensions: {cell_w} x {cell_h} pixels{packing_note}\n"
        header += f"// Bytes per character: {bytes_per_char}\n"
        header += f"// Number of characters: {len(chars_str)}\n"
        header += f"// First character: '{first_char}' (0x{ord(first_char):02X})\n\n"
        header += f"// CHAR_WIDTH {cell_w}\n"
        header += f"// CHAR_HEIGHT {cell_h}\n"
        header += f"// BYTES_PER_CHAR {bytes_per_char}\n"
        header += f"// FIRST_CHAR '{first_char}'\n"
        header += f"// NUM_CHARS {len(chars_str)}\n"
        header += f"// ARRAY_SIZE {len(chars_str) * bytes_per_char} bytes \n\n"
    else:
        header += f"// Image dimensions: {cell_w} x {cell_h} pixels\n"
        header += f"// Packed array length: {len(bitarray)} bytes\n\n"
        array_decl = f"const uint8_t font_bitmap[] = {{\n"

    # Validate total size
    if cell_w and cell_h:
        expected_total = len(chars_str) * bytes_per_char
        if len(bitarray) != expected_total:
            raise ValueError(
                f"Bitmap length ({len(bitarray)}) != expected ({expected_total}) for "
                f"{len(chars_str)} chars × {bytes_per_char} bytes each."
            )
    # Print each character's bytes on one line
    for idx, ch in enumerate(chars_str):
        start = idx * bytes_per_char
        end = start + bytes_per_char
        line_bytes = bitarray[start:end]
        hex_str = ", ".join(f"0x{b:02X}" for b in line_bytes)
        header += f"{hex_str}, // '{ch}'\n"

    if output_path == "-":
        print(header)
    else:
        with open(output_path, "w") as f:
            f.write(header)
        print(f"Header written to {output_path}")


def main():
    parser = argparse.ArgumentParser(description="TTF font → PNG → uint8_t bit array")
    parser.add_argument("font", nargs="?", help="Path to the .ttf font file")
    parser.add_argument("--size", type=int, default=12, help="Font size in points")
    parser.add_argument("--chars", default="0123456789ABCDEF", help="Characters to render")
    parser.add_argument("--chars-file", default=None, help="Read characters from a file (overrides --chars)")
    parser.add_argument("--char-width", type=int, default=None, help="Fixed width of each character cell")
    parser.add_argument("--char-height", type=int, default=None, help="Fixed height of each character cell")
    parser.add_argument("--png", default="font.png", help="Output PNG file (default: font.png)")
    parser.add_argument("--header", default="font", help="Output C header file (default: font.h)")
    parser.add_argument("--only-png", action="store_true", help="Only generate the PNG, do not create a header")
    parser.add_argument("--only-header", action="store_true", help="Only generate the header from an existing PNG (requires --input-png)")
    parser.add_argument("--input-png", default=None, help="Path to an existing PNG to convert to header")
    parser.add_argument("--tight", action="store_true", help="Use tight (contiguous) bit packing instead of row‑padded")
    args = parser.parse_args()

    output_path = args.header
    if args.header == "font":
        output_path = f"../../../src/GameCore/inc/data_{output_path}{args.char_width}x{args.char_height}.inc"
    else:
        output_path = "font.inc"

    if args.chars_file:
        with open(args.chars_file, 'r') as f:
            args.chars = f.read().rstrip('\n')
        print(f"Loaded {len(args.chars)} characters from {args.chars_file}")

    if args.only_header:
        if not args.input_png:
            parser.error("--only-header requires --input-png")
        if args.char_width and args.char_height:
            if not args.chars:
                parser.error("--chars is required in cell mode to know character order")
            cell_w = args.char_width
            cell_h = args.char_height
        else:
            cell_w = cell_h = None

        img = Image.open(args.input_png).convert('1')
        bitarray, first_char, cw, ch, bpc = png_to_bitarray(
            img, cell_w=cell_w, cell_h=cell_h,
            chars=args.chars if cell_w else None,
            tight_packing=args.tight
        )
        write_header(bitarray, first_char, cw, ch, bpc, args.header,
                     args.input_png, "n/a", args.chars, tight_packing=args.tight)
        return

    if not args.font:
        parser.error("font path is required unless using --only-header")
    font = ImageFont.truetype(args.font, args.size)
    chars = args.chars

    if args.char_width and args.char_height:
        img = draw_text_strip(font, chars, args.char_width, args.char_height)
    else:
        img = draw_text_tight(font, chars)

    output_png = f"images/{args.png}"

    img.save(output_png)
    print(f"PNG saved to {output_png}")

    if args.only_png:
        return

    png_img = Image.open(output_png).convert('1')
    cell_w = args.char_width if args.char_width and args.char_height else None
    cell_h = args.char_height if args.char_width and args.char_height else None
    bitarray, first_char, cw, ch, bpc = png_to_bitarray(png_img, cell_w=cell_w, cell_h=cell_h, chars=chars if cell_w else None, tight_packing=args.tight)
    write_header(bitarray, first_char, cw, ch, bpc, output_path, args.font, args.size, chars, tight_packing=args.tight)


if __name__ == "__main__":
    main()
