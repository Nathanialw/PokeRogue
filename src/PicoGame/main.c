#include "game_state.h"
#include "ili9341.h"
#include "init.h"
#include "input.h"
#include "memory_ram.h"
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
    GameLoop(api);
}
