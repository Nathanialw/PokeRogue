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
ActionOutcome RestoreResource(IntMax999* resource, EntityId creature_id, uint16_t value, uint16_t* cache)
{
    if (creature_id == NO_CREATURE) return ACTION_CANNOT;
    IntMax999 res = resource[creature_id];
    uint16_t cur = Int999GetCurrent(&res);
    uint16_t max = Int999GetMax(&res);
    if (cur == max) return ACTION_CANNOT;
    *cache = cur;
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
    const uint8_t level = g_core.creatures.level[creatureID].value >> 1;
    const uint16_t base = g_core.creatures.stats[creatureID].attack;
    const uint16_t skill = abilityPower;
    const uint16_t mod = GetNibble(g_core.creatures.attributes.strength, creatureID);

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
    g_core.battleMode.battle_hp_cache = hp;
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
    uint8_t mod = g_core.creatures.attributes.fortitude[defenderID]; //max 255
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
    return RestoreResource(g_core.creatures.hp, e_id, heal, &g_core.battleMode.battle_hp_cache);
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
    return RestoreResource(g_core.creatures.mp, e_id, value, &g_core.battleMode.battle_mp_cache);
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
ActionOutcome Repel(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.repel[e_id] < 8)
    {
        g_core.creatures.status.repel[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Hover(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.hovering[e_id] < 8)
    {
        g_core.creatures.status.hovering[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterBreathing(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.waterBreathing[e_id] < 8)
    {
        g_core.creatures.status.waterBreathing[e_id] = duration;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome XRayVision(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.lineOfSight[e_id] < 8)
    {
        g_core.creatures.status.lineOfSight[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterWalking(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.waterWalk[e_id] < 8)
    {
        g_core.creatures.status.waterWalk[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WallWalking(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.wallWalking[e_id] < 8)
    {
        g_core.creatures.status.wallWalking[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Invisibility(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.invisibility[e_id] < 8)
    {
        g_core.creatures.status.invisibility[e_id]++;
        return ACTION_SUCCEEDED;
    }
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
            if (trainer_id == GetPlayerID())
                g_core.player.currentPartySize++;
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

/**********************************************************************************************************************
*  Ends Combat and moves player to an adjacent tile
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Flee()
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
    if (g_core.creatures.status.poison[e_id] < 8)
    {
        g_core.creatures.status.poison[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyCurse(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.curse[e_id] < 8)
    {
        g_core.creatures.status.curse[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyParalyze(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.paralyzed[e_id] < 8)
    {
        g_core.creatures.status.paralyzed[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyDisease(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.disease[e_id] < 8)
    {
        g_core.creatures.status.disease[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplySleep(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.sleep[e_id] < 8)
    {
        g_core.creatures.status.sleep[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyFear(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.fear[e_id] < 8)
    {
        g_core.creatures.status.fear[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyFrozen(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.frozen[e_id] < 8)
    {
        g_core.creatures.status.frozen[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyBurn(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.burned[e_id] < 8)
    {
        g_core.creatures.status.burned[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplyHaste(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.hasted[e_id] < 8)
    {
        g_core.creatures.status.hasted[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome ApplySlow(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.slowed[e_id] < 8)
    {
        g_core.creatures.status.slowed[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusLesserBlind(EntityId e_id, uint8_t duration)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusGreaterBlind(EntityId e_id, uint8_t duration)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemovePoison(EntityId e_id)
{
    if (g_core.creatures.status.poison[e_id] > 0)
    {
        g_core.creatures.status.poison[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveCurse(EntityId e_id)
{
    if (g_core.creatures.status.curse[e_id] > 0)
    {
        g_core.creatures.status.curse[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveParalyze(EntityId e_id)
{
    if (g_core.creatures.status.paralyzed[e_id] > 0)
    {
        g_core.creatures.status.paralyzed[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveDisease(EntityId e_id)
{
    if (g_core.creatures.status.disease[e_id] > 0)
    {
        g_core.creatures.status.disease[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveSleep(EntityId e_id)
{
    if (g_core.creatures.status.sleep[e_id] > 0)
    {
        g_core.creatures.status.sleep[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveFear(EntityId e_id)
{
    if (g_core.creatures.status.fear[e_id] > 0)
    {
        g_core.creatures.status.fear[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveFrozen(EntityId e_id)
{
    if (g_core.creatures.status.frozen[e_id] > 0)
    {
        g_core.creatures.status.frozen[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveBurn(EntityId e_id)
{
    if (g_core.creatures.status.burned[e_id] > 0)
    {
        g_core.creatures.status.burned[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveHaste(EntityId e_id)
{
    if (g_core.creatures.status.hasted[e_id] > 0)
    {
        g_core.creatures.status.hasted[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RemoveSlow(EntityId e_id)
{
    if (g_core.creatures.status.slowed[e_id] > 0)
    {
        g_core.creatures.status.slowed[e_id]--;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusLesserLight(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.light[e_id] < 8)
    {
        g_core.creatures.status.light[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome StatusGreaterLight(EntityId e_id, uint8_t duration)
{
    if (g_core.creatures.status.light[e_id] < 8)
    {
        g_core.creatures.status.light[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
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
    if (g_core.creatures.status.light[e_id] < 8)
    {
        g_core.creatures.status.light[e_id]++;
        return ACTION_SUCCEEDED;
    }
    return ACTION_CANNOT;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome PersistentPoisonCloud(uint8_t duration)
{
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// RESISTANCES

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAcidResistance(EntityId e_id)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseFireResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseWaterResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseIceResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMagicResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAllResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAcidResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerFireResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerWaterResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerIceResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMagicResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAllResistance(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome FireEating(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome WaterEating(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome IceEating(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome AcidEating(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LavaEating(EntityId e_id)
{
    return ACTION_FAILED;
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
ActionOutcome RaiseStrength(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseDefence(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseMagic(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseSpeed(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseAccuracy(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerStrength(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerDefence(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerMagic(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerSpeed(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerAccuracy(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseBaseStrength(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseBaseDefence(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseBaseMagic(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome RaiseBaseSpeed(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerBaseSpeed(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerBaseDefence(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerBaseMagic(EntityId e_id)
{
    return ACTION_FAILED;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome LowerBaseStrength(EntityId e_id)
{
    return ACTION_FAILED;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome DrainXP(EntityId e_id)
{
    return ACTION_FAILED;
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
