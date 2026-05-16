//
// Created by nathanial on 2/27/26.
//

#include "game_state.h"

#include "lib_debugging.h"
#include "lib_decl.h"
#include "lib_memory.h"

#include "menu.h"
#include "player.h"
#include "memory_ram.h"
#include "menu_battle.h"
#include "menu_main.h"
#include "animation.h"
#include "battles.h"
#include "camera.h"
#include "core.h"
#include "entities.h"
#include "graphics.h"
#include "map.h"
#include "memory_rom.h"
#include "rendering.h"


#define TITLE_RATE_DELAY 500

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
void SetGameLoopRateDefault()
{
    g_run.btns.gameLoopRate = g_run.btns.defaultGameLoopRate;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
void SetGameLoopRate(uint16_t time)
{
    g_run.btns.gameLoopRate = time;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".splash")
void TitleRateDelay(HardwareInterface hardware)
{
    hardware.SleepMS(TITLE_RATE_DELAY);
}


void GameLoopRateDelay(HardwareInterface hardware)
{
    hardware.SleepMS(g_run.btns.gameLoopRate);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
State SetInputState(InputState state)
{
    g_run.state.inputState = state;
    return g_run.state;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
State SetBattleState(BattleState state)
{
    g_run.state.battleState = state;
    return g_run.state;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CheckBattleState(BattleState state)
{
    if (g_run.state.battleState == state)
        return true;
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
State SetGameState(GameState state)
{
    g_run.state.gameState = state;
    return g_run.state;
}


/**********************************************************************************************************************/
/*  input handling based on game state
**********************************************************************************************************************/
void UpdateBattleRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    if (g_run.state.inputState == BATTLE)
    {
        if (input.GetButtonA())
        {
            bool b = BattleMenuCommand(hardware, input, memory);
            if (!b) return; //No state change for menu input
            SetBattleState(BATTLE_ATTACK);
        }

        if (input.GetButtonB())
        {
            ExitMenu();
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
            if (!SetMenuDelta(input, memory, input.GetInputKeyState().d))
                UpdateBattleMenu(input);
        }

        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(input, memory, input.GetInputKeyState().d))
                UpdateBattleMenu(input);
        }
        return;
    }
}

/**********************************************************************************************************************/
/*  input handling based on game state
**********************************************************************************************************************/
void UpdateGameRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    if (g_run.state.inputState == MENU)
    {
        if (input.GetButtonA())
        {
            if (!OpenSubMenu(input, memory))
            {
                SetInputState(MOVING);
            }
            return;
        }

        if (input.GetButtonB())
        {
            if (!MenuBack(memory))
            {
                SetInputState(MOVING);
                SetGameLoopRateDefault();
                FullRedraw(graphics, memory);
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
            if (!SetMenuDelta(input, memory, input.GetInputKeyState().d))
                OpenSubMenu(input, memory);
            return;
        }


        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(input, memory, input.GetInputKeyState().d))
                OpenSubMenu(input, memory);
            return;
        }
    }


    if (g_run.state.inputState == MOVING)
    {
        if (input.GetButtonA())
        {
            PlayerInteractItemInCell();
        }

        if (input.GetButtonB())
        {
            PlayerInteractObjectInCell(memory);
        }

        if (input.GetButtonX())
        {
        }

        if (input.GetButtonY())
        {
            InitMainMenu();
            SetInputState(MENU);
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

SET_MEMORY(".splash")
bool UpdateGameTitleState(InputInterface input)
{
    if (input.GetButtonA())
    {
        return true;
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
/**  Game State forking
**********************************************************************************************************************/
void HandleGameState(GameInterface* spi)
{
    if (g_run.state.inputState == MOVING)
    {
        UpdateGame(spi->hardware);
        RenderObjects(spi->graphics, spi->hardware, spi->memory);
    }
    if (g_run.state.inputState == MENU)
    {
        HandleMenu(spi->graphics, spi->hardware, spi->memory);
        HandleGameMenu(spi->graphics, spi->hardware, spi->memory);
        DrawCursor(spi->graphics, spi->memory);
    }
    if (g_run.state.inputState == BATTLE)
    {
        if (CheckBattleState(BATTLE_INIT))
        {
            AnimationScreenClearRandom(spi->graphics, spi->hardware); //ANIMATION - move both creatures into place
            HandleBattle(spi->graphics, spi->hardware, spi->memory);
            HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
            SetBattleState(BATTLE_MENUS);
        }
        else if (CheckBattleState(BATTLE_ATTACK))
        {
            BattlerAnimationAttack(spi->graphics, true); //attacking animation
            BattlerAnimationStruck(spi->graphics, false); //hit animation
            AnimationUpdateHealth(spi->graphics, spi->hardware, true);
            if (!CheckPlayerAttackOutcome())
            {
                AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
                DestroyEnemyCreature(spi->hardware);
                AnimationScreenFade(spi->graphics, spi->hardware); //ANIMATION - enemy creature drops off screen
                FullRedraw(spi->graphics, spi->memory);
                SetInputState(MOVING);
                return;
            }

            UseSkill(spi->hardware, spi->memory, false);
            BattlerAnimationAttack(spi->graphics, false); //attacking animation
            BattlerAnimationStruck(spi->graphics, true); //hit animation
            AnimationUpdateHealth(spi->graphics, spi->hardware, false);
            if (CheckEnemyAttackOutcome())
            {
                //ANIMATION - player's creature drops off screen
                if (false) // if no more creatures left
                {
                    // updateState.inputState = TITLE_SCREEN;
                }
            }
            SetBattleState(BATTLE_MENUS);
        }
        else if (CheckBattleState(BATTLE_MENUS))
        {
            HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
        }
        DrawCursor(spi->graphics, spi->memory);
    }

    // spi.audio.PlaySoundEffect();
}

/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
SET_MEMORY(".splash_entry")
uint8_t GameLoopTitleScreen(GameInterface* spi)
{
    spi->graphics.FillScreen(0xF000); // TODO: update to real title screen
    int start = 0;
    while (start == 0)
    {
        spi->input.HandleInput();
        start = UpdateGameTitleState(spi->input);
        TitleRateDelay(spi->hardware);
    }

    return GAME_MAP_GEN;
}


bool MainBattleLoop(GameInterface* spi)
{
    return true;
}


SET_MEMORY(".battle_entry")
uint8_t BattleLoopMain(GameInterface* spi)
{
    bool battling = true;
    while (battling)
    {
        UpdateBattleRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);;
        battling = MainBattleLoop(spi);;
    }

    return GAME_MAP;
}

SET_MEMORY(".map_gen_entry")
uint8_t GameLoopEntry(GameInterface* spi)
{
    InitGame(spi->hardware, spi->memory);
    return GAME_MAP;
}

SET_MEMORY(".map_entry")
uint8_t GameLoopMain(GameInterface* spi)
{
    ResetEntities(spi->hardware, spi->memory, true);
    PopulateLevelCreatures(spi->hardware, spi->memory);
    PopulateLevelObjects(spi->hardware, spi->memory);
    PopulateLevelItems(spi->hardware, spi->memory);
    PlacePlayerOnMap(spi->hardware);
    SetMapFog(0xFF);

    InitCamera(0, 0, TILE_W * VIEW_TW, TILE_H * VIEW_TH);
    SetCameraPlayer();

    FullRedraw(spi->graphics, spi->memory);

    while (g_run.state.gameState == GAME_RUNNING)
    {
        spi->input.HandleInput();
        UpdateGameRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);
        HandleGameState(spi);
        GameLoopRateDelay(spi->hardware);
    }
}

// __attribute__((section(".strings")))
bool GameLoopNewMap(GameInterface* spi)
{
    NewMap();
    SetGameState(GAME_RUNNING);
    return true;
}


bool GameLoopShutdown(GameInterface* spi)
{
    return false;
}


typedef uint8_t (*GameLoopFunc)(GameInterface* spi);
GameLoopFunc GameLoopState[GAME_STATE_SIZE] = {GameLoopTitleScreen, GameLoopMain, GameLoopNewMap, GameLoopShutdown};


SET_MEMORY(".battle")
void TestMain(GameInterface* spi)
{
    uint16_t color = 0x000A;

    while (1)
    {
        spi->input.HandleInput();
        if (spi->input.GetButtonA())
            color = 0xA000;
        else if (spi->input.GetButtonB())
            color = 0x041F;
        else if (spi->input.GetButtonX())
            color = 0xF10A;

        spi->graphics.FillScreen(color);
        spi->hardware.SleepMS(100);
    }
}


/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
void GameLoop(GameInterface* spi)
{
    SetInputState(MOVING);
    SetGameState(TITLE_SCREEN);

    while (1)
    {
        bool b = GameLoopState[g_run.state.gameState](spi);
        if (!b) return;
    }
}
