//
// Created by nathanial on 2/22/26.
//

#include "core_effects.h"
#include "core_entities.h"
#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"

#include "lib_debugging.h"
#include "lib_memory.h"
#include "map_effects.h"
#include "map_entities.h"


/**********************************************************************************************************************
*
 *  OBJECT INTERACT EFFECTS
 *
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SetUsed(EntityId e_id)
{
    if (!GetBit(g_core.objects.interactable, e_id))
        return false;
    SetBit(g_core.objects.interactable, e_id, false);
    return true;
}

SET_MEMORY(".map")
bool CheckUsed(EntityId e_id)
{
    if (!GetBit(g_core.objects.interactable, e_id))
        return false;
    return true;
}

/**********************************************************************************************************************
*  TODO run the effect stored as the index in the metadata field
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractAltar(HardwareInterface hardware, EntityId item_id, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAltar");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
 *  TODO chance of random movement
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractRaft(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRaft");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractRowBoat(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRowBoat");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO chance of breaking when walked on
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractRopeBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRopeBridge");
    return NoEffect();
}

/**********************************************************************************************************************
*  TODO chance of spawning a troll
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractStoneBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStoneBridge");
    return NoEffect();
}

/**********************************************************************************************************************
* TODO supersedes the effect of water lava and acid
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWoodenBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodenBridge");
    return NoEffect();
}

/**********************************************************************************************************************
*  TODO generates a spellbook or skillbook item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBookCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        Position pos = GetEntityPosition(OBJECT, object_id);
        uint8_t n = hardware.GetRandom_uint8_t(0, 1);
        if (n == 0)
            SpawnEntity(hardware, memory, ITEM, SPELL_BOOK, pos.x, pos.y, 0);
        else
            SpawnEntity(hardware, memory, ITEM, ABILITY_BOOK, pos.x, pos.y, 0);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO generates a ring or amulet item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractJewelleryCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        Position pos = GetEntityPosition(OBJECT, object_id);
        // TODO pick a random of the correwct item type
        SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO generates a random scroll
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractScrollCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        Position pos = GetEntityPosition(OBJECT, object_id);
        SpawnEntity(hardware, memory, ITEM, SCROLL, pos.x, pos.y, 0);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*   TODO spawns a random potion
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCauldron(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        Position pos = GetEntityPosition(OBJECT, object_id);
        // TODO pick a random of the correct item type
        SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO chance to do damage
*  TODO chance to melt items in bag
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractAcidCloud(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidCloud");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO chance to apply poison
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractPoisonGas(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractPoisonGas");
    return ApplyPoison(e_id, 1);
}

/**********************************************************************************************************************
*  TODO chance to do damage
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractSmokeCloud(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSmokeCloud");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCoffin(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCoffin");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractSarcophagus(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSarcophagus");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractHangingCorpse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractHangingCorpse");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractLaidCorpse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLaidCorpse");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBarredDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBarredDoor");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractIronDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractIronDoor");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractStoneDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStoneDoor");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWickerDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWickerDoor");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWoodDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodDoor");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO add a success chance
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractLadder(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLadder");
    if (GetPlayerID() == e_id)
        return MapAscend(hardware, memory, g_core.player.id);
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractStairs(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStairs");
    if (GetPlayerID() == e_id)
        return MapDescend(hardware, memory, g_core.player.id);
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCave(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCave");
    if (GetPlayerID() == e_id)
        return MapLateral(hardware, memory, g_core.player.id);
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBonfire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBonfire");
    if (g_core.objects.interactable[e_id])
    {
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBrazier(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBrazier");
    if (g_core.objects.interactable[e_id])
    {
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCampfire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCampfire");
    if (g_core.objects.interactable[e_id])
    {
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractStandingTorch(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStandingTorch");
    if (g_core.objects.interactable[e_id])
    {
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWallTorch(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWallTorch");
    if (g_core.objects.interactable[e_id])
    {
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO add chacne to descend when walked on
*  TODO deals damage
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCrumblingFloor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCrumblingFloor");
    if (GetPlayerID() == e_id)
    {
        MapDescend(hardware, memory, g_core.player.id);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO deals damage
*  TODO melts items
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractAcidFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return ACTION_CANNOT;
    }

    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Acid Fountain restoring 20 Mana to party member 0");
        return ACTION_SUCCEEDED;
    }

    DEBUG("party member 0 already at max mana");
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO heals demons
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBloodFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return ACTION_CANNOT;
    }
    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Blood Fountain restoring 20 Mana to party member 0");
        return ACTION_SUCCEEDED;
    }
    DEBUG("party member 0 already at max mana");
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWaterFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return ACTION_CANNOT;
    }

    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Water Fountain restoring 20 Mana to party member 0");
        return ACTION_SUCCEEDED;
    }

    DEBUG("party member 0 already at max mana");
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWell(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWell");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return ACTION_CANNOT;
    }

    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    GainXP(creature_id, objectData.power);
    SetUsed(object_id);
    DEBUG("Drank from Well gaining XP for a party member");
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  TODO no sprite
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractHiddenCompartment(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractHiddenCompartment");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractAcidPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractLavaPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLavaPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractNarowPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractNarowPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractShallowPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractShallowPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractSnakesPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSnakesPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractSpikedPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSpkiedPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractPitStandard(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractPitStandard");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWaterPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWaterPit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWidePit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWidePit");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractArmorRack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractArmorRack");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWeaponRack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWeaponRack");
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBarrel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBarrel");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractBasket(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBasket");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractChest(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractChest");
    if (SetUsed(e_id))
    {
        uint8_t x = 20;
        uint8_t y = 20;
        uint8_t l = 20;
        return CreateItemMagic(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCoffer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCoffer");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractCrate(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCrate");
    if (SetUsed(e_id))
    {


        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractTrunk(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractTrunk");
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractUrn(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractVault(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
    {
        uint8_t x = g_core.objects.position[object_id].x;
        uint8_t y = g_core.objects.position[object_id].y;
        uint8_t l = 1;
        return CreateItemCommon(hardware, memory, ITEM, x, y, l);
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  TODO collision for random creatures
*  TODO no collision for trainers
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractWard(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWard");
    return false;
}
