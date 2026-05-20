//
// Created by nathanial on 5/19/26.
//

#include "map_stats.h"
#include "types.h"
#include "lib_memory.h"

#include "core_memory_access.h"
#include "core_utils.h"

#include "map_memory_access.h"
#include "map_ram.h"


/**********************************************************************************************************************/
/** extracts growth values from bytes 4 bits each
**********************************************************************************************************************/
SET_MEMORY(".map")
static inline uint8_t GrowthAttack(uint16_t g) { return (g >> 12) & 0xF; }

SET_MEMORY(".map")
static inline uint8_t GrowthDefence(uint16_t g) { return (g >> 8) & 0xF; }

SET_MEMORY(".map")
static inline uint8_t GrowthMagic(uint16_t g) { return (g >> 4) & 0xF; }

SET_MEMORY(".map")
static inline uint8_t GrowthSpeed(uint16_t g) { return g & 0xF; }


SET_MEMORY(".map.rodata")
static const uint8_t growth_table[8] = {1, 2, 3, 4, 5, 6, 7, 8};


SET_MEMORY(".map.rodata")
static const char str_spawn_creature_type[] = "1";
SET_MEMORY(".map.rodata")
static const char str_spawn_creature_skills[] = "2";
SET_MEMORY(".map.rodata")
static const char str_spawn_creature_done[] = "3";

/**********************************************************************************************************************/
/** Returns the stats of a given creature type and level
**********************************************************************************************************************/
SET_MEMORY(".map")
void GetStats(HardwareInterface hardware, MemoryInterface memory, Stats *stats, Creature type, uint8_t level)
{
    memory.Print(str_spawn_creature_type);

    Flash_GetCreatureStatsRange(memory, &g_map.statsCache, type);
    Stats minStats = g_map.statsCache.min;
    Stats maxStats = g_map.statsCache.max;
    memory.Print(str_spawn_creature_skills);

    uint8_t growth = Flash_GetStatGrowth(memory, type);

    memory.Print(str_spawn_creature_done);
    uint8_t a = growth_table[GrowthAttack(growth)];
    uint8_t d = growth_table[GrowthDefence(growth)];
    uint8_t m = growth_table[GrowthMagic(growth)];
    uint8_t s = growth_table[GrowthSpeed(growth)];

    memory.Print(str_spawn_creature_type);

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
SET_MEMORY(".map")
IntMax999 GetHP(Creature type, uint8_t level)
{
    IntMax999 k = {0};
    Int999SetCurrent(&k, level * 20);
    Int999SetMax(&k, level * 20);
    return k;
}

/**********************************************************************************************************************/
/**Returns the current and max mp of a creature by type and level
 *  TODO get the values from the DB values and calc with growth
**********************************************************************************************************************/
SET_MEMORY(".map")
IntMax999 GetMP(Creature type, uint8_t level)
{
    IntMax999 k = {0};
    Int999SetCurrent(&k, level * 10);
    Int999SetMax(&k, level * 10);
    return k;
}
