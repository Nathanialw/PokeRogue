//
// Created by nathanial on 5/20/26.
//

#include "memory.h"

#include "lib_decl.h"
#include "debug.h"


// TODO:
void GetRom(uint32_t addr, uint8_t* buf, uint32_t size) //rom data
{
}

// TODO:
void GetRam(uint32_t addr, char* buf, uint32_t size) //psram
{
}


// TODO:
void SaveToRam(uint32_t addr, char* buf, uint32_t size) //psram
{
}

// TODO:
void SaveGame(uint32_t addr, char* buf, uint32_t size) //fram
{
}



MemoryInterface MemoryInterfaceInit()
{
    MemoryInterface memoryInterface = {
        .GetRom = GetRom,
        .GetRam = GetRam,
        .SaveToRam = SaveToRam,
        .SaveGame = SaveGame,
        .Print = Print,
        .PrintVar = PrintVar,
    };
    return memoryInterface;
}
