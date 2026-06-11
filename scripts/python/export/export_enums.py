from python.data import db_manager
from python.config import constants


def get_entity_enums(entity):
    filename = f"{constants.TYPES_INC_FOLDER}/data_enum_{entity}s.inc"
    names = db_manager.get_entity_enums(entity)

    count = 0
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(names)} total used {entity}s\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")
        for n in names:
            f.write(f"{n}, //{count} \n")
            count+=1

        f.write("\n")
        f.write(f"//ALL_NAMES_COUNT = {len(names)};\n")

    return count

def get_data_enums(entity):
    filename = f"{constants.TYPES_INC_FOLDER}/data_enum_{entity}.inc"
    names = db_manager.get_data_enums(entity)

    count = 0
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(names)} total used {entity}\n\n")

        # Write individual constants
        f.write(f"// Individual {entity} data\n")
        for n in names:
            f.write(f"{n[1]}, //{n[0]}\n")
            count+=1

        f.write("\n")
        f.write(f"//ALL_NAMES_COUNT = {len(names)};\n")

    return count




