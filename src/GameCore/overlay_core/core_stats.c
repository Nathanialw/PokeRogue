//
// Created by nathanial on 5/19/26.
//

#include "core_stats.h"

#include "core_memory_access.h"
#include "lib_memory.h"

#include "core_ram.h"
#include "core_utils.h"


/**********************************************************************************************************************/
/** Takes in an entity id
 *  calculate the xp required for the next level
 *  Saves it into the Max value of the entity xp array value
 *  Sets current x to 0
**********************************************************************************************************************/
SET_MEMORY(".core")
void SetXPToLevel(EntityId id, uint_max999* xp)
{
    const Stats stats = g_core.creatures.stats[id];
    const uint99 level = g_core.creatures.level[id];
    const uint16_t total_stats = (stats.attack + stats.defence + stats.magic + stats.speed + (20 * level.value)) >> 1;

    Int999SetCurrent(xp, 0);
    Int999SetMax(xp, total_stats);
}


/**********************************************************************************************************************/
/** handles xp gain and  level up
**********************************************************************************************************************/
SET_MEMORY(".core")
void GainXP(EntityId creature_id, uint16_t xp_value)
{
    uint_max999 xp = g_core.creatures.xp[creature_id];
    uint16_t cur = Int999GetCurrent(&xp);
    g_core.battleMode.battle_xp_cache = cur;
    uint16_t max = Int999GetMax(&xp);
    uint16_t new_xp = (cur + xp_value);
    if (new_xp < max)
    {
        Int999SetCurrent(&xp, (cur + xp_value));
    }
    else
    {
        g_core.creatures.level[creature_id].value++;
        new_xp = new_xp - max;
        SetXPToLevel(creature_id, &xp);
        Int999SetCurrent(&xp, new_xp);
        g_core.battleMode.battle_xp_max_cache = Int999GetMax(&xp);
    }

    g_core.creatures.xp[creature_id] = xp;
}


/**********************************************************************************************************************/
/** Retrieves the xp value of a killed creature and calls Gain XP that handles xp gain and level up
**********************************************************************************************************************/
SET_MEMORY(".core")
void GainXPFromKill(EntityId id, EntityId dead_id)
{
    Stats stats = g_core.creatures.stats[dead_id];
    uint8_t level = g_core.creatures.level[dead_id].value;
    uint16_t total_stats = stats.magic + stats.attack + stats.defence + stats.speed + (20 * level);
    uint16_t xp_value = total_stats / 5;

    GainXP(id, xp_value);
}


/**********************************************************************************************************************/
/** extracts growth values from bytes 4 bits each
**********************************************************************************************************************/
SET_MEMORY(".core.rodata")
static const uint8_t growth_table[8] = {1, 2, 3, 4, 5, 6, 7, 8};


/**********************************************************************************************************************/
/** Returns the stats of a given creature type and level
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetStats(HardwareInterface hardware, MemoryInterface memory, Stats* stats, Creature type, uint8_t level)
{
    Flash_GetCreatureStatsRange(memory, &g_core.statsCache, type);
    Stats minStats = g_core.statsCache.min;
    Stats maxStats = g_core.statsCache.max;

    uint8_t a = growth_table[g_core.statsCache.growth.attack];
    uint8_t d = growth_table[g_core.statsCache.growth.defence];
    uint8_t m = growth_table[g_core.statsCache.growth.magic];
    uint8_t s = growth_table[g_core.statsCache.growth.speed];

    stats->attack = hardware.GetRandom_uint8_t(minStats.attack, maxStats.attack);
    stats->defence = hardware.GetRandom_uint8_t(minStats.defence, maxStats.defence);
    stats->magic = hardware.GetRandom_uint8_t(minStats.magic, maxStats.magic);
    stats->speed = hardware.GetRandom_uint8_t(minStats.speed, maxStats.speed);

    stats->attack += a * (level / 4);
    stats->defence += d * (level / 4);
    stats->magic += m * (level / 4);
    stats->speed += s * (level / 4);
}


/**********************************************************************************************************************/
/**Returns the current and max hp of a creature by type and level
 *  TODO add random variance
**********************************************************************************************************************/
SET_MEMORY(".core")
uint_max999 GetHP(Creature type, uint8_t level)
{
    uint_max999 k = {0};
    uint16_t hp = g_core.statsCache.hp_base + ((level + 1) * g_core.statsCache.hp_growth);
    Int999SetCurrent(&k, hp);
    Int999SetMax(&k, hp);
    return k;
}

/**********************************************************************************************************************/
/**Returns the current and max mp of a creature by type and level
 *  TODO add random variance
**********************************************************************************************************************/
SET_MEMORY(".core")
uint_max999 GetMP(Creature type, uint8_t level)
{
    uint_max999 k = {0};
    uint16_t mp = g_core.statsCache.mp_base + ((level + 1) * g_core.statsCache.mp_growth);
    Int999SetCurrent(&k, mp);
    Int999SetMax(&k, mp);
    return k;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
void SetDefaultSkills(MemoryInterface memory, EntityId id, Type type)
{
    uint8_t idx = 0;
    while (idx < MAX_ABILITIES)
    {
        g_core.creatures.attacks[id][idx] = NO_ABILITY;
        idx++;
    }

    CreatureSkillLearnLevels skills = {0};
    Flash_GetSkill(memory, &skills, type, idx);

    for (uint8_t i = 0; i < MAX_ABILITIES; i++)
    {
        if (skills.c[i].level > 0)
        {
            g_core.creatures.attacks[id][i] = skills.c[i].skillID;
        }
    }
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetStatusEffect(uint8_t* status_effect, EntityId creature_id)
{
    uint8_t index = creature_id % 2;
    index += creature_id / 2;
    uint8_t value = status_effect[index];
    return value;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t SetStatusEffect(uint8_t* status_effect, EntityId creature_id, uint8_t value)
{
    if (value > MAX_STATUS_VALUE) value = MAX_STATUS_VALUE;
    uint8_t index = creature_id % 2;
    index += creature_id / 2;
    status_effect[index] = value;
    return value;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t IncrementStatusEffect(uint8_t status_value, EntityId creature_id)
{
    if (status_value < (MAX_STATUS_VALUE - 1))
        status_value++;

    return status_value;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t DecrementStatusEffect(uint8_t status_value, EntityId creature_id)
{
    if (status_value > 0)
        status_value--;

    return status_value;
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
SET_MEMORY(".core")
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

