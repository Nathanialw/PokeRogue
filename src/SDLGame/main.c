//
// Created by nathanial on 3/3/26.
//

#include "SDL3/SDL.h"

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
#include "ram.h"
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
    MapGenEntry,
    BattleLoopMain,
};

GameInterface api;

int main()
{
    if (SDL_CreateWindowAndRenderer("window", SCREEN_W, SCREEN_H, 0, &g_ramState.window, &g_ramState.renderer) != 1)
    {
        printf("Failed to create window and renderer: %s\n", SDL_GetError());
        return 1;
    }

    InitRamSDL();
    LoadGameData();

    api.memory = MemoryInterfaceInit();
    api.hardware = HardwareInterfaceInit();
    api.audio = AudioInterfaceInit();
    api.graphics = GraphicsInterfaceInit();
    api.input = InputInterfaceInit();


    g_core.state.overlay = overlays[1](&api);;

    while (g_core.state.overlay != 0)
    {
        g_core.state.overlay = overlays[g_core.state.overlay](&api);;
    }

    return 0;
}
