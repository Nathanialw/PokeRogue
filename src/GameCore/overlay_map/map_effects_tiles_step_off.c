//
// Created by nathanial on 6/10/26.
//

#include "types.h"
#include "lib_memory.h"

#include "map_effects.h"

SET_MEMORY(".map")
bool TIleStepOffCastleFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffDirtFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffMeadowFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffTundraFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFloorVolcanic(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWoodFloor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidAcid(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidCrystal(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return CollisionFluidTile(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidLava(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffFluidWater(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitAcid(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitLava(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitMinor(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSmall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSnake(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitSpike(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitWater(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffPitWide(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    uint8_t chance = hardware.GetRandom_uint8_t(1, 100);
    if (chance <= 30)
    {
        return Wall(id, type, x, y);
    }
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffRiverFrozen(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffBrickWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffCastleWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWallIce(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffStoneWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}

SET_MEMORY(".map")
bool TIleStepOffWoodWall(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return NoInteraction(id, type, x, y);
}


