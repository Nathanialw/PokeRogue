# Generated from creature_debuff_img_prompts table
# Do not edit manually

Creature_debuffs = [
    "BLEED",
    "BLIND",
    "BURNED",
    "CURSE",
    "DISARM",
    "DISEASE",
    "ENFEEBLED",
    "FEAR",
    "FROZEN",
    "PARALYZED",
    "PETRIFIED",
    "POISON",
    "ROOT",
    "SAPPED",
    "SLEEP",
    "SLOWED",
]

Creature_debuffsDict = [
   { "name": 'BLEED', 'prompt': "BLEED"},
   { "name": 'BLIND', 'prompt': "blind"},
   { "name": 'BURNED', 'prompt': "burned"},
   { "name": 'CURSE', 'prompt': "curse"},
   { "name": 'DISARM', 'prompt': "DISARM"},
   { "name": 'DISEASE', 'prompt': "disease"},
   { "name": 'ENFEEBLED', 'prompt': "ENFEEBLED"},
   { "name": 'FEAR', 'prompt': "fear"},
   { "name": 'FROZEN', 'prompt': "frozen"},
   { "name": 'PARALYZED', 'prompt': "paralyzed"},
   { "name": 'PETRIFIED', 'prompt': "PETRIFIED"},
   { "name": 'POISON', 'prompt': "poison"},
   { "name": 'ROOT', 'prompt': "ROOT"},
   { "name": 'SAPPED', 'prompt': "SAPPED"},
   { "name": 'SLEEP', 'prompt': "sleep"},
   { "name": 'SLOWED', 'prompt': "slowed"},
]

CREATURE_DEBUFFS_BASE_PROMPT = (
    f"bold details, with a diverse colour palette, black background, "
    "photo-realistic hi fidelity detailed, fantasy debuff icon demonstration for a debuff icon icon, subject clearly visible, centered composition, no cropping, highly detailed dark fantasy, sharp focus, "
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
      