//
// Created by nathanial on 2/27/26.
//

#include "game_state.h"

#include "menu.h"
#include "player.h"
#include "memory_ram.h"
#include "menu_battle.h"
#include "menu_main.h"
#include "animation.h"
#include "battles.h"
#include "core.h"
#include "graphics.h"
#include "memory_rom.h"
#include "rendering.h"
#include "sound.h"
#include "types.h"

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
Delta SetDelta(Delta newDelta)
{
    g_run.btns.d = newDelta;
    return g_run.btns.d;
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
    DEBUG("SetBattleState %d", state);
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
State UpdateGameState(State state)
{
    if (state.gameState == GAME_RUNNING)
    {
        if (g_run.btns.RedClick_Pressed)
        {
            state.inputState = REBOOT;
        }


        if (state.inputState == BATTLE)
        {
            if (g_run.btns.RedClick_Pressed)
            {
            }

            if (g_run.btns.WhiteClick_Pressed)
            {
                bool b = BattleMenuCommand();
                if (!b) return state; //No state change for menu input
                SetBattleState(BATTLE_ATTACK);
                state.battleState = BATTLE_ATTACK;
                return state;
            }

            if (g_run.btns.BlueClick_Pressed)
            {
                ExitMenu();
            }


            if (g_run.btns.JSClick_Pressed)
            {
            }

            if (g_run.btns.JS_Pressed)
            {
                if (!SetMenuDelta(g_run.btns.d))
                    UpdateBattleMenu();
            }

            if (g_run.btns.DPad_Pressed)
            {
                if (!SetMenuDelta(g_run.btns.d))
                    UpdateBattleMenu();
            }
            return state;
        }


        if (state.inputState == MENU)
        {
            if (g_run.btns.WhiteClick_Pressed)
            {
                if (!OpenSubMenu())
                {
                    state.inputState = MOVING;
                }
                return state;
            }


            if (g_run.btns.BlueClick_Pressed)
            {
                if (!MenuBack())
                {
                    state.inputState = MOVING;
                }

                return state;
            }


            if (g_run.btns.JS_Pressed)
            {
                if (!SetMenuDelta(g_run.btns.d))
                    OpenSubMenu();
                return state;
            }


            if (g_run.btns.DPad_Pressed)
            {
                if (!SetMenuDelta(g_run.btns.d))
                    OpenSubMenu();
                return state;
            }
        }


        if (state.inputState == MOVING)
        {
            if (g_run.btns.WhiteClick_Pressed)
            {
            }


            if (g_run.btns.BlueClick_Pressed)
            {
            }


            if (g_run.btns.GreenClick_Pressed)
            {
                InitMainMenu();
                state.inputState = MENU;
                return state;
            }


            if (g_run.btns.JS_Pressed)
            {
                SetPlayerDelta(g_run.btns.d);
                return state;
            }

            if (g_run.btns.DPad_Pressed)
            {
                SetPlayerDelta(g_run.btns.d);
                return state;
            }
        }
    }


    if (state.gameState == TITLE_SCREEN)
    {
        if (g_run.btns.WhiteClick_Pressed)
            state.gameState = GAME_RUNNING;
    }

    return state;
}

/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
void HandleGameState(State updateState)
{
    if (updateState.inputState == MOVING)
    {
        UpdateGame();
        RenderObjects();
    }
    if (updateState.inputState == MENU)
    {
        HandleMenu();
        HandleGameMenu();
        DrawCursor();
    }
    if (updateState.inputState == BATTLE)
    {
        if (CheckBattleState(BATTLE_INIT))
        {
            AnimationScreenClearRandom(); //ANIMATION - move both creatures into place
            HandleBattle();
            HandleBattleMenu();
            SetBattleState(BATTLE_MENUS);
        }
        else if (CheckBattleState(BATTLE_ATTACK))
        {
            BattlerAnimationAttack(true); //attacking animation
            BattlerAnimationStruck(false); //hit animation
            AnimationUpdateHealth(true);
            if (!CheckPlayerAttackOutcome())
            {
                AnimationBattlerDie(false);
                DestroyEnemyCreature();
                AnimationScreenFade(); //ANIMATION - enemy creature drops off screen
                FullRedraw();
                SetInputState(MOVING);
                return;
            }

            UseSkill(false);
            BattlerAnimationAttack(false); //attacking animation
            BattlerAnimationStruck(true); //hit animation
            AnimationUpdateHealth(false);
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
            HandleBattleMenu();
        }
        DrawCursor();
    }

    PlaySoundEffect();
}


/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
bool GameLoopTitleScreen()
{
    FillScreen(g_gameFlash.GetColor[PAL_OFF_WHITE_GRAY]); // TODO: update to real title screen

    while (g_run.state.gameState == TITLE_SCREEN)
    {
        // Pico_AnimationTitle();
        g_run.state = HandleInput(g_run.state);
    }

    InitGame();
    return true;
}


bool GameLoopMain()
{
    FullRedraw();
    while (g_run.state.gameState == GAME_RUNNING)
    {
        g_run.state = HandleInput(g_run.state);
        HandleGameState(g_run.state);
    }
    return true;
}

bool GameLoopNewMap()
{
    NewMap();
    g_run.state.gameState = GAME_RUNNING;
    return true;
}


bool GameLoopShutdown()
{
    return false;
}


typedef bool (*GameLoopFunc)();
GameLoopFunc GameLoopState[GAME_STATE_SIZE] = {GameLoopTitleScreen, GameLoopMain, GameLoopNewMap, GameLoopShutdown};

/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
void GameLoop()
{
    g_run.state.gameState = TITLE_SCREEN;
    g_run.state.inputState = MOVING;


    while (1)
    {
        bool b = GameLoopState[g_run.state.gameState]();
        if (!b) return;
    }
}
