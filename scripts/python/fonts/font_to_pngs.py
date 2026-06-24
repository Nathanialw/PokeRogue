from PIL import Image, ImageFont, ImageDraw, ImageChops


def save_individual_chars(text, font_path, font_size, output_prefix="char"):
    # Load the monospace font
    try:
        font = ImageFont.truetype(font_path, font_size)
    except IOError:
        print("Font file not found. Using default.")
        font = ImageFont.load_default()

    for i, char in enumerate(text):
        # Skip whitespace if desired, or handle it as an empty image
        if char.strip() == "":
            continue

        # 1. Create a temporary large image to draw the character
        # We make it large enough to fit any character comfortably
        temp_img = Image.new('RGBA', (font_size * 2, font_size * 2), (0, 0, 0, 0))
        draw = ImageDraw.Draw(temp_img)

        # 2. Draw the character
        # Using textbbox to get exact dimensions for cropping later
        bbox = draw.textbbox((0, 0), char, font=font)
        char_width = bbox[2] - bbox[0]
        char_height = bbox[3] - bbox[1]

        # Resize temp image to exact character size + small padding
        final_img = Image.new('RGBA', (char_width + 4, char_height + 4), (0, 0, 0, 0))
        final_draw = ImageDraw.Draw(final_img)

        # Draw at (2, 2) to account for padding
        final_draw.text((2, 2), char, font=font, fill='black')

        # 3. Save the individual character
        # Sanitize filename for special characters
        safe_char = "".join(c if c.isalnum() else f"_{ord(c)}_" for c in char)
        filename = f"{output_prefix}_{safe_char}.png"
        final_img.save(filename)
        print(f"Saved: {filename}")


# Usage
text_to_convert = "Monospace"
# Replace with a path to a real monospace font on your system
# Windows: "C:/Windows/Fonts/cour.ttf"
# macOS: "/Library/Fonts/Courier New.ttf"
# Linux: "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf"
font_path = "Courier-New"

save_individual_chars(text_to_convert, font_path, 48)

#font="Courier-New"
#for c in H e l o; do
  #convert -font "$font" -pointsize 48 -background none -fill black label:"$c" "char_$c.png"
#done
