//
// Created by nathanial on 2/22/26.
//
#include "core_effects_items.h"

#include "lib_memory.h"

#include "core_actions.h"
#include "core_effects.h"
#include "core_ram.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// USE EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RaiseFireResistance(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RestorePP(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Invisibility(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    MakeInvulnerable(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Levitate(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    // Position random_tile_pos = GetRandomMapTile(hardware, CREATURE, true);
    // uint8_t as = 0b11000001;
    // Reposition(as, random_tile_pos);
    // Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Repel(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    Revive(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplySleep(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyParalyze(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UsePoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyPoison(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusLesserLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusGreaterLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UsePouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseSpeed(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseDefence(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    LearnSkill(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return HealTarget(e_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return RestoreMana(e_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_core.creatures.metaData[item_id].SpellId;
    return LearnSpell(e_id);
}

/**********************************************************************************************************************/
/*  Check while spell i is
 *  Try ro cast it
*
*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_core.creatures.metaData[item_id].SpellId;
    return CastSpell(hardware, memory, spell_id, e_id, e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemovePoison(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveCurse(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveDisease(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseAcidResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseFireResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseWaterResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseIceResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseMagicResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UsePick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}
