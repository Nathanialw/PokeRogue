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

#include "battle_memory_access.h"
#include "battle_stats.h"

/**********************************************************************************************************************/
/**  Draws battle mode menu list - ie bag items, party, spells
**********************************************************************************************************************/
SET_MEMORY(".battle")
void HandleBattleLists(GraphicsInterface graphics, MemoryInterface memory)
{
    // use screen area of player battler and down to the bottom of the skill list
    const uint16_t x = PLAYER_BATTLER_FRAME.x;
    const uint8_t y = PLAYER_BATTLER_FRAME.y;
    const uint16_t w = PLAYER_BATTLER_FRAME.w;

    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_chars = w / 8;
    const uint8_t max_lines = (MAIN_MENU_H * font_size);

    //display menu text
    uint8_t list_y = y + size;
    uint8_t i = 0;

    while (1)
    {
        char line[SMALL_STRINGS];
        GetMenuLine(memory, line, i);
        bool line_empty = (line[0] == '\0');
        if (line_empty || i > (max_lines)) break;

        // if selected into SwapMenu
        if (g_core.menu.sel[0].y == 0) // drawing party
        {
            //level //name
            list_y += PrintLineStr(graphics, memory, x, list_y, font_size, max_chars, line, indent);

            //health //mana
            uint8_t rect_w = w / 2;
            //TODO: replace with actual values
            graphics.FillRect(x, list_y, rect_w, size, Flash_GetColor(memory, PAL_EMERALD_GREEN));
            graphics.FillRect(x + rect_w, list_y, rect_w, size, Flash_GetColor(memory, PAL_ICE_BLUE));

            g_core.menu.lineHeight = size + (size / 2);
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
    const uint8_t y = PLAYER_BATTLER_FRAME.y;
    const uint16_t w = PLAYER_BATTLER_FRAME.w;
    const uint8_t h = PLAYER_BATTLER_FRAME.h + (8 * 6);
    graphics.FillRect(x, y, w, h, Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

    const uint8_t indent = 1;
    const FontSize font_size = g_core.settings.fontSize;
    const uint8_t size = (font_size == FONT8x8) ? TEXT_W : TILE_W;
    const uint8_t max_chars = w / 8;
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
void CreatureStats(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId id, Rect_16 rect, uint8_t size, FontSize font_size)
{
    uint8_t max_chars = 12;

    graphics.FillRect(rect.x, rect.y, rect.w, rect.h, Flash_GetColor(memory, PAL_LIGHT_GRAY));

    char text[SMALL_STRINGS];
    Flash_GetCreatureName(memory, text, GetCreatureType(id));
    PrintLineStr(graphics, memory, rect.x + TEXT_W, rect.y + TEXT_W, font_size, max_chars, text, false);

    char status_line[max_chars];

    const uint16_t cur_hp = Int999GetCurrent(&g_core.creatures.hp[id]);
    const uint16_t max_hp = Int999GetMax(&g_core.creatures.hp[id]);
    GetStatLine(hardware, cur_hp, max_hp, max_chars, status_line, "HP:");
    PrintLineStr(graphics, memory, rect.x + TEXT_W, rect.y + size + TEXT_W, font_size, max_chars, status_line, false);

    const uint16_t hp_w = ((float)cur_hp / (float)max_hp) * (float)(rect.w - 16);
    graphics.FillRect(rect.x + TEXT_W, rect.y + (size * 2) + TEXT_W, hp_w, TEXT_W, Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN));

    const uint16_t cur_mp = Int999GetCurrent(&g_core.creatures.mp[id]);
    const uint16_t max_mp = Int999GetMax(&g_core.creatures.mp[id]);

    GetStatLine(hardware, cur_mp, max_mp, max_chars, status_line, "MP:");
    PrintLineStr(graphics, memory, rect.x + TEXT_W, rect.y + (size * 3) + TEXT_W, font_size, max_chars, status_line, false);

    const uint16_t mp_w = ((float)cur_mp / (float)max_mp) * (float)(rect.w - 16);
    graphics.FillRect(rect.x + TEXT_W, rect.y + (size * 4) + TEXT_W, mp_w, TEXT_W, Flash_GetColor(memory, PAL_GRAY_BLUE));
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
    uint8_t size = TILE_W;
    if (font_size == FONT8x8)
        size = TEXT_W;
    uint8_t indent = 1;
    uint8_t max_chars = (TFT_W / 2 / size) - indent;

    Rect_16 player = PLAYER_BATTLER_FRAME;
    Rect_16 playerHP = PLAYER_RESOURCE_FRAME;
    Rect_16 enemy = ENEMY_BATTLER_FRAME;
    Rect_16 enemyHP = ENEMY_RESOURCE_FRAME;
    Rect_16 dialogue = DIALOGUE_BOX_FRAME;


    const SpriteLayout pLayout = Flash_GetBattlerLayout(memory, GetCreatureType(g_core.battleMode.enemyMonsterID), false);
    DrawBattler(graphics, memory, player.x + 24, player.y, &pLayout, CREATURE, false);

    const SpriteLayout eLayout = Flash_GetBattlerLayout(memory, GetCreatureType(g_core.battleMode.enemyMonsterID), true);
    DrawBattler(graphics, memory, enemy.x + 24, enemy.y, &eLayout, CREATURE, true);

    CreatureStats(graphics, hardware, memory, g_core.battleMode.playerMonsterID, playerHP, size, font_size);
    CreatureStats(graphics, hardware, memory, g_core.battleMode.enemyMonsterID, enemyHP, size, font_size);


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

    x = dialogue.x + (20 * size);
    y = dialogue.y;
    i = 0;
    while (i < BATTLE_MENU_SIZE)
    {
        Flash_GetBattleMenuList(memory, (uint8_t*)line, i);
        y += PrintLineStr(graphics, memory, x, y, font_size, max_chars, line, indent);
        i++;
    }


    //combat log
    graphics.FillRect(dialogue.x, dialogue.y + (6 * size), dialogue.w, dialogue.h, Flash_GetColor(memory, PAL_BRIGHT_LIGHT_GRN));
    PrintLineStr(graphics, memory, dialogue.x, dialogue.y + (6 * size), font_size, 40, g_core.battleMode.combatLog[0], false);
    PrintLineStr(graphics, memory, dialogue.x, dialogue.y + (7 * size), font_size, 40, g_core.battleMode.combatLog[1], false);

    g_core.menu.colorCache = Flash_GetColor(memory, PAL_BRIGHT_CYAN);
}
