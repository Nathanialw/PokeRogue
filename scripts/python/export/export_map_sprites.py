#!/usr/bin/env python3
"""
export_to_c.py

Converts all JSON files from a folder (recursively) into C struct code,
appending layouts to layouts.inc and data to data.inc.
Tracks byte offsets for sprite data indexing.

Usage:
    python export_to_c.py input_folder layout_output bytes_output
    Example: python export_to_c.py CreaturesFrontJson battlers_front_layout battlers_front
"""

import json
import os
from pathlib import Path

from python.config import constants
from python.data import db_manager

# Starting index for monsters (can be changed)
START_IDX = 0


def format_hex_array(bytes_list, indent=1, items_per_line=16 * 7):
    """Format list of ints (0-255) as C hex array with line breaks"""
    lines = []
    indent_str = "    " * indent

    if not bytes_list:
        return f"{indent_str}{{ /** empty */ }}"

    lines.append(f"{indent_str}{{")
    for i in range(0, len(bytes_list), items_per_line):
        chunk = bytes_list[i: i + items_per_line]
        hex_str = ", ".join(f"0x{b:02x}" for b in chunk)
        lines.append(f"{indent_str}    {hex_str},")
    lines.append(f"{indent_str}}},")
    return "\n".join(lines)


def get_relative_path(file_path, base_folder):
    """Get relative path from base folder, preserving folder structure in comments"""
    try:
        rel_path = Path(file_path).relative_to(Path(base_folder))
        return str(rel_path.parent)
    except ValueError:
        return ""


def process_json_file(json_path, monster_idx, comment, folder_path, layout_file, data_file, byte_offset):
    """Process a single JSON file and append to output files"""
    with open(json_path, "r") as f:
        data = json.load(f)

    tile_rle = data["rle_data"]  # only non-empty ones

    # Flatten only the non-empty RLE data
    all_rle_bytes = []
    all_rle_bytes.extend(tile_rle)

    # Calculate size of this sprite's data
    sprite_size = len(all_rle_bytes)

    # Format palette
    palette_str = data["palette_rgb565"]
    # palette_str = ", ".join(f"0x{p:04x}" for p in img_palette)

    # Get folder structure for better organization
    folder_info = get_relative_path(json_path, folder_path)
    if folder_info:
        folder_comment = f" [Folder: {folder_info}]"
    else:
        folder_comment = ""

    # Write layout to layout file with byte offset as the idx
    layout_file.write(f"// {comment}{folder_comment} (sprite index: {monster_idx}, byte offset: {byte_offset}, size: {sprite_size})\n")
    # layout_file.write(f"{{  .idx = {byte_offset}, .palette = {{ {', '.join(palette_str)} }}, }},\n")
    layout_file.write(f"{{  .index = {byte_offset}, }},\n")
    # layout_file.write(f"{{   }},\n")

    # Write data to data file
    data_file.write(f"// {comment}{folder_comment} - RLE compressed data (offset: {byte_offset}, size: {sprite_size})\n")
    if all_rle_bytes:
        # Write bytes in chunks
        for i in range(0, len(all_rle_bytes), 16 * 7):
            chunk = all_rle_bytes[i: i + 16 * 7]
            hex_str = ", ".join(f"0x{b:02x}" for b in chunk)
            data_file.write(f"{hex_str},\n")

        total_compressed = len(all_rle_bytes)
        data_file.write(f"// Compressed size: {total_compressed} bytes "
                        f"original pixels: 12544 uint16_t → ~25088 bytes uncompressed)\n\n")
    else:
        data_file.write("{ /** fully empty sprite */ },\n\n")

    return sprite_size


def check_used(file_name, creature_names):
    for name in creature_names:
        if file_name == name:
            return True
    return False


def export_image_data(entity, size):
    # Ensure input folder exists
    input_folder = f"../assets_processed/{entity}s/deployable"

    creature_names = db_manager.get_folders(entity)

    # Find all JSON files recursively
    input_path = Path(input_folder)
    all_json_files = sorted(input_path.rglob(f"*_{size}.json"))

    # Filter to only include files whose parent folder is in creature_names
    json_files = []
    for json_file in all_json_files:
        # Get the immediate parent folder name
        parent_folder_name = json_file.parent.name
        # Check if this folder name is in creature_names
        if parent_folder_name in creature_names:
            json_files.append(json_file)

    print(f"Found {len(all_json_files)} total JSON files, filtered to {len(json_files)} files in specified creature folders")
    print(f"\nProcessing... {len(json_files)} images")

    folders = {}
    for json_file in json_files:
        folder = json_file.parent
        if folder not in folders:
            folders[folder] = []
        folders[folder].append(json_file)

    for folder, files in sorted(folders.items()):
        rel_folder = folder.relative_to(input_path)
        print(f"  {rel_folder}/ ({len(files)} files)")

    print(f"\nProcessing...")

    # Create inc folder if it doesn't exist
    os.makedirs(constants.INC_FOLDER, exist_ok=True)


    bytes_output = f"sprite_{size}x{size}_{entity}"
    layout_output = f"sprite_{size}x{size}_{entity}_metaData"

    # Open output files in write mode (overwrite) to start fresh
    data_path = os.path.join(constants.INC_FOLDER, f"{bytes_output}.inc")
    layout_path = os.path.join(constants.INC_FOLDER, f"{layout_output}.inc")

    print(data_path)
    print(layout_path)

    with open(layout_path, "w") as layout_file, \
            open(data_path, "w") as data_file:

        # Add header comments
        layout_file.write(f"// Layouts generated from {input_folder} (recursive scan)\n")
        layout_file.write(f"// Starting monster index: {START_IDX}\n")
        layout_file.write(f"// Format: {{ {{ .idx = byte_offset, .palette = {{...}}, .emptyIndexes = {{...}} }},\n")
        layout_file.write(f"// Files are processed in alphabetical order by full path\n\n")

        data_file.write(f"// RLE data generated from {input_folder} (recursive scan)\n")
        data_file.write(f"// Data is concatenated sequentially\n\n")

        # Process each JSON file
        byte_offset = 0
        processed_count = 0
        failed_count = 0

        for i, json_path in enumerate(json_files):
            # Extract filename without extension as base name
            base_name = json_path.stem

            # Get relative folder path for context
            rel_folder = json_path.parent.relative_to(input_path)

            # Create comment with folder structure
            if str(rel_folder) == ".":
                comment = base_name.replace('_', ' ').replace('-', ' ').title()
                full_comment = comment
            else:
                folder_part = str(rel_folder).replace('/', ' / ').replace('_', ' ').replace('-', ' ')
                name_part = base_name.replace('_', ' ').replace('-', ' ').title()
                full_comment = f"{folder_part} / {name_part}"

            monster_idx = START_IDX + i
            print(f"  [{i + 1:3d}/{len(json_files)}] Processing {json_path.name} -> sprite index {monster_idx}, byte offset {byte_offset}")

            try:
                sprite_size = process_json_file(
                    json_path, monster_idx, full_comment, input_folder,
                    layout_file, data_file, byte_offset
                )
                byte_offset += sprite_size
                processed_count += 1
            except Exception as e:
                print(f"  ❌ Error processing {json_path}: {e}")
                failed_count += 1
                continue

        # Add footer with total size
        byte_alignment = 16
        rnd = byte_offset % byte_alignment
        byte_offset += (byte_alignment - rnd)
        layout_file.write(f"\n// Total sprites processed: {processed_count}, total data size: {byte_offset} bytes\n")
        data_file.write(f"// Total data size: {byte_offset} bytes\n")

    print(f"\n{'=' * 60}")
    print(f"PROCESSING COMPLETE")
    print(f"Successfully processed: {processed_count}")
    print(f"Failed: {failed_count}")
    print(f"Total files: {len(json_files)}")
    print(f"{'=' * 60}")
    print(f"\nFiles written:")
    print(f"  {layout_path}")
    print(f"  {data_path}")
    print(f"  Total data size: {byte_offset} bytes")
    print(f"\nNote: The .idx field in each layout now contains the byte offset into the data file")

    return byte_offset

