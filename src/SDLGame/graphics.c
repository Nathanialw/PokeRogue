//
// Created by nathanial on 5/20/26.
//

#include "graphics.h"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>

#include "lib_constants.h"
#include "lib_debugging.h"
#include "lib_types.h"
#include "lib_decl.h"
#include "ram.h"


void Draw(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data);
void FillRectColor(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565);
void SetFrameBufferColor(Color rgb565);
void Draw16(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);


uint16_t* GetFrameBufferFront(void)
{
    return g_ramState.framebuffer.front;
}

uint16_t* GetFrameBufferBack(void)
{
    return g_ramState.framebuffer.back;
}

uint8_t* GetFrameBuffer1byte(void)
{
    return g_ramState.framebuffer.frameBuffer1byte;
}

uint16_t* GetFrameBuffer2bytes(void)
{
    return g_ramState.framebuffer.frameBuffer;
}

uint16_t GetBufferWidth(void)
{
    return BUFFER_W;
}

uint16_t GetBufferHeight(void)
{
    return BUFFER_H;
}

// #define SWAP_COLOR_BYTES

static inline uint16_t SetColorByte(Color c)
{
#if defined(SWAP_COLOR_BYTES)
    return (c.color >> 8) | (c.color << 8);
#else
    return c.color;
#endif
}


/**********************************************************************************************************************/
/**  fills the given buffer with the given colour value
**********************************************************************************************************************/
void SetRectColor(uint32_t length, uint16_t* p, Color rgb565)
{
    for (uint32_t i = 0; i < length; i++)
        p[i] = SetColorByte(rgb565);
}


void DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565)
{
    // if ((w * h) < (BUFFER_SIZE * 2))
    if ((w * h) < (SCREEN_H * SCREEN_W * 2))
    {
        SetFrameBufferColor(rgb565);
        Draw16(x, y, w, h, g_ramState.framebuffer.frameBuffer);
    }
    else
    {
        if (w > h)
        {
            w = w / 2;
            FillRectColor(x, y, w, h, rgb565);
            x += w;
            FillRectColor(x, y, w, h, rgb565);
        }
        else
        {
            h = h / 2;
            FillRectColor(x, y, w, h, rgb565);
            y += h;
            FillRectColor(x, y, w, h, rgb565);
        }
    }
}

/**********************************************************************************************************************/
/**  Blits the buffer to the screen with the given position and dimensions
**********************************************************************************************************************/
void Draw(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t* data)
{
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;
    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    memcpy(g_ramState.framebuffer.frameBuffer1byte, data, w * h);
    SDL_Rect rect = {x, y, w, h};

    SDL_UpdateTexture(g_ramState.screen, &rect, g_ramState.framebuffer.frameBuffer, w * sizeof(uint16_t));
    SDL_RenderTexture(g_ramState.renderer, g_ramState.screen, NULL, NULL);

    // SDL_RenderPresent(g_ramState.renderer);
}

void Draw16(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data)
{
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;
    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    // printf("Drawing ->  ");
    // for (uint16_t i = 0; i < 16; i++)
    // printf("%04X ", data[i]);
    // printf("\n");


    SDL_Rect rect = {x, y, w, h};
    if (!SDL_UpdateTexture(g_ramState.screen, &rect, data, w * sizeof(uint16_t)))
        SDL_Log("Failed to update texture %s", SDL_GetError());
    if (!SDL_RenderTexture(g_ramState.renderer, g_ramState.screen, NULL, NULL))
        SDL_Log("Failed to render texture %s", SDL_GetError());

    // SDL_RenderPresent(g_ramState.renderer);
}

void ClearBuffer(void)
{
    Color c = {.color = 0xFFFF};
    SetRectColor(BUFFER_SIZE_2BYTES, g_ramState.framebuffer.frameBuffer, c);
}

void DrawBuffer(const FrameBuffer f)
{
    Draw16(f.x, f.y, f.w, f.h, g_ramState.framebuffer.frameBuffer);
}

void DrawSpriteTile(const FrameBuffer f, const uint8_t* sprite)
{
    Draw(f.x, f.y, f.w, f.h, sprite);
}

void DrawToBuffer(const FrameBuffer* frameBuffer, const uint16_t* pixels, const Rect_16* rect)
{
    uint16_t width = frameBuffer->w;
    // = Flash_GetColor(memory, PAL_KEY];

    uint16_t clip_x = 0;
    uint16_t clip_y = 0;
    uint16_t dest_x = rect->x;
    uint16_t dest_y = rect->y;

    // handle out of bounds drawing
    if (rect->x < 0)
    {
        clip_x = -rect->x;
        dest_x = 0;
    }
    if (rect->y < 0)
    {
        clip_y = -rect->y;
        dest_y = 0;
    }

    for (uint16_t y = clip_y; y < rect->h; y++)
    {
        for (uint16_t x = clip_x; x < rect->w; x++)
        {
            Color color;
            color.color = pixels[(y * rect->w) + x];
            if (color.color == TRANSPARENCY) continue;

            uint16_t screen_x = dest_x + x;
            uint16_t screen_y = dest_y + y;
            uint16_t index = (screen_y * width) + screen_x;

            // g_run.tileCache.frameBuffer.frameBuffer[index] = Pico_SwapBytes(color);
            g_ramState.framebuffer.frameBuffer[index] = SetColorByte(color);
        }
    }
}


//TODO:
void DrawTileKeyed(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data)
{
    for (uint16_t row = 0; row < h; row++)
    {
        for (uint16_t col = 0; col < w; col++)
        {
            if (data[row * w + col] != TRANSPARENCY)
            {
                // printf("#");
                uint16_t c = data[row * w + col];
                Draw16(x + col, y + row, 1, 1, &c);
            }
            else
            {
                // printf(" ");
            }
        }
        // printf("\n");
    }
}


//TODO:
void SetBuffer(uint16_t length, uint16_t* p, Color rgb565)
{
    SetRectColor(length, p, rgb565);
}

//TODO:
void SetBufferColor(uint16_t length, uint16_t* p, Color rgb565)
{
    SetRectColor(length, p, rgb565);
}

//TODO:
void SetFrameBuffer(Color rgb565)
{
    SetRectColor(BUFFER_SIZE_2BYTES, g_ramState.framebuffer.frameBuffer, rgb565);
}

//TODO:
/**********************************************************************************************************************/
/**  fills the frame buffer with the given colour value
**********************************************************************************************************************/
void SetFrameBufferColor(Color rgb565)
{
    SetRectColor(BUFFER_SIZE_2BYTES, g_ramState.framebuffer.frameBuffer, rgb565);
}

//TODO:
void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565)
{
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;

    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    DrawRect(x, y, w, h, rgb565);
}

//TODO:
void FillRectColor(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565)
{
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;

    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    DEBUG("FillRectColor");
    DrawRect(x, y, w, h, rgb565);
}

void FillScreen(Color rgb565)
{
    FillRectColor(0, 0, TFT_W, TFT_H, rgb565);
}

void FillScreenColor(Color rgb565)
{
    FillRectColor(0, 0, TFT_W, TFT_H, rgb565);
}


/**********************************************************************************************************************/
/**  TEMP - for testing animations
**********************************************************************************************************************/
void TestAnimation(FrameBuffer* f, Rect_16* r, Color* color1)
{
    // FrameBuffer f1 = {.x = 0, .y = 0, .w = 50, .h = 50};
    // Rect_16 r1 = {.x = 0, .y = 0, .w = 50, .h = 50};
    // Color color11 = {.color = 0xFFFF};

    SetFrameBuffer((Color){.color = 0xd6fa}); // gray
    uint16_t size = r->w * r->h;
    uint16_t p[size];

    DrawToBuffer(f, p, r);
    SetRectColor(size, p, *color1); //blu
    DrawBuffer(*f);


    SDL_RenderPresent(g_ramState.renderer);
    SDL_Delay(20);
}


void EndFrame(void)
{
    SDL_RenderPresent(g_ramState.renderer);
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
        .Draw16 = Draw16,
        .SetBuffer = SetBuffer,
        .SetBufferColor = SetBufferColor,
        .SetFrameBuffer = SetFrameBuffer,
        .SetFrameBufferColor = SetFrameBufferColor,
        .FillRect = FillRect,
        .FillRectColor = FillRectColor,
        .FillScreen = FillScreen,
        .FillScreenColor = FillScreenColor,
        .EndFrame = EndFrame,
        .TestAnimation = TestAnimation,
    };

    return graphicsInterface;
}


void TestColors()
{
    uint16_t width = SCREEN_H / 8;
    FrameBuffer f = {.x = 0, .y = 0, .w = width, .h = SCREEN_H};

    uint16_t colors[8] =
    {
        0xFFFF, //White
        0xFFE0, //Yellow
        0x07FF, //Cyan
        0x0400, //Green
        0xF81F, //Magenta
        0xF800, //Red
        0x001F, //Blue
        0x0000, //Black
    };


    for (uint8_t i = 0; i < 8; i++)
    {
        Color c = {.color = colors[i]};
        FillRectColor(f.x, f.y, f.w, f.h, c);
        f.x += width;
    }
}
