//
// Created by nathanial on 5/20/26.
//

#pragma once
#include "lib_decl.h"


GraphicsInterface GraphicsInterfaceInit();
void SetFrameBufferColor(Color rgb565);
void TestColors();
void TestAnimation(FrameBuffer* f, Rect_16* r, Color* color1);