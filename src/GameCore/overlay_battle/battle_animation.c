//
// Created by nathanial on 5/19/26.
//

#include "battle_animation.h"
#include "lib_memory.h"
#include "constants.h"

#include "core_ram.h"
#include "core_utils.h"

#include "battle_animation_effects.h"
#include "battle_memory_access.h"
#include "battle_ram.h"
#include "core_memory_access.h"

/************************************************************************************************************
 *
 *      Core animation control, including general animation definitions
 *
 ************************************************************************************************************/


/**********************************************************************************************************************
 *  ANIMATIONS: --- WORK IN PROGRESS ---
 *
 *  TITLE SCREEN
 *
 *  MAP
 *      MOVE - SMOOTH MOVEMENT BETWEEN CELLS
 *      IDLE - 3 FRAME ANIMATIONS
 *      SPELL - CUSTOM ANIMATIONS (difficult, perhaps animations by spell type)
 *  BATTLES
 *      BATTLE START    - CLEAR SCREEN (several animations, random) - CREATURE BATTERS SLIDE INTO FRAME
 *      BATTLE END      - CLEAR SCREEN FADEOUT
 *      USE SKILL       - MANA SLIDES DOWN - CUSTOM ANIMATIONS (difficult, perhaps animations by skill type)
 *      DAMAGE TAKEN    - HEALTH SLIDES DOWN
 *      ON KILL         - XP SLIDES UP
 *      ON LEVEL UP     - LEVEL UP ANIMATION
 *  MENU
 *      PARTY FRAME - HEALTH SLIDES UP - MANA SLIDES UP
 *
**********************************************************************************************************************/

/************************************************************************************************************
 *
 *      UI ANIMATIONS
 *
 ************************************************************************************************************/


/************************************************************************************************************
 *  HEALTH - FALL
 *  HEALTH - RISE TODO: NOT IMPLEMENTED YET
 ************************************************************************************************************/
SET_MEMORY(".battle")
void UpdateResourceBar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, uint16_t offset_h, uint16_t cache_value, uint_max999* stat, bool attackersTurn)
{
    Rect_16 r = {0};
    uint16_t cur_mp = 0;
    uint16_t max_mp = 0;

    if (attackersTurn)
    {
        r = ENEMY_RESOURCE_FRAME;
        const EntityId e_id = g_core.battleMode.enemyMonsterID;
        cur_mp = Int999GetCurrent(&stat[e_id]);
        max_mp = Int999GetMax(&stat[e_id]);
    }
    else
    {
        r = PLAYER_RESOURCE_FRAME;
        const EntityId p_id = g_core.battleMode.playerMonsterID;
        cur_mp = Int999GetCurrent(&stat[p_id]);
        max_mp = Int999GetMax(&stat[p_id]);
    }

    const uint8_t pad = 1;
    const uint8_t pad2 = pad << 1;

    const uint16_t x = ((r.x + TEXT_W) + pad);
    const uint16_t bar_w = (r.w - (TEXT_W * 2)) - pad2;

    const uint16_t current_bar = (uint16_t)(((uint32_t)cache_value * bar_w) / max_mp);
    const uint16_t change_w = (uint16_t)(((uint32_t)(max_mp - cur_mp) * bar_w) / max_mp);

    const uint16_t y = r.y + offset_h + pad;
    const uint16_t w = 1;
    const uint16_t h = RESOURCE_HEIGHT - pad2;


    uint16_t start_x = x + current_bar;
    const uint16_t end_pos = x + (bar_w - change_w);

    const Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);

    while (true)
    {
        if (start_x < end_pos || start_x <= x)
            break;
        start_x -= 1;

        graphics.FillRect(start_x, y, w, h, color_bg);
        graphics.EndFrame();
        hardware.SleepMS(6);
    }

    hardware.SleepMS(1000);
}

SET_MEMORY(".battle")
void AnimationUpdateHealth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool attackersTurn)
{
    UpdateResourceBar(graphics, hardware, memory, (TEXT_H * 2), g_core.battleMode.battle_hp_cache, g_core.creatures.hp, attackersTurn);
    g_core.battleMode.battle_hp_cache = 0;
}

/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET
 *  MANA - RISE AND FALL
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationUpdateMana(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool attackersTurn)
{
    UpdateResourceBar(graphics, hardware, memory, (TEXT_H * 3), g_core.battleMode.battle_mp_cache, g_core.creatures.mp, attackersTurn);
    g_core.battleMode.battle_mp_cache = 0;
}


/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET *
 *  XP - RISE AND FALL
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationUpdateXP(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    Rect_16 r = PLAYER_RESOURCE_FRAME;
    uint16_t cur_xp = 0;
    uint16_t max_xp = 0;

    r = PLAYER_RESOURCE_FRAME;
    EntityId p_id = g_core.battleMode.playerMonsterID;
    cur_xp = Int999GetCurrent(&g_core.creatures.xp[p_id]);
    max_xp = Int999GetMax(&g_core.creatures.xp[p_id]);

    uint8_t pad = 1;
    uint8_t pad2 = pad << 1;

    float current_bar = ((float)g_core.battleMode.battle_xp_cache / (float)max_xp);
    const float bar_w = (r.w - (TEXT_W)) - pad2;
    const uint16_t xp_w = ((float)cur_xp / (float)max_xp) * (float)bar_w;


    const uint16_t origin = r.x + TEXT_W;
    uint16_t x = (origin + (bar_w * current_bar));
    if (x > origin + TEXT_W) x -= TEXT_W;

    const uint16_t y = r.y + (TEXT_H * 4) + pad;
    const uint16_t w = 1;
    const uint16_t h = (RESOURCE_HEIGHT >> 1) - pad2;

    const uint16_t end_pos = (origin + xp_w);

    Color color_xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);

    while (true)
    {
        if (x >= end_pos)
            break;
        x += 1;

        graphics.FillRect(x, y, w, h, color_xp);
        graphics.EndFrame();
        hardware.SleepMS(15);
    }

    g_core.battleMode.battle_xp_max_cache = 0;
    hardware.SleepMS(1000);
}


/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET
 *  CLEAR SCREEN WITH A RANDOM ANIMATION
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationScreenClearRandom(GraphicsInterface graphics, HardwareInterface hardware)
{
    FrameBuffer f = {50, 100, 64, 80, 0xd6fa};
    Rect_16 r = {5, 20, 10, 10};
    Color c;
    c.color = 0x001f;

    while (true)
    {
        graphics.TestAnimation(&f, &r, &c);
        hardware.SleepMS(16);
        graphics.EndFrame();


        r.h += 1;
        if (r.h > 60)
            break;
    }
}


/************************************************************************************************************
 *  BATTLE START animation
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationBattlerStart(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    BattleStart(graphics, memory, hardware, 2);
}


/************************************************************************************************************
 *  DEATH animation
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationBattlerDie(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    if (onAttacker)
    {
        if (g_core.battleMode.playerMonsterID == NO_ENTITY)
            return;
    }
    else
    {
        if (g_core.battleMode.enemyMonsterID == NO_ENTITY)
            return;
    }

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);
    MoveCenterToDown(graphics, hardware, r, r.h, 1);
}


/************************************************************************************************************
 *  Handles all battler animations for spells, items and skills
 ************************************************************************************************************/
SET_MEMORY(".battle")
void BattlerAnimationAttack(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player)
{
    if (player)
    {
        if (g_core.battleMode.playerMonsterID == NO_ENTITY)
            return;
    }
    else
    {
        if (g_core.battleMode.enemyMonsterID == NO_ENTITY)
            return;
    }

    const ObjectsTypes move_type = g_core.battleMode.moveType;
    const ObjectType move_id = g_core.battleMode.moveID;

    if (move_type == ITEM)
        Flash_BattlerAttackAnimation(graphics, hardware, memory, move_id.ItemId, ITEM, player);
    else if (SKILL)
        Flash_BattlerAttackAnimation(graphics, hardware, memory, move_id.AbilityId, SKILL, player);
    else if (SPELL)
        Flash_BattlerAttackAnimation(graphics, hardware, memory, move_id.value, SPELL, player);
}


SET_MEMORY(".battle")
void BattlerAnimationStruck(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool player)
{
    if (player)
    {
        if (g_core.battleMode.playerMonsterID == NO_ENTITY)
            return;
    }
    else
    {
        if (g_core.battleMode.enemyMonsterID == NO_ENTITY)
            return;
    }

    const ObjectsTypes move_type = g_core.battleMode.moveType;
    const ObjectType move_id = g_core.battleMode.moveID;

    if (move_type == ITEM)
        Flash_BattlerStruckAnimation(graphics, hardware, memory, move_id.ItemId, ITEM, player);
    else if (SKILL)
        Flash_BattlerStruckAnimation(graphics, hardware, memory, move_id.AbilityId, SKILL, player);
    else if (SPELL)
        Flash_BattlerStruckAnimation(graphics, hardware, memory, move_id.value, SPELL, player);
}


SET_MEMORY(".battle")
void EffectAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    if (g_battle.effect_type == ITEM)
    {
        g_battle.effect_animation_index = NO_ITEM;
    }
    else if (g_battle.effect_type == SPELL)
    {
        g_battle.effect_animation_index = NO_SPELL;
    }

    g_battle.effect_type = NO_OBJECT_TYPE;
}
