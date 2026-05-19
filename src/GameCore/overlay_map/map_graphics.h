//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "common/enums.h"
#include "lib_decl.h"
#include "common/types.h"
#include "lib_types.h"

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
void ClipTile(uint16_t* clip, const uint16_t* pixels, Rect_16 r);

void DrawTile(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);
void DrawSprite(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, Creature tile_id, ObjectsTypes type);
void DrawSpriteCached(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t sprite_id, ObjectsTypes type);
void DrawTileCached(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);

void HandleMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void HandleGameMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);