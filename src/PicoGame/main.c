// #include "game_state.h"
#include "cartridge.h"
#include "cartridge_rom.h"
#include "sounds.h"
#include "ili9341.h"
#include "init.h"
#include "input.h"
#include "lib_debugging.h"
#include "memory_ram.h"
#include "pico/multicore.h"
#include "pico/time.h"

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

#define CORE_VMA    0x20000000
#define OVERLAY_VMA 0x20010000

int main()
{
    Pico_Init();
    InitRam();
    sleep_ms(1000);;
    // Pico_AudioInit(); // Initialize audio system (this must be done on core 0)

    GameInterface api;
    api.hardware = GetHardwareInterface();
    api.input = GetInputInterface();
    api.graphics = GetGraphicsInterface();
    api.audio = SetAudioInterface();

    // load overlay table - save it into ram
    // on return jump to new overlay table
    // common data will be stored in psram
    // save data in psram
    // static data in eeprom

    uint8_t n;
    uint16_t s = sizeof(Overlay);
    EEPROM_Read(0, &n, 1);
    DEBUG("EEPROM: %d %d %d", n, s, n*s);
    EEPROM_Read(1, g_pico_ram.overlays.bytes, n * s);

    for (int i = 0; i < n; i++)
    {
        DEBUG("addr: %lu size: %lu", (g_pico_ram.overlays.overlay[i].addr), (g_pico_ram.overlays.overlay[i].size));
    }

    uint8_t overlay_table_addr = 0;
    LoadOverlay(g_pico_ram.overlays.overlay[overlay_table_addr].addr, CORE_VMA, g_pico_ram.overlays.overlay[overlay_table_addr].size);

    overlay_table_addr = 1;
    while (1)
    {
        overlay_table_addr = RunOverlay(&api, g_pico_ram.overlays.overlay[overlay_table_addr].addr, OVERLAY_VMA, g_pico_ram.overlays.overlay[overlay_table_addr].size);
        if (overlay_table_addr == 0)
        {
            DEBUG("OVERLAY RESERVED FOR CORE CODE, %d", overlay_table_addr);
            break;
        }
    }

    DEBUG("Program Done!~");
    // multicore_launch_core1(ThreadTwo, api.hardware);
    // GameLoop(api);
}
