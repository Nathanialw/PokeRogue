//
// Created by nathanial on 6/10/26.
//

#include "types.h"
#include "lib_memory.h"

#include "map_effects.h"

SET_MEMORY(".map")
bool TIleStepOffCastleFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffDirtFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffMeadowFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffTundraFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFloorVolcanic(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWoodFloor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);

}

SET_MEMORY(".map")
bool TIleStepOffFluidAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidCrystal(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitMinor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSmall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSnake(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSpike(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitWide(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffRiverFrozen(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffBrickWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffCastleWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWallIce(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffStoneWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWoodWall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}
