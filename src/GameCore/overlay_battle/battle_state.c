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
#include "core_input.h"
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
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
void CacheCreatureState()
{
    if (g_core.battleMode.enemyMonsterID != NO_ENTITY)
    {
        g_core.battleMode.battle_hp_cache[0] = (int16_t)Int999GetCurrent(&g_core.creatures.hp[g_core.battleMode.playerMonsterID]);
        g_core.battleMode.battle_hp_cache[1] = (int16_t)Int999GetCurrent(&g_core.creatures.hp[g_core.battleMode.enemyMonsterID]);
        g_core.battleMode.battle_mp_cache[0] = (int16_t)Int999GetCurrent(&g_core.creatures.mp[g_core.battleMode.playerMonsterID]);
        g_core.battleMode.battle_mp_cache[1] = (int16_t)Int999GetCurrent(&g_core.creatures.mp[g_core.battleMode.enemyMonsterID]);
        // g_core.battleMode.battle_xp_cache = (int16_t)Int999GetCurrent(&g_core.creatures.xp[g_core.battleMode.playerMonsterID]);
    }
}


/**********************************************************************************************************************/
/*  input handling based on game state
**********************************************************************************************************************/
SET_MEMORY(".battle")
void UpdateBattleRunningState(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, AudioInterface audio)
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
            audio.PlaySoundEffect(GetMenuSoundId(MENU_PREVIOUS));
        }

        if (input.GetDPPressed())
        {
            if (!SetMenuDelta(graphics, hardware, input, memory, input.GetInputKeyState().dp))
                UpdateBattleMenu(input, graphics, memory);
            audio.PlaySoundEffect(GetMenuSoundId(MENU_NEXT));
        }
    }
}


/**********************************************************************************************************************/
/**  Game State forking
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleStateInit(GameInterface* spi)
{
    spi->graphics.FillScreen(Flash_GetColor(spi->memory, PAL_OFF_WHITE_GRAY_BLUE));
    // AnimationScreenClearRandom(spi->graphics, spi->hardware); //ANIMATION - move both creatures into place
    AnimationBattlerStart(spi->graphics, spi->hardware, spi->memory);
    HandleBattle(spi->graphics, spi->hardware, spi->memory);
    HandleBattleMenu(spi->graphics, spi->hardware, spi->memory);
    SetBattleState(BATTLE_MENUS);
    DrawCursor(spi->graphics, spi->memory);
    DrawScreen(spi->graphics, spi->memory);

    g_battle.enemy_captured = false;
    g_battle.pass_turn = false;
    for (uint8_t i = 0; i < MAX_DEAD_CREATURES_CACHED; i++)
        g_battle.dead_creatures[i] = NO_ENTITY;
}

void CleanUpBattleState(GameInterface* spi)
{
    if (!CheckBattleState(BATTLE_FLEE))
    {
        if (g_core.battleMode.enemy_trainer_id != NO_ENTITY)
        {
            SetBit(g_core.player.defeated_trainers, g_core.battleMode.enemy_trainer_id, true);
            DestroyTrainer(g_core.battleMode.enemy_trainer_id);
        }

        for (uint8_t i = 0; i < MAX_DEAD_CREATURES_CACHED; i++)
            DestroyCreature(g_battle.dead_creatures[i]);
    }

    g_core.battleMode.enemyMonsterID = NO_ENTITY;
    g_core.battleMode.enemy_trainer_id = NO_ENTITY;
}

SET_MEMORY(".battle")
void HandleBattleState(GameInterface* spi)
{
    if (CheckBattleState(BATTLE_ATTACK))
    {
        CombatLogFullDraw(spi->graphics, spi->memory);
        if (!g_battle.pass_turn)
        {
            //TODO
            //animation  calls will eb base on item type used
            // right now g_battle.pass_turn skips this block for swaps/spells/items

            spi->audio.PlaySoundEffect(g_core.battleMode.moveID.AbilityId);
            AnimationUpdatePlayerMana(spi->graphics, spi->hardware, spi->memory);
            BattlerAnimationAttack(spi->graphics, spi->hardware, spi->memory, true); //attacking animation
            BattlerAnimationStruck(spi->graphics, spi->hardware, spi->memory, false); //hit animation
        }
        else
        {
            //spells or item used
        }

        AnimationUpdateEnemyHealth(spi->graphics, spi->hardware, spi->memory);
        AnimationUpdatePlayerHealth(spi->graphics, spi->hardware, spi->memory);
        AnimationUpdateEnemyMana(spi->graphics, spi->hardware, spi->memory);
        HandleBattle(spi->graphics, spi->hardware, spi->memory);
        // g_battle.pass_turn = false;

        if (g_battle.enemy_captured)
        {
            SetBattleState(BATTLE_CAPTURE_ENEMY);
            g_battle.enemy_captured = false;
        }
        else if (CheckPlayerAttackOutcome())
        {
            SetBattleState(BATTLE_DEAD_ENEMY);
        }
        else
        {
            CacheCreatureState();
            if (UseSkill(spi->hardware, spi->memory, false))
            {
                spi->audio.PlaySoundEffect(g_core.battleMode.moveID.AbilityId);
                CombatLogFullDraw(spi->graphics, spi->memory);
                AnimationUpdateEnemyMana(spi->graphics, spi->hardware, spi->memory);
                BattlerAnimationAttack(spi->graphics, spi->hardware, spi->memory, false); //attacking animation
                BattlerAnimationStruck(spi->graphics, spi->hardware, spi->memory, true); //hit animation
                AnimationUpdateEnemyHealth(spi->graphics, spi->hardware, spi->memory);
                AnimationUpdatePlayerHealth(spi->graphics, spi->hardware, spi->memory);
                AnimationUpdatePlayerMana(spi->graphics, spi->hardware, spi->memory);
                HandleBattle(spi->graphics, spi->hardware, spi->memory);
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

    g_core.battleMode.battle_hp_cache[0] = -1;
    g_core.battleMode.battle_hp_cache[1] = -1;
    g_core.battleMode.battle_mp_cache[0] = -1;
    g_core.battleMode.battle_mp_cache[1] = -1;

    if (CheckBattleState(BATTLE_FLEE))
    {
        SetInputState(INPUT_ACTING);
        g_core.state.overlay = OVERLAY_MAP;
        return;
    }

    if (CheckBattleState(BATTLE_DEAD_ENEMY))
    {
        AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
        DestroyEnemyCreature(spi->hardware);
        AnimationUpdateXP(spi->graphics, spi->hardware, spi->memory);
        if (!UpdateBattleCreature())
        {
            SetInputState(INPUT_ACTING);
            g_core.state.overlay = OVERLAY_MAP;
            return;
        }
    }

    if (CheckBattleState(BATTLE_CAPTURE_ENEMY))
    {
        AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, false);
        g_core.update_right_party = true;

        if (g_core.battleMode.enemy_trainer_id == NO_ENTITY)
        {
            SetInputState(INPUT_ACTING);
            g_core.state.overlay = OVERLAY_MAP;
            return;
        }

        DeleteCreatureFromParty(g_core.battleMode.enemy_trainer_id, g_core.battleMode.enemyMonsterID);
        g_core.battleMode.enemyMonsterID = NO_ENTITY;
        if (!UpdateBattleCreature())
        {
            SetInputState(INPUT_ACTING);
            g_core.state.overlay = OVERLAY_MAP;
            return;
        }
    }


    if (CheckBattleState(BATTLE_DEAD_FRIEND))
    {
        AnimationBattlerDie(spi->graphics, spi->hardware, spi->memory, true);
        bool has_next_creature = SendNextPartyCreature();

        if (!has_next_creature)
            g_core.state.overlay = OVERLAY_GAME_LOSS;
        SetBattleState(BATTLE_MENUS);

        HandleBattle(spi->graphics, spi->hardware, spi->memory);
        DrawScreen(spi->graphics, spi->memory);
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

    if (g_core.update_right_text)
    {
        g_core.update_right_text = false;
        g_core.update_right_text_clear = true;
    }

    while (g_core.state.overlay == OVERLAY_BATTLE)
    {
        bool redraw_window = spi->input.HandleInput();
        if (redraw_window)
        {
            InteractUI(spi->graphics, spi->input);
            g_core.update_text = true;
            g_core.update_right_inventory = true;
            g_core.update_right_party = true;
            g_core.update_left_spellbook = true;
            g_core.update_left_player = true;
            DrawScreen(spi->graphics, spi->memory);
        }
        else
        {
            UpdateBattleRunningState(spi->graphics, spi->hardware, spi->input, spi->memory, spi->audio);;
            HandleBattleState(spi);
            MainBattleLoop(spi);
            DrawScreen(spi->graphics, spi->memory);
        }
    }

    CleanUpBattleState(spi);

    return g_core.state.overlay;
}
