//
// Created by nathanial on 2/22/26.
//

#include "core_effects.h"
#include "core_ram.h"

#include "lib_debugging.h"
#include "lib_memory.h"
#include "map_effects.h"


/**********************************************************************************************************************
*
 *  OBJECT INTERACT EFFECTS
 *
**********************************************************************************************************************/

/**********************************************************************************************************************
*  TODO run the effect stored as the index in the metadata field
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAltar(HardwareInterface hardware, EntityId item_id, EntityId e_id, ObjectData itemData)
{
    DEBUG("InteractAltar");
    return false;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
 *  TODO chance of random movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRaft(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRaft");
    return false;
}

/**********************************************************************************************************************
*  TODO keeps the player on the boat when moved on water
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRowBoat(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRowBoat");
    return false;
}

/**********************************************************************************************************************
*  TODO chance of breaking when walked on
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractRopeBridge(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractRopeBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
*  TODO chance of spawning a troll
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStoneBridge(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStoneBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWoodenBridge(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodenBridge");
    NoEffect();
    return false;
}

/**********************************************************************************************************************
*  TODO generates a spellbook or skillbook item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBookCase(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBookCase");
    return false;
}

/**********************************************************************************************************************
*  TODO generates a ring or amulet item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractJewelleryCase(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractJewelleryCase");
    return false;
}

/**********************************************************************************************************************
*  TODO generates a random scroll
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractScrollCase(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractScrollCase");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCauldren(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCauldren");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to do damage
*  TODO chance to melt items in bag
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidCloud(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidCloud");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to apply poison
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractPoisonGas(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractPoisonGas");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to do damage
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSmokeCloud(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSmokeCloud");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCoffin(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCoffin");
    return false;
}

/**********************************************************************************************************************
*  TODO chance to spawn an undead
*  TODO chance to generate an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSarcophagus(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSarcophagus");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractHangingCorpse(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractHangingCorpse");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLaidCorpse(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLaidCorpse");
    return false;
}

/**********************************************************************************************************************
*  TODO has collision
*  TODO chance to break when the player moves onto
*  TODO chance to to damage when the player moves onto
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBarredDoor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
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
bool InteractIronDoor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
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
bool InteractStoneDoor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
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
bool InteractWickerDoor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
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
bool InteractWoodDoor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWoodDoor");
    return false;
}

/**********************************************************************************************************************
*  TODO add a success chance
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLadder(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLadder");
    MapAscend(hardware, memory, g_core.player.id);
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStairs(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStairs");
    MapDescend(hardware, memory, g_core.player.id);
    return true;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCave(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCave");
    MapLateral(hardware, memory, g_core.player.id);
    return true;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBonfire(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBonfire");
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBrazier(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBrazier");
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCampfire(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCampfire");
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractStandingTorch(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractStandingTorch");
    return false;
}

/**********************************************************************************************************************
*  TODO add light radius
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWallTorch(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWallTorch");
    return false;
}

/**********************************************************************************************************************
*  TODO add chacne to descend when walked on
*  TODO deals damage
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCrumblingFloor(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCrumblingFloor");
    MapDescend(hardware, memory, g_core.player.id);
    return false;
}

/**********************************************************************************************************************
*  TODO deals damage
*  TODO melts items
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidFountain(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidFountain");
    return false;
}

/**********************************************************************************************************************
*  TODO heals demons
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBloodFountain(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBloodFountain");
    return false;
}

/**********************************************************************************************************************
*  TODO heals
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWaterFountain(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWaterFountain");
    return false;
}

/**********************************************************************************************************************
*  TODO no sprite
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractHiddenCompartment(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractHiddenCompartment");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractAcidPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractAcidPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractLavaPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractLavaPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractNarowPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractNarowPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractShallowPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractShallowPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSnakesPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSnakesPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractSpkiedPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractSpkiedPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractPitStandard(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractPitStandard");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWaterPit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWaterPit");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWidePit(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWidePit");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractArmorRack(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractArmorRack");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWeaponRack(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWeaponRack");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBarrel(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBarrel");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractBasket(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractBasket");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractChest(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractChest");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCoffer(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCoffer");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractCrate(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractCrate");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractTrunk(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractTrunk");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractUrn(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractUrn");
    return false;
}

/**********************************************************************************************************************
*  TODO spawns an item
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractVault(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractVault");
    return false;
}

/**********************************************************************************************************************
*  TODO collision for random creatures
*  TODO no collision for trainers
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWard(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWard");
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractWell(HardwareInterface hardware, MemoryInterface memory,EntityId object_id, EntityId e_id, ObjectData objectData)
{
    DEBUG("InteractWell");
    return false;
}
