//
// Created by nathanial on 4/11/26.
//
#include "core_graphics.h"

#include "core_memory_access.h"
#include "lib_debugging.h"
#include "lib_decl.h"
#include "lib_types.h"
#include "lib_constants.h"

#include "core_menu.h"
#include "core_ram.h"
#include "core_tiles.h"
#include "map_memory_access.h"


#include "common/types.h"
#include "common/enums.h"
#include "map_ram.h"


/**********************************************************************************************************************/
/**  Blit the given tile id to the given screen coords
**********************************************************************************************************************/
void DrawChar(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id)
{
    uint16_t px = (uint16_t)(screen_tx * TILE_W);
    uint16_t py = (uint16_t)(screen_ty * TILE_H);

    g_map.tileCache.tile_id = tile_id;
    Flash_GetBiomeTile(memory, &g_map.tileCache.tileCache, g_core.biome, tile_id);
    CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.tilePixels.pixels, g_map.tileCache.tileCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.tileCache.fg), Flash_GetColor(memory, g_map.tileCache.tileCache.bg));
    graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.tilePixels.pixels);
}


/**********************************************************************************************************************/
/**  copies text pixel data of the given char array into the buffer then draws the buffer at the given screen position
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t PrintLineStr(GraphicsInterface graphics, MemoryInterface memory, uint16_t x, uint16_t y, FontSize fontSize, uint8_t maxChars, const char* textLine, bool indent)
{
    uint8_t text_size;
    uint8_t char_idx = 0;
    Glyph16x16 glyph;
    uint8_t c = CH_NONE;

    if (fontSize == FONT8x8)
        text_size = TEXT_W;
    else
        text_size = TILE_W;

    if (indent)
        x += text_size;

    while (textLine[char_idx])
        char_idx++;

    maxChars = char_idx;
    char_idx = 0;

    graphics.SetFrameBuffer(0xd6fa); // gray
    FrameBuffer frameBuffer = {x, y, maxChars * text_size, text_size, 0xd6fa};

    Glyph buffer = {0};

    while (textLine[char_idx] && char_idx < maxChars)
    {
        char nc = textLine[char_idx] - FONT_OFFSET;
        if (c != nc)
        {
            c = nc;
            CharFromGlyph1bpp(memory, buffer, glyph.pixels, c, fontSize, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        }

        uint16_t char_pos = (char_idx * text_size);
        Rect_16 rect = {char_pos, 0, text_size, text_size};

        graphics.DrawToBuffer(frameBuffer, glyph.pixels, rect);
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

    const uint16_t x = g_core.menu.x * TILE_W;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t list_y = g_core.menu.y * size;

    uint8_t sel_y = GetSelectorY();
    Glyph buffer = {0};

    graphics.FillRect(x, list_y + (g_core.menu.eraseSel.y * (size + g_core.menu.lineHeight)), size, size, g_core.menu.colorCache);

    if (font_size == FONT8x8)
    {
        Glyph8x8 character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(x, list_y + (sel_y * (size + g_core.menu.lineHeight)), size, size, character.pixels);
    }
    else
    {
        Glyph16x16 character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(x, list_y + (sel_y * (size + g_core.menu.lineHeight)), size, size, character.pixels);
    }
}


SET_MEMORY(".core.data")
static const char gg[] = "%lu\n";
SET_MEMORY(".core.data")
static const char gag[] = "%s";
SET_MEMORY(".core.data")
static const char hh[] = "%08b ";
SET_MEMORY(".core.data")
static const char hd[] = "0x%2x, ";
SET_MEMORY(".core.data")
static const char hf[] = "----------------\n";


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

    memory.Print(gg, type);
    memory.Print(gg, front);
    memory.Print(gg, layout->idx);
    memory.Print(hf);


    FrameBuffer f = {screen_x, screen_y, pixel_w, pixel_h};
    graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

    while (tile_counter < BATTLER_TILES_H * BATTLER_TILES_W)
    {
        // DEBUG("while (tile_counter < BATTLER_TILES_H * BATTLER_TILES_W)");
        int row = tile_counter / BATTLER_TILES_H;
        int col = tile_counter % BATTLER_TILES_W;


        uint8_t tile_idx = row * BATTLER_TILES_W + col;
        uint8_t mask_byte = tile_idx / 8;
        uint8_t mask_bit = tile_idx % 8;
        // Check if this tile position is suppposed to be drawn
        if ((layout->emptyIndexes[mask_byte] & (1u << mask_bit)) == 0)
        {
            tile_counter++;
            continue;
        }

        memory.Print(gg, tile_counter);

        int draw_x = col * TILE_W;
        int draw_y = row * TILE_H;


        memory.Print(gg, layout->idx);
        const uint32_t index = layout->idx + byte_offset;
        memory.Print(hf);

        Flash_GetSprite(memory, g_map.spriteCache, index, 256, type, front);

        for (uint16_t i = 0; i < 256; i++)
            memory.Print(hd, g_map.spriteCache[i]);
        memory.Print(hf);

        // Decompress and get how many compressed bytes were used
        byte_offset += Expand4bppPackedToByte(memory, g_map.spriteCache, layout->palette, g_map.tile.pixels);

        Rect_16 r = {draw_x, draw_y, TILE_W, TILE_H};
        graphics.DrawToBuffer(f, g_map.tile.pixels, r);
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
