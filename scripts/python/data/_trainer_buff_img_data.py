# Generated from trainer_buff_img_prompts table
# Do not edit manually

Trainer_buffs = [
    "FLOOR_MEMORY",
    "HASTE",
    "HOVERING",
    "INVISIBILITY",
    "LIGHT",
    "LINE_OF_SIGHT",
    "REPEL",
    "SENSE_MONSTER",
    "TRAP_VISION",
    "WALL_WALKING",
    "WATER_BREATHING",
    "WATER_WALK",
]

Trainer_buffsDict = [
   { "name": 'FLOOR_MEMORY', 'prompt': "FLOOR_MEMORY"},
   { "name": 'HASTE', 'prompt': "HASTE"},
   { "name": 'HOVERING', 'prompt': "HOVERING"},
   { "name": 'INVISIBILITY', 'prompt': "INVISIBILITY"},
   { "name": 'LIGHT', 'prompt': "LIGHT"},
   { "name": 'LINE_OF_SIGHT', 'prompt': "LINE_OF_SIGHT"},
   { "name": 'REPEL', 'prompt': "REPEL"},
   { "name": 'SENSE_MONSTER', 'prompt': "SENSE_MONSTER"},
   { "name": 'TRAP_VISION', 'prompt': "TRAP_VISION"},
   { "name": 'WALL_WALKING', 'prompt': "WALL_WALKING"},
   { "name": 'WATER_BREATHING', 'prompt': "WATER_BREATHING"},
   { "name": 'WATER_WALK', 'prompt': "WATER_WALK"},
]

TRAINER_BUFFS_BASE_PROMPT = (
    f"bold details, with a diverse colour palette, black background, "
    "photo-realistic hi fidelity detailed, fantasy buff icon demonstration for a buff icon, subject clearly visible, centered composition, no cropping, highly detailed dark fantasy, sharp focus, "
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
      