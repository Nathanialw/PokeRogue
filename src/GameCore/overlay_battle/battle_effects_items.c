//
// Created by nathanial on 2/22/26.
//
#include "battle_effects_items.h"

#include "battle_actions.h"
#include "battle_ram.h"
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
bool UseBattleLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    RaiseFireResistance(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RestorePP(user_id, index, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Invisibility(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    MakeInvulnerable(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyHaste(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Hover(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(user_id, random_tile_pos);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Repel(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    Revive(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplySleep(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyParalyze(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ApplyPoison(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    DestroyRandomPlayerItem();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    StatusLesserLight(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    StatusGreaterLight(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;

}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (Capture(hardware, user_id, target_id, itemData.chance))
    {
        g_battle.end_battle = true;
        return true;
    }
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseStrength(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseSpeed(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseStrength(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    RaiseDefence(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    ApplyHaste(user_id, itemData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    Flee();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    LearnSkill(user_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    uint8_t value = g_core.items.metaData[item_id].value;
    return HealTarget(user_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    uint8_t value = g_core.items.metaData[item_id].value;
    return RestoreMana(user_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
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
SET_MEMORY(".battle")
bool UseBattleScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    return CastSpellBattle(hardware, memory, spell_id, SPELL_INDEX_NULL, user_id, user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return RemovePoison(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return RemoveCurse(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return RemoveDisease(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseAcidResistance(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseWaterResistance(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseIceResistance(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseMagicResistance(user_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattlePick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/* SetXPToLevel guarantees max xp is >0
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    LevelUpRetainProgress(target_id);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseBattleXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return false;
    return true;
}
