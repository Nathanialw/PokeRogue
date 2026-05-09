//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"
#include "types.h"
#include "lib_types.h"

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
void ClipTile(uint16_t* clip, const uint16_t* pixels, Rect_16 r);

void DrawTile(GraphicsInterface graphics, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);
void DrawMonster(GraphicsInterface graphics, uint8_t screen_tx, uint8_t screen_ty, Creature tile_id, const Sprite* spriteArray);
void DrawMonsterCached(GraphicsInterface graphics, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id, const Sprite* spriteArray);
void DrawTileCached(GraphicsInterface graphics, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);

FrameBuffer DrawBattlerToBuffer(GraphicsInterface graphics, uint16_t screen_x, uint16_t screen_y, const SpriteLayout layout, const uint8_t* sprite);
void DrawBattler(GraphicsInterface graphics, uint16_t screen_x, uint16_t screen_y, const SpriteLayout layout, const uint8_t* sprite);
void HandleMenu(GraphicsInterface graphics);
void HandleGameMenu(GraphicsInterface graphics);
void DrawCursor(GraphicsInterface graphics);
void HandleBattle(GraphicsInterface graphics);
void HandleBattleMenu(GraphicsInterface graphics);

