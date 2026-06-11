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
#include "battle_ram.h"
#include "battle_ui.h"
#include "core_entities.h"
#include "core_memory_access.h"
#include "core_utils.h"


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
            bool use_skill_success = BattleMenuCommand(graphics, hardware, input, memory);
            if (!use_skill_success) return; //No state change for menu input
            SetBattleState(BATTLE_ATTACK);
        }

        if (input.GetButtonB())
        {
            ExitMenu(memory);
            HandleBattle(graphics, hardware, memory);
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
            if (!SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().js))
                UpdateBattleMenu(input, graphics, memory);
        }

        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().dp))
                UpdateBattleMenu(input, graphics, memory);
        }
    }
}


/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleStateInit(GameInterface* spi)
{
    spi->graphics.FillScreen(Flash_GetColor(spi->memory, PAL_OFF_WHITE_GRAY));
    // AnimationScreenClearRandom(spi->graphics, spi->hardware); //ANIMATION - move both creatures into place
    AnimationBattlerStart(spi->graphics, spi->hardware, spi->memory);
    HandleBattle(spi->graphics, spi->hardware, spi->memory);
    HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
    SetBattleState(BATTLE_MENUS);
    DrawCursor(spi->graphics, spi->memory);
    spi->graphics.EndFrame();

    g_battle.end_battle = false;
    g_battle.pass_turn = false;
    for (uint8_t i = 0; i < MAX_DEAD_CREATURES_CACHED; i++)
        g_battle.dead_creatures[i] = NO_ENTITY;
}

void CleanUpBattleState(GameInterface* spi)
{
    if (g_core.battleMode.enemy_trainer_id != NO_ENTITY)
    {
        SetBit(g_core.player.defeated_trainers, g_core.battleMode.enemy_trainer_id, true);
        DestroyTrainer(g_core.battleMode.enemy_trainer_id);
        g_core.battleMode.enemy_trainer_id = NO_ENTITY;
    }

    for (uint8_t i = 0; i < MAX_DEAD_CREATURES_CACHED; i++)
        DestroyCreature(g_battle.dead_creatures[i]);
}

SET_MEMORY(".battle")
void HandleBattleState(GameInterface* spi)
{
    if (CheckBattleState(BATTLE_ATTACK))
    {
        CombatLogFullDraw(spi->graphics, spi->memory);
        if (!g_battle.pass_turn)
        {
            AnimationUpdateMana(spi->graphics, spi->hardware, spi->memory, false);
            BattlerAnimationAttack(spi->graphics, spi->hardware, spi->memory, true); //attacking animation
            BattlerAnimationStruck(spi->graphics, spi->hardware, spi->memory, false); //hit animation
            AnimationUpdateHealth(spi->graphics, spi->hardware, spi->memory, true);
        }
        else
        {
            //spells or item used
        }
        g_battle.pass_turn = false;

        if (!CheckPlayerAttackOutcome())
        {
            SetBattleState(BATTLE_DEAD_ENEMY);
        }
        else if (g_battle.end_battle)
        {
            SetBattleState(BATTLE_CAPTURE_ENEMY);
        }
        else
        {
            if (UseSkill(spi->hardware, spi->memory, false))
            {
                CombatLogFullDraw(spi->graphics, spi->memory);
                AnimationUpdateMana(spi->graphics, spi->hardware, spi->memory, true);
                BattlerAnimationAttack(spi->graphics, spi->hardware, spi->memory, false); //attacking animation
                BattlerAnimationStruck(spi->graphics, spi->hardware, spi->memory, true); //hit animation
                AnimationUpdateHealth(spi->graphics, spi->hardware, spi->memory, false);
            }

            if (CheckEnemyAttackOutcome())
            {
                SetBattleState(BATTLE_DEAD_FRIEND);
            }
            else
            {
                SetBattleState(BATTLE_MENUS);
            }
        }
    }
    else if (CheckBattleState(BATTLE_MENUS))
    {
        HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
        EffectAnimation(spi->graphics, spi->hardware, spi->memory);
        DrawCursor(spi->graphics, spi->memory);
    }


    if (CheckBattleState(BATTLE_DEAD_ENEMY))
    {
        AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
        DestroyEnemyCreature(spi->hardware);
        AnimationUpdateXP(spi->graphics, spi->hardware, spi->memory);
        SetInputState(INPUT_ACTING);
        g_core.state.overlay = OVERLAY_MAP;
        return;
    }

    if (CheckBattleState(BATTLE_CAPTURE_ENEMY))
    {
        AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
        SetInputState(INPUT_ACTING);
        g_core.state.overlay = OVERLAY_MAP;
        return;
    }


    if (CheckBattleState(BATTLE_DEAD_FRIEND))
    {
        g_core.state.overlay = OVERLAY_GAME_LOSS;

        //ANIMATION - player's creature drops off screen
        if (false) // if no more creatures left
        {
            g_core.state.overlay = OVERLAY_TITLE_SCREEN;
            // updateState.inputState = TITLE_SCREEN;
        }
    }
}


bool MainBattleLoop(GameInterface* spi)
{
    return true;
}


SET_MEMORY(".battle_entry")
uint8_t OverlayBattleEntry(GameInterface* spi)
{
    InitBattleMenu();
    HandleBattleStateInit(spi);

    while (g_core.state.overlay == OVERLAY_BATTLE)
    {
        spi->input.HandleInput();
        UpdateBattleRunningState(spi->graphics, spi->hardware, spi->input, spi->memory);;
        HandleBattleState(spi);
        MainBattleLoop(spi);;
        spi->graphics.EndFrame();
    }

    CleanUpBattleState(spi);

    return g_core.state.overlay;
}
