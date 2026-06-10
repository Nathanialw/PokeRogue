//
// Created by nathanial on 3/8/26.
//
#include "battle_menu.h"

#include "lib_memory.h"
#include "lib_decl.h"

#include "battle_actions.h"
#include "battle_graphics.h"
#include "battle_ram.h"
#include "battle_state.h"
#include "battle_ui.h"

#include "core_actions.h"
#include "core_entities.h"
#include "core_graphics.h"
#include "core_memory_access.h"
#include "core_menu.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_state.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef enum
{
    ABILITY_MENU,
    BATTLE_MENU,
} BattleMenu;

SET_MEMORY(".battle.data")
BattleMenu battleMenu = ABILITY_MENU;

/**********************************************************************************************************************/
/** Open list frame
 *  Set menu cursor cache data to defaults for lists
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool EnterMenu(const uint8_t listSize)
{
    if (g_core.menu.depth > 0)
    {
        return true;
    }
    g_core.menu.depth++;
    g_core.menu.visibleMenuOptions = listSize;
    g_core.menu.menuScrollOffset[g_core.menu.depth].y = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.x = PLAYER_BATTLER_FRAME.x / TEXT_W;
    g_core.menu.y = (PLAYER_BATTLER_FRAME.y / TEXT_W) + 1;
    g_core.menu.w = 0;

    return false;
}

/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
void OpenUseOnPartyBattle(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f)
{
    FillListByEntityID(memory, g_core.player.currentPartySize, CREATURE, GetPlayerMonsterIDs());
    g_core.menu.useOnPartyMember = f;
    g_core.menu.visibleMenuOptions = g_core.player.currentPartySize;

    g_core.menu.depth++;

    g_core.menu.menuScrollOffset[g_core.menu.depth].y = 0;
    g_core.menu.x = PLAYER_BATTLER_FRAME.x / TEXT_W;
    g_core.menu.y = (PLAYER_BATTLER_FRAME.y / TEXT_W) + 1;
    g_core.menu.w = 0;

    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.totalMenuOptions = g_core.player.currentPartySize;
    g_battle.show_party = true;
}

/**********************************************************************************************************************
**
**********************************************************************************************************************/
SET_MEMORY(".map")
void CloseUseOnPartyBattle(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f)
{
    g_core.menu.useOnPartyMember = BACK_NONE;
    g_core.menu.menuScrollOffset[g_core.menu.depth].y = 0;
    g_core.menu.x = PLAYER_BATTLER_FRAME.x / TEXT_W;
    g_core.menu.y = (PLAYER_BATTLER_FRAME.y / TEXT_W) + 1;
    g_core.menu.w = 0;

    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;

    EntityId player_id = GetPlayerID();
    if (f == BACK_ITEM)
    {
        g_core.menu.visibleMenuOptions = g_core.player.currentBagSize;
        g_core.menu.totalMenuOptions = g_core.player.currentBagSize;
        FillListByEntityID(memory, g_core.player.currentBagSize, ITEM, g_core.trainers.itemID[player_id]);
    }
    else
    {
        g_core.menu.visibleMenuOptions = MAX_SPELLBOOK_SIZE;
        FillListByTypeID(memory, g_core.player.currentSpellbookSize, g_core.trainers.spellID[player_id]);
        g_core.menu.totalMenuOptions = MAX_SPELLBOOK_SIZE;
    }

    g_core.menu.lineHeight = 0;
    g_battle.show_party = false;
    g_core.menu.depth--;
}

/**********************************************************************************************************************/
/** Set menu cursor cache data to defaults
 *  Close main menu
**********************************************************************************************************************/
SET_MEMORY(".battle")
void ExitMenu(void)
{
    if (g_core.menu.depth > 0)
    {
        g_battle.show_party = false;
        ClearMenu();
        g_core.menu.sel[g_core.menu.depth].y = 0;
        g_core.menu.menuScrollOffset[g_core.menu.depth].y = 0;
        g_core.menu.visibleMenuOptions = BATTLE_MENU_SIZE;
        g_core.menu.x = BATTLE_MENU_X;
        g_core.menu.y = BATTLE_MENU_Y;
        g_core.menu.w = BATTLE_MENU_COL_2;
        g_core.menu.depth--;
        g_core.menu.lineHeight = 0;
    }
}

/**********************************************************************************************************************/
/** Initial invocation updates the string list cache for display, opening the party frame
 *  Subsequent invocation sets the creature at the cursor position as the active battle creature
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleSwap(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    EntityId p_ID = GetPlayerID();
    if (EnterMenu(g_core.player.currentPartySize))
    {
        uint8_t sel = g_core.menu.sel[g_core.menu.depth].y;
        if (GetCreatureType(g_core.trainers.partyID[p_ID][sel]) == NO_CREATURE) return true;
        g_core.battleMode.playerMonsterID = g_core.trainers.partyID[p_ID][sel];
        g_battle.show_party = false;
        g_battle.pass_turn = true;
        return true;
    }


    g_battle.show_party = true;
    FillListByEntityID(memory, g_core.player.currentPartySize, CREATURE, GetPlayerMonsterIDs());
    return true;
}

/**********************************************************************************************************************/
/** Initial invocation updates the string list cache for display, opening the spellbook list frame
 *  Subsequent invocation runs the spell action for the spell id at the cursor index of the spellbook
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleSpell(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    EntityId p_ID = GetPlayerID();
    if (EnterMenu(g_core.player.currentSpellbookSize))
    {
        uint8_t spellbook_index = g_core.menu.sel[g_core.menu.depth].y;
        SpellId spell_id = g_core.trainers.spellID[p_ID][spellbook_index];
        CastSpellBattle(hardware, memory, spell_id, spellbook_index, g_core.battleMode.playerMonsterID, g_core.battleMode.enemyMonsterID);
        g_battle.effect_animation_index = spell_id;
        g_battle.effect_type = SPELL;
        SetBattleState(BATTLE_ATTACK);
        //TODO: close menu
        g_battle.pass_turn = true;
        return true;
    }


    FillListByTypeID(memory, g_core.player.currentSpellbookSize, g_core.trainers.spellID[p_ID]);
    return true;
}


/**********************************************************************************************************************/
/** Initial invocation updates the string list cache for display, opening the backpack list frame
 *  Subsequent invocation runs the item action for the item id at the cursor index of the backpack
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleItems(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    EntityId player_id = GetPlayerID();
    if (EnterMenu(g_core.player.currentBagSize))
    {
        EntityId target_id = g_core.battleMode.playerMonsterID;

        uint8_t bag_idx = 0;
        EntityId item_id = 0;
        uint8_t item_type = 0;
        ItemData itemData = {0};

        if (!g_battle.show_party)
        {
            bag_idx = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
            item_id = g_core.trainers.itemID[player_id][bag_idx];
            item_type = GetItemType(item_id);
            Flash_GetItemData(memory, &itemData, item_type);


            if (itemData.consumable_party)
            {
                OpenUseOnPartyBattle(hardware, memory, BACK_ITEM);
                return true;
            }

            target_id = g_core.battleMode.enemyMonsterID;
        }
        else
        {
            bag_idx = g_core.menu.sel[g_core.menu.depth - 1].y + g_core.menu.menuScrollOffset[g_core.menu.depth - 1].y;
            target_id = g_core.menu.sel[g_core.menu.depth].y + g_core.menu.menuScrollOffset[g_core.menu.depth].y;
            item_id = g_core.trainers.itemID[player_id][bag_idx];
            item_type = GetItemType(item_id);
            Flash_GetItemData(memory, &itemData, item_type);
            CloseUseOnPartyBattle(hardware, memory, BACK_ITEM);
            PrintCombatLogText(hardware, memory, "Use Item on Party");
        }

        if (itemData.consumable)
        {
            if (UseItemBattle(hardware, memory, &itemData, item_id, player_id, target_id, 0))
            {
                ConsumeItem(bag_idx, item_id);
                g_battle.effect_animation_index = item_type;
                g_battle.effect_type = ITEM;
                PrintCombatLogText(hardware, memory, "Use Item Success, consumed");
            }
            else
            {
                PrintCombatLogText(hardware, memory, "Use Item Failed, not consumed");
            }
        }
        else if (UseItemBattle(hardware, memory, &itemData, item_id, player_id, target_id, 0))
        {
            g_battle.effect_animation_index = item_type;
            g_battle.effect_type = ITEM;
            PrintCombatLogText(hardware, memory, "Use Item Success");
        }
        else
        {
            PrintCombatLogText(hardware, memory, "Use Item Failed");
        }

        g_battle.pass_turn = true;
        ExitMenu();
        HandleBattle(graphics, hardware, memory);
        graphics.EndFrame();
        SetBattleState(BATTLE_ATTACK);
        return true;
    }

    FillListByEntityID(memory, g_core.player.currentBagSize, ITEM, g_core.trainers.itemID[player_id]);
    return true;
}

/**********************************************************************************************************************/
/** attempts the end the battle and queue a move to an empty adjacent map cell
 *  TODO: NOT YET IMPLEMENTED
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleFlee(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    if (EnterMenu(4))
    {
        return true;
    }

    return true;
}

/**********************************************************************************************************************/
/** display a full screen of teh combat lines cache
 *  TODO: NOT YET IMPLEMENTED
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleCombatLog(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update)
{
    // fire on initial entry
    if (EnterMenu(4))
    {
        return true;
    }

    return true;
}

/**********************************************************************************************************************/
/** Function pointer array for battle menu options
**********************************************************************************************************************/
SET_MEMORY(".battle.rodata")
SubMenu battleSubmenus[BATTLE_MENU_SIZE] =
{
    BattleSwap,
    BattleSpell,
    BattleItems,
    BattleCombatLog,
    BattleFlee,
};

/**********************************************************************************************************************/
/** Returns the number of usable abilities of the player's active battle creature
**********************************************************************************************************************/
SET_MEMORY(".battle")
uint8_t AbilityCount(void)
{
    uint8_t num_abilities = 0;
    while (num_abilities < MAX_ABILITIES)
    {
        if (g_core.creatures.attacks[g_core.battleMode.playerMonsterID][num_abilities] == NO_ABILITY) break;
        num_abilities++;
    }

    return num_abilities;
}

/**********************************************************************************************************************/
/** Sets battle menu cache data to defaults
 *  Sets input state to BATTLE
 *  Sets battle state to BATTLE_INIT to trigger drawing the battle screen procedure
**********************************************************************************************************************/
SET_MEMORY(".battle")
void InitBattleMenu(void)
{
    SetInputState(INPUT_BATTLE);
    g_core.menu.x = BATTLE_MENU_COL_1;
    g_core.menu.y = BATTLE_MENU_Y;
    g_core.menu.h = MAX_ABILITIES;

    g_core.menu.subMenus = battleSubmenus;
    g_core.menu.visibleMenuOptions = AbilityCount();

    g_core.menu.depth = 0;
    g_core.menu.sel[g_core.menu.depth].x = 0;
    g_core.menu.sel[g_core.menu.depth].y = 0;
    g_core.menu.selectedMenu = BATTLE_MENU;
}

/**********************************************************************************************************************/
/** toggles menu cache cursor data between the use ability list and the battle menu list
**********************************************************************************************************************/
SET_MEMORY(".battle")
void UpdateBattleMenu(InputInterface input, GraphicsInterface graphics, MemoryInterface memory)
{
    if (input.GetInputKeyState().dp.x == 0) return;
    if (g_core.menu.depth > 0) return;

    //clear old cursor before updating x
    const uint16_t x = g_core.menu.x * TEXT_W;
    const uint16_t list_y = g_core.menu.y * TEXT_H;
    const uint16_t erase_x = x + (g_core.menu.eraseSel.x * g_core.menu.w * TEXT_W);
    Color battler_menu_color = Flash_GetColor(memory, PAL_OFF_WHITE_GRAY);
    graphics.FillRect(erase_x, list_y + (g_core.menu.eraseSel.y * (TEXT_W + g_core.menu.lineHeight)), TEXT_W, TEXT_W, battler_menu_color);

    if (g_core.menu.w == BATTLE_MENU_COL_1)
    {
        battleMenu = BATTLE_MENU;
        g_core.menu.w = BATTLE_MENU_COL_2;
        g_core.menu.sel[g_core.menu.depth].y = 0;
        g_core.menu.visibleMenuOptions = BATTLE_MENU_SIZE;
    }
    else
    {
        battleMenu = ABILITY_MENU;
        g_core.menu.w = BATTLE_MENU_COL_1;
        g_core.menu.sel[g_core.menu.depth].y = 0;
        g_core.menu.visibleMenuOptions = AbilityCount();
    }
}

/**********************************************************************************************************************/
/** Main entry point for battle menu actions
 *  Checks which menu the cursor is active in
 *  Then runs the functino pointer at the cursor index
 *  Returns true if Attacking
 *  Returns false if menu
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool BattleMenuCommand(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory)
{
    bool use_skill_success = false;

    if (battleMenu == ABILITY_MENU)
        use_skill_success = UseSkill(hardware, memory, true);
    if (battleMenu == BATTLE_MENU)
        battleSubmenus[g_core.menu.sel[0].y](graphics, hardware, input, memory, true); //0 to enter the menu base entry point

    PrintCombatLogFull(graphics, memory);
    return use_skill_success;
}
