//
// Created by nathanial on 5/19/26.
//

#include "map_effects.h"

#include "lib_decl.h"
#include "map.h"
#include "types.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(hardware, memory, MAP_LEVEL_DOWN);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(hardware, memory, MAP_LEVEL_UP);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    GoNextLevel(hardware, memory, MAP_LEVEL_LATERAL);
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
