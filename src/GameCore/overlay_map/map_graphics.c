//
// Created by nathanial on 5/19/26.
//

#include "map_graphics.h"

#include "lib_constants.h"
#include "lib_memory.h"
#include "types.h"

#include "core_entities.h"
#include "core_graphics.h"
#include "core_map.h"
#include "core_memory_access.h"
#include "core_menu.h"
#include "core_ram.h"
#include "core_tiles.h"

#include "map_entities.h"
#include "map_memory_access.h"
#include "map_ram.h"
#include "map_utils.h"


/**********************************************************************************************************************/
/**  copy the given rect of the give pixel array into the given clip pixel array
**********************************************************************************************************************/
SET_MEMORY(".map")
void ClipTile(uint16_t* clip, const uint16_t* pixels, Rect_16 r)
{
    for (int y = 0; y < TILE_W; ++y)
    {
        for (int x = 0; x < TILE_H; ++x)
        {
            clip[(TILE_W * y) + x] = pixels[(TILE_H * y) + x];
        }
    }
}


SET_MEMORY(".map.data")
static const char FullRedraw_starsta[] = "gl  %d\n";
SET_MEMORY(".map.data")
static const char FullRedraw_starstb[] = "fg  %d\n";
SET_MEMORY(".map.data")
static const char FullRedraw_starstc[] = "bg  %d\n";
SET_MEMORY(".map.data")
static const char FullRedraw_starstd[] = "hex 0x%02x\n";
/**********************************************************************************************************************/
/**  Blit the given tile id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawTile(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id)
{
    uint16_t px = (uint16_t)(screen_tx * TILE_W);
    uint16_t py = (uint16_t)(screen_ty * TILE_H);

    g_map.tileCache.tile_id = tile_id;
    Flash_GetBiomeTile(memory, &g_map.tileCache.tileCache, g_core.biome, tile_id);
    CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.tilePixels.pixels, g_map.tileCache.tileCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.tileCache.fg), Flash_GetColor(memory, g_map.tileCache.tileCache.bg));
    graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.tilePixels.pixels);
}

/**********************************************************************************************************************/
/**  Blit the given creature id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawSprite(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, Creature sprite_id, ObjectsTypes type)
{
    uint16_t px = (uint16_t)(screen_tx * TILE_W);
    uint16_t py = (uint16_t)(screen_ty * TILE_H);

    g_map.tileCache.sprite_id = sprite_id;
    Flash_GetSpriteMetadata(memory, &g_map.tileCache.entityCache, type, sprite_id);
    CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.spritePixels.pixels, g_map.tileCache.entityCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.entityCache.fg), Flash_GetColor(memory, PAL_KEY));
    graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.spritePixels.pixels);
}

/**********************************************************************************************************************/
/**  Checks cache
 *  Updates cache
 *  Blit the given tile id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawTileCached(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t tile_id)
{
    uint16_t px = (uint16_t)(screen_tx * TILE_W);
    uint16_t py = (uint16_t)(screen_ty * TILE_H);

    if (g_map.tileCache.tile_id != tile_id)
    {
        g_map.tileCache.tile_id = tile_id;
        Flash_GetBiomeTile(memory, &g_map.tileCache.tileCache, g_core.biome, tile_id);
        CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.tilePixels.pixels, g_map.tileCache.tileCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.tileCache.fg), Flash_GetColor(memory, g_map.tileCache.tileCache.bg));
    }
    graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.tilePixels.pixels);
}

/**********************************************************************************************************************/
/**  Checks cache
 *  Updates cache
 *  Blit the given creature id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawSpriteCached(GraphicsInterface graphics, MemoryInterface memory, uint8_t screen_tx, uint8_t screen_ty, uint8_t sprite_id, ObjectsTypes type)
{
    uint16_t px = (uint16_t)(screen_tx * TILE_W);
    uint16_t py = (uint16_t)(screen_ty * TILE_H);

    if (g_map.tileCache.sprite_id != sprite_id)
    {
        g_map.tileCache.sprite_id = sprite_id;
        Flash_GetSpriteMetadata(memory, &g_map.tileCache.entityCache, type, sprite_id);
        CharFromGlyph1bpp(memory, g_map.tileCache.spriteCache, g_map.tileCache.spritePixels.pixels, g_map.tileCache.entityCache.glyph_index, FONT16x16, Flash_GetColor(memory, g_map.tileCache.entityCache.fg), Flash_GetColor(memory, PAL_KEY));
    }

    graphics.DrawTileKeyed(px, py, TILE_W, TILE_H, g_map.tileCache.spritePixels.pixels);
}

/**********************************************************************************************************************/
/**  sorts units into the order they are drawn into the partial frame buffer for the minimap
**********************************************************************************************************************/
SET_MEMORY(".map")
void OrderUnitsByBufferLine(GraphicsInterface graphics, EntityId* units, uint8_t* meta)
{
    for (uint16_t id = 0; id < ENTITY_COUNT; ++id)
    {
        if (!GetBit(g_core.creatures.onMap, id)) continue;
        Position pos = g_core.creatures.position[id];
        uint8_t row = pos.y / BUFFER_W;

        uint16_t cursor = 0;
        for (uint8_t i = 0; i <= row; i++)
            cursor += meta[i];

        EntityId cache1 = units[cursor];
        units[cursor] = id;
        meta[row]++;

        for (uint16_t i = cursor + 1; i < ENTITY_COUNT; i++)
        {
            if (cache1 == NO_ENTITY) break;
            EntityId cache2 = units[i];
            units[i] = cache1;
            cache1 = cache2;
        }
    }
}


/**********************************************************************************************************************/
/**  Draws each tile as a pixel on the screen
 *  colour coded
 *  draws creature position pixels on top of their tile position
**********************************************************************************************************************/
SET_MEMORY(".map.rodata")
static const uint8_t colors[16] =
{
    PAL_PEACH_SKIN,
    PAL_MEDIUM_BROWN,
    PAL_PALE_GREEN,
    PAL_GRAYISH_GREEN,
    PAL_DIRTY_YELLOW_GRN,
    PAL_BROWNISH_RED,
    PAL_LIGHT_TAN,
    PAL_GRAY_BLUE,
    PAL_DULL_ORANGE,
    PAL_DARK_BROWN,
    PAL_MUTED_GREEN,
    PAL_DARK_GRAY_GREEN,
    PAL_GRAY_BROWN,
    PAL_LIGHT_GRAY,
    PAL_TAN_BROWN,
    PAL_BRIGHT_LIGHT_GRN,
};


SET_MEMORY(".map")
void DrawMiniMap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    uint16_t screen_w = TFT_H;
    uint8_t buffer_lines = TFT_H / BUFFER_H;
    uint8_t centerOffset = 32;

    OrderUnitsByBufferLine(graphics, g_map.units, g_map.meta);

    uint16_t cursor = 0;
    uint16_t transparency = Flash_GetColor(memory, PAL_KEY);
    for (uint16_t y = 0; y < MAP_H; y += BUFFER_H)
    {
        graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        // memset(graphics.GetFrameBuffer2bytes(), Flash_GetColor(memory, PAL_DARK_GRN_BLACK), sizeof(*graphics.GetFrameBuffer2bytes()));
        cursor = (screen_w - MAP_W) / 2; //reset position
        for (uint16_t row = 0; row < BUFFER_H; row++)
        {
            uint16_t cy = y + row;
            if (cy >= MAP_H) break;
            for (uint16_t x = 0; x < MAP_W; x++)
            {
                uint16_t color = Flash_GetColor(memory, colors[GetMapTile(x, cy)]);
                if (color == transparency) continue;
                graphics.GetFrameBuffer2bytes()[cursor++] = color;
            }
            cursor += (screen_w - MAP_W);
        }

        uint16_t c = 0;
        for (uint8_t i = 0; i < y / BUFFER_H; i++) c += g_map.meta[i];

        uint8_t buffer_line = y / BUFFER_H;
        uint8_t n = g_map.meta[buffer_line];
        for (uint16_t j = c; j < c + n; j++)
        {
            uint16_t color = Flash_GetColor(memory, PAL_BRIGHT_RED);
            Position pos = g_core.creatures.position[g_map.units[j]];
            uint8_t row = pos.y - y;
            if (GetPlayerID() == g_map.units[j])
                color = Flash_GetColor(memory, PAL_DEEP_BLUE);

            graphics.GetFrameBuffer2bytes()[centerOffset + (row * (centerOffset * 2)) + (row * MAP_W) + pos.x] = color;
        }

        graphics.Draw(0, y, screen_w, BUFFER_H, graphics.GetFrameBuffer1byte());
    }
}


/**********************************************************************************************************************/
/**  Draws the player party frame
 *  Draws each creature name and their resources
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawParty(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    const uint16_t x = MAIN_MENU_X * TILE_W;
    uint8_t y = MAIN_MENU_Y * TILE_H;
    const uint16_t w = MAIN_MENU_W * TILE_W;
    const uint16_t h = MAIN_MENU_H * TILE_H;
    graphics.FillRect(x, y, w, h, Flash_GetColor(memory, PAL_LIGHT_GRAY));

    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_lines = (MAIN_MENU_H * font_size);
    const uint8_t max_chars = (((MAIN_MENU_W) * font_size) - indent) + 1;

    char border[max_chars + 1];
    memset(border, '-', max_chars);
    border[max_chars] = '\0';

    y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, border, false);
    const uint8_t list_y = y;

    uint8_t lineHeight = 0;
    uint8_t i = 0;
    while (i < MAX_PARTY_SIZE)
    {
        lineHeight = 0;
        char line[SMALL_STRINGS];
        GetMenuLine(memory, line, i);
        bool line_empty = (line[0] == '\0');
        if (line_empty || i > (max_lines)) break;


        //level
        if (GetCreatureType(g_core.player.partyID[i]) == NO_CREATURE)
        {
            PrintLineStr(graphics, memory, x, y, font_size, 3, "---", indent);
        }
        else
        {
            Int99 level = g_core.creatures.level[g_core.player.partyID[i]];
            CharStr_99 levelStr;
            GetAsChars_99(level, &levelStr, false);
            PrintLineStr(graphics, memory, x, y, font_size, 3, levelStr, indent);
        }

        y += PrintLineStr(graphics, memory, x + (3 * size), y + lineHeight, font_size, max_chars, line, indent);

        if (GetCreatureType(g_core.player.partyID[i]) == NO_CREATURE)
        {
            lineHeight += (size * 3);
            lineHeight += (size / 2);
            y += lineHeight;
            i++;
            continue;
        }

        //hunger?

        uint16_t cur = 0;
        uint16_t max = 0;
        float line_w = 0.0f;

        IntMax999 hp = g_core.creatures.hp[g_core.player.partyID[i]];
        cur = Int999GetCurrent(&hp);
        max = Int999GetMax(&hp);
        line_w = (((float)cur / (float)max) * ((float)(max_chars - 2) * (float)size));
        if (line_w > 2) line_w -= 2;
        graphics.FillRect(x + size, y + lineHeight, (max_chars - 2) * size, size, Flash_GetColor(memory, PAL_DARK_GRN_BLACK));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, ((max_chars - 2) * size) - 2, size - 2, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, (uint16_t)line_w, size - 2, Flash_GetColor(memory, PAL_EMERALD_GREEN));
        lineHeight += size;

        IntMax999 mp = g_core.creatures.mp[g_core.player.partyID[i]];
        cur = Int999GetCurrent(&mp);
        max = Int999GetMax(&mp);
        line_w = (((float)cur / (float)max) * ((float)(max_chars - 2) * (float)size));
        if (line_w > 2) line_w -= 2;
        graphics.FillRect(x + size, y + lineHeight, (max_chars - 2) * size, size, Flash_GetColor(memory, PAL_DARK_GRN_BLACK));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, ((max_chars - 2) * size) - 2, size - 2, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, (uint16_t)line_w, size - 2, Flash_GetColor(memory, PAL_ICE_BLUE));
        lineHeight += size;

        IntMax999 xp = g_core.creatures.xp[g_core.player.partyID[i]];
        cur = Int999GetCurrent(&xp);
        max = Int999GetMax(&xp);
        line_w = (((float)cur / (float)max) * ((float)(max_chars - 2) * (float)size));
        if (line_w > 2) line_w -= 2;
        graphics.FillRect(x + size, y + lineHeight, (max_chars - 2) * size, size, Flash_GetColor(memory, PAL_DARK_GRN_BLACK));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, ((max_chars - 2) * size) - 2, size - 2, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
        graphics.FillRect(x + 1 + size, y + lineHeight + 1, (uint16_t)line_w, size - 2, Flash_GetColor(memory, PAL_MEDIUM_PURPLE));

        lineHeight += size;
        lineHeight += (size / 2);
        y += lineHeight;
        i++;
    }
    g_core.menu.lineHeight = lineHeight;

    PrintLineStr(graphics, memory, x, (max_lines - 1) * size, font_size, max_chars, border, false);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_LIGHT_GRAY);
}


SET_MEMORY(".map.data")
const char str_splash_exit1[] = "Exiting splash_entry, Going to map_gen_entry\n";

SET_MEMORY(".map.data")
const char str_splash_entry2[] = "==== DRAWING MENU ====   \n";

SET_MEMORY(".map.data")
const char str_splash_exit3[] = "const char* line = GetMenuLine(i);\n";

SET_MEMORY(".map.data")
const char str_splash_entry4[] = "drawing ----   %s\n";

SET_MEMORY(".map.data")
const char str_splash_entry5[] = "fILL RECT %d %d %d %d\n";

/**********************************************************************************************************************/
/**  Draws the cached char arrays menu list to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawList(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    memory.Print(str_splash_entry2);

    const uint16_t x = MAIN_MENU_X * TILE_W;
    uint8_t y = MAIN_MENU_Y * TILE_H;
    const uint16_t w = MAIN_MENU_W * TILE_W;
    const uint16_t h = MAIN_MENU_H * TILE_H;
    graphics.FillRect(x, y, w, h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
    memory.Print(str_splash_entry5, x, y, w, h);


    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_lines = (MAIN_MENU_H * font_size);
    const uint8_t max_chars = (((MAIN_MENU_W) * font_size) - indent) + 1;

    char border[max_chars + 1];
    memset(border, '-', max_chars);
    border[max_chars] = '\0';

    y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, border, false);
    const uint8_t list_y = y;

    uint8_t i = 0;
    while (1)
    {
        memory.Print(str_splash_exit3);
        GetMenuLine(memory, g_core.menu.text[i], i);
        memory.Print(str_splash_entry4, g_core.menu.text[i]);
        bool line_empty = (g_core.menu.text[i][0] == '\0');
        if (line_empty || i > (max_lines)) break;
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, g_core.menu.text[i], indent);
        i++;
    }

    uint16_t numSpaces = (max_lines - i - 2) * size;
    PrintLineStr(graphics, memory, x, y + numSpaces, font_size, max_chars, border, false);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
}

/**********************************************************************************************************************/
/**  handles while menu selection to draw
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    if (g_core.menu.displayedMenu == g_core.menu.selectedMenu && (g_core.menu.menuScrollOffset[g_core.menu.depth].y <= 0 && !g_core.menu.forceRedraw)) return;
    g_core.menu.displayedMenu = g_core.menu.selectedMenu;
    g_core.menu.forceRedraw = false;

    if (g_core.menu.displayedMenu == MINIMAP) // draw minimap
    {
        DrawMiniMap(graphics, hardware, memory);
        return;
    }

    if (g_core.menu.displayedMenu == PARTY || g_core.menu.useOnPartyMember) //draw party
    {
        DrawParty(graphics, hardware, memory);
        return;
    }

    DrawList(graphics, hardware, memory);
}


/**********************************************************************************************************************/
/**  Draws the background panel to the screen for the "pokedex" style encyclopedias
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuLeftBG(GraphicsInterface graphics, MemoryInterface memory, const uint16_t x, uint8_t y)
{
    const uint16_t w = (VIEW_TW * TILE_W) - (MAIN_MENU_W * TILE_W);
    const uint16_t h = (VIEW_TH * TILE_H);
    graphics.FillRect(x, y, w, h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
}

/**********************************************************************************************************************/
/**  Draws the name text to the screen for the "pokedex" style encyclopedias
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuLeftName(GraphicsInterface graphics, MemoryInterface memory, const uint16_t x, uint8_t y, const char* name)
{
    const uint8_t indent = 1;
    PrintLineStr(graphics, memory, x, y, g_core.settings.fontSize, SMALL_STRINGS, name, indent);
}

/**********************************************************************************************************************/
/**  Draws the rarity and power bars to the screen for the "pokedex" style encyclopedias
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuLeftStat(GraphicsInterface graphics, MemoryInterface memory, const uint16_t x, const uint16_t x2, uint8_t y, uint8_t size, const char* power_str)
{
    const uint8_t indent = 1;

    //strength line
    float power = 115;
    float max_power = 255;
    // power
    PrintLineStr(graphics, memory, x, y, g_core.settings.fontSize, 10, power_str, indent);

    //strength bar
    float f_bar_width = power / max_power;
    uint8_t bar_width = (uint8_t)((float)(4 * size) * f_bar_width);
    graphics.FillRect(x2, y, (4 * size), size, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
    graphics.FillRect(x2, y, bar_width, size, Flash_GetColor(memory, PAL_BROWN_GREEN));
}

/**********************************************************************************************************************/
/**  Draws the borders to the screen for the "pokedex" style encyclopedias
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuBorders(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    const uint16_t x = 0;
    uint8_t y = 0;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_lines = (VIEW_TH * font_size);
    const uint8_t max_chars = (((VIEW_TW) * font_size)) + 1;

    char border[max_chars + 1];
    memset(border, '-', max_chars);
    border[max_chars] = '\0';
    PrintLineStr(graphics, memory, x, y, font_size, max_chars, border, false);
    uint16_t numSpaces = (max_lines - 1) * size;
    PrintLineStr(graphics, memory, x, y + numSpaces, font_size, max_chars, border, false);
}

/**********************************************************************************************************************/
/**  Draws the type info text to the screen for the "pokedex" style encyclopedias
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuTypes(GraphicsInterface graphics, MemoryInterface memory, const char* typeA, const char* typeB)
{
    if (!typeA || !typeB) return;

    const uint16_t x = 0;
    uint8_t y = 0;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t indent = 1;


    if (typeA)
        PrintLineStr(graphics, memory, x + (size * 10), y + (size * 18), font_size, 10, typeA, indent);
    if (typeB)
        PrintLineStr(graphics, memory, x + (size * 10), y + (size * 20) - 4, font_size, 10, typeB, indent);
}

/**********************************************************************************************************************/
/**  Draws the description text to the screen for the "pokedex" style encyclopedias
 *  Handles line breaks and word breaks
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenuDescription(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, uint16_t y, const char* desc)
{
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_chars = (VIEW_TW * font_size) + 1;
    const uint8_t indent = 1;
    const uint8_t MAX_LINES = 8;
    const uint8_t LINE_LEN = 20;

    uint8_t desc_x = 1;
    uint8_t desc_y = y;

    if (!desc) return;

    bool done = false;
    uint16_t cursor = 0;
    uint8_t lines_printed = 0;

    for (uint8_t i = 0; i < MAX_LINES; i++)
    {
        if (done) break;

        char line[LINE_LEN + 2]; // +2 for possible hyphen and null
        memset(line, ' ', LINE_LEN);
        line[LINE_LEN] = '\0';
        line[LINE_LEN + 1] = '\0';

        // Fill line
        uint8_t j = 0;
        while (j < LINE_LEN && !done)
        {
            // Skip leading spaces
            if (j == 0 && desc[cursor] == ' ')
            {
                cursor++;
                continue;
            }

            if (desc[cursor] == '\0')
            {
                done = true;
                break;
            }

            line[j] = desc[cursor];
            cursor++;
            j++;
        }

        // Word wrap/hyphenation if needed
        if (!done && j == LINE_LEN)
        {
            // First try to find a natural break (space or hyphen)
            int8_t break_pos = -1;
            for (int8_t k = LINE_LEN - 1; k >= 0; k--)
            {
                if (line[k] == ' ' || line[k] == '-')
                {
                    break_pos = k;
                    break;
                }
            }

            if (break_pos >= 0)
            {
                // Natural break found
                cursor -= (LINE_LEN - break_pos - 1);

                if (line[break_pos] == '-')
                {
                    line[break_pos + 1] = '\0';
                }
                else // Space
                {
                    line[break_pos] = '\0';
                }
            }
            else
            {
                // No natural break - try hyphenation
                // Find the current word we're in
                uint8_t word_start = 0;
                for (int8_t k = LINE_LEN - 1; k >= 0; k--)
                {
                    if (line[k] == ' ')
                    {
                        word_start = k + 1;
                        break;
                    }
                }

                uint8_t word_len = LINE_LEN - word_start;

                // Look for a hyphenation point in the last 4-5 characters
                int8_t hyphen_pos = -1;
                for (int8_t k = LINE_LEN - 2; k >= word_start + 2; k--)
                {
                    if (IsHyphenationPoint(hardware, line, k, LINE_LEN))
                    {
                        hyphen_pos = k;
                        break;
                    }
                }

                if (hyphen_pos >= 0)
                {
                    // Insert hyphen and wrap
                    line[hyphen_pos] = '-';
                    line[hyphen_pos + 1] = '\0';
                    cursor -= (LINE_LEN - hyphen_pos - 1);
                }
                else
                {
                    // No hyphenation point - hard break
                    line[LINE_LEN] = '\0';
                }
            }
        }

        PrintLineStr(graphics, memory, desc_x, desc_y + (lines_printed * size), font_size, max_chars, line, indent);
        lines_printed++;
    }
}


/**********************************************************************************************************************/
/**  Retrieves the entity type data for the entity type found at the menu cursor
**********************************************************************************************************************/
SET_MEMORY(".map")
void FillObjectData(MemoryInterface memory, EntityData* entityData)
{
    uint8_t menu_idx = g_core.menu.sel[0].y;

    if (menu_idx == 1) // creature
    {
        Flash_GetCreatureName(memory, entityData->name, g_core.menu.gameMenu.displayId);
        Flash_GetCreatureDescription(memory, entityData->desc, g_core.menu.gameMenu.displayId);
        Flash_GetSpriteLayout(memory, &entityData->layout, g_core.menu.gameMenu.displayId, CREATURE, true);
        MonsterType m_type;
        Flash_GetType(memory, &m_type, g_core.menu.gameMenu.displayId);
        Flash_GetTypeName(memory, entityData->typeA, m_type.typeA);
        Flash_GetTypeName(memory, entityData->typeB, m_type.typeA);
    }
    else if (menu_idx == 2) // objects
    {
        Flash_GetObjectName(memory, entityData->name, g_core.menu.gameMenu.displayId);
        Flash_GetObjectDescription(memory, entityData->desc, g_core.menu.gameMenu.displayId);
        Flash_GetSpriteLayout(memory, &entityData->layout, g_core.menu.gameMenu.displayId, OBJECT, true);
        entityData->typeA[0] = '\0';
        entityData->typeB[0] = '\0';
    }
    else if (menu_idx == 3) // item
    {
        Flash_GetItemName(memory, entityData->name, g_core.menu.gameMenu.displayId);
        Flash_GetItemDescription(memory, entityData->desc, g_core.menu.gameMenu.displayId);
        Flash_GetSpriteLayout(memory, &entityData->layout, g_core.menu.gameMenu.displayId, ITEM, true);
        entityData->typeA[0] = '\0';
        entityData->typeB[0] = '\0';
    }
    else if (menu_idx == 4) //spell
    {
        Flash_GetSpellName(memory, entityData->name, g_core.menu.gameMenu.displayId);
        Flash_GetSpellDescription(memory, entityData->desc, g_core.menu.gameMenu.displayId);
        Flash_GetSpriteLayout(memory, &entityData->layout, g_core.menu.gameMenu.displayId, SPELL, true);
        entityData->typeA[0] = '\0';
        entityData->typeB[0] = '\0';
    }
    else if (menu_idx == 5) // skill
    {
        Flash_GetSkillName(memory, entityData->name, g_core.menu.gameMenu.displayId);
        Flash_GetSkillDescription(memory, entityData->desc, g_core.menu.gameMenu.displayId);
        Flash_GetSpriteLayout(memory, &entityData->layout, g_core.menu.gameMenu.displayId, SKILL, true);
        entityData->typeA[0] = '\0';
        entityData->typeB[0] = '\0';
    }
}


/**********************************************************************************************************************/
/**  Draws the "pokedex" style encyclopedia frame
**********************************************************************************************************************/
SET_MEMORY(".map")
void HandleGameMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    if (!g_core.menu.gameMenu.open && (g_core.menu.gameMenu.displayId == g_core.menu.gameMenu.id)) return;
    g_core.menu.gameMenu.displayId = g_core.menu.gameMenu.id;

    const uint16_t x = 0;
    uint8_t y = 0;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    FillObjectData(memory, &g_map.entityData);

    HandleGameMenuLeftBG(graphics, memory, x, y);
    HandleGameMenuBorders(graphics, hardware, memory);
    DrawBattler(graphics, memory, x, y + (size), &g_map.entityData.layout, g_core.menu.sel[0].y - 1, true);
    HandleGameMenuLeftName(graphics, memory, x, y + (size * 16), g_map.entityData.name);
    HandleGameMenuLeftStat(graphics, memory, x, x + (size * 6), y + (size * 18), size, g_map.power);
    HandleGameMenuLeftStat(graphics, memory, x, x + (size * 6), y + (size * 20) - 4, size, g_map.rarity);
    HandleGameMenuTypes(graphics, memory, g_map.entityData.typeA, g_map.entityData.typeB);
    HandleGameMenuDescription(graphics, hardware, memory, (size * 21), g_map.entityData.desc);
}
