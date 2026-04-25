#!/usr/bin/env python3
"""
batch_remove_background.py

Processes all images in subfolders, maintaining folder structure.
For each input folder, creates a corresponding folder in processed_images/
and saves threshold variants there.
"""

import os
import sys
from PIL import Image
from transparent_background import Remover


def process_folder(input_folder: object, base_output_folder, remover, thresholds):
    """
    Process all images in a specific folder, saving to corresponding output folder
    """
    # Create corresponding output folder path
    rel_path = os.path.relpath(input_folder, start=os.path.dirname(input_folder))
    if rel_path == '.':
        # If it's the root folder, use the folder name
        output_subfolder = os.path.join(base_output_folder, os.path.basename(input_folder))
    else:
        output_subfolder = os.path.join(base_output_folder, rel_path)

    os.makedirs(output_subfolder, exist_ok=True)

    # Get all images in this folder
    image_extensions = {'.jpg', '.jpeg', '.png', '.bmp', '.tiff', '.webp'}
    image_files = []

    for file in os.listdir(input_folder):
        file_path = os.path.join(input_folder, file)
        if os.path.isfile(file_path):
            ext = os.path.splitext(file)[1].lower()
            if ext in image_extensions:
                image_files.append(file)

    if not image_files:
        return 0  # No images in this folder

    print(f"\nProcessing folder: {input_folder}")
    print(f"  Output folder: {output_subfolder}")
    print(f"  Found {len(image_files)} images")

    # Process each image
    processed_count = 0
    for img_idx, filename in enumerate(image_files, 1):
        input_path = os.path.join(input_folder, filename)
        print(f"\n  [{img_idx}/{len(image_files)}] Processing: {filename}")

        try:
            img = Image.open(input_path).convert('RGB')
            name, ext = os.path.splitext(filename)

            for thresh in thresholds:
                out = remover.process(img, threshold=thresh)
                out_name = f"{name}_th{thresh:.3f}{ext}"
                out_path = os.path.join(output_subfolder, out_name)
                out.save(out_path)
                print(f"    Saved: {out_name}")

            processed_count += 1

        except Exception as e:
            print(f"    Error: {e}")
            continue

    return processed_count


def main():
    # Check command line arguments
    if len(sys.argv) < 2:
        print("Usage: python batch_remove_background.py <input_root_folder>")
        print("  Example: python batch_remove_background.py ./images")
        print("  This will create ./processed_images/ with the same folder structure")
        sys.exit(1)

    input_root = sys.argv[1]  # =
    base_output_folder = sys.argv[2]  # =

    # input_root = sys.argv[1]

    if not os.path.isdir(input_root):
        print(f"Error: '{input_root}' is not a valid directory")
        sys.exit(1)

    # Generate 10 thresholds from 0.01 to 0.5
    # thresholds = [round(0.01 + i * (0.49 / 9), 3) for i in range(10)]
    thresholds = [0.1]
    print(f"Using thresholds: {[f'{t:.3f}' for t in thresholds]}")

    # Create base output folder
    os.makedirs(base_output_folder, exist_ok=True)

    # Initialize remover
    print("\nInitializing Remover...")
    remover = Remover(resize='dynamic', device='cuda')

    # Walk through all folders
    total_folders = 0
    total_images = 0

    print(f"\nScanning folder: {input_root}")

    for root, dirs, files in os.walk(input_root):
        # Skip the base output folder if it's inside input_root
        if base_output_folder in root:
            continue

        # Process this folder
        processed = process_folder(root, base_output_folder, remover, thresholds)

        if processed > 0:
            total_folders += 1
            total_images += processed

    print(f"\n{'=' * 50}")
    print(f"Processing complete!")
    print(f"Total folders processed: {total_folders}")
    print(f"Total images processed: {total_images}")
    print(f"Output saved to: {base_output_folder}/")
    print(f"Folder structure maintained with threshold variants in each folder")


if __name__ == "__main__":
    main()
