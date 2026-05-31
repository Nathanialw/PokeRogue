//
// Created by nathanial on 5/2/26.
//
#pragma once

#define MAX_VOICES 4

// #define RES_320x240
// #define RES_320x320
// #define RES_480x480


#define TILE_W 16
#define TILE_H 16

#if defined(RES_320x240)
#define TFT_W 320
#define TFT_H 240
#define SCREEN_W 320
#define SCREEN_H 240
#define TEXT_W 8
#define TEXT_H 8
#define TFT_WIDTH  320
#define TFT_HEIGHT 240
#elif defined(CARTRIDGE)
#define TFT_W 320
#define TFT_H 320
#define SCREEN_W 320
#define SCREEN_H 320
#define TEXT_W 8
#define TEXT_H 8
#define TFT_WIDTH  320
#define TFT_HEIGHT 320
#elif defined(RES_480x480)
#define TFT_W 480
#define TFT_H 480
#define SCREEN_W 480
#define SCREEN_H 480
#define TEXT_W 8
#define TEXT_H 8
#define TFT_WIDTH  480
#define TFT_HEIGHT 480
#elif defined(SDL)
#define TFT_W 320
#define TFT_H 320
#define SCREEN_W 320
#define SCREEN_H 320
#define TEXT_W 8
#define TEXT_H 8
#define TFT_WIDTH  320
#define TFT_HEIGHT 320
#else
#error "Define RES_320x240 or RES_320x320 or RES_480x480 or SDL"
#endif

#define TRANSPARENCY 0xF81F

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
#if defined(RES_320x240)
#define BUFFER_H (TILE_H)
#define BUFFER_W (320)
#elif defined(CARTRIDGE)
#define BUFFER_H (20)
#define BUFFER_W (320)
#elif defined(RES_480x480)
#define BUFFER_H (TILE_H)
#define BUFFER_W (480)
#elif defined(SDL)
#define BUFFER_H (320)
#define BUFFER_W (320)
#else
#error "Define RES_320x240 or RES_320x320 or RES_480x480 or SDL"
#endif

#define BUFFER_SIZE_FRONT (BUFFER_W * BUFFER_H)
#define BUFFER_SIZE_BACK (BUFFER_W * BUFFER_H)
#define BUFFER_SIZE_1BYTE ((BUFFER_W * BUFFER_H) * 4)
#define BUFFER_SIZE_2BYTES ((BUFFER_W * BUFFER_H) * 2)
