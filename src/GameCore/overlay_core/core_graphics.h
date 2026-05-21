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
uint8_t PrintLineStr(GraphicsInterface graphics, MemoryInterface memory, uint16_t x, uint16_t y, FontSize fontSize, uint8_t maxChars, const char* textLine, bool indent);
FrameBuffer DrawBattlerToBuffer(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front);
void DrawBattler(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front);
void DrawCursor(GraphicsInterface graphics, MemoryInterface memory);

