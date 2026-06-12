//
// Created by nathanial on 2/22/26.
//

#include "types.h"
#include "lib_debugging.h"
#include "lib_memory.h"

#include "core_effects.h"
#include "core_ram.h"
#include "core_player.h"

#include "battle_player.h"
#include "battle_ram.h"


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
ActionOutcome SkillNoSkill(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return NoEffect();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FIRE SKILLS

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFlameBlast(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFireball(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEmber(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIncinerate(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCombustion(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFlare(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
//UNUSED
SET_MEMORY(".battle")
ActionOutcome SkillHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFlamePunch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}


/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPyre(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillScorch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCinderStorm(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerSpeed(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMagmaBurst(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSunfury(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBlazingCharge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack happens before anything
    NoEffect();
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAshCloud(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillInferno(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWildfire(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyBurn(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ICE SKILLS

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBlizzard(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIceShard(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFrostBite(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFreeze(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHailstorm(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGlacialSpike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillColdSnap(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NextAttackFreezes();
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIceArmor(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    FreezeAttackers(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFrostNova(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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

    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPermafrost(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSnowBlind(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerAccuracy(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIceLance(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCryoBlast(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    ApplyFrozen(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillArcticWinds(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFrozen(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFrozenOrb(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPolarVortex(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// WATER SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCavitation(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillShellbreaker(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTorrent(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWhirlpool(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDrowningGrasp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);

    if (Capture(hardware, trainer_id, defenderID, abilityData.power))
    {
        g_battle.enemy_captured = true;
    }
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTidalWave(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWaterWhip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAquaJet(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRiptide(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHydroBlast(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDeepCurrent(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMaelstrom(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBrineSpray(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSurge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPressureCrush(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PLANT SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVineWhip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPollenCloud(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillThornBarrage(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBloom(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    HealTarget(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRootAnchor(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillForestWard(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGravityRoot(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSporeExplosion(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLeafStorm(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBrambleTrap(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSeedVolley(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVerdantGrowth(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillToxicIvy(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCanopyShade(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPetalBlitz(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // ensure this attack hits before anything
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillOvergrowth(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABERRATION SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillConsume(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPsychicShock(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRealitySlip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMaddeningGaze(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    AbandonTeam(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVoidRift(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAnomaly(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDissonance(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCorrupt(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMindSpike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEldritchBlast(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWarpPulse(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillThoughtLeech(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSanityBreak(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAstralChains(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

// UNUSED
SET_MEMORY(".battle")
ActionOutcome SkillChaosNova(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return ACTION_SUCCEEDED;
}

// UNUSED
SET_MEMORY(".battle")
ActionOutcome SkillDimensionalTear(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    NoEffect();
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPetrifyingGaze(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPetrifyingTouch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DRAGONS SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTailWhip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWingBuffet(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDragonBreath(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFearRoar(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFlyby(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillScalesHarden(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAncientWrath(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTreasureHunt(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSkyDive(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDraconicFury(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTailSweep(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEmberRoar(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillScaleStorm(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWyrmCharge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAncientGuard(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGoldenInstinct(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GIANTS SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBodySlam(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStomp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEarthquake(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMightyThrow(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGroundPound(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCrush(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTitanSwing(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMountainBreaker(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBoulderToss(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSeismicSlam(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIronGrip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTremorStep(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillColossalCharge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLandslide(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBedrockShield(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTitanicRoar(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BEAST SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillScratch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPounce(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFeralRage(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHuntingInstinct(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPackCall(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTerrifyingRoar(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBloodScent(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillViciousBite(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRipAndTear(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAmbushStrike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // only quick attack if the enemy has not attacked otherwise just a normal attack
    if (!QuickAttack(hardware, memory, attackerID, defenderID, abilityData))
        Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLunge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHowlOfThePack(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSavageMaul(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPredatorFocus(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillThroatClamp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStalk(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FEY SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPixieDust(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGlamour(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTricksterTreat(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEnchantingMelody(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFaerieFire(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDreamDust(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySleep(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWildMagic(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGladeTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMoonbeam(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMirrorGlamour(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFaeWhisper(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPetalDance(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStarSprinkle(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMysticTangle(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLuminaBlessing(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTwilightShimmer(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMIGOD SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPrayer(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDivineSmite(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBlessing(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMiracle(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillJudgement(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAuraOfReverence(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillChannelDivinity(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillApotheosis(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHolyLight(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSacredShield(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCelestialCall(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPurify(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    RemoveCurse(attackerID);
    RemovePoison(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDivineIntervention(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHaloOfGrace(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRighteousFury(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSeraphicWard(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(attackerID);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// HUMANOID SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTackle(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSlash(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBash(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPreciseStrike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseAccuracy(attackerID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillExorcism(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTaunt(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRally(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
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
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDisarm(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCharge(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    QuickAttack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillParry(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Parry(attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCripplingBlow(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGuardBreak(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSecondWind(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RestoreMana(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillIronWill(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillShieldBash(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTacticalRetreat(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Flee();
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ANCIENT SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPrimordialForce(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTimeWarp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFossilize(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCallOfTheVoid(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerMagic(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWorldTear(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSleepOfAges(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAncientWisdom(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseMagic(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCatastrophe(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillArcaneEruption(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStoneTide(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTemporalShift(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyHaste(attackerID, abilityData.power);
    ApplySlow(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPrimalScream(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCosmicRay(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEternalGrasp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    if (Capture(hardware, trainer_id, defenderID, abilityData.power))
    {
        g_battle.enemy_captured = true;
    }
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVolcanicOutburst(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRunicAegis(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UNDEAD SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPlague(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLifeDrain(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGraveTouch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHaunt(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyFear(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillNecroticBurst(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRaiseMinion(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Summon(SKELETON);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWither(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerStrength(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDeathsDoor(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillWail(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    InstantKill(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

// UNUSED
SET_MEMORY(".battle")
ActionOutcome SkillSoulSip(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBoneSpike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCursedGround(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyCurse(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVampiricWave(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    HealTarget(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPhantomGrasp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    if (Capture(hardware, trainer_id, defenderID, abilityData.power))
    {
        g_battle.enemy_captured = true;
    }
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTombShield(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDarkRitual(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    SacrificeHeal(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEpitaph(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DEMONIC SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSultryLook(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillKiss(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHellfire(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCorruptingTouch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    ApplyDisease(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDemonicPact(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSoulSiphon(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DrainMana(defenderID, abilityData.power);
    RestoreMana(attackerID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTemptation(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillFelblaze(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillChaosWhisper(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLustfulGlare(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAbyssalGrasp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    if (Capture(hardware, trainer_id, defenderID, abilityData.power))
    {
        g_battle.enemy_captured = true;
    }
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillCursedEmbrace(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillInfernalRush(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillDiabolicCry(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseStrength(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillHellscape(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TOXIC SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSting(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVenomSpit(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillToxicCloud(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillParalyze(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAcidSpray(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    DestroyRandomPlayerItem();
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillNeurotoxin(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillContagion(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillAntidote(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemovePoison(attackerID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillToxicFang(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyPoison(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVirulentBite(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillToxicBarrage(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillNerveStrike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillToxicMist(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    PersistentPoisonCloud(abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillVenomousTail(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillInfectiousTouch(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyDisease(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillPurifyCure(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RemoveDisease(attackerID);
    return ACTION_SUCCEEDED;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EARTHEN SKILLS
/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillSacrifice(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillRockThrow(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMudSlide(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStoneSkin(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    LowerDefence(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillQuicksand(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEarthenPrison(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplyParalyze(defenderID, abilityData.power);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLavaBurst(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTerraform(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillBoulderCrush(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillEarthquakeStomp(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillTremorWave(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillStoneSpike(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMudClaw(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    ApplySlow(defenderID, abilityData.power);
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillGeoBarrier(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    RaiseDefence(defenderID);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillMagmaFlow(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/*********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome SkillLandShift(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NEW ADDED
