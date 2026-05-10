#include "game_state.h"
#include "sounds.h"
#include "ili9341.h"
#include "init.h"
#include "input.h"
#include "memory_ram.h"
#include "pico/multicore.h"
#include "pico/time.h"

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
int main()
{

    Pico_Init();
    InitRam();
    Pico_TestColors();
    sleep_ms(1000);;

    GameInterface api;
    api.hardware = GetHardwareInterface();
    api.input = GetInputInterface();
    api.graphics = GetGraphicsInterface();

    Pico_AudioInit(); // Initialize audio system (this must be done on core 0)
    // multicore_launch_core1(ThreadTwo, api.hardware);
    GameLoop(api);
}
