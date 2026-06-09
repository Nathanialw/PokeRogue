//
// Created by nathanial on 2/22/26.
//
#include "battle_effects_items.h"

#include "battle_actions.h"
#include "lib_memory.h"

#include "core_actions.h"
#include "core_effects.h"
#include "core_ram.h"
#include "core_utils.h"


//////////////////////////////////////////////////////////////////////////////////////////////////
/// UseBattle EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RaiseFireResistance(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    RestorePP(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Invisibility(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    MakeInvulnerable(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Hover(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(e_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Repel(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    Revive(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplySleep(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyParalyze(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    ApplyPoison(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusLesserLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    StatusGreaterLight(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);

}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return Capture(hardware, e_id, itemData.chance);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseSpeed(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseStrength(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    RaiseDefence(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    ApplyHaste(e_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    LearnSkill(e_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return HealTarget(e_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    uint8_t value = g_core.creatures.metaData[item_id].value;
    return RestoreMana(e_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
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
SET_MEMORY(".battle")
bool UseBattleScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    uint8_t spell_id = g_core.creatures.metaData[item_id].SpellId;
    return CastSpellBattle(hardware, memory, spell_id, e_id, e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemovePoison(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveCurse(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return RemoveDisease(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseAcidResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseFireResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseWaterResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseIceResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return RaiseMagicResistance(e_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId e_id, ItemData itemData)
{
    if (e_id == NO_ENTITY) return false;
    return true;
}
