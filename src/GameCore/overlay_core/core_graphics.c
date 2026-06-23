//
// Created by nathanial on 4/11/26.
//
#include "core_graphics.h"

#include "core_entities.h"
#include "types.h"
#include "enums.h"

#include "lib_decl.h"
#include "lib_types.h"
#include "lib_constants.h"
#include "lib_memory.h"

#include "core_menu.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_tiles.h"
#include "core_utils.h"
#include "lib_debugging.h"


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
uint8_t PrintLineStr(GraphicsInterface graphics, MemoryInterface memory, uint16_t x, uint16_t y, FontSize fontSize, uint8_t maxChars, const char* textLine, bool indent, uint8_t fg, uint8_t bg)
{
    uint8_t text_size;
    uint8_t char_idx = 0;
    uint8_t c = CH_NONE;
    text_size = TEXT_W;

    if (indent)
        x += text_size;

    if (maxChars == 0)
    {
        while (textLine[char_idx])
            char_idx++;

        maxChars = char_idx;
        char_idx = 0;
    }

    // Color color = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    Color color = Flash_GetColor(memory, bg);
    graphics.SetFrameBuffer(color); // gray
    FrameBuffer frameBuffer = {x, y, maxChars * text_size, text_size, color.color};

    while (textLine[char_idx] && char_idx < maxChars)
    {
        char nc = textLine[char_idx] - FONT_OFFSET;
        if (c != nc)
        {
            //
            c = nc;
            CharFromGlyph1bpp(memory, g_core.buffer, g_core.tile.pixels, c, fontSize, Flash_GetColor(memory, fg), color);
        }

        uint16_t char_pos = (char_idx * text_size);
        Rect_16 rect = {char_pos, 0, text_size, text_size};

        graphics.DrawToBuffer(&frameBuffer, g_core.tile.pixels, &rect);
        char_idx++;
    }

    graphics.DrawBuffer(frameBuffer, NULL);
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
    const uint16_t erase_x = x + (g_core.menu.eraseSel.x * g_core.menu.x_offset * TEXT_W);
    Color battler_menu_color = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
    graphics.FillRect(erase_x, list_y + (g_core.menu.eraseSel.y * (TEXT_W + g_core.menu.lineHeight)), TEXT_W, TEXT_W, battler_menu_color);


    Glyph buffer = {0};
    uint8_t sel_y = GetSelectorY();
    uint8_t sel_x = GetSelectorX();
    uint16_t draw_x = x + (sel_x * g_core.menu.x_offset * TEXT_W);
    uint16_t draw_y = list_y + (sel_y * (TEXT_W + g_core.menu.lineHeight));
    const FontSize font_size = g_core.settings.fontSize;
    if (font_size == FONT8x8)
    {
        Glyph8x8 character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(draw_x, draw_y, TEXT_W, TEXT_W, character.pixels);
    }
    else
    {
        Glyph character;
        CharFromGlyph1bpp(memory, buffer, character.pixels, '>' - FONT_OFFSET, font_size, Flash_GetColor(memory, PAL_DARK_BLUE_GRAY), Flash_GetColor(memory, PAL_KEY));
        graphics.DrawTileKeyed(draw_x, draw_y, TEXT_W, TEXT_W, character.pixels);
    }
}


/**********************************************************************************************************************/
/**     Clears the Buffer to gray
 *      Draws a multi-tile sprite to a buffer one TILE_W x TILE_H tile at a tile
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
    graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE));

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
    graphics.DrawBuffer(f, NULL);
}

/**********************************************************************************************************************/
/**  Checks cache
 *  Updates cache
 *  Blit the given creature id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawIconCached(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_tx, uint16_t screen_ty, uint8_t sprite_id, IconType type)
{
    SpriteFrames layout = {0};
    Flash_GetIconMetadata(memory, &layout, type, sprite_id);
    Flash_GetIconSprite(memory, g_core.tileCache.spriteCache.bytes, &layout, type);

    uint8_t icon_size = ICON_W;
    if (type == ICON_CREATURE_BUFF || type == ICON_CREATURE_DEBUFF || type == ICON_TRAINER_BUFF)
        icon_size = BUFF_W;

    Expand4bppPackedToByte(memory, g_core.tileCache.spriteCache.bytes, layout.palette, g_core.tileCache.spritePixels.pixels, icon_size);

    Rect_16 rect = {screen_tx, screen_ty, icon_size, icon_size};
    graphics.Draw16(NULL, &rect, g_core.tileCache.spritePixels.pixels);
}


/**********************************************************************************************************************/
/**  Checks cache
 *  Updates cache
 *  Blit the given creature id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".core")
void DrawBuffs(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, const uint8_t* buff_values, IconType icon_type, uint8_t num_per_row)
{
    const uint8_t spacing = 5;
    uint8_t index = 0;

    Color color;

    if (icon_type == ICON_CREATURE_BUFF || icon_type == ICON_TRAINER_BUFF)
        color = Flash_GetColor(memory, PAL_BRIGHT_VINE_GRN);
    else if (icon_type == ICON_CREATURE_DEBUFF)
        color = Flash_GetColor(memory, PAL_REDDISH_BROWN);

    for (uint8_t i = 0; i < MAX_MAX_STATUS_EFFECTS; i++)
    {
        if (buff_values[i] > 0)
        {
            if (index % num_per_row == 0)
            {
                if (index != 0)
                    screen_y += (BUFF_H + spacing);
                index = 0;
                DrawIconCached(graphics, memory, screen_x, screen_y, i, icon_type);
                graphics.DrawRectOutline(screen_x, screen_y, BUFF_W, BUFF_H, 1, color);
                index++;
            }
            else
            {
                DrawIconCached(graphics, memory, screen_x + (index * (BUFF_W + 8)), screen_y, i, icon_type);
                graphics.DrawRectOutline(screen_x + (index * (BUFF_W + 8)), screen_y, BUFF_W, BUFF_H, 1, color);
                index++;
            }
        }
    }
}

/**********************************************************************************************************************/
/**  Checks cache
 *  Updates cache
 *  Blit the given creature id to the given screen coords
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t DrawSkillBuffs(GraphicsInterface graphics, MemoryInterface memory, uint16_t screen_x, uint16_t screen_y, uint16_t buff_values, IconType icon_type, uint8_t num_per_row)
{
    const uint8_t spacing = 5;
    uint8_t index = 0;
    uint8_t n = 0; // counts total buffs drawn
    Color color;

    if (icon_type == ICON_CREATURE_BUFF || icon_type == ICON_TRAINER_BUFF)
        color = Flash_GetColor(memory, PAL_BRIGHT_VINE_GRN);
    else if (icon_type == ICON_CREATURE_DEBUFF)
        color = Flash_GetColor(memory, PAL_REDDISH_BROWN);

    for (int8_t i = 0; i < MAX_MAX_STATUS_EFFECTS; i++)
    {
        if (((buff_values & 0x8000) >> 15) > 0)
        {
            // Start a new row when we've filled the current one
            if (index % num_per_row == 0)
            {
                if (n != 0) // <-- FIX: use n instead of buff_index
                    screen_y += (BUFF_H + spacing);
                index = 0;
                DrawIconCached(graphics, memory, screen_x, screen_y, i, icon_type);
                graphics.DrawRectOutline(screen_x, screen_y, BUFF_W, BUFF_H, 1, color);
                index++;
            }
            else
            {
                DrawIconCached(graphics, memory, screen_x + (index * (BUFF_W + 8)), screen_y, i, icon_type);
                graphics.DrawRectOutline(screen_x + (index * (BUFF_W + 8)), screen_y, BUFF_W, BUFF_H, 1, color);
                index++;
            }
            n++;
        }
        buff_values <<= 1;
    }
    return n;
}


SET_MEMORY(".core")
void DrawRightWing(GraphicsInterface graphics, MemoryInterface memory)
{
    if (g_core.update_right_party)
    {
        g_core.update_right_party = false;
        graphics.DrawToRight();
        Rect_16 rect = graphics.GetRightRect();
        Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
        Color border = Flash_GetColor(memory, PAL_DARK_BLUE_GRAY);


        uint16_t party_x = TEXT_W;
        uint16_t party_w = (rect.w - (2 * TEXT_W)) > SMALL_STRINGS * TEXT_W ? SMALL_STRINGS * TEXT_W : (rect.w - (2 * TEXT_W));
        uint16_t line_h = TEXT_H;
        uint16_t area_down_y = 416;

        graphics.FillRect(rect.x, rect.y, rect.w, area_down_y, color_bg);
        uint16_t y = TEXT_H;

        Color portrait = Flash_GetColor(memory, PAL_TAN_RED);
        Color hp = Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN);
        Color mp = Flash_GetColor(memory, PAL_ICE_BLUE);
        Color xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);

        Color colors[3] = {hp, mp, xp};
        uint16_t party_h = TEXT_H * 3;
        uint16_t status_x = TEXT_W + party_h;
        uint16_t w = (party_w - party_h > SMALL_STRINGS * TEXT_W) ? SMALL_STRINGS * TEXT_W : (party_w - party_h);

        EntityId* party = GetPlayerParty();

        for (int i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId creature_id = party[i];
            graphics.DrawRectOutline(party_x, y, party_w, party_h, 1, border);
            if (creature_id == NO_ENTITY)
            {
                y += party_h;
            }
            else
            {
                graphics.FillRect(party_x, y, party_h, party_h, portrait);
                graphics.DrawRectOutline(party_x, y, party_h, party_h, 1, border);

                uint_max999 vals[3] = {g_core.creatures.hp[creature_id], g_core.creatures.mp[creature_id], g_core.creatures.xp[creature_id]};
                for (int j = 0; j < 3; ++j)
                {
                    uint16_t cur = Int999GetCurrent(&vals[j]);
                    uint16_t max = Int999GetMax(&vals[j]);
                    uint16_t percent = (cur * 100) / max;
                    uint16_t percent_w = (percent * w) / 100;
                    graphics.FillRect(status_x, y, w, line_h, color_bg);
                    graphics.FillRect(status_x, y, percent_w, line_h, colors[j]);
                    graphics.DrawRectOutline(status_x, y, w, line_h, 1, border);
                    y += line_h;
                }
            }
            y += line_h;
        }
    }


    if (g_core.update_right_inventory)
    {
        g_core.update_right_inventory = false;
        graphics.DrawToRight();
        Rect_16 rect = graphics.GetRightRect();
        Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
        Color border = Flash_GetColor(memory, PAL_DARK_BLUE_GRAY);
        Color xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);


        uint16_t party_x = TEXT_W;
        uint16_t party_w = (rect.w - (2 * TEXT_W)) > SMALL_STRINGS * TEXT_W ? SMALL_STRINGS * TEXT_W : (rect.w - (2 * TEXT_W));
        uint16_t line_h = TEXT_H;
        uint16_t area_down_y = 416;

        uint16_t y = area_down_y;
        graphics.FillRect(rect.x, y, rect.w, rect.h - y, color_bg);

        Color occupied = Flash_GetColor(memory, PAL_LIGHT_TAN);
        EntityId* inventory = GetPlayerInventory();
        char item[SMALL_STRINGS];
        for (int i = 0; i < GetPlayerBagData().current_max_size; ++i)
        {
            if (inventory[i] == NO_ENTITY)
            {
            }
            else
            {
                graphics.FillRect(party_x + line_h, y, party_w - line_h, line_h, occupied);
                graphics.FillRect(party_x, y, line_h, line_h, xp);
                graphics.DrawRectOutline(party_x, y, line_h, line_h, 1, border);
                Flash_GetItemName(memory, item, GetItemType(inventory[i]));
                PrintLineStr(graphics, memory, party_x + line_h, y, g_core.settings.fontSize, ((party_w) / TEXT_W) - 1, item, 0, PAL_DARK_BLUE_GRAY, PAL_LIGHT_TAN);
            }
            graphics.DrawRectOutline(party_x, y, party_w, line_h, 1, border);
            y += line_h;
        }
    }

    if (g_core.update_right_text_clear)
    {
        graphics.DrawToRight();
        Rect_16 rect = graphics.GetRightRect();
        g_core.update_right_text_clear = false;
        Color xp = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
        uint16_t area_down_y = rect.h - (16 * 7);
        graphics.FillRect(rect.x, area_down_y, rect.w, 16 * 7, xp);
    }

    if (g_core.update_right_text)
    {
        if (g_core.tooltip_text[0][0] == '\0') return;
        graphics.DrawToRight();
        Rect_16 rect = graphics.GetRightRect();
        uint16_t text_w = (rect.w) / TEXT_W < LARGE_STRINGS ? (rect.w) / TEXT_W : LARGE_STRINGS;

        rect.y = rect.h - (16 * 7);

        PrintLineStr(graphics, memory, rect.x, rect.y, g_core.settings.fontSize, text_w, g_core.tooltip_text[0], 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        rect.y += TEXT_H;

        for (int i = 1; i < MAX_OBJECT_EFFECTS + 1; ++i)
        {
            PrintLineStr(graphics, memory, rect.x, rect.y, g_core.settings.fontSize, text_w, g_core.tooltip_text[i], 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
            g_core.tooltip_text[i][0] = '\0';
            rect.y += TEXT_H;
        }
    }
}


SET_MEMORY(".core")
void DrawLeftWing(GraphicsInterface graphics, MemoryInterface memory)
{
    if (g_core.update_left_player)
    {
        g_core.update_left_player = false;
        graphics.DrawToLeft();
        Rect_16 rect = graphics.GetLeftRect();
        Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
        uint16_t area_down_y = g_core.area_down_y;
        graphics.FillRect(rect.x, rect.y, rect.w, area_down_y, color_bg);

        Color border = Flash_GetColor(memory, PAL_DARK_BLUE_GRAY);
        Color xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);
        char line[SMALL_STRINGS];


        uint16_t x = TEXT_W;
        uint16_t y = TEXT_H;
        uint16_t w = (rect.w - (2 * TEXT_W) > SMALL_STRINGS * TEXT_W) ? SMALL_STRINGS * TEXT_W : (rect.w - (2 * TEXT_W));
        uint16_t h = TEXT_H;
        uint16_t portrait_w = 6 * TEXT_H;

        graphics.FillRect(x, y, portrait_w, portrait_w, xp);
        graphics.DrawRectOutline(x, y, portrait_w, portrait_w, 1, border);

        PrintLineStr(graphics, memory, portrait_w + x, y, g_core.settings.fontSize, SMALL_STRINGS, "trainer name", 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        PrintLineStr(graphics, memory, portrait_w + x, y += TEXT_H, g_core.settings.fontSize, SMALL_STRINGS, "Turn count", 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        PrintLineStr(graphics, memory, portrait_w + x, y += TEXT_H, g_core.settings.fontSize, SMALL_STRINGS, "map type", 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

        uint99* level_value = GetPlayerLevel();
        GetAsChars_uint8(level_value->value, (CharStr_uint8*)(line), false, true);
        PrintLineStr(graphics, memory, portrait_w + x, y += TEXT_H, g_core.settings.fontSize, SMALL_STRINGS, line, 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

        uint_max999 xp_val = g_core.trainers.xp[GetPlayerID()];
        uint16_t cur = Int999GetCurrent(&xp_val);
        uint16_t max = Int999GetMax(&xp_val);
        uint16_t percent = (cur * 100) / max;
        uint16_t percent_w = (percent * w) / 100;

        y += TEXT_H * 3;
        graphics.FillRect(x, y, percent_w, h, xp);
        graphics.DrawRectOutline(x, y, w, h, 1, border);

        h = TEXT_H * 2;
        for (int i = 0; i < 4; ++i)
        {
            y += 5;
            graphics.FillRect(x, y += h, h, h, xp);
            graphics.DrawRectOutline(x, y, h, h, 1, border);
        }
    }


    if (g_core.update_left_spellbook)
    {
        g_core.update_left_spellbook = false;
        graphics.DrawToLeft();
        Rect_16 rect = graphics.GetLeftRect();
        Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
        uint16_t area_down_y = g_core.area_down_y;
        graphics.FillRect(rect.x, area_down_y, rect.w, rect.h - area_down_y, color_bg);

        Color border = Flash_GetColor(memory, PAL_DARK_BLUE_GRAY);
        Color mp = Flash_GetColor(memory, PAL_ICE_BLUE);
        Color xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);

        uint16_t x = TEXT_W;
        uint16_t y = TEXT_H;
        uint16_t w = (rect.w - (2 * TEXT_W) > SMALL_STRINGS * TEXT_W) ? SMALL_STRINGS * TEXT_W : (rect.w - (2 * TEXT_W));
        uint16_t h = TEXT_H;


        y = area_down_y;

        SpellBook* spellbook = GetPlayerSpellbook();
        char spell[SMALL_STRINGS];

        for (int i = 0; i < spellbook->current_max_pages; ++i)
        {
            if (spellbook->spell_id[i] == NO_SPELL)
            {
            }
            else
            {
                uint16_t pp_count_size = 64;
                uint16_t cur = spellbook->page[i].pp;
                uint16_t max = spellbook->page[i].spellData.pp;
                uint16_t percent = (cur * 100) / max;
                uint16_t percent_w = (percent * (pp_count_size)) / 100;

                graphics.FillRect(x + h, y, percent_w, h, mp);
                graphics.FillRect(x, y, h, h, xp);
                graphics.DrawRectOutline(x, y, h, h, 1, border);
                Flash_GetSpellName(memory, spell, spellbook->spell_id[i]);
                PrintLineStr(graphics, memory, x + h, y, g_core.settings.fontSize, (w / TEXT_W) - 1, spell, 0, PAL_DARK_BLUE_GRAY, PAL_ICE_BLUE);

                //pp count
                graphics.FillRect(x + w, y, percent_w, h, mp);
                char* pp_text = spell;
                uint8_t offset = 2;
                GetAsChars_uint8(spellbook->page[i].pp, (CharStr_uint8*)pp_text, false, true);
                if (spellbook->page[i].pp < 10)
                {
                    pp_text[1] = '/';
                }
                else if (spellbook->page[i].pp < 100)
                {
                    pp_text[2] = '/';
                    offset = 3;
                }

                GetAsChars_uint8(spellbook->page[i].spellData.pp, (CharStr_uint8*)(pp_text + offset), false, true);
                PrintLineStr(graphics, memory, x + w + pp_count_size, y, g_core.settings.fontSize, 0, pp_text, 0, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
                graphics.DrawRectOutline(x + w, y, pp_count_size, h, 1, border);
            }
            graphics.DrawRectOutline(x, y, w, h, 1, border);
            y += TEXT_H;
        }
    }

    if (g_core.update_left_text)
    {
    }
}

SET_MEMORY(".core")
void DrawText(GraphicsInterface graphics, MemoryInterface memory)
{
    if (!g_core.update_text) return;
    g_core.update_text = false;

    graphics.DrawToText();
    Rect_16 rect = graphics.GetTextRect();
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
    graphics.FillRect(rect.x, rect.y, rect.w, rect.h, color_bg);

    for (int i = 0; i < MAX_SPELLBOOK_SIZE; ++i)
    {
    }
}


SET_MEMORY(".core")
void DrawScreen(GraphicsInterface graphics, MemoryInterface memory)
{
    graphics.UpdateDrawAreas();
    DrawRightWing(graphics, memory);
    DrawLeftWing(graphics, memory);
    DrawText(graphics, memory);
    graphics.DrawToMain();
    graphics.EndFrame();
}
