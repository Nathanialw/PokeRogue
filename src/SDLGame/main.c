//
// Created by nathanial on 3/3/26.
//
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */

#include "SDL3/SDL.h"
#include <SDL3/SDL_main.h>

#include "audio.h"
#include "lib_debugging.h"
#include "lib_decl.h"

#include "battle_state.h"
#include "core_ram.h"
#include "generate_map_state.h"
#include "graphics.h"
#include "hardware.h"
#include "input.h"
#include "map_state.h"
#include "memory.h"
#include "splash_state.h"

/**************************************************************************************************************************************************
 *
 *      - init
 *      - function pointer overlay loop
 *
 **************************************************************************************************************************************************/


typedef uint8_t (*OverlayEntry)(GameInterface* spi);


// GAME_CORE, //reserved for core code
// GAME_SPLASH,
// GAME_MAP,
// GAME_MAP_GEN,
// GAME_BATTLE,

OverlayEntry overlays[12] =
{
    NULL,
    GameLoopTitleScreen,
    GameLoopMain,
    GameLoopEntry,
    BattleLoopMain,
};

GameInterface api;


static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;


/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Hello World", 320, 320, SDL_WINDOW_BORDERLESS, &window, &renderer))
    {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    api.memory = MemoryInterfaceInit();
    api.hardware = HardwareInterfaceInit();
    api.audio = AudioInterfaceInit();
    api.graphics = GraphicsInterfaceInit();
    api.input = InputInterfaceInit();

    g_core.state.overlay = overlays[1](&api);;

    DEBUG("Hello World!");

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_KEY_DOWN ||
        event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS; /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{

    overlays[g_core.state.overlay](&api);;


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);


    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
}
