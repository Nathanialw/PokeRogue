//
// Created by nathanial on 5/19/26.
//

#include "battle_state.h"

#include "enums.h"
#include "lib_decl.h"
#include "lib_enums.h"
#include "lib_memory.h"

#include "core_graphics.h"
#include "core_menu.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_state.h"

#include "battle_actions.h"
#include "battle_animation.h"
#include "battle_graphics.h"
#include "battle_menu.h"
#include "battle_player.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
State SetBattleState(BattleState state)
{
    g_core.state.battleState = state;
    return g_core.state;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckBattleState(BattleState state)
{
    if (g_core.state.battleState == state)
        return true;
    return false;
}


/**********************************************************************************************************************/
/*  input handling based on game state
**********************************************************************************************************************/
SET_MEMORY(".battle")
void UpdateBattleRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    if (g_core.state.inputState == INPUT_BATTLE)
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
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().d))
                UpdateBattleMenu(input);
        }

        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(hardware, input, memory, input.GetInputKeyState().d))
                UpdateBattleMenu(input);
        }
    }
}


/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleState(GameInterface* spi)
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
        BattlerAnimationAttack(spi->graphics, spi->memory, true); //attacking animation
        BattlerAnimationStruck(spi->graphics, spi->memory, false); //hit animation
        AnimationUpdateHealth(spi->graphics, spi->hardware, true);
        if (!CheckPlayerAttackOutcome())
        {
            AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
            DestroyEnemyCreature(spi->hardware);
            SetInputState(INPUT_MOVING);
            g_core.state.overlay = OVERLAY_MAP;
            g_core.state.battleState = BATTLE_INIT;
            return;
        }

        UseSkill(spi->hardware, spi->memory, false);
        BattlerAnimationAttack(spi->graphics, spi->memory, false); //attacking animation
        BattlerAnimationStruck(spi->graphics, spi->memory, true); //hit animation
        AnimationUpdateHealth(spi->graphics, spi->hardware, false);
        if (CheckEnemyAttackOutcome())
        {
            //ANIMATION - player's creature drops off screen
            if (false) // if no more creatures left
            {
                g_core.state.overlay = OVERLAY_TITLE_SCREEN;
                // updateState.inputState = TITLE_SCREEN;
            }
        }
        SetBattleState(BATTLE_MENUS);
    }
    else if (CheckBattleState(BATTLE_MENUS))
    {
        HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
        DrawCursor(spi->graphics, spi->memory);
    }
}





bool MainBattleLoop(GameInterface* spi)
{
    return true;
}


SET_MEMORY(".battle_entry")
uint8_t BattleLoopMain(GameInterface* spi)
{
    InitBattleMenu();

    while (g_core.state.overlay == OVERLAY_BATTLE)
    {
        UpdateBattleRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);;
        HandleBattleState(spi);
        MainBattleLoop(spi);;
    }

    return OVERLAY_MAP;
}