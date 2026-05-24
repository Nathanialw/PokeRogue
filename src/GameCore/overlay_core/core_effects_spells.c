//
// Created by nathanial on 5/19/26.
//
#include "core_effects_spells.h"

#include "types.h"
#include "lib_memory.h"

#include "core_effects.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastNoAttack_PLACEHOLDER(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool PlaceholderSpell(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHeal(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    if (partyID == NO_CREATURE) return false;
    HealTarget(partyID, spellData.power);
    return true;
}


// no interaction effect for lava, water, acid or pits

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastLevitate(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Levitate(partyID, spellData.power);
    return true;
}

// teleport to random empty cell on the map

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // Position random_tile_pos = GetRandomMapTile(hardware, CREATURE, true);
    // Reposition(partyID, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WaterWalking(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastWaterBreathing(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WaterBreathing(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(partyID, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastResurrect(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Revive(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRaiseDead(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastDescend(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // MapDescend(hardware, memory, partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastFlameEater(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    FireEating(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastPortal(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // uint8_t n = hardware.GetRandom_uint8_t(1, 3);
    // if (n == 1)
    //     MapDescend(hardware, memory, partyID);
    // else if (n == 2)
    //     MapAscend(hardware, memory, partyID);
    // else
    //     MapLateral(hardware, memory, partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastBrewPotion(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRepel(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Repel(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCapture(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Capture(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCurePoison(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemovePoison(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCureDisease(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveDisease(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCureCurse(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveCurse(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemFood();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCreateCommon(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastFireball(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // Attack(partyID, enemyID, spellData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastIceBolt(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRazorGrass(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastMudSling(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCreateMagicItem(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastAwaken(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveSleep(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastNerveRepair(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastBlindingLight(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastSoothe(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveFear(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastFear(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyFear(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHaste(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyHaste(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastSlow(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplySlow(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHypothermia(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyFrozen(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastBurnHeal(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveBurn(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastFocus(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseAccuracy(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRage(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseStrength(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastOpenChest(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastIncreaseBag(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastGlowingEmbers(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    StatusLesserLight(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastBrillianceAura(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    StatusGreaterLight(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastReflect(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastSilence(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastPowerOverwhelming(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    MakeInvulnerable(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastShadows(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Invisibility(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastEmpower(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastDefend(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseDefence(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastWizen2(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHasten(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyHaste(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastStrengthen(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseStrength(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastFortify(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseDefence(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastWizen(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastGrowMuscle(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseSpeed(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastClairvoyance(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // RevealMap();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastWallWalking(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WallWalking(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCreatePit(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // Position pos = GetSelectedTile(hardware, true);
    // MapModifyTile(pos, PIT);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastXRayVision(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    XRayVision(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRainStorm(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastDrought(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastCrusade(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastHunt(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastPurification(HardwareInterface hardware, MemoryInterface memory, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastRaiseSkeleton(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}
