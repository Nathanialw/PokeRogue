//
// Created by nathanial on 5/20/26.
//

#include "graphics.h"

#include "lib_decl.h"


//TODO:
uint16_t* GetFrameBufferFront(void)
{
    return NULL;
}

//TODO:
uint16_t* GetFrameBufferBack(void)
{
    return NULL;
}

//TODO:
uint8_t* GetFrameBuffer1byte(void)
{
    return NULL;
}

//TODO:
uint16_t* GetFrameBuffer2bytes(void)
{
    return NULL;
}

//TODO:
uint16_t GetBufferWidth(void)
{
    return 0;
}

//TODO:
uint16_t GetBufferHeight(void)
{
    return 0;
}

//TODO:
void ClearBuffer(void)
{
}

//TODO:
void DrawBuffer(const FrameBuffer frame_buffer)
{
}

//TODO:
void DrawSpriteTile(FrameBuffer frame_buffer, const uint8_t* sprite)
{
}

//TODO:
void DrawToBuffer(const FrameBuffer frame_buffer, const uint16_t* pixels, const Rect_16 rect)
{
}

//TODO:
void DrawTileKeyed(uint16_t uint16, uint16_t uint17, uint16_t uint18, uint16_t uint19, const uint16_t* data)
{
}

//TODO:
void Draw(uint16_t uint16, uint16_t uint17, uint16_t uint18, uint16_t uint19, const uint8_t* data)
{
}

//TODO:
void SetBuffer(uint16_t length, uint16_t* p, uint16_t rgb565)
{
}

//TODO:
void SetBufferColor(uint16_t length, uint16_t* p, Color rgb565)
{
}

//TODO:
void SetFrameBuffer(uint16_t rgb565)
{
}

//TODO:
void SetFrameBufferColor(Color rgb565)
{
}

//TODO:
void FillRect(uint16_t uint16, uint16_t uint17, uint16_t uint18, uint16_t uint19, uint16_t rgb565)
{
}

//TODO:
void FillRectColor(uint16_t uint16, uint16_t uint17, uint16_t uint18, uint16_t uint19, Color rgb565)
{
}

//TODO:
void FillScreen(uint16_t rgb565)
{
}

//TODO:
void FillScreenColor(Color rgb565)
{
}

//TODO:
void TestAnimation(FrameBuffer frame_buffer, Rect_16 rect_16, Color color1)
{
}


GraphicsInterface GraphicsInterfaceInit()
{
    GraphicsInterface graphicsInterface = {
        .GetFrameBufferFront = GetFrameBufferFront,
        .GetFrameBufferBack = GetFrameBufferBack,
        .GetFrameBuffer1byte = GetFrameBuffer1byte,
        .GetFrameBuffer2bytes = GetFrameBuffer2bytes,
        .GetBufferWidth = GetBufferWidth,
        .GetBufferHeight = GetBufferHeight,
        .ClearBuffer = ClearBuffer,
        .DrawBuffer = DrawBuffer,
        .DrawSprite = DrawSpriteTile,
        .DrawToBuffer = DrawToBuffer,
        .DrawTileKeyed = DrawTileKeyed,
        .Draw = Draw,
        .SetBuffer = SetBuffer,
        .SetBufferColor = SetBufferColor,
        .SetFrameBuffer = SetFrameBuffer,
        .SetFrameBufferColor = SetFrameBufferColor,
        .FillRect = FillRect,
        .FillRectColor = FillRectColor,
        .FillScreen = FillScreen,
        .FillScreenColor = FillScreenColor,
        .TestAnimation = TestAnimation,

    };

    return graphicsInterface;
}
