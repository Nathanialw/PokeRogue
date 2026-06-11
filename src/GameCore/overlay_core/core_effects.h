//
// Created by nathanial on 3/29/26.
//
#pragma once
#include "types.h"


/**********************************************************************************************************************/
/*
 *  All effects for items, objects, skills and spells are stored here as functions
*   Effect Functions make it easy to mix and match any effects to build unique actions
*
**********************************************************************************************************************/

/**********************************************************************************************************************/
/** ACCESSIBLE FOR TESTING
**********************************************************************************************************************/
#ifdef ENABLE_DEBUG_OUTPUT
uint16_t CalcModifier(MemoryInterface memory, EntityId attackerID, EntityId defenderID, Type attackType, uint16_t damage);
uint16_t CalcDamage(EntityId creatureID, uint16_t abilityPower);
uint16_t CalcHeal(EntityId creatureID, uint16_t abilityPower);
#endif

ActionOutcome NoEffect();

/**********************************************************************************************************************/
/** DAMAGE EFFECTS
**********************************************************************************************************************/
void Attack(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData);
void InstantKill(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData);
ActionOutcome QuickAttack(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData);
ActionOutcome Parry(EntityId attackerID, EntityId defenderID, SkillData abilityData);
ActionOutcome Summon(CreatureID creature);
ActionOutcome SacrificeHeal(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData);
void DoDamage(EntityId creatureID, uint16_t damage);

/**********************************************************************************************************************/
/** RESOURCE EFFECTS
**********************************************************************************************************************/
ActionOutcome Revive(EntityId e_id);
ActionOutcome MakeInvulnerable(EntityId e_id);
ActionOutcome HealTarget(EntityId e_id, uint16_t value);
ActionOutcome RestoreMana(EntityId e_id, uint8_t value);
ActionOutcome DrainMana(EntityId e_id, uint8_t value);
ActionOutcome RestorePP(EntityId trainer_id, uint8_t spell_index, uint8_t value);

/**********************************************************************************************************************/
/** STATUS EFFECTS
**********************************************************************************************************************/
ActionOutcome ApplyPoison(EntityId e_id, uint8_t duration);
ActionOutcome ApplyCurse(EntityId e_id, uint8_t duration);
ActionOutcome ApplyDisease(EntityId e_id, uint8_t duration);
ActionOutcome ApplyParalyze(EntityId e_id, uint8_t duration);
ActionOutcome ApplySleep(EntityId e_id, uint8_t duration);
ActionOutcome ApplyFrozen(EntityId e_id, uint8_t duration);
ActionOutcome ApplyFear(EntityId e_id, uint8_t duration);
ActionOutcome ApplyBurn(EntityId e_id, uint8_t duration);
ActionOutcome ApplySlow(EntityId e_id, uint8_t duration);
ActionOutcome ApplyHaste(EntityId e_id, uint8_t duration);
ActionOutcome RemovePoison(EntityId e_id);
ActionOutcome RemoveCurse(EntityId e_id);
ActionOutcome RemoveDisease(EntityId e_id);
ActionOutcome RemoveParalyze(EntityId e_id);
ActionOutcome RemoveSleep(EntityId e_id);
ActionOutcome RemoveFrozen(EntityId e_id);
ActionOutcome RemoveFear(EntityId e_id);
ActionOutcome RemoveBurn(EntityId e_id);
ActionOutcome RemoveSlow(EntityId e_id);
ActionOutcome RemoveHaste(EntityId e_id);
ActionOutcome NextAttackFreezes();
ActionOutcome FreezeAttackers(EntityId e_id, uint8_t duration);
ActionOutcome PersistentPoisonCloud(uint8_t duration);

/**********************************************************************************************************************/
/** RESISTANCES
**********************************************************************************************************************/
ActionOutcome RaiseAcidResistance(EntityId e_id);
ActionOutcome RaiseFireResistance(EntityId e_id);
ActionOutcome RaiseWaterResistance(EntityId e_id);
ActionOutcome RaiseIceResistance(EntityId e_id);
ActionOutcome RaiseMagicResistance(EntityId e_id);
ActionOutcome RaiseAllResistance(EntityId e_id);
ActionOutcome LowerAcidResistance(EntityId e_id);
ActionOutcome LowerFireResistance(EntityId e_id);
ActionOutcome LowerWaterResistance(EntityId e_id);
ActionOutcome LowerIceResistance(EntityId e_id);
ActionOutcome LowerMagicResistance(EntityId e_id);
ActionOutcome FireEating(EntityId e_id);
ActionOutcome WaterEating(EntityId e_id);
ActionOutcome IceEating(EntityId e_id);
ActionOutcome AcidEating(EntityId e_id);
ActionOutcome LavaEating(EntityId e_id);


/**********************************************************************************************************************/
/** CREATURE STATS
**********************************************************************************************************************/
ActionOutcome LowerAccuracy(EntityId e_id);
ActionOutcome RaiseAccuracy(EntityId e_id);
ActionOutcome RaiseStrength(EntityId e_id);
ActionOutcome RaiseDefence(EntityId e_id);
ActionOutcome RaiseMagic(EntityId e_id);
ActionOutcome RaiseSpeed(EntityId e_id);
ActionOutcome LowerSpeed(EntityId e_id);
ActionOutcome LowerDefence(EntityId e_id);
ActionOutcome LowerMagic(EntityId e_id);
ActionOutcome LowerStrength(EntityId e_id);
ActionOutcome RaiseBaseStrength(EntityId e_id);
ActionOutcome RaiseBaseDefence(EntityId e_id);
ActionOutcome RaiseBaseMagic(EntityId e_id);
ActionOutcome RaiseBaseSpeed(EntityId e_id);
ActionOutcome LowerBaseSpeed(EntityId e_id);
ActionOutcome LowerBaseDefence(EntityId e_id);
ActionOutcome LowerBaseMagic(EntityId e_id);
ActionOutcome LowerBaseStrength(EntityId e_id);
ActionOutcome DrainXP(EntityId e_id);
ActionOutcome ResetTemporaryStatsMods(EntityId e_id);
ActionOutcome LevelUpRetainProgress(EntityId target_id);

/**********************************************************************************************************************/
/** PLAYER
**********************************************************************************************************************/
ActionOutcome DiscoverItem(EntityId e_id);
ActionOutcome DiscoverCreature(EntityId e_id);
ActionOutcome DiscoverObject(EntityId e_id);
ActionOutcome DiscoverSpell(Spell spell_id);
ActionOutcome DiscoverSkill(Ability ability_id);
ActionOutcome LearnSpell(MemoryInterface memory, EntityId e_id, Spell spell_id);
ActionOutcome TeachSkill(EntityId creature_id, SpellId spell_id);
ActionOutcome Capture(HardwareInterface hardware, EntityId trainer_id, EntityId target_id, uint8_t successChance);
ActionOutcome AbandonTeam(EntityId e_id);
ActionOutcome Flee();
ActionOutcome DestroyPlayerItem(EntityId item_id);
ActionOutcome DestroyRandomPlayerItem();

/**********************************************************************************************************************/
/** MAP EFFECTS
**********************************************************************************************************************/
ActionOutcome Repel(EntityId e_id, uint8_t duration);
ActionOutcome Hover(EntityId e_id, uint8_t duration);
ActionOutcome Invisibility(EntityId e_id, uint8_t duration);

ActionOutcome StatusGreaterLight(EntityId e_id, uint8_t duration);
ActionOutcome StatusLesserLight(EntityId e_id, uint8_t duration);

ActionOutcome WaterWalking(EntityId e_id, uint8_t duration);
ActionOutcome WallWalking(EntityId e_id, uint8_t duration);
ActionOutcome WaterBreathing(EntityId e_id, uint8_t duration);
ActionOutcome XRayVision(EntityId e_id, uint8_t duration);
ActionOutcome CreateItem(HardwareInterface hardware, MemoryInterface memory, ObjectsTypes type, uint8_t t, uint8_t x, uint8_t y, uint8_t l);
ActionOutcome CreateItemFood(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l);
ActionOutcome CreateItemCommon(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l);
ActionOutcome CreateItemMagic(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l);
ActionOutcome MapModifyTile(Position, MapTile tileType);
ActionOutcome RemoveMapFog();
ActionOutcome GoNextLevel(MapLevelChange dir);