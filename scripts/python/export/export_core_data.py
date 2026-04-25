from python.data import db_manager
from ..config import constants

model_name = constants.MODEL_NAMES['mistral']

# Show database stats
stats = db_manager.get_model_stats(model_name)
if stats:
    print(f"\nDatabase stats for {model_name}:")
    print(f"  Total descriptions: {stats[0][0]}")
    print(f"  Unique creatures: {stats[0][3]}")
    print(f"  Average words: {stats[0][1]:.1f}")


def write_types_inc():
    types = db_manager.get_type_strings()

    with open(constants.OUTPUT_TYPE_STRINGS, 'w') as f:
        for type_str in types:
            f.write(f'"{type_str[0]}\\0",\n')  # Always add comma

    print(f"📄 Exported {len(types)} types to {constants.OUTPUT_TYPE_STRINGS}")



