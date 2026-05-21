//
// Created by nathanial on 5/20/26.
//

#include "ram.h"

#include <SDL3/SDL_log.h>

#include "lib_types.h"




RamState g_ramState =
{
    .keys = {0}
};


void InitRamSDL()
{
    g_ramState.screen = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGB565, SDL_TEXTUREACCESS_STREAMING, SCREEN_W, SCREEN_H);
    if (!g_ramState.screen)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }
}
