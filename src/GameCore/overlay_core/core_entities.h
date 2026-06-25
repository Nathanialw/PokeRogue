//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"


bool PickItem(EntityId trainer_id, EntityId item_id);
EntityId CaptureMonster(EntityId id);

void GetEntityTypes(MemoryInterface memory, uint8_t* typeIDs, const uint8_t* e_ids, ObjectsTypes type, uint8_t n, uint8_t offset);
ItemTypes GetItemType(EntityId id);
Object GetObjectType(EntityId id);
Creature GetCreatureType(EntityId id);

void DestroyCreature(EntityId i);
void DestroyItem(EntityId id);
void DestroyObject(EntityId id);
void DestroyTrainer(EntityId id);
void DestroyEnvironmentObject(EntityId id);
EntityId DestroyPartyCreature(EntityId trainer_id, EntityId creature_id);


EntityId SpawnEntity(HardwareInterface hardware, MemoryInterface memory, ObjectsTypes type, uint8_t t, uint8_t x, uint8_t y, uint8_t l);
bool AddCreatureToParty(EntityId trainer_id, EntityId creatureid);
bool DeleteCreatureFromParty(EntityId trainer_id, EntityId creature_id);
EntityId GetNextPartyCreature(EntityId trainer_id);

Stats GetCreatureStats(EntityId id);
Attributes GetCreatureAttributes(EntityId id);
Resists GetCreatureResists(EntityId id);
Absorb GetCreatureAbsorb(EntityId id);
uint_max999 GetCreaturehp(EntityId id);
uint_max999 GetCreaturemp(EntityId id);
uint_max999 GetCreaturexp(EntityId id);

void AddSpellPage(MemoryInterface memory, EntityId id, Spell spell, uint8_t spellbook_idx);
void ClearSpellPage(EntityId id, uint8_t spellbook_idx);