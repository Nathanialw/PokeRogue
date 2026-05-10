//
// Created by nathanial on 2/20/26.
//
#pragma once
#include "lib_decl.h"


void Pico_Init(void);
HardwareInterface GetHardwareInterface();
void HardwareReset(void);

void ThreadTwo(HardwareInterface hardware);