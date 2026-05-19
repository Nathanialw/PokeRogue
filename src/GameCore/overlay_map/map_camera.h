//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "../common/types.h"
#include "lib_types.h"

Camera InitCamera(uint8_t x, uint8_t y, uint16_t w, uint16_t h);
Camera SetCamera(uint8_t x, uint8_t y);
void SetCameraPlayer(void);
Camera GetCamera(void);
bool CameraContains(uint8_t x, uint8_t y);
