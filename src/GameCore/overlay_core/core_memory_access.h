//
// Created by nathanial on 5/15/26.
//
#pragma once
#include "lib_decl.h"

#include "common/enums.h"
#include "common/types.h"

// ENTITIES
void Flash_GetCreatureStatsRange(MemoryInterface memory, StatsRange* stats, Creature creature_type);
MonsterType Flash_GetType(MemoryInterface memory, uint8_t index);
int8_t Flash_GetTypeEffects(MemoryInterface memory, uint8_t index);
SkillData Flash_GetSkillData(MemoryInterface memory, uint8_t index);
SpellData Flash_GetSpellData(MemoryInterface memory, uint8_t index);
ItemData Flash_GetItemData(MemoryInterface memory, uint8_t index);



//GRAPHICS
void Flash_GetSpriteLayout(MemoryInterface memory, SpriteLayout spriteLayout, uint8_t index, ObjectsTypes type, bool front);
void Flash_GetSprite(MemoryInterface memory, uint8_t* sprite, uint16_t length, ObjectsTypes type, bool front);


///FONTS
void Flash_GetFontChar8x8(MemoryInterface memory, uint8_t* glyph, uint8_t index);
void Flash_GetFontChar16x16(MemoryInterface memory, uint8_t* glyph, uint8_t index);

///COLORS
uint16_t Flash_GetColor(MemoryInterface memory, uint8_t color);

///TEXT

//ui

//entities

void Flash_GetSpellbookText(MemoryInterface memory, char* textBuffer, uint8_t index);
void Flash_GetCreatureName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetItemName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSpellName(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSkillName(MemoryInterface memory, char* text, uint8_t index);

//FUNCTIONS
bool Flash_GetSpellEffect(HardwareInterface hardware, MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SpellData spellData);
bool Flash_GetItemEffect(MemoryInterface memory, uint8_t index, EntityId item_id, EntityId id, ItemData itemData);
