#!/usr/bin/env python3
import os
from pathlib import Path
from python.data.db_manager import get_image, set_image



def copy_first_images(source_dir, entity_type):
    """
    Walk through source_dir, find all subdirectories, and copy the first image
    from each subdirectory into dest_dir maintaining the same folder structure.
    """
    # Common image extensions
    IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.bmp', '.tiff', '.webp', '.svg'}

    source_path = Path(source_dir)

    # Counter for statistics
    total_folders = 0
    images_copied = 0
    folders_without_images = 0

    # Walk through all directories
    source_path = Path(source_path).resolve()
    first_iteration = True

    for root, dirs, files in os.walk(source_path):
        # Skip the root directory itself on the first iteration
        if first_iteration:
            first_iteration = False
            continue  # Skip processing root, but still descend into subdirs

        # Get all image files in current directory
        image_files = [f for f in files if Path(f).suffix.lower() in IMAGE_EXTENSIONS]

        entity_name = root.split('/').pop()

        print(f"entity_dir == {entity_name}")

        # for entity_dir in root:
        hh = get_image(entity_type, entity_name)
        if not hh and image_files:
            print("ADDING")
            gg = set_image(entity_type, entity_name, image_files[0])
        else:
            print("SKIPPING")



        total_folders += 1

    # Print summary
    print("\n" + "=" * 50)
    print(f"SUMMARY:")
    print(f"Total folders processed: {total_folders}")
    print(f"Images copied: {images_copied}")
    print(f"Folders without images: {folders_without_images}")


def main():
    entity_types = ["creature", "object", "trainer", "item", "skill", "spell", "tile",]
    for entity_type in entity_types:
        source_dir = f"../assets_raw/sprites/{entity_type}"

        # Check if source exists
        if not os.path.exists(source_dir):
            print(f"Error: Source folder '{source_dir}' does not exist! Creating one!")

        # Create destination if it doesn't exist

        print(f"Scanning: {source_dir}")
        print("-" * 50)

        copy_first_images(source_dir, entity_type)


if __name__ == "__main__":
    main()
