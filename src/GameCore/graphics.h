//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "enums.h"
#include "types.h"

/**********************************************************************************************************************/
/**  IMPLEMENTATION DEFINED
**********************************************************************************************************************/

void ClearBuffer();
void DrawBuffer(const FrameBuffer f);
void SetFrameBuffer(Color rgb565);
void SetBuffer(uint16_t length, uint16_t* p, Color rgb565);
void DrawSprite(FrameBuffer f, const uint8_t* sprite);
void DrawToBuffer(const FrameBuffer frameBuffer, const uint16_t* pixels, const Rect_16 rect);
void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565);
void FillScreen(Color rgb565);
void TestAnimation(FrameBuffer f, Rect_16 r, uint16_t color1);
void DrawTileKeyed(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void Draw(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data);

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
void ClipTile(uint16_t* clip, const uint16_t* pixels, Rect_16 r);

void DrawMonster(uint8_t screen_tx, uint8_t screen_ty, Creature tile_id);
void DrawTile(uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);
void DrawMonsterCached(uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);
void DrawTileCached(uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id);

FrameBuffer DrawBattlerToBuffer(uint16_t screen_x, uint16_t screen_y, const SpriteLayout layout, const uint8_t* sprite);
void DrawBattler(uint16_t screen_x, uint16_t screen_y, const SpriteLayout layout, const uint8_t* sprite);
void HandleMenu();
void HandleGameMenu();
void DrawCursor();
void HandleBattle();
void HandleBattleMenu();

