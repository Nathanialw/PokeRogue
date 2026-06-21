//
// Created by nathanial on 5/20/26.
//

#pragma once
#include <SDL3/SDL_render.h>

#include "constants.h"
#include "lib_types.h"

#define MAX_OVERLAYS 256
#define MAX_CACHED_TEXTURES 256
#define MAX_CACHED_SPRITES 256
#define MAX_CACHED_SOLID_COLORS 256


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


typedef union
{
    SDL_Color matrix[SCREEN_W][SCREEN_H];
    SDL_Color array[SCREEN_W * SCREEN_H];
} ImageBuffer;


typedef struct
{
    OverlayData overlays;



    SDL_Texture* current_target;

    SDL_Surface* surface;
    SDL_Texture* screen;
    SDL_Texture* text;
    SDL_Texture* right_wing;
    SDL_Texture* left_wing;
    SDL_Texture* pixel_buffer;
    SDL_Texture* view;

    SDL_FRect clip_rect_main;
    SDL_FRect display_rect_main;
    SDL_FRect clip_rect_left;
    SDL_FRect display_rect_left;
    SDL_FRect clip_rect_right;
    SDL_FRect display_rect_right;
    SDL_FRect clip_rect_text;
    SDL_FRect display_rect_text;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* tilesCache[MAX_CACHED_TEXTURES];
    SDL_Texture* spritesCache[MAX_CACHED_SPRITES];

    Color solidColorCacheIndexes[MAX_CACHED_SOLID_COLORS];
    SDL_Texture* solidColorCache[MAX_CACHED_SOLID_COLORS];

    // SDL_Surface* surfaceCache;
    // SDL_Texture* textureCache;
    ImageBuffer pixels;
    ImageBuffer pixels2;

    PartialFrameBuffer framebuffer;
    KeyState keys;
    uint8_t* bytes;


    uint8_t volume_effects;
    uint8_t volume_music;

    uint8_t* funcs;
    bool running;
    bool redraw;

    uint8_t* rom_bytes;

    uint8_t* music_bytes;
    size_t music_size;

    SDL_Thread *sound_thread;
    SDL_Thread *music_thread;
} RamState;


extern RamState g_ramState;
void InitRamSDL();