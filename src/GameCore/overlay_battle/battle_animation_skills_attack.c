//
// Created by nathanial on 4/10/26.
//


/************************************************************************************************************
 *
 *  Animations for each skill are composed with functions from the animations_effects.h file
 *  Each function runs sequentially go give a unique animation effect
 *  work in progress, empty functions are no animation effect and instant
 *
 ************************************************************************************************************/


/************************************************************************************************************
 *  Utility functions
 ************************************************************************************************************/


#include "battle_animation_effects.h"
#include "lib_decl.h"
#include "lib_memory.h"

/************************************************************************************************************
 *  Sprite straight floats up off the top of the battler area
 *  Floats back down quickly to its default position
 ************************************************************************************************************/
SET_MEMORY(".battle")
bool Pico_AnimationBattlerFly(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    MoveCenterToTop(graphics, hardware, r, r.h, 8);
    return false;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAttackAbyssalGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAcidSpray(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAmbushStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAncientGuard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAncientWisdom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAncientWrath(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAnomaly(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAntidote(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackApotheosis(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAquaJet(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackArcaneEruption(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackArcticWinds(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAshCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAstralChains(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackAuraOfReverence(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBedrockShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBlazingCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBlessing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBlizzard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBloodScent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBloom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBodySlam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBoneSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBoulderCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBoulderToss(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBrambleTrap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackBrineSpray(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCallOfTheVoid(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCanopyShade(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCatastrophe(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCavitation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCelestialCall(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackChannelDivinity(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackChaosWhisper(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCinderStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackColdSnap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackColossalCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCombustion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackConsume(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackContagion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCorrupt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCorruptingTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCosmicRay(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCripplingBlow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCryoBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, memory, r, BATTLER_OFFSET, 32, PAL_BRIGHT_CYAN);
        ReDrawBattler(graphics, memory, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, memory, onAttacker, r);
    return true;
}

SET_MEMORY(".battle")
bool SkillAttackCursedEmbrace(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackCursedGround(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDarkRitual(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDeathsDoor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDeepCurrent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDemonicPact(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDiabolicCry(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDisarm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDissonance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDivineIntervention(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDivineSmite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDraconicFury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDragonBreath(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDreamDust(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackDrowningGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEarthenPrison(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEarthquake(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEarthquakeStomp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEldritchBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, memory, r, BATTLER_OFFSET, 32, PAL_DARK_BLU_PURP);
        ReDrawBattler(graphics, memory, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, memory, onAttacker, r);
    return true;
}

SET_MEMORY(".battle")
bool SkillAttackEmber(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEmberRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEnchantingMelody(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEpitaph(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackEternalGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackExorcism(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFaerieFire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFaeWhisper(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFearRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFelblaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFeralRage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFireball(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFlameBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, memory, r, BATTLER_OFFSET, 32, PAL_BRIGHT_RED);
        ReDrawBattler(graphics, memory, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, memory, onAttacker, r);
    return true;
}

SET_MEMORY(".battle")
bool SkillAttackFlamePunch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFlare(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFlyby(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackForestWard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFossilize(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFreeze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFrostBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFrostNova(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackFrozenOrb(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGeoBarrier(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGlacialSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGladeTeleport(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGlamour(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGoldenInstinct(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGraveTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGravityRoot(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGroundPound(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackGuardBreak(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHailstorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHaloOfGrace(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHaunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHellfire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHellscape(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHolyLight(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHowlOfThePack(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHuntingInstinct(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackHydroBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, memory, r, BATTLER_OFFSET, 32, PAL_DEEP_BLUE);
        ReDrawBattler(graphics, memory, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, memory, onAttacker, r);
    return true;
}

SET_MEMORY(".battle")
bool SkillAttackHypervision(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIceArmor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIceLance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIceShard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIncinerate(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackInfectiousTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackInfernalRush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackInferno(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIronGrip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackIronWill(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackJudgement(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackKiss(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLandslide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLandShift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLavaBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLeafStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLifeDrain(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLuminaBlessing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLunge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackLustfulGlare(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMaddeningGaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMaelstrom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMagmaBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMagmaFlow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMightyThrow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMindSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMiracle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMirrorGlamour(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMoonbeam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMountainBreaker(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMudClaw(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMudSlide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackMysticTangle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackNecroticBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackNerveStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackNeurotoxin(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackOvergrowth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPackCall(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackParalyze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackParry(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPermafrost(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPetalBlitz(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPetalDance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPetrifyingGaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPetrifyingTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPhantomGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPixieDust(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPlague(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackToxicFang(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackToxicIvy(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackToxicMist(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPolarVortex(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPollenCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPounce(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        MoveCenterToLeft(graphics, hardware, r, BATTLER_OFFSET, 32);
        MoveLeftToCenter(graphics, hardware, r, BATTLER_OFFSET, 16);
    }
    else
    {
        MoveCenterToRight(graphics, hardware, r, BATTLER_OFFSET, 32);
        MoveRightToCenter(graphics, hardware, r, BATTLER_OFFSET, 16);
    }
    return true;
}

SET_MEMORY(".battle")
bool SkillAttackPrayer(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPreciseStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPredatorFocus(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPressureCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPrimalScream(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPrimordialForce(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPsychicShock(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPurify(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPurifyCure(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackPyre(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackQuicksand(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRaiseMinion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRally(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRealitySlip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRighteousFury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRiptide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRipAndTear(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRockThrow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRootAnchor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackRunicAegis(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSacredShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSacrifice(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSanityBreak(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSavageMaul(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackScalesHarden(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackScaleStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackScorch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackScratch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSecondWind(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSeedVolley(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSeismicSlam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSeraphicWard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackShellbreaker(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackShieldBash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSkyDive(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSlash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSleepOfAges(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSnowBlind(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSoulSiphon(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSporeExplosion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStalk(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStarSprinkle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSting(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStomp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStoneSkin(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStoneSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackStoneTide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSultryLook(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSunfury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackSurge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

/************************************************************************************************************
 *  Sprite slowly backs off
 *  Then quickly moves forward to its default position
 ************************************************************************************************************/
SET_MEMORY(".battle")
bool SkillAttackTackle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    if (onAttacker)
    {
        MoveCenterToLeft(graphics, hardware, r, BATTLER_OFFSET, 32);
        MoveLeftToCenter(graphics, hardware, r, BATTLER_OFFSET, 16);
    }
    else
    {
        MoveCenterToRight(graphics, hardware, r, BATTLER_OFFSET, 32);
        MoveRightToCenter(graphics, hardware, r, BATTLER_OFFSET, 16);
    }

    ReDrawBattler(graphics, memory, onAttacker, r);
    return true;
}


SET_MEMORY(".battle")
bool SkillAttackTacticalRetreat(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTailSweep(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTailWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTaunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTemporalShift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTemptation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTerraform(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTerrifyingRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackThornBarrage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackThoughtLeech(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackThroatClamp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTidalWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTimeWarp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTitanicRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTitanSwing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTombShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTorrent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackToxicBarrage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackToxicCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTreasureHunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTremorStep(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTremorWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTricksterTreat(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackTwilightShimmer(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVampiricWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVenomousTail(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVenomSpit(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVerdantGrowth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackViciousBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVineWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVirulentBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVoidRift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackVolcanicOutburst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWail(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWarpPulse(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWaterWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWhirlpool(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWildfire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWildMagic(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWingBuffet(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWither(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWorldTear(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

SET_MEMORY(".battle")
bool SkillAttackWyrmCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}
