//
// Created by nathanial on 2/22/26.
//

#include "battle_effects_skills.h"

#include "types.h"
#include "lib_debugging.h"
#include "lib_memory.h"
#include "core_effects.h"
#include "core_ram.h"

#include "battle_player.h"
#include "core_player.h"


/*********************************************************************************************************************
*
 *  Initial implementation is simple 1 or 2 effects on each skill.
 *  Effect Functions make it easy to mix and match any effects to build unique skills
 *
**********************************************************************************************************************/



/****************************************************************************************************
 *
 *  WORK IN PROGRESS - NEED TO ADD MORE EFFECTS TO MIX AND MATCH FOR MORE INTERESTING MOVES
 *  GOAL IS TO HAVE 4 - 8 EFFECTS PER SKILL WITH AS MANY CUSTOM 1-OFF EFFECTS AS I CAN THINK UP
 *
*******************************************************************************************************/


/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillNoSkill(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FIRE SKILLS

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFlameBlast(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFireball(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEmber(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIncinerate(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCombustion(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFlare(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
//UNUSED
SET_MEMORY(".battle")
bool SkillHeatWave(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFlamePunch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}


/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPyre(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DEBUG("Pyre");
    if (IsInParty(attackerID))
    {
        EntityId p_ID = GetPlayerID();
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            RaiseMagic(g_core.trainers.partyID[p_ID][i]);
        }
    }
    else
    {
        RaiseMagic(attackerID);
    }
    DEBUG("Done Pyre");
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillScorch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCinderStorm(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerSpeed(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMagmaBurst(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSunfury(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBlazingCharge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack happens before anything
    NoEffect();
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAshCloud(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillInferno(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWildfire(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ICE SKILLS

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBlizzard(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIceShard(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFrostBite(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFreeze(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHailstorm(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGlacialSpike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillColdSnap(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NextAttackFreezes();
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIceArmor(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    FreezeAttackers(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFrostNova(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(defenderID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId p_ID = GetPlayerID();
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            Attack(hardware, memory, attackerID, defenderID, abilityData);
        }
    }
    else
    {
        Attack(hardware, memory, attackerID, defenderID, abilityData);
    }

    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPermafrost(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSnowBlind(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIceLance(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCryoBlast(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    ApplyFrozen(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillArcticWinds(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFrozenOrb(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPolarVortex(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(defenderID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId p_ID = GetPlayerID();
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            Attack(hardware, memory, attackerID, defenderID, abilityData);
        }
    }
    else
    {
        Attack(hardware, memory, attackerID, defenderID, abilityData);
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// WATER SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCavitation(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHypervision(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillShellbreaker(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTorrent(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWhirlpool(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDrowningGrasp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTidalWave(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWaterWhip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAquaJet(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRiptide(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHydroBlast(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDeepCurrent(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMaelstrom(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBrineSpray(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSurge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPressureCrush(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PLANT SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVineWhip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPollenCloud(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillThornBarrage(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBloom(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    HealTarget(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRootAnchor(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillForestWard(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGravityRoot(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSporeExplosion(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLeafStorm(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBrambleTrap(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSeedVolley(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVerdantGrowth(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillToxicIvy(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCanopyShade(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPetalBlitz(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack hits before anything
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillOvergrowth(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABERRATION SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillConsume(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPsychicShock(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRealitySlip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMaddeningGaze(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    AbandonTeam(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVoidRift(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAnomaly(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDissonance(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCorrupt(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMindSpike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEldritchBlast(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWarpPulse(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillThoughtLeech(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSanityBreak(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAstralChains(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

// UNUSED
SET_MEMORY(".battle")
bool SkillChaosNova(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

// UNUSED
SET_MEMORY(".battle")
bool SkillDimensionalTear(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPetrifyingGaze(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPetrifyingTouch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DRAGONS SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTailWhip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWingBuffet(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDragonBreath(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFearRoar(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFlyby(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillScalesHarden(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAncientWrath(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTreasureHunt(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSkyDive(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDraconicFury(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTailSweep(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEmberRoar(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillScaleStorm(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWyrmCharge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAncientGuard(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGoldenInstinct(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GIANTS SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBodySlam(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStomp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEarthquake(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMightyThrow(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGroundPound(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCrush(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTitanSwing(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMountainBreaker(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBoulderToss(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSeismicSlam(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIronGrip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTremorStep(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillColossalCharge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLandslide(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBedrockShield(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTitanicRoar(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BEAST SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillScratch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPounce(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFeralRage(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHuntingInstinct(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPackCall(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTerrifyingRoar(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBloodScent(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillViciousBite(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRipAndTear(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAmbushStrike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // only quick attack if the enemy has not attacked otherwise just a normal attack
    if (!QuickAttack(hardware, memory, attackerID, defenderID, abilityData))
        Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLunge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHowlOfThePack(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId p_ID = GetPlayerID();
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            RaiseStrength(g_core.trainers.partyID[p_ID][i]);
        }
    }
    else
    {
        RaiseStrength(attackerID);
    }
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSavageMaul(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPredatorFocus(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillThroatClamp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStalk(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FEY SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPixieDust(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGlamour(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTricksterTreat(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEnchantingMelody(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFaerieFire(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDreamDust(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWildMagic(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGladeTeleport(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMoonbeam(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMirrorGlamour(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFaeWhisper(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPetalDance(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStarSprinkle(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMysticTangle(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLuminaBlessing(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTwilightShimmer(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMIGOD SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPrayer(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId p_ID = GetPlayerID();
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            HealTarget(g_core.trainers.partyID[p_ID][i], abilityData.power);
        }
    }
    else
    {
        HealTarget(attackerID, abilityData.power);
    }
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDivineSmite(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBlessing(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMiracle(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillJudgement(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAuraOfReverence(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillChannelDivinity(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillApotheosis(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHolyLight(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSacredShield(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCelestialCall(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPurify(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    RemoveCurse(attackerID);
    RemovePoison(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDivineIntervention(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHaloOfGrace(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRighteousFury(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSeraphicWard(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// HUMANOID SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTackle(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSlash(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBash(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPreciseStrike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillExorcism(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTaunt(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRally(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    if (IsInParty(attackerID))
    {
        for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        {
            EntityId p_ID = GetPlayerID();
            if (g_core.trainers.partyID[p_ID][i] == NO_ENTITY) continue;
            RaiseStrength(g_core.trainers.partyID[p_ID][i]);
        }
    }
    else
    {
        RaiseStrength(attackerID);
    }
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDisarm(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCharge(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    QuickAttack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillParry(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Parry(attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCripplingBlow(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGuardBreak(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSecondWind(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RestoreMana(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillIronWill(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillShieldBash(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTacticalRetreat(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Flee();
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ANCIENT SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPrimordialForce(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTimeWarp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFossilize(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCallOfTheVoid(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerMagic(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWorldTear(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSleepOfAges(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAncientWisdom(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCatastrophe(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillArcaneEruption(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStoneTide(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTemporalShift(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPrimalScream(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCosmicRay(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEternalGrasp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVolcanicOutburst(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRunicAegis(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UNDEAD SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPlague(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLifeDrain(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGraveTouch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHaunt(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillNecroticBurst(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRaiseMinion(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Summon(SKELETON);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWither(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDeathsDoor(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillWail(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

// UNUSED
SET_MEMORY(".battle")
bool SkillSoulSip(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBoneSpike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCursedGround(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVampiricWave(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPhantomGrasp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTombShield(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDarkRitual(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    SacrificeHeal(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEpitaph(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMONIC SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSultryLook(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillKiss(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHellfire(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCorruptingTouch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    ApplyDisease(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDemonicPact(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSoulSiphon(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DrainMana(defenderID, abilityData.power);
    RestoreMana(attackerID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTemptation(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillFelblaze(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillChaosWhisper(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLustfulGlare(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAbyssalGrasp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    Capture(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillCursedEmbrace(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillInfernalRush(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillDiabolicCry(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillHellscape(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TOXIC SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSting(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVenomSpit(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillToxicCloud(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillParalyze(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAcidSpray(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DestroyRandomPlayerItem();
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillNeurotoxin(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillContagion(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAntidote(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemovePoison(attackerID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillToxicFang(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVirulentBite(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillToxicBarrage(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillNerveStrike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillToxicMist(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    PersistentPoisonCloud(abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillVenomousTail(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillInfectiousTouch(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillPurifyCure(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EARTHEN SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillSacrifice(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillRockThrow(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMudSlide(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStoneSkin(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillQuicksand(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEarthenPrison(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLavaBurst(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTerraform(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillBoulderCrush(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillEarthquakeStomp(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillTremorWave(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillStoneSpike(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMudClaw(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillGeoBarrier(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillMagmaFlow(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillLandShift(HardwareInterface hardware,  MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NEW ADDED
