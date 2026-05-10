//
// Created by nathanial on 2/25/26.
//

#include "effects.h"
#include "lib_debugging.h"
#include "map.h"
#include "memory_rom.h"
#include "player.h"
#include "types.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastNoAttack_PLACEHOLDER(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool PlaceholderSpell(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    DEBUG("PlaceholderSpell()");
    return true;
}


// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHeal(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    if (partyID == NO_CREATURE) return false;
    HealTarget(partyID, spellData.power);
    return true;
}


// no interaction effect for lava, water, acid or pits

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastLevitate(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Levitate(partyID, spellData.power);
    return true;
}

// teleport to random empty cell on the map

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastDisplacement(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Position random_tile_pos = GetRandomMapTile(hardware, CREATURE, true);
    Reposition(partyID, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastWaterWalking(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WaterWalking(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastWaterBreathing(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WaterBreathing(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastTeleport(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Position random_tile_pos = GetSelectedTile(hardware, true);
    Reposition(partyID, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastResurrect(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Revive(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRaiseDead(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    TileHasCorpse(GetPlayerPosition());
    Summon(SKELETON);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastDescend(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    DEBUG("CastDescend()");
    MapDescend(hardware, partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastFlameEater(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    FireEating(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastPortal(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    uint8_t n = hardware.GetRandom_uint8_t(1, 3);
    if (n == 1)
        MapDescend(hardware, partyID);
    else if (n == 2)
        MapAscend(hardware, partyID);
    else
        MapLateral(hardware, partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastBrewPotion(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRepel(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Repel(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCapture(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Capture(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCurePoison(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemovePoison(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCureDisease(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveDisease(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCureCurse(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveCurse(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCreateFood(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemFood();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCreateCommon(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastFireball(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // Attack(partyID, enemyID, spellData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastIceBolt(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRazorGrass(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastMudSling(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCreateMagicItem(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastAwaken(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveSleep(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastNerveRepair(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastBlindingLight(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastSoothe(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveFear(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastFear(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyFear(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHaste(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyHaste(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastSlow(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplySlow(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHypervision(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHypothermia(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyFrozen(enemyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastBurnHeal(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RemoveBurn(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastFocus(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseAccuracy(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRage(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseStrength(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastOpenChest(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastIncreaseBag(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastGlowingEmbers(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    StatusLesserLight(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastBrillianceAura(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    StatusGreaterLight(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastReflect(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastSilence(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastPowerOverwhelming(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    MakeInvulnerable(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastShadows(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Invisibility(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastEmpower(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastDefend(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseDefence(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastWizen2(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHasten(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    ApplyHaste(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastStrengthen(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseStrength(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastFortify(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseDefence(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastWizen(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseMagic(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastGrowMuscle(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RaiseSpeed(partyID);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastClairvoyance(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    RevealMap();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastWallWalking(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    WallWalking(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCreatePit(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    Position pos = GetSelectedTile(hardware, true);
    MapModifyTile(pos, PIT);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastXRayVision(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    XRayVision(partyID, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRainStorm(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHeatWave(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastDrought(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastCrusade(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastHunt(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastPurification(HardwareInterface hardware, EntityId partyID, EntityId enemyID, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastRaiseSkeleton(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    TileHasCorpse(GetPlayerPosition());
    Summon(SKELETON);
    return true;
}

