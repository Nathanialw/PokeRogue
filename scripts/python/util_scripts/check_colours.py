from PIL import Image
import numpy as np


def count_unique_colors(image_path):
    # Open image and convert to RGB (ignores alpha for color count)
    img = Image.open(image_path).convert("RGB")
    pixels = np.array(img)

    # Reshape to list of [R,G,B] and find unique rows
    unique_colors = np.unique(pixels.reshape(-1, 3), axis=0)
    num_unique = len(unique_colors)

    print(f"Number of unique colors: {num_unique}")

    if num_unique <= 50:  # only print if reasonable
        print("Unique colors (RGB):")
        for color in unique_colors:
            print(tuple(color))

    return num_unique


# Run it
count_unique_colors("../col_indexed_output-custom-64b.png")  # replace with your file
