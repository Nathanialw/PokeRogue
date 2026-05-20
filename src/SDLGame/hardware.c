//
// Created by nathanial on 5/20/26.
//

#include "hardware.h"

#include <string.h>

#include "lib_decl.h"

#include "debug.h"


//TODO
void HardwareReset(void)
{
}

//TODO
void SleepMS(uint32_t uint32)
{
}

//TODO
uint32_t Abs(int max)
{
    return 0;
}

//TODO
uint8_t GetRandomUniform(uint8_t min, uint8_t max)
{
    return 0;
}

//TODO
uint8_t GetRandom_uint8_t(uint8_t min, uint8_t max)
{
    return 0;
}


HardwareInterface HardwareInterfaceInit()
{
    HardwareInterface mardwareInterface = {
        .HardwareReset = HardwareReset,
        .SleepMS = SleepMS,
        .MemSet = memset,
        .Abs = Abs,
        .GetRandomUniform = GetRandomUniform,
        .GetRandom_uint8_t = GetRandom_uint8_t,
        .StrChr = strchr,
        .Print = Print,
        .PrintVar = PrintVar,
    };
    return mardwareInterface;
}
