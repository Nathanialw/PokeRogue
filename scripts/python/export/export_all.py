import os

from python.config import constants
from python.data.db_manager import init_database
from python.cartridge import make_dummy_constants
from . import export_creatures
from . import export_core_data
from . import export_battlers
from . import export_map_sprites
from . import export
from . import export_structs
from . import export_enums
from . import export_img_prompts


def run():
    init_database()
    if not os.path.exists(constants.INC_FOLDER):
        os.mkdir(constants.INC_FOLDER)
    make_dummy_constants.main()

    # CORE DATA
    bytes_count = []
    bytes_count_map_sprites = []
    counts = []

    # update enums
    export_enums.get_entity_enums("creature")
    export_enums.get_entity_enums("skill")
    export_enums.get_entity_enums("spell")
    export_enums.get_entity_enums("item")
    export_enums.get_entity_enums("object")
    export_enums.get_entity_enums("trainer")

    # image generation strings
    export_img_prompts.generate_data_from_db('creature')
    export_img_prompts.generate_data_from_db('skill')
    export_img_prompts.generate_data_from_db('spell')
    export_img_prompts.generate_data_from_db('item')
    export_img_prompts.generate_data_from_db('object')
    export_img_prompts.generate_data_from_db('trainer')

    # type strings
    export_core_data.write_types_inc()

    ################################################################################################################################################
    # CREATURES
    export_structs.creatures_skills("creature")
    export_structs.creatures_level_up_skills("creature")
    # creature name strings
    counts.append(export.name_to_c_array("creature"))
    # creature description strings
    export.desc_to_c_array("creature")
    # creature map sprites
    export.export_map_sprites_char("creature")
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("creature", 16))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("creature", 20))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("creature", 24))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("creature", 32))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("creature", 64))

    # creature type data
    export_creatures.export_types_to_c_array()
    # creature battlers front
    bytes_count.append(export_battlers.export_image_data("creature", 16, 16, "front"))
    bytes_count.append(export_battlers.export_image_data("creature", 16, 16, "back"))

    bytes_count.append(export_battlers.export_image_data("creature", 64, 64, "front"))
    bytes_count.append(export_battlers.export_image_data("creature", 64, 64, "back"))

    ################################################################################################################################################
    # ABILITIES
    # ability struct data
    export_structs.abilities("skill")
    # ability functions headers
    export.func_c_headers("skill", "Skill", "ActionOutcome", "HardwareInterface hardware,  MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData")
    # ability animation functions
    export.funcs_to_c_animations_array("skill", "attack")
    export.funcs_to_c_animations_array("skill", "struck")
    # ability animation functions header
    export.func_c_animation_headers("skill", "attack", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    export.func_c_animation_headers("skill", "struck", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    # ability name strings
    counts.append(export.name_to_c_array("skill"))
    # ability description strings
    export.desc_to_c_array("skill")
    # ability icons
    bytes_count.append(export_battlers.export_image_data("skill", 16, 16))
    bytes_count.append(export_battlers.export_image_data("skill", 64, 64))

    ################################################################################################################################################
    # SPELLS
    # spell struct data
    export_structs.spells("spell")
    # spell functions headers
    export.func_c_headers("spell", "CastBattle", "ActionOutcome", "HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData")
    export.func_c_headers("spell", "CastMap", "ActionOutcome", "HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData")
    # spell animation functions
    export.funcs_to_c_animations_array("spell", "attack")
    export.funcs_to_c_animations_array("spell", "struck")
    # spell animation functions header
    export.func_c_animation_headers("spell", "attack", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    export.func_c_animation_headers("spell", "struck", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    # spell name strings
    counts.append(export.name_to_c_array("spell"))
    # spell description strings
    export.desc_to_c_array("spell")
    # spell icons
    bytes_count.append(export_battlers.export_image_data("spell", 16, 16))
    bytes_count.append(export_battlers.export_image_data("spell", 64, 64))

    ################################################################################################################################################
    # ITEMS
    # item struct data
    export_structs.items("item")
    # item map sprites header
    export.export_map_sprites_char("item")
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("item", 16))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("item", 20))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("item", 24))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("item", 32))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("item", 64))

    # item functions header
    export.func_c_headers("item", "UseBattle", "ActionOutcome", "HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index")
    export.func_c_headers("item", "UseMap", "ActionOutcome", "HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index")
    # item animation functions
    export.funcs_to_c_animations_array("item", "attack")
    export.funcs_to_c_animations_array("item", "struck")
    # item animation functions header
    export.func_c_animation_headers("item", "attack", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    export.func_c_animation_headers("item", "struck", "bool", "GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker")
    # item name strings
    counts.append(export.name_to_c_array("item"))
    # item description strings
    export.desc_to_c_array("item")
    # item icons
    bytes_count.append(export_battlers.export_image_data("item", 16, 16))
    bytes_count.append(export_battlers.export_image_data("item", 64, 64))

    ################################################################################################################################################
    # OBJECTS
    export_structs.objects("object")
    # object map sprites header
    export.export_map_sprites_char("object")
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("object", 16))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("object", 20))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("object", 24))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("object", 32))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("object", 64))

    # object functions header
    export.func_c_headers("object", "Interact", "ActionOutcome", "HardwareInterface hardware, EntityId object_id, EntityId e_id, ObjectData objectData")
    # object name strings
    counts.append(export.name_to_c_array("object"))
    # object description strings
    export.desc_to_c_array("object")
    # object icons
    bytes_count.append(export_battlers.export_image_data("object", 16, 16))
    bytes_count.append(export_battlers.export_image_data("object", 64, 64))

    ################################################################################################################################################
    # TRAINERS
    export.export_map_sprites_char("trainer")
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("trainer", 16))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("trainer", 20))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("trainer", 24))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("trainer", 32))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("trainer", 64))

    # trainer name strings
    counts.append(export.name_to_c_array("trainer"))
    # trainer description strings
    export.desc_to_c_array("trainer")
    # trainer map sprites
    bytes_count.append(export_battlers.export_image_data("trainer", 16, 16))
    bytes_count.append(export_battlers.export_image_data("trainer", 64, 64))

    ################################################################################################################################################
    # TILES
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("tile", 16))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("tile", 20))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("tile", 24))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("tile", 32))
    bytes_count_map_sprites.append(export_map_sprites.export_image_data("tile", 64))

    export.func_c_headers("tile", "TIleStepOn", "bool", "HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y")
    export.func_c_headers("tile", "TIleStepOff", "bool", "HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y")

    # tile name strings
    # counts.append(export.name_to_c_array("tile"))
    # tile description strings
    # export.desc_to_c_array("tile")
    # tile map sprites
    # bytes_count.append(export_battlers.export_image_data("tile"))
    counts.append(export_enums.get_entity_enums("tile"))


    # enums
    export_enums.get_data_enums("item_types")
    export_enums.get_data_enums("biomes")
    export_enums.get_data_enums("themes")
    export_enums.get_data_enums("types")
    export_enums.get_data_enums("races")
    export_enums.get_data_enums("pathing_types")
    export_enums.get_data_enums("tile_types")


    export.export_constants(bytes_count, counts, bytes_count_map_sprites)


run()
