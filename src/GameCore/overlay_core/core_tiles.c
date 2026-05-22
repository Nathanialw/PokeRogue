//
// Created by nathanial on 2/23/26.
//
#include "lib_memory.h"

#include "core_tiles.h"
#include "core_memory_access.h"
#include "core_ram.h"

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
#define GLYPH_ROWS 16
#define GLYPH_WORDS_PER_ROW 2
#define GLYPH_WORDS16x16 (GLYPH_ROWS * GLYPH_WORDS_PER_ROW)


#define GLYPH_ROWS8x8 8
#define GLYPH_WORDS8x8 (GLYPH_ROWS8x8 * GLYPH_WORDS_PER_ROW)


#define GLYPH_ROWS96x96 96
#define GLYPH_WORDS96x96 (GLYPH_ROWS96x96 * GLYPH_ROWS96x96)   // = 576 words (9216 bits)


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
void TilesetFromGlyph1bpp(TileSet* tileset, uint16_t tile_id, uint8_t glyph_index, uint16_t fg, uint16_t bg)
{
    // uint16_t tile_base = tile_id * TILE_PIXELS;
    // uint16_t glyph_base = glyph_index * GLYPH_WORDS16x16;
    //
    // for (int y = 0; y < GLYPH_ROWS; y++)
    // {
    //     uint16_t row_mask = (g_gameFlash.spriteData.font16x16[glyph_base + y * 2] << 8) |
    //         g_gameFlash.spriteData.font16x16[glyph_base + y * 2 + 1];
    //
    //     for (int x = 0; x < TILE_W; x++)
    //     {
    //         uint16_t bit = 0x8000 >> x;
    //         (*tileset)[tile_base + y * TILE_W + x] = (row_mask & bit) ? fg : bg;
    //     }
    // }
}

/**********************************************************************************************************************/
/* saves 1bpp data into cache, applies fg and bg color for 0 and 1
*       union is a g_core.tileCache.spriteCache
*       g_core.tileCache.spriteCache.bytes uint8_t array
*       g_core.tileCache.spriteCache.glyph uint16_t array
********************************************* *************************************************************************/
SET_MEMORY(".core")
void CharFromGlyph1bpp(MemoryInterface memory, Glyph buffer, uint16_t* character, uint8_t glyph_index, FontSize fontSize, uint16_t fg, uint16_t bg)
{
    //     if (fontSize == FONT16x16)
    //     {
    //         Flash_GetFontChar16x16(memory, buffer.bytes, glyph_index);
    //
    //         for (int y = 0; y < 16; y++)
    //         {
    //             uint16_t row = buffer.glyph[y];
    //             row = (row >> 8) | (row << 8);
    //
    //             for (int x = 0; x < 16; x++)
    //             {
    // #if defined(SDL)
    //                 uint16_t bit = 0x8000 >> x;
    //                 character[y * 16 + x] = (row & bit) ? fg : bg;
    // #else
    //                 uint16_t bit = 1 << x;
    //                 character[y * 16 + x] = (row & bit) ? fg : bg;
    // #endif
    //             }
    //         }
    //         return;
    //     }

    uint8_t length = 0;
    switch (fontSize)
    {
    case FONT8x8: length = Flash_GetFontChar8x8(memory, buffer.bytes, glyph_index);
        break;
    case FONT20x20: length = Flash_GetFontChar20x20(memory, buffer.bytes, glyph_index);
        break;
    case FONT16x16: length = Flash_GetFontChar16x16(memory, buffer.bytes, glyph_index);
        break;
    default: return;
    }

    for (int y = 0; y < length; y++)
    {
        uint8_t row = buffer.bytes[y];

        for (int x = 0; x < 8; x++)
        {
            character[y * 8 + x] = (row & (1 << x)) ? fg : bg; //place unin16_t colour in the array based on bit value
        }
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
void Expand4bppPackedToRGB(const uint16_t* src, const uint16_t* pal, uint16_t* dest)
{
    int dest_idx = 0;

    for (int i = 0; i < 64; i++)
    {
        uint16_t word = src[i];

        // Because Python packed uint16 as: word = byte0 | (byte1<<8)
        // byte0 holds pixels 0,1 in (hi,lo) nibbles
        // byte1 holds pixels 2,3 in (hi,lo) nibbles
        uint8_t idx0 = (word >> 4) & 0x0F; // pixel0 = high nibble of byte0
        uint8_t idx1 = (word >> 0) & 0x0F; // pixel1 = low  nibble of byte0
        uint8_t idx2 = (word >> 12) & 0x0F; // pixel2 = high nibble of byte1
        uint8_t idx3 = (word >> 8) & 0x0F; // pixel3 = low  nibble of byte1

        dest[dest_idx++] = pal[idx0];
        dest[dest_idx++] = pal[idx1];
        dest[dest_idx++] = pal[idx2];
        dest[dest_idx++] = pal[idx3];
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t Expand4bppPackedToByte(MemoryInterface memory, const uint8_t* src, const uint16_t* pal, uint16_t* dest)
{
    uint16_t dest_idx = 0;
    uint8_t bytes_read = 0; // renamed for clarity
    const uint8_t* p = src;

    while (dest_idx < 256)
    {
        // memory.Print(aadc, dest_idx);
        uint8_t byte = *p++; // read first
        bytes_read++; // count AFTER reading

        uint8_t high = byte >> 4;
        uint8_t color_idx = byte & 0x0F;

        uint8_t count = (high == 0) ? 16 : high;

        uint16_t color = pal[color_idx];

        for (uint8_t k = 0; k < count && dest_idx < 256; k++)
        {
            // memory.Print(aavc, k, dest_idx);
            dest[dest_idx++] = color;
        }
    }

    return bytes_read;
}
