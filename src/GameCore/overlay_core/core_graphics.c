//
// Created by nathanial on 4/11/26.
//
#include "core_graphics.h"

#include <stdio.h>

#include "types.h"
#include "enums.h"

#include "lib_decl.h"
#include "lib_types.h"
#include "lib_constants.h"
#include "lib_memory.h"

#include "core_menu.h"
#include "core_memory_access.h"
#include "core_ram.h"
#include "core_tiles.h"


/**********************************************************************************************************************/
/**  Blit the given tile id to the given screen coords
**********************************************************************************************************************/
// void DrawChar(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id)
// {
//     uint16_t px = (uint16_t)(screen_tx * TILE_W);
//     uint16_t py = (uint16_t)(screen_ty * TILE_H);
//
//     g_map.tileCache.tile_id = tile_id;
//     Flash_GetBiomeTile(memory, &g_map.tileCache.tileCache, g_core.biome, tile_id);
//     CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.tilePixels.pixels, g_map.tileCache.tileCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.tileCache.fg), Flash_GetColor(memory, g_map.tileCache.tileCache.bg));
//     graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.tilePixels.pixels);
// }


/**********************************************************************************************************************/
/**  copies text pixel data of the given char array into the buffer then draws the buffer at the given screen position
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t PrintLineStr(GraphicsInterface graphics, MemoryInterface memory, uint16_t x, uint16_t y, FontSize fontSize, uint8_t maxChars, const char* textLine, bool indent)
{
    uint8_t text_size;
    uint8_t char_idx = 0;
    uint8_t c = CH_NONE;
    text_size = TEXT_W;

    if (indent)
        x += text_size;

    while (textLine[char_idx])
        char_idx++;

    maxChars = char_idx;
    char_idx = 0;

    Color color = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    graphics.SetFrameBuffer(color); // gray
    FrameBuffer frameBuffer = {x, y, maxChars * text_size, text_size, color.color};

    while (textLine[char_idx] && char_idx < maxChars)
    {
        char nc = textLine[char_idx] - FONT_OFFSET;
        if (c != nc)
        {
            c = nc;
            CharFromGlyph1bpp(memory, g_core.buffer, g_core.tile.pixels, c, fontSize, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        }

        uint16_t char_pos = (char_idx * text_size);
        Rect_16 rect = {char_pos, 0, text_size, text_size};

        graphics.DrawToBuffer(&frameBuffer, g_core.tile.pixels, &rect);
        char_idx++;
    }

    graphics.DrawBuffer(frameBuffer);
    return text_size;
}

/**********************************************************************************************************************/
/**  Check whether cursor should be drawn
**********************************************************************************************************************/
SET_MEMORY(".core")
bool HideCursor()
{
    if (g_core.menu.displayedMenu == MINIMAP)
    {
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/**  Draw menu cursor at the cached cursor location
**********************************************************************************************************************/
SET_MEMORY(".core")
void DrawCursor(GraphicsInterface graphics, MemoryInterface memory)
{
    if (HideCursor()) return;

    const uint16_t x = g_core.menu.x * TEXT_W;
    const uint16_t list_y = g_core.menu.y * TEXT_H;
    const uint16_t erase_x = x + (g_core.menu.eraseSel.x * g_core.menu.w * TEXT_W);
    Color battler_menu_color = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    graphics.FillRect(erase_x, list_y + (g_core.menu.eraseSel.y * (TEXT_W + g_core.menu.lineHeight)), TEXT_W, TEXT_W, battler_menu_color);


    Glyph buffer = {0};
    uint8_t sel_y = GetSelectorY();
    uint8_t sel_x = GetSelectorX();
    const FontSize font_size = g_core.settings.fontSize;
    if (font_size == FONT8x8)
    {
        Glyph8x8 character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(x + (sel_x * g_core.menu.w * TEXT_W), list_y + (sel_y * (TEXT_W + g_core.menu.lineHeight)), TEXT_W, TEXT_W, character.pixels);
    }
    else
    {
        Glyph character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(x + (sel_x * g_core.menu.w * TEXT_W), list_y + (sel_y * (TEXT_W + g_core.menu.lineHeight)), TEXT_W, TEXT_W, character.pixels);
    }
}


/**********************************************************************************************************************/
/**     Clears the Buffer to gray
 *      Draws a multitile sprite to a buffer one TILE_W x TILE_H tile at a tile
 *      Draws the buffer to the screen
**********************************************************************************************************************/
SET_MEMORY(".core")
FrameBuffer DrawBattlerToBuffer(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front)
{
    uint32_t byte_offset = 0; // starts at beginning of this sprite's data
    uint8_t tile_counter = 0;

    uint16_t pixel_w = BATTLER_TILES_W * TILE_W;
    uint16_t pixel_h = BATTLER_TILES_H * TILE_H;


    FrameBuffer f = {screen_x, screen_y, pixel_w, pixel_h};
    graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

    while (tile_counter < BATTLER_TILES_H * BATTLER_TILES_W)
    {
        // DEBUG("while (tile_counter < BATTLER_TILES_H * BATTLER_TILES_W)");
        uint16_t row = tile_counter / BATTLER_TILES_H;
        uint16_t col = tile_counter % BATTLER_TILES_W;

        uint8_t tile_idx = row * BATTLER_TILES_W + col;
        uint8_t mask_byte = tile_idx / 8;
        uint8_t mask_bit = tile_idx % 8;
        if ((layout->emptyIndexes[mask_byte] & (1u << mask_bit)) == 0)
        // Check if this tile position is suppposed to be drawn
        {
            tile_counter++;
            continue;
        }

        int16_t draw_x = col * TILE_W;
        int16_t draw_y = row * TILE_H;

        const uint32_t index = layout->idx + byte_offset;
        // Flash_GetSprite(memory, g_core.spriteCache.bytes, index, TILE_W * TILE_H, type, front);
        Flash_GetSprite_64(memory, g_core.spriteCache.bytes, index, TILE_W * TILE_H, type, front);

        // Decompress and get how many compressed bytes were used
        byte_offset += Expand4bppPackedToByte(memory, g_core.spriteCache.bytes, layout->palette, g_core.tile.pixels, TILE_W);

        Rect_16 r = {draw_x, draw_y, TILE_W, TILE_H};
        graphics.DrawToBuffer(&f, g_core.tile.pixels, &r);
        tile_counter++;
    }

    return f;
}


/**********************************************************************************************************************/
/**     Clears the Buffer to gray
 *      Draws a multitile sprite to a buffer one TILE_W x TILE_H tile at a tile
 *      Draws the buffer to the screen
**********************************************************************************************************************/
SET_MEMORY(".core")
void DrawBattler(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const SpriteLayout* layout, ObjectsTypes type, bool front)
{
    FrameBuffer f = DrawBattlerToBuffer(graphics, memory, screen_x, screen_y, layout, type, front);
    graphics.DrawBuffer(f);
}
