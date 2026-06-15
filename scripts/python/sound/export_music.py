import struct
import os
from pathlib import Path
import wave

from python.data.db_manager import get_entity_sounds, init_database
from python.config.constants import TYPES_INC_FOLDER


def get_wav_spec(filepath):
    try:
        with wave.open(str(filepath), 'rb') as wf:  # ← added str()
            return (wf.getnchannels(), wf.getframerate(), wf.getsampwidth() * 8)
    except Exception as e:
        print(f"WAV read error for {filepath}: {e}")
        return None


def pack_music_id(output_path, input_files, audio_type, id_start=0):
    for f in input_files:
        if not os.path.isfile(f):
            print(f"Error: '{f}' not found.")
            return

    num_files = len(input_files)
    if num_files == 0:
        print("No files specified.")
        return
    if num_files > 65535:
        print("Too many files (max 65535).")
        return

    ENTRY_FMT = '<HII'  # id, offset, size
    entry_size = struct.calcsize(ENTRY_FMT)
    header_size = 4 + 1 + 2 + num_files * entry_size

    entries = []
    blobs = []
    current_offset = header_size

    # First, gather audio specs for consistency check
    spec_list = []
    for filepath in input_files:
        spec_list.append(get_wav_spec(filepath))

    # Determine if all specs match (for WAV files only)
    unique_specs = set(s for s in spec_list if s is not None)
    if len(unique_specs) > 1:
        print("\n*** WARNING: WAV files have different audio specs! ***")
        for fp, spec in zip(input_files, spec_list):
            if spec:
                print(f"  {spec}  {fp}")

    for idx, filepath in enumerate(input_files):
        with open(filepath, 'rb') as f:
            data = f.read()
        size = len(data)

        asset_id = id_start + idx
        entries.append((asset_id, current_offset, size))
        blobs.append(data)
        current_offset += size

    # Write the .bin file
    with open(output_path, 'wb') as out:
        out.write(b'ASST')
        out.write(struct.pack('<B', 1))
        out.write(struct.pack('<H', num_files))

        for asset_id, offset, size in entries:
            out.write(struct.pack(ENTRY_FMT, asset_id, offset, size))

        for data in blobs:
            out.write(data)

    print(f"Created {output_path} with {num_files} files:")
    for idx, (asset_id, offset, size) in enumerate(entries):
        name = os.path.basename(input_files[asset_id - id_start])
        spec = spec_list[idx]
        if spec:
            ch, rate, bits = spec
            print(f"  ID {asset_id:3d}: {name:40s}  [{ch} ch, {rate} Hz, {bits}‑bit]  offset=0x{offset:08X}, size={size}")
        else:
            print(f"  ID {asset_id:3d}: {name:40s}  [non‑WAV]                offset=0x{offset:08X}, size={size}")

    root_path = f"../../{TYPES_INC_FOLDER}"
    header_path = f"{root_path}/data_constants_{audio_type}.inc"
    with open(header_path, 'w') as hdr:
        hdr.write('#pragma once\n\n')
        for asset_id, _, _ in entries:
            name = os.path.basename(input_files[asset_id - id_start])
            macro_name = name.upper().replace(' ', '_').replace('.', '_')
            hdr.write(f'#define SOUND_{macro_name} {asset_id}\n')


def get_files_sorted(directory):
    p = Path(directory)
    if not p.is_dir():
        return []
    return sorted([f for f in p.iterdir() if f.is_file()])


if __name__ == '__main__':
    init_database()

    raw_path = '../../../assets_raw/sound/'
    output_path = '../../../bin/'

    music = 'music'
    music_bin = f"{output_path}/{music}.bin"
    input_music = get_files_sorted(f'{raw_path}/{music}')
    pack_music_id(music_bin, input_music, music, id_start=0)
