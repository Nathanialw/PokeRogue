//
// Created by nathanial on 5/15/26.
//
#pragma once
#include <stdint.h>

#include "lib_decl.h"

#include "enums.h"
#include "types.h"

// ENTITIES
SkillLearnLevel Flash_GetSkill(MemoryInterface memory, Type creatureType, uint8_t index);
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type);
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature creature_type);
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature creature_type);
StatsRange Flash_GetCreatureStatsRange(MemoryInterface memory, Creature creature_type);
MonsterType Flash_GetType(MemoryInterface memory, uint8_t index);
int8_t Flash_GetTypeEffects(MemoryInterface memory, uint8_t index);
SkillData Flash_GetSkillData(MemoryInterface memory, uint8_t index);
SpellData Flash_GetSpellData(MemoryInterface memory, uint8_t index);
ItemData Flash_GetItemData(MemoryInterface memory, uint8_t index);
ObjectData Flash_GetObjectData(MemoryInterface memory, uint8_t index);

//MAP
Tile Flash_GetBiomeTile(MemoryInterface memory, uint8_t biomeType, uint8_t partial_tile_id0);

//GRAPHICS
Sprite Flash_GetSpriteMetadata(MemoryInterface memory, ObjectsTypes type, uint8_t index);
const SpriteLayout* Flash_GetSpriteLayout(MemoryInterface memory, uint8_t index, ObjectsTypes type);
const uint8_t* Flash_GetSprite(MemoryInterface memory, ObjectsTypes type);
SpriteLayout Flash_GetBattlerLayout(MemoryInterface memory, uint8_t creatureType, bool front);
const uint8_t* Flash_GetBattlerArray(MemoryInterface memory, bool front);

//ANIMATION
void Flash_BattlerAttackAnimation(EntityId id, ObjectsTypes type, bool player);
void Flash_BattlerStruckAnimation(EntityId id, ObjectsTypes type, bool player);

///FONTS
void Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index);
void Flash_GetFontChar16x16(MemoryInterface memory, uint16_t* glyph, uint8_t index);

///COLORS
uint16_t Flash_GetColor(MemoryInterface memory, uint8_t color);

///TEXT
//ui
const char* Flash_GetOptionText(MemoryInterface memory, uint8_t index);
void Flash_GetMenuText(char* textBuffer, uint8_t index);
const char* Flash_GetBattleMenuList(MemoryInterface memory, uint8_t idx);
//entities
void Flash_GetSpellbookText(char* textBuffer, uint8_t index);
const char* Flash_GetCreatureName(MemoryInterface memory, uint8_t index);
const char* Flash_GetCreatureDescription(MemoryInterface memory, uint8_t index);
const char* Flash_GetObjectName(MemoryInterface memory, uint8_t index);
const char* Flash_GetObjectDescription(MemoryInterface memory, uint8_t index);
const char* Flash_GetItemName(MemoryInterface memory, uint8_t index);
const char* Flash_GetItemDescription(MemoryInterface memory, uint8_t index);
const char* Flash_GetSpellName(MemoryInterface memory, uint8_t index);
const char* Flash_GetSpellDescription(MemoryInterface memory, uint8_t index);
const char* Flash_GetSkillName(MemoryInterface memory, uint8_t index);
const char* Flash_GetSkillDescription(MemoryInterface memory, uint8_t index);
const char* Flash_GetTypeName(MemoryInterface memory, uint8_t typeIndex);
const SmallStringArray* Flash_GetCreatureNameArray(MemoryInterface memory);
const SmallStringArray* Flash_GetItemNameArray(MemoryInterface memory);
const SmallStringArray* Flash_GetObjectNameArray(MemoryInterface memory);

//FUNCTIONS
bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SkillData skillData);
bool Flash_GetSpellEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SpellData spellData);
bool Flash_GetItemEffect(MemoryInterface memory, uint8_t index, EntityId item_id, EntityId id, ItemData itemData);
bool Flash_GetObjectEffect(MemoryInterface memory, uint8_t index, EntityId object_id, EntityId target_id, ObjectData objectData);
