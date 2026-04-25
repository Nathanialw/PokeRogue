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

#include "core.h"
#include "hardware.h"
#include "memory_ram.h"
#include "sound.h"
#include "sounds.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"
#include "hardware/structs/clocks.h"

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
void ThreadTwo()
{
    MusicData music_data = InitMusicData();
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
        GenerateDungeonMelody(g_run.music.notes);
        AudioPlayVoices(&music_data, g_run.music.notes);
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
    DEBUG("STARTUP!\n");
#endif
    uint32_t freq = clock_get_hz(clk_sys);
    DEBUG("Current CPU Frequency: %lu.%03lu MHz\n", freq / 1000000, (freq % 1000000) / 1000);

    // I/O initialization (same as before)
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);


    // InitBtn(JSCLICKBTN);

    InitBtn(REDBTN);
    InitBtn(WHITEBTN);
    InitBtn(BLUEBTN);
    InitBtn(GREENBTN);

    InitBtn(DCLICKBTN);
    InitBtn(RIGHTBTN);
    InitBtn(LEFTBTN);
    InitBtn(DOWNBTN);
    InitBtn(UPBTN);

    Backlight_Init();
    adc_init();
    adc_gpio_init(JSX); // VRx
    adc_gpio_init(JSY); // VRy
    adc_gpio_init(BATTERY); // VRy

    Pico_ADS1115_Init();
    Pico_ili9341_Init();
    sleep_ms(200);

    // Initialize audio system (this must be done on core 0)
    Pico_AudioInit();

    multicore_launch_core1(ThreadTwo);
    DEBUG("init complete - game on core 0,  audio running on core 1");
}
