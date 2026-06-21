# Generated from creature_buff_img_prompts table
# Do not edit manually

Creature_buffs = [
    "BERSERK",
    "FIRE_EATING",
    "FLYING",
    "HASTED",
    "INVIGORATE",
    "INVISIBLE",
    "LIFELINK",
    "MAGIC_SHIELD",
    "REFLECT",
    "REGENERATION",
    "REVITALIZE",
    "SPELL_POWER",
    "STONESKIN",
    "THORNS",
    "VAMPIRIC_AURA",
    "WARDED",
]

Creature_buffsDict = [
   { "name": 'BERSERK', 'prompt': "BERSERK"},
   { "name": 'FIRE_EATING', 'prompt': "fire_eating"},
   { "name": 'FLYING', 'prompt': "FLYING"},
   { "name": 'HASTED', 'prompt': "hasted"},
   { "name": 'INVIGORATE', 'prompt': "INVIGORATE"},
   { "name": 'INVISIBLE', 'prompt': "INVISIBLE"},
   { "name": 'LIFELINK', 'prompt': "LIFELINK"},
   { "name": 'MAGIC_SHIELD', 'prompt': "MAGIC_SHIELD"},
   { "name": 'REFLECT', 'prompt': "REFLECT"},
   { "name": 'REGENERATION', 'prompt': "REGENERATION"},
   { "name": 'REVITALIZE', 'prompt': "REVITALIZE"},
   { "name": 'SPELL_POWER', 'prompt': "SPELL_POWER"},
   { "name": 'STONESKIN', 'prompt': "STONESKIN"},
   { "name": 'THORNS', 'prompt': "THORNS"},
   { "name": 'VAMPIRIC_AURA', 'prompt': "VAMPIRIC_AURA"},
   { "name": 'WARDED', 'prompt': "WARDED"},
]

CREATURE_BUFFS_BASE_PROMPT = (
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
VIEW_ANGLES = [ "strict angled front view, 45 degree lateral pose, full buff in frame", "strict subject turned slightly askew, front view, 45 degree lateral pose, full buff in frame", "front  three-quarter view, mostly front but slight side visible", ]

# 
# VIEW_ANGLES = [
#     "strict angled front view, 45 degree lateral pose, full body in frame",
#     "strict subject turned slightly askew, front view, 45 degree lateral pose, full body in frame",
#     "front  three-quarter view, mostly front but slight side visible",
# ]

# Generate all combinations
VARIANTS = [
    f"{angle + ', ' if angle else ''}{style}, neutral background"
    for style in LIGHTING_STYLES
    for angle in VIEW_ANGLES
]
              
NEGATIVE_PROMPT = (
    "deformed iris, deformed pupils, semi-realistic, cgi, 3d, render, sketch, cartoon, drawing), text, cropped, out of frame, worst quality, low quality, jpeg artifacts, ugly, duplicate, morbid, mutilated, extra fingers, mutated hands, poorly drawn hands, poorly drawn face, mutation, deformed, blurry, dehydrated, bad anatomy, bad proportions, extra limbs, cloned face, disfigured, gross proportions, malformed limbs, missing arms, missing legs, extra arms, extra legs, fused fingers, too many fingers, long neck, brown men, black men, asian men"
)
                