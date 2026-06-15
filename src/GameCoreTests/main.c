//
// Created by nathanial on 2/21/26.
//

#include "lib_debugging.h"

#include <SDL3/SDL.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include "combat_tests.h"
#include "creatures.h"
#include "generate_map_state.h"
#include "SDLGame/ram.h"


State HandleInput(State state)
{
    return state;
}


void SleepMS(uint32_t t)
{
};

void ClearBuffer()
{
};

void SetFrameBuffer(Color rgb565)
{
};

void DrawBuffer(FrameBuffer f)
{
};

void DrawSprite(FrameBuffer f, const uint8_t* sprite)
{
};

void DrawToBuffer(const FrameBuffer frameBuffer, const uint16_t* pixels, const Rect_16 rect)
{
};

void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565)
{
};

void TestAnimation(FrameBuffer f, Rect_16 r, uint16_t color1)
{
};

void DrawTileKeyed(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data)
{
};

void Draw(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data)
{
};

void FillScreen(Color rgb565)
{
}

void PlaySoundEffect()
{
}

void SetBuffer()
{
}

bool GetButtonA()
{
    return false;
}

bool GetButtonB()
{
    return false;
}

bool GetButtonY()
{
    return false;
}

bool GetButtonX()
{
    return false;
}

bool GetButtonSelect()
{
    return false;
}

bool GetButtonStart()
{
    return false;
}

bool GetButtonUp()
{
    return false;
}

bool GetButtonDown()
{
    return false;
}

bool GetButtonLeft()
{
    return false;
}

bool GetButtonRight()
{
    return false;
}

bool GetButtonJSClick()
{
    return false;
}

bool GetButtonDPClick()
{
    return false;
}

uint16_t* GetFrameBufferFront()
{
    return NULL;
}

uint16_t* GetFrameBufferBack()
{
    return NULL;
}

uint8_t* GetFrameBuffer1byte()
{
    return NULL;
}

uint16_t* GetFrameBuffer2bytes()
{
    return NULL;
}

uint16_t GetBufferWidth()
{
    return 0;
}

uint16_t GetBufferHeight()
{
    return 0;
}

KeyState GetInputKeyState()
{
    KeyState k = {0};
    return k;
}

void sleep_ms(uint32_t t)
{
    sleep(t);
}

uint8_t GetRandom_uint8_t(uint8_t min, uint8_t max)
{
    return random() % max + min;
}


void PlayMusic(uint16_t music_id)
{
}


typedef struct
{
    uint8_t* rom_bytes;
    size_t romSize;
} TestRamState;


TestRamState g_testsRamState;

void GetRom(uint32_t addr, uint8_t* buf, uint32_t size)
{
    memcpy(buf, &g_testsRamState.rom_bytes[addr], size);
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
    void* romData = LoadBinaryFile("bin/cartridge_data.bin", &g_testsRamState.romSize);

    if (romData)
    {
        DEBUG("SUCCESS");
        // romData points to a buffer of exactly romSize bytes.
        // You can cast it to uint8_t* and treat it as a byte array.
        g_testsRamState.rom_bytes = (uint8_t*)romData;
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
    SDL_free(g_testsRamState.rom_bytes);
}


GameInterface InitAPI()
{
    GameInterface api;
    api.hardware = (HardwareInterface)
    {
        // .HardwareReset = HardwareReset,
        .SleepMS = sleep_ms,
        .MemSet = memset,
        .GetRandom_uint8_t = GetRandom_uint8_t,
        // .GetRandom_uint8_t = GetRandom_uint8_t,
        // .StrChr = strchr,
        // .StrLen = strlen,
        // .StrCmp = strcmp,
        // .StrCpy = strcpy,
        // .StrCat = strcat,
    };


    api.memory = (MemoryInterface)
    {
        .GetRom = GetRom,
    };

    api.audio = (AudioInterface)
    {
        .PlayMusic = PlayMusic,
    };

    return api;
}

int main()
{
    LoadGameData();

    GameInterface api = InitAPI();
    InitGame(api.hardware, api.memory, api.audio);


    RunCombatTests(api.hardware, api.memory);
    // CreatureTests(api.hardware);
    // CheckAnimationImplemented();


    return 0;
};
