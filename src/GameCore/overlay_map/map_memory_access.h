//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"
#include "types.h"

SkillLearnLevel Flash_GetSkill(MemoryInterface memory, CreatureSkillLearnLevels c, Type creatureType, uint8_t index);
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type);
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature index);
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature index);

void Flash_GetSpriteMetadata(MemoryInterface memory, Sprite* sprite, ObjectsTypes type, uint8_t index);


void Flash_GetOptionText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index);




//MAP
void Flash_GetBiomeTile(MemoryInterface memory, Tile* tile, uint8_t biomeType, uint8_t tile_id);


void Flash_GetCreatureDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetObjectDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetItemDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSpellDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSkillDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetTypeName(MemoryInterface memory, char* text, uint8_t typeIndex);


ObjectData Flash_GetObjectData(MemoryInterface memory, uint8_t index);


bool Flash_GetObjectEffect(MemoryInterface memory, HardwareInterface hardware, uint8_t index, EntityId object_id, EntityId target_id, ObjectData objectData);
