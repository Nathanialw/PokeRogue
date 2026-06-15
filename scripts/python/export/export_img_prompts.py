# generate_data_from_db.py
import sqlite3

from numpy.core.defchararray import capitalize, upper

from ..config import constants

DB_FILE = constants.DB_FILE


def generate_data_from_db(entity):
    start_prompt = {
        'creature': "fantasy creature, tasteful nudity male, nude female or nude trans-woman, creature fully visible, creature composition, isolated subject, single creature, no cropping, highly detailed dark fantasy, sharp focus, ",
        'environment_object': "photo-realistic hi fidelity detailed, fantasy environment_object, subject fully visible, centered composition, isolated subject, single subject, no cropping, highly detailed dark fantasy, sharp focus, ",
        'item': "photo-realistic hi fidelity detailed, fantasy item, item fully visible, centered composition, isolated item, single subject, no cropping, highly detailed dark fantasy, sharp focus, ",
        'object': "photo-realistic hi fidelity detailed, fantasy object, object fully visible, centered composition, isolated subject, single object, no cropping, highly detailed dark fantasy, sharp focus, ",
        'spell': "photo-realistic hi fidelity detailed, fantasy spell demonstration, subject fully visible, centered composition, isolated subject, single subject, no cropping, highly detailed dark fantasy, sharp focus, ",
        'skill': "photo-realistic hi fidelity detailed, fantasy skill demonstration, subject fully visible, centered composition, isolated subject, single subject, no cropping, highly detailed dark fantasy, sharp focus, ",
        'trainer': "fantasy adventurer, tasteful nudity male, nude female or nude trans-woman, subject fully visible, centered composition, isolated subject, single subject, no cropping, highly detailed dark fantasy, sharp focus, ",
    }

    table_in = f"{entity}_descriptions"
    file_out = f"python/data/_{entity}_img_data.py"

    f"""Generate {entity} img_prompts table"""

    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()

    # Get all distinct creature names
    cursor.execute(f'SELECT DISTINCT name FROM {entity}s ORDER BY name')
    entities = [row[0] for row in cursor.fetchall()]

    # Get the latest prompt for each creature (or you could get all)
    prompts = {}
    for e in entities:
        cursor.execute(f'''
            SELECT description FROM {table_in} 
            WHERE name = ? 
            ORDER BY timestamp DESC 
            LIMIT 1
        ''', (e,))
        result = cursor.fetchone()
        if result:
            prompts[e] = result[0]
        else:
            RED = '\033[91m'
            RESET = '\033[0m'
            print(f"{RED} {e} image prompt not found {RESET}")
            prompts[e] = f"{e}"

    conn.close()

    # Generate the Python file
    with open(file_out, "w", encoding='utf-8') as f:
        f.write(f"# Generated from {entity}_img_prompts table\n")
        f.write("# Do not edit manually\n\n")

        entity_type = entity.capitalize() + 's'

        # Write Creatures array
        f.write(f"{entity_type} = [\n")
        for e in entities:
            f.write(f'    "{e}",\n')
        f.write("]\n\n")

        # Write CreaturesDict dictionary
        f.write(f"{entity_type}Dict = [\n")
        for e, prompt in prompts.items():
            # Escape the prompt for Python string
            escaped_prompt = prompt.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
            f.write('   { ' + f"\"name\": '{e}', 'prompt': \"{escaped_prompt}\"" + "},\n")
        f.write("]\n")

        f.write(f'''
# {upper(entity_type)}_BASE_PROMPT = (
#     # f"photo-realistic hi fidelity detailed, "
#     "fantasy {entity}, full body visible, centered composition, isolated creature, "
#     "single subject, no cropping, highly detailed dark fantasy, sharp focus, "
# )

{upper(entity_type)}_BASE_PROMPT = (
    f"general details that can be seen from afar, "
    # "fantasy item, full body visible, centered composition, isolated creature, "
    # "single subject, no cropping, highly detailed dark fantasy, sharp focus, "
    \"{start_prompt[entity]}\"
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
    # "",  # front/full face (implied)
    # "back view",
    "strict side profile view, 90 degree lateral pose, full side silhouette",
    "three-quarter side view, strong 45 degree angle over-the-shoulder",
    "rear three-quarter view, mostly back but slight side visible",
    # "direct rear view, seen from straight behind, full back, over-the-shoulder",
    # "looking back over shoulder, body in profile but head turned",
]

# Generate all combinations
VARIANTS = [
'''+
'    f'+"\"{angle + ', ' if angle else ''}{style}, neutral background\""
'''
    for style in LIGHTING_STYLES
    for angle in VIEW_ANGLES
]
              
NEGATIVE_PROMPT = (
  "deformed iris, deformed pupils, semi-realistic, cgi, 3d, render, sketch, cartoon, drawing, anime), text, cropped, out of frame, worst quality, low quality, jpeg artifacts, ugly, duplicate, morbid, mutilated, extra fingers, mutated hands, poorly drawn hands, poorly drawn face, mutation, deformed, blurry, dehydrated, bad anatomy, bad proportions, extra limbs, cloned face, disfigured, gross proportions, malformed limbs, missing arms, missing legs, extra arms, extra legs, fused fingers, too many fingers, long neck, brown men, black men, asian men"
)
      ''')

    print(f"✅ Generated {file_out} with {len(entities)} creatures")
