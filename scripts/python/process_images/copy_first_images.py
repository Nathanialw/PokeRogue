#!/usr/bin/env python3
import os
import shutil
import sys
from pathlib import Path


def copy_first_images(source_dir, dest_dir):
    """
    Walk through source_dir, find all subdirectories, and copy the first image
    from each subdirectory into dest_dir maintaining the same folder structure.
    """
    # Common image extensions
    IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.bmp', '.tiff', '.webp', '.svg'}

    source_path = Path(source_dir)
    dest_path = Path(dest_dir)

    # Counter for statistics
    total_folders = 0
    images_copied = 0
    folders_without_images = 0

    # Walk through all directories
    for root, dirs, files in os.walk(source_path):
        # Skip the root directory itself
        if Path(root) == source_path:
            continue

        # Get all image files in current directory
        image_files = [f for f in files if Path(f).suffix.lower() in IMAGE_EXTENSIONS]

        if image_files:
            # Sort to ensure consistent "first" image
            image_files.sort()
            first_image = image_files[0]

            # Construct full paths
            src_file = Path(root) / first_image

            # Create corresponding destination path
            relative_path = Path(root).relative_to(source_path)
            dest_subdir = dest_path / relative_path
            dest_subdir.mkdir(parents=True, exist_ok=True)

            # Copy the file
            dest_file = dest_subdir / first_image
            shutil.copy2(src_file, dest_file)  # copy2 preserves metadata

            print(f"✓ Copied: {relative_path / first_image}")
            images_copied += 1
        else:
            print(f"✗ No images in: {Path(root).relative_to(source_path)}")
            folders_without_images += 1

        total_folders += 1

    # Print summary
    print("\n" + "=" * 50)
    print(f"SUMMARY:")
    print(f"Total folders processed: {total_folders}")
    print(f"Images copied: {images_copied}")
    print(f"Folders without images: {folders_without_images}")
    print(f"Destination: {dest_path.absolute()}")


def main():
    if len(sys.argv) != 3:
        print("Usage: python copy_first_images.py <source_folder> <destination_folder>")
        print("Example: python copy_first_images.py ./photos ./thumbnails")
        sys.exit(1)

    source_dir = sys.argv[1]
    dest_dir = sys.argv[2]

    # Check if source exists
    if not os.path.exists(source_dir):
        print(f"Error: Source folder '{source_dir}' does not exist! Creating one!")

    # Create destination if it doesn't exist
    os.makedirs(dest_dir, exist_ok=True)

    print(f"Scanning: {source_dir}")
    print(f"Copying to: {dest_dir}")
    print("-" * 50)

    copy_first_images(source_dir, dest_dir)


if __name__ == "__main__":
    main()
