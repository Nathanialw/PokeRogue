//
// Created by nathanial on 4/30/26.
//

#include "memory_ram.h"

Data g_pico_ram = {0};

void InitRam()
{
    g_pico_ram.input.defaultPollingRate = 12;
    g_pico_ram.input.pollingRate = 12;
    g_pico_ram.sound.master_volume = 32768;
}
