//
// Created by nathanial on 5/19/26.
//

#include "map_player.h"
#include "lib_memory.h"

#include "core_ram.h"

#include "map.h"
#include "map_actions.h"
#include "map_entities.h"
#include "map_utils.h"


/*******************************************************************************************************************
*
**********************************************************************************************************************/

EntityId PlayerCaptureMonster(EntityId id);
EntityId PlayerPickItem(EntityId id);


/*******************************************************************************************************************
** Initializes player data
 *  Creates default creatures for party
 *  Creates default items for party
 *  Places default spells in spellbook
 *  Sets player to a random empty cell on the map
 *  sets sight rango around player
**********************************************************************************************************************/
SET_MEMORY(".map")
void InitPlayer(HardwareInterface hardware, MemoryInterface memory)
{
    g_core.player.currentBagSize = DEFAULT_BAG_SIZE;
    g_core.player.currentSpellbookSize = DEFAULT_SPELLBOOK_SIZE;

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        g_core.player.partyID[i] = NO_ENTITY;

    for (uint8_t i = 0; i < MAX_BAG_SIZE; ++i)
        g_core.player.itemID[i] = NO_ENTITY;

    for (uint8_t i = 0; i < MAX_SPELLBOOK_SIZE; ++i)
        g_core.player.spellID[i] = NO_SPELL;

    g_core.player.spellID[0] = HEAL;
    g_core.player.spellID[1] = DESCEND;

    Position pos = FindOpenMapLocation(hardware, CREATURE);
    uint8_t x = pos.x;
    uint8_t y = pos.y;

    g_core.player.id = SpawnEntity(hardware, memory, CREATURE, HUMAN, x, y, 0);

    g_core.creatures.speed[g_core.player.id].max = 99;
    g_core.creatures.speed[g_core.player.id].current = 15;

    EntityId e_id;
    e_id = SpawnEntity(hardware, memory, CREATURE, LAMIA, x, y, 5);

    PlayerCaptureMonster(e_id);

    e_id = SpawnEntity(hardware, memory, ITEM, HEALTH_POTION, x, y, 0);

    PlayerPickItem(e_id);


    for (uint16_t j = y - 5; j < y + 5; ++j)
        for (uint16_t i = x - 5; i < x + 5; ++i)
            SetFog(i, j, false);

}

/*******************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
EntityId CachePlayerCreatureData(HardwareInterface hardware)
{
    EntityId creature_idx = 0;
    //set player to beginning of the array
    if (GetPlayerID() != 0)
    {
    }
    creature_idx++;

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
    {
        if (g_core.player.partyID[i] != NO_ENTITY && g_core.player.partyID[i] > creature_idx)
        {
            CopyCreature(hardware, g_core.player.partyID[i], creature_idx);
            g_core.player.partyID[i] = creature_idx;
            creature_idx++;
        }
    }

    //set player creatures to beginning of the array
    return creature_idx;
}

SET_MEMORY(".map")
EntityId CachePlayerItemData()
{
    EntityId item_idx = 0;
    EntityId sorted_indexes[MAX_BAG_SIZE];
    SortEntityArray(sorted_indexes, g_core.player.itemID, MAX_BAG_SIZE);

    for (uint8_t i = 0; i < MAX_BAG_SIZE; ++i)
    {
        if (sorted_indexes[i] != NO_ENTITY && sorted_indexes[i] != item_idx)
        {
            CopyItem(g_core.player.itemID[i], item_idx);
            g_core.player.itemID[i] = item_idx;
            item_idx++;
        }
    }

    //set player items to beginning of the array
    return item_idx;
}



/*******************************************************************************************************************
** Returns the player position as map cell index
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetPlayerPosition(void)
{
    return GetEntityPosition(CREATURE, g_core.player.id);
}

/*******************************************************************************************************************
**Sets player Position value to NewPosition value
 * stores the player delta value into the scroll value
 * clears the player delta value
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdatePlayerPosition(void)
{
    Position pos = GetPlayerPosition();
    uint8_t x = pos.x + g_core.player.d.x;
    uint8_t y = pos.y + g_core.player.d.y;
    QueueObjectMovePosition(g_core.player.id, x, y);
    g_core.player.scroll.x = g_core.player.d.x;
    g_core.player.scroll.y = g_core.player.d.y;
    g_core.player.d.x = 0;
    g_core.player.d.y = 0;
}

/*******************************************************************************************************************
**Set the player movement delta
 * -1 or 0 or 1 for single cell movement
**********************************************************************************************************************/
SET_MEMORY(".map")
Delta SetPlayerDelta(Delta newDelta)
{
    g_core.player.d = newDelta;
    return g_core.player.d;
}





/*******************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
void PlacePlayerOnMap(HardwareInterface hardware)
{
    Position pos = FindOpenMapLocation(hardware, CREATURE);
    g_core.creatures.position[g_core.player.id].x = pos.x;
    g_core.creatures.position[g_core.player.id].y = pos.y;
}

/*******************************************************************************************************************
*  interact with item in player's cell
*  interact with object in player's cell
**********************************************************************************************************************/
SET_MEMORY(".map")
void PlayerInteractItemInCell()
{
    Position pos = GetPlayerPosition();
    EntityId item_id = CheckTileForEntity(ITEM, g_core.player.id, pos);
    PlayerPickItem(item_id);
}

SET_MEMORY(".map")
void PlayerInteractObjectInCell(MemoryInterface memory, HardwareInterface hardware)
{
    Position pos = GetPlayerPosition();
    EntityId object_id = CheckTileForEntity(OBJECT, g_core.player.id, pos);
    InteractObject(memory, hardware, object_id, g_core.player.id);
}
