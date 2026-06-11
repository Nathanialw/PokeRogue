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
void SetXPToLevel(EntityId id, IntMax999* xp)
{
    const Stats stats = g_core.creatures.stats[id];
    const Int99 level = g_core.creatures.level[id];
    const uint16_t total_stats = (stats.magic + stats.attack + stats.defence + stats.speed + (50 * level.value)) >> 2;

    Int999SetCurrent(xp, 0);
    Int999SetMax(xp, total_stats);
}


/**********************************************************************************************************************/
/** handles xp gain and  level up
**********************************************************************************************************************/
SET_MEMORY(".core")
void GainXP(EntityId creature_id, uint16_t xp_value)
{
    IntMax999 xp = g_core.creatures.xp[creature_id];
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
    uint16_t total_stats = stats.magic + stats.attack + stats.defence + stats.speed + (50 * level);
    uint16_t xp_value = total_stats / 20;

    GainXP(id, xp_value);
}


/**********************************************************************************************************************/
/** extracts growth values from bytes 4 bits each
**********************************************************************************************************************/
SET_MEMORY(".core")
static inline uint8_t GrowthAttack(uint16_t g) { return (g >> 12) & 0xF; }

SET_MEMORY(".core")
static inline uint8_t GrowthDefence(uint16_t g) { return (g >> 8) & 0xF; }

SET_MEMORY(".core")
static inline uint8_t GrowthMagic(uint16_t g) { return (g >> 4) & 0xF; }

SET_MEMORY(".core")
static inline uint8_t GrowthSpeed(uint16_t g) { return g & 0xF; }


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

    uint8_t growth = Flash_GetStatGrowth(memory, type);

    uint8_t a = growth_table[GrowthAttack(growth)];
    uint8_t d = growth_table[GrowthDefence(growth)];
    uint8_t m = growth_table[GrowthMagic(growth)];
    uint8_t s = growth_table[GrowthSpeed(growth)];

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
 *  TODO get the values from the DB values and calc with growth
**********************************************************************************************************************/
SET_MEMORY(".core")
IntMax999 GetHP(Creature type, uint8_t level)
{
    IntMax999 k = {0};
    Int999SetCurrent(&k, ((level + 1) * 20));
    Int999SetMax(&k, ((level + 1) * 20));\
    return k;
}

/**********************************************************************************************************************/
/**Returns the current and max mp of a creature by type and level
 *  TODO get the values from the DB values and calc with growth
**********************************************************************************************************************/
SET_MEMORY(".core")
IntMax999 GetMP(Creature type, uint8_t level)
{
    IntMax999 k = {0};
    Int999SetCurrent(&k, (level + 1) * 10);
    Int999SetMax(&k, (level + 1) * 10);
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
