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
bool Pico_AnimationBattlerFly(bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    MoveCenterToTop(r, r.h, 8);
    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool SkillAttackAbyssalGrasp(bool onAttacker)
{
    return false;
}

bool SkillAttackAcidSpray(bool onAttacker)
{
    return false;
}

bool SkillAttackAmbushStrike(bool onAttacker)
{
    return false;
}

bool SkillAttackAncientGuard(bool onAttacker)
{
    return false;
}

bool SkillAttackAncientWisdom(bool onAttacker)
{
    return false;
}

bool SkillAttackAncientWrath(bool onAttacker)
{
    return false;
}

bool SkillAttackAnomaly(bool onAttacker)
{
    return false;
}

bool SkillAttackAntidote(bool onAttacker)
{
    return false;
}

bool SkillAttackApotheosis(bool onAttacker)
{
    return false;
}

bool SkillAttackAquaJet(bool onAttacker)
{
    return false;
}

bool SkillAttackArcaneEruption(bool onAttacker)
{
    return false;
}

bool SkillAttackArcticWinds(bool onAttacker)
{
    return false;
}

bool SkillAttackAshCloud(bool onAttacker)
{
    return false;
}

bool SkillAttackAstralChains(bool onAttacker)
{
    return false;
}

bool SkillAttackAuraOfReverence(bool onAttacker)
{
    return false;
}

bool SkillAttackBash(bool onAttacker)
{
    return false;
}

bool SkillAttackBedrockShield(bool onAttacker)
{
    return false;
}

bool SkillAttackBlazingCharge(bool onAttacker)
{
    return false;
}

bool SkillAttackBlessing(bool onAttacker)
{
    return false;
}

bool SkillAttackBlizzard(bool onAttacker)
{
    return false;
}

bool SkillAttackBloodScent(bool onAttacker)
{
    return false;
}

bool SkillAttackBloom(bool onAttacker)
{
    return false;
}

bool SkillAttackBodySlam(bool onAttacker)
{
    return false;
}

bool SkillAttackBoneSpike(bool onAttacker)
{
    return false;
}

bool SkillAttackBoulderCrush(bool onAttacker)
{
    return false;
}

bool SkillAttackBoulderToss(bool onAttacker)
{
    return false;
}

bool SkillAttackBrambleTrap(bool onAttacker)
{
    return false;
}

bool SkillAttackBrineSpray(bool onAttacker)
{
    return false;
}

bool SkillAttackCallOfTheVoid(bool onAttacker)
{
    return false;
}

bool SkillAttackCanopyShade(bool onAttacker)
{
    return false;
}

bool SkillAttackCatastrophe(bool onAttacker)
{
    return false;
}

bool SkillAttackCavitation(bool onAttacker)
{
    return false;
}

bool SkillAttackCelestialCall(bool onAttacker)
{
    return false;
}

bool SkillAttackChannelDivinity(bool onAttacker)
{
    return false;
}

bool SkillAttackChaosWhisper(bool onAttacker)
{
    return false;
}

bool SkillAttackCharge(bool onAttacker)
{
    return false;
}

bool SkillAttackCinderStorm(bool onAttacker)
{
    return false;
}

bool SkillAttackColdSnap(bool onAttacker)
{
    return false;
}

bool SkillAttackColossalCharge(bool onAttacker)
{
    return false;
}

bool SkillAttackCombustion(bool onAttacker)
{
    return false;
}

bool SkillAttackConsume(bool onAttacker)
{
    return false;
}

bool SkillAttackContagion(bool onAttacker)
{
    return false;
}

bool SkillAttackCorrupt(bool onAttacker)
{
    return false;
}

bool SkillAttackCorruptingTouch(bool onAttacker)
{
    return false;
}

bool SkillAttackCosmicRay(bool onAttacker)
{
    return false;
}

bool SkillAttackCripplingBlow(bool onAttacker)
{
    return false;
}

bool SkillAttackCrush(bool onAttacker)
{
    return false;
}

bool SkillAttackCryoBlast(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(r, BATTLER_OFFSET, 32, PAL_BRIGHT_CYAN);
        ReDrawBattler(onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(onAttacker, r);
    return true;
}

bool SkillAttackCursedEmbrace(bool onAttacker)
{
    return false;
}

bool SkillAttackCursedGround(bool onAttacker)
{
    return false;
}

bool SkillAttackDarkRitual(bool onAttacker)
{
    return false;
}

bool SkillAttackDeathsDoor(bool onAttacker)
{
    return false;
}

bool SkillAttackDeepCurrent(bool onAttacker)
{
    return false;
}

bool SkillAttackDemonicPact(bool onAttacker)
{
    return false;
}

bool SkillAttackDiabolicCry(bool onAttacker)
{
    return false;
}

bool SkillAttackDisarm(bool onAttacker)
{
    return false;
}

bool SkillAttackDissonance(bool onAttacker)
{
    return false;
}

bool SkillAttackDivineIntervention(bool onAttacker)
{
    return false;
}

bool SkillAttackDivineSmite(bool onAttacker)
{
    return false;
}

bool SkillAttackDraconicFury(bool onAttacker)
{
    return false;
}

bool SkillAttackDragonBreath(bool onAttacker)
{
    return false;
}

bool SkillAttackDreamDust(bool onAttacker)
{
    return false;
}

bool SkillAttackDrowningGrasp(bool onAttacker)
{
    return false;
}

bool SkillAttackEarthenPrison(bool onAttacker)
{
    return false;
}

bool SkillAttackEarthquake(bool onAttacker)
{
    return false;
}

bool SkillAttackEarthquakeStomp(bool onAttacker)
{
    return false;
}

bool SkillAttackEldritchBlast(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(r, BATTLER_OFFSET, 32, PAL_DARK_BLU_PURP);
        ReDrawBattler(onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(onAttacker, r);
    return true;
}

bool SkillAttackEmber(bool onAttacker)
{
    return false;
}

bool SkillAttackEmberRoar(bool onAttacker)
{
    return false;
}

bool SkillAttackEnchantingMelody(bool onAttacker)
{
    return false;
}

bool SkillAttackEpitaph(bool onAttacker)
{
    return false;
}

bool SkillAttackEternalGrasp(bool onAttacker)
{
    return false;
}

bool SkillAttackExorcism(bool onAttacker)
{
    return false;
}

bool SkillAttackFaerieFire(bool onAttacker)
{
    return false;
}

bool SkillAttackFaeWhisper(bool onAttacker)
{
    return false;
}

bool SkillAttackFearRoar(bool onAttacker)
{
    return false;
}

bool SkillAttackFelblaze(bool onAttacker)
{
    return false;
}

bool SkillAttackFeralRage(bool onAttacker)
{
    return false;
}

bool SkillAttackFireball(bool onAttacker)
{
    return false;
}

bool SkillAttackFlameBlast(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(r, BATTLER_OFFSET, 32, PAL_BRIGHT_RED);
        ReDrawBattler(onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(onAttacker, r);
    return true;
}

bool SkillAttackFlamePunch(bool onAttacker)
{
    return false;
}

bool SkillAttackFlare(bool onAttacker)
{
    return false;
}

bool SkillAttackFlyby(bool onAttacker)
{
    return false;
}

bool SkillAttackForestWard(bool onAttacker)
{
    return false;
}

bool SkillAttackFossilize(bool onAttacker)
{
    return false;
}

bool SkillAttackFreeze(bool onAttacker)
{
    return false;
}

bool SkillAttackFrostBite(bool onAttacker)
{
    return false;
}

bool SkillAttackFrostNova(bool onAttacker)
{
    return false;
}

bool SkillAttackFrozenOrb(bool onAttacker)
{
    return false;
}

bool SkillAttackGeoBarrier(bool onAttacker)
{
    return false;
}

bool SkillAttackGlacialSpike(bool onAttacker)
{
    return false;
}

bool SkillAttackGladeTeleport(bool onAttacker)
{
    return false;
}

bool SkillAttackGlamour(bool onAttacker)
{
    return false;
}

bool SkillAttackGoldenInstinct(bool onAttacker)
{
    return false;
}

bool SkillAttackGraveTouch(bool onAttacker)
{
    return false;
}

bool SkillAttackGravityRoot(bool onAttacker)
{
    return false;
}

bool SkillAttackGroundPound(bool onAttacker)
{
    return false;
}

bool SkillAttackGuardBreak(bool onAttacker)
{
    return false;
}

bool SkillAttackHailstorm(bool onAttacker)
{
    return false;
}

bool SkillAttackHaloOfGrace(bool onAttacker)
{
    return false;
}

bool SkillAttackHaunt(bool onAttacker)
{
    return false;
}

bool SkillAttackHellfire(bool onAttacker)
{
    return false;
}

bool SkillAttackHellscape(bool onAttacker)
{
    return false;
}

bool SkillAttackHolyLight(bool onAttacker)
{
    return false;
}

bool SkillAttackHowlOfThePack(bool onAttacker)
{
    return false;
}

bool SkillAttackHuntingInstinct(bool onAttacker)
{
    return false;
}

bool SkillAttackHydroBlast(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        AnimationBeam(r, BATTLER_OFFSET, 32, PAL_DEEP_BLUE);
        ReDrawBattler(onAttacker, r);
    }
    else
    {
    }

    ReDrawBattler(onAttacker, r);
    return true;
}

bool SkillAttackHypervision(bool onAttacker)
{
    return false;
}

bool SkillAttackIceArmor(bool onAttacker)
{
    return false;
}

bool SkillAttackIceLance(bool onAttacker)
{
    return false;
}

bool SkillAttackIceShard(bool onAttacker)
{
    return false;
}

bool SkillAttackIncinerate(bool onAttacker)
{
    return false;
}

bool SkillAttackInfectiousTouch(bool onAttacker)
{
    return false;
}

bool SkillAttackInfernalRush(bool onAttacker)
{
    return false;
}

bool SkillAttackInferno(bool onAttacker)
{
    return false;
}

bool SkillAttackIronGrip(bool onAttacker)
{
    return false;
}

bool SkillAttackIronWill(bool onAttacker)
{
    return false;
}

bool SkillAttackJudgement(bool onAttacker)
{
    return false;
}

bool SkillAttackKiss(bool onAttacker)
{
    return false;
}

bool SkillAttackLandslide(bool onAttacker)
{
    return false;
}

bool SkillAttackLandShift(bool onAttacker)
{
    return false;
}

bool SkillAttackLavaBurst(bool onAttacker)
{
    return false;
}

bool SkillAttackLeafStorm(bool onAttacker)
{
    return false;
}

bool SkillAttackLifeDrain(bool onAttacker)
{
    return false;
}

bool SkillAttackLuminaBlessing(bool onAttacker)
{
    return false;
}

bool SkillAttackLunge(bool onAttacker)
{
    return false;
}

bool SkillAttackLustfulGlare(bool onAttacker)
{
    return false;
}

bool SkillAttackMaddeningGaze(bool onAttacker)
{
    return false;
}

bool SkillAttackMaelstrom(bool onAttacker)
{
    return false;
}

bool SkillAttackMagmaBurst(bool onAttacker)
{
    return false;
}

bool SkillAttackMagmaFlow(bool onAttacker)
{
    return false;
}

bool SkillAttackMightyThrow(bool onAttacker)
{
    return false;
}

bool SkillAttackMindSpike(bool onAttacker)
{
    return false;
}

bool SkillAttackMiracle(bool onAttacker)
{
    return false;
}

bool SkillAttackMirrorGlamour(bool onAttacker)
{
    return false;
}

bool SkillAttackMoonbeam(bool onAttacker)
{
    return false;
}

bool SkillAttackMountainBreaker(bool onAttacker)
{
    return false;
}

bool SkillAttackMudClaw(bool onAttacker)
{
    return false;
}

bool SkillAttackMudSlide(bool onAttacker)
{
    return false;
}

bool SkillAttackMysticTangle(bool onAttacker)
{
    return false;
}

bool SkillAttackNecroticBurst(bool onAttacker)
{
    return false;
}

bool SkillAttackNerveStrike(bool onAttacker)
{
    return false;
}

bool SkillAttackNeurotoxin(bool onAttacker)
{
    return false;
}

bool SkillAttackOvergrowth(bool onAttacker)
{
    return false;
}

bool SkillAttackPackCall(bool onAttacker)
{
    return false;
}

bool SkillAttackParalyze(bool onAttacker)
{
    return false;
}

bool SkillAttackParry(bool onAttacker)
{
    return false;
}

bool SkillAttackPermafrost(bool onAttacker)
{
    return false;
}

bool SkillAttackPetalBlitz(bool onAttacker)
{
    return false;
}

bool SkillAttackPetalDance(bool onAttacker)
{
    return false;
}

bool SkillAttackPetrifyingGaze(bool onAttacker)
{
    return false;
}

bool SkillAttackPetrifyingTouch(bool onAttacker)
{
    return false;
}

bool SkillAttackPhantomGrasp(bool onAttacker)
{
    return false;
}

bool SkillAttackPixieDust(bool onAttacker)
{
    return false;
}

bool SkillAttackPlague(bool onAttacker)
{
    return false;
}

bool SkillAttackToxicFang(bool onAttacker)
{
    return false;
}

bool SkillAttackToxicIvy(bool onAttacker)
{
    return false;
}

bool SkillAttackToxicMist(bool onAttacker)
{
    return false;
}

bool SkillAttackPolarVortex(bool onAttacker)
{
    return false;
}

bool SkillAttackPollenCloud(bool onAttacker)
{
    return false;
}

bool SkillAttackPounce(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        MoveCenterToLeft(r, BATTLER_OFFSET, 32);
        MoveLeftToCenter(r, BATTLER_OFFSET, 16);
    }
    else
    {
        MoveCenterToRight(r, BATTLER_OFFSET, 32);
        MoveRightToCenter(r, BATTLER_OFFSET, 16);
    }
    return true;
}

bool SkillAttackPrayer(bool onAttacker)
{
    return false;
}

bool SkillAttackPreciseStrike(bool onAttacker)
{
    return false;
}

bool SkillAttackPredatorFocus(bool onAttacker)
{
    return false;
}

bool SkillAttackPressureCrush(bool onAttacker)
{
    return false;
}

bool SkillAttackPrimalScream(bool onAttacker)
{
    return false;
}

bool SkillAttackPrimordialForce(bool onAttacker)
{
    return false;
}

bool SkillAttackPsychicShock(bool onAttacker)
{
    return false;
}

bool SkillAttackPurify(bool onAttacker)
{
    return false;
}

bool SkillAttackPurifyCure(bool onAttacker)
{
    return false;
}

bool SkillAttackPyre(bool onAttacker)
{
    return false;
}

bool SkillAttackQuicksand(bool onAttacker)
{
    return false;
}

bool SkillAttackRaiseMinion(bool onAttacker)
{
    return false;
}

bool SkillAttackRally(bool onAttacker)
{
    return false;
}

bool SkillAttackRealitySlip(bool onAttacker)
{
    return false;
}

bool SkillAttackRighteousFury(bool onAttacker)
{
    return false;
}

bool SkillAttackRiptide(bool onAttacker)
{
    return false;
}

bool SkillAttackRipAndTear(bool onAttacker)
{
    return false;
}

bool SkillAttackRockThrow(bool onAttacker)
{
    return false;
}

bool SkillAttackRootAnchor(bool onAttacker)
{
    return false;
}

bool SkillAttackRunicAegis(bool onAttacker)
{
    return false;
}

bool SkillAttackSacredShield(bool onAttacker)
{
    return false;
}

bool SkillAttackSacrifice(bool onAttacker)
{
    return false;
}

bool SkillAttackSanityBreak(bool onAttacker)
{
    return false;
}

bool SkillAttackSavageMaul(bool onAttacker)
{
    return false;
}

bool SkillAttackScalesHarden(bool onAttacker)
{
    return false;
}

bool SkillAttackScaleStorm(bool onAttacker)
{
    return false;
}

bool SkillAttackScorch(bool onAttacker)
{
    return false;
}

bool SkillAttackScratch(bool onAttacker)
{
    return false;
}

bool SkillAttackSecondWind(bool onAttacker)
{
    return false;
}

bool SkillAttackSeedVolley(bool onAttacker)
{
    return false;
}

bool SkillAttackSeismicSlam(bool onAttacker)
{
    return false;
}

bool SkillAttackSeraphicWard(bool onAttacker)
{
    return false;
}

bool SkillAttackShellbreaker(bool onAttacker)
{
    return false;
}

bool SkillAttackShieldBash(bool onAttacker)
{
    return false;
}

bool SkillAttackSkyDive(bool onAttacker)
{
    return false;
}

bool SkillAttackSlash(bool onAttacker)
{
    return false;
}

bool SkillAttackSleepOfAges(bool onAttacker)
{
    return false;
}

bool SkillAttackSnowBlind(bool onAttacker)
{
    return false;
}

bool SkillAttackSoulSiphon(bool onAttacker)
{
    return false;
}

bool SkillAttackSporeExplosion(bool onAttacker)
{
    return false;
}

bool SkillAttackStalk(bool onAttacker)
{
    return false;
}

bool SkillAttackStarSprinkle(bool onAttacker)
{
    return false;
}

bool SkillAttackSting(bool onAttacker)
{
    return false;
}

bool SkillAttackStomp(bool onAttacker)
{
    return false;
}

bool SkillAttackStoneSkin(bool onAttacker)
{
    return false;
}

bool SkillAttackStoneSpike(bool onAttacker)
{
    return false;
}

bool SkillAttackStoneTide(bool onAttacker)
{
    return false;
}

bool SkillAttackSultryLook(bool onAttacker)
{
    return false;
}

bool SkillAttackSunfury(bool onAttacker)
{
    return false;
}

bool SkillAttackSurge(bool onAttacker)
{
    return false;
}

/************************************************************************************************************
 *  Sprite slowly backs off
 *  Then quickly moves forward to its default position
 ************************************************************************************************************/
bool SkillAttackTackle(bool onAttacker)
{

    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    if (onAttacker)
    {
        MoveCenterToLeft(r, BATTLER_OFFSET, 32);
        MoveLeftToCenter(r, BATTLER_OFFSET, 16);
    }
    else
    {
        MoveCenterToRight(r, BATTLER_OFFSET, 32);
        MoveRightToCenter(r, BATTLER_OFFSET, 16);
    }

    ReDrawBattler(onAttacker, r);
    return true;
}


bool SkillAttackTacticalRetreat(bool onAttacker)
{
    return false;
}

bool SkillAttackTailSweep(bool onAttacker)
{
    return false;
}

bool SkillAttackTailWhip(bool onAttacker)
{
    return false;
}

bool SkillAttackTaunt(bool onAttacker)
{
    return false;
}

bool SkillAttackTemporalShift(bool onAttacker)
{
    return false;
}

bool SkillAttackTemptation(bool onAttacker)
{
    return false;
}

bool SkillAttackTerraform(bool onAttacker)
{
    return false;
}

bool SkillAttackTerrifyingRoar(bool onAttacker)
{
    return false;
}

bool SkillAttackThornBarrage(bool onAttacker)
{
    return false;
}

bool SkillAttackThoughtLeech(bool onAttacker)
{
    return false;
}

bool SkillAttackThroatClamp(bool onAttacker)
{
    return false;
}

bool SkillAttackTidalWave(bool onAttacker)
{
    return false;
}

bool SkillAttackTimeWarp(bool onAttacker)
{
    return false;
}

bool SkillAttackTitanicRoar(bool onAttacker)
{
    return false;
}

bool SkillAttackTitanSwing(bool onAttacker)
{
    return false;
}

bool SkillAttackTombShield(bool onAttacker)
{
    return false;
}

bool SkillAttackTorrent(bool onAttacker)
{
    return false;
}

bool SkillAttackToxicBarrage(bool onAttacker)
{
    return false;
}

bool SkillAttackToxicCloud(bool onAttacker)
{
    return false;
}

bool SkillAttackTreasureHunt(bool onAttacker)
{
    return false;
}

bool SkillAttackTremorStep(bool onAttacker)
{
    return false;
}

bool SkillAttackTremorWave(bool onAttacker)
{
    return false;
}

bool SkillAttackTricksterTreat(bool onAttacker)
{
    return false;
}

bool SkillAttackTwilightShimmer(bool onAttacker)
{
    return false;
}

bool SkillAttackVampiricWave(bool onAttacker)
{
    return false;
}

bool SkillAttackVenomousTail(bool onAttacker)
{
    return false;
}

bool SkillAttackVenomSpit(bool onAttacker)
{
    return false;
}

bool SkillAttackVerdantGrowth(bool onAttacker)
{
    return false;
}

bool SkillAttackViciousBite(bool onAttacker)
{
    return false;
}

bool SkillAttackVineWhip(bool onAttacker)
{
    return false;
}

bool SkillAttackVirulentBite(bool onAttacker)
{
    return false;
}

bool SkillAttackVoidRift(bool onAttacker)
{
    return false;
}

bool SkillAttackVolcanicOutburst(bool onAttacker)
{
    return false;
}

bool SkillAttackWail(bool onAttacker)
{
    return false;
}

bool SkillAttackWarpPulse(bool onAttacker)
{
    return false;
}

bool SkillAttackWaterWhip(bool onAttacker)
{
    return false;
}

bool SkillAttackWhirlpool(bool onAttacker)
{
    return false;
}

bool SkillAttackWildfire(bool onAttacker)
{
    return false;
}

bool SkillAttackWildMagic(bool onAttacker)
{
    return false;
}

bool SkillAttackWingBuffet(bool onAttacker)
{
    return false;
}

bool SkillAttackWither(bool onAttacker)
{
    return false;
}

bool SkillAttackWorldTear(bool onAttacker)
{
    return false;
}

bool SkillAttackWyrmCharge(bool onAttacker)
{
    return false;
}
