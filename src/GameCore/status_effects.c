//
// Created by nathanial on 4/11/26.
//

#include <stdint.h>

#include "status_effects.h"
#include "constants.h"
#include "memory_ram.h"


typedef uint8_t (*TurnEffect)(uint8_t power, EntityId id);

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t UpdateStatus(uint8_t n)
{
    if (n == 0) return 0;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= n) n--;
    return n;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t HoveringEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t WaterWalkEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t WaterBreathingEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t RepelEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t InvisibilityEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t WallWalkingEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t FireEatingEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t LineOfSightEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t ParalyzedEffect(uint8_t power, EntityId id)
{
    g_run.creatures.speed[id].negativeEffect = false;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= 10)
        g_run.creatures.speed[id].negativeEffect = true;
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t SleepEffect(uint8_t power, EntityId id)
{
    g_run.creatures.speed[id].negativeEffect = false;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= 10)
        g_run.creatures.speed[id].negativeEffect = true;
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t PoisonEffect(uint8_t power, EntityId id)
{
    Int999ApplyValue(&g_run.creatures.hp[id], -power);
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t FrozenEffect(uint8_t power, EntityId id)
{
    g_run.creatures.speed[id].negativeEffect = false;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= 10)
        g_run.creatures.speed[id].negativeEffect = true;
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t DiseaseEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t CurseEffect(uint8_t power, EntityId id)
{
    Int999ApplyValue(&g_run.creatures.hp[id], -power);
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t HastedEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t FearEffect(uint8_t power, EntityId id)
{
    g_run.creatures.speed[id].negativeEffect = false;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= 10)
        g_run.creatures.speed[id].negativeEffect = true;
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t BurnedEffect(uint8_t power, EntityId id)
{
    Int999ApplyValue(&g_run.creatures.hp[id], -power);
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t LightEffect(uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
uint8_t SlowedEffect(uint8_t power, EntityId id)
{
    g_run.creatures.speed[id].negativeEffect = false;
    uint8_t chance = GetRandom_uint8_t(10, 100);
    if (chance <= 10)
        g_run.creatures.speed[id].negativeEffect = true;
    return 0;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
static inline void UpdateStatusEffect(uint8_t* status_effect, TurnEffect turnEffect)
{
    for (uint8_t i = 0; i < ENTITY_COUNT / 2; ++i)
    {
        if (status_effect[i] == 0) continue;
        uint8_t lower_unit = GetBottomByte(status_effect[i]);
        if (lower_unit > 0)
            turnEffect(lower_unit, i * 2);
        lower_unit = UpdateStatus(lower_unit);

        uint8_t upper_unit = GetTopByte(status_effect[i]);
        if (upper_unit > 0)
            turnEffect(upper_unit, (i * 2) + 1);
        upper_unit = UpdateStatus(upper_unit);

        //save updated effect
        status_effect[i] = lower_unit | (upper_unit << 8);
    }
}


void UpdateObjectStatusEffects()
{
    UpdateStatusEffect(g_run.creatures.status.hovering, HoveringEffect);
    UpdateStatusEffect(g_run.creatures.status.waterWalk, WaterWalkEffect);
    UpdateStatusEffect(g_run.creatures.status.waterBreathing, WaterBreathingEffect);
    UpdateStatusEffect(g_run.creatures.status.repel, RepelEffect);
    UpdateStatusEffect(g_run.creatures.status.invisibility, InvisibilityEffect);
    UpdateStatusEffect(g_run.creatures.status.wallWalking, WallWalkingEffect);
    UpdateStatusEffect(g_run.creatures.status.fireEating, FireEatingEffect);
    UpdateStatusEffect(g_run.creatures.status.lineOfSight, LineOfSightEffect);
    UpdateStatusEffect(g_run.creatures.status.paralyzed, ParalyzedEffect);
    UpdateStatusEffect(g_run.creatures.status.sleep, SleepEffect);
    UpdateStatusEffect(g_run.creatures.status.poison, PoisonEffect);
    UpdateStatusEffect(g_run.creatures.status.frozen, FrozenEffect);
    UpdateStatusEffect(g_run.creatures.status.disease, DiseaseEffect);
    UpdateStatusEffect(g_run.creatures.status.curse, CurseEffect);
    UpdateStatusEffect(g_run.creatures.status.hasted, HastedEffect);
    UpdateStatusEffect(g_run.creatures.status.fear, FearEffect);
    UpdateStatusEffect(g_run.creatures.status.burned, BurnedEffect);
    UpdateStatusEffect(g_run.creatures.status.light, LightEffect);
    UpdateStatusEffect(g_run.creatures.status.slowed, SlowedEffect);
}
