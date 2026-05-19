//
// Created by nathanial on 5/19/26.
//

#pragma once

#include "types.h"


bool MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
bool MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
bool MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id);
bool RevealMap();
