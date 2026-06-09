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
#include "battle_stats.h"
#include "core_player.h"

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
    const uint8_t max_lines = (MAIN_MENU_H / TEXT_W);

    //display menu text
    uint16_t list_y = y + size;
    uint8_t i = 0;

    Color color_border = Flash_GetColor(memory, PAL_BLACK);
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    Color color_hp = Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN);
    Color color_mp = Flash_GetColor(memory, PAL_ICE_BLUE);
    Color color_xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);

    while (1)
    {
        char line[SMALL_STRINGS];
        GetMenuLine(memory, line, i);
        bool line_empty = (line[0] == '\0');
        if (line_empty || i > (max_lines)) break;

        uint8_t idx = 0;
        // if selected into SwapMenu
        if (g_battle.show_party) // drawing party
        {
            //level //name
            list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, line, indent);
            if (line[0] != ' ')
            {
                //health //mana / xp
                uint16_t rect_w = w / 2;

                EntityId player_id = GetPlayerID();
                EntityId creature_id = g_core.trainers.partyID[player_id][idx];

                IntMax999 hp = GetCreaturehp(creature_id);
                uint16_t cur_hp = Int999GetCurrent(&hp);
                uint16_t max_hp = Int999GetMax(&hp);
                IntMax999 mp = GetCreaturemp(creature_id);
                uint16_t cur_mp = Int999GetCurrent(&mp);
                uint16_t max_mp = Int999GetMax(&mp);
                IntMax999 xp = GetCreaturexp(creature_id);
                uint16_t cur_xp = Int999GetCurrent(&xp);
                uint16_t max_xp = Int999GetMax(&xp);

                const uint8_t pad = 1;
                const uint8_t pad2 = pad << 1;

                float bar_w = ((float)rect_w - (float)pad2) * ((float)cur_hp / (float)max_hp);
                graphics.FillRect(x + size, list_y, rect_w, size, color_border);
                graphics.FillRect(x + size + pad, list_y + pad, rect_w - pad2, size - pad2, color_bg);
                graphics.FillRect(x + size + pad, list_y + pad, (uint16_t)bar_w, size - pad2, color_hp);

                bar_w = ((float)rect_w - (float)pad2) * ((float)cur_mp / (float)max_mp);
                graphics.FillRect(x + size, list_y + size, rect_w, size, color_border);
                graphics.FillRect(x + size + pad, list_y + size + pad, rect_w - pad2, size - pad2, color_bg);
                graphics.FillRect(x + size + pad, list_y + size + pad, (uint16_t)bar_w, size - pad2, color_mp);

                bar_w = ((float)rect_w - (float)pad2) * ((float)cur_xp / (float)max_xp);
                graphics.FillRect(x + size, list_y + (size * 2), rect_w, size >> 1, color_border);
                graphics.FillRect(x + size + pad, list_y + (size * 2) + pad, rect_w - pad2, (size >> 1) - pad2, color_bg);
                graphics.FillRect(x + size + pad, list_y + (size * 2) + pad, (uint16_t)bar_w, (size >> 1) - pad2, color_xp);
            }

            idx++;
            g_core.menu.lineHeight = size * 3;
            list_y += g_core.menu.lineHeight;
        }
        else // drawing general list
        {
            // name
            list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, line, indent);
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
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
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
    PrintLineStr(graphics, memory, x, y, font_size, max_chars, border, false);
    PrintLineStr(graphics, memory, x, y + (h - size), font_size, max_chars, border, false);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_LIGHT_GRAY);
}


/**********************************************************************************************************************/
/*  Draws the formatted Creature stats in battle - hp, mama
**********************************************************************************************************************/
SET_MEMORY(".battle")
void CreatureStats(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId creature_id, Rect_16 rect, uint8_t size, FontSize font_size)
{
    uint8_t max_chars = 12;

    graphics.FillRect(rect.x, rect.y, rect.w, rect.h, Flash_GetColor(memory, PAL_LIGHT_GRAY));

    rect.w -= size << 1;

    char text[SMALL_STRINGS];
    Flash_GetCreatureName(memory, text, GetCreatureType(creature_id));
    PrintLineStr(graphics, memory, rect.x + TEXT_W, rect.y + TEXT_W, font_size, max_chars, text, false);
    //Level text

    char status_line[max_chars];

    Color color_border = Flash_GetColor(memory, PAL_BLACK);
    Color color_bg = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    Color color_hp = Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN);
    Color color_mp = Flash_GetColor(memory, PAL_ICE_BLUE);
    Color color_xp = Flash_GetColor(memory, PAL_PALE_BLU_PURP);


    IntMax999 hp = GetCreaturehp(creature_id);
    uint16_t cur_hp = Int999GetCurrent(&hp);
    uint16_t max_hp = Int999GetMax(&hp);
    IntMax999 mp = GetCreaturemp(creature_id);
    uint16_t cur_mp = Int999GetCurrent(&mp);
    uint16_t max_mp = Int999GetMax(&mp);
    IntMax999 xp = GetCreaturexp(creature_id);
    uint16_t cur_xp = Int999GetCurrent(&xp);
    uint16_t max_xp = Int999GetMax(&xp);

    GetStatLine(hardware, cur_hp, max_hp, max_chars, status_line, "HP:");
    GetStatLine(hardware, cur_mp, max_mp, max_chars, status_line, "MP:");

    const uint8_t pad = 1;
    const uint8_t pad2 = pad << 1;


    float bar_w = ((float)rect.w - (float)pad2) * ((float)cur_hp / (float)max_hp);
    graphics.FillRect(rect.x + TEXT_W, rect.y + size + TEXT_W, rect.w, size, color_border);
    graphics.FillRect(rect.x + TEXT_W + pad, rect.y + size + TEXT_W + pad, rect.w - pad2, size - pad2, color_bg);
    graphics.FillRect(rect.x + TEXT_W + pad, rect.y + size + TEXT_W + pad, (uint16_t)bar_w, size - pad2, color_hp);

    bar_w = ((float)rect.w - (float)pad2) * ((float)cur_mp / (float)max_mp);
    graphics.FillRect(rect.x + TEXT_W, rect.y + (size * 2) + TEXT_W, rect.w, size, color_border);
    graphics.FillRect(rect.x + TEXT_W + pad, rect.y + (size * 2) + TEXT_W + pad, rect.w - pad2, size - pad2, color_bg);
    graphics.FillRect(rect.x + TEXT_W + pad, rect.y + (size * 2) + TEXT_W + pad, (uint16_t)bar_w, size - pad2, color_mp);

    if (g_core.battleMode.playerMonsterID == creature_id)
    {
        // hp text
        // mana text

        bar_w = ((float)rect.w - (float)pad2) * ((float)cur_xp / (float)max_xp);
        graphics.FillRect(rect.x + TEXT_W, rect.y + (size * 3) + TEXT_W, rect.w, size >> 1, color_border);
        graphics.FillRect(rect.x + TEXT_W + pad, rect.y + (size * 3) + TEXT_W + pad, rect.w - pad2, (size >> 1) - pad2, color_bg);
        graphics.FillRect(rect.x + TEXT_W + pad, rect.y + (size * 3) + TEXT_W + pad, (uint16_t)bar_w, (size >> 1) - pad2, color_xp);
    }


    //buff frame

    //debuff frame
}


void PrintCombatLogFull(GraphicsInterface graphics, MemoryInterface memory)
{
    graphics.FillRect(DIALOGUE_BOX_FRAME.x, DIALOGUE_BOX_FRAME.y + (6 * TEXT_H), DIALOGUE_BOX_FRAME.w, DIALOGUE_BOX_FRAME.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

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
        PrintLineStr(graphics, memory, DIALOGUE_BOX_FRAME.x, DIALOGUE_BOX_FRAME.y + (6 * TEXT_H) + (TEXT_H * i), g_core.settings.fontSize, 40, g_core.battleMode.combatLog[index + i], false);
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
    uint8_t max_chars = (TFT_W / 2 / size) - indent;

    Rect_16 player = PLAYER_BATTLER_FRAME;
    Rect_16 playerHP = PLAYER_RESOURCE_FRAME;
    Rect_16 enemy = ENEMY_BATTLER_FRAME;
    Rect_16 enemyHP = ENEMY_RESOURCE_FRAME;
    Rect_16 dialogue = DIALOGUE_BOX_FRAME;

    graphics.FillRect(enemy.x, enemy.y, enemy.w, enemy.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));
    graphics.FillRect(player.x, player.y, player.w, player.h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

    SpriteLayout pLayout = {};
    Flash_GetSpriteLayout_64(memory, &pLayout, GetCreatureType(g_core.battleMode.playerMonsterID), CREATURE, false);
    DrawBattler(graphics, memory, player.x + BATTLER_OFFSET, player.y, &pLayout, CREATURE, false);

    SpriteLayout eLayout = {};
    Flash_GetSpriteLayout_64(memory, &eLayout, GetCreatureType(g_core.battleMode.enemyMonsterID), CREATURE, true);
    DrawBattler(graphics, memory, enemy.x + BATTLER_OFFSET, enemy.y, &eLayout, CREATURE, true);

    CreatureStats(graphics, hardware, memory, g_core.battleMode.playerMonsterID, playerHP, size, font_size);
    CreatureStats(graphics, hardware, memory, g_core.battleMode.enemyMonsterID, enemyHP, size, font_size);
    //player creature xp

    uint16_t x = dialogue.x;
    uint16_t y = dialogue.y;
    uint8_t i = 0;
    char line[SMALL_STRINGS];

    while (i < MAX_ABILITIES)
    {
        Flash_GetSkillName(memory, line, g_core.creatures.attacks[g_core.battleMode.playerMonsterID][i]);
        if (line[0] == '\0') break;
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, line, indent);
        i++;
    }

    x = dialogue.x + (BATTLE_MENU_COL_2 * size);
    y = dialogue.y;
    i = 0;
    while (i < BATTLE_MENU_SIZE)
    {
        Flash_GetBattleMenuList(memory, (uint8_t*)line, i);
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, line, indent);
        i++;
    }


    //combat log
    PrintCombatLogFull(graphics, memory);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
}
