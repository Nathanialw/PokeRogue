//
// Created by nathanial on 3/3/26.
//

#include "SDL3/SDL.h"

#include "lib_debugging.h"
#include "lib_decl.h"

#include "core_ram.h"

#include "audio.h"
#include "graphics.h"
#include "hardware.h"
#include "input.h"
#include "memory.h"
#include "ram.h"

#include "battle_state.h"
#include "map_state.h"
#include "game_loss_state.h"
#include "generate_map_state.h"
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

OverlayEntry overlays[OVERLAY_GAME_STATE_SIZE] =
{
    NULL,
    OverlaySplashEntry,
    OverlayMapEntry,
    OverlayMapGenEntry,
    OverlayBattleEntry,
    OverlayGameLossEntry,
};



int main()
{
    InitAudio();
    InitMusicSystem();

    g_ramState.sound_thread = SDL_CreateThread(SoundThreadFunc, "SoundThread", NULL);
    g_ramState.music_thread = SDL_CreateThread(MusicThreadFunc, "MusicThread", NULL);

    if (SDL_CreateWindowAndRenderer("window", 1280, 800, SDL_WINDOW_RESIZABLE, &g_ramState.window, &g_ramState.renderer) != 1)
    {
        DEBUG("Failed to create window and renderer: %s\n", SDL_GetError());
        return 1;
    }

    InitRamSDL();
    LoadGameData();
    InitInput();

    GameInterface api;

    api.memory = MemoryInterfaceInit();
    api.hardware = HardwareInterfaceInit();
    api.audio = AudioInterfaceInit();
    api.graphics = GraphicsInterfaceInit();
    api.input = InputInterfaceInit();


    g_core.state.overlay = overlays[1](&api);;

    while (g_core.state.overlay != 0 && g_core.state.running)
    {
        g_core.state.overlay = overlays[g_core.state.overlay](&api);;
    }

    SDL_Quit();
    return 0;
}
