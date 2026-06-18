//
// Created by nathanial on 5/19/26.
//

#include "map_state.h"

#include "lib_memory.h"
#include "lib_decl.h"
#include "lib_enums.h"
#include "lib_constants.h"


#include "core_graphics.h"
#include "core_menu.h"
#include "core_ram.h"
#include "core_state.h"

#include "map_camera.h"
#include "map_graphics.h"
#include "map_menu.h"
#include "map_movement.h"
#include "map_player.h"
#include "map_rendering.h"
#include "tooltip.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetGameLoopRateDefault()
{
    g_core.btns.gameLoopRate = g_core.btns.defaultGameLoopRate;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetGameLoopRate(uint16_t time)
{
    g_core.btns.gameLoopRate = time;
}


SET_MEMORY(".map")
void GameLoopRateDelay(HardwareInterface hardware)
{
    hardware.SleepMS(g_core.btns.gameLoopRate);
}


/**********************************************************************************************************************/
/*  input handling based on game state
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateGameRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, AudioInterface audio)
{
    if (g_core.state.inputState == INPUT_MENU)
    {
        if (input.GetButtonA())
        {
            if (!OpenSubMenu(graphics, hardware, input, memory))
            {
                SetInputState(INPUT_IDLE);
            }
            return;
        }

        if (input.GetButtonB())
        {
            if (!MenuBack(memory))
            {
                SetInputState(INPUT_IDLE);
                SetGameLoopRateDefault();
                FullRedraw(graphics, hardware, memory);
                graphics.EndFrame();
            }

            return;
        }

        if (input.GetButtonX())
        {
        }

        if (input.GetButtonY())
        {
        }


        if (input.GetButtonStart())
        {
            if (!MenuBack(memory))
            {
                SetInputState(INPUT_IDLE);
                SetGameLoopRateDefault();
                FullRedraw(graphics, hardware, memory);
                graphics.EndFrame();
            }

            audio.PlaySoundEffect(GetMenuSoundId(MENU_MAIN_OPEN));
            return;
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
            SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().js);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_NEXT));
            return;
        }


        if (input.GetDPPressed())
        {
            SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().dp);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_NEXT));
            return;
        }
    }

    if (g_core.state.inputState == INPUT_USE)
    {
        if (input.GetButtonA())
        {
            ActionOutcome action_outcome = PlayerInteractObjectInCell(memory, hardware);
            if (action_outcome == ACTION_SUCCEEDED)
                FullRedraw(graphics, hardware, memory);
            return;
        }

        if (input.GetButtonB())
        {
            BackUseOnParty(memory);
            SetInputState(INPUT_ACTING);
            FullRedraw(graphics, hardware, memory);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_BACK));
            return;
        }

        if (input.GetButtonX())
        {
        }

        if (input.GetButtonY())
        {
        }


        if (input.GetButtonStart())
        {
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
            SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().js);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_NEXT));
            return;
        }


        if (input.GetDPPressed())
        {
            SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().dp);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_NEXT));
            return;
        }
    }


    if (g_core.state.inputState == INPUT_IDLE)
    {
        if (input.GetButtonA())
        {
            bool action_outcome = PlayerInteractItemInCell();

            if (!action_outcome)
                PlayerInteractObjectInCell(memory, hardware);

            FullRedraw(graphics, hardware, memory);
            return;
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
            InitMainMenu();
            SetInputState(INPUT_MENU);
            SetGameLoopRate(MENU_INPUT_POLLING_RATE);
            return;
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
            SetInputState(INPUT_ACTING);
        }

        if (input.GetDPPressed())
        {
            SetInputState(INPUT_ACTING);
        }
    }


    if (g_core.state.inputState == INPUT_ACTING)
    {
        SetInputState(INPUT_IDLE);

        if (input.GetButtonA())
        {
            bool action_outcome = PlayerInteractItemInCell();

            if (!action_outcome)
                PlayerInteractObjectInCell(memory, hardware);

            FullRedraw(graphics, hardware, memory);
            return;
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
            InitMainMenu();
            SetInputState(INPUT_MENU);
            SetGameLoopRate(MENU_INPUT_POLLING_RATE);
            return;
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
            SetInputState(INPUT_ACTING);
            SetPlayerDelta(input.GetInputKeyState().js);
            return;
        }

        if (input.GetDPPressed())
        {
            SetInputState(INPUT_ACTING);
            SetPlayerDelta(input.GetInputKeyState().dp);
            return;
        }
    }
}


/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameState(GameInterface* spi)
{
    if (g_core.state.inputState == INPUT_ACTING)
    {
        UpdateGame(spi->memory, spi->hardware, spi->audio);
        RenderObjects(spi->graphics, spi->hardware, spi->memory);
        UpdateTooltip(spi->graphics, spi->memory);
        g_core.turn_count++;
        spi->graphics.EndFrame();
    }

    if (g_core.state.inputState == INPUT_MENU || g_core.state.inputState == INPUT_USE)
    {
        HandleMenu(spi->graphics, spi->hardware, spi->memory, spi->audio);
        HandleGameMenu(spi->graphics, spi->hardware, spi->memory);
        DrawCursor(spi->graphics, spi->memory);
        spi->graphics.EndFrame();
    }

    if (g_core.state.inputState == INPUT_IDLE)
    {
        spi->graphics.EndFrame();
    }

    // spi.audio.PlaySoundEffect();
}


SET_MEMORY(".map_entry")
uint8_t OverlayMapEntry(GameInterface* spi)
{
    SetCameraPlayer();

    FullRedraw(spi->graphics, spi->hardware, spi->memory);
    spi->graphics.EndFrame();
    InitMainMenu();

    while (g_core.state.overlay == OVERLAY_MAP && g_core.state.running)
    {
        spi->input.HandleInput();
        UpdateGameRunningState(spi->graphics, spi->hardware, spi->input, spi->memory, spi->audio);
        HandleGameState(spi);
    }

    return g_core.state.overlay;
}
