#include "debug.h"
#ifdef STANDALONE
#include "game_state.h"
#endif
#include "cartridge.h"
#include "cartridge_rom.h"
#include "sounds.h"
#include "constants.h"
#include "ili9341.h"
#include "init.h"
#include "input.h"
#include "lib_debugging.h"
#include "memory_ram.h"
#include "pico/stdlib.h"

#define CORE_VMA    0x20000000
#define OVERLAY_VMA 0x20010000
#define END_VMA     0x20020000


int main()
{
    Pico_Init();
    InitRam();
    // Pico_AudioInit(); // Initialize audio system (this must be done on core 0)

    GameInterface api;
    api.hardware = GetHardwareInterface();
    api.input = GetInputInterface();
    api.graphics = GetGraphicsInterface();
    api.audio = SetAudioInterface();
    api.memory = GetMemoryInterface();

    Pico_TestColors();



begin:
    DEBUG("WELCOME TO PICO ROGUE");

    while (1)
    {
        api.input.HandleInput();
        if (api.input.GetButtonB())
        {
            EEPROM_Flash(EEPROM_CART_FUNC_CS);
            DEBUG("CODE EEPROM FLASHED");
        }
        if (api.input.GetButtonY())
        {
            EEPROM_Flash(EEPROM_CART_DATA_CS);
            DEBUG("DATA EEPROM FLASHED");
        }

        if (api.input.GetButtonDown())
        {
            EEPROM_Verify(EEPROM_CART_FUNC_CS);
            sleep_ms(500);
            EEPROM_Verify(EEPROM_CART_DATA_CS);

            // DEBUG("----- BEGIN TESTS ---");
            // EEPROM_FullTest(EEPROM_CART_FUNC_CS);
            // DEBUG("----- BEGIN TESTS ---");
            // EEPROM_FullTest(EEPROM_CART_DATA_CS);
            //
            // //
            // uint32_t size = 4 * 1024 * 1024;
            // EEPROM_VerifySize(EEPROM_CART_FUNC_CS, size);
            // EEPROM_FullMemoryTest(EEPROM_CART_FUNC_CS, size);
            // EEPROM_RetentionCheck(EEPROM_CART_FUNC_CS, size);
            //
            // EEPROM_VerifySize(EEPROM_CART_DATA_CS, size);
            // EEPROM_FullMemoryTest(EEPROM_CART_DATA_CS, size);
            // EEPROM_RetentionCheck(EEPROM_CART_DATA_CS, size);
        }

        if (api.input.GetButtonA())
        {
            break;
        }

        if (api.input.GetButtonStart())
        {
            return 0;
        }
    }

    // load overlay table - save it into ram
    // on return jump to new overlay table
    // common data will be stored in psram
    // save data in psram
    // static data in eeprom

    uint8_t n;
    uint16_t s = sizeof(Overlay);
    EEPROM_Read(EEPROM_CART_FUNC_CS, 4, &n, 1);
    DEBUG("EEPROM: %d %d %d", n, s, n*s);
    EEPROM_Read(EEPROM_CART_FUNC_CS, 5, g_pico_ram.overlays.bytes, n * s);

    for (int i = 0; i < n; i++)
    {
        DEBUG("addr: %lu size: %lu", (g_pico_ram.overlays.overlay[i].addr), (g_pico_ram.overlays.overlay[i].size));
    }

    uint8_t overlay_idx = 0;
    LoadOverlay(g_pico_ram.overlays.overlay[overlay_idx].addr, CORE_VMA, g_pico_ram.overlays.overlay[overlay_idx].size);
    DEBUG("Reserved Core    RAM size: %d bytes - Used: %lu bytes", OVERLAY_VMA - CORE_VMA, g_pico_ram.overlays.overlay[overlay_idx].size);
    if (g_pico_ram.overlays.overlay[overlay_idx].size >= OVERLAY_VMA - CORE_VMA)
        DEBUG("ERROR CORE EXCEEDS RESERVED SPACE");

    // uint32_t overlay_table_addr = 0x20000000 + g_pico_ram.overlays.overlay[overlay_idx].size;
    overlay_idx = 1;
    while (1)
    {
        DEBUG("Reserved Overlay RAM size: %d bytes - Used: %lu bytes", END_VMA - OVERLAY_VMA, g_pico_ram.overlays.overlay[overlay_idx].size);
        overlay_idx = RunOverlay(&api, g_pico_ram.overlays.overlay[overlay_idx].addr, OVERLAY_VMA, g_pico_ram.overlays.overlay[overlay_idx].size);
        if (overlay_idx == 0)
        {
            DEBUG("OVERLAY RESERVED FOR CORE CODE, %d", overlay_idx);
            break;
        }
    }

    goto begin;
#ifdef STANDALONE
    // multicore_launch_core1(ThreadTwo, api.hardware);
    GameLoop(&api);
#endif
}
