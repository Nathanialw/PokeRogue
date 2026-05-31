//
// Created by nathanial on 5/20/26.
//

#include "memory.h"

#include <stdio.h>
#include <SDL3/SDL.h>

#include "lib_decl.h"
#include "debug.h"
#include "lib_debugging.h"
#include "ram.h"

size_t romSize;


// TODO:
void ReadROMemory(uint32_t addr, uint8_t* buf, uint32_t size)
{
#if defined(DEBUG)
    if (addr > romSize || size > romSize - addr)
    {
        // Attempted read beyond the end of memory
        SDL_Log("ReadMemory out of bounds: addr=%u size=%u (max=%lu)", addr, size, romSize);
        return;
    }
#endif
    memcpy(buf, &g_ramState.bytes[addr], size);
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
        .GetRom = ReadROMemory,
        .GetRam = GetRam,
        .SaveToRam = SaveToRam,
        .SaveGame = SaveGame,
        .Print = Print,
        .PrintVar = PrintVar,
    };
    return memoryInterface;
}



void* LoadBinaryFile(const char* filename, size_t* dataSize)
{
    void* data = SDL_LoadFile(filename, dataSize);
    if (!data)
    {
        SDL_Log("Failed to load file %s: %s", filename, SDL_GetError());
        return NULL;
    }
    return data;
}

void LoadGameData(void)
{
    void* romData = LoadBinaryFile("bin/cartridge_data.bin", &romSize);

    if (romData)
    {
        DEBUG("SUCCESS");
        // romData points to a buffer of exactly romSize bytes.
        // You can cast it to uint8_t* and treat it as a byte array.
        g_ramState.bytes = (uint8_t*)romData;
        // ... use the data ...

        // Free it when done
    }
    else
    {
        DEBUG("FAILED");
    }
}

void FreeGameData(void)
{
    SDL_free(g_ramState.bytes);
}
