//
// Created by nathanial on 3/8/26.
//
#include "map_menu.h"

#include "constants.h"

#include "lib_decl.h"
#include "lib_memory.h"
#include "lib_types.h"

#include "core_entities.h"
#include "core_menu.h"
#include "core_ram.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_state.h"
#include "core_utils.h"
#include "lib_debugging.h"
#include "map_actions.h"

#include "map_graphics.h"
#include "map_memory_access.h"
#include "map_rendering.h"


/**********************************************************************************************************************
** Forward declared functions for the main menu
**********************************************************************************************************************/

bool MiniMap(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool MonsterData(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Objectpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Itempedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Spellpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Abilitypedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Trainerpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Party(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Bag(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Spells(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Religion(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Options(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
bool Exit(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);


/**********************************************************************************************************************
** Function pointers to control which submenu to display
 *  Use the menu cursor position y to index into this array
**********************************************************************************************************************/
SET_MEMORY(".map.rodata")
SubMenu submenus[MAIN_MENUS_SIZE] = {
    MiniMap,
    MonsterData,
    Objectpedia,
    Itempedia,
    Spellpedia,
    Abilitypedia,
    Trainerpedia,
    Party,
    Bag,
    Spells,
    Religion,
    Options,
    Exit,
};

/**********************************************************************************************************************
**
 *      IMPLEMENTATIONS
 *
 *      For lists:
 *          -the initial call sets the string pointers of the list to the char strings of that list for display
 *          -subsequent calls use the selector to index into the list
 *
**********************************************************************************************************************/

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Back(SubMainMenuWindow menuWin)
{
    if (g_core.menu.selectedMenu == menuWin)
        return true;

    g_core.menu.lineHeight = 0;
    if (g_core.menu.useOnPartyMember)
    {
        g_core.menu.useOnPartyMember = BACK_NONE;
        g_core.menu.forceRedraw = true;
        return true;
    }

    g_core.menu.selectedMenu = menuWin;
    g_core.menu.occupied_visible_menu_options = MAIN_MENUS_SIZE;
    g_core.menu.max_visible_menu_options = MAIN_MENUS_SIZE;
    g_core.menu.menuScrollOffset[g_core.menu.depth].y = 0;
    g_core.menu.depth--;
    return true;
}


/**********************************************************************************************************************
** Sets Menu to open
 *  Reset menu cache values to defaults
**********************************************************************************************************************/
SET_MEMORY(".map")
void InitMainMenu(void)
{
    g_core.menu.x = MAIN_MENU_X;
    g_core.menu.y = (MAIN_MENU_Y + 1);
    g_core.menu.h = MAIN_MENU_H;
    g_core.menu.x_offset = 0;
    g_core.menu.subMenus = submenus;

    g_core.menu.max_visible_menu_options = MAIN_MENUS_SIZE;
    g_core.menu.occupied_visible_menu_options = MAIN_MENUS_SIZE;
    g_core.menu.depth = 0;
    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;

    g_core.menu.forceRedraw = true;
    g_core.menu.selectedMenu = MAIN_MENU;
    g_core.menu.displayedMenu = MENU_NONE;
}


// bool ToggleMenu(SubMainMenuWindow menuWin, uint8_t occupied_visible_menu_options, uint8_t max_visible_menu_options);


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool ToggleMenu(SubMainMenuWindow menuWin, uint8_t occupied_visible_menu_options, uint8_t max_visible_menu_options)
{
    if (g_core.menu.selectedMenu == menuWin)
    {
        return true;
    }
    g_core.menu.depth++;
    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.selectedMenu = menuWin;
    g_core.menu.occupied_visible_menu_options = ListSize(occupied_visible_menu_options);
    g_core.menu.max_visible_menu_options = ListSize(max_visible_menu_options);
    g_core.menu.totalMenuOptions = max_visible_menu_options;
    ClearMenu();
    return false;
}

/**********************************************************************************************************************
** MAP DISPLAY
 * Sets the current menu mode to minimap value
 *  the display code handles fetching the object data to draw the pixels to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MiniMap(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(MAP_SUBMENU, 0, 0))
        return true;

    return true;
};


/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MonsterData(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(MONSTER_DATA_LIST_SUBMENU, CREATURE_COUNT, CREATURE_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;

        EntityId creature_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        g_core.menu.gameMenu.id = creature_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;

    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum

    while ((min_s + i) < max_s)
    {
        Flash_GetCreatureName(memory, g_core.menu.text[i], min_s + i);
        i++;
    }
    g_core.menu.text[i][0] = '\0';


    return true;
};


/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Objectpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(OBJECT_DATA_LIST_SUBMENU, OBJECT_COUNT, OBJECT_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;

        EntityId object_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        g_core.menu.gameMenu.id = object_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    while ((min_s + i) < max_s)
    {
        Flash_GetObjectName(memory, g_core.menu.text[i], min_s + i);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
            i++;
    }
    g_core.menu.text[i][0] = '\0';


    return true;
};

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Itempedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(ITEM_DATA_LIST_SUBMENU, ITEM_COUNT, ITEM_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;
        EntityId item_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        //open creature info panel
        g_core.menu.gameMenu.id = item_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum

    while ((min_s + i) < max_s)
    {
        Flash_GetItemName(memory, g_core.menu.text[i], min_s + i);
        i++;
    }
    g_core.menu.text[i][0] = '\0';

    return true;
};

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Spellpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(SPELL_DATA_LIST_SUBMENU, SPELL_COUNT, SPELL_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;
        EntityId spell_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        //open creature info panel
        g_core.menu.gameMenu.id = spell_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    while ((min_s + i) < max_s)
    {
        Flash_GetSpellName(memory, g_core.menu.text[i], min_s + i);
        for (uint8_t j = 0; j < SMALL_STRINGS; j++)
            i++;
    }
    g_core.menu.text[i][0] = '\0';

    return true;
}

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Abilitypedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(ABILITY_DATA_LIST_SUBMENU, ABILITY_COUNT, ABILITY_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;
        EntityId ability_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        //open creature info panel
        g_core.menu.gameMenu.id = ability_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    while ((min_s + i) < max_s)
    {
        Flash_GetSkillName(memory, g_core.menu.text[i], min_s + i);
        i++;
    }
    g_core.menu.text[i][0] = '\0';

    return true;
}


/**********************************************************************************************************************
** LIST /TODO: add the
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Trainerpedia(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(TRAINER_DATA_LIST_SUBMENU, ABILITY_COUNT, ABILITY_COUNT) && input.GetInputKeyState().dp.y == 0)
    {
        if (ListJump(graphics, hardware, input, memory)) return true;
        EntityId ability_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        g_core.menu.gameMenu.id = ability_id;
        return true;
    }

    uint8_t i = 0;
    uint8_t min_s = g_core.menu.menuScrollOffset[g_core.menu.depth].y;
    uint8_t max_s = min_s + g_core.menu.max_visible_menu_options;
    if (max_s >= 255) max_s = 255; //prevent wraparound, assumes NO_CREATURE is max in Creature enum
    while ((min_s + i) < max_s)
    {
        Flash_GetTrainerName(memory, g_core.menu.text[i], min_s + i);
        i++;
    }
    g_core.menu.text[i][0] = '\0';

    return true;
}


/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
void OpenUseOnSpellPage(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f)
{
    EntityId player_id = GetPlayerID();
    FillListByTypeID(memory, g_core.player.currentSpellbookSize, g_core.trainers.spellID[player_id]);

    g_core.menu.forceRedraw = true;


    g_core.menu.depth++;
    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.max_visible_menu_options = ListSize(g_core.player.currentSpellbookMaxSize);
    g_core.menu.occupied_visible_menu_options = g_core.player.currentSpellbookSize;
    g_core.menu.totalMenuOptions = g_core.player.currentSpellbookSize;
}


/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
void OpenUseOnParty(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f)
{
    FillListByEntityID(memory, MAX_PARTY_SIZE, CREATURE, GetPlayerMonsterIDs());

    g_core.menu.forceRedraw = true;
    g_core.menu.useOnPartyMember = f;

    g_core.menu.max_visible_menu_options = ListSize(MAX_PARTY_SIZE);
    g_core.menu.occupied_visible_menu_options = g_core.player.currentPartySize;
    g_core.menu.totalMenuOptions = MAX_PARTY_SIZE;

    g_core.menu.depth++;
    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
}

/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
void BackUseOnParty(MemoryInterface memory)
{
    EntityId player_id = GetPlayerID();
    if (g_core.menu.useOnPartyMember == BACK_ITEM)
    {
        FillListByEntityID(memory, g_core.player.occupiedBagSlots, ITEM, g_core.trainers.itemID[player_id]);
        g_core.menu.max_visible_menu_options = ListSize(g_core.player.currentBagMaxSize);
        g_core.menu.occupied_visible_menu_options = ListSize(g_core.player.occupiedBagSlots);
        g_core.menu.totalMenuOptions = g_core.player.occupiedBagSlots;
    }
    if (g_core.menu.useOnPartyMember == BACK_SPELL)
    {
        FillListByTypeID(memory, g_core.player.currentSpellbookSize, g_core.trainers.spellID[player_id]);
        g_core.menu.max_visible_menu_options = ListSize(g_core.player.currentSpellbookMaxSize);
        g_core.menu.occupied_visible_menu_options = ListSize(g_core.player.currentSpellbookSize);
        g_core.menu.totalMenuOptions = g_core.player.currentSpellbookSize;
    }

    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.depth--;
    g_core.menu.forceRedraw = true;
    g_core.menu.lineHeight = 0;
    g_core.menu.useOnPartyMember = BACK_NONE;
}


/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Party(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(MONSTERS_SUBMENU, g_core.player.currentPartySize, MAX_PARTY_SIZE))
    {
        uint8_t target_index = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        EntityId party_id1 = g_core.trainers.partyID[GetPlayerID()][0];
        EntityId party_id2 = g_core.trainers.partyID[GetPlayerID()][target_index];
        g_core.trainers.partyID[GetPlayerID()][0] = party_id2;
        g_core.trainers.partyID[GetPlayerID()][target_index] = party_id1;
        FillListByEntityID(memory, g_core.player.currentPartySize, CREATURE, GetPlayerMonsterIDs());
        DrawParty(graphics, hardware, memory);
    }

    FillListByEntityID(memory, g_core.player.currentPartySize, CREATURE, GetPlayerMonsterIDs());
    return true;
};

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Bag(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    EntityId player_id = GetPlayerID();
    if (ToggleMenu(BAG_SUBMENU, g_core.player.occupiedBagSlots, g_core.player.currentBagMaxSize))
    {
        //open use/toss menu
        //if use/toss menu open, select cursor option

        //if use
        //use item on self, return true is success, false if usable on party
        if (g_core.menu.depth == 1)
        {
            uint8_t idx = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
            EntityId item_id = g_core.trainers.itemID[player_id][idx];

            if (item_id == NO_ITEM)
            {
                //maybe an error sound
                return true;
            }

            ItemData itemData;
            ItemTypes item_type = GetItemType(item_id);
            Flash_GetItemData(memory, &itemData, item_type);
            if (itemData.consumable_party)
            {
                OpenUseOnParty(hardware, memory, BACK_ITEM);
                return true;
            }

            if (itemData.consumable_spellbook)
            {
                OpenUseOnSpellPage(hardware, memory, BACK_ITEM);
                return true;
            }

            if (!itemData.consumable)
                return true;

            ActionOutcome action_outcome = UseItemMap(hardware, memory, &itemData, item_id, player_id, NO_ENTITY, 0);

            if (action_outcome == ACTION_SUCCEEDED)
            {
                PlayerConsumeItem(idx, item_id);
                FullRedraw(graphics, hardware, memory);
                FillListByEntityID(memory, g_core.player.occupiedBagSlots, ITEM, g_core.trainers.itemID[player_id]);
                DrawList(graphics, hardware, memory);
                return true;
            }
            else
            {
                return true;
            }
        }


        uint8_t item_idx = g_core.menu.sel[g_core.menu.depth - 1].y + g_core.menu.menuScrollOffset[g_core.menu.depth - 1].y;
        EntityId item_id = g_core.trainers.itemID[player_id][item_idx];
        uint8_t item_type = GetItemType(item_id);
        uint8_t target_index = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
        EntityId target_id = g_core.trainers.partyID[player_id][target_index];

        ItemData itemData;
        Flash_GetItemData(memory, &itemData, item_type);

        if (itemData.consumable_spellbook)
        {
            ActionOutcome action_outcome = UseItemMap(hardware, memory, &itemData, item_id, player_id, target_id, target_index);
            if (action_outcome == ACTION_SUCCEEDED)
            {
                PlayerConsumeItem(item_idx, item_id);
                BackUseOnParty(memory);
                DrawList(graphics, hardware, memory);
            }

            return true;
        }

        if (itemData.consumable_party)
        {
            ActionOutcome action_outcome = UseItemMap(hardware, memory, &itemData, item_id, player_id, target_id, target_index);;
            if (action_outcome == ACTION_SUCCEEDED)
            {
                PlayerConsumeItem(item_idx, item_id);
                BackUseOnParty(memory);
                DrawList(graphics, hardware, memory);
            }
            else
            {
                //display error message why the item could not be used
            }
        }

        //if toss
        //remove item from bag
        //set item on ground
        //close use/toss menu

        return true;
    }

    FillListByEntityID(memory, g_core.player.occupiedBagSlots, ITEM, g_core.trainers.itemID[player_id]);
    return true;
};

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Spells(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    EntityId player_id = GetPlayerID();
    if (ToggleMenu(SPELLS_SUBMENU, g_core.player.currentSpellbookSize, g_core.player.currentSpellbookMaxSize))
    {
        if (g_core.menu.depth == 1)
        {
            uint8_t spellbook_index = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
            EntityId spell_id = g_core.trainers.spellID[player_id][spellbook_index];

            if (spell_id == NO_SPELL)
            {
                //maybe an error sound
                return true;
            }

            SpellData spellData = {0};
            Flash_GetSpellData(memory, &spellData, spell_id);

            if (spellData.use_on_party_member)
            {
                OpenUseOnParty(hardware, memory, BACK_SPELL);
            }
            else
            {
                ActionOutcome action_outcome = CastSpellMap(hardware, memory, spell_id, spellbook_index, player_id, NO_ENTITY);
                MenuBack(memory);
                Exit(graphics, hardware, input, memory, false);
                SetInputState(INPUT_IDLE);
            }

            FullRedraw(graphics, hardware, memory);
            DrawList(graphics, hardware, memory);
            return true;
        }

        uint8_t spellbook_index = g_core.menu.sel[g_core.menu.depth - 1].y + g_core.menu.menuScrollOffset[g_core.menu.depth - 1].y;
        EntityId spell_id = g_core.trainers.spellID[player_id][spellbook_index];
        EntityId creature_id = g_core.trainers.partyID[player_id][g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y];

        ActionOutcome action_outcome = CastSpellMap(hardware, memory, spell_id, spellbook_index, player_id, creature_id);

        if (action_outcome == ACTION_SUCCEEDED)
        {
            BackUseOnParty(memory);
        }
        else if (action_outcome == ACTION_FAILED)
        {
            DEBUG("Spell failed on this target");
        }
        else if (action_outcome == ACTION_CANNOT)
        {
            DEBUG("Spell cannot be cast on this target");
        }

        return true;
    }

    FillListByTypeID(memory, g_core.player.currentSpellbookSize, g_core.trainers.spellID[player_id]);
    return true;
};

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Religion(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    return true;
}

/**********************************************************************************************************************
** LIST
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Options(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (ToggleMenu(OPTIONS_SUBMENU, OPTIONS_MENU_SIZE, OPTIONS_MENU_SIZE))
    {
        //run a switch or a func ptr array against the sel at the current depth
        switch (g_core.menu.sel[g_core.menu.depth].y)
        {
        case 0:
            {
                if (g_core.settings.fontSize == FONT8x8)
                    g_core.settings.fontSize = FONT16x16;
                else
                    g_core.settings.fontSize = FONT8x8;

                g_core.menu.displayedMenu = MENU_NONE;
                break;
            }
        case 1:
            {
                break;
            }
        case 2:
            {
                g_core.btns.gameSpeed += input.GetInputKeyState().dp.x;
                if (g_core.btns.gameSpeed > 10 || g_core.btns.gameSpeed < 0)
                {
                    g_core.btns.gameSpeed += (-input.GetInputKeyState().dp.x);
                    break;
                }

                /*******************************************
                 * update game speed value
                 ******************************************/
                CharStr_uint8 gameSpeedStr;
                GetAsChars_uint8(g_core.btns.gameSpeed, &gameSpeedStr, false);
                uint8_t i = 0;
                Flash_GetOptionText(memory, (uint8_t*)g_core.btns.gameSpeedStr, 2);
                i = 4;
                g_core.btns.gameSpeedStr[i] = ' ';
                i++;
                uint8_t j = 0;
                while (gameSpeedStr[i])
                {
                    g_core.btns.gameSpeedStr[i] = gameSpeedStr[j];
                    j++;
                    i++;
                }
                for (uint8_t i = 0; i < SMALL_STRINGS; i++)
                {
                    g_core.menu.text[2][j] = g_core.btns.gameSpeedStr[j];
                }

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
    GetAsChars_uint8(g_core.btns.gameSpeed, &gameSpeedStr, false);
    uint8_t i = 0;

    Flash_GetOptionText(memory, (uint8_t*)g_core.btns.gameSpeedStr, 2);
    i = 4;
    g_core.btns.gameSpeedStr[i] = ' ';
    i++;
    uint8_t j = 0;
    while (gameSpeedStr[i])
    {
        g_core.btns.gameSpeedStr[i] = gameSpeedStr[j];
        j++;
        i++;
    }


    Flash_GetOptionText(memory, (uint8_t*)g_core.menu.text[0], 0);
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
    {
        g_core.menu.text[1][j] = g_core.hardware.volts[j];
        g_core.menu.text[2][j] = g_core.btns.gameSpeedStr[j];
    }
    g_core.menu.text[3][0] = '\0';

    return true;
};

/**********************************************************************************************************************
** Closes the main menu
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Exit(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    g_core.menu.displayedMenu = MENU_NONE;
    Back(MAIN_MENU);
    return false;
};

/**********************************************************************************************************************
** Opens the submenu at the index of the cursor y position
**********************************************************************************************************************/
SET_MEMORY(".map")
bool OpenSubMenu(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    bool r = submenus[g_core.menu.sel[0].y](graphics, hardware, input, memory, true); //always use the base index of zero to access the the menu branch
    return r;
}

/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
bool MenuBack(MemoryInterface memory)
{
    //TODO: check if a comfirmation box is open, close it


    if (g_core.menu.gameMenu.open)
    {
        g_core.menu.gameMenu.id = NO_CREATURE;
        g_core.menu.gameMenu.displayId = NO_CREATURE;
        g_core.menu.gameMenu.open = false;
    }

    if (g_core.menu.selectedMenu == MAIN_MENU)
    {
        g_core.menu.displayedMenu = MENU_NONE;
        return false;
    }

    // handle back from using on a party member
    if (g_core.menu.useOnPartyMember)
        BackUseOnParty(memory);

    Back(MAIN_MENU);

    return true;
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

    FullRedraw(graphics, hardware, memory);
    DrawList(graphics, hardware, memory);
}
