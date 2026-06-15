import struct
import os
from pathlib import Path
import wave

from python.data.db_manager import get_entity_sounds, init_database
from python.config.constants import TYPES_INC_FOLDER, IMAGE_TYPES

raw_path = '../'
output_path = '../bin/'

def get_wav_spec(filepath):
    try:
        with wave.open(str(filepath), 'rb') as wf:
            return (wf.getnchannels(), wf.getframerate(), wf.getsampwidth() * 8)
    except Exception as e:
        print(f"WAV read error for {filepath}: {e}")
        return None


def pack_entity_sounds(output_basename, entity_list):
    """
    Packs all sound effects for a list of entity types into one .bin.

    entity_list : list of strings (e.g. ['tiles', 'creatures', ...]).
    get_entity_sounds(entity) must return a list of (name, relative_path)
    in the **exact order** of the enum.

    Missing files are skipped and get a sentinel 0xFFFF.
    A single .bin is written.
    Per-entity .inc headers contain a static const uint16_t array mapping
    enum index → sound ID (or 0xFFFF).
    """

    # ----- 1. Gather all valid sounds, in global packing order -----
    all_entries = []               # (enum_idx, filepath, name, entity)
    entity_data = {}               # entity -> { size: int, mapping: dict(enum_idx->sound_id) }

    global_sound_id = 0

    for entity in entity_list:
        print(f"\nProcessing entity: {entity}")
        raw_sounds = get_entity_sounds(entity)   # [(name, rel_path), ...] in enum order
        if not raw_sounds:
            print(f"  No sounds returned from DB for {entity}")
            entity_data[entity] = {'size': 0, 'mapping': {}}
            continue

        size = len(raw_sounds)
        mapping = {}

        for enum_idx, (name, rel_path) in enumerate(raw_sounds):
            if not rel_path:
                rel_path = "assets_raw/sound/effects/walking/Light Armor Walking 2_10.wav"
            full_path = os.path.join(raw_path, rel_path)  # adjust if rel_path is already absolute
            if not os.path.isfile(full_path):
                print(f"  WARNING: file missing for {entity}::'{name}' (enum {enum_idx}) → {full_path}")
                # leave mapping as missing, sentinel later
                continue

            # Add to global packing list
            all_entries.append((enum_idx, full_path, name, entity))
            mapping[enum_idx] = global_sound_id
            global_sound_id += 1

        entity_data[entity] = {'size': size, 'mapping': mapping}
        print(f"  {len(mapping)}/{size} sounds valid for {entity}")

    if not all_entries:
        print("No valid sound files – nothing to pack.")
        return

    # ----- 2. Write the .bin file -----
    bin_path = f"{output_path}/{output_basename}.bin"
    num_files = len(all_entries)

    ENTRY_FMT = '<HII'          # id, offset, size
    entry_size = struct.calcsize(ENTRY_FMT)
    header_size = 4 + 1 + 2 + num_files * entry_size

    entries = []
    blobs = []
    current_offset = header_size
    spec_list = []

    for idx, (enum_idx, filepath, name, entity) in enumerate(all_entries):
        with open(filepath, 'rb') as f:
            data = f.read()
        size = len(data)
        spec = get_wav_spec(filepath)
        spec_list.append(spec)

        entries.append((idx, current_offset, size))   # id = sequential global ID
        blobs.append(data)
        current_offset += size

    with open(bin_path, 'wb') as out:
        out.write(b'ASST')
        out.write(struct.pack('<B', 1))
        out.write(struct.pack('<H', num_files))
        for asset_id, offset, size in entries:
            out.write(struct.pack(ENTRY_FMT, asset_id, offset, size))
        for data in blobs:
            out.write(data)

    print(f"\nCreated {bin_path} with {num_files} files:")
    for idx, (enum_idx, filepath, name, entity) in enumerate(all_entries):
        spec = spec_list[idx]
        if spec:
            ch, rate, bits = spec
            print(f"  ID {idx:3d}: {name:40s} [{ch} ch, {rate} Hz, {bits}‑bit]  from {entity} enum {enum_idx}")
        else:
            print(f"  ID {idx:3d}: {name:40s} [non‑WAV]  from {entity} enum {enum_idx}")

    # ----- 3. Write per-entity .inc headers -----
    for entity, info in entity_data.items():
        size = info['size']
        if size == 0:
            continue  # no sounds for this entity, skip header

        mapping = info['mapping']
        sound_ids = [0xFFFF] * size
        for enum_idx, sid in mapping.items():
            sound_ids[enum_idx] = sid

        header_path = f"{TYPES_INC_FOLDER}/data_sounds_{entity}.inc"
        os.makedirs(os.path.dirname(header_path), exist_ok=True)

        with open(header_path, 'w') as hdr:
            hdr.write('#pragma once\n\n')
            hdr.write(f'// Sound IDs for entity type: {entity}\n')
            # hdr.write(f'#define {entity.upper()}_SOUND_COUNT {size}\n\n')
            # hdr.write(f'static const uint16_t sound_ids_{entity}[{size}] = {{\n')
            for i, sid in enumerate(sound_ids):
                if sid == 0xFFFF:
                    hdr.write(f'0xFFFF,  // {i}: no sound\n')
                else:
                    # Find name for comment (optional)
                    name = next((n for idx, fp, n, e in all_entries if e == entity and idx == i), '?')
                    hdr.write(f'{sid},     // {i}: {name}\n')
            # hdr.write('};\n')

        print(f"Wrote header: {header_path}")


# ----- Main -----
if __name__ == '__main__':
    init_database()

    # List of entity types to process (order defines packing order)


    pack_entity_sounds('effects', IMAGE_TYPES)

