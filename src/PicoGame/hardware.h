//
// Created by nathanial on 3/26/26.
//
#pragma once
#include "lib_types.h"

void Pico_BatteryStatus(void);
void Backlight_Init(void);
bool Pico_ADS1115_Init(void);
void RecoverADS1115(void);
void UpdateBacklight(void);
int16_t Pico_VolumeControl(void);
