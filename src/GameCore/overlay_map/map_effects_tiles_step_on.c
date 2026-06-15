//
// Created by nathanial on 6/10/26.
//


#include "data_constants_effects.inc"
#include "types.h"
#include "lib_memory.h"

#include "map_effects.h"

SET_MEMORY(".map")
bool TIleStepOnCastleFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnDirtFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnMeadowFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnTundraFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFloorVolcanic(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWoodFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);

}

SET_MEMORY(".map")
bool TIleStepOnFluidAcid(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidCrystal(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidLava(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnFluidWater(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitAcid(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitLava(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitMinor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSmall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSnake(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitSpike(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitWater(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnPitWide(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Pit(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnRiverFrozen(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnBrickWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnCastleWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWallIce(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnStoneWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOnWoodWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return Wall(id, type, x, y);
}
