#!/usr/bin/env python3
import os
import shutil
import sys
from pathlib import Path

from python.data.db_manager import get_images

image_types = ["item", "spell", "skill", "creature", "object", "trainer"]


def copy_first_images(entity_type):
    """
    Walk through source_dir, find all subdirectories, and copy the first image
    from each subdirectory into dest_dir maintaining the same folder structure.
    """
    # Common image extensions
    IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.bmp', '.tiff', '.webp', '.svg'}

    # Counter for statistics
    total_folders = 0
    images_copied = 0
    folders_without_images = 0

    images = get_images(entity_type)
    for image_path, name in images:
        src_file = image_path
        if src_file and src_file.find('/') > 0:
            img_name = image_path.split('/').pop()
            dest_dir = f"../assets_processed/{entity_type}s/staged/{name}/"
            os.makedirs(dest_dir, exist_ok=True)
            dest_file = f"{dest_dir}{img_name}"
            src_file = f"../{src_file}"
            print(src_file)
            print(dest_file)
            shutil.copy2(src_file, dest_file)  # copy2 preserves metadata
            images_copied += 1
        else:
            folders_without_images += 1
            pass

        total_folders += 1

    # Print summary
    print("\n" + "=" * 50)
    print(f"SUMMARY:")
    print(f"Total folders processed: {total_folders}")
    print(f"Images copied: {images_copied}")
    print(f"Folders without images: {folders_without_images}")


def main():


    for entity_type in image_types:
        copy_first_images(entity_type)


if __name__ == "__main__":
    main()
