//
// Created by nathanial on 2/22/26.
//
#include "lib_memory.h"

#include "core_effects.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"

#include "battle_actions.h"
#include "battle_ram.h"
#include "core_entities.h"
#include "core_memory_access.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
/// UseBattle EFFECTS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleLavaResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRestorePpPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RestorePP(target_id, index, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleInvisibilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Invisibility(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleInvulnerabilityPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return MakeInvulnerable(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleHastePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyHaste(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleLevitatePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Hover(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleTeleportPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(user_id, random_tile_pos);
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBlinkPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRepelPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Repel(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRevivePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return Revive(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSleepDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplySleep(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleParalyzeDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyParalyze(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattlePoisonDart(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ApplyPoison(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*  // chance to fail and melt a players item
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleAcidVial(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    DoDamage(g_core.battleMode.enemyMonsterID, itemData.power);
    return DestroyRandomPlayerItem();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleHolyWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleExplosiveFlask(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    DoDamage(g_core.battleMode.enemyMonsterID, itemData.power);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleTorch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return StatusLesserLight(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleLantern(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return StatusGreaterLight(user_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleMirror(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleEarmuffs(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleLockpick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattlePouch(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBackpack(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleAltarStone(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBootsAcidWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBootsLavaWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBootsWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleGlovesAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleWisdomCrown(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return NoEffect();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRainWater(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleMutton(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleCake(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRawMeat(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleFish(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleManFlesh(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBerries(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleWine(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSoulEssence(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleLasso(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);

    if (action_outcome == ACTION_SUCCEEDED)
    {
        if (g_core.battleMode.enemy_trainer_id == NO_ENTITY)
        {
            g_battle.enemy_captured = true;
        }
        else
        {
            g_battle.enemy_captured = true;
        }
    }

    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleShackles(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);
    if (action_outcome == ACTION_SUCCEEDED)
        g_battle.enemy_captured = true;
    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleChain(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);
    if (action_outcome == ACTION_SUCCEEDED)
        g_battle.enemy_captured = true;
    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleBearTrap(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);
    if (action_outcome == ACTION_SUCCEEDED)
        g_battle.enemy_captured = true;
    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleNet(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);
    if (action_outcome == ACTION_SUCCEEDED)
        g_battle.enemy_captured = true;
    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleElementalBolas(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    ActionOutcome action_outcome = Capture(hardware, user_id, target_id, itemData.chance);
    if (action_outcome == ACTION_SUCCEEDED)
        g_battle.enemy_captured = true;
    return action_outcome;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleWhip(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseStrength(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleAmphetamines(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseSpeed(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleGrowthHormones(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseStrength(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleIronSkinElixir(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return RaiseDefence(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSwiftnessSerum(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ApplyHaste(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleWildMushroom(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleHeartScale(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSmokeBall(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return Flee();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleAbilityBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    SpellId skill_id = g_core.items.metaData[item_id].spell_id;
    return TeachSkill(target_id, skill_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleHealthPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    uint8_t value = g_core.items.metaData[item_id].value;
    return HealTarget(target_id, value);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleVisionPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    SetBit(g_core.player.effects, P_EFFECTS_MAP_VISION_CREATURES, true);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleManaPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    uint8_t value = g_core.items.metaData[item_id].value;
    return RestoreMana(target_id, value);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSpellBook(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    return LearnSpell(memory, user_id, spell_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleScroll(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    uint8_t spell_id = g_core.items.metaData[item_id].spell_id;
    SpellData spell_data = {0};
    Flash_GetSpellData(memory, &spell_data, spell_id);

    return CastSpellBattle(hardware, memory, spell_id, SPELL_INDEX_NULL, user_id, target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleAntidotePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RemovePoison(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleDecursePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RemoveCurse(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleCurePotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    return RemoveDisease(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleCloakAcidResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseAcidResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleFireResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseFireResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleWaterResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseWaterResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleIceResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseIceResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleMagicResistance(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return RaiseMagicResistance(target_id, itemData.power);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleEscapeRope(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattlePick(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/* SetXPToLevel guarantees max xp is >0
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRareCandy(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return LevelUpRetainProgress(target_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleShovel(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleXPPotion(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    if (user_id == NO_ENTITY) return ACTION_CANNOT;
    GainXP(target_id, itemData.value);
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleSpellbookPage(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseBattleRosarie(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return ACTION_FAILED;
}
