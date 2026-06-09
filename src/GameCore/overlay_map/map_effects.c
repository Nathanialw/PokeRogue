//
// Created by nathanial on 5/19/26.
//

#include "map_effects.h"
#include "types.h"

#include "core_effects.h"
#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "map.h"
#include "map_camera.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(MAP_LEVEL_DOWN);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(MAP_LEVEL_UP);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(MAP_LEVEL_LATERAL);
    return true;
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
