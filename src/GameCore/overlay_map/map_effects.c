//
// Created by nathanial on 5/19/26.
//

#include "map_effects.h"
#include "types.h"

#include "core_effects.h"
#include "core_entities.h"
#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "map.h"
#include "map_camera.h"
#include "map_entities.h"
#include "map_player.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_DOWN);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_LATERAL);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool RevealMap()
{
    SetMapFog(0xFF);
    return true;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Reposition(HardwareInterface hardware, EntityId e_id)
{
    Position random_tile_pos = GetRandomMapTile(hardware, TRAINER, true);
    g_core.trainers.position[GetPlayerID()] = random_tile_pos;
    SetCameraPlayer();
    return true;
}


/**********************************************************************************************************************/
/** Space is empty, free to move into
**********************************************************************************************************************/
SET_MEMORY(".map")
bool NoInteraction(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

/**********************************************************************************************************************/
/** Space is blocked, no movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Wall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    // check current tile, cancel movement

    if (id == g_core.player.id)
    {
        g_core.player.scroll.x = 0;
        g_core.player.scroll.y = 0;
    }


    return false;
}

/**********************************************************************************************************************/
/** Space is blocked, no movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Pit(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    // check current tile, cancel movement

    if (id == g_core.player.id)
    {
        g_core.player.scroll.x = 0;
        g_core.player.scroll.y = 0;
    }


    return false;
}


/**********************************************************************************************************************/
/** Space is water
 *  TODO: add drift mechanics
 *  TODO: add drowning mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CollisionFluidTile(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    if (type == TRAINER)
    {
        if (g_core.creatures.status.waterWalk[id])
            return true;


        EntityId creature_id = g_core.trainers.partyID[id][0];
        DoDamage(creature_id, 3);
        bool dead = CheckCreatureDead(creature_id);
        if (dead)
        {
            DestroyPartyCreature(creature_id);
            if (id == GetPlayerID())
            {
                if (CheckGameLost())
                    g_core.state.overlay = OVERLAY_TITLE_SCREEN;
            }
        }
    }
    if (type == CREATURE)
    {
    }

    // check for damage and position drift
    return true;
}
