//
// Created by nathanial on 5/20/26.
//

#include "hardware.h"

#include <string.h>
#include <stdlib.h>
#include <SDL3/SDL_timer.h>

#include "lib_decl.h"

#include "debug.h"


//TODO
void HardwareReset(void)
{
}

//TODO
void SleepMS(uint32_t uint32)
{
    SDL_Delay(uint32);
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

uint8_t GetRandom_uint8_t(uint8_t min, uint8_t max)
{
    if (min > max) return min;
    return rand() % (max - min + 1) + min;
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
