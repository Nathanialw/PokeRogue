//
// Created by nathanial on 5/19/26.
//

#include "core_stats.h"
#include "lib_memory.h"

#include "core_ram.h"


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
    const uint16_t total_stats = stats.magic + stats.attack + stats.defence + stats.speed + (50 * level.value);

    Int999SetCurrent(xp, 0);
    Int999SetMax(xp, total_stats / 10);
}


/**********************************************************************************************************************/
/** Retrieves the xp value of a killed creature and adds it to the xp of the slaying creature
 *  handles level up
**********************************************************************************************************************/
SET_MEMORY(".core")
void GainXP(EntityId id, EntityId dead_id)
{
    Stats stats = g_core.creatures.stats[dead_id];
    uint8_t level = g_core.creatures.level[dead_id].value;
    uint16_t total_stats = stats.magic + stats.attack + stats.defence + stats.speed + (50 * level);
    uint16_t xp_value = total_stats / 20;

    IntMax999 xp = g_core.creatures.xp[id];
    uint16_t cur = Int999GetCurrent(&xp);
    uint16_t max = Int999GetMax(&xp);
    uint16_t new_xp = (cur + xp_value);
    if (new_xp < max)
    {
        Int999SetCurrent(&xp, (cur + xp_value));
    }
    else
    {
        g_core.creatures.level[id].value++;
        new_xp = new_xp - max;
        SetXPToLevel(id, &xp);
        Int999SetCurrent(&xp, new_xp);
    }

    g_core.creatures.xp[id] = xp;
}
