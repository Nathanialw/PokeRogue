//
// Created by nathanial on 6/10/26.
//


#include "types.h"
#include "lib_memory.h"

#include "map_effects.h"

SET_MEMORY(".map")
bool TIleStepOnCastleFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnDirtFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnMeadowFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnTundraFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFloorVolcanic(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWoodFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);

}

SET_MEMORY(".map")
bool TIleStepOnFluidAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidCrystal(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitMinor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSmall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSnake(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSpike(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitWide(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnRiverFrozen(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnBrickWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnCastleWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWallIce(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnStoneWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWoodWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}
