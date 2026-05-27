//
// Created by nathanial on 5/19/26.
//

#include "splash_state.h"

#include "core_ram.h"
#include "lib_memory.h"
#include "lib_decl.h"
#include "enums.h"
#include "lib_debugging.h"


#define TITLE_RATE_DELAY 500


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".splash")
void TitleRateDelay(HardwareInterface hardware)
{
    hardware.SleepMS(TITLE_RATE_DELAY);
}


SET_MEMORY(".splash")
bool UpdateGameTitleState(InputInterface input)
{
    if (input.GetButtonA())
    {
        g_core.state.overlay = OVERLAY_GEN_MAP;
    }

    if (input.GetButtonB())
    {
    }

    if (input.GetButtonX())
    {
    }

    if (input.GetButtonY())
    {
    }

    if (input.GetButtonStart())
    {
        g_core.state.overlay = OVERLAY_GEN_MAP;
    }

    if (input.GetButtonSelect())
    {
    }

    if (input.GetButtonJSClick())
    {
    }

    if (input.GetButtonDPClick())
    {
    }

    if (input.GetJSPressed())
    {
    }

    if (input.GetDPPressed())
    {
    }


    return false;
}


/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
SET_MEMORY(".splash_entry")
uint8_t GameLoopTitleScreen(GameInterface* spi)
{
    g_core.state.overlay = OVERLAY_TITLE_SCREEN;
    spi->graphics.FillScreen((Color){.color = 0x546a});
    spi->graphics.EndFrame();


    while (g_core.state.overlay == OVERLAY_TITLE_SCREEN)
    {
        spi->input.HandleInput();
        UpdateGameTitleState(spi->input);
        TitleRateDelay(spi->hardware);
        spi->graphics.EndFrame();
    }

    return g_core.state.overlay;
}
