//
// Created by nathanial on 4/13/26.
//

#include "animation_effects.h"


/************************************************************************************************************
 *
 *  Animations for each skill are composed with functions from the animations_effects.h file
 *  Each function runs sequentially go give a unique animation effect
 *  work in progress, empty functions are no animation effect and instant
 *
 ************************************************************************************************************/


/************************************************************************************************************
 *
 *      Utility functions
 *
 ************************************************************************************************************/

/************************************************************************************************************
 *  shakes the battler back and forth
 ************************************************************************************************************/
void CommonStruckAnimation(bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);

    uint8_t l = BATTLER_OFFSET / 2;

    MoveCenterToRight(r, l, 2);
    MoveRightToCenter(r, l, 2);
    MoveCenterToLeft(r, l, 2);
    MoveLeftToCenter(r, l, 2);
    MoveCenterToRight(r, l, 4);
    MoveRightToCenter(r, l, 4);
    MoveCenterToLeft(r, l, 4);
    MoveLeftToCenter(r, l, 4);
}

/************************************************************************************************************
 *  Draws random 4px x 4px squares on the battler of the given colour
 ************************************************************************************************************/
void SparkleStruckAnimation(bool onAttacker, uint8_t palletIndex)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);
    AnimationRandomParticles(r, BATTLER_OFFSET, 64, palletIndex, 32);
    RefreshBattler(onAttacker, r);
}


/************************************************************************************************************
 *
 *      Implementations
 *
 ************************************************************************************************************/

/************************************************************************************************************
 *
 ************************************************************************************************************/
bool SkillStruckAbyssalGrasp(bool onAttacker)
{
    return false;
}

bool SkillStruckAcidSpray(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_EMERALD_GREEN);
    return false;
}

bool SkillStruckAmbushStrike(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckAncientGuard(bool onAttacker)
{
    return false;
}

bool SkillStruckAncientWisdom(bool onAttacker)
{
    return false;
}

bool SkillStruckAncientWrath(bool onAttacker)
{
    return false;
}

bool SkillStruckAnomaly(bool onAttacker)
{
    return false;
}

bool SkillStruckAntidote(bool onAttacker)
{
    return false;
}

bool SkillStruckApotheosis(bool onAttacker)
{
    return false;
}

bool SkillStruckAquaJet(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckArcaneEruption(bool onAttacker)
{
    return false;
}

bool SkillStruckArcticWinds(bool onAttacker)
{
    return false;
}

bool SkillStruckAshCloud(bool onAttacker)
{
    return false;
}

bool SkillStruckAstralChains(bool onAttacker)
{
    return false;
}

bool SkillStruckAuraOfReverence(bool onAttacker)
{
    return false;
}

bool SkillStruckBash(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckBedrockShield(bool onAttacker)
{
    return false;
}

bool SkillStruckBlazingCharge(bool onAttacker)
{
    return false;
}

bool SkillStruckBlessing(bool onAttacker)
{
    return false;
}

bool SkillStruckBlizzard(bool onAttacker)
{
    return false;
}

bool SkillStruckBloodScent(bool onAttacker)
{
    return false;
}

bool SkillStruckBloom(bool onAttacker)
{
    return false;
}

bool SkillStruckBodySlam(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckBoneSpike(bool onAttacker)
{
    return false;
}

bool SkillStruckBoulderCrush(bool onAttacker)
{
    return false;
}

bool SkillStruckBoulderToss(bool onAttacker)
{
    return false;
}

bool SkillStruckBrambleTrap(bool onAttacker)
{
    return false;
}

bool SkillStruckBrineSpray(bool onAttacker)
{
    return false;
}

bool SkillStruckCallOfTheVoid(bool onAttacker)
{
    return false;
}

bool SkillStruckCanopyShade(bool onAttacker)
{
    return false;
}

bool SkillStruckCatastrophe(bool onAttacker)
{
    return false;
}

bool SkillStruckCavitation(bool onAttacker)
{
    return false;
}

bool SkillStruckCelestialCall(bool onAttacker)
{
    return false;
}

bool SkillStruckChannelDivinity(bool onAttacker)
{
    return false;
}

bool SkillStruckChaosWhisper(bool onAttacker)
{
    return false;
}

bool SkillStruckCharge(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckCinderStorm(bool onAttacker)
{
    return false;
}

bool SkillStruckColdSnap(bool onAttacker)
{
    return false;
}

bool SkillStruckColossalCharge(bool onAttacker)
{
    return false;
}

bool SkillStruckCombustion(bool onAttacker)
{
    return false;
}

bool SkillStruckConsume(bool onAttacker)
{
    return false;
}

bool SkillStruckContagion(bool onAttacker)
{
    return false;
}

bool SkillStruckCorrupt(bool onAttacker)
{
    return false;
}

bool SkillStruckCorruptingTouch(bool onAttacker)
{
    return false;
}

bool SkillStruckCosmicRay(bool onAttacker)
{
    return false;
}

bool SkillStruckCripplingBlow(bool onAttacker)
{
    return false;
}

bool SkillStruckCrush(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckCryoBlast(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckCursedEmbrace(bool onAttacker)
{
    return false;
}

bool SkillStruckCursedGround(bool onAttacker)
{
    return false;
}

bool SkillStruckDarkRitual(bool onAttacker)
{
    return false;
}

bool SkillStruckDeathsDoor(bool onAttacker)
{
    return false;
}

bool SkillStruckDeepCurrent(bool onAttacker)
{
    return false;
}

bool SkillStruckDemonicPact(bool onAttacker)
{
    return false;
}

bool SkillStruckDiabolicCry(bool onAttacker)
{
    return false;
}

bool SkillStruckDisarm(bool onAttacker)
{
    return false;
}

bool SkillStruckDissonance(bool onAttacker)
{
    return false;
}

bool SkillStruckDivineIntervention(bool onAttacker)
{
    return false;
}

bool SkillStruckDivineSmite(bool onAttacker)
{
    return false;
}

bool SkillStruckDraconicFury(bool onAttacker)
{
    return false;
}

bool SkillStruckDragonBreath(bool onAttacker)
{
    return false;
}

bool SkillStruckDreamDust(bool onAttacker)
{
    return false;
}

bool SkillStruckDrowningGrasp(bool onAttacker)
{
    return false;
}

bool SkillStruckEarthenPrison(bool onAttacker)
{
    return false;
}

bool SkillStruckEarthquake(bool onAttacker)
{
    return false;
}

bool SkillStruckEarthquakeStomp(bool onAttacker)
{
    return false;
}

bool SkillStruckEldritchBlast(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_PURPLE_BLUE);
    return true;
}

bool SkillStruckEmber(bool onAttacker)
{
    return false;
}

bool SkillStruckEmberRoar(bool onAttacker)
{
    return false;
}

bool SkillStruckEnchantingMelody(bool onAttacker)
{
    return false;
}

bool SkillStruckEpitaph(bool onAttacker)
{
    return false;
}

bool SkillStruckEternalGrasp(bool onAttacker)
{
    return false;
}

bool SkillStruckExorcism(bool onAttacker)
{
    return false;
}

bool SkillStruckFaerieFire(bool onAttacker)
{
    return false;
}

bool SkillStruckFaeWhisper(bool onAttacker)
{
    return false;
}

bool SkillStruckFearRoar(bool onAttacker)
{
    return false;
}

bool SkillStruckFelblaze(bool onAttacker)
{
    return false;
}

bool SkillStruckFeralRage(bool onAttacker)
{
    return false;
}

bool SkillStruckFireball(bool onAttacker)
{
    return false;
}

bool SkillStruckFlameBlast(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_BRIGHT_ORANGE);
    return true;
}

bool SkillStruckFlamePunch(bool onAttacker)
{
    return false;
}

bool SkillStruckFlare(bool onAttacker)
{
    return false;
}

bool SkillStruckFlyby(bool onAttacker)
{
    return false;
}

bool SkillStruckForestWard(bool onAttacker)
{
    return false;
}

bool SkillStruckFossilize(bool onAttacker)
{
    return false;
}

bool SkillStruckFreeze(bool onAttacker)
{
    return false;
}

bool SkillStruckFrostBite(bool onAttacker)
{
    return false;
}

bool SkillStruckFrostNova(bool onAttacker)
{
    return false;
}

bool SkillStruckFrozenOrb(bool onAttacker)
{
    return false;
}

bool SkillStruckGeoBarrier(bool onAttacker)
{
    return false;
}

bool SkillStruckGlacialSpike(bool onAttacker)
{
    return false;
}

bool SkillStruckGladeTeleport(bool onAttacker)
{
    return false;
}

bool SkillStruckGlamour(bool onAttacker)
{
    return false;
}

bool SkillStruckGoldenInstinct(bool onAttacker)
{
    return false;
}

bool SkillStruckGraveTouch(bool onAttacker)
{
    return false;
}

bool SkillStruckGravityRoot(bool onAttacker)
{
    return false;
}

bool SkillStruckGroundPound(bool onAttacker)
{
    return false;
}

bool SkillStruckGuardBreak(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckHailstorm(bool onAttacker)
{
    return false;
}

bool SkillStruckHaloOfGrace(bool onAttacker)
{
    return false;
}

bool SkillStruckHaunt(bool onAttacker)
{
    return false;
}

bool SkillStruckHellfire(bool onAttacker)
{
    return false;
}

bool SkillStruckHellscape(bool onAttacker)
{
    return false;
}

bool SkillStruckHolyLight(bool onAttacker)
{
    return false;
}

bool SkillStruckHowlOfThePack(bool onAttacker)
{
    return false;
}

bool SkillStruckHuntingInstinct(bool onAttacker)
{
    return false;
}

bool SkillStruckHydroBlast(bool onAttacker)
{
    SparkleStruckAnimation(onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckHypervision(bool onAttacker)
{
    return false;
}

bool SkillStruckIceArmor(bool onAttacker)
{
    return false;
}

bool SkillStruckIceLance(bool onAttacker)
{
    return false;
}

bool SkillStruckIceShard(bool onAttacker)
{
    return false;
}

bool SkillStruckIncinerate(bool onAttacker)
{
    return false;
}

bool SkillStruckInfectiousTouch(bool onAttacker)
{
    return false;
}

bool SkillStruckInfernalRush(bool onAttacker)
{
    return false;
}

bool SkillStruckInferno(bool onAttacker)
{
    return false;
}

bool SkillStruckIronGrip(bool onAttacker)
{
    return false;
}

bool SkillStruckIronWill(bool onAttacker)
{
    return false;
}

bool SkillStruckJudgement(bool onAttacker)
{
    return false;
}

bool SkillStruckKiss(bool onAttacker)
{
    return false;
}

bool SkillStruckLandslide(bool onAttacker)
{
    return false;
}

bool SkillStruckLandShift(bool onAttacker)
{
    return false;
}

bool SkillStruckLavaBurst(bool onAttacker)
{
    return false;
}

bool SkillStruckLeafStorm(bool onAttacker)
{
    return false;
}

bool SkillStruckLifeDrain(bool onAttacker)
{
    return false;
}

bool SkillStruckLuminaBlessing(bool onAttacker)
{
    return false;
}

bool SkillStruckLunge(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckLustfulGlare(bool onAttacker)
{
    return false;
}

bool SkillStruckMaddeningGaze(bool onAttacker)
{
    return false;
}

bool SkillStruckMaelstrom(bool onAttacker)
{
    return false;
}

bool SkillStruckMagmaBurst(bool onAttacker)
{
    return false;
}

bool SkillStruckMagmaFlow(bool onAttacker)
{
    return false;
}

bool SkillStruckMightyThrow(bool onAttacker)
{
    return false;
}

bool SkillStruckMindSpike(bool onAttacker)
{
    return false;
}

bool SkillStruckMiracle(bool onAttacker)
{
    return false;
}

bool SkillStruckMirrorGlamour(bool onAttacker)
{
    return false;
}

bool SkillStruckMoonbeam(bool onAttacker)
{
    return false;
}

bool SkillStruckMountainBreaker(bool onAttacker)
{
    return false;
}

bool SkillStruckMudClaw(bool onAttacker)
{
    return false;
}

bool SkillStruckMudSlide(bool onAttacker)
{
    return false;
}

bool SkillStruckMysticTangle(bool onAttacker)
{
    return false;
}

bool SkillStruckNecroticBurst(bool onAttacker)
{
    return false;
}

bool SkillStruckNerveStrike(bool onAttacker)
{
    return false;
}

bool SkillStruckNeurotoxin(bool onAttacker)
{
    return false;
}

bool SkillStruckOvergrowth(bool onAttacker)
{
    return false;
}

bool SkillStruckPackCall(bool onAttacker)
{
    return false;
}

bool SkillStruckParalyze(bool onAttacker)
{
    return false;
}

bool SkillStruckParry(bool onAttacker)
{
    return false;
}

bool SkillStruckPermafrost(bool onAttacker)
{
    return false;
}

bool SkillStruckPetalBlitz(bool onAttacker)
{
    return false;
}

bool SkillStruckPetalDance(bool onAttacker)
{
    return false;
}

bool SkillStruckPetrifyingGaze(bool onAttacker)
{
    return false;
}

bool SkillStruckPetrifyingTouch(bool onAttacker)
{
    return false;
}

bool SkillStruckPhantomGrasp(bool onAttacker)
{
    return false;
}

bool SkillStruckPixieDust(bool onAttacker)
{
    return false;
}

bool SkillStruckPlague(bool onAttacker)
{
    return false;
}

bool SkillStruckToxicFang(bool onAttacker)
{
    return false;
}

bool SkillStruckToxicIvy(bool onAttacker)
{
    return false;
}

bool SkillStruckToxicMist(bool onAttacker)
{
    return false;
}

bool SkillStruckPolarVortex(bool onAttacker)
{
    return false;
}

bool SkillStruckPollenCloud(bool onAttacker)
{
    return false;
}

bool SkillStruckPounce(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckPrayer(bool onAttacker)
{
    return false;
}

bool SkillStruckPreciseStrike(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckPredatorFocus(bool onAttacker)
{
    return false;
}

bool SkillStruckPressureCrush(bool onAttacker)
{
    return false;
}

bool SkillStruckPrimalScream(bool onAttacker)
{
    return false;
}

bool SkillStruckPrimordialForce(bool onAttacker)
{
    return false;
}

bool SkillStruckPsychicShock(bool onAttacker)
{
    return false;
}

bool SkillStruckPurify(bool onAttacker)
{
    return false;
}

bool SkillStruckPurifyCure(bool onAttacker)
{
    return false;
}

bool SkillStruckPyre(bool onAttacker)
{
    return false;
}

bool SkillStruckQuicksand(bool onAttacker)
{
    return false;
}

bool SkillStruckRaiseMinion(bool onAttacker)
{
    return false;
}

bool SkillStruckRally(bool onAttacker)
{
    return false;
}

bool SkillStruckRealitySlip(bool onAttacker)
{
    return false;
}

bool SkillStruckRighteousFury(bool onAttacker)
{
    return false;
}

bool SkillStruckRiptide(bool onAttacker)
{
    return false;
}

bool SkillStruckRipAndTear(bool onAttacker)
{
    return false;
}

bool SkillStruckRockThrow(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckRootAnchor(bool onAttacker)
{
    return false;
}

bool SkillStruckRunicAegis(bool onAttacker)
{
    return false;
}

bool SkillStruckSacredShield(bool onAttacker)
{
    return false;
}

bool SkillStruckSacrifice(bool onAttacker)
{
    return false;
}

bool SkillStruckSanityBreak(bool onAttacker)
{
    return false;
}

bool SkillStruckSavageMaul(bool onAttacker)
{
    return false;
}

bool SkillStruckScalesHarden(bool onAttacker)
{
    return false;
}

bool SkillStruckScaleStorm(bool onAttacker)
{
    return false;
}

bool SkillStruckScorch(bool onAttacker)
{
    return false;
}

bool SkillStruckScratch(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckSecondWind(bool onAttacker)
{
    return false;
}

bool SkillStruckSeedVolley(bool onAttacker)
{
    return false;
}

bool SkillStruckSeismicSlam(bool onAttacker)
{
    return false;
}

bool SkillStruckSeraphicWard(bool onAttacker)
{
    return false;
}

bool SkillStruckShellbreaker(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckShieldBash(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckSkyDive(bool onAttacker)
{
    return false;
}

bool SkillStruckSlash(bool onAttacker)
{
    return false;
}

bool SkillStruckSleepOfAges(bool onAttacker)
{
    return false;
}

bool SkillStruckSnowBlind(bool onAttacker)
{
    return false;
}

bool SkillStruckSoulSiphon(bool onAttacker)
{
    return false;
}

bool SkillStruckSporeExplosion(bool onAttacker)
{
    return false;
}

bool SkillStruckStalk(bool onAttacker)
{
    return false;
}

bool SkillStruckStarSprinkle(bool onAttacker)
{
    return false;
}

bool SkillStruckSting(bool onAttacker)
{
    return false;
}

bool SkillStruckStomp(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}

bool SkillStruckStoneSkin(bool onAttacker)
{
    return false;
}

bool SkillStruckStoneSpike(bool onAttacker)
{
    return false;
}

bool SkillStruckStoneTide(bool onAttacker)
{
    return false;
}

bool SkillStruckSultryLook(bool onAttacker)
{
    return false;
}

bool SkillStruckSunfury(bool onAttacker)
{
    return false;
}

bool SkillStruckSurge(bool onAttacker)
{
    return false;
}

bool SkillStruckTackle(bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(onAttacker, r);
    uint8_t l = BATTLER_OFFSET / 2;

    CommonStruckAnimation(onAttacker);
    return true;
}

bool SkillStruckTacticalRetreat(bool onAttacker)
{
    return false;
}

bool SkillStruckTailSweep(bool onAttacker)
{
    return false;
}

bool SkillStruckTailWhip(bool onAttacker)
{
    return false;
}

bool SkillStruckTaunt(bool onAttacker)
{
    return false;
}

bool SkillStruckTemporalShift(bool onAttacker)
{
    return false;
}

bool SkillStruckTemptation(bool onAttacker)
{
    return false;
}

bool SkillStruckTerraform(bool onAttacker)
{
    return false;
}

bool SkillStruckTerrifyingRoar(bool onAttacker)
{
    return false;
}

bool SkillStruckThornBarrage(bool onAttacker)
{
    return false;
}

bool SkillStruckThoughtLeech(bool onAttacker)
{
    return false;
}

bool SkillStruckThroatClamp(bool onAttacker)
{
    return false;
}

bool SkillStruckTidalWave(bool onAttacker)
{
    return false;
}

bool SkillStruckTimeWarp(bool onAttacker)
{
    return false;
}

bool SkillStruckTitanicRoar(bool onAttacker)
{
    return false;
}

bool SkillStruckTitanSwing(bool onAttacker)
{
    return false;
}

bool SkillStruckTombShield(bool onAttacker)
{
    return false;
}

bool SkillStruckTorrent(bool onAttacker)
{
    return false;
}

bool SkillStruckToxicBarrage(bool onAttacker)
{
    return false;
}

bool SkillStruckToxicCloud(bool onAttacker)
{
    return false;
}

bool SkillStruckTreasureHunt(bool onAttacker)
{
    return false;
}

bool SkillStruckTremorStep(bool onAttacker)
{
    return false;
}

bool SkillStruckTremorWave(bool onAttacker)
{
    return false;
}

bool SkillStruckTricksterTreat(bool onAttacker)
{
    return false;
}

bool SkillStruckTwilightShimmer(bool onAttacker)
{
    return false;
}

bool SkillStruckVampiricWave(bool onAttacker)
{
    return false;
}

bool SkillStruckVenomousTail(bool onAttacker)
{
    return false;
}

bool SkillStruckVenomSpit(bool onAttacker)
{
    return false;
}

bool SkillStruckVerdantGrowth(bool onAttacker)
{
    return false;
}

bool SkillStruckViciousBite(bool onAttacker)
{
    return false;
}

bool SkillStruckVineWhip(bool onAttacker)
{
    return false;
}

bool SkillStruckVirulentBite(bool onAttacker)
{
    return false;
}

bool SkillStruckVoidRift(bool onAttacker)
{
    return false;
}

bool SkillStruckVolcanicOutburst(bool onAttacker)
{
    return false;
}

bool SkillStruckWail(bool onAttacker)
{
    return false;
}

bool SkillStruckWarpPulse(bool onAttacker)
{
    return false;
}

bool SkillStruckWaterWhip(bool onAttacker)
{
    return false;
}

bool SkillStruckWhirlpool(bool onAttacker)
{
    return false;
}

bool SkillStruckWildfire(bool onAttacker)
{
    return false;
}

bool SkillStruckWildMagic(bool onAttacker)
{
    return false;
}

bool SkillStruckWingBuffet(bool onAttacker)
{
    return false;
}

bool SkillStruckWither(bool onAttacker)
{
    return false;
}

bool SkillStruckWorldTear(bool onAttacker)
{
    return false;
}

bool SkillStruckWyrmCharge(bool onAttacker)
{
    CommonStruckAnimation(onAttacker);
    return false;
}
