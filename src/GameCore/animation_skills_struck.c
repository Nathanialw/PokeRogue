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
void CommonStruckAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);

    uint8_t l = BATTLER_OFFSET / 2;

    MoveCenterToRight(graphics, hardware, r, l, 2);
    MoveRightToCenter(graphics, hardware, r, l, 2);
    MoveCenterToLeft(graphics, hardware, r, l, 2);
    MoveLeftToCenter(graphics, hardware, r, l, 2);
    MoveCenterToRight(graphics, hardware, r, l, 4);
    MoveRightToCenter(graphics, hardware, r, l, 4);
    MoveCenterToLeft(graphics, hardware, r, l, 4);
    MoveLeftToCenter(graphics, hardware, r, l, 4);
}

/************************************************************************************************************
 *  Draws random 4px x 4px squares on the battler of the given colour
 ************************************************************************************************************/
void SparkleStruckAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker, uint8_t palletIndex)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);
    AnimationRandomParticles(graphics, hardware, memory, r, BATTLER_OFFSET, 64, palletIndex, 32);
    RefreshBattler(graphics, memory, onAttacker, r);
}


/************************************************************************************************************
 *
 *      Implementations
 *
 ************************************************************************************************************/

/************************************************************************************************************
 *
 ************************************************************************************************************/
bool SkillStruckAbyssalGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAcidSpray(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_EMERALD_GREEN);
    return false;
}

bool SkillStruckAmbushStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckAncientGuard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAncientWisdom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAncientWrath(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAnomaly(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAntidote(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckApotheosis(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAquaJet(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckArcaneEruption(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckArcticWinds(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAshCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAstralChains(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckAuraOfReverence(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckBedrockShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBlazingCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBlessing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBlizzard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBloodScent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBloom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBodySlam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckBoneSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBoulderCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBoulderToss(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBrambleTrap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckBrineSpray(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCallOfTheVoid(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCanopyShade(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCatastrophe(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCavitation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCelestialCall(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckChannelDivinity(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckChaosWhisper(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckCinderStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckColdSnap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckColossalCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCombustion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckConsume(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckContagion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCorrupt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCorruptingTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCosmicRay(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCripplingBlow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckCryoBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckCursedEmbrace(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckCursedGround(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDarkRitual(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDeathsDoor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDeepCurrent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDemonicPact(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDiabolicCry(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDisarm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDissonance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDivineIntervention(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDivineSmite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDraconicFury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDragonBreath(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDreamDust(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckDrowningGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEarthenPrison(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEarthquake(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEarthquakeStomp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEldritchBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_PURPLE_BLUE);
    return true;
}

bool SkillStruckEmber(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEmberRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEnchantingMelody(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEpitaph(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckEternalGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckExorcism(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFaerieFire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFaeWhisper(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFearRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFelblaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFeralRage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFireball(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFlameBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_BRIGHT_ORANGE);
    return true;
}

bool SkillStruckFlamePunch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFlare(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFlyby(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckForestWard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFossilize(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFreeze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFrostBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFrostNova(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckFrozenOrb(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGeoBarrier(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGlacialSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGladeTeleport(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGlamour(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGoldenInstinct(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGraveTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGravityRoot(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGroundPound(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckGuardBreak(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckHailstorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHaloOfGrace(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHaunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHellfire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHellscape(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHolyLight(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHowlOfThePack(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHuntingInstinct(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckHydroBlast(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    SparkleStruckAnimation(graphics, hardware, memory, onAttacker, PAL_BRIGHT_CYAN);
    return true;
}

bool SkillStruckHypervision(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIceArmor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIceLance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIceShard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIncinerate(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckInfectiousTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckInfernalRush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckInferno(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIronGrip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckIronWill(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckJudgement(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckKiss(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLandslide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLandShift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLavaBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLeafStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLifeDrain(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLuminaBlessing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckLunge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckLustfulGlare(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMaddeningGaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMaelstrom(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMagmaBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMagmaFlow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMightyThrow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMindSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMiracle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMirrorGlamour(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMoonbeam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMountainBreaker(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMudClaw(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMudSlide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckMysticTangle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckNecroticBurst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckNerveStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckNeurotoxin(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckOvergrowth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPackCall(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckParalyze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckParry(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPermafrost(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPetalBlitz(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPetalDance(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPetrifyingGaze(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPetrifyingTouch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPhantomGrasp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPixieDust(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPlague(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckToxicFang(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckToxicIvy(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckToxicMist(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPolarVortex(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPollenCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPounce(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckPrayer(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPreciseStrike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckPredatorFocus(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPressureCrush(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPrimalScream(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPrimordialForce(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPsychicShock(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPurify(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPurifyCure(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckPyre(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckQuicksand(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRaiseMinion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRally(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRealitySlip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRighteousFury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRiptide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRipAndTear(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRockThrow(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckRootAnchor(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckRunicAegis(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSacredShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSacrifice(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSanityBreak(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSavageMaul(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckScalesHarden(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckScaleStorm(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckScorch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckScratch(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckSecondWind(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSeedVolley(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSeismicSlam(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSeraphicWard(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckShellbreaker(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckShieldBash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckSkyDive(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSlash(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSleepOfAges(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSnowBlind(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSoulSiphon(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSporeExplosion(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckStalk(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckStarSprinkle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSting(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckStomp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}

bool SkillStruckStoneSkin(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckStoneSpike(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckStoneTide(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSultryLook(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSunfury(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckSurge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTackle(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    Rect_16 r = GetBattlerRect(onAttacker);
    RefreshBattler(graphics, memory, onAttacker, r);
    uint8_t l = BATTLER_OFFSET / 2;

    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return true;
}

bool SkillStruckTacticalRetreat(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTailSweep(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTailWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTaunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTemporalShift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTemptation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTerraform(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTerrifyingRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckThornBarrage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckThoughtLeech(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckThroatClamp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTidalWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTimeWarp(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTitanicRoar(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTitanSwing(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTombShield(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTorrent(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckToxicBarrage(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckToxicCloud(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTreasureHunt(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTremorStep(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTremorWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTricksterTreat(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckTwilightShimmer(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVampiricWave(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVenomousTail(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVenomSpit(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVerdantGrowth(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckViciousBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVineWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVirulentBite(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVoidRift(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckVolcanicOutburst(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWail(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWarpPulse(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWaterWhip(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWhirlpool(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWildfire(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWildMagic(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWingBuffet(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWither(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWorldTear(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    return false;
}

bool SkillStruckWyrmCharge(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker)
{
    CommonStruckAnimation(graphics, hardware, memory, onAttacker);
    return false;
}
