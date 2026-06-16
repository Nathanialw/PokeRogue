from python.data.db_manager import populate_descriptions, init_database
from python.config.constants import IMAGE_TYPES

if __name__ == "__main__":
    init_database()
    for e in IMAGE_TYPES:
        print(e)
        populate_descriptions(e)
