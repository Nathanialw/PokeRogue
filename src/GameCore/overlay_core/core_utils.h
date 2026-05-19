//
// Created by nathanial on 3/8/26.
//
#pragma once

#include "types.h"


/**********************************************************************************************************************/
/** TYPES
**********************************************************************************************************************/
typedef char CharStr_uint8[4];
typedef char CharStr_max999[4];
typedef char CharStr_max99[4];
typedef char CharStr_99[3];
typedef char CharStr_uint16[6];


/**********************************************************************************************************************/
/** FUNCTIONS
**********************************************************************************************************************/

void GetAsChars_uint8(uint8_t n, CharStr_uint8* out, bool prependZeros);
void GetAsChars_uint16(uint16_t n, CharStr_uint16* out);
void GetAsChars_Max999(uint16_t n, CharStr_max999* out);

uint8_t GetBottomByte(uint8_t originalByte);
uint8_t GetTopByte(uint8_t originalByte);
void GetAsChars_99(Int99 n, CharStr_99* out, bool prependZeros);

uint16_t Int999GetCurrent(const IntMax999* hp);
uint16_t Int999GetMax(const IntMax999* hp);
void Int999SetMax(IntMax999* hp, uint16_t value);
void Int999SetCurrent(IntMax999* hp, uint16_t value);
void Int999ApplyValue(HardwareInterface hardware, IntMax999* hp, int16_t value);



void* memset(void* dst, int value, size_t len);
void* memcpy(void* dst, const void* src, size_t len);

/**********************************************************************************************************************/
/** BIT ARRAY MANIPULATION
**********************************************************************************************************************/
bool SetBit(uint8_t* bitField, uint8_t idx, bool set);
bool GetBit(const uint8_t* bitField, uint8_t idx);
bool ToggleBit(uint8_t* bitField, uint8_t idx);


uint8_t GetNibble(uint8_t* bitField, uint8_t id);
void GetAsChars_Max99(uint8_t n, CharStr_max99* out);