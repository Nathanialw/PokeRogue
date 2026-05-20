//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"

void GetSkills(MemoryInterface memory, EntityId id, Type type);
bool InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_id, EntityId e_id);
