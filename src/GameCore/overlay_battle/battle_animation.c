//
// Created by nathanial on 5/19/26.
//

#include "battle_animation.h"

#include "core_ram.h"

#include "battle_animation_effects.h"
#include "battle_memory_access.h"

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
void AnimationUpdateHealth(GraphicsInterface graphics, HardwareInterface hardware, bool attackersTurn)
{
    Rect_16 r = {0};
    uint16_t cur_hp = 0;
    uint16_t max_hp = 0;

    if (attackersTurn)
    {
        r = ENEMY_RESOURCE_FRAME;
        EntityId e_id = g_core.battleMode.enemyMonsterID;
        cur_hp = Int999GetCurrent(&g_core.creatures.hp[e_id]);
        max_hp = Int999GetMax(&g_core.creatures.hp[e_id]);
    }
    else
    {
        r = PLAYER_RESOURCE_FRAME;
        EntityId p_id = g_core.battleMode.playerMonsterID;
        cur_hp = Int999GetCurrent(&g_core.creatures.hp[p_id]);
        max_hp = Int999GetMax(&g_core.creatures.hp[p_id]);
    }


    uint16_t x = r.x + r.w - 8;
    const uint16_t y = r.y + (8 * 3);
    const uint16_t w = 1;
    const uint16_t h = RESOURCE_HEIGHT;


    const uint16_t bar_w = r.w - 16;
    const uint16_t dmg_w = ((float)cur_hp / (float)max_hp) * (float)bar_w;
    const uint16_t end_pos = x - (bar_w - dmg_w);

    while (true)
    {
        if (x <= end_pos)
            break;
        x -= 1;

        graphics.FillRect(x, y, w, h, 0xf00a);
        hardware.SleepMS(16);
    }
}

/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET
 *  MANA - RISE AND FALL
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationUpdateMana(GraphicsInterface graphics, HardwareInterface hardware)
{
    FrameBuffer f = {50, 100, 64, 80, 0xd6fa};
    Rect_16 r = {5, 20, 10, 10};

    Color c;
    c.color = 0x001f;

    while (true)
    {
        graphics.TestAnimation(f, r, c);
        hardware.SleepMS(16);

        r.h += 1;
        if (r.h > 60)
            break;
    }
}


/************************************************************************************************************
 *  TODO: NOT IMPLEMENTED YET *
 *  XP - RISE AND FALL
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationUpdateXP(GraphicsInterface graphics, HardwareInterface hardware)
{
    FrameBuffer f = {50, 100, 64, 80, 0xd6fa};
    Rect_16 r = {5, 20, 10, 10};
    Color c;
    c.color = 0x001f;

    while (true)
    {
        graphics.TestAnimation(f, r, c);
        hardware.SleepMS(16);

        r.h += 1;
        if (r.h > 60)
            break;
    }
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
        graphics.TestAnimation(f, r, c);
        hardware.SleepMS(16);

        r.h += 1;
        if (r.h > 60)
            break;
    }
}



/************************************************************************************************************
 *  BATTLE START animation
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationBattlerStart(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    MoveCenterToDown(graphics, hardware, r, r.h, 8);
}


/************************************************************************************************************
 *  DEATH animation
 ************************************************************************************************************/
SET_MEMORY(".battle")
void AnimationBattlerDie(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    MoveCenterToDown(graphics, hardware, r, r.h, 8);
}


/************************************************************************************************************
 *  Handles all battler animations for spells, items and skills
 ************************************************************************************************************/
SET_MEMORY(".battle")
void BattlerAnimationAttack(GraphicsInterface graphics, MemoryInterface memory, bool player)
{
    const ObjectsTypes move_type = g_core.battleMode.moveType;

    const ObjectType move_id = g_core.battleMode.moveID;

    if (move_type == ITEM)
        Flash_BattlerAttackAnimation(memory, move_id.ItemId, ITEM, player);
    else if (SKILL)
        Flash_BattlerAttackAnimation(memory, move_id.AbilityId, SKILL, player);
    else if (SPELL)
        Flash_BattlerAttackAnimation(memory, move_id.SpellId, SPELL, player);
}


SET_MEMORY(".battle")
void BattlerAnimationStruck(GraphicsInterface graphics, MemoryInterface memory, bool player)
{
    const ObjectsTypes move_type = g_core.battleMode.moveType;

    const ObjectType move_id = g_core.battleMode.moveID;

    if (move_type == ITEM)
        Flash_BattlerStruckAnimation(memory, move_id.ItemId, ITEM, player);
    else if (SKILL)
        Flash_BattlerStruckAnimation(memory, move_id.AbilityId, SKILL, player);
    else if (SPELL)
        Flash_BattlerStruckAnimation(memory, move_id.SpellId, SPELL, player);
}
