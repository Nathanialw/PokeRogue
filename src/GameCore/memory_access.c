//
// Created by nathanial on 5/15/26.
//

#include "memory_access.h"

#include "lib_decl.h"

#include "enums.h"
#include "memory_ram.h"
#include "memory_rom.h"
#include "types.h"

/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".map")
SkillLearnLevel Flash_GetSkill(MemoryInterface memory, Type creatureType, uint8_t index)
{
    // return g_gameFlash.gameData.levelUpSkills[creatureType][index];
    SkillLearnLevel tmp = {0};
    return tmp;
}

SET_MEMORY(".map")
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type)
{
    // return g_gameFlash.gameData.creatureStats[type].growth;
    return 0;
}

SET_MEMORY(".map")
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature creature_type)
{
    // return g_gameFlash.tileset.monsterGroups[biome][creature_type];
    return 0;
}

SET_MEMORY(".map")
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature creature_type)
{
    // return g_gameFlash.tileset.themeGroups[theme][creature_type];
    return 0;
}

SET_MEMORY(".map")
StatsRange Flash_GetCreatureStatsRange(MemoryInterface memory, Creature creature_type)
{
    // return g_gameFlash.gameData.creatureStats[creature_type];
    StatsRange stats = {0};
    return stats;
}


MonsterType Flash_GetType(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.creatureTypes[index];
    MonsterType t = {0};
    return t;
}

int8_t Flash_GetTypeEffects(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.typeEffects[index];
    uint8_t t = 0;
    return 0;
}

SkillData Flash_GetSkillData(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.abilityData[index];
    SkillData skillData = {0};
    return skillData;
}

SpellData Flash_GetSpellData(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.spellData[index];
    SpellData d = {0};
    return d;
}

ItemData Flash_GetItemData(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.itemData[index];
    ItemData i = {0};
    return i;
}

ObjectData Flash_GetObjectData(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.gameData.objectData[index];
    ObjectData i = {0};
    return i;
}

/**********************************************************************************************************************/
/**     MAP
**********************************************************************************************************************/
Tile Flash_GetBiomeTile(MemoryInterface memory, uint8_t biomeType, uint8_t partial_tile_id0)
{
    // return g_gameFlash.sprites.biomes[g_run.biome][partial_tile_id0];
    // return g_gameFlash.sprites.biomes[biomeType][partial_tile_id0];
    Tile t = {0};
    return t;
}


/**********************************************************************************************************************/
/*      SPRITES
**********************************************************************************************************************/
Sprite Flash_GetSpriteMetadata(MemoryInterface memory, ObjectsTypes type, uint8_t index)
{
    if (type == ITEM)
    {
        // return g_gameFlash.sprites.items[type][index];
    }
    else if (type == CREATURE)
    {
        // return g_gameFlash.sprites.monsters[type][index];
    }
    else if (type == OBJECT)
    {
        // return g_gameFlash.sprites.objects[type][index];
    }

    Sprite s = {0};
    return s;
}

const SpriteLayout* Flash_GetSpriteLayout(MemoryInterface memory, uint8_t index, ObjectsTypes type)
{
    // if (type == ITEM)
    //     return &g_gameFlash.spriteData.itemLayout[index];
    // else if (type == OBJECT)
    //     return &g_gameFlash.spriteData.objectLayout[index];
    // else if (type == SPELL)
    //     return &g_gameFlash.spriteData.spellLayout[index];
    // else if (type == SKILL)
    //     return &g_gameFlash.spriteData.skillLayout[index];
    return NULL;
}

const uint8_t* Flash_GetSprite(MemoryInterface memory, ObjectsTypes type)
{
    // if (type == ITEM)
    // return g_gameFlash.spriteData.itemSprites;
    // else if (type == OBJECT)
    // return g_gameFlash.spriteData.objectSprites;
    // else if (type == SPELL)
    // return g_gameFlash.spriteData.spells;
    // else if (type == SKILL)
    // return g_gameFlash.spriteData.skills;
    return NULL;
}

SpriteLayout Flash_GetBattlerLayout(MemoryInterface memory, uint8_t creatureType, bool front)
{
    // if (front)
    // return g_gameFlash.spriteData.battlers.frontLayout[creatureType];
    // else
    // return g_gameFlash.spriteData.battlers.backLayout[creatureType];
    SpriteLayout l = {0};
    return l;
}

const uint8_t* Flash_GetBattlerArray(MemoryInterface memory, bool front)
{
    // if (front)
    // return g_gameFlash.spriteData.battlers.front;
    // else
    // return g_gameFlash.spriteData.battlers.back;
    return NULL;
}


/**********************************************************************************************************************/
/*      ANIMATIONS
**********************************************************************************************************************/
void Flash_BattlerAttackAnimation(EntityId id, ObjectsTypes type, bool player)
{
    // if (type == ITEM)
    //     g_gameFlash.animation.itemsAttack[id](player);
    // else if (type == SKILL)
    //     g_gameFlash.animation.skillsAttack[id](player);
    // else if (type == SPELL)
    //     g_gameFlash.animation.spellsAttack[id](player);
}

void Flash_BattlerStruckAnimation(EntityId id, ObjectsTypes type, bool player)
{
    // if (type == ITEM)
    //     g_gameFlash.animation.itemsStruck[id](player);
    // else if (type == SKILL)
    //     g_gameFlash.animation.skillsStruck[id](player);
    // else if (type == SPELL)
    //     g_gameFlash.animation.spellsStruck[id](player);
}


/**********************************************************************************************************************/
/*      TEXT
**********************************************************************************************************************/
SET_MEMORY(".core")
void Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
    for (uint16_t i = 0; i < 8; i++)
    {
        // glyph[i] = g_gameFlash.spriteData.font8x8[(index * 8) + i];
    }
}

void Flash_GetFontChar16x16(MemoryInterface memory, uint16_t* glyph, uint8_t index)
{
    for (uint16_t i = 0; i < 16; i++)
    {
        // glyph[i] = g_gameFlash.spriteData.font16x16[(index * 16) + i];
    }
}


/**********************************************************************************************************************/
/*      Color
**********************************************************************************************************************/
uint16_t Flash_GetColor(MemoryInterface memory, uint8_t color)
{
    // return Flash_GetColor(memory, PAL_OFF_WHITE_GRAY];
    return 0;
}


/**********************************************************************************************************************/
/*      Text
**********************************************************************************************************************/

/**********************************************************************************************************************/
/*  for fixed length string strings in an array
 *  use length * index to get the offset
**********************************************************************************************************************/
// UI
const char* Flash_GetOptionText(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.menus.options[index];
    return NULL;
}

void Flash_GetMenuText(char* textBuffer, uint8_t index)
{
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        // textBuffer[i] = g_gameFlash.text.menus.main[index][i];
    }
}

/**********************************************************************************************************************/
/** Returns a pointer to the char array for the given index of the battle menu
 *  Used for printing the menu options to the screen
**********************************************************************************************************************/
const char* Flash_GetBattleMenuList(MemoryInterface memory, uint8_t idx)
{
    // return g_gameFlash.text.menus.battleMenu[idx];
    return NULL;
}


// Game Data

void Flash_GetSpellbookText(char* textBuffer, uint8_t index)
{
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        // textBuffer[i] = g_gameFlash.text.names.spells[index][i];
    }
}

void Flash_GetEntityText(char* textBuffer, uint8_t index)
{
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        // textBuffer[i] = g_gameFlash.text.names.spells[index][i];
    }
}

const char* Flash_GetCreatureDescription(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.monsters[index];
    return NULL;
}


const char* Flash_GetCreatureName(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.monsters[index];
    return NULL;
}


const char* Flash_GetObjectDescription(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.objects[index];
    return NULL;
}

const char* Flash_GetObjectName(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.objects[index];
    return NULL;
}


const char* Flash_GetItemDescription(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.items[index];
    return NULL;
}

const char* Flash_GetItemName(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.items[index];
    return NULL;
}


const char* Flash_GetSpellDescription(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.spells[index];
    return NULL;
}

const char* Flash_GetSpellName(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.spells[index];
    return NULL;
}

const char* Flash_GetSkillDescription(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.attacks[index];
    return NULL;
}

const char* Flash_GetSkillName(MemoryInterface memory, uint8_t index)
{
    // return g_gameFlash.text.descriptions.attacks[index];
    return NULL;
}


const char* Flash_GetTypeName(MemoryInterface memory, uint8_t typeIndex)
{
    // return g_gameFlash.text.types[typeIndex];
    return NULL;
}


//Arrays

const SmallStringArray* Flash_GetCreatureNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
    // text = g_gameFlash.text.names.monsters;
    return text;
}

const SmallStringArray* Flash_GetObjectNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
    // text = g_gameFlash.text.names.objects;
    return text;
}

const SmallStringArray* Flash_GetItemNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
    // text = g_gameFlash.text.names.items;
    return text;
}


/**********************************************************************************************************************/
/**     Animation
**********************************************************************************************************************/


/**********************************************************************************************************************/
/**     FUNCTIONS
**********************************************************************************************************************/
bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SkillData skillData)
{
    // return g_gameFlash.funcs.abilityFunctions[index](id, target_id, skillData);
    return false;
}

bool Flash_GetSpellEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SpellData spellData)
{
    // return g_gameFlash.funcs.abilityFunctions[index](id, target_id, skillData);
    return false;
}


bool Flash_GetItemEffect(MemoryInterface memory, uint8_t index, EntityId id, ItemData itemData)
{
    // return g_gameFlash.funcs.abilityFunctions[index](id, target_id, skillData);
    return false;
}


bool Flash_GetObjectEffect(MemoryInterface memory, uint8_t index, EntityId id, ObjectData objectData)
{
    // return g_gameFlash.funcs.abilityFunctions[index](id, target_id, skillData);
    return false;
}
