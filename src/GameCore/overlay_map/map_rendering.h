//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "lib_decl.h"


void UpdateVision(GraphicsInterface graphics, HardwareInterface hardware);
void FullRedraw(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
void RenderObjects(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);

void DrawMiniMap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory);
