//
// Created by nathanial on 5/19/26.
//

#include "map_state.h"

#include "lib_decl.h"
#include "lib_enums.h"

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
                SetInputState(INPUT_MOVING);
            }
            return;
        }

        if (input.GetButtonB())
        {
            if (!MenuBack(memory))
            {
                SetInputState(INPUT_MOVING);
                SetGameLoopRateDefault();
                FullRedraw(graphics, hardware, memory);
            }

            return;
        }

        if (input.GetButtonX())
        {
        }

        if (input.GetButtonY())
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
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().d))
                OpenSubMenu(hardware, input, memory);
            return;
        }


        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().d))
                OpenSubMenu(hardware, input, memory);
            return;
        }
    }


    if (g_core.state.inputState == INPUT_MOVING)
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
            InitMainMenu();
            SetInputState(INPUT_MENU);
            SetGameLoopRate(MENU_INPUT_POLLING_RATE);
            return;
        }

        if (input.GetButtonJSClick())
        {
        }

        if (input.GetButtonDPClick())
        {
        }

        if (input.GetJSPressed())
        {
            SetPlayerDelta(input.GetInputKeyState().d);
            return;
        }

        if (input.GetDPPressed())
        {
            SetPlayerDelta(input.GetInputKeyState().d);
            return;
        }
    }
}



SET_MEMORY(".map.rodata")
const char test01[] = "UpdateGame\n";

SET_MEMORY(".map.rodata")
const char test02[] = "RenderObjects\n";


SET_MEMORY(".map.rodata")
const char test021[] = "DONE";
/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameState(GameInterface* spi)
{
    if (g_core.state.inputState == INPUT_MOVING)
    {
        spi->hardware.Print(test01);
        UpdateGame(spi->hardware);
        spi->hardware.Print(test02);
        RenderObjects(spi->graphics, spi->hardware, spi->memory);
    }

    if (g_core.state.inputState == INPUT_MENU)
    {
        HandleMenu(spi->graphics, spi->hardware, spi->memory);
        spi->hardware.Print(test01);
        HandleGameMenu(spi->graphics, spi->hardware, spi->memory);
        spi->hardware.Print(test02);
        DrawCursor(spi->graphics, spi->memory);
        spi->hardware.Print(test021);
    }

    // spi.audio.PlaySoundEffect();
}


SET_MEMORY(".map_entry")
uint8_t GameLoopMain(GameInterface* spi)
{
    g_core.state.overlay = OVERLAY_MAP;
    spi->graphics.FillScreen(0x0f00); // TODO: update to real title screen
    ResetEntities(spi->hardware, spi->memory, false);
    InitPlayer(spi->hardware, spi->memory);
    PopulateLevelCreatures(spi->hardware, spi->memory);
    PopulateLevelObjects(spi->hardware, spi->memory);
    PopulateLevelItems(spi->hardware, spi->memory);
    PlacePlayerOnMap(spi->hardware);
    SetMapFog(0xFF);
    InitCamera(0, 0, TILE_W * VIEW_TW, TILE_H * VIEW_TH);
    SetCameraPlayer();
    FullRedraw(spi->graphics, spi->hardware, spi->memory);

    while (g_core.state.overlay == OVERLAY_MAP)
    {
        spi->input.HandleInput();
        UpdateGameRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);
        HandleGameState(spi);
        GameLoopRateDelay(spi->hardware);
    }

    return g_core.state.overlay;
}