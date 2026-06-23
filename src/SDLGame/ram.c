//
// Created by nathanial on 5/20/26.
//

#include "ram.h"

#include <SDL3/SDL_log.h>

#include "lib_types.h"
#include "SDL3/SDL_oldnames.h"


RamState g_ramState =
{
    .redraw = false,
    .keys = {0},
    .running = true,
    .scale = 0.0f,

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

    g_ramState.text = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.text)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }

    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.text);
    SDL_SetRenderDrawColor(g_ramState.renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(g_ramState.renderer, NULL);

    g_ramState.right_wing = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.right_wing)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }


    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.right_wing);
    SDL_SetRenderDrawColor(g_ramState.renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(g_ramState.renderer, NULL);

    g_ramState.left_wing = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, SCREEN_W, SCREEN_H);
    if (!g_ramState.left_wing)
    {
        SDL_Log("CreateTexture failed: %s", SDL_GetError());
    }

    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.left_wing);
    SDL_SetRenderDrawColor(g_ramState.renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(g_ramState.renderer, NULL);

    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.screen);
}
