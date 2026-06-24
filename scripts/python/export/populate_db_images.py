#!/usr/bin/env python3
import os
import shutil

from python.data.db_manager import get_images, get_back_images
from python.config.constants import IMAGE_TYPES_0, IMAGE_TYPES_1



def copy_selected_images(entity_type):
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
    if not images:
        print(f"No images found for {entity_type}")
        return

    for image_path, name in images:
        if not image_path:
            image_path = "assets_raw/sprites/default/default.png"

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


def copy_front_images(entity_type):
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
    if not images:
        print(f"No images found for {entity_type}")
        return

    for image_path, name in images:
        if not image_path:
            image_path = "assets_raw/sprites/default/default.png"

        src_file = image_path
        if src_file and src_file.find('/') > 0:
            img_name = image_path.split('/').pop()
            dest_dir = f"../assets_processed/{entity_type}s/staged/front/{name}/"
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


def copy_back_images(entity_type):
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

    images = get_back_images(entity_type)
    if not images:
        print(f"No images found for {entity_type}")
        return

    for image_path, name in images:
        if not image_path:
            image_path = "assets_raw/sprites/default/default.png"

        src_file = image_path
        if src_file and src_file.find('/') > 0:
            img_name = image_path.split('/').pop()
            dest_dir = f"../assets_processed/{entity_type}s/staged/back/{name}/"
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
    for entity_type in IMAGE_TYPES_0:
        copy_selected_images(entity_type)

    for entity_type in IMAGE_TYPES_1:
        copy_front_images(entity_type)
        copy_back_images(entity_type)


if __name__ == "__main__":
    main()
