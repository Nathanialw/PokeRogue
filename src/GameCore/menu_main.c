//
// Created by nathanial on 3/8/26.
//
#include "menu_main.h"

#include "lib_decl.h"
#include "lib_debugging.h"
#include "lib_types.h"

#include "battles.h"
#include "constants.h"
#include "entities.h"
#include "memory_access.h"
#include "memory_rom.h"
#include "memory_ram.h"
#include "player.h"
#include "menu.h"
#include "utils.h"


/**********************************************************************************************************************/
/** Forward declared functions for the main menu
**********************************************************************************************************************/

bool MiniMap(InputInterface input, MemoryInterface memory, bool update);
bool MonsterData(InputInterface input, MemoryInterface memory, bool update);
bool Objectpedia(InputInterface input, MemoryInterface memory, bool update);
bool Itempedia(InputInterface input, MemoryInterface memory, bool update);
bool Spellpedia(InputInterface input, MemoryInterface memory, bool update);
bool Abilitypedia(InputInterface input, MemoryInterface memory, bool update);
bool Party(InputInterface input, MemoryInterface memory, bool update);
bool Bag(InputInterface input, MemoryInterface memory, bool update);
bool Spells(InputInterface input, MemoryInterface memory, bool update);
bool Options(InputInterface input, MemoryInterface memory, bool update);
bool Exit(InputInterface input, MemoryInterface memory, bool update);


/**********************************************************************************************************************/
/** Function pointers to control which submenu to display
 *  Use the menu cursor position y to index into this array
**********************************************************************************************************************/
SubMenu submenus[MAIN_MENUS_SIZE] = {
    MiniMap,
    MonsterData,
    Objectpedia,
    Itempedia,
    Spellpedia,
    Abilitypedia,
    Party,
    Bag,
    Spells,
    Options,
    Exit,
};

/**********************************************************************************************************************/
/**
 *      IMPLEMENTATIONS
 *
 *      For lists:
 *          -the initial call sets the string pointers of the list to the char strings of that list for display
 *          -subsequent calls use the selector to index into the list
 *
**********************************************************************************************************************/

/**********************************************************************************************************************/
/** MAP DISPLAY
 * Sets the current menu mode to minimap value
 *  the display code handles fetching the object data to draw the pixels to the screen
**********************************************************************************************************************/
bool MiniMap(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(MAP_SUBMENU, 0))
        return true;

    return true;
};


/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool MonsterData(InputInterface input, MemoryInterface memory, bool update)
{
    DEBUG("MonsterData g_run.btns.d.y %d", input.GetInputKeyState().d.y);
    if (ToggleMenu(MONSTER_DATA_LIST_SUBMENU, CREATURE_COUNT) && input.GetInputKeyState().d.y == 0)
    {
        if (ListJump(input, memory)) return true;

        EntityId creature_id = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
        DEBUG("Showing Creature id %d", creature_id);
        //open creature info panel
        g_run.menu.gameMenu.id = creature_id;
        // }
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_run.menu.menuScrollOffset[g_run.menu.depth].y;
    uint8_t max_s = min_s + g_run.menu.visibleMenuOptions;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    DEBUG("updating to ----   %d %d", min_s, max_s);
    while ((min_s + i) < max_s)
    {
        const char* spellStr = Flash_GetCreatureName(memory, min_s + i);
        DEBUG("text: ----   %s", spellStr);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
        {
            g_run.menu.text[i][j] = spellStr[i];
        }
        i++;
    }
    g_run.menu.text[i][0] = '\0';


    return true;
};


/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Objectpedia(InputInterface input, MemoryInterface memory, bool update)
{
    DEBUG("Objectpedia g_run.btns.d.y %d", input.GetInputKeyState().d.y);
    if (ToggleMenu(OBJECT_DATA_LIST_SUBMENU, OBJECT_COUNT) && input.GetInputKeyState().d.y == 0)
    {
        if (ListJump(input, memory)) return true;

        EntityId object_id = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
        DEBUG("Showing Object id %d", object_id);
        g_run.menu.gameMenu.id = object_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_run.menu.menuScrollOffset[g_run.menu.depth].y;
    uint8_t max_s = min_s + g_run.menu.visibleMenuOptions;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    DEBUG("updating to ----   %d %d", min_s, max_s);
    while ((min_s + i) < max_s)
    {
        const char* object_str = Flash_GetObjectName(memory, min_s + i);
        DEBUG("text: ----   %s", object_str);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
        {
            g_run.menu.text[i][j] = object_str[j];
        }

        i++;
    }
    g_run.menu.text[i][0] = '\0';


    return true;
};

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Itempedia(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(ITEM_DATA_LIST_SUBMENU, ITEM_COUNT) && input.GetInputKeyState().d.y == 0)
    {
        if (ListJump(input, memory)) return true;
        EntityId item_id = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
        DEBUG("Showing Item id %d", item_id);
        //open creature info panel
        g_run.menu.gameMenu.id = item_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_run.menu.menuScrollOffset[g_run.menu.depth].y;
    uint8_t max_s = min_s + g_run.menu.visibleMenuOptions;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    DEBUG("updating to ----   %d %d", min_s, max_s);
    while ((min_s + i) < max_s)
    {
        const char* spellStr = Flash_GetItemName(memory, min_s + i);
        DEBUG("text: ----   %s", spellStr);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
        {
            g_run.menu.text[i][j] = spellStr[j];
        }

        i++;
    }
    g_run.menu.text[i][0] = '\0';

    return true;
};

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Spellpedia(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(SPELL_DATA_LIST_SUBMENU, SPELL_COUNT) && input.GetInputKeyState().d.y == 0)
    {
        if (ListJump(input, memory)) return true;
        EntityId spell_id = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
        DEBUG("Showing Spell id %d", spell_id);
        //open creature info panel
        g_run.menu.gameMenu.id = spell_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_run.menu.menuScrollOffset[g_run.menu.depth].y;
    uint8_t max_s = min_s + g_run.menu.visibleMenuOptions;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    DEBUG("updating to ----   %d %d", min_s, max_s);
    while ((min_s + i) < max_s)
    {
        const char* spellStr = Flash_GetSpellName(memory, min_s + i);
        DEBUG("text: ----   %s", spellStr);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
        {
            g_run.menu.text[i][j] = spellStr[j];
        }

        i++;
    }
    g_run.menu.text[i][0] = '\0';

    return true;
}

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Abilitypedia(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(ABILITY_DATA_LIST_SUBMENU, ABILITY_COUNT) && input.GetInputKeyState().d.y == 0)
    {
        if (ListJump(input, memory)) return true;
        EntityId ability_id = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
        DEBUG("Showing Skill id %d", ability_id);
        //open creature info panel
        g_run.menu.gameMenu.id = ability_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_run.menu.menuScrollOffset[g_run.menu.depth].y;
    uint8_t max_s = min_s + g_run.menu.visibleMenuOptions;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    DEBUG("updating to ----   %d %d", min_s, max_s);
    while ((min_s + i) < max_s)
    {
        const char* abilityStr = Flash_GetSkillName(memory, min_s + i);
        DEBUG("text: ----   %s", spellStr);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
        {
            g_run.menu.text[i][j] = abilityStr[j];
        }

        i++;
    }
    g_run.menu.text[i][0] = '\0';

    return true;
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
void OpenUseOnParty(MemoryInterface memory, UseFrameBack f)
{
    DEBUG("creating party list to use");
    FillListByEntityID(memory, MAX_PARTY_SIZE, CREATURE, GetPlayerMonsterIDs());

    g_run.menu.forceRedraw = true;
    g_run.menu.useOnPartyMember = f;
    g_run.menu.visibleMenuOptions = MAX_PARTY_SIZE;

    g_run.menu.depth++;
    g_run.menu.sel[g_run.menu.depth].x = 0;
    g_run.menu.sel[g_run.menu.depth].y = 0;
    g_run.menu.visibleMenuOptions = ListSize(MAX_PARTY_SIZE);
    g_run.menu.totalMenuOptions = MAX_PARTY_SIZE;
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
void BackUseOnParty(MemoryInterface memory)
{
    DEBUG("creating bag list, already open");
    if (g_run.menu.useOnPartyMember == BACK_ITEM)
        FillListByEntityID(memory, g_run.player.currentBagSize, ITEM, g_run.player.itemID);
    if (g_run.menu.useOnPartyMember == BACK_SPELL)
        FillListByTypeID(g_run.player.currentSpellbookSize, g_run.player.spellID);
    else
        DEBUG("void BackUseOnParty() invalid 'else' hit %d", g_run.menu.useOnPartyMember);

    g_run.menu.sel[g_run.menu.depth].x = 0;
    g_run.menu.sel[g_run.menu.depth].y = 0;
    g_run.menu.depth--;
    g_run.menu.forceRedraw = true;
    g_run.menu.lineHeight = 0;
    g_run.menu.visibleMenuOptions = ListSize(g_run.player.currentBagSize);
    g_run.menu.totalMenuOptions = g_run.player.currentBagSize;
    g_run.menu.useOnPartyMember = BACK_NONE;
}

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Party(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(MONSTERS_SUBMENU, MAX_PARTY_SIZE))
    {
    }

    FillListByEntityID(memory, MAX_PARTY_SIZE, CREATURE, GetPlayerMonsterIDs());
    return true;
};

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Bag(InputInterface input, MemoryInterface memory, bool update)
{
    DEBUG("initing bag");
    if (ToggleMenu(BAG_SUBMENU, g_run.player.currentBagSize))
    {
        DEBUG("bag already open, %d", g_run.menu.depth);
        //open use/toss menu
        //if use/toss menu open, select cursor option

        //if use
        //use item on self, return true is success, false if usable on party
        if (g_run.menu.depth == 1)
        {
            uint8_t idx = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
            EntityId item_id = g_run.player.itemID[idx];
            DEBUG("open party screen %d %d", idx, item_id);

            if (item_id == NO_ITEM)
            {
                DEBUG("no item in that bag slot");
                //maybe an error sound
                return true;
            }

            if (UseItem(memory, item_id, NO_ENTITY))
                ConsumeItem(idx, item_id);
            else
                OpenUseOnParty(memory, BACK_ITEM);

            return true;
        }

        uint8_t idx = g_run.menu.sel[g_run.menu.depth - 1].y + g_run.menu.menuScrollOffset[g_run.menu.depth - 1].y;
        EntityId item_id = g_run.player.itemID[idx];
        EntityId entity_id = g_run.player.partyID[g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y];
        DEBUG("open party screen %d %d %d", idx, item_id, entity_id);

        if (UseItem(memory, item_id, entity_id))
        {
            ConsumeItem(idx, item_id);
            BackUseOnParty(memory);
        }
        else
        {
            DEBUG("falied to use item");
            //display error message why the item could not be used
        }

        //if toss
        //remove item from bag
        //set item on ground
        //close use/toss menu

        return true;
    }
    DEBUG("crating bag list");

    FillListByEntityID(memory, g_run.player.currentBagSize, ITEM, g_run.player.itemID);
    return true;
};

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Spells(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(SPELLS_SUBMENU, g_run.player.currentSpellbookSize))
    {
        if (g_run.menu.depth == 1)
        {
            uint8_t idx = g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y;
            EntityId spell_id = g_run.player.spellID[idx];
            DEBUG("open party screen %d %d", idx, spell_id);

            if (spell_id == NO_SPELL)
            {
                DEBUG("no spell in that spellbook page");
                //maybe an error sound
                return true;
            }

            if (!CastSpell(memory, spell_id, NO_ENTITY, NO_ENTITY))
                OpenUseOnParty(memory, BACK_SPELL);

            return true;
        }

        uint8_t idx = g_run.menu.sel[g_run.menu.depth - 1].y + g_run.menu.menuScrollOffset[g_run.menu.depth - 1].y;
        EntityId spell_id = g_run.player.spellID[idx];
        EntityId entity_id = g_run.player.partyID[g_run.menu.sel[g_run.menu.depth].y + g_run.menu.menuScrollOffset[g_run.menu.depth].y];
        DEBUG("open party screen %d %d %d", idx, spell_id, entity_id);

        if (CastSpell(memory, spell_id, entity_id, NO_ENTITY))
            BackUseOnParty(memory);

        return true;
    }

    FillListByTypeID(g_run.player.currentSpellbookSize, g_run.player.spellID);
    return true;
};

/**********************************************************************************************************************/
/** LIST
**********************************************************************************************************************/
bool Options(InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(OPTIONS_SUBMENU, OPTIONS_MENU_SIZE))
    {
        //run a switch or a func ptr array against the sel at the current depth
        switch (g_run.menu.sel[g_run.menu.depth].y)
        {
        case 0:
            {
                if (g_run.settings.fontSize == FONT8x8)
                    g_run.settings.fontSize = FONT16x16;
                else
                    g_run.settings.fontSize = FONT8x8;

                g_run.menu.displayedMenu = MENU_NONE;
                break;
            }
        case 1:
            {
                break;
            }
        case 2:
            {
                g_run.btns.gameSpeed += input.GetInputKeyState().d.x;
                if (g_run.btns.gameSpeed > 10 || g_run.btns.gameSpeed < 0)
                {
                    g_run.btns.gameSpeed += (-input.GetInputKeyState().d.x);
                    break;
                }

                /*******************************************
                 * update game speed value
                 */
                CharStr_uint8 gameSpeedStr;
                GetAsChars_uint8(g_run.btns.gameSpeed, &gameSpeedStr, false);
                uint8_t i = 0;
                const char* option_2 = Flash_GetOptionText(memory, 2);
                while (option_2[i])
                {
                    g_run.btns.gameSpeedStr[i] = option_2[i];
                    i++;
                }
                g_run.btns.gameSpeedStr[i] = ' ';
                i++;
                uint8_t j = 0;
                while (gameSpeedStr[i])
                {
                    g_run.btns.gameSpeedStr[i] = gameSpeedStr[j];
                    j++;
                    i++;
                }
                for (uint8_t i = 0; i < SMALL_STRINGS; i++)
                {
                    g_run.menu.text[2][j] = g_run.btns.gameSpeedStr[j];
                }

                DEBUG("g_run.btns.gameSpeed %d", g_run.btns.gameSpeed);
                break;
            }
        default:
            {
                return true;
            };
        }

        return true;
    }


    CharStr_uint8 gameSpeedStr;
    GetAsChars_uint8(g_run.btns.gameSpeed, &gameSpeedStr, false);
    uint8_t i = 0;

    const char* option_2 = Flash_GetOptionText(memory, 2);
    while (option_2[i])
    {
        g_run.btns.gameSpeedStr[i] = option_2[i];
        i++;
    }
    g_run.btns.gameSpeedStr[i] = ' ';
    i++;
    uint8_t j = 0;
    while (gameSpeedStr[i])
    {
        g_run.btns.gameSpeedStr[i] = gameSpeedStr[j];
        j++;
        i++;
    }


    const char* option_0 = Flash_GetOptionText(memory, 0);
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        g_run.menu.text[0][j] = option_0[j];
        g_run.menu.text[1][j] = g_run.hardware.volts[j];
        g_run.menu.text[2][j] = g_run.btns.gameSpeedStr[j];
    }
    g_run.menu.text[3][0] = '\0';

    return true;
};

/**********************************************************************************************************************/
/** Closes the main menu
**********************************************************************************************************************/
bool Exit(InputInterface input, MemoryInterface memory, bool update)
{
    g_run.menu.displayedMenu = MENU_NONE;
    Back(MAIN_MENU);
    return false;
};

/**********************************************************************************************************************/
/** Opens the submenu at the index of the cursor y position
**********************************************************************************************************************/
bool OpenSubMenu(InputInterface input, MemoryInterface memory)
{
    DEBUG("opening submenu, %d", g_run.menu.sel[0].y);
    bool r = submenus[g_run.menu.sel[0].y](input, memory, true); //always use the base index of zero to access the the menu branch
    return r;
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
bool MenuBack(MemoryInterface memory)
{
    //TODO: check if a comfirmation box is open, close it


    if (g_run.menu.gameMenu.open)
    {
        g_run.menu.gameMenu.id = NO_CREATURE;
        g_run.menu.gameMenu.displayId = NO_CREATURE;
        g_run.menu.gameMenu.open = false;
    }

    if (g_run.menu.selectedMenu == MAIN_MENU)
    {
        g_run.menu.displayedMenu = MENU_NONE;
        return false;
    }

    // handle back from using on a party member
    if (g_run.menu.useOnPartyMember)
        BackUseOnParty(memory);

    Back(MAIN_MENU);

    return true;
}

/**********************************************************************************************************************/
/** Sets Menu to open
 *  Reset menu cache values to defaults
**********************************************************************************************************************/
void InitMainMenu(void)
{
    g_run.menu.x = MAIN_MENU_X;
    g_run.menu.y = (MAIN_MENU_Y + 1);
    g_run.menu.h = MAIN_MENU_H;
    g_run.menu.subMenus = submenus;

    g_run.menu.visibleMenuOptions = MAIN_MENUS_SIZE;
    g_run.menu.depth = 0;
    g_run.menu.sel[g_run.menu.depth].x = 0;
    g_run.menu.sel[g_run.menu.depth].y = 0;

    g_run.menu.forceRedraw = true;
    g_run.menu.selectedMenu = MAIN_MENU;
    g_run.menu.displayedMenu = MENU_NONE;
}
