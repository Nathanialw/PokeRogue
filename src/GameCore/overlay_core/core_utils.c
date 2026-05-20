//
// Created by nathanial on 3/8/26.
//
#include "core_utils.h"
#include "lib_memory.h"

#include "types.h"


/**********************************************************************************************************************/
/** IMPLEMENTATION DEFINED
**********************************************************************************************************************/
#define CHAR_OFFSET 48

/**********************************************************************************************************************/
/** takes a char array and a uin8_t and writes the value og the integer as chars to the array
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetAsChars_uint8(uint8_t n, CharStr_uint8* out, bool prependZeros)
{
    uint8_t hundreds = ((n / 100) % 10);
    uint8_t tens = ((n / 10) % 10);
    uint8_t ones = (n % 10);

    if (!prependZeros && CHAR_OFFSET + hundreds == '0')
        (*out)[0] = ' ';
    else
        (*out)[0] = CHAR_OFFSET + hundreds;

    if (!prependZeros && CHAR_OFFSET + tens == '0')
        (*out)[1] = ' ';
    else
        (*out)[1] = CHAR_OFFSET + tens;

    (*out)[2] = CHAR_OFFSET + ones;
    (*out)[3] = '\0';
}

/**********************************************************************************************************************/
/** takes a char array and a uin16_t and writes the value og the integer as chars to the array
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetAsChars_uint16(uint16_t n, CharStr_uint16* out)
{
    uint8_t ten_thousands = (n / 10000) % 10;
    uint8_t thousands = (n / 1000) % 10;
    uint8_t hundreds = (n / 100) % 10;
    uint8_t tens = (n / 10) % 10;
    uint8_t ones = n % 10;

    (*out)[0] = CHAR_OFFSET + ten_thousands;
    (*out)[1] = CHAR_OFFSET + thousands;
    (*out)[2] = CHAR_OFFSET + hundreds;
    (*out)[3] = CHAR_OFFSET + tens;
    (*out)[4] = CHAR_OFFSET + ones;
    (*out)[5] = '\0';
}

/**********************************************************************************************************************/
/** takes a char array and a uint16_t and writes the value og the integer as chars to the array
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetAsChars_Max999(uint16_t n, CharStr_max999* out)
{
    uint8_t hundreds = (n / 100) % 10;
    uint8_t tens = (n / 10) % 10;
    uint8_t ones = n % 10;

    (*out)[0] = CHAR_OFFSET + hundreds;
    (*out)[1] = CHAR_OFFSET + tens;
    (*out)[2] = CHAR_OFFSET + ones;
    (*out)[3] = '\0';
}

/**********************************************************************************************************************/
/** takes a char array and a uint8_t and writes the value og the integer as chars to the array
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetAsChars_Max99(uint8_t n, CharStr_max99* out)
{
    uint8_t hundreds = (n / 100) % 10;
    uint8_t tens = (n / 10) % 10;
    uint8_t ones = n % 10;

    (*out)[0] = CHAR_OFFSET + hundreds;
    (*out)[1] = CHAR_OFFSET + tens;
    (*out)[2] = CHAR_OFFSET + ones;
    (*out)[3] = '\0';
}

/**********************************************************************************************************************/
/** takes a char array and a uint8_t and writes the value og the integer as chars to the array
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetAsChars_99(Int99 n, CharStr_99* out, bool prependZeros)
{
    uint8_t tens = (n.value / 10) % 10;
    uint8_t ones = n.value % 10;

    if (!prependZeros && CHAR_OFFSET + tens == '0')
        (*out)[0] = ' ';
    else
        (*out)[0] = CHAR_OFFSET + tens;
    (*out)[1] = CHAR_OFFSET + ones;
    (*out)[2] = '\0';
}

/**********************************************************************************************************************/
/** Returns the top 4 bits of the given byte
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetTopByte(uint8_t originalByte)
{
    return originalByte >> 4;
}

/**********************************************************************************************************************/
/** Returns the bottom 4 bits of the given byte
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetBottomByte(uint8_t originalByte)
{
    return originalByte & 0x0F;
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetNibble(uint8_t* bitField, uint8_t id)
{
    if (id % 2 == 0)
        return GetTopByte(bitField[id / 2]);
    return GetBottomByte(bitField[id / 2]);
}

/**********************************************************************************************************************/
/** Returns the current value of the given IntMax999
**********************************************************************************************************************/
SET_MEMORY(".core")
uint16_t Int999GetCurrent(const IntMax999* hp)
{
    return (hp->current_high << 8) | hp->current_low;
}

/**********************************************************************************************************************/
/** Returns the max value of the given IntMax999
**********************************************************************************************************************/
SET_MEMORY(".core")
uint16_t Int999GetMax(const IntMax999* hp)
{
    return (hp->max_high << 8) | hp->max_low;
}

/**********************************************************************************************************************/
/** Sets the current value of the given IntMax999 to the given value
**********************************************************************************************************************/
SET_MEMORY(".core")
void Int999SetCurrent(IntMax999* hp, uint16_t value)
{
    hp->current_low = value & 0xFF;
    hp->current_high = (value >> 8) & 0x03;
}

/**********************************************************************************************************************/
/** Sets the max value of the given IntMax999 to the given value
**********************************************************************************************************************/
SET_MEMORY(".core")
void Int999SetMax(IntMax999* hp, uint16_t value)
{
    hp->max_low = value & 0xFF;
    hp->max_high = (value >> 8) & 0x03;
}

SET_MEMORY(".core")
void Int999ApplyValue(HardwareInterface hardware, IntMax999* hp, int16_t value)
{
    uint16_t n = Int999GetCurrent(hp);
    if (n >= hardware.Abs(value))
    {
        n += value;
        Int999SetCurrent(hp, n);
    }
    else
    {
        Int999SetCurrent(hp, 0);
    }
}


/********************************************************************************************************************************************************************************************************************************************/
/* *
 *  bit field functions
 *
/********************************************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************************/
/**Takes an array on uint8_t
 * sets the bit at the given index to the set value
 * Returns the bit value at the given index
**********************************************************************************************************************/
SET_MEMORY(".core")
bool SetBit(uint8_t* bitField, uint8_t idx, bool set)
{
    uint32_t byteIndex = idx >> 3; // / 8 faster on pico ARM
    uint32_t bitIndex = idx & 0x07; // % 8 faster on pico ARM
    uint8_t mask = (uint8_t)(1u << bitIndex);

    uint8_t* bytePtr = &bitField[byteIndex];
    uint8_t old = *bytePtr;

    if (set)
    {
        *bytePtr |= mask;
    }
    else
    {
        *bytePtr &= (uint8_t)~mask;
    }

    return *bytePtr != old;
}

/**********************************************************************************************************************/
/** Takes an array on uint8_t
 *  Returns the bit value at the given index
**********************************************************************************************************************/
SET_MEMORY(".core")
bool GetBit(const uint8_t* bitField, uint8_t idx)
{
    uint32_t byteIndex = idx >> 3;
    uint32_t bitIndex = idx & 0x07;
    uint8_t mask = (uint8_t)(1u << bitIndex);

    return (bitField[byteIndex] & mask) != 0;
}

/**********************************************************************************************************************/
/**Takes an array on uint8_t
 * flips the bit at the given index
 * Returns the bit value at the given index
**********************************************************************************************************************/
SET_MEMORY(".core")
bool ToggleBit(uint8_t* bitField, uint8_t idx)
{
    uint32_t byteIndex = idx >> 3;
    uint32_t bitIndex = idx & 0x07;
    uint8_t mask = (uint8_t)(1u << bitIndex);

    uint8_t* bytePtr = &bitField[byteIndex];
    *bytePtr ^= mask; // Toggle with XOR

    return (*bytePtr & mask) != 0; // Return new state
}


SET_MEMORY(".core")
void* memcpy(void* dst, const void* src, size_t len)
{
    uint8_t* d = (uint8_t*)dst;
    const uint8_t* s = (const uint8_t*)src;

    while (len--)
    {
        *d++ = *s++;
    }

    return dst;
}

SET_MEMORY(".core")
void* memset(void* dst, int value, size_t len)
{
    uint8_t* d = (uint8_t*)dst;

    while (len--)
    {
        *d++ = (uint8_t)value;
    }

    return dst;
}
