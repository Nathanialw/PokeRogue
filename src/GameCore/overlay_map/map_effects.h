//
// Created by nathanial on 5/19/26.
//

#pragma once

#include "types.h"


ActionOutcome MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
ActionOutcome MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
ActionOutcome MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
bool RevealMap();
bool Reposition(HardwareInterface hardware, EntityId e_id);
bool SetTilse(Position position, MapTile type);
bool SetSurroundingTils(Position position, MapTile type);
ActionOutcome DamageCreature(CreatureID entity_id, uint8_t damage, ObjectsTypes entity_type);

//tiles
bool CollisionFluidTile(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);;
bool Pit(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Wall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool NoInteraction(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
