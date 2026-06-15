//
// Created by nathanial on 4/7/26.
//

#include "combat_tests.h"

#include <string.h>

#include "core_effects.h"
#include "core_entities.h"
#include "core_memory_access.h"
#include "core_ram.h"
#include "lib_debugging.h"
#include "map_entities.h"
#include "types.h"


#define MAX_ARRAY_SIZE 20

struct
{
    uint8_t failureCount;
    uint16_t base_damage[MAX_ARRAY_SIZE];
    uint16_t damage[MAX_ARRAY_SIZE];
    Stats attackerStats[MAX_ARRAY_SIZE];
    Stats defenderStats[MAX_ARRAY_SIZE];
    char ability_used[MAX_ARRAY_SIZE][SMALL_STRINGS];
    char attackerName[MAX_ARRAY_SIZE][SMALL_STRINGS];
    char defenderName[MAX_ARRAY_SIZE][SMALL_STRINGS];

    uint16_t damageCount[256];
    uint16_t highestDamage;
} DamageTest;


bool RunAbilityDamageTest(HardwareInterface hardware, MemoryInterface memory, Creature attacker, Creature defender, Ability abilityID, uint8_t attackerLevel, uint8_t defenderLevel, uint16_t maxDamage)
{
    EntityId attackerID = SpawnEntity(hardware, memory, CREATURE, attacker, 0, 0, attackerLevel);
    EntityId defenderID = SpawnEntity(hardware, memory, CREATURE, defender, 0, 0, defenderLevel);

    SkillData ability_data = {0};
    Flash_GetSkillData(memory, &ability_data, abilityID);

    uint16_t base_damage = CalcDamage(attackerID, ability_data.power);
    uint16_t damage = CalcModifier(memory, attackerID, defenderID, ability_data.type, base_damage);
    Stats attackerStats = g_core.creatures.stats[attackerID];
    Stats defenderStats = g_core.creatures.stats[defenderID];
    ResetEntities(hardware, memory, false);
    DamageTest.damageCount[damage]++;
    if (damage > DamageTest.highestDamage)
        DamageTest.highestDamage = damage;

    if (damage > maxDamage || damage == 0)
    {
        Flash_GetCreatureName(memory, DamageTest.defenderName[DamageTest.failureCount], defender);
        Flash_GetSkillName(memory, DamageTest.ability_used[DamageTest.failureCount], attacker);
        Flash_GetCreatureName(memory, DamageTest.attackerName[DamageTest.failureCount], abilityID);

        DamageTest.base_damage[DamageTest.failureCount] = base_damage;
        DamageTest.damage[DamageTest.failureCount] = damage;
        DamageTest.attackerStats[DamageTest.failureCount] = attackerStats;
        DamageTest.defenderStats[DamageTest.failureCount] = defenderStats;
        DamageTest.failureCount++;
        if (DamageTest.failureCount == MAX_ARRAY_SIZE)
            return true;
    }

    return false;
}

void TestAbilityDamageAll(HardwareInterface hardware, MemoryInterface memory, uint8_t attackerLevel, uint8_t defenderLevel, uint16_t maxDamage, const char* testName)
{
    memset(&DamageTest, 0, sizeof(DamageTest));

    for (uint8_t a = 0; a < ABILITY_COUNT; a++)
    {
        DEBUG_INLINE(".");
        for (uint8_t i = 0; i < CREATURE_COUNT; i++)
        {


            for (uint8_t j = 0; j < CREATURE_COUNT; j++)
                if (RunAbilityDamageTest(hardware, memory, i, j, a, attackerLevel, defenderLevel, maxDamage))
                    goto end_early;
        }
    }

end_early:
    DEBUG_INLINE("\n");
    if (DamageTest.failureCount > 0)
    {
        DEBUG("FAILED lvl: %d vs lvl: %d - %s %d times", attackerLevel, defenderLevel, testName, DamageTest.failureCount);
        for (int i = 0; i < DamageTest.failureCount; i++)
        {
            DEBUG("     %s", DamageTest.ability_used[i]);
            DEBUG("         Attacker %s stats A: %d, D: %d, M: %d, S: %d", DamageTest.attackerName[i], DamageTest.attackerStats[i].attack, DamageTest.attackerStats[i].defence, DamageTest.attackerStats[i].magic, DamageTest.attackerStats[i].speed);
            DEBUG("         Defender %s stats A: %d, D: %d, M: %d, S: %d", DamageTest.defenderName[i], DamageTest.defenderStats[i].attack, DamageTest.defenderStats[i].defence, DamageTest.defenderStats[i].magic, DamageTest.defenderStats[i].speed);
            DEBUG("         base_damage %d, damage %d", DamageTest.base_damage[i], DamageTest.damage[i]);
        }
    }
    else
        DEBUG("PASSED lvl: %d vs lvl: %d - No %s", attackerLevel, defenderLevel, testName);

    // for (uint16_t i = 0; i < DamageTest.highestDamage + 1; i++)
    // {
    //     if (DamageTest.damageCount[i] == 0) continue;
    //     DEBUG("%d: %d", i, DamageTest.damageCount[i]);
    // }
}

void RunCombatTests(HardwareInterface hardware, MemoryInterface memory)
{
    // test abilities at low level  do more than 0 damage but not too much damage, 12 for now
    // for (uint8_t i = 0; i < 99; i++)
    // for (uint8_t j = 0; j < 99; j++)
    // TestAbilityDamageAll(i,  j, 999, "Damage exceeded max of 999 or damage == 0");
    TestAbilityDamageAll(hardware, memory, 5, 5, 20, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 10, 10, 50, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 20, 20, 100, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 30, 30, 200, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 40, 40, 300, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 50, 50, 400, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 60, 60, 500, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 70, 70, 500, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 80, 80, 500, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 90, 90, 600, "Damage exceeded max of 999 or damage == 0");
    // TestAbilityDamageAll(hardware, memory, 99, 99, 700, "Damage exceeded max of 999 or damage == 0");
}
