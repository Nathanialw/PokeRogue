//
// Created by nathanial on 2/22/26.
//

#include "core_effects.h"
#include "core_entities.h"
#include "core_player.h"
#include "core_ram.h"
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
bool InteractAltar(HardwareInterface hardware, EntityId item_id, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAltar");
    return false;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
 *  TODO chance of random movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRaft(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRaft");
    return false;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRowBoat(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRowBoat");
    return false;
}

/**********************************************************************************************************************
*  TODO chance of breaking when walked on
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRopeBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRopeBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
*  TODO chance of spawning a troll
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStoneBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStoneBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
* TODO supersedes the effect of water lava and acid
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWoodenBridge(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodenBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
*  TODO generates a spellbook or skillbook item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBookCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    Position pos = GetEntityPosition(OBJECT, object_id);
    // TODO pick a random of the correwct item type
    SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
    return false;
}

/**********************************************************************************************************************
*  TODO generates a ring or amulet item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractJewelleryCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    Position pos = GetEntityPosition(OBJECT, object_id);
    // TODO pick a random of the correwct item type
    SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
    return false;
}

/**********************************************************************************************************************
*  TODO generates a random scroll
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractScrollCase(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    ItemData itemData = {};
    Position pos = GetEntityPosition(OBJECT, object_id);
    // TODO pick a random of the correwct item type
    SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
    return false;
}

/**********************************************************************************************************************
*   TODO spawns a random potion
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCauldron(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    Position pos = GetEntityPosition(OBJECT, object_id);
    // TODO pick a random of the correwct item type
    SpawnEntity(hardware, memory, ITEM, POTION_HEALTH, pos.x, pos.y, 0);
    return false;
}

/**********************************************************************************************************************
*  TODO chance to do damage
*  TODO chance to melt items in bag
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidCloud(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidCloud");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to apply poison
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractPoisonGas(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    ApplyPoison(e_id, 1);
    DEBUG("InteractPoisonGas");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to do damage
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSmokeCloud(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSmokeCloud");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCoffin(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractCoffin");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSarcophagus(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractSarcophagus");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractHangingCorpse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractHangingCorpse");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLaidCorpse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractLaidCorpse");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBarredDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBarredDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractIronDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractIronDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStoneDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStoneDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWickerDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWickerDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWoodDoor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO add a success chance
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLadder(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLadder");
    if (GetPlayerID() == e_id)
        MapAscend(hardware, memory, g_core.player.id);
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStairs(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStairs");
    if (GetPlayerID() == e_id)
        MapDescend(hardware, memory, g_core.player.id);
    return true;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCave(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCave");
    if (GetPlayerID() == e_id)
        MapLateral(hardware, memory, g_core.player.id);
    return true;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBonfire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBonfire");
    if (g_core.objects.interactable[e_id])
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBrazier(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBrazier");
    if (g_core.objects.interactable[e_id])
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCampfire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCampfire");
    if (g_core.objects.interactable[e_id])
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStandingTorch(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStandingTorch");
    if (g_core.objects.interactable[e_id])
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWallTorch(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (g_core.objects.interactable[e_id])
        g_core.objects.toggle[e_id] = !g_core.objects.toggle[e_id];
    DEBUG("InteractWallTorch");
    return false;
}

/**********************************************************************************************************************
*  TODO add chacne to descend when walked on
*  TODO deals damage
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCrumblingFloor(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCrumblingFloor");
    if (GetPlayerID() == e_id)
        MapDescend(hardware, memory, g_core.player.id);
    return false;
}

/**********************************************************************************************************************
*  TODO deals damage
*  TODO melts items
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return false;
    }

    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Acid Fountain restoring 20 Mana to party member 0");
        return true;
    }

    DEBUG("party member 0 already at max mana");
    return false;
}

/**********************************************************************************************************************
*  TODO heals demons
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBloodFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return false;
    }
    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Blood Fountain restoring 20 Mana to party member 0");
        return true;
    }
    DEBUG("party member 0 already at max mana");
    return false;
}

/**********************************************************************************************************************
*  TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWaterFountain(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("TODO HAVE THE FOUNTAIN OPEN THE PART PAGE AND SELECT THE CREATURE, EFFECT BASED ON CREATURE TYPE");
    if (!CheckUsed(object_id))
    {
        DEBUG("Fountain already drained");
        return false;
    }

    EntityId creature_id = g_core.trainers.partyID[e_id][0];
    if (RestoreMana(creature_id, 20))
    {
        SetUsed(object_id);
        DEBUG("Drank from Water Fountain restoring 20 Mana to party member 0");
        return true;
    }

    DEBUG("party member 0 already at max mana");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWell(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWell");
    return false;
}

/**********************************************************************************************************************
*  TODO no sprite
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractHiddenCompartment(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractHiddenCompartment");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLavaPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLavaPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractNarowPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractNarowPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractShallowPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractShallowPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSnakesPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSnakesPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSpikedPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSpkiedPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractPitStandard(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractPitStandard");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWaterPit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWaterPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWidePit(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWidePit");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractArmorRack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractArmorRack");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWeaponRack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWeaponRack");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBarrel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractBarrel");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBasket(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractBasket");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractChest(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemMagic();
    DEBUG("InteractChest");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCoffer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractCoffer");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCrate(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    DEBUG("InteractCrate");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractTrunk(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemMagic();
    DEBUG("InteractTrunk");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractUrn(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractVault(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    if (SetUsed(e_id))
        CreateItemCommon();
    return false;
}

/**********************************************************************************************************************
*  TODO collision for random creatures
*  TODO no collision for trainers
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWard(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWard");
    return false;
}
