//
// Created by nathanial on 5/20/26.
//

#include "ram.h"

#include <SDL3/SDL_log.h>

#include "lib_types.h"


RamState g_ramState =
{
    .redraw = false,
    .keys = {0},
    .running = true,


    .volume_effects = 5,
    .volume_music = 1,
};


void InitRamSDL()
{
    g_ramState.screen = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.screen)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }

    g_ramState.pixel_buffer = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.pixel_buffer)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }

    g_ramState.view = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.view)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }
}
