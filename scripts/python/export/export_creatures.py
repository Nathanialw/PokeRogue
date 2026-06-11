from python.data import db_manager
from python.config import constants


def export_types_to_c_array():
    """Export the database contents to a C array file"""
    filename = f"{constants.DATA_INC_FOLDER}/data_types_creatures.inc"

    entities = db_manager.get_creature_types()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write("// Generated creature types\n")
        f.write(f"// Database contains {len(entities)} total entities\n\n")

        # Write individual constants
        f.write("// Individual types strings\n")
        for i, (formatted, type_0, type_1) in enumerate(entities):
            f.write(f"{{ .typeA = {type_0}, .typeB = {type_1}}}, //{formatted}\n")

        f.write("\n")

        f.write(f"//ALL_TYPES_COUNT = {len(entities)};\n")

    print(f"📄 Exported {len(entities)} types to {filename}")

