#pragma once
#include <stdint.h>

#include "types.h"


#define TFT_W 320
#define TFT_H 240


void Pico_ili9341_Init(void);
void Pico_ili9341_FillScreen(Color rgb565);
void Pico_ili9341_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565);
void Pico_ili9341_Blit(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data);
void Pico_ili9341_BlitKeyed(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);

void Pico_DrawSprite(const FrameBuffer f, const uint8_t* sprite);
void Pico_DrawToBuffer(FrameBuffer frameBuffer, const uint16_t* pixels, Rect_16 rect);

void Pico_TestFrameBuffer();

void Pico_TestAnimation(FrameBuffer f, Rect_16 r, uint16_t color1);
