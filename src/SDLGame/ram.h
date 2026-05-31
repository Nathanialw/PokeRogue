//
// Created by nathanial on 5/20/26.
//

#pragma once
#include <SDL3/SDL_render.h>

#include "lib_types.h"

#define MAX_OVERLAYS 256

typedef struct __attribute__((packed))
{
    uint32_t addr; //memory adress
    uint32_t size;
} Overlay;

typedef union
{
    Overlay overlay[MAX_OVERLAYS];
    uint8_t bytes[4 * 4 * MAX_OVERLAYS];
} OverlayData;


typedef struct
{
    OverlayData overlays;


    SDL_Surface* surface;
    SDL_Texture* screen;
    SDL_Window* window;
    SDL_Renderer* renderer;

    PartialFrameBuffer framebuffer;
    KeyState keys;
    uint8_t* bytes;
    uint8_t* funcs;
    bool running;
} RamState;


extern RamState g_ramState;
void InitRamSDL();
