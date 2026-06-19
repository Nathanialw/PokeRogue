//
// Created by nathanial on 5/19/26.
//

#include "battle_graphics.h"
#include "lib_memory.h"
#include "lib_decl.h"

#include "core_graphics.h"
#include "core_menu.h"
#include "core_memory_access.h"
#include "core_ram.h"
#include "core_entities.h"
#include "core_utils.h"

#include "battle_memory_access.h"
#include "battle_ram.h"
#include "core_player.h"
#include "core_stats.h"

SET_MEMORY(".battle")
void CreateCreatureName(const char* name, const uint99 level, char* out)
{
    uint8_t char_index = 0;
    uint8_t line_index = 0;

    CharStr_99 level_str;
    GetAsChars_99(level, &level_str, false);

    out[line_index] = 'L';
    line_index++;
    while (level_str[char_index] != '\0')
    {
        out[line_index] = level_str[char_index];
        line_index++;
        char_index++;
    }

    out[line_index] = ' ';
    line_index++;
    char_index = 0;
    while (name[char_index] != '\0')
    {
        out[line_index] = name[char_index];
        line_index++;
        char_index++;
    }
    out[line_index] = '\0';
}


SET_MEMORY(".battle")
void GetStatPrefix(char* out, const char* prefix, uint16_t cur, uint16_t max)
{
    uint16_t i = 0;
    while (prefix[i])
    {
        out[i] = prefix[i];
        i++;
    }

    CharStr_max999 c;
    GetAsChars_Max999(cur, &c, false);
    uint16_t j = 0;
    while (c[j])
    {
        out[i] = c[j];
        i++;
        j++;
    }

    out[i] = '/';
    i++;

    CharStr_max999 m;
    GetAsChars_Max999(max, &m, false);
    j = 0;
    while (m[j])
    {
        out[i] = m[j];
        i++;
        j++;
    }

    out[i] = '\0';
}

/**********************************************************************************************************************/
/**  Draws battle mode menu list - ie bag items, party, spells
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleLists(GraphicsInterface graphics, MemoryInterface memory)
{
    // use screen area of player battler and down to the bottom of the skill list
    const uint16_t x = PLAYER_BATTLER_FRAME.x;
    const uint16_t y = PLAYER_BATTLER_FRAME.y;
    const uint16_t w = PLAYER_BATTLER_FRAME.w;

    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = TEXT_W;
    const uint8_t max_chars = w / TEXT_W;
    const uint8_t max_lines = BATTLE_LIST_H;

    const Color color_border = Flash_GetColor(memory, PAL_BLACK);
    const Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
    const Color color_hp = Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN);
    const Color color_mp = Flash_GetColor(memory, PAL_ICE_BLUE);
    const Color color_xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP); 

    //display menu text
    uint16_t list_y = y + size;
    uint8_t i = 0;
    uint8_t idx = 0;
    char empty_line[SMALL_STRINGS] = "------\0";
    const char* text = empty_line;
    char line[MEDIUM_STRINGS];
    bool end = false;

    while (1)
    {
        // if selected into SwapMenu
        if (g_battle.show_party) // drawing party
        {
            if (i >= MAX_PARTY_SIZE)
                break;

            if (i >= g_core.menu.occupied_visible_menu_options)
            {
                list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, empty_line, indent, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
                g_core.menu.lineHeight = size * 3;
                list_y += g_core.menu.lineHeight;
            }
            else
            {
                char name[SMALL_STRINGS];
                GetMenuLine(memory, name, i);
                const EntityId player_id = GetPlayerID();
                const EntityId creature_id = g_core.trainers.partyID[player_id][idx];
                const uint99 level = g_core.creatures.level[creature_id];

                CreateCreatureName(name, level, line);
                //level //name
                list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, line, indent, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

#define ROW_1 list_y
#define ROW_2 (list_y + size)
#define ROW_3 (list_y + (size * 2) )

                if (line[0] != ' ')
                {
                    //health //mana / xp
                    const uint16_t rect_w = w / 2;

                    const uint_max999 hp = GetCreaturehp(creature_id);
                    const uint16_t cur_hp = Int999GetCurrent(&hp);
                    const uint16_t max_hp = Int999GetMax(&hp);
                    const uint_max999 mp = GetCreaturemp(creature_id);
                    const uint16_t cur_mp = Int999GetCurrent(&mp);
                    const uint16_t max_mp = Int999GetMax(&mp);
                    const uint_max999 xp = GetCreaturexp(creature_id);
                    const uint16_t cur_xp = Int999GetCurrent(&xp);
                    const uint16_t max_xp = Int999GetMax(&xp);

                    const uint8_t pad = 1;
                    const uint8_t pad2 = pad << 1;

                    // GetStatPrefix(line, "HP:", cur_hp, max_hp);
                    // PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_1, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
                    // GetStatPrefix(line, "MP:", cur_mp, max_mp);
                    // PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_2, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
                    // GetStatPrefix(line, "XP:", cur_xp, max_xp);
                    // PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_3, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

                    float bar_w = ((float)rect_w - (float)pad2) * ((float)cur_hp / (float)max_hp);
                    graphics.FillRect(x + size, ROW_1, rect_w, size, color_border);
                    graphics.FillRect(x + size + pad, ROW_1 + pad, rect_w - pad2, size - pad2, color_bg);
                    graphics.FillRect(x + size + pad, ROW_1 + pad, (uint16_t)bar_w, size - pad2, color_hp);

                    bar_w = ((float)rect_w - (float)pad2) * ((float)cur_mp / (float)max_mp);
                    graphics.FillRect(x + size, ROW_2, rect_w, size, color_border);
                    graphics.FillRect(x + size + pad, ROW_2 + pad, rect_w - pad2, size - pad2, color_bg);
                    graphics.FillRect(x + size + pad, ROW_2 + pad, (uint16_t)bar_w, size - pad2, color_mp);

                    bar_w = ((float)rect_w - (float)pad2) * ((float)cur_xp / (float)max_xp);
                    graphics.FillRect(x + size, ROW_3, rect_w, size >> 1, color_border);
                    graphics.FillRect(x + size + pad, ROW_3 + pad, rect_w - pad2, (size >> 1) - pad2, color_bg);
                    graphics.FillRect(x + size + pad, ROW_3 + pad, (uint16_t)bar_w, (size >> 1) - pad2, color_xp);
                }
                idx++;
                g_core.menu.lineHeight = size * 3;
                list_y += g_core.menu.lineHeight;
            }
        }
        else // drawing general list
        {
            if (!end)
            {
                GetMenuLine(memory, line, i);
                text = line;
                if (line[0] == '\0')
                {
                    end = true;
                    text = empty_line;
                }
            }
            else
            {
                if (i >= g_core.menu.max_visible_menu_options)
                    break;
                text = empty_line;
            }

            list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, text, indent, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        }
        i++;
    }
}

/**********************************************************************************************************************/
/**  Draws the back panel of the battle menu list and calls the draw battle list function
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    if (g_core.menu.depth == 0) return;

    // use screen area of player battler and down to the bottom of the skill list
    const uint16_t x = PLAYER_BATTLER_FRAME.x;
    const uint16_t y = PLAYER_BATTLER_FRAME.y;
    const uint16_t w = PLAYER_BATTLER_FRAME.w;
    const uint16_t h = PLAYER_BATTLER_FRAME.h;
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
    graphics.FillRect(x, y, w, h, color_bg);

    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = TEXT_W;
    const uint8_t max_chars = w / TEXT_W;
    const uint8_t max_lines = (MAIN_MENU_H * font_size);

    char border[max_chars + 1];
    memset(border, '-', max_chars);
    border[max_chars] = '\0';

    HandleBattleLists(graphics, memory);

    //borders
    PrintLineStr(graphics, memory, x, y, font_size, max_chars, border, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
    PrintLineStr(graphics, memory, x, y + (h - size), font_size, max_chars, border, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
}


/**********************************************************************************************************************/
/*  Draws the formatted Creature stats in battle - hp, mama
**********************************************************************************************************************/
SET_MEMORY(".battle")
void CreatureStats(GraphicsInterface graphics, MemoryInterface memory, EntityId creature_id, const Rect_16 rect, const Rect_16 text_rect, const Rect_16 buff_rect, const Rect_16 debuff_rect, uint8_t size, FontSize font_size)
{
    uint8_t max_chars = 12;

    graphics.FillRect(rect.x, rect.y, rect.w, rect.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE));
    graphics.FillRect(text_rect.x, text_rect.y, text_rect.w, text_rect.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE));


    char text[SMALL_STRINGS];
    Flash_GetCreatureName(memory, text, GetCreatureType(creature_id));
    char line[MEDIUM_STRINGS];
    const uint99 level = g_core.creatures.level[creature_id];
    CreateCreatureName(text, level, line);
    PrintLineStr(graphics, memory, rect.x + TEXT_W, rect.y + TEXT_W, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
    //Level text

    char status_line[max_chars];

    Color color_border = Flash_GetColor(memory, PAL_BLACK);
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE);
    Color color_hp = Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN);
    Color color_mp = Flash_GetColor(memory, PAL_ICE_BLUE);


    uint_max999 hp = GetCreaturehp(creature_id);
    uint16_t cur_hp = Int999GetCurrent(&hp);
    uint16_t max_hp = Int999GetMax(&hp);
    uint_max999 mp = GetCreaturemp(creature_id);
    uint16_t cur_mp = Int999GetCurrent(&mp);
    uint16_t max_mp = Int999GetMax(&mp);
    uint_max999 xp = GetCreaturexp(creature_id);
    uint16_t cur_xp = Int999GetCurrent(&xp);
    uint16_t max_xp = Int999GetMax(&xp);


    const uint8_t pad = 1;
    const uint8_t pad2 = pad << 1;

#define STAT_ROW_1 (text_rect.y + size + TEXT_W + pad)
#define STAT_ROW_2 (text_rect.y + (size * 2) + TEXT_W + pad)
#define STAT_ROW_3 (text_rect.y + (size * 3) + TEXT_W + pad)


    float bar_w = ((float)rect.w - (float)pad2) * ((float)cur_hp / (float)max_hp);
    graphics.FillRect(rect.x, rect.y + size + TEXT_W, rect.w, size, color_border);
    graphics.FillRect(rect.x + pad, rect.y + size + TEXT_W + pad, rect.w - pad2, size - pad2, color_bg);
    graphics.FillRect(rect.x + pad, rect.y + size + TEXT_W + pad, (uint16_t)bar_w, size - pad2, color_hp);

    bar_w = ((float)rect.w - (float)pad2) * ((float)cur_mp / (float)max_mp);
    graphics.FillRect(rect.x, rect.y + (size * 2) + TEXT_W, rect.w, size, color_border);
    graphics.FillRect(rect.x + pad, rect.y + (size * 2) + TEXT_W + pad, rect.w - pad2, size - pad2, color_bg);
    graphics.FillRect(rect.x + pad, rect.y + (size * 2) + TEXT_W + pad, (uint16_t)bar_w, size - pad2, color_mp);

    if (g_core.battleMode.playerMonsterID == creature_id)
    {
        GetStatPrefix(line, "HP:", cur_hp, max_hp);
        PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_1, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        GetStatPrefix(line, "MP:", cur_mp, max_mp);
        PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_2, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        GetStatPrefix(line, "XP:", cur_xp, max_xp);
        PrintLineStr(graphics, memory, text_rect.x, STAT_ROW_3, font_size, max_chars, line, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);

        Color color_xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);

        bar_w = ((float)rect.w - (float)pad2) * ((float)cur_xp / (float)max_xp);
        graphics.FillRect(rect.x, rect.y + (size * 3) + TEXT_W, rect.w, size >> 1, color_border);
        graphics.FillRect(rect.x + pad, rect.y + (size * 3) + TEXT_W + pad, rect.w - pad2, (size >> 1) - pad2, color_bg);
        graphics.FillRect(rect.x + pad, rect.y + (size * 3) + TEXT_W + pad, (uint16_t)bar_w, (size >> 1) - pad2, color_xp);
    }


    graphics.DrawRectOutline(rect.x, rect.y, rect.w, rect.h, 1, color_border);
    graphics.DrawRectOutline(text_rect.x, text_rect.y, text_rect.w, text_rect.h, 1, color_mp);
    graphics.DrawRectOutline(buff_rect.x, buff_rect.y, buff_rect.w, buff_rect.h, 1, color_hp);
    graphics.DrawRectOutline(debuff_rect.x, debuff_rect.y, debuff_rect.w, debuff_rect.h, 1, color_mp);


    uint8_t buff_values[16] = {0};
    //buff frame
    GetCreatureStatusEffectStateBuffs(buff_values, creature_id);
    DrawBuffs(graphics, memory, buff_rect.x, buff_rect.y, buff_values, ICON_CREATURE_DEBUFF, 8);

    //debuff frame
    GetCreatureStatusEffectStateDebuffs(buff_values, creature_id);
    DrawBuffs(graphics, memory, debuff_rect.x, debuff_rect.y, buff_values, ICON_CREATURE_DEBUFF, 8);
}


SET_MEMORY(".battle")
void CombatLogFullDraw(GraphicsInterface graphics, MemoryInterface memory)
{
    graphics.DrawRectOutline(DIALOGUE_BOX_FRAME.x, DIALOGUE_BOX_FRAME.y, DIALOGUE_BOX_FRAME.w, DIALOGUE_BOX_FRAME.h, 1, Flash_GetColor(memory, PAL_DEEP_BLUE));

    //clear area
    uint8_t index = 0;
    uint8_t num_lines = g_core.battleMode.current_line;
    if (g_core.battleMode.current_line > COMBAT_LOG_LINES)
    {
        num_lines = g_core.battleMode.current_line - COMBAT_LOG_LINES;
        index = num_lines;
    }

    uint8_t i = 0;
    while (i < num_lines)
    {
        PrintLineStr(graphics, memory, DIALOGUE_BOX_FRAME.x, DIALOGUE_BOX_FRAME.y + (6 * TEXT_H) + (TEXT_H * i), g_core.settings.fontSize, 40, g_core.battleMode.combatLog[index + i], false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        i++;
    }
}


/**********************************************************************************************************************/
/*   Draws the main Battle screen
 *      -2 battler sprites
 *      -2 status boxes
 *      -battle menu list for actuve creature abilities
 *      -battle menu list for player actions ie swap, use item, use spell etx
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    FontSize font_size = g_core.settings.fontSize;
    uint8_t size = TEXT_W;
    uint8_t indent = 1;
    uint8_t max_chars = (SCREEN_W / 2 / size) - indent;

    Rect_16 player = PLAYER_BATTLER_FRAME;
    Rect_16 playerHP = PLAYER_RESOURCE_FRAME;
    Rect_16 enemy = ENEMY_BATTLER_FRAME;
    Rect_16 enemyHP = ENEMY_RESOURCE_FRAME;
    Rect_16 dialogue = DIALOGUE_BOX_FRAME;
    Rect_16 menu = BATTLE_MENU_BOX_FRAME;

    graphics.FillRect(enemy.x, enemy.y, enemy.w, enemy.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE));
    graphics.FillRect(player.x, player.y, player.w, player.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY_BLUE));

    if (g_core.battleMode.playerMonsterID != NO_ENTITY)
    {
        SpriteLayout pLayout = {};
        Flash_GetSpriteLayout_64(memory, &pLayout, GetCreatureType(g_core.battleMode.playerMonsterID), CREATURE, false);
        DrawBattler(graphics, memory, player.x + BATTLER_OFFSET, player.y, &pLayout, CREATURE, false);
        CreatureStats(graphics, memory, g_core.battleMode.playerMonsterID, playerHP, PLAYER_STAT_TEXT_FRAME, PLAYER_BUFF_FRAME, PLAYER_DEBUFF_FRAME, size, font_size);
    }

    if (g_core.battleMode.enemyMonsterID != NO_ENTITY)
    {
        SpriteLayout eLayout = {};
        Flash_GetSpriteLayout_64(memory, &eLayout, GetCreatureType(g_core.battleMode.enemyMonsterID), CREATURE, true);
        DrawBattler(graphics, memory, enemy.x + BATTLER_OFFSET, enemy.y, &eLayout, CREATURE, true);
        CreatureStats(graphics, memory, g_core.battleMode.enemyMonsterID, enemyHP, ENEMY_STAT_TEXT_FRAME, ENEMY_BUFF_FRAME, ENEMY_DEBUFF_FRAME, size, font_size);
    }

    uint16_t x = menu.x;
    uint16_t y = menu.y;
    uint8_t i = 0;
    char line[SMALL_STRINGS];
    graphics.DrawRectOutline(menu.x, menu.y, menu.w, menu.h, 1, Flash_GetColor(memory, PAL_RED_ORANGE));

    while (i < MAX_ABILITIES)
    {
        Flash_GetSkillName(memory, line, g_core.creatures.attacks[g_core.battleMode.playerMonsterID][i]);
        if (line[0] == '\0') break;
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, line, indent, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        i++;
    }

    x = menu.x + (BATTLE_MENU_COL_2 * size);
    y = menu.y;
    i = 0;
    while (i < BATTLE_MENU_SIZE)
    {
        Flash_GetBattleMenuList(memory, (uint8_t*)line, i);
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, line, indent, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
        i++;
    }


    //combat log
    CombatLogFullDraw(graphics, memory);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_DARK_BLUE_GRAY);
}
