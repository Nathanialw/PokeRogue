//
// Created by nathanial on 5/19/26.
//

#include "map_player.h"
#include "lib_memory.h"

#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"

#include "map_actions.h"
#include "map_entities.h"


/*******************************************************************************************************************
*
**********************************************************************************************************************/

/*******************************************************************************************************************
** Returns the player position as map cell index
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetPlayerPosition(void)
{
    return GetEntityPosition(TRAINER, g_core.player.id);
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
    EntityId p_ID = GetPlayerID();
    InteractObject(memory, hardware, object_id, g_core.trainers.partyID[p_ID][0]);
}


SET_MEMORY(".map")
bool CheckGameLost()
{
    EntityId player_id = GetPlayerID();
    if (g_core.trainers.partyID[player_id][1] == NO_ENTITY) return true;

    for (uint8_t i = 0; i < MAX_PARTY_SIZE - 1; i++)
    {
        EntityId creature_id = g_core.trainers.partyID[player_id][i - 1];
        g_core.trainers.partyID[player_id][i] = creature_id;
    }
    return false;
}


void ApplyPassiveBuff(EntityId item_id)
{
    switch (item_id)
    {
    case BAG_POUCH:
        {
            break;
        }
    case BAG_SACK:
        {
            break;
        }
    case BAG_BACKPACK:
        {
            break;
        }

    case EARMUFFS:
        {
            break;
        }
    case MIRROR:
        {
            break;
        }
    case WISDOM_CROWN:
        {
            break;
        }
    default:
        {
            break;
        }
    }
}

void UpdatePlayerVariables()
{
    for (uint8_t i = 0; i < MAX_BAG_SIZE; i++)
    {
        EntityId item_id = g_core.trainers.itemID[g_core.player.id][i];
        if (item_id == NO_ENTITY)
            continue;

        ApplyPassiveBuff(item_id);
    }
}
