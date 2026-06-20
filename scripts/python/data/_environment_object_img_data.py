# Generated from environment_object_img_prompts table
# Do not edit manually

Environment_objects = [
    "CLOUD_ACID",
    "CLOUD_POISON_GAS",
    "CLOUD_SMOKE",
    "FIRE_BLAZING",
    "FIRE_SMALL",
    "FLOOR_CRUMBLING",
]

Environment_objectsDict = [
   { "name": 'CLOUD_ACID', 'prompt': "A swirling emerald mist coils upward, reeking of sulfur and withering all life in its path with a touch."},
   { "name": 'CLOUD_POISON_GAS', 'prompt': "A swirling, ethereal mist that shifts colors with the phases of the moon and whispers secrets to those who dare to listen."},
   { "name": 'CLOUD_SMOKE', 'prompt': "A swirling, ethereal mist that shifts colors with the phases of the moon and whispers secrets to those who dare to listen."},
   { "name": 'FIRE_BLAZING', 'prompt': "a blazing orange fire"},
   { "name": 'FIRE_SMALL', 'prompt': "a small orange fire"},
   { "name": 'FLOOR_CRUMBLING', 'prompt': "swveral black cracks on a white floor"},
]

ENVIRONMENT_OBJECTS_BASE_PROMPT = (
    f"bold details, with a diverse colour palette, black background, "
    "photo-realistic hi fidelity detailed, fantasy environment_object, subject fully visible, centered composition, isolated subject, single subject, no cropping, highly detailed dark fantasy, sharp focus, "
)

LIGHTING_STYLES = [
    # "dramatic rim lighting",
    # "moody low-key lighting, subtle fog",
    "good lighting with high visibility",
    "clear lighting with realistic colours",
    # "ancient parchment illustration style, inked linework",
    # "torchlit dungeon lighting",
    # "volumetric light shafts",
    # "soft studio lighting",

    "high contrast lighting, crisp image",
    # "grimdark concept art, gritty texture",
    # "moonlit night lighting",
    # "overcast diffuse lighting",
]

# View angles - expanded with back-side angles
VIEW_ANGLES = [
    "strict angled front view, 45 degree lateral pose, full body in frame",
    "strict subject turned slightly askew, front view, 45 degree lateral pose, full body in frame",
    "front  three-quarter view, mostly front but slight side visible",
]

# Generate all combinations
VARIANTS = [
    f"{angle + ', ' if angle else ''}{style}, neutral background"
    for style in LIGHTING_STYLES
    for angle in VIEW_ANGLES
]
              
NEGATIVE_PROMPT = (
  "deformed iris, deformed pupils, semi-realistic, cgi, 3d, render, sketch, cartoon, drawing, anime), text, cropped, out of frame, worst quality, low quality, jpeg artifacts, ugly, duplicate, morbid, mutilated, extra fingers, mutated hands, poorly drawn hands, poorly drawn face, mutation, deformed, blurry, dehydrated, bad anatomy, bad proportions, extra limbs, cloned face, disfigured, gross proportions, malformed limbs, missing arms, missing legs, extra arms, extra legs, fused fingers, too many fingers, long neck, brown men, black men, asian men"
)
      