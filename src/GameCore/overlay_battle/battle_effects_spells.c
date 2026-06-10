//
// Created by nathanial on 6/9/26.
//

#include "battle_effects_spells.h"

#include "types.h"
#include "lib_memory.h"

#include "core_effects.h"



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleNoAttack_PLACEHOLDER(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}

// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    if (friendly_id == NO_ENTITY) return false;
    HealTarget(friendly_id, spellData.power);
    return true;
}


// no interaction effect for lava, water, acid or pits

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleLevitate(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}

// teleport to random empty cell on the battle

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleWaterBreathing(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(partyID, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleResurrect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    Revive(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRaiseDead(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleDescend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleFlameEater(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    FireEating(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattlePortal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // uint8_t n = hardware.GetRandom_uint8_t(1, 3);
    // if (n == 1)
    //     battleDescend(hardware, memory, partyID);
    // else if (n == 2)
    //     battleAscend(hardware, memory, partyID);
    // else
    //     battleLateral(hardware, memory, partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleBrewPotion(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRepel(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCapture(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    Capture(hardware, caster_id, enemy_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCurePoison(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemovePoison(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCureDisease(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemoveDisease(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCureCurse(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemoveCurse(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    CreateItemFood();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCreateCommon(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleFireball(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Attack(partyID, enemyID, spellData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleIceBolt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRazorGrass(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleMudSling(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCreateMagicItem(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleAwaken(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemoveSleep(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleNerveRepair(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleBlindingLight(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleSoothe(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemoveFear(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleFear(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    ApplyFear(enemy_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHaste(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    ApplyHaste(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleSlow(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    ApplySlow(enemy_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHypothermia(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    ApplyFrozen(enemy_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleBurnHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RemoveBurn(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleFocus(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseAccuracy(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRage(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseStrength(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleOpenChest(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleIncreaseBag(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleGlowingEmbers(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    StatusLesserLight(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleBrillianceAura(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    StatusGreaterLight(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleReflect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleSilence(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattlePowerOverwhelming(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    MakeInvulnerable(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleShadows(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    Invisibility(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleEmpower(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseMagic(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleDefend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseDefence(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleWizen2(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseMagic(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHasten(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    ApplyHaste(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleStrengthen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseStrength(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleFortify(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseDefence(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleWizen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseMagic(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleGrowMuscle(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    RaiseSpeed(friendly_id);
    return true;
}


/**********************************************************************************************************************/
/* removes the dark black fog of the battle
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleClairvoyance(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleWallWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    WallWalking(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCreatePit(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // Position pos = GetSelectedTile(hardware, true);
    // battleModifyTile(pos, PIT);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleXRayVision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    XRayVision(friendly_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRainStorm(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleDrought(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleCrusade(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleHunt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattlePurification(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastBattleRaiseSkeleton(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}
