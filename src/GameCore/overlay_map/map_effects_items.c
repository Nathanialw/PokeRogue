//
// Created by nathanial on 6/9/26.
//
#include "map_effects_items.h"

#include "battle_actions.h"
#include "lib_memory.h"

#include "core_actions.h"
#include "core_effects.h"
#include "core_ram.h"
#include "core_utils.h"
#include "map_effects.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// UseMap EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RaiseFireResistance(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RestorePP(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Invisibility(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    MakeInvulnerable(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Hover(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Reposition(hardware, e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Repel(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    Revive(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplySleep(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyParalyze(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyPoison(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusLesserLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusGreaterLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);

}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseSpeed(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseDefence(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    LearnSkill(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return HealTarget(e_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return RestoreMana(e_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_core.creatures.metaData[item_id].SpellId;
    return LearnSpell(memory, e_id, spell_id);
}

/**********************************************************************************************************************/
/*  Check while spell i is
 *  Try ro cast it
*
*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_core.creatures.metaData[item_id].SpellId;
    return CastSpellBattle(hardware, memory, spell_id, e_id, e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemovePoison(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveCurse(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveDisease(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseAcidResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseFireResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseWaterResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseIceResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseMagicResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}
