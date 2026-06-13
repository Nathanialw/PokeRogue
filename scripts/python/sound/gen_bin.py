import struct
import os
from pathlib import Path


def pack_files(output_path, input_files):
    # Make sure all input files exist
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

    # Header format (little-endian)
    # Magic: 4 bytes "ASST"
    # Version: 1 byte
    # File count: 2 bytes (unsigned short)
    # For each file:
    #   name: 32 bytes (UTF-8, null-padded)
    #   offset: 4 bytes (unsigned int) from start of bin
    #   size: 4 bytes (unsigned int)
    ENTRY_FMT = '<32sII'  # name, offset, size
    entry_size = struct.calcsize(ENTRY_FMT)

    # Calculate header size
    header_size = 4 + 1 + 2 + num_files * entry_size

    # Read all files into memory and build entries
    entries = []
    blobs = []
    current_offset = header_size

    for filepath in input_files:
        with open(filepath, 'rb') as f:
            data = f.read()
        size = len(data)

        # Truncate/pad filename to 32 bytes
        name = os.path.basename(filepath).encode('utf-8')
        if len(name) > 31:
            name = name[:31] + b'\0'
        else:
            name = name + b'\0' * (32 - len(name))

        entries.append((name, current_offset, size))
        blobs.append(data)
        current_offset += size

    # Write the .bin file
    with open(output_path, 'wb') as out:
        # Magic and header info
        out.write(b'ASST')
        out.write(struct.pack('<B', 1))  # version
        out.write(struct.pack('<H', num_files))  # file count

        # Write file entries
        for name, offset, size in entries:
            out.write(struct.pack(ENTRY_FMT, name, offset, size))

        # Write raw file data
        for data in blobs:
            out.write(data)

    print(f"Created {output_path} with {num_files} files:")
    for name, offset, size in entries:
        name_str = name.split(b'\0')[0].decode('utf-8')
        print(f"  {name_str}: offset=0x{offset:08X}, size={size} bytes")



def get_files_pathlib(directory):
    # Returns list of Path objects for files only
    return [p for p in Path(directory).iterdir() if p.is_file()]


if __name__ == '__main__':
    effects_bin = "effects.bin"
    input_effects = get_files_pathlib('effects')

    music_bin = "music.bin"
    input_music = get_files_pathlib('music')

pack_files(effects_bin, input_effects)
pack_files(music_bin, input_music)
