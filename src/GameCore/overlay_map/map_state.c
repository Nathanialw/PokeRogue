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

#include "map.h"
#include "map_camera.h"
#include "map_entities.h"
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
void UpdateGameRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    if (g_core.state.inputState == INPUT_MENU)
    {
        if (input.GetButtonA())
        {
            if (!OpenSubMenu(hardware, input, memory))
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
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().js))
                OpenSubMenu(hardware, input, memory);
            return;
        }


        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().dp))
                OpenSubMenu(hardware, input, memory);
            return;
        }
    }


    if (g_core.state.inputState == INPUT_IDLE)
    {
        if (input.GetButtonA())
        {
            PlayerInteractItemInCell();
        }

        if (input.GetButtonB())
        {
            PlayerInteractObjectInCell(memory, hardware);
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
            PlayerInteractItemInCell();
        }

        if (input.GetButtonB())
        {
            PlayerInteractObjectInCell(memory, hardware);
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
        UpdateGame(spi->memory, spi->hardware);
        RenderObjects(spi->graphics, spi->hardware, spi->memory);
        UpdateTooltip(spi->graphics, spi->memory);
        g_core.turn_count++;
        spi->graphics.EndFrame();
    }

    if (g_core.state.inputState == INPUT_MENU)
    {
        HandleMenu(spi->graphics, spi->hardware, spi->memory);
        HandleGameMenu(spi->graphics, spi->hardware, spi->memory);
        DrawCursor(spi->graphics, spi->memory);
        if (g_core.menu.displayedMenu != MINIMAP) spi->graphics.EndFrame();
    }

    if (g_core.state.inputState == INPUT_IDLE)
    {
    }

    // spi.audio.PlaySoundEffect();
}


SET_MEMORY(".map_entry")
uint8_t GameLoopMain(GameInterface* spi)
{
    if (g_core.turn_count == 0)
    {
        ResetEntities(spi->hardware, spi->memory, false);
        InitPlayer(spi->hardware, spi->memory);
        PopulateLevelTrainers(spi->hardware, spi->memory);
        PopulateLevelCreatures(spi->hardware, spi->memory);
        PopulateLevelObjects(spi->hardware, spi->memory);
        PopulateLevelItems(spi->hardware, spi->memory);
        PlacePlayerOnMap(spi->hardware);
        SetMapFog(0xFF);
        InitCamera(0, 0, TILE_W * VIEW_TW, TILE_H * VIEW_TH);
        SetCameraPlayer();
        UpdateVision(spi->graphics, spi->hardware);
    }

    FullRedraw(spi->graphics, spi->hardware, spi->memory);
    spi->graphics.EndFrame();

    while (g_core.state.overlay == OVERLAY_MAP)
    {
        spi->input.HandleInput();
        UpdateGameRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);
        HandleGameState(spi);
    }

    return g_core.state.overlay;
}
