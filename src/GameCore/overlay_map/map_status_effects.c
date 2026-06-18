//
// Created by nathanial on 4/11/26.
//

#include "map_status_effects.h"

#include "constants.h"
#include "lib_memory.h"

#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"


typedef uint8_t (*TurnEffect)(HardwareInterface hardware, uint8_t power, EntityId id);

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t UpdateStatus(HardwareInterface hardware, uint8_t n)
{
    if (n == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(0, 20);
    if (chance <= n) n--;
    return n;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t HoveringEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t WaterWalkEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t WaterBreathingEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t RepelEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t InvisibilityEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t WallWalkingEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t FireEatingEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t LineOfSightEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t ParalyzedEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
        g_core.creatures.debuffs[id].paralyzed = DecrementStatusEffect(g_core.creatures.debuffs[id].paralyzed, id);
    return g_core.creatures.debuffs[id].paralyzed;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t SleepEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
        g_core.creatures.debuffs[id].sleep = DecrementStatusEffect(g_core.creatures.debuffs[id].sleep, id);
    return g_core.creatures.debuffs[id].sleep;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t PoisonEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        Int999ApplyValue(hardware, &g_core.creatures.hp[id], -power);
        g_core.creatures.debuffs[id].poison = DecrementStatusEffect(g_core.creatures.debuffs[id].poison, id);
    }
    return g_core.creatures.debuffs[id].poison;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t FrozenEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        g_core.creatures.debuffs[id].frozen = DecrementStatusEffect(g_core.creatures.debuffs[id].frozen, id);
    }
    return g_core.creatures.debuffs[id].frozen;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t DiseaseEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        Int999ApplyValue(hardware, &g_core.creatures.hp[id], -power);
        g_core.creatures.debuffs[id].disease = DecrementStatusEffect(g_core.creatures.debuffs[id].disease, id);
    }
    return g_core.creatures.debuffs[id].disease;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t CurseEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        Int999ApplyValue(hardware, &g_core.creatures.hp[id], -power);
        g_core.creatures.debuffs[id].curse = DecrementStatusEffect(g_core.creatures.debuffs[id].curse, id);
    }
    return g_core.creatures.debuffs[id].curse;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t HastedEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        Int999ApplyValue(hardware, &g_core.creatures.hp[id], -power);
        g_core.creatures.buffs[id].hasted = DecrementStatusEffect(g_core.creatures.buffs[id].hasted, id);
    }
    return g_core.creatures.buffs[id].hasted;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t FearEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
        g_core.creatures.debuffs[id].fear = DecrementStatusEffect(g_core.creatures.debuffs[id].fear, id);
    return g_core.creatures.debuffs[id].fear;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t BurnedEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
    {
        Int999ApplyValue(hardware, &g_core.creatures.hp[id], -power);
        g_core.creatures.debuffs[id].burned = DecrementStatusEffect(g_core.creatures.debuffs[id].burned, id);
    }
    return g_core.creatures.debuffs[id].burned;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t LightEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    return 0;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t SlowedEffect(HardwareInterface hardware, uint8_t power, EntityId id)
{
    if (power == 0) return 0;
    uint8_t chance = hardware.GetRandom_uint8_t(10, 100);
    if (chance <= 25)
        g_core.creatures.debuffs[id].slowed = DecrementStatusEffect(g_core.creatures.debuffs[id].slowed, id);
    return g_core.creatures.debuffs[id].slowed;
}

//
// /**********************************************************************************************************************
// *
// **********************************************************************************************************************/
SET_MEMORY(".map")
void GetCreatureStatusEffectStateBuffs(uint8_t* buff_values, EntityId creature_id)
{
    for (uint8_t i = 0; i < MAX_MAX_STATUS_EFFECTS; i++)
        buff_values[i] = 0;

    buff_values[0] = g_core.creatures.buffs[creature_id].hasted;
    buff_values[1] = g_core.creatures.buffs[creature_id].fire_eating;
}

//
// /**********************************************************************************************************************
// *
// **********************************************************************************************************************/
SET_MEMORY(".map")
void GetCreatureStatusEffectStateDebuffs(uint8_t* buff_values, EntityId creature_id)
{
    for (uint8_t i = 0; i < MAX_MAX_STATUS_EFFECTS; i++)
        buff_values[i] = 0;

    buff_values[0] = g_core.creatures.debuffs[creature_id].paralyzed;
    buff_values[1] = g_core.creatures.debuffs[creature_id].sleep;
    buff_values[2] = g_core.creatures.debuffs[creature_id].poison;
    buff_values[3] = g_core.creatures.debuffs[creature_id].frozen;
    buff_values[4] = g_core.creatures.debuffs[creature_id].disease;
    buff_values[5] = g_core.creatures.debuffs[creature_id].curse;
    buff_values[6] = g_core.creatures.debuffs[creature_id].fear;
    buff_values[8] = g_core.creatures.debuffs[creature_id].burned;
    buff_values[9] = g_core.creatures.debuffs[creature_id].slowed;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateStatusEffectCreatures(HardwareInterface hardware)
{
    for (uint8_t i = 0; i < MAX_ENTITY_TRAINER_COUNT; i++)
    {
        g_core.creatures.debuffs[i].paralyzed = ParalyzedEffect(hardware, g_core.creatures.debuffs[i].paralyzed, i);
        g_core.creatures.debuffs[i].sleep = SleepEffect(hardware, g_core.creatures.debuffs[i].sleep, i);
        g_core.creatures.debuffs[i].poison = PoisonEffect(hardware, g_core.creatures.debuffs[i].poison, i);
        g_core.creatures.debuffs[i].frozen = FrozenEffect(hardware, g_core.creatures.debuffs[i].frozen, i);
        g_core.creatures.debuffs[i].disease = DiseaseEffect(hardware, g_core.creatures.debuffs[i].disease, i);
        g_core.creatures.debuffs[i].curse = CurseEffect(hardware, g_core.creatures.debuffs[i].curse, i);
        g_core.creatures.debuffs[i].fear = FearEffect(hardware, g_core.creatures.debuffs[i].fear, i);
        g_core.creatures.debuffs[i].burned = BurnedEffect(hardware, g_core.creatures.debuffs[i].burned, i);
        g_core.creatures.debuffs[i].slowed = SlowedEffect(hardware, g_core.creatures.debuffs[i].slowed, i);
    }

    for (uint8_t i = 0; i < MAX_ENTITY_TRAINER_COUNT; i++)
    {
        g_core.creatures.buffs[i].fire_eating = FireEatingEffect(hardware, g_core.creatures.buffs[i].fire_eating, i);
        g_core.creatures.buffs[i].hasted = HastedEffect(hardware, g_core.creatures.buffs[i].hasted, i);
    }
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateStatusEffectTrainers(HardwareInterface hardware)
{
    for (uint8_t i = 0; i < MAX_ENTITY_TRAINER_COUNT; i++)
    {
        g_core.trainers.buffs[i].hovering = HoveringEffect(hardware, g_core.trainers.buffs[i].hovering, i);
        g_core.trainers.buffs[i].water_walk = WaterWalkEffect(hardware, g_core.trainers.buffs[i].water_walk, i);
        g_core.trainers.buffs[i].water_breathing = WaterBreathingEffect(hardware, g_core.trainers.buffs[i].water_breathing, i);
        g_core.trainers.buffs[i].repel = RepelEffect(hardware, g_core.trainers.buffs[i].repel, i);
        g_core.trainers.buffs[i].invisibility = InvisibilityEffect(hardware, g_core.trainers.buffs[i].invisibility, i);
        g_core.trainers.buffs[i].wall_walking = WallWalkingEffect(hardware, g_core.trainers.buffs[i].wall_walking, i);
        g_core.trainers.buffs[i].line_of_sight = LineOfSightEffect(hardware, g_core.trainers.buffs[i].line_of_sight, i);
        g_core.trainers.buffs[i].light = LightEffect(hardware, g_core.trainers.buffs[i].light, i);
    }
}


SET_MEMORY(".map")
void UpdateObjectStatusEffects(HardwareInterface hardware)
{
    UpdateStatusEffectCreatures(hardware);
    UpdateStatusEffectTrainers(hardware);
}
