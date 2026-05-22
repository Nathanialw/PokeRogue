//
// Created by nathanial on 5/15/26.
//
#pragma once
#include "lib_decl.h"

#include "enums.h"
#include "types.h"

// ENTITIES
SkillLearnLevel Flash_GetSkill(MemoryInterface memory, CreatureSkillLearnLevels c, Type creatureType, uint8_t index);
void Flash_GetCreatureStatsRange(MemoryInterface memory, StatsRange* stats, Creature creature_type);
void Flash_GetType(MemoryInterface memory, MonsterType* monsterType, uint8_t index);
void Flash_GetTypeEffects(MemoryInterface memory, uint8_t* type, uint8_t index);
void Flash_GetSkillData(MemoryInterface memory, SkillData* skillData, uint8_t index);
void Flash_GetSpellData(MemoryInterface memory, SpellData* spellData, uint8_t index);
void Flash_GetItemData(MemoryInterface memory, ItemData* itemData, uint8_t index);


//GRAPHICS
void Flash_GetSpriteLayout(MemoryInterface memory, SpriteLayout* spriteLayout, uint8_t index, ObjectsTypes type, bool front);
void Flash_GetSprite(MemoryInterface memory, uint8_t* sprite, uint32_t index, uint16_t length, ObjectsTypes type, bool front);


///FONTS
uint8_t Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index);
uint8_t Flash_GetFontChar16x16(MemoryInterface memory, uint8_t* glyph, uint8_t index);
uint8_t Flash_GetFontChar20x20(MemoryInterface memory, uint8_t* glyph, uint8_t index);

///COLORS
uint16_t Flash_GetColor(MemoryInterface memory, uint8_t color);

///TEXT

void Flash_GetObjectName(MemoryInterface memory, char* text, uint8_t index);
//ui
void Flash_GetMenuText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index);

//entities

void Flash_GetSpellbookText(MemoryInterface memory, char* textBuffer, uint8_t index);
void Flash_GetCreatureName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetItemName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSpellName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSkillName(MemoryInterface memory, char* text, uint8_t index);

//FUNCTIONS
bool Flash_GetSpellEffect(HardwareInterface hardware, MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SpellData spellData);
bool Flash_GetItemEffect(MemoryInterface memory, uint8_t index, EntityId item_id, EntityId id, ItemData itemData);
