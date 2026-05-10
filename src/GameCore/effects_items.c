//
// Created by nathanial on 2/22/26.
//


#include "battles.h"
#include "effects.h"
#include "map.h"
#include "memory_ram.h"
#include "memory_rom.h"
#include "entities.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// USE EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseLavaResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RaiseFireResistance(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRestorePpPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RestorePP(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseInvisibilityPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Invisibility(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseInvulnerabilityPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    MakeInvulnerable(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseHastePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseLevitatePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Levitate(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseTeleportPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Position random_tile_pos = GetSelectedTile(hardware, true);
    Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBlinkPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Position random_tile_pos = GetRandomMapTile(hardware, CREATURE, true);
    uint8_t as = 0b11000001;
    Reposition(as, random_tile_pos);
    Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRepelPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Repel(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRevivePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    Revive(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSleepDart(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplySleep(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseParalyzeDart(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyParalyze(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UsePoisonDart(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyPoison(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAcidVial(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseHolyWater(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseExplosiveFlask(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseTorch(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusLesserLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseLantern(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusGreaterLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseMirror(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseEarmuffs(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseLockpick(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UsePouch(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSack(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBackpack(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAltarStone(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBootsAcidWalking(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBootsLavaWalking(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBootsWaterWalking(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseGlovesAcidResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseWisdomCrown(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRainWater(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseMutton(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseCake(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRawMeat(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseFish(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseManFlesh(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBerries(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseWine(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSoulEssence(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseLasso(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseShackles(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseChain(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseBearTrap(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseNet(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseElementalBolas(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Capture(e_id, itemData.chance);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseWhip(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAmphetamines(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseSpeed(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseGrowthHormones(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseIronSkinElixir(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseDefence(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSwiftnessSerum(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseWildMushroom(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseHeartScale(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSmokeBall(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAbilityBook(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    LearnSkill(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseHealthPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_run.creatures.metaData[item_id].value;
    return HealTarget(e_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseManaPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_run.creatures.metaData[item_id].value;
    return RestoreMana(e_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSpellBook(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_run.creatures.metaData[item_id].SpellId;
    return LearnSpell(e_id);
}

/**********************************************************************************************************************/
/*  Check while spell i is
 *  Try ro cast it
*
*
**********************************************************************************************************************/
bool UseScroll(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_run.creatures.metaData[item_id].SpellId;
    return CastSpell(spell_id, e_id, e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAntidotePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemovePoison(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseDecursePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveCurse(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseCurePotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveDisease(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseAcidResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseAcidResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseFireResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseFireResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseWaterResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseWaterResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseIceResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseIceResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseMagicResistance(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseMagicResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseEscapeRope(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UsePick(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseRareCandy(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseShovel(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseXPPotion(HardwareInterface hardware, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

