//
// Created by nathanial on 2/22/26.
//

#include "memory_ram.h"
#include "memory_rom.h"
#include "stats.h"
#include "types.h"
#include "effects.h"
#include "lib_debugging.h"
#include "player.h"

/**********************************************************************************************************************/
/*
 *  Initial implementation is simple 1 or 2 effects on each skill.
 *  Effect Functions make it easy to mix and match any effects to build unique skills
 *
**********************************************************************************************************************/



/*****************************************************************************************************
 *
 *  WORK IN PROGRESS - NEED TO ADD MORE EFFECTS TO MIX AND MATCH FOR MORE INTERESTING MOVES
 *  GOAL IS TO HAVE 4 - 8 EFFECTS PER SKILL WITH AS MANY CUSTOM 1-OFF EFFECTS AS I CAN THINK UP
 *
 ******************************************************************************************************
 */


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillNoSkill(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FIRE SKILLS

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFlameBlast(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFireball(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillEmber(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillIncinerate(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCombustion(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFlare(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
//UNUSED
bool SkillHeatWave(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFlamePunch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPyre(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DEBUG("Pyre");
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            RaiseMagic(g_run.player.partyID[i]);
        }
    }
    else
    {
        RaiseMagic(attackerID);
    }
    DEBUG("Done Pyre");
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillScorch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCinderStorm(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerSpeed(defenderID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillMagmaBurst(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSunfury(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillBlazingCharge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack happens before anything
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAshCloud(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillInferno(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWildfire(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ICE SKILLS

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillBlizzard(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillIceShard(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFrostBite(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFreeze(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillHailstorm(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillGlacialSpike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillColdSnap(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NextAttackFreezes();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillIceArmor(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    FreezeAttackers(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFrostNova(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(defenderID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            Attack(hardware, attackerID, defenderID, abilityData);
        }
    }
    else
    {
        Attack(hardware, attackerID, defenderID, abilityData);
    }

    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPermafrost(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSnowBlind(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillIceLance(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCryoBlast(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    ApplyFrozen(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillArcticWinds(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFrozenOrb(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPolarVortex(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(defenderID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            Attack(hardware, attackerID, defenderID, abilityData);
        }
    }
    else
    {
        Attack(hardware, attackerID, defenderID, abilityData);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// WATER SKILLS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCavitation(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillHypervision(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillShellbreaker(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillTorrent(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWhirlpool(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillDrowningGrasp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillTidalWave(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWaterWhip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAquaJet(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillRiptide(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillHydroBlast(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillDeepCurrent(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillMaelstrom(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillBrineSpray(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSurge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPressureCrush(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PLANT SKILLS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillVineWhip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPollenCloud(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillThornBarrage(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillBloom(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    HealTarget(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillRootAnchor(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillForestWard(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillGravityRoot(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSporeExplosion(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillLeafStorm(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillBrambleTrap(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSeedVolley(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillVerdantGrowth(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillToxicIvy(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCanopyShade(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPetalBlitz(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack hits before anything
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillOvergrowth(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABERRATION SKILLS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillConsume(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPsychicShock(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillRealitySlip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillMaddeningGaze(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    AbandonTeam(defenderID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillVoidRift(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAnomaly(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillDissonance(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillCorrupt(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillMindSpike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillEldritchBlast(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWarpPulse(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillThoughtLeech(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSanityBreak(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAstralChains(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

// UNUSED
bool SkillChaosNova(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

// UNUSED
bool SkillDimensionalTear(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPetrifyingGaze(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillPetrifyingTouch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, attackerID, defenderID, abilityData);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DRAGONS SKILLS
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillTailWhip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWingBuffet(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillDragonBreath(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFearRoar(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillFlyby(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillScalesHarden(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAncientWrath(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillTreasureHunt(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillSkyDive(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillDraconicFury(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillTailSweep(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillEmberRoar(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillScaleStorm(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillWyrmCharge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAncientGuard(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGoldenInstinct(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GIANTS SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBodySlam(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStomp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEarthquake(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMightyThrow(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGroundPound(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCrush(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTitanSwing(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMountainBreaker(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBoulderToss(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSeismicSlam(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillIronGrip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTremorStep(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillColossalCharge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLandslide(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBedrockShield(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTitanicRoar(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BEAST SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillScratch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPounce(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillFeralRage(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHuntingInstinct(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPackCall(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTerrifyingRoar(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBloodScent(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillViciousBite(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRipAndTear(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAmbushStrike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // only quick attack if the enemy has not attacked otherwise just a normal attack
    if (!QuickAttack(hardware, attackerID, defenderID, abilityData))
        Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLunge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHowlOfThePack(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            RaiseStrength(g_run.player.partyID[i]);
        }
    }
    else
    {
        RaiseStrength(attackerID);
    }
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSavageMaul(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPredatorFocus(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillThroatClamp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStalk(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FEY SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPixieDust(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGlamour(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTricksterTreat(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEnchantingMelody(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillFaerieFire(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDreamDust(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillWildMagic(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGladeTeleport(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMoonbeam(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMirrorGlamour(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillFaeWhisper(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPetalDance(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStarSprinkle(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMysticTangle(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLuminaBlessing(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTwilightShimmer(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMIGOD SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPrayer(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            HealTarget(g_run.player.partyID[i], abilityData.power);
        }
    }
    else
    {
        HealTarget(attackerID, abilityData.power);
    }
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDivineSmite(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBlessing(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMiracle(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillJudgement(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAuraOfReverence(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillChannelDivinity(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillApotheosis(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHolyLight(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSacredShield(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCelestialCall(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPurify(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    RemoveCurse(attackerID);
    RemovePoison(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDivineIntervention(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHaloOfGrace(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRighteousFury(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSeraphicWard(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// HUMANOID SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTackle(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSlash(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBash(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPreciseStrike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillExorcism(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTaunt(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRally(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_run.player.partyID[i] == NO_ENTITY) continue;
            RaiseStrength(g_run.player.partyID[i]);
        }
    }
    else
    {
        RaiseStrength(attackerID);
    }
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDisarm(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCharge(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    QuickAttack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillParry(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Parry(attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCripplingBlow(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGuardBreak(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSecondWind(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RestoreMana(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillIronWill(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillShieldBash(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTacticalRetreat(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Flee();
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ANCIENT SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPrimordialForce(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTimeWarp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillFossilize(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCallOfTheVoid(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerMagic(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillWorldTear(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSleepOfAges(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAncientWisdom(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCatastrophe(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillArcaneEruption(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStoneTide(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTemporalShift(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPrimalScream(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCosmicRay(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEternalGrasp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillVolcanicOutburst(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRunicAegis(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UNDEAD SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPlague(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLifeDrain(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGraveTouch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHaunt(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillNecroticBurst(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRaiseMinion(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Summon(SKELETON);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillWither(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDeathsDoor(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillWail(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, attackerID, defenderID, abilityData);
    return true;
}

// UNUSED
bool SkillSoulSip(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBoneSpike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCursedGround(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillVampiricWave(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPhantomGrasp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTombShield(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDarkRitual(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    SacrificeHeal(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEpitaph(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMONIC SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSultryLook(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillKiss(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHellfire(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCorruptingTouch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    ApplyDisease(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDemonicPact(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSoulSiphon(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DrainMana(defenderID, abilityData.power);
    RestoreMana(attackerID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTemptation(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillFelblaze(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillChaosWhisper(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLustfulGlare(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAbyssalGrasp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillCursedEmbrace(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillInfernalRush(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillDiabolicCry(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillHellscape(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TOXIC SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSting(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillVenomSpit(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillToxicCloud(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillParalyze(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAcidSpray(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DestroyRandomPlayerItem();
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillNeurotoxin(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillContagion(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillAntidote(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemovePoison(attackerID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillToxicFang(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillVirulentBite(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillToxicBarrage(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillNerveStrike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillToxicMist(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    PersistentPoisonCloud(abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillVenomousTail(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillInfectiousTouch(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillPurifyCure(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EARTHEN SKILLS
/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillSacrifice(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillRockThrow(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMudSlide(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStoneSkin(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillQuicksand(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEarthenPrison(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLavaBurst(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTerraform(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillBoulderCrush(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillEarthquakeStomp(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillTremorWave(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillStoneSpike(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMudClaw(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillGeoBarrier(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillMagmaFlow(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

/**********************************************************************************************************************
/*
**********************************************************************************************************************/
bool SkillLandShift(HardwareInterface hardware, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, attackerID, defenderID, abilityData);
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NEW ADDED
