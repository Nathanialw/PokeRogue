//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"


EntityId PickItem(EntityId id);
EntityId CaptureMonster(EntityId id);

void GetEntityTypes(MemoryInterface memory, uint8_t* typeIDs, const uint8_t* e_ids, ObjectsTypes type, uint8_t n, uint8_t offset);
ItemTypes GetItemType(EntityId id);
Object GetObjectType(EntityId id);
Creature GetCreatureType(EntityId id);

void DestroyCreature(EntityId i);
void DestroyItem(EntityId id);
void DestroyObject(EntityId id);
void DestroyTrainer(EntityId id);
EntityId SpawnEntity(HardwareInterface hardware, MemoryInterface memory, ObjectsTypes type, uint8_t t, uint8_t x, uint8_t y, uint8_t l);

