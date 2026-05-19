//
// Created by nathanial on 5/19/26.
//
#pragma once

#include "lib_decl.h"

typedef char StatusPrefix[3];

void GetStatLine(HardwareInterface hardware, uint16_t cur, uint16_t max, uint8_t max_chars, char* dest, const StatusPrefix prefix);