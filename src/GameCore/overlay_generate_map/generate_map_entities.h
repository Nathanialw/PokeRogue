//
// Created by nathanial on 6/5/26.
//

#pragma once
#include "lib_decl.h"


void GenerateEntities(GameInterface* spi);


// void CopyCreature(HardwareInterface hardware, EntityId src_id, EntityId target_id);
// void CopyTrainer(HardwareInterface hardware, EntityId src_id, EntityId target_id);
// void CopyItem(EntityId src_id, EntityId target_id);
// void CopyObject(EntityId src_id, EntityId target_id);
void PopulateLevelCreatures(HardwareInterface hardware, MemoryInterface memory);
void PopulateLevelItems(HardwareInterface hardware, MemoryInterface memory);
void PopulateLevelObjects(HardwareInterface hardware, MemoryInterface memory);
void PopulateLevelTrainers(HardwareInterface hardware, MemoryInterface memory);
