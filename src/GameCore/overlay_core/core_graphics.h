//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "lib_decl.h"
#include "lib_types.h"

#include "enums.h"
#include "types.h"


/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
uint8_t PrintLineStr(GraphicsInterface graphics, MemoryInterface memory, uint16_t x, uint16_t y, FontSize fontSize, uint8_t maxChars, const char* textLine, bool indent, uint8_t fg, uint8_t bg);
FrameBuffer DrawBattlerToBuffer(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front);
void DrawBattler(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front);
void DrawCursor(GraphicsInterface graphics, MemoryInterface memory);

//Icons
void DrawIconCached(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_tx, uint16_t screen_ty, uint8_t sprite_id, IconType type);
void DrawBuffs(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const uint8_t* buff_values, IconType icon_type, uint8_t num_per_row);


uint8_t DrawSkillBuffs(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, uint16_t buff_values, IconType icon_type, uint8_t num_per_row);

void DrawRightWing(GraphicsInterface graphics, MemoryInterface memory);
void DrawLeftWing(GraphicsInterface graphics, MemoryInterface memory);
void DrawText(GraphicsInterface graphics, MemoryInterface memory);
void DrawScreen(GraphicsInterface graphics, MemoryInterface memory);