//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"
#include "types.h"




void Flash_GetTextSpriteMetadata(MemoryInterface memory, Sprite* sprite, ObjectsTypes type, uint8_t index);

void Flash_GetMapTileMetadata(MemoryInterface memory, SpriteFrames* sprite, uint8_t index);
void Flash_GetMapTile(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite);
void Flash_GetMapSpriteMetadata(MemoryInterface memory, SpriteFrames* sprite, ObjectsTypes type, uint8_t index);
void Flash_GetMapSprite(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite, ObjectsTypes type);

void Flash_GetOptionText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index);


//MAP
void Flash_GetBiomeTile(MemoryInterface memory, Tile* tile, uint8_t biomeType, uint8_t tile_id);


void Flash_GetCreatureDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetObjectDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetItemDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSpellDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetSkillDescription(MemoryInterface memory, char* text, uint8_t index);
void Flash_GetTypeName(MemoryInterface memory, char* text, uint8_t typeIndex);




bool Flash_GetObjectEffect(MemoryInterface memory, HardwareInterface hardware, uint8_t index, EntityId object_id, EntityId target_id, ObjectData objectData);
