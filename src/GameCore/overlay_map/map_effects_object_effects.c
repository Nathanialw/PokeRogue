//
// Created by nathanial on 6/22/26.
//

#include "core_effects.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "enums.h"
#include "types.h"

#include "core_stats.h"

#include "map_effects.h"


SET_MEMORY(".map")
ActionOutcome EffectAbandonTrainer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDamage(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    DamageCreature(creature_id, 1, CREATURE);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyBerserk(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyBerserk(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyBleed(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyBleed(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyBlind(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyBlind(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyBurn(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyBurn(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyCurse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyCurse(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyDisarm(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyDisarm(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyDisease(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyDisease(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyEnfeeble(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyEnfeeble(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyFear(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyFear(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyFireEating(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyFireEating(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyFlying(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyFrozen(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyFrozen(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyHaste(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyInvigorate(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyInvisible(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyLifelink(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyMagicShield(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyParalyze(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyParalyze(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyPetrify(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyPetrify(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyPoison(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyPoison(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyReflect(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyRegeneration(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyRevitalize(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyRoot(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplyRoot(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplySap(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplySap(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplySleep(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplySleep(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplySlow(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    ApplySlow(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplySpellPower(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyStoneSkin(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyThorns(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyVampiricAura(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectApplyWarded(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************/
/*  TODO not sure yet what to do with this, maybe require a nearby monster
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome EffectCaptureCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateItemBook(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateItemCommon(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateItemMagic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateItemPotion(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateItemScroll(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectInstakill(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDestroyCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverItem(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverObject(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverSkill(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverSpell(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDiscoverTrainer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainBagSlot(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    GainBagSlot(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainLevelCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainLevelTrainer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainXPTrainer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerAccuracy(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerAccuracy(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerAgility(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerAgility(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerAttack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerAttack(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerDefense(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerDefence(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerDexterity(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerDexterity(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerFortitude(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerFortitude(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerIntelligence(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerIntelligence(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerLoyalty(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerLoyalty(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerMagic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerMagic(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerMaxHP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerMaxHP(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerMaxMP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerMaxMP(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerMaxPP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerMaxPP(creature_id, 1, index);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistEarth(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerEarthResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistFire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerFireResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistIce(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerIceResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistMagic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerMagicResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistToxic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerAcidResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerResistWater(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerSpeed(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerSpeed(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerStamina(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerStamina(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerStrength(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerStrength(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerXPCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerCurrentCreatureXP(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectMeltItemRandom(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectNoObjectEffect(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectLowerXPTrainer(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    LowerCurrentTrainerXP(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainXPCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    GainXP(creature_id, 1, CREATURE);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseAccuracy(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseAgility(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseAttack(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseAttack(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseDefense(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseDefence(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseDexterity(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseDexterity(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseFortitude(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseIntelligence(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseLoyalty(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseLoyalty(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseMagic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseMagic(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistEarth(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseEarthResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistFire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseFireResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistIce(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseIceResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistMagic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseMagicResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistToxic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseAcidResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseResistWater(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseWaterResistance(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseSpeed(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseSpeed(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseStamina(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseStamina(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRaiseStrength(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RaiseStrength(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveBerserk(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveBleed(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveBlind(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveBurn(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveCurse(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveDisarm(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveDisease(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveEnfeeble(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveFear(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveFireEating(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveFlying(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveFrozen(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveHaste(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveInvigorate(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveInvisible(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveLifelink(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveMagicShield(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveParalyze(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemovePetrify(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemovePoison(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveReflect(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveRegeneration(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveRevitalize(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveRoot(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveSap(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveSleep(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveSlow(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveSpellPower(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveStoneSkin(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveThorns(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveVampiricAura(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRemoveWarded(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRestoreHP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    HealTarget(creature_id, 1);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRestoreMP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RestoreMana(creature_id, 1);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRestorePP(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RestorePP(creature_id, 1, index);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectRevive(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectSacrificeCreatureRepeatable(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SacrificeCreature(hardware, trainer_id, creature_id, 60);
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectSacrificeCreatureOnce(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    //check if the creature has already been sacrificed
    SacrificeCreature(hardware, trainer_id, creature_id, 120);
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectGainSpellPage(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}


SET_MEMORY(".map")
ActionOutcome EffectStatueWizard(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectAscendLevel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateCopper(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateCrystal(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateGold(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateIron(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateSilver(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectCreateTin(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectDescendLevel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return MapDescend(hardware, memory, trainer_id);
}

SET_MEMORY(".map")
ActionOutcome EffectDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return Reposition(hardware, trainer_id);
}

SET_MEMORY(".map")
ActionOutcome EffectLateralLevel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return MapLateral(hardware, memory, trainer_id);
}

SET_MEMORY(".map")
ActionOutcome EffectRaisePietyCatholic(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectRest(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectShowMap(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    RevealMap();
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonAngel(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, ANGEL);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonDemon(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, DEMON);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonHag(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, GetRandomHag(hardware));;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonLeprechaun(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, LEPRECHAUN);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonSkeleton(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, SKELETON);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonUndead(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    CreatureID creature_type = GetRandomUndead(hardware);
    SummonCreature(hardware, memory, trainer_id, creature_type);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonZombie(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, ZOMBIE);;
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectSmeltOre(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectStartFire(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectSummonOoze(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    SummonCreature(hardware, memory, trainer_id, OOZE);
    return ACTION_SUCCEEDED;
}

SET_MEMORY(".map")
ActionOutcome EffectJanusPillar(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectKeystoneArchway(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectSigilHexagram(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_FAILED;
}

SET_MEMORY(".map")
ActionOutcome EffectBreak(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId trainer_id, EntityId creature_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index)
{
    return ACTION_SUCCEEDED;
}
