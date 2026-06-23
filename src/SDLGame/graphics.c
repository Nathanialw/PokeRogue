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
void Draw16(Rect_16* clip_rect, Rect_16* render_rect, const uint16_t* data);
void DrawToBufferImage(const FrameBuffer* frameBuffer, const uint16_t* pixels, const Rect_16* rect);

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


void ConvertRGB565ToRGBA8888(uint16_t w, uint16_t h, const uint16_t* data)
{
    uint32_t size = w * h;
    for (uint32_t i = 0; i < size; i++)
    {
        if (data[i] == TRANSPARENCY)
        {
            g_ramState.pixels.array[i] = (SDL_Color){0, 0, 0, 0};
        }
        else
        {
            uint16_t pixel = data[i];

            uint8_t red = (pixel >> 11) & 0x1F;
            uint8_t green = (pixel >> 5) & 0x3F;
            uint8_t blue = pixel & 0x1F;

            red = (red << 3) | (red >> 2);
            green = (green << 2) | (green >> 4);
            blue = (blue << 3) | (blue >> 2);

            SDL_Color c = {.r = red, .g = green, .b = blue, .a = 255};
            g_ramState.pixels.array[i] = c;
        }
    }
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
    if ((w * h) < (SCREEN_H * SCREEN_W * 2))
    {
        uint16_t c = rgb565.color;

        uint8_t r5 = (c >> 11) & 0x1F;
        uint8_t g6 = (c >> 5) & 0x3F;
        uint8_t b5 = c & 0x1F;

        uint8_t red = (r5 << 3) | (r5 >> 2);
        uint8_t green = (g6 << 2) | (g6 >> 4);
        uint8_t blue = (b5 << 3) | (b5 >> 2);

        SDL_SetRenderDrawColor(g_ramState.renderer, red, green, blue, 255);
        SDL_FRect r = {x, y, w, h};
        SDL_RenderFillRect(g_ramState.renderer, &r);
        SDL_FlushRenderer(g_ramState.renderer);
        SDL_SetRenderDrawColor(g_ramState.renderer, 255, 255, 255, 255);
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

    ConvertRGB565ToRGBA8888(w / 2, h, (uint16_t*)data);

    SDL_Rect rect = {x, y, w, h};
    SDL_UpdateTexture(g_ramState.screen, &rect, g_ramState.pixels.array, w * sizeof(SDL_Color));
}

void Draw16(Rect_16* clip_rect, Rect_16* render_rect, const uint16_t* data)
{
    if ((render_rect->w == 0 || render_rect->h == 0) || (render_rect->x >= TFT_W || render_rect->y >= TFT_H))
        return;
    if (render_rect->x + render_rect->w > TFT_W) render_rect->w = TFT_W - render_rect->x;
    if (render_rect->y + render_rect->h > TFT_H) render_rect->h = TFT_H - render_rect->y;

    ConvertRGB565ToRGBA8888(render_rect->w, render_rect->h, data);
    SDL_Rect rect = {render_rect->x, render_rect->y, render_rect->w, render_rect->h};

    if (clip_rect)
    {
        SDL_Color c = {.r = 0, .g = 0, .b = 155, .a = 125};
        SDL_Color c1 = {.r = 123, .g = 0, .b = 0, .a = 125};
        for (uint32_t i = 0; i < clip_rect->h * clip_rect->w; i++)
            g_ramState.pixels2.array[i] = c1;

        SDL_Color* dst = g_ramState.pixels2.array; // .colors is SDL_Color[]
        SDL_Color* src = g_ramState.pixels.array;

        uint32_t pixel_count = 0;
        uint32_t src_index = 0; // start at the beginning
        for (uint32_t i = 0; i < clip_rect->h * clip_rect->w; i++)
        {
            dst[i] = src[src_index];
            src_index++;
            pixel_count++;

            // If we just finished a row (i.e., the next i would be the start of a new row)
            if ((i % clip_rect->w) == clip_rect->w - 1)
            {
                uint32_t jump_value = (clip_rect->h - clip_rect->w); // skip the unused part of the source row
                src_index += jump_value;
            }
        }

        int pitch = render_rect->w * sizeof(SDL_Color);

        DEBUG("pixel_count %d", pixel_count);
        if (!SDL_UpdateTexture(g_ramState.current_target, &rect, g_ramState.pixels2.array, pitch))
            SDL_Log("Failed to update texture: %s", SDL_GetError());
    }
    else
    {
        if (!SDL_UpdateTexture(g_ramState.current_target, &rect, g_ramState.pixels.array, render_rect->w * sizeof(SDL_Color)))
            SDL_Log("Failed to update texture: %s", SDL_GetError());
    }
}

void ClearBuffer(void)
{
    Color c = {.color = 0xFFFF};
    SetRectColor(BUFFER_SIZE_2BYTES, g_ramState.framebuffer.frameBuffer, c);
}

void DrawBuffer(const FrameBuffer f, Rect_16* clip_rect)
{
    Rect_16 render_rect = {.x = f.x, .y = f.y, .w = f.w, .h = f.h};
    Draw16(clip_rect, &render_rect, g_ramState.framebuffer.frameBuffer);
}

void DrawBufferImage(const FrameBuffer f, Rect_16* clip_rect)
{
    SDL_FRect render_rect = {.x = f.x, .y = f.y, .w = f.w, .h = f.h};
    const SDL_FRect sdl_clip_rect = {.x = clip_rect->x, .y = clip_rect->y, .w = clip_rect->w, .h = clip_rect->h};
    SDL_RenderTexture(g_ramState.renderer, g_ramState.pixel_buffer, &sdl_clip_rect, &render_rect);
}

void DrawToBufferImage(const FrameBuffer* frameBuffer, const uint16_t* pixels, const Rect_16* rect)
{
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.pixel_buffer);

    SDL_Rect sdl_rect = {frameBuffer->x, frameBuffer->y, frameBuffer->w, frameBuffer->h};

    if (!pixels)
        pixels = g_ramState.framebuffer.frameBuffer;

    ConvertRGB565ToRGBA8888(sdl_rect.w, sdl_rect.h, pixels);

    if (!SDL_UpdateTexture(g_ramState.pixel_buffer, &sdl_rect, g_ramState.pixels.array, sdl_rect.w * sizeof(SDL_Color)))
        SDL_Log("Failed to update texture: %s", SDL_GetError());

    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.screen);
    g_ramState.current_target = g_ramState.screen;
}

void DrawSpriteTile(const FrameBuffer f, const uint8_t* sprite)
{
    Draw(f.x, f.y, f.w, f.h, sprite);
}

void DrawToBuffer(const FrameBuffer* frameBuffer, const uint16_t* pixels, const Rect_16* rect)
{
    uint16_t width = frameBuffer->w;

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
            uint32_t index = (screen_y * width) + screen_x;

            g_ramState.framebuffer.frameBuffer[index] = SetColorByte(color);
        }
    }
}


//TODO:
void DrawTileKeyed(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data)
{
    //will add caching later after this is working
    ConvertRGB565ToRGBA8888(w, h, data);

    // SDL_FRect testArea = {x, y, w, h};   // same as your tile destination
    // SDL_SetRenderDrawColor(g_ramState.renderer, 255, 0, 0, 255); // opaque red
    // SDL_RenderFillRect(g_ramState.renderer, &testArea);

    SDL_Texture* spriteTex = SDL_CreateTexture(g_ramState.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, w, h);
    SDL_UpdateTexture(spriteTex, NULL, g_ramState.pixels.array, w * sizeof(SDL_Color));
    SDL_SetTextureBlendMode(spriteTex, SDL_BLENDMODE_BLEND);

    // Draw onto the main canvas
    SDL_FRect dest = {x, y, w, h};
    SDL_RenderTexture(g_ramState.renderer, spriteTex, NULL, &dest);
    SDL_DestroyTexture(spriteTex);
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

void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color rgb565)
{
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;

    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    DrawRect(x, y, w, h, rgb565);
}

void DrawRectOutline(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r, Color rgb565)
{
    if (r == 0) return;
    if ((w == 0 || h == 0) || (x >= TFT_W || y >= TFT_H))
        return;

    if (x + w > TFT_W) w = TFT_W - x;
    if (y + h > TFT_H) h = TFT_H - y;

    if ((w * h) < (SCREEN_H * SCREEN_W * 2))
    {
        uint16_t c = rgb565.color;

        uint8_t r5 = (c >> 11) & 0x1F;
        uint8_t g6 = (c >> 5) & 0x3F;
        uint8_t b5 = c & 0x1F;

        uint8_t red = (r5 << 3) | (r5 >> 2);
        uint8_t green = (g6 << 2) | (g6 >> 4);
        uint8_t blue = (b5 << 3) | (b5 >> 2);

        while (1)
        {
            r--;
            SDL_SetRenderDrawColor(g_ramState.renderer, red, green, blue, 255);
            SDL_FRect rect = {x + r, y + r, w - (r * 2), h - (r * 2)};
            SDL_RenderRect(g_ramState.renderer, &rect);
            SDL_FlushRenderer(g_ramState.renderer);
            SDL_SetRenderDrawColor(g_ramState.renderer, 255, 255, 255, 255);
            if (r == 0) break;
        }
    }
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
    // DrawBuffer(*f);


    SDL_RenderPresent(g_ramState.renderer);
    SDL_Delay(20);
}


void UpdateDrawAreas(void)
{
    int w, h;
    SDL_GetWindowSize(g_ramState.window, &w, &h);
    float main_h = (float)h; // - ((float)h * 0.1f); //0.2f is the text area for description, set as a const when it is fleshed out

    if (w > h)
    {
        float main_x = (w - main_h) / 2.0f;
        float wing_w = ((w - main_h) / 2.0f);
        float left_x = 0.0f;
        float right_x = main_x + main_h;

        //TODO enforce a minimum size and maximum size for the text on the wings is always legible
        float ratio = (float)SCREEN_W / (float)h;
        float clip_h = (float)h * ratio;
        float clip_wing_w = wing_w * ratio;

        g_ramState.display_rect_main = (SDL_FRect){main_x, 0.0f, main_h, main_h};
        g_ramState.display_rect_left = (SDL_FRect){left_x, 0.0f, wing_w, h};
        g_ramState.display_rect_right = (SDL_FRect){right_x, 0.0f, wing_w, h};
        // g_ramState.display_rect_text = (SDL_FRect){main_x, main_h, main_h, h - main_h};

        //scale clip h when it exceeds the texture h
        if (h > SCREEN_H)
        {
            g_ramState.scale = (float)SCREEN_H / (float)h;
            wing_w *= g_ramState.scale;
            DEBUG("scale: %f", g_ramState.scale);
        }

        g_ramState.clip_rect_main = (SDL_FRect){0.0f, 0.0f, main_h, main_h};
        g_ramState.clip_rect_left = (SDL_FRect){0.0f, 0.0f, clip_wing_w, clip_h};
        g_ramState.clip_rect_right = (SDL_FRect){0.0f, 0.0f, clip_wing_w, clip_h};
        // g_ramState.clip_rect_text = (SDL_FRect){0.0f, 0.0f, main_h, h - main_h};
    }
    else
    {
        g_ramState.display_rect_main = (SDL_FRect){0, 0, w, w};
        g_ramState.clip_rect_main = (SDL_FRect){0, 0, w, w};
        g_ramState.display_rect_text = (SDL_FRect){0, w, w, h - w};
        g_ramState.clip_rect_text = (SDL_FRect){0, 0, w, h - w};
        g_ramState.display_rect_left.w = 0.0f;
        g_ramState.display_rect_left.h = 0.0f;
        g_ramState.display_rect_right.w = 0.0f;
        g_ramState.display_rect_right.h = 0.0f;

        g_ramState.clip_rect_left = (SDL_FRect){0.0f, 0.0f, g_ramState.clip_rect_left.w, g_ramState.clip_rect_left.h};
        g_ramState.clip_rect_right = (SDL_FRect){0.0f, 0.0f, g_ramState.clip_rect_right.w, g_ramState.clip_rect_right.h};
    }
}

void EndFrame(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, NULL); // set to window
    SDL_RenderClear(g_ramState.renderer);
    SDL_RenderTexture(g_ramState.renderer, g_ramState.screen, NULL, &g_ramState.display_rect_main);
    SDL_RenderTexture(g_ramState.renderer, g_ramState.right_wing, &g_ramState.clip_rect_right, &g_ramState.display_rect_right);
    SDL_RenderTexture(g_ramState.renderer, g_ramState.left_wing, &g_ramState.clip_rect_left, &g_ramState.display_rect_left);
    // SDL_RenderTexture(g_ramState.renderer, g_ramState.text, &g_ramState.clip_rect_text, &g_ramState.display_rect_text);
    SDL_RenderPresent(g_ramState.renderer);
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.screen); // set to buffer
    g_ramState.current_target = g_ramState.screen;
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_EVENT_FIRST, SDL_EVENT_LAST);
}

void RenderMain(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, NULL); // set to window
    SDL_RenderClear(g_ramState.renderer);
    SDL_RenderTexture(g_ramState.renderer, g_ramState.screen, NULL, NULL);
    SDL_RenderPresent(g_ramState.renderer);
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.screen); // set to buffer
    g_ramState.current_target = g_ramState.screen;
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_EVENT_FIRST, SDL_EVENT_LAST);
}

void (DrawToMain)(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.screen);
    g_ramState.current_target = g_ramState.screen;
}

void (DrawToLeft)(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.left_wing);
    g_ramState.current_target = g_ramState.left_wing;
}

void (DrawToRight)(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.right_wing);
    g_ramState.current_target = g_ramState.right_wing;
}

void (DrawToText)(void)
{
    SDL_SetRenderTarget(g_ramState.renderer, g_ramState.text);
    g_ramState.current_target = g_ramState.text;
}

Rect_16 (GetMainRect)(void)
{
    Rect_16 rect = {g_ramState.clip_rect_main.x, g_ramState.clip_rect_main.y, g_ramState.clip_rect_main.w, g_ramState.clip_rect_main.h};
    return rect;
}

Rect_16 (GetLeftRect)(void)
{
    Rect_16 rect = {g_ramState.clip_rect_left.x, g_ramState.clip_rect_left.y, g_ramState.clip_rect_left.w, g_ramState.clip_rect_left.h};
    return rect;
}

Rect_16 (GetRightRect)(void)
{
    Rect_16 rect = {g_ramState.clip_rect_right.x, g_ramState.clip_rect_right.y, g_ramState.clip_rect_right.w, g_ramState.clip_rect_right.h};
    return rect;
}

Rect_16 (GetTextRect)(void)
{
    Rect_16 rect = {g_ramState.clip_rect_text.x, g_ramState.clip_rect_text.y, g_ramState.clip_rect_text.w, g_ramState.clip_rect_text.h};
    return rect;
}

Rect_16 (GetMainScreenRect)(void)
{
    Rect_16 rect = {g_ramState.display_rect_main.x, g_ramState.display_rect_main.y, g_ramState.display_rect_main.w, g_ramState.display_rect_main.h};
    return rect;
}

Rect_16 (GetLeftScreenRect)(void)
{
    Rect_16 rect = {g_ramState.display_rect_left.x, g_ramState.display_rect_left.y, g_ramState.display_rect_left.w, g_ramState.display_rect_left.h};
    return rect;
}

Rect_16 (GetRightScreenRect)(void)
{
    Rect_16 rect = {g_ramState.display_rect_right.x, g_ramState.display_rect_right.y, g_ramState.display_rect_right.w, g_ramState.display_rect_right.h};
    return rect;
}

Rect_16 (GetTextScreenRect)(void)
{
    Rect_16 rect = {g_ramState.display_rect_text.x, g_ramState.display_rect_text.y, g_ramState.display_rect_text.w, g_ramState.display_rect_text.h};
    return rect;
}

float (GetScale)(void)
{
    return g_ramState.scale;
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
        .DrawBufferImage = DrawBufferImage,
        .DrawSprite = DrawSpriteTile,
        .DrawToBuffer = DrawToBuffer,
        .DrawToBufferImage = DrawToBufferImage,
        .DrawTileKeyed = DrawTileKeyed,
        .Draw = Draw,
        .Draw16 = Draw16,
        .SetBuffer = SetBuffer,
        .SetBufferColor = SetBufferColor,
        .SetFrameBuffer = SetFrameBuffer,
        .SetFrameBufferColor = SetFrameBufferColor,
        .FillRect = FillRect,
        .DrawRectOutline = DrawRectOutline,
        .FillRectColor = FillRectColor,
        .FillScreen = FillScreen,
        .FillScreenColor = FillScreenColor,
        .EndFrame = EndFrame,
        .TestAnimation = TestAnimation,
        .DrawToMain = DrawToMain,
        .DrawToLeft = DrawToLeft,
        .DrawToRight = DrawToRight,
        .DrawToText = DrawToText,
        .GetMainRect = GetMainRect,
        .GetLeftRect = GetLeftRect,
        .GetRightRect = GetRightRect,
        .GetTextRect = GetTextRect,
        .UpdateDrawAreas = UpdateDrawAreas,
        .GetMainScreenRect = GetMainScreenRect,
        .GetLeftScreenRect = GetLeftScreenRect,
        .GetRightScreenRect = GetRightScreenRect,
        .GetTextScreenRect = GetTextScreenRect,
        .GetScale = GetScale,
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
