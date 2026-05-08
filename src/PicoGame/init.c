//
// Created by nathanial on 2/20/26.
//
#include "ili9341.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/adc.h"

#include "input.h"
#include "pico_constants.h"

#include "init.h"

#include "cartridge_ram.h"
#include "catridge_rom.h"
#include "hardware.h"
#include "lib_debugging.h"
#include "memory_psram.h"
#include "sounds.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"

#define PICO

void InitBtn(int btn)
{
    gpio_init(btn);
    gpio_set_dir(btn, GPIO_IN);
    gpio_pull_up(btn);
}


void SleepMS(uint32_t t)
{
    sleep_ms(t);
}


/**********************************************************************************************************************/
/**  updates the battery data after each generated song
 *  routines to run on core 1
 *      -Audio
 *      -Battery status
 *  //TODO: more tasks, perhaps input polling
**********************************************************************************************************************/
void ThreadTwo(void)
{
    // MusicData music_data = InitMusicData();
    while (1)
    {
        Pico_BatteryStatus();

        // if (g_run.music.master_volume <= MIN_VOLUME)
        // {
        //     CheckVolume();
        //     sleep_ms(200);
        // }
        // else
        // {
        // GenerateDungeonMelody(g_run.music.notes);
        // AudioPlayVoices(&music_data, g_run.music.notes);
        // }
    }
}


/**********************************************************************************************************************/
/**  Pico main init function
**********************************************************************************************************************/
void Pico_Init(void)
{
#ifdef ENABLE_DEBUG_OUTPUT
#include <stdio.h>
    stdio_init_all();
    sleep_ms(5000);
#endif

    uint32_t freq = clock_get_hz(clk_sys);
    DEBUG("Current CPU Frequency: %lu.%03lu MHz", freq / 1000000, (freq % 1000000) / 1000);
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

#if defined(SN74HC165N_SPI)
    SN74HC165N_Setup();
#elif defined(SN74HC165N_BITBANG)
    SN74HC165N_BitBangInit();
#elif defined(SN74HC165N_PIO)
#error "SN74HC165N_PIO not yet implemented"
#else
#error "Define SN74HC165N_BITBANG or SN74HC165N_SPI or SN74HC165N_PIO"
#endif

    InitCart();
    FRAM_Init();
    InitPSram();

    Backlight_Init();
    adc_init();
    adc_gpio_init(JSX); // VRx
    adc_gpio_init(JSY); // VRy
    adc_gpio_init(BATTERY); // VRy

    // Pico_ADS1115_Init();
    Pico_ili9341_Init();
    sleep_ms(200);

    DEBUG("----- BEGIN TESTS ---");
    EEPROM_FullTest();
    DEBUG("----- EEPROM Test Complete ---");
    FRAM_FullTest();
    DEBUG("----- FRAM Test Complete ---");
    PSRAM_FullTest();
    DEBUG("----- PSRAM Test Complete ---");

    // Pico_AudioInit(); // Initialize audio system (this must be done on core 0)
    // multicore_launch_core1(ThreadTwo);
}
