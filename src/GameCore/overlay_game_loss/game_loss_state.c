//
// Created by nathanial on 6/6/26.
//

#include "game_loss_state.h"
#include "lib_decl.h"
#include "lib_memory.h"

#include "core_ram.h"
#include "enums.h"


SET_MEMORY(".game_loss")
bool UpdateGameLossState(InputInterface input)
{
    if (input.GetButtonA())
    {
        g_core.state.overlay = OVERLAY_TITLE_SCREEN;
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
        g_core.state.overlay = OVERLAY_TITLE_SCREEN;
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
SET_MEMORY(".game_loss_entry")
uint8_t OverlayGameLossEntry(GameInterface* spi)
{
    spi->graphics.FillScreen((Color){.color = 0x54ff});
    spi->graphics.EndFrame();
    g_core.player.id = NO_ENTITY;

    while (g_core.state.overlay == OVERLAY_GAME_LOSS)
    {
        spi->input.HandleInput();
        UpdateGameLossState(spi->input);
        spi->graphics.EndFrame();
    }

    return g_core.state.overlay;
}
