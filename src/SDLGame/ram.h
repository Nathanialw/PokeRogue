//
// Created by nathanial on 5/20/26.
//

#pragma once
#include <SDL3/SDL_render.h>

#include "lib_types.h"

typedef struct
{
    SDL_Surface* surface;
    SDL_Texture* screen;
    SDL_Window* window;
    SDL_Renderer* renderer;

    PartialFrameBuffer framebuffer;
    KeyState keys;
    uint8_t* bytes;
} RamState;


extern RamState g_ramState;
void InitRamSDL();
