//
// Created by nathanial on 5/15/26.
//

#include "memory_access.h"

#include "lib_decl.h"

#include "memory_ram.h"
#include "memory_constants.h"

#include "enums.h"
#include "memory_rom.h"
#include "types.h"

/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".map")
SkillLearnLevel Flash_GetSkill(MemoryInterface memory, Type creatureType, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.levelUpSkills[creatureType][index];
#else
    SkillLearnLevel tmp = {0};
    return tmp;
#endif
}

SET_MEMORY(".map")
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureStats[type].growth;
#else
    return 0;
#endif
}

SET_MEMORY(".map")
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature creature_type)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.monsterGroups[biome][creature_type];
#else
    return 0;
#endif
}

SET_MEMORY(".map")
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature creature_type)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.themeGroups[theme][creature_type];
#else
    return 0;
#endif
}

SET_MEMORY(".map")
StatsRange Flash_GetCreatureStatsRange(MemoryInterface memory, Creature creature_type)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureStats[creature_type];
#else
    StatsRange stats = {0};
    return stats;
#endif
}


MonsterType Flash_GetType(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureTypes[index];
#else
    MonsterType t = {0};
    return t;
#endif
}

int8_t Flash_GetTypeEffects(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.typeEffects[index];
#else
    uint8_t t = 0;
    return 0;
#endif
}

SkillData Flash_GetSkillData(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.abilityData[index];
#else
    SkillData skillData = {0};
    return skillData;
#endif
}

SpellData Flash_GetSpellData(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.spellData[index];
#else
    SpellData d = {0};
    return d;
#endif
}

ItemData Flash_GetItemData(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.itemData[index];
#else
    ItemData i = {0};
    return i;
#endif
}

ObjectData Flash_GetObjectData(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.objectData[index];
#else
    ObjectData i = {0};
    return i;
#endif
}

/**********************************************************************************************************************/
/**     MAP
**********************************************************************************************************************/
Tile Flash_GetBiomeTile(MemoryInterface memory, uint8_t biomeType, uint8_t partial_tile_id0)
{
#ifdef STANDALONE
    return g_gameFlash.sprites.biomes[biomeType][partial_tile_id0];
#else
    Tile t = {0};
    return t;
#endif
}


/**********************************************************************************************************************/
/*      SPRITES
**********************************************************************************************************************/
Sprite Flash_GetSpriteMetadata(MemoryInterface memory, ObjectsTypes type, uint8_t index)
{
#ifdef STANDALONE
    if (type == ITEM)
    {
        return g_gameFlash.sprites.items[type];
    }
    else if (type == CREATURE)
    {
        return g_gameFlash.sprites.monsters[type];
    }
    else if (type == OBJECT)
    {
        return g_gameFlash.sprites.objects[type];
    }
#else
    Sprite s = {0};
    return s;
#endif
}

const SpriteLayout* Flash_GetSpriteLayout(MemoryInterface memory, uint8_t index, ObjectsTypes type)
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
    return NULL;
#endif
}

const uint8_t* Flash_GetSprite(MemoryInterface memory, ObjectsTypes type)
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
    return NULL;
#endif
}

SpriteLayout Flash_GetBattlerLayout(MemoryInterface memory, uint8_t creatureType, bool front)
{
#ifdef STANDALONE
    if (front)
        return g_gameFlash.spriteData.battlers.frontLayout[creatureType];
    else
        return g_gameFlash.spriteData.battlers.backLayout[creatureType];
#else
    SpriteLayout l = {0};
    return l;
#endif
}

const uint8_t* Flash_GetBattlerArray(MemoryInterface memory, bool front)
{
#ifdef STANDALONE
    if (front)
        return g_gameFlash.spriteData.battlers.front;
    else
        return g_gameFlash.spriteData.battlers.back;
#else
    return NULL;
#endif
}


/**********************************************************************************************************************/
/*      ANIMATIONS
**********************************************************************************************************************/
SET_MEMORY(".battle")
void Flash_BattlerAttackAnimation(EntityId id, ObjectsTypes type, bool player)
{
#ifdef STANDALONE
    if (type == ITEM)
        g_gameFlash.animation.itemsAttack[id](player);
    else if (type == SKILL)
        g_gameFlash.animation.skillsAttack[id](player);
    else if (type == SPELL)
        g_gameFlash.animation.spellsAttack[id](player);
#else
    if (type == ITEM)
        itemsAttack[id](player);
    else if (type == SKILL)
        skillsAttack[id](player);
    else if (type == SPELL)
        spellsAttack[id](player);
#endif
}

SET_MEMORY(".battle")
void Flash_BattlerStruckAnimation(EntityId id, ObjectsTypes type, bool player)
{
#ifdef STANDALONE
    if (type == ITEM)
        g_gameFlash.animation.itemsStruck[id](player);
    else if (type == SKILL)
        g_gameFlash.animation.skillsStruck[id](player);
    else if (type == SPELL)
        g_gameFlash.animation.spellsStruck[id](player);
#else
    if (type == ITEM)
        itemsStruck[id](player);
    else if (type == SKILL)
        skillsStruck[id](player);
    else if (type == SPELL)
        spellsStruck[id](player);
#endif
}


/**********************************************************************************************************************/
/*      TEXT
**********************************************************************************************************************/
void Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 8; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font8x8[(index * 8) + i];
    }
#else

#endif
}

void Flash_GetFontChar16x16(MemoryInterface memory, uint16_t* glyph, uint8_t index)
{
#ifdef STANDALONE
    for (uint16_t i = 0; i < 16; i++)
    {
        glyph[i] = g_gameFlash.spriteData.font16x16[(index * 16) + i];
    }
#else

#endif
}


/**********************************************************************************************************************/
/*      Color
**********************************************************************************************************************/
uint16_t Flash_GetColor(MemoryInterface memory, uint8_t color)
{
#ifdef STANDALONE
    // return Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
#else
    return 0;
#endif
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
#ifdef STANDALONE
    return g_gameFlash.text.menus.options[index];
#else
    return NULL;
#endif
}

void Flash_GetMenuText(char* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        textBuffer[i] = g_gameFlash.text.menus.main[index][i];
    }
#else

#endif
}

/**********************************************************************************************************************/
/** Returns a pointer to the char array for the given index of the battle menu
 *  Used for printing the menu options to the screen
**********************************************************************************************************************/
const char* Flash_GetBattleMenuList(MemoryInterface memory, uint8_t idx)
{
#ifdef STANDALONE
    return g_gameFlash.text.menus.battleMenu[idx];
#else
    return NULL;
#endif
}


// Game Data

void Flash_GetSpellbookText(char* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        textBuffer[i] = g_gameFlash.text.names.spells[index][i];
    }
#else

#endif
}

void Flash_GetEntityText(char* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        textBuffer[i] = g_gameFlash.text.names.spells[index][i];
    }
#else

#endif
}

const char* Flash_GetCreatureDescription(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.monsters[index];
#else
    return NULL;
#endif
}


const char* Flash_GetCreatureName(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.monsters[index];
#else
    return NULL;
#endif
}


const char* Flash_GetObjectDescription(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.objects[index];
#else
    return NULL;
#endif
}

const char* Flash_GetObjectName(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.objects[index];
#else
    return NULL;
#endif
}


const char* Flash_GetItemDescription(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.items[index];
#else
    return NULL;
#endif
}

const char* Flash_GetItemName(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.items[index];
#else
    return NULL;
#endif
}


const char* Flash_GetSpellDescription(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.spells[index];
#else
    return NULL;
#endif
}

const char* Flash_GetSpellName(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.spells[index];
#else
    return NULL;
#endif
}

const char* Flash_GetSkillDescription(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.attacks[index];
#else
    return NULL;
#endif
}

const char* Flash_GetSkillName(MemoryInterface memory, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.attacks[index];
#else
    return NULL;
#endif
}


const char* Flash_GetTypeName(MemoryInterface memory, uint8_t typeIndex)
{
#ifdef STANDALONE
    return g_gameFlash.text.types[typeIndex];
#else
    return NULL;
#endif
}


//Arrays
const SmallStringArray* Flash_GetCreatureNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
#ifdef STANDALONE
    text = g_gameFlash.text.names.monsters;
#else
    return text;
#endif
}

const SmallStringArray* Flash_GetObjectNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
#ifdef STANDALONE
    text = g_gameFlash.text.names.objects;
#else
    return text;
#endif
}

const SmallStringArray* Flash_GetItemNameArray(MemoryInterface memory)
{
    const SmallStringArray* text = NULL;
#ifdef STANDALONE
    text = g_gameFlash.text.names.items;
#else
    return text;
#endif
}


/**********************************************************************************************************************/
/**     FUNCTIONS
**********************************************************************************************************************/
SET_MEMORY(".core")
bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t skillType, EntityId id, EntityId target_id, SkillData skillData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.abilityFunctions[skillType](id, target_id, skillData);
#else
    return abilityFunctions[skillType](id, target_id, skillData);
#endif
}

SET_MEMORY(".core")
bool Flash_GetSpellEffect(MemoryInterface memory, uint8_t spellType, EntityId id, EntityId target_id, SpellData spellData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.spellFunctions[spellType](id, target_id, spellData);
#else
    return spellFunctions[spellType](id, target_id, spellData);
#endif
}

SET_MEMORY(".core")
bool Flash_GetItemEffect(MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId id, ItemData itemData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.itemFunctions[itemType](item_id, id, itemData);
#else
    return itemFunctions[itemType](item_id, id, itemData);
#endif
}

SET_MEMORY(".map")
bool Flash_GetObjectEffect(MemoryInterface memory, uint8_t objectType, EntityId object_id, EntityId target_id, ObjectData objectData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.objectFunctions[objectType](object_id, target_id, objectData);
#else
    return objectFunctions[objectType](object_id, target_id, objectData);
#endif
}
