//
// Created by nathanial on 6/9/26.
//
#include "lib_memory.h"

#include "core_effects.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"
#include "map_actions.h"
#include "map_effects.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// UseMap EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(target_id);
}

/**********************************************************************************************************************/
/* input EntityId item_id as the spell_book index to increase the pp of
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RestorePP(user_id, index, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Invisibility(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return MakeInvulnerable(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyHaste(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Hover(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(user_id, random_tile_pos);
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Reposition(hardware, user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Repel(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return Revive(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplySleep(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyParalyze(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapPoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyPoison(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return DestroyRandomPlayerItem();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return StatusLesserLight(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return StatusGreaterLight(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapPouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Capture(hardware, user_id, target_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseStrength(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseSpeed(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseStrength(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseDefence(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ApplyHaste(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    SpellId skill_id = g_core.items.metaData[item_id].spell_id;
    return TeachSkill(target_id, skill_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    uint8_t value = g_core.items.metaData[item_id].value;
    return HealTarget(target_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    uint8_t value = g_core.items.metaData[item_id].value;
    return RestoreMana(target_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
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
ActionOutcome UseMapScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    return CastSpellMap(hardware, memory, spell_id, SPELL_INDEX_NULL, user_id, target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RemovePoison(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RemoveCurse(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RemoveDisease(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseAcidResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseWaterResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseIceResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseMagicResistance(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapPick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return LevelUpRetainProgress(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome UseMapXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    GainXP(target_id, itemData.value);
    return ACTION_SUCCEEDED;
}
