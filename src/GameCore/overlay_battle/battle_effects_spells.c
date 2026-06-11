//
// Created by nathanial on 6/9/26.
//

#include "battle_effects_spells.h"

#include "types.h"
#include "lib_memory.h"

#include "core_effects.h"
#include "core_entities.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleNoAttack_PLACEHOLDER(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}

// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    if (friendly_id == NO_ENTITY) return ACTION_CANNOT;
    return HealTarget(friendly_id, spellData.power);
}


// no interaction effect for lava, water, acid or pits

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleLevitate(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}

// teleport to random empty cell on the battle

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleWaterBreathing(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(partyID, random_tile_pos);
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleResurrect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return Revive(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRaiseDead(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleDescend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleFlameEater(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return FireEating(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattlePortal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // uint8_t n = hardware.GetRandom_uint8_t(1, 3);
    // if (n == 1)
    //     battleDescend(hardware, memory, partyID);
    // else if (n == 2)
    //     battleAscend(hardware, memory, partyID);
    // else
    //     battleLateral(hardware, memory, partyID);
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleBrewPotion(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRepel(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCapture(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return Capture(hardware, caster_id, enemy_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCurePoison(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemovePoison(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCureDisease(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemoveDisease(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCureCurse(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemoveCurse(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return CreateItemFood();
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCreateCommon(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return CreateItemCommon();
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleFireball(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Attack(partyID, enemyID, spellData);
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleIceBolt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRazorGrass(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleMudSling(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCreateMagicItem(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return CreateItemCommon();
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleAwaken(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemoveSleep(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleNerveRepair(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleBlindingLight(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleSoothe(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemoveFear(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleFear(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ApplyFear(enemy_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHaste(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ApplyHaste(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleSlow(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ApplySlow(enemy_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHypothermia(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ApplyFrozen(enemy_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleBurnHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RemoveBurn(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleFocus(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseAccuracy(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRage(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseStrength(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleOpenChest(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    uint8_t enemy_type = GetCreatureType(enemy_id);
    if (enemy_type == MIMIC)
    {
        DoDamage(enemy_id, spellData.power);
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleIncreaseBag(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleGlowingEmbers(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return StatusLesserLight(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleBrillianceAura(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return StatusGreaterLight(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleReflect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleSilence(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattlePowerOverwhelming(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return MakeInvulnerable(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleShadows(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return Invisibility(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleEmpower(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseMagic(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleDefend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseDefence(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleWizen2(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseMagic(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHasten(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ApplyHaste(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleStrengthen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseStrength(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleFortify(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseDefence(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleWizen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseMagic(friendly_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleGrowMuscle(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return RaiseSpeed(friendly_id);
}


/**********************************************************************************************************************/
/* removes the dark black fog of the battle
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleClairvoyance(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleWallWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return WallWalking(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCreatePit(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Position pos = GetSelectedTile(hardware, true);
    // battleModifyTile(pos, PIT);
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleXRayVision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return XRayVision(friendly_id, spellData.power);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRainStorm(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleDrought(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleCrusade(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleHunt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattlePurification(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome CastBattleRaiseSkeleton(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return ACTION_FAILED;
}
