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
#include "map_actions.h"
#include "map_effects.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// UseMap EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    RaiseFireResistance(target_id);
    return true;
}

/**********************************************************************************************************************/
/* input EntityId item_id as the spell_book index to increase the pp of
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RestorePP(user_id, index, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Invisibility(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    MakeInvulnerable(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyHaste(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Hover(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(user_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Reposition(hardware, user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Repel(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    Revive(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplySleep(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyParalyze(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyPoison(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    StatusLesserLight(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    StatusGreaterLight(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);

}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseStrength(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseSpeed(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseStrength(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseDefence(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    ApplyHaste(target_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    LearnSkill(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    uint8_t value = g_core.items.metaData[item_id].value;
    return HealTarget(target_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    uint8_t value = g_core.items.metaData[item_id].value;
    return RestoreMana(target_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    return LearnSpell(memory, user_id, spell_id);
}

/**********************************************************************************************************************/
/*  Check while spell i is
 *  Try ro cast it
*
*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    return CastSpellMap(hardware, memory, spell_id, SPELL_INDEX_NULL, user_id, target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return RemovePoison(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return RemoveCurse(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return RemoveDisease(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseAcidResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseWaterResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseIceResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseMagicResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapPick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return LevelUpRetainProgress(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMapXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return false;
    return true;
}

