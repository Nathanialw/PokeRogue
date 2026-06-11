//
// Created by nathanial on 5/15/26.
//

#include "core_memory_access.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "data_constants_memory.inc"
#include "enums.h"
#include "types.h"



// #define MEMORY_PRINT

#if defined(MEMORY_PRINT)
SET_MEMORY(".core.data")
static const char str_spawn_creature_type[] = "0x%2x,";

SET_MEMORY(".core.data")
static const char begin[] = "begin\n";

SET_MEMORY(".core.data")
static const char new_line[] = "\n";
#endif


/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".core")
void Flash_GetSkill(MemoryInterface memory, CreatureSkillLearnLevels* c, Type creatureType, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.levelUpSkills[creatureType][index];
#else
    const uint8_t length = sizeof(CreatureSkillLearnLevels);
    memory.GetRom(GAME_DATA_LEVEL_UP_SKILLS_POSITION + (length * creatureType), c->bytes, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, c.bytes[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".core")
void Flash_GetCreatureStatsRange(MemoryInterface memory, StatsRange* stats, Creature creature_type)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureStats[creature_type];
#else
    const uint8_t length = 10;
    memory.GetRom(TILESET_THEME_POSITION + (creature_type * length), stats->bytes, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, stats->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".core")
//TODO
void Flash_GetType(MemoryInterface memory, MonsterType* monsterType, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureTypes[index];
#else

    memory.GetRom(GAME_DATA_CREATURE_TYPES_POSITION + (index * sizeof(MonsterType)), monsterType->bytes, sizeof(MonsterType));
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < 1; i++)
        memory.Print(str_spawn_creature_type, monsterType->typeA);
    memory.Print(new_line);
#endif
#endif
}


//TODO
SET_MEMORY(".core")
void Flash_GetTypeEffects(MemoryInterface memory, uint8_t* type, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.typeEffects[index];
#else
    memory.GetRom(GAME_DATA_TYPE_EFFECTS_POSITION + index, type, 1);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < 1; i++)
        memory.Print(str_spawn_creature_type, type[0]);
    memory.Print(new_line);
#endif
#endif
}

//TODO
SET_MEMORY(".core")
void Flash_GetSkillData(MemoryInterface memory, SkillData* skillData, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.abilityData[index];
#else
    memory.GetRom(GAME_DATA_ABILITY_POSITION + (index * sizeof(SkillData)), skillData->bytes, sizeof(SkillData));
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(SkillData); i++)
        memory.Print(str_spawn_creature_type, skillData->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

//TODO
SET_MEMORY(".core")
void Flash_GetSpellData(MemoryInterface memory, SpellData* spellData, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.spellData[index];
#else
    memory.GetRom(GAME_DATA_SPELL_POSITION + (index * sizeof(SpellData)), spellData->bytes, sizeof(SpellData));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(SpellData); i++)
        memory.Print(str_spawn_creature_type, spellData->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

//TODO
SET_MEMORY(".core")
void Flash_GetItemData(MemoryInterface memory, ItemData* itemData, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.itemData[index];
#else
    memory.GetRom(GAME_DATA_ITEM_POSITION + (index * sizeof(ItemData)), itemData->bytes, sizeof(ItemData));
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(ItemData); i++)
        memory.Print(str_spawn_creature_type, itemData->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetObjectData(MemoryInterface memory, ObjectData* object_data, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.objectData[index];
#else
    memory.GetRom(GAME_DATA_OBJECT_POSITION + index, object_data->bytes, sizeof(ObjectData));
    memory.GetRom(GAME_DATA_OBJECT_POSITION + (index * sizeof(ObjectData)), object_data->bytes, sizeof(ObjectData));
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Tile); i++)
        memory.Print(str_spawn_creature_type);
    memory.Print(new_line);
    return object_data;
#endif
#endif
}



/**********************************************************************************************************************/
/*      SPRITES
**********************************************************************************************************************/
SET_MEMORY(".core")
void Flash_GetSpriteLayout(MemoryInterface memory, SpriteLayout* spriteLayout, uint8_t index, ObjectsTypes type, bool front)
{
#ifdef STANDALONE
    if (type == ITEM)
        return &g_gameFlash.spriteData.itemLayout[index];
    else if (type == OBJECT)
        return &g_gameFlash.spriteData.objectLayout[index];
    else if (type == SPELL)
        return &g_gameFlash.spriteData.spellLayout[index];
    else if (type == SKILL)
        return &g_gameFlash.spriteData.skillLayout[index];
#else
    const uint32_t position = index * sizeof(SpriteLayout);

    if (type == ITEM)
        memory.GetRom(SPRITE_ITEMS_LAYOUT_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_OBJECTS_LAYOUT_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == SPELL)
        memory.GetRom(SPRITE_SPELLS_LAYOUT_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == SKILL)
        memory.GetRom(SPRITE_SKILLS_LAYOUT_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == CREATURE)
    {
        if (front)
            memory.GetRom(SPRITE_BATTLER_LAYOUT_FRONT_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
        else
            memory.GetRom(SPRITE_BATTLER_LAYOUT_BACK_16_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    }

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(SpriteLayout); i++)
        memory.Print(str_spawn_creature_type, spriteLayout->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

#if defined(MEMORY_PRINT)
SET_MEMORY(".core.data")
static const char aascyyy[] = "Flash_GetSprite INVALID type! index: %d\n";
#endif


SET_MEMORY(".core")
void Flash_GetSprite(MemoryInterface memory, uint8_t* sprite, uint32_t index, uint16_t length, ObjectsTypes type, bool front)
{
#ifdef STANDALONE
    if (type == ITEM)
        return g_gameFlash.spriteData.itemSprites;
    else if (type == OBJECT)
        return g_gameFlash.spriteData.objectSprites;
    else if (type == SPELL)
        return g_gameFlash.spriteData.spells;
    else if (type == SKILL)
        return g_gameFlash.spriteData.skills;
#else
    if (type == ITEM)
        memory.GetRom(SPRITE_ITEMS_16_POSITION + index, sprite, length);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_OBJECTS_16_POSITION + index, sprite, length);
    else if (type == SPELL)
        memory.GetRom(SPRITE_SPELLS_16_POSITION + index, sprite, length);
    else if (type == SKILL)
        memory.GetRom(SPRITE_SKILLS_16_POSITION + index, sprite, length);
    else if (type == CREATURE)
    {
        if (front)
            memory.GetRom(SPRITE_BATTLER_FRONT_16_POSITION + index, sprite, length);
        else
            memory.GetRom(SPRITE_BATTLER_BACK_16_POSITION + index, sprite, length);
    }
#if defined(MEMORY_PRINT)
    else
    memory.Print(aascyyy, type);

    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, sprite[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetSpriteLayout_64(MemoryInterface memory, SpriteLayout* spriteLayout, uint8_t index, ObjectsTypes type, bool front)
{
#ifdef STANDALONE
    if (type == ITEM)
        return &g_gameFlash.spriteData.itemLayout[index];
    else if (type == OBJECT)
        return &g_gameFlash.spriteData.objectLayout[index];
    else if (type == SPELL)
        return &g_gameFlash.spriteData.spellLayout[index];
    else if (type == SKILL)
        return &g_gameFlash.spriteData.skillLayout[index];
#else
    const uint32_t position = index * sizeof(SpriteLayout);

    if (type == ITEM)
        memory.GetRom(SPRITE_ITEMS_LAYOUT_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_OBJECTS_LAYOUT_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == SPELL)
        memory.GetRom(SPRITE_SPELLS_LAYOUT_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == SKILL)
        memory.GetRom(SPRITE_SKILLS_LAYOUT_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    else if (type == CREATURE)
    {
        if (front)
            memory.GetRom(SPRITE_BATTLER_LAYOUT_FRONT_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
        else
            memory.GetRom(SPRITE_BATTLER_LAYOUT_BACK_64_POSITION + position, spriteLayout->bytes, sizeof(SpriteLayout));
    }

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(SpriteLayout); i++)
        memory.Print(str_spawn_creature_type, spriteLayout->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

#if defined(MEMORY_PRINT)
SET_MEMORY(".core.data")
static const char aascyyy[] = "Flash_GetSprite INVALID type! index: %d\n";
#endif


SET_MEMORY(".core")
void Flash_GetSprite_64(MemoryInterface memory, uint8_t* sprite, uint32_t index, uint16_t length, ObjectsTypes type, bool front)
{
#ifdef STANDALONE
    if (type == ITEM)
        return g_gameFlash.spriteData.itemSprites;
    else if (type == OBJECT)
        return g_gameFlash.spriteData.objectSprites;
    else if (type == SPELL)
        return g_gameFlash.spriteData.spells;
    else if (type == SKILL)
        return g_gameFlash.spriteData.skills;
#else
    if (type == ITEM)
        memory.GetRom(SPRITE_ITEMS_64_POSITION + index, sprite, length);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_OBJECTS_64_POSITION + index, sprite, length);
    else if (type == SPELL)
        memory.GetRom(SPRITE_SPELLS_64_POSITION + index, sprite, length);
    else if (type == SKILL)
        memory.GetRom(SPRITE_SKILLS_64_POSITION + index, sprite, length);
    else if (type == CREATURE)
    {
        if (front)
            memory.GetRom(SPRITE_BATTLER_FRONT_64_POSITION + index, sprite, length);
        else
            memory.GetRom(SPRITE_BATTLER_BACK_64_POSITION + index, sprite, length);
    }
#if defined(MEMORY_PRINT)
    else
    memory.Print(aascyyy, type);

    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, sprite[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".core")
void Flash_GetSpriteCreature16x16(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 16; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font16x16[(index * 16) + i];
    }
#else
    const uint16_t length = 0;
    memory.GetRom(SPRITE_16X16_CREATURE_POSITION + (length * index), glyph, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, glyph[i]);
    memory.Print(new_line);
#endif
#endif
}


/**********************************************************************************************************************/
/*      TEXT
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 8; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font8x8[(index * 8) + i];
    }
#else
    const uint8_t length = FONT_8_BYTES_PER_CHAR;
    memory.GetRom(FONT_8X8_POSITION + (length * index), glyph, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, glyph[i]);
    memory.Print(new_line);
#endif
#endif
    return length;
}

SET_MEMORY(".core")
uint8_t Flash_GetFontChar16x16(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 16; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font16x16[(index * 16) + i];
    }
#else
    const uint16_t length = FONT_16_BYTES_PER_CHAR;
    memory.GetRom(FONT_16X16_POSITION + (length * index), glyph, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, glyph[i]);
    memory.Print(new_line);
#endif
#endif
    return length;
}


SET_MEMORY(".core")
uint8_t Flash_GetFontChar20x20(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 16; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font16x16[(index * 16) + i];
    }
#else
    const uint16_t length = FONT_20_BYTES_PER_CHAR;
    memory.GetRom(FONT_20X20_POSITION + (length * index), glyph, length);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, glyph[i]);
    memory.Print(new_line);
#endif
#endif
    return length;
}


/**********************************************************************************************************************/
/*      Color
**********************************************************************************************************************/
SET_MEMORY(".core")
Color Flash_GetColor(MemoryInterface memory, uint8_t color)
{
#ifdef STANDALONE
    // return Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
#else
    uint8_t color_value[2];
    memory.GetRom(COLORS_16_POSITION + (2 * color), color_value, 2);
    Color color_return = {.color = ((uint16_t)color_value[0] << 8) | color_value[1]};
    // Color color_return = {.color = ((uint16_t)color_value[1] << 8) | color_value[0]}; //a byte swap
    return color_return;
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < 2; i++)
        memory.Print(str_spawn_creature_type, color_value[i]);
    memory.Print(new_line);
#endif
#endif
}


/**********************************************************************************************************************/
/*      Text
**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Returns a pointer to the char array for the given index of the battle menu
 *  Used for printing the menu options to the screen
**********************************************************************************************************************/
// Game Data
SET_MEMORY(".core")
void Flash_GetSpellbookText(MemoryInterface memory, char* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        textBuffer[i] = g_gameFlash.text.names.spells[index][i];
#else
    Flash_GetSpellName(memory, textBuffer, index);
#endif
}


SET_MEMORY(".core")
void Flash_GetCreatureName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.monsters[index];
#else
    memory.GetRom(STRINGS_NAMES_CREATURES_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".core")
void Flash_GetItemName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.items[index];
#else
    memory.GetRom(STRINGS_NAMES_ITEMS_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetSpellName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.spells[index];
#else
    memory.GetRom(STRINGS_NAMES_SPELLS_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetSkillName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.attacks[index];
#else
    memory.GetRom(STRINGS_NAMES_SKILLS_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetTrainerName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.attacks[index];
#else
    memory.GetRom(STRINGS_NAMES_TRAINERS_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".core")
void Flash_GetObjectName(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.objects[index];
#else
    memory.GetRom(STRINGS_NAMES_OBJECTS_POSITION + (SMALL_STRINGS * index), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}





SET_MEMORY(".core")
void Flash_GetMenuText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        textBuffer[i] = g_gameFlash.text.menus.main[index][i];
    }
#else
    memory.GetRom(STRINGS_MENU_MAIN_POSITION + (SMALL_STRINGS * index), textBuffer, SMALL_STRINGS);


#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, textBuffer[i]);
    memory.Print(new_line);
#endif
#endif
}

/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureStats[type].growth;
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(GAME_DATA_CREATURE_STATS_POSITION + type, struct_bytes, length);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}



SET_MEMORY(".core")
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature index)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.monsterGroups[biome][index];
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(CHAR_SPRITES_BIOMES_POSITION + index, struct_bytes, length);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}


SET_MEMORY(".core")
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature index)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.themeGroups[theme][creature_type];
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(TILESET_THEME_POSITION + index, struct_bytes, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}

