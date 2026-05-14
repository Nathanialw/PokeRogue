//
// Created by nathanial on 5/12/26.
//
#pragma once
#include <stdint.h>
#include <stdbool.h>

void SDCard_Init();
void SDCard_ProgramCartridge(uint32_t chip_size);
bool Test_CSD(void);
