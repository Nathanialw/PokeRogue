//
// Created by nathanial on 5/19/26.
//

#include "map_memory_access.h"
#include "lib_memory.h"

#include "types.h"

#include "core_ram.h"
#include "data_constants_memory.inc"


/**********************************************************************************************************************/
/**     MAP
**********************************************************************************************************************/
SET_MEMORY(".map")
void Flash_GetBiomeTile(MemoryInterface memory, Tile* tile, uint8_t biomeType, uint8_t tile_id)
{
    memory.GetRom(CHAR_SPRITES_BIOMES_POSITION + (g_core.biome * (NUM_TILES * sizeof(Tile))) + (tile_id * sizeof(Tile)), tile->bytes, sizeof(Tile));
}

/**********************************************************************************************************************/
/*      SPRITES
**********************************************************************************************************************/
SET_MEMORY(".map")
void Flash_GetTextSpriteMetadata(MemoryInterface memory, Sprite* sprite, ObjectsTypes type, uint8_t index)
{
    memory.GetRom(CHAR_SPRITES_TRAINERS_POSITION + (index * sizeof(Sprite)), sprite->bytes, sizeof(Sprite));
}

SET_MEMORY(".map")
void Flash_GetMapTileMetadata(MemoryInterface memory, SpriteFrames* sprite, uint8_t index)
{
    memory.GetRom(SPRITE_64X64_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
}

SET_MEMORY(".map")
void Flash_GetMapTile(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite)
{
    memory.GetRom(SPRITE_64X64_TILE_POSITION + sprite->index, bytes, sprite->size);
}


SET_MEMORY(".map")
void Flash_GetMapSpriteMetadata(MemoryInterface memory, SpriteFrames* sprite, ObjectsTypes type, uint8_t index)
{
    if (type == ITEM)
        memory.GetRom(SPRITE_64X64_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_64X64_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_64X64_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_64X64_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
}

SET_MEMORY(".map")
void Flash_GetMapSprite(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite, ObjectsTypes type)
{
    if (type == ITEM)
        memory.GetRom(SPRITE_64X64_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_64X64_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_64X64_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_64X64_TRAINER_POSITION + sprite->index, bytes, sprite->size);
}


/**********************************************************************************************************************/
/*      Text
**********************************************************************************************************************/

/**********************************************************************************************************************/
/*  for fixed length string strings in an array
 *  use length * index to get the offset
**********************************************************************************************************************/
// UI
SET_MEMORY(".map")
void Flash_GetOptionText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index)
{
    memory.GetRom(STRINGS_MENU_OPTIONS_POSITION + (SMALL_STRINGS * index), textBuffer, SMALL_STRINGS);
}


SET_MEMORY(".map")
void Flash_GetCreatureDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_CREATURES_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}


SET_MEMORY(".map")
void Flash_GetObjectDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_OBJECTS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}


SET_MEMORY(".map")
void Flash_GetItemDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_ITEMS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}


SET_MEMORY(".map")
void Flash_GetSpellDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_SPELLS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}


SET_MEMORY(".map")
void Flash_GetSkillDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_SKILLS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}

SET_MEMORY(".map")
void Flash_GetTrainerDescription(MemoryInterface memory, char* text, uint8_t index)
{
    memory.GetRom(STRINGS_DESCRIPTIONS_TRAINERS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);
}

SET_MEMORY(".map")
void Flash_GetTypeName(MemoryInterface memory, char* text, uint8_t typeIndex)
{
    memory.GetRom(STRINGS_TYPES_POSITION + (SMALL_STRINGS * typeIndex), (uint8_t*)text, SMALL_STRINGS);
}
