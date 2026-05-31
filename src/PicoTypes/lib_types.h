//
// Created by nathanial on 5/2/26.
//
#pragma once
#include "lib_constants.h"
#include "stdbool.h"
#include "stdint.h"


/**********************************************************************************************************************/
/*  The main frame buffer
*   can be accessed as:
*   linear array of  25088 uint8_t
*   linear array of  12544 uint16_t
*   front buff and back buffers each of 6272 uint16_t
**********************************************************************************************************************/
#if defined(SDL)
typedef union
{
    uint16_t frameBuffer[BUFFER_SIZE_2BYTES];
    uint8_t frameBuffer1byte[BUFFER_SIZE_1BYTE];

    struct
    {
        uint16_t front[BUFFER_SIZE_BACK];
        uint16_t back[BUFFER_SIZE_FRONT];
    };
} PartialFrameBuffer;

_Static_assert(409600 == BUFFER_SIZE_1BYTE, "SpriteLayout must be 20480 bytes");

#else
typedef union
{
    uint16_t frameBuffer[BUFFER_SIZE_2BYTES];
    uint8_t frameBuffer1byte[BUFFER_SIZE_1BYTE];

    struct
    {
        uint16_t front[BUFFER_SIZE_BACK];
        uint16_t back[BUFFER_SIZE_FRONT];
    };
} PartialFrameBuffer;

_Static_assert(BUFFER_SIZE_1BYTE >= 25088, "SpriteLayout must be 20480 bytes");

#endif
/**********************************************************************************************************************/
/**  Stores the current game state
 *   Holds enums:
*       GameState
*       InputState
*       BattleState
**********************************************************************************************************************/
typedef struct State
{
    uint8_t gameState : 2;
    uint8_t battleState : 2;
    uint8_t inputState : 3;
    uint8_t running : 1;
    uint8_t overlay;
} State;


typedef union Color
{
    struct
    {
        uint16_t r : 5;
        uint16_t g : 6;
        uint16_t b : 5;
    };

    uint16_t color;
    uint8_t bytes[2];
} Color;

/**********************************************************************************************************************/
/**holds the data for each music note
*   note            max <128
*   rest            bool
*   duration        max <16
*   instrument      max <4
*   articulation    max <4
*   volume          max <8
**********************************************************************************************************************/
typedef struct
{
    uint8_t note : 7;
    uint8_t rest : 1;
    uint8_t duration : 4; // increments of 1/16 for note length - 15 is a full note
    uint8_t instrument : 2;
    uint8_t articulation : 2;
    uint8_t volume : 3;
    //TODO: bits unused
    uint8_t _pad : 5;
} Note;

_Static_assert(sizeof(Note) == 3, "Note must be 3 bytes");

/**********************************************************************************************************************/
/**holds the data for a song
*   idx
*   offset
*   length
*   delay
*   numVoices
*   BPM
**********************************************************************************************************************/
typedef struct
{
    uint32_t idx;
    uint32_t offset[MAX_VOICES];
    uint16_t length[MAX_VOICES];
    uint16_t delay[MAX_VOICES];
    uint8_t numVoices;
    uint8_t BPM;
} MusicData;


/**********************************************************************************************************************/
/** defines a rectangle each value is a 2-byte signed integer
**********************************************************************************************************************/
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
} Rect_16;

_Static_assert(sizeof(Rect_16) == 8, "Rect_16 must be 8 bytes");

/**********************************************************************************************************************/
/**  Defines the position, dimensions and background colour of a frame buffer to draw to
**********************************************************************************************************************/
typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
    uint16_t bgColor;
} FrameBuffer;

_Static_assert(sizeof(FrameBuffer) == 10, "FrameBuffer must be 10 bytes");

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef struct Delta
{
    int8_t x : 4;
    int8_t y : 4;
} Delta;

//
_Static_assert(sizeof(Delta) == 1, "Delta must be 1 bytes");


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef struct

{
    union
    {
        struct
        {
            uint8_t a : 1;
            uint8_t b : 1;
            uint8_t x : 1;
            uint8_t y : 1;

            uint8_t start : 1;
            uint8_t select : 1;
            uint8_t dp_click : 1;
            uint8_t js_click : 1;

            uint8_t up : 1;
            uint8_t down : 1;
            uint8_t left : 1;
            uint8_t right : 1;

            uint8_t unused_1 : 1;
            uint8_t unused_2 : 1;
            uint8_t unused_3 : 1;
            uint8_t unused_4 : 1;
        };

        uint16_t buttons;
    };

    // Delta d;
    Delta dp;
    Delta js;

    // uint8_t _pad;
} KeyState;

_Static_assert(sizeof(KeyState) == 4, "KeyState must be 4 bytes");
