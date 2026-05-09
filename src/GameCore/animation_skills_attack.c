//
// Created by nathanial on 4/10/26.
//

#include "animation_effects.h"
#include "entities.h"
#include "memory_ram.h"
#include "memory_rom.h"

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


/************************************************************************************************************
 *  Sprite straight floats up off the top of the battler area
 *  Floats back down quickly to its default position
 ************************************************************************************************************/
bool Pico_AnimationBattlerFly(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

    MoveCenterToTop(graphics, hardware, r, r.h, 8);
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAttackAbyssalGrasp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAcidSpray(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAmbushStrike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAncientGuard(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAncientWisdom(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAncientWrath(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAnomaly(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAntidote(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackApotheosis(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAquaJet(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackArcaneEruption(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackArcticWinds(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAshCloud(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAstralChains(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackAuraOfReverence(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBash(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBedrockShield(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBlazingCharge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBlessing(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBlizzard(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBloodScent(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBloom(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBodySlam(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBoneSpike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBoulderCrush(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBoulderToss(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBrambleTrap(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackBrineSpray(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCallOfTheVoid(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCanopyShade(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCatastrophe(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCavitation(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCelestialCall(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackChannelDivinity(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackChaosWhisper(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCharge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCinderStorm(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackColdSnap(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackColossalCharge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCombustion(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackConsume(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackContagion(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCorrupt(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCorruptingTouch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCosmicRay(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCripplingBlow(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCrush(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCryoBlast(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, r, BATTLER_OFFSET, 32, PAL_BRIGHT_CYAN);
        ReDrawBattler(graphics, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, onAttacker, r);
    return true;
}

bool SkillAttackCursedEmbrace(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackCursedGround(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDarkRitual(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDeathsDoor(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDeepCurrent(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDemonicPact(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDiabolicCry(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDisarm(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDissonance(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDivineIntervention(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDivineSmite(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDraconicFury(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDragonBreath(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDreamDust(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackDrowningGrasp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEarthenPrison(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEarthquake(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEarthquakeStomp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEldritchBlast(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, r, BATTLER_OFFSET, 32, PAL_DARK_BLU_PURP);
        ReDrawBattler(graphics, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, onAttacker, r);
    return true;
}

bool SkillAttackEmber(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEmberRoar(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEnchantingMelody(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEpitaph(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackEternalGrasp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackExorcism(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFaerieFire(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFaeWhisper(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFearRoar(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFelblaze(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFeralRage(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFireball(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFlameBlast(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, r, BATTLER_OFFSET, 32, PAL_BRIGHT_RED);
        ReDrawBattler(graphics, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, onAttacker, r);
    return true;
}

bool SkillAttackFlamePunch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFlare(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFlyby(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackForestWard(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFossilize(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFreeze(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFrostBite(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFrostNova(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackFrozenOrb(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGeoBarrier(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGlacialSpike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGladeTeleport(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGlamour(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGoldenInstinct(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGraveTouch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGravityRoot(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGroundPound(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackGuardBreak(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHailstorm(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHaloOfGrace(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHaunt(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHellfire(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHellscape(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHolyLight(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHowlOfThePack(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHuntingInstinct(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackHydroBlast(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(graphics, hardware, r, BATTLER_OFFSET, 32, PAL_DEEP_BLUE);
        ReDrawBattler(graphics, onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(graphics, onAttacker, r);
    return true;
}

bool SkillAttackHypervision(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIceArmor(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIceLance(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIceShard(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIncinerate(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackInfectiousTouch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackInfernalRush(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackInferno(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIronGrip(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackIronWill(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackJudgement(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackKiss(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLandslide(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLandShift(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLavaBurst(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLeafStorm(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLifeDrain(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLuminaBlessing(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLunge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackLustfulGlare(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMaddeningGaze(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMaelstrom(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMagmaBurst(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMagmaFlow(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMightyThrow(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMindSpike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMiracle(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMirrorGlamour(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMoonbeam(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMountainBreaker(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMudClaw(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMudSlide(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackMysticTangle(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackNecroticBurst(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackNerveStrike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackNeurotoxin(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackOvergrowth(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPackCall(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackParalyze(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackParry(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPermafrost(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPetalBlitz(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPetalDance(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPetrifyingGaze(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPetrifyingTouch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPhantomGrasp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPixieDust(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPlague(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackToxicFang(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackToxicIvy(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackToxicMist(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPolarVortex(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPollenCloud(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPounce(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

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

bool SkillAttackPrayer(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPreciseStrike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPredatorFocus(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPressureCrush(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPrimalScream(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPrimordialForce(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPsychicShock(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPurify(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPurifyCure(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackPyre(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackQuicksand(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRaiseMinion(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRally(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRealitySlip(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRighteousFury(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRiptide(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRipAndTear(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRockThrow(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRootAnchor(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackRunicAegis(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSacredShield(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSacrifice(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSanityBreak(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSavageMaul(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackScalesHarden(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackScaleStorm(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackScorch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackScratch(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSecondWind(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSeedVolley(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSeismicSlam(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSeraphicWard(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackShellbreaker(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackShieldBash(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSkyDive(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSlash(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSleepOfAges(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSnowBlind(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSoulSiphon(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSporeExplosion(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStalk(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStarSprinkle(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSting(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStomp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStoneSkin(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStoneSpike(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackStoneTide(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSultryLook(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSunfury(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackSurge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

/************************************************************************************************************
 *  Sprite slowly backs off
 *  Then quickly moves forward to its default position
 ************************************************************************************************************/
bool SkillAttackTackle(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, onAttacker, r);

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

    ReDrawBattler(graphics, onAttacker, r);
    return true;
}


bool SkillAttackTacticalRetreat(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTailSweep(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTailWhip(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTaunt(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTemporalShift(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTemptation(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTerraform(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTerrifyingRoar(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackThornBarrage(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackThoughtLeech(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackThroatClamp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTidalWave(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTimeWarp(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTitanicRoar(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTitanSwing(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTombShield(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTorrent(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackToxicBarrage(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackToxicCloud(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTreasureHunt(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTremorStep(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTremorWave(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTricksterTreat(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackTwilightShimmer(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVampiricWave(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVenomousTail(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVenomSpit(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVerdantGrowth(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackViciousBite(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVineWhip(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVirulentBite(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVoidRift(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackVolcanicOutburst(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWail(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWarpPulse(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWaterWhip(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWhirlpool(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWildfire(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWildMagic(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWingBuffet(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWither(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWorldTear(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}

bool SkillAttackWyrmCharge(GraphicsInterface graphics, HardwareInterface hardware, bool onAttacker)
{
    return false;
}
