//
// Created by nathanial on 5/7/26.
//
#pragma once
#include <stddef.h>

#include "lib_types.h"

void InitCart(uint32_t cs);

bool EEPROM_WriteAny(uint32_t cs, uint32_t addr, uint8_t* data, uint32_t length, bool verify);
void EEPROM_Read(uint32_t cs, uint32_t addr, uint8_t* data, size_t len);
void EEPROM_Clear(uint32_t cs, uint32_t expected_size);
void EEPROM_EraseSector(uint32_t cs, uint32_t addr);
void EEPROM_Flash(uint32_t cs);

void EEPROM_Dump(uint32_t cs, uint32_t chip_size);


void EEPROM_FullMemoryTest(uint32_t cs, uint32_t chip_size);
bool EEPROM_VerifySize(uint32_t cs, uint32_t expected_size);

void EEPROM_PrintBuffer(uint32_t sector, uint8_t* buf, uint32_t BUF_SIZE);
bool EEPROM_FullTest(uint32_t cs);
void EEPROM_RetentionCheck(uint32_t cs, uint32_t chip_size);
void EEPROM_Verify(uint32_t cs, uint32_t chip_size);
