//
// Created by nathanial on 3/29/26.
//

#include "core_effects.h"

#include "lib_debugging.h"
#include "lib_memory.h"

#include "constants.h"
#include "enums.h"

#include "core_utils.h"
#include "core_entities.h"
#include "core_map.h"
#include "core_ram.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_stats.h"


/**********************************************************************************************************************
*
 *  util functions
 *
**********************************************************************************************************************/
/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RestoreResource(uint_max999* resource, EntityId creature_id, uint8_t value)
{
    if (creature_id == NO_CREATURE) return ACTION_CANNOT;
    uint_max999 res = resource[creature_id];
    uint16_t cur = Int999GetCurrent(&res);
    uint16_t max = Int999GetMax(&res);
    if (cur == max) return ACTION_CANNOT;
    cur = (cur + value > max) ? max : cur + value;
    Int999SetCurrent(&res, cur);
    resource[creature_id] = res;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint16_t CalcDamage(EntityId creatureID, uint16_t abilityPower)
{
    const uint8_t level = g_core.creatures.level[creatureID].value;
    const uint16_t base = g_core.creatures.stats[creatureID].attack >> 2;
    const uint16_t accuracy = g_core.creatures.stats[creatureID].accuracy >> 2;
    const uint16_t skill = (abilityPower + g_core.creatures.attributes[creatureID].intelligence) >> 3;
    const uint16_t mod = g_core.creatures.attributes[creatureID].strength >> 3;

    uint16_t damage = level + base + skill + mod;
    DEBUG("CalcDamage %d %d %d %d - total %d", level, base, skill, mod, damage);
    if (damage == 0) damage = 1;
    return damage;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
uint16_t CalcHeal(EntityId creatureID, uint16_t abilityPower)
{
    uint16_t damage = g_core.creatures.stats[creatureID].magic + abilityPower;
    if (damage == 0) damage = 1;
    return damage;
}


/********************************************************************************************************************************************************************************************************************************************
*
********************************************************************************************************************************************************************************************************************************************/
SET_MEMORY(".core")
void DoDamage(EntityId creatureID, uint16_t damage)
{
    uint16_t hp = Int999GetCurrent(&g_core.creatures.hp[creatureID]);
    hp = (hp > damage) ? hp - damage : 0;
    Int999SetCurrent(&g_core.creatures.hp[creatureID], hp);
}

/**********************************************************************************************************************
*  Apply the bonus damage of same type attack
*  Apply the bonus/reduction of attack vs creature types
 *  Apply the damage reduction from defence
**********************************************************************************************************************/
SET_MEMORY(".core")
uint16_t CalcModifier(MemoryInterface memory, EntityId attackerID, EntityId defenderID, Type attackType, uint16_t input_damage)
{
    Creature creature_type1 = GetCreatureType(attackerID);
    MonsterType m_type;
    Flash_GetType(memory, &m_type, creature_type1);
    Type attacker_typeA = m_type.typeA;
    Type attacker_typeB = m_type.typeB;

    uint16_t output_damage = input_damage; //input damage already capped at 999
    if (attacker_typeA == attackType || attacker_typeB == attackType)
        output_damage = input_damage << 1;

    CreatureID target_creature_id = GetCreatureType(defenderID);
    uint8_t base = g_core.creatures.stats[defenderID].defence >> 1; //max 255
    uint8_t mod = g_core.creatures.attributes[defenderID].fortitude; //max 255
    uint16_t damage_reduction = base + mod;

    MonsterType m_type2;
    Flash_GetType(memory, &m_type2, target_creature_id);
    Type defender_typeA = m_type2.typeA;
    Type defender_typeB = m_type2.typeB;

    int8_t mult_a = 0;
    Flash_GetTypeEffects(memory, &mult_a, (attackType * TYPE_COUNT) + defender_typeA);
    int8_t mult_b = 0;
    Flash_GetTypeEffects(memory, &mult_b, (attackType * TYPE_COUNT) + defender_typeB);
    int32_t effectiveness = 200 + mult_a + mult_b;
    ASSERT(effectiveness >= 0, "effectiveness cannot be less than zero, probable data corruption, attack type: %d - defender types: %d %d", attackType, defender_typeA, defender_typeB);
    uint16_t raw_damage = (uint16_t)(((uint32_t)output_damage * effectiveness) / 200);


    if (damage_reduction > raw_damage)
        output_damage = 1; //immunities are handled elsewhere
    else
        output_damage = raw_damage - damage_reduction;

    DEBUG("CalcModifier %d%% - raw with mods: %u after reduction: %u", effectiveness - 200, raw_damage, output_damage);
    if (output_damage == 0) output_damage = 1;
    return output_damage;
}

/**********************************************************************************************************************
*
 *      MIx and match these EFFECTS to create item, spell, skill and object interaction effects
 *
**********************************************************************************************************************/
SET_MEMORY(".core")
bool IncreaseValue(uint16_t* n, uint16_t value, uint16_t max)
{
    if (*n == max) return false;
    if (value == 0) return false;

    const uint16_t temp = *n + value;
    if (temp < max)
        *n += value;
    else
        *n = max;

    return true;
}

// SET_MEMORY(".core")
// bool DecreaseValue(uint16_t *n, uint16_t value)
// {
//     if (*n == 0) return false;
//     if (value == 0) return false;
//
//     if (*n > value)
//         *n -= value;
//     else
//         *n = 0;
//
//     return true;
// }


SET_MEMORY(".core")
uint16_t IncreaseValue_999(uint16_t n, uint16_t value)
{
    if (n == 999) return n;
    if (value == 0) return n;


    const uint16_t temp = n + value;
    if (temp < 999)
        n += value;
    else
        n = 999;

    return n;
}

SET_MEMORY(".core")
uint16_t DecreaseValue(uint16_t n, uint16_t value)
{
    if (n == 0) return n;
    if (value == 0) return n;

    if (n > value)
        n -= value;
    else
        n = 0;

    return n;
}


SET_MEMORY(".core")
bool IncreaseValue_255(uint8_t* n, uint8_t value)
{
    if (*n == 255) return false;
    if (value == 0) return false;


    const uint16_t temp = (uint16_t)*n + (uint16_t)value;
    if (temp < 255)
        *n += value;
    else
        *n = 255;

    return true;
}


SET_MEMORY(".core")
bool IncreaseValue_int99(int99* n, uint8_t value)
{
    if (*n == 99) return false;
    if (value == 0) return false;


    const int16_t temp = *n + value;
    if (temp < 99)
        *n += value;
    else
        *n = 99;

    return true;
}

SET_MEMORY(".core")
bool DecreaseValue_int99(int99* n, uint8_t value)
{
    if (*n == -99) return false;
    if (value == 0) return false;

    const int16_t temp = *n - value;
    if (temp > -99) // clamp to the real minimum -99
        *n -= value;
    else
        *n = -99;

    return true;
}


SET_MEMORY(".core")
bool IncreaseValue_uint99(uint99* n, uint8_t value)
{
    if (n->value == 99) return false;
    if (value == 0) return false;


    const uint16_t temp = n->value + (uint16_t)value;
    if (temp < 99)
        n->value += value;
    else
        n->value = 99;

    return true;
}

SET_MEMORY(".core")
bool DecreaseValue_99(uint99* n, uint8_t value)
{
    if (n->value == 0) return false;
    if (value == 0) return false;

    if (n->value > value)
        n->value -= value;
    else
        n->value = 0;

    return true;
}


SET_MEMORY(".core")
bool IncreaseValue_IntMax999(uint_max999* n, uint8_t value)
{
    uint16_t cur = Int999GetCurrent(n);
    uint16_t max = Int999GetMax(n);
    if (cur == max) return false;
    if (value == 0) return false;


    const uint16_t temp = cur + (uint16_t)value;
    if (temp < max)
        cur += value;
    else
        cur = 99;

    Int999SetCurrent(n, cur);
    return true;
}

SET_MEMORY(".core")
bool DecreaseValue_IntMax999(uint_max999* n, uint8_t value)
{
    uint16_t cur = Int999GetCurrent(n);
    if (cur == 0) return false;
    if (value == 0) return false;

    if (cur > value)
        cur -= value;
    else
        cur = 0;

    Int999SetCurrent(n, cur);
    return true;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome NoEffect()
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
void Attack(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    uint16_t damage = CalcDamage(attackerID, abilityData.power);
    damage = CalcModifier(memory, attackerID, defenderID, abilityData.type, damage);
    DoDamage(defenderID, damage);
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
void InstantKill(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    uint16_t damage = CalcDamage(attackerID, 999);
    damage = CalcModifier(memory, attackerID, defenderID, abilityData.type, damage);
    DoDamage(defenderID, damage);
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome QuickAttack(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TODO: always attack first
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Parry(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TODO:
    return ACTION_FAILED;
}

/********************************************************************************************************************************************************************************************************************************************
*
*   MONSTER EFFECTS
*
********************************************************************************************************************************************************************************************************************************************/


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome HealTarget(EntityId e_id, uint16_t value)
{
    uint16_t heal = CalcHeal(e_id, value);
    return RestoreResource(g_core.creatures.hp, e_id, heal);
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Revive(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome MakeInvulnerable(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RestoreMana(EntityId e_id, uint8_t value)
{
    return RestoreResource(g_core.creatures.mp, e_id, value);
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DrainMana(EntityId e_id, uint8_t value)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RestorePP(EntityId trainer_id, uint8_t spell_index, uint8_t value)
{
    if (g_core.trainers.spellbook[trainer_id].page[spell_index].pp < value)
    {
        g_core.trainers.spellbook[trainer_id].page[spell_index].pp = g_core.trainers.spellbook[trainer_id].page[spell_index].spellData.pp;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMaxPP(EntityId trainer_id, uint8_t spell_index, uint8_t value)
{
    if (g_core.trainers.spellbook[trainer_id].page[spell_index].spellData.pp < MAX_PP)
    {
        g_core.trainers.spellbook[trainer_id].page[spell_index].spellData.pp += value;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Repel(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].repel;
    g_core.trainers.buffs[e_id].repel = DecrementStatusEffect(g_core.trainers.buffs[e_id].repel, e_id);
    if (cur != g_core.trainers.buffs[e_id].repel)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Hover(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].hovering;
    g_core.trainers.buffs[e_id].hovering = DecrementStatusEffect(g_core.trainers.buffs[e_id].hovering, e_id);
    if (cur != g_core.trainers.buffs[e_id].hovering)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterBreathing(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].water_breathing;
    g_core.trainers.buffs[e_id].water_breathing = DecrementStatusEffect(g_core.trainers.buffs[e_id].water_breathing, e_id);
    if (cur != g_core.trainers.buffs[e_id].water_breathing)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome XRayVision(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].line_of_sight;
    g_core.trainers.buffs[e_id].line_of_sight = DecrementStatusEffect(g_core.trainers.buffs[e_id].line_of_sight, e_id);
    if (cur != g_core.trainers.buffs[e_id].line_of_sight)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterWalking(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].water_walk;
    g_core.trainers.buffs[e_id].water_walk = DecrementStatusEffect(g_core.trainers.buffs[e_id].water_walk, e_id);
    if (cur != g_core.trainers.buffs[e_id].water_walk)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WallWalking(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].wall_walking;
    g_core.trainers.buffs[e_id].wall_walking = DecrementStatusEffect(g_core.trainers.buffs[e_id].wall_walking, e_id);
    if (cur != g_core.trainers.buffs[e_id].wall_walking)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Invisibility(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].invisibility;
    g_core.trainers.buffs[e_id].invisibility = DecrementStatusEffect(g_core.trainers.buffs[e_id].invisibility, e_id);
    if (cur != g_core.trainers.buffs[e_id].invisibility)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Summon(CreatureID creature)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
ActionOutcome SacrificeHeal(HardwareInterface hardware, MemoryInterface memory, EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    Attack(hardware, memory, attackerID, defenderID, abilityData);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
ActionOutcome DestroyPlayerItem(EntityId item_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
ActionOutcome DestroyRandomPlayerItem()
{
    return ACTION_FAILED;
}

/********************************************************************************************************************************************************************************************************************************************
*
*
*     PLAYER ONLY
*
*
********************************************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Capture(HardwareInterface hardware, EntityId trainer_id, EntityId target_id, uint8_t successChance)
{
    if (target_id == g_core.trainers.partyID[GetPlayerID()][0])
        return ACTION_CANNOT;

    uint8_t n = hardware.GetRandom_uint8_t(1, successChance);
    DEBUG("capture %d/%d", n, successChance);
    if (n < 100)
    {
        if (AddCreatureToParty(trainer_id, target_id))
        {
            g_core.trainers.currentPartySize[trainer_id]++;
            CaptureMonster(target_id);
            return ACTION_SUCCEEDED;
        }
        return ACTION_CANNOT; //party full
    }
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*  Sets the flag for the Creature id as discovered for the podedex use
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DiscoverCreature(EntityId e_id)
{
    SetBit(g_core.player.knownCreatures, GetCreatureType(e_id), 1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  Sets the flag for the Item id as discovered for the podedex use
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DiscoverItem(EntityId e_id)
{
    SetBit(g_core.player.knownItems, GetItemType(e_id), 1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  Sets the flag for the skill id as discovered for the podedex use
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DiscoverSkill(Ability ability_id)
{
    SetBit(g_core.player.knownAbilities, ability_id, 1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  Sets the flag for the Spell id as discovered for the podedex use
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DiscoverSpell(Spell spell_id)
{
    SetBit(g_core.player.knownSpells, spell_id, 1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  Sets the flag for the Object id as discovered for the podedex use
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DiscoverObject(EntityId e_id)
{
    SetBit(g_core.player.knownObjects, GetItemType(e_id), 1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome GainSpellbookPages(EntityId trainer_id, uint8_t pages)
{
    if (trainer_id == NO_ENTITY) return ACTION_CANNOT;
    if (trainer_id == NO_ENTITY) return ACTION_CANNOT;

    uint8_t temp = g_core.trainers.spellbook[trainer_id].current_max_pages + pages;
    if (temp < MAX_SPELLBOOK_SIZE)
    {
        g_core.trainers.spellbook[trainer_id].current_max_pages += pages;
        return ACTION_SUCCEEDED;
    }

    if (g_core.trainers.spellbook[trainer_id].current_max_pages < MAX_SPELLBOOK_SIZE)
    {
        g_core.trainers.spellbook[trainer_id].current_max_pages = MAX_SPELLBOOK_SIZE;
        return ACTION_SUCCEEDED;
    }


    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  Checks whether the given entity ID can learn the spell
 *  ON SUCCESS - return true
 *  ON FAIL - return fail
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome TeachSkill(EntityId creature_id, SpellId spell_id)
{
    if (creature_id == NO_ENTITY) return ACTION_CANNOT;

    uint8_t skill_slot = 0;
    while (skill_slot < MAX_ABILITIES)
    {
        if (g_core.creatures.attacks[creature_id][skill_slot] == NO_ABILITY)
            break;

        skill_slot++;
    }

    if (skill_slot < MAX_ABILITIES)
    {
        g_core.creatures.attacks[creature_id][skill_slot] = spell_id;
        return ACTION_SUCCEEDED;
    }

    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*  Checks whether the player entity ID can learn the spell
 *  ON SUCCESS - return true
 *  ON FAIL - return fail
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LearnSpell(MemoryInterface memory, EntityId e_id, Spell spell_id)
{
    if (spell_id == NO_SPELL) return ACTION_CANNOT;;
    if (e_id == NO_ENTITY) return ACTION_CANNOT;

    int8_t spell_book_index = -1;
    for (uint8_t i = 0; i < g_core.trainers.spellbook[e_id].current_max_pages; i++)
    {
        if (g_core.trainers.spellbook[e_id].spell_id[i] == NO_SPELL)
        {
            spell_book_index = i;
            break;
        }
    }

    if (spell_book_index == -1) return ACTION_CANNOT;

    AddSpellPage(memory, e_id, spell_id, spell_book_index);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*  Creature leaves the team to an adjacent cell on the map
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbandonTeam(EntityId e_id)
{
    return ACTION_FAILED;
}

/********************************************************************************************************************************************************************************************************************************************
*
*
*      DEBUFF MANAGEMENT
*
*
********************************************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyPoison(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].poison;
    g_core.creatures.debuffs[e_id].poison = IncrementStatusEffect(g_core.creatures.debuffs[e_id].poison, e_id);
    if (cur != g_core.creatures.debuffs[e_id].poison)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyCurse(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].curse;
    g_core.creatures.debuffs[e_id].curse = IncrementStatusEffect(g_core.creatures.debuffs[e_id].curse, e_id);
    if (cur != g_core.creatures.debuffs[e_id].curse)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyParalyze(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].paralyzed;
    g_core.creatures.debuffs[e_id].paralyzed = IncrementStatusEffect(g_core.creatures.debuffs[e_id].paralyzed, e_id);
    if (cur != g_core.creatures.debuffs[e_id].paralyzed)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyDisease(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].disease;
    g_core.creatures.debuffs[e_id].disease = IncrementStatusEffect(g_core.creatures.debuffs[e_id].disease, e_id);
    if (cur != g_core.creatures.debuffs[e_id].disease)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplySleep(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].sleep;
    g_core.creatures.debuffs[e_id].sleep = IncrementStatusEffect(g_core.creatures.debuffs[e_id].sleep, e_id);
    if (cur != g_core.creatures.debuffs[e_id].sleep)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyFear(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].fear;
    g_core.creatures.debuffs[e_id].fear = IncrementStatusEffect(g_core.creatures.debuffs[e_id].fear, e_id);
    if (cur != g_core.creatures.debuffs[e_id].fear)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyFrozen(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].frozen;
    g_core.creatures.debuffs[e_id].frozen = IncrementStatusEffect(g_core.creatures.debuffs[e_id].frozen, e_id);
    if (cur != g_core.creatures.debuffs[e_id].frozen)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyBurn(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].burned;
    g_core.creatures.debuffs[e_id].burned = IncrementStatusEffect(g_core.creatures.debuffs[e_id].burned, e_id);
    if (cur != g_core.creatures.debuffs[e_id].burned)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyHaste(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.buffs[e_id].hasted;
    g_core.creatures.buffs[e_id].hasted = IncrementStatusEffect(g_core.creatures.buffs[e_id].hasted, e_id);
    if (cur != g_core.creatures.buffs[e_id].hasted)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplySlow(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].slowed;
    g_core.creatures.debuffs[e_id].slowed = IncrementStatusEffect(g_core.creatures.debuffs[e_id].slowed, e_id);
    if (cur != g_core.creatures.debuffs[e_id].slowed)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome debuffsLesserBlind(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].blind;
    g_core.creatures.debuffs[e_id].blind = DecrementStatusEffect(g_core.creatures.debuffs[e_id].blind, e_id);
    if (cur != g_core.creatures.debuffs[e_id].blind)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome debuffsGreaterBlind(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].blind;
    g_core.creatures.debuffs[e_id].blind = DecrementStatusEffect(g_core.creatures.debuffs[e_id].blind, e_id);
    if (cur != g_core.creatures.debuffs[e_id].blind)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemovePoison(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].poison;
    g_core.creatures.debuffs[e_id].poison = DecrementStatusEffect(g_core.creatures.debuffs[e_id].poison, e_id);
    if (cur != g_core.creatures.debuffs[e_id].poison)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveCurse(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].curse;
    g_core.creatures.debuffs[e_id].curse = DecrementStatusEffect(g_core.creatures.debuffs[e_id].curse, e_id);
    if (cur != g_core.creatures.debuffs[e_id].curse)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveParalyze(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].paralyzed;
    g_core.creatures.debuffs[e_id].paralyzed = DecrementStatusEffect(g_core.creatures.debuffs[e_id].paralyzed, e_id);
    if (cur != g_core.creatures.debuffs[e_id].paralyzed)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveDisease(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].disease;
    g_core.creatures.debuffs[e_id].disease = DecrementStatusEffect(g_core.creatures.debuffs[e_id].disease, e_id);
    if (cur != g_core.creatures.debuffs[e_id].disease)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveSleep(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].sleep;
    g_core.creatures.debuffs[e_id].sleep = DecrementStatusEffect(g_core.creatures.debuffs[e_id].sleep, e_id);
    if (cur != g_core.creatures.debuffs[e_id].sleep)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveFear(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].fear;
    g_core.creatures.debuffs[e_id].fear = DecrementStatusEffect(g_core.creatures.debuffs[e_id].fear, e_id);
    if (cur != g_core.creatures.debuffs[e_id].fear)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveFrozen(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].frozen;
    g_core.creatures.debuffs[e_id].frozen = DecrementStatusEffect(g_core.creatures.debuffs[e_id].frozen, e_id);
    if (cur != g_core.creatures.debuffs[e_id].frozen)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveBurn(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].burned;
    g_core.creatures.debuffs[e_id].burned = DecrementStatusEffect(g_core.creatures.debuffs[e_id].burned, e_id);
    if (cur != g_core.creatures.debuffs[e_id].burned)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveHaste(EntityId e_id)
{
    uint8_t cur = g_core.creatures.buffs[e_id].hasted;
    g_core.creatures.buffs[e_id].hasted = DecrementStatusEffect(g_core.creatures.buffs[e_id].hasted, e_id);
    if (cur != g_core.creatures.buffs[e_id].hasted)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveSlow(EntityId e_id)
{
    uint8_t cur = g_core.creatures.debuffs[e_id].slowed;
    g_core.creatures.debuffs[e_id].slowed = DecrementStatusEffect(g_core.creatures.debuffs[e_id].slowed, e_id);
    if (cur != g_core.creatures.debuffs[e_id].slowed)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusLesserLight(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].light;
    g_core.trainers.buffs[e_id].light = DecrementStatusEffect(g_core.trainers.buffs[e_id].light, e_id);
    if (cur != g_core.trainers.buffs[e_id].light)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusGreaterLight(EntityId e_id, uint8_t duration)
{
    uint8_t cur = g_core.trainers.buffs[e_id].light;
    g_core.trainers.buffs[e_id].light = DecrementStatusEffect(g_core.trainers.buffs[e_id].light, e_id);
    if (cur != g_core.trainers.buffs[e_id].light)
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*   TODO
**********************************************************************************************************************/
ActionOutcome NextAttackFreezes()
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome FreezeAttackers(EntityId e_id, uint8_t duration)
{
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*   TODO
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome PersistentPoisonCloud(uint8_t duration)
{
    return ACTION_CANNOT;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// RESISTANCES

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbEarth(EntityId e_id)
{
    g_core.creatures.absorb[e_id].earth = 1;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbToxic(EntityId e_id)
{
    g_core.creatures.absorb[e_id].toxic = 1;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbWater(EntityId e_id)
{
    g_core.creatures.absorb[e_id].earth = 1;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbIce(EntityId e_id)
{
    g_core.creatures.absorb[e_id].ice = 1;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbFire(EntityId e_id)
{
    g_core.creatures.absorb[e_id].fire = 1;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AbsorbMagic(EntityId e_id)
{
    g_core.creatures.absorb[e_id].magic = 1;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseEarthResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].earth, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAcidResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].toxic, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseFireResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].fire, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseWaterResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].water, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseIceResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].ice, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMagicResistance(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_int99(&g_core.creatures.resists[e_id].magic, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAllResistance(EntityId e_id, uint8_t value)
{
    ActionOutcome action_outcome = ACTION_FAILED;
    if (RaiseAcidResistance(e_id, value) ||
        RaiseEarthResistance(e_id, value) ||
        RaiseFireResistance(e_id, value) ||
        RaiseWaterResistance(e_id, value) ||
        RaiseIceResistance(e_id, value) ||
        RaiseMagicResistance(e_id, value))
    {
        action_outcome = ACTION_SUCCEEDED;
    };
    return action_outcome;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerEarthResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].earth, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAcidResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].toxic, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerFireResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].fire, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerWaterResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].water, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerIceResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].ice, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMagicResistance(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_int99(&g_core.creatures.resists[e_id].magic, value))
        return ACTION_SUCCEEDED;
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAllResistance(EntityId e_id, uint8_t value)
{
    ActionOutcome action_outcome = ACTION_FAILED;
    if (LowerAcidResistance(e_id, value) ||
        LowerEarthResistance(e_id, value) ||
        LowerFireResistance(e_id, value) ||
        LowerWaterResistance(e_id, value) ||
        LowerIceResistance(e_id, value) ||
        LowerMagicResistance(e_id, value))
    {
        action_outcome = ACTION_SUCCEEDED;
    };
    return action_outcome;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome FireEating(EntityId e_id)
{
    //cou;d use the top values >99 to denotes absorb and have a decay time
    // maybe not, can't save the orgiunal value, woudl have to cache, better to use  somethin else


    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterEating(EntityId e_id)
{
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome IceEating(EntityId e_id)
{
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AcidEating(EntityId e_id)
{
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LavaEating(EntityId e_id)
{
    return ACTION_SUCCEEDED;
}


/********************************************************************************************************************************************************************************************************************************************
*
*   STATS
*
********************************************************************************************************************************************************************************************************************************************/


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAttack(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].attack, value);
    if (attribute == g_core.creatures.stats[e_id].attack)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].attack = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseDefence(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].defence, value);
    if (attribute == g_core.creatures.stats[e_id].defence)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].defence = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMagic(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].magic, value);
    if (attribute == g_core.creatures.stats[e_id].magic)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].magic = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseSpeed(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].speed, value);
    if (attribute == g_core.creatures.stats[e_id].speed)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].speed = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAccuracy(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].accuracy, value);
    if (attribute == g_core.creatures.stats[e_id].accuracy)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].accuracy = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseLoyalty(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.stats[e_id].loyalty, value);
    if (attribute == g_core.creatures.stats[e_id].loyalty)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].loyalty = attribute;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAttack(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].attack, value);
    if (attribute == g_core.creatures.stats[e_id].attack)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].attack = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerDefence(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].defence, value);
    if (attribute == g_core.creatures.stats[e_id].defence)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].defence = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMagic(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].magic, value);
    if (attribute == g_core.creatures.stats[e_id].magic)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].magic = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerSpeed(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].speed, value);
    if (attribute == g_core.creatures.stats[e_id].speed)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].speed = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAccuracy(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].accuracy, value);
    if (attribute == g_core.creatures.stats[e_id].speed)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].accuracy = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerLoyalty(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.stats[e_id].loyalty, value);
    if (attribute == g_core.creatures.stats[e_id].loyalty)
        return ACTION_CANNOT;

    g_core.creatures.stats[e_id].loyalty = attribute;
    return ACTION_SUCCEEDED;
}

/********************************************************************************************************************************************************************************************************************************************
*
*   ATTRIBUTES
*
********************************************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseStrength(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].strength, value);
    if (attribute == g_core.creatures.attributes[e_id].strength)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].strength = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseFortitude(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].fortitude, value);
    if (attribute == g_core.creatures.attributes[e_id].fortitude)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].fortitude = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseIntelligence(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].intelligence, value);
    if (attribute == g_core.creatures.attributes[e_id].intelligence)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].intelligence = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAgility(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].agility, value);
    if (attribute == g_core.creatures.attributes[e_id].agility)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].agility = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseDexterity(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].dexterity, value);
    if (attribute == g_core.creatures.attributes[e_id].dexterity)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].dexterity = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseStamina(EntityId e_id, uint8_t value)
{
    uint16_t attribute = IncreaseValue_999(g_core.creatures.attributes[e_id].stamina, value);
    if (attribute == g_core.creatures.attributes[e_id].stamina)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].stamina = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerStrength(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].strength, value);
    if (attribute == g_core.creatures.attributes[e_id].strength)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].strength = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerFortitude(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].fortitude, value);
    if (attribute == g_core.creatures.attributes[e_id].fortitude)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].fortitude = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerIntelligence(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].intelligence, value);
    if (attribute == g_core.creatures.attributes[e_id].intelligence)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].intelligence = attribute;
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAgility(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].agility, value);
    if (attribute == g_core.creatures.attributes[e_id].agility)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].agility = attribute;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerDexterity(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].dexterity, value);
    if (attribute == g_core.creatures.attributes[e_id].dexterity)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].dexterity = attribute;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerStamina(EntityId e_id, uint8_t value)
{
    uint16_t attribute = DecreaseValue(g_core.creatures.attributes[e_id].stamina, value);
    if (attribute == g_core.creatures.attributes[e_id].stamina)
        return ACTION_CANNOT;

    g_core.creatures.attributes[e_id].stamina = attribute;
    return ACTION_SUCCEEDED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerCurrentXP(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_IntMax999(&g_core.creatures.xp[e_id], value))
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMaxHP(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_IntMax999(&g_core.creatures.hp[e_id], value))
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMaxHP(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_IntMax999(&g_core.creatures.hp[e_id], value))
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMaxMP(EntityId e_id, uint8_t value)
{
    if (IncreaseValue_IntMax999(&g_core.creatures.mp[e_id], value))
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMaxMP(EntityId e_id, uint8_t value)
{
    if (DecreaseValue_IntMax999(&g_core.creatures.mp[e_id], value))
        return ACTION_SUCCEEDED;
    return ACTION_CANNOT;
}

/********************************************************************************************************************************************************************************************************************************************

*
*   MAP MANIPULATION
*

********************************************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveMapFog()
{
    SetMapFog(1);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome CreateItemFood(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l)
{
    // TODO: Get random food type
    uint8_t food_type = hardware.GetRandom_uint8_t(0, ITEM_COUNT);
    SpawnEntity(hardware, memory, t, food_type, x, y, l);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId CreateItemCommon(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l)
{
    // TODO: Get random common type item
    uint8_t common_type = hardware.GetRandom_uint8_t(0, ITEM_COUNT);
    return SpawnEntity(hardware, memory, t, common_type, x, y, l);
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome CreateItemMagic(HardwareInterface hardware, MemoryInterface memory, uint8_t t, uint8_t x, uint8_t y, uint8_t l)
{
    // TODO: Get random common type item
    uint8_t magic_type = hardware.GetRandom_uint8_t(0, ITEM_COUNT);
    SpawnEntity(hardware, memory, t, magic_type, x, y, l);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome MapModifyTile(Position pos, MapTile tileType)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LevelUpRetainProgress(EntityId target_id)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;;
    if (g_core.creatures.level[target_id].value >= MAX_CREATURE_LEVEL) return ACTION_CANNOT;

    uint32_t old_max = Int999GetMax(&g_core.creatures.xp[target_id]);
    uint32_t old_cur = Int999GetCurrent(&g_core.creatures.xp[target_id]);

    // level up
    g_core.creatures.level[target_id].value++;
    SetXPToLevel(target_id, &g_core.creatures.xp[target_id]);
    uint32_t new_max = Int999GetMax(&g_core.creatures.xp[target_id]);

    // new_cur = floor(old_cur * new_max / old_max)
    uint32_t new_cur = (uint32_t)(((uint64_t)old_cur * new_max) / old_max);
    Int999SetCurrent(&g_core.creatures.xp[target_id], new_cur);
    return ACTION_SUCCEEDED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome GoNextLevel(MapLevelChange dir)
{
    if (dir == MAP_LEVEL_UP && g_core.floor > 1)
    {
        g_core.floor--;
        g_core.state.overlay = OVERLAY_GEN_MAP;
        return ACTION_SUCCEEDED;
    }

    if (dir == MAP_LEVEL_DOWN && g_core.floor < MAX_LEVELS)
    {
        g_core.floor++;
        g_core.state.overlay = OVERLAY_GEN_MAP;
        return ACTION_SUCCEEDED;
    }

    if (dir == MAP_LEVEL_LATERAL)
    {
        g_core.state.overlay = OVERLAY_GEN_MAP;
        return ACTION_SUCCEEDED;
    }

    return ACTION_FAILED;

    // UpdateLevel(g_core.floor, DESERT);
}
