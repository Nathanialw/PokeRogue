from python.data import db_manager
from python.config import constants


def export_types_to_c_array():
    """Export the database contents to a C array file"""
    filename = f"{constants.INC_FOLDER}/types_creatures.inc"

    types = db_manager.get_creature_types()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write("// Generated creature types\n")
        f.write(f"// Database contains {len(types)} total types\n\n")

        # Write individual constants
        f.write("// Individual types strings\n")
        desc_vars = []
        for i, (formatted, type_0, type_1) in enumerate(types):
            f.write("{" + f" .typeA = {type_0}, .typeB = {type_1} " + "},\n")

        f.write("\n")

        f.write(f"//ALL_TYPES_COUNT = {len(desc_vars)};\n")

    print(f"📄 Exported {len(types)} types to {filename}")

