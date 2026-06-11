//
// Created by nathanial on 6/5/26.
//

#include "generate_map_entities.h"
#include "lib_memory.h"

#include "core_entities.h"
#include "core_map.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_utils.h"

#include "generate_map.h"


/*******************************************************************************************************************
** Initializes player data
 *  Creates default creatures for party
 *  Creates default items for party
 *  Places default spells in spellbook
 *  Sets player to a random empty cell on the map
 *  sets sight rango around player
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void InitPlayer(HardwareInterface hardware, MemoryInterface memory)
{
    if (g_core.player.id != NO_ENTITY)
        return;

    Position pos = FindOpenMapLocation(hardware, TRAINER);
    uint8_t x = pos.x;
    uint8_t y = pos.y;
    g_core.player.id = SpawnEntity(hardware, memory, TRAINER, 0, x, y, 0);

    //  TODO: load trainer spell data from the database flash
    AddSpellPage(memory, g_core.player.id, HEAL, g_core.player.currentSpellbookSize);
    g_core.player.currentSpellbookSize++;
    AddSpellPage(memory, g_core.player.id, DESCEND, g_core.player.currentSpellbookSize);
    g_core.player.currentSpellbookSize++;
    AddSpellPage(memory, g_core.player.id, CLAIRVOYANCE, g_core.player.currentSpellbookSize);
    g_core.player.currentSpellbookSize++;
    AddSpellPage(memory, g_core.player.id, DISPLACEMENT, g_core.player.currentSpellbookSize);
    g_core.player.currentSpellbookSize++;


    //  TODO: set from trainer data in the database flash
    EntityId item_id = SpawnEntity(hardware, memory, ITEM, RARE_CANDY, x, y, 0);
    PlayerPickItem(item_id);
    EntityId item_id2 = SpawnEntity(hardware, memory, ITEM, POTION_XP, x, y, 0);
    PlayerPickItem(item_id2);
    EntityId item_id3 = SpawnEntity(hardware, memory, ITEM, EXPLOSIVE_FLASK, x, y, 0);
    PlayerPickItem(item_id3);

    g_core.trainers.speed[g_core.player.id].max = 99;
    g_core.trainers.speed[g_core.player.id].current = 15;
}


/**********************************************************************************************************************
*   Copy all values of the given entity ID
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CopyCreature(HardwareInterface hardware, EntityId src_id, EntityId target_id)
{
    g_core.creatures.position[target_id] = g_core.creatures.position[src_id];
    g_core.creatures.types[target_id] = g_core.creatures.types[src_id];

    g_core.creatures.metaData[target_id].unused = g_core.creatures.metaData[src_id].unused;
    g_core.creatures.senses[target_id].sight = g_core.creatures.senses[src_id].sight;
    g_core.creatures.senses[target_id].smell = g_core.creatures.senses[src_id].smell;
    g_core.creatures.senses[target_id].sound = g_core.creatures.senses[src_id].sound;
    g_core.creatures.stealth[target_id].sight = g_core.creatures.stealth[src_id].sight;
    g_core.creatures.stealth[target_id].sound = g_core.creatures.stealth[src_id].sound;
    g_core.creatures.stealth[target_id].smell = g_core.creatures.stealth[src_id].smell;
    g_core.creatures.stats[target_id].attack = g_core.creatures.stats[src_id].attack;
    g_core.creatures.stats[target_id].defence = g_core.creatures.stats[src_id].defence;
    g_core.creatures.stats[target_id].magic = g_core.creatures.stats[src_id].magic;
    g_core.creatures.stats[target_id].speed = g_core.creatures.stats[src_id].speed;
    g_core.creatures.level[target_id].value = g_core.creatures.level[src_id].value;

    for (uint8_t i = 0; i < 8; i++)
        g_core.creatures.attacks[target_id][i] = NO_ABILITY;
    Int999SetCurrent(&g_core.creatures.hp[target_id], 0);
    Int999SetMax(&g_core.creatures.hp[target_id], 0);

    SetBit(g_core.creatures.alive, target_id, GetBit(g_core.creatures.alive, src_id));
    SetBit(g_core.creatures.onMap, target_id, GetBit(g_core.creatures.onMap, src_id));
    SetBit(g_core.creatures.active, target_id, GetBit(g_core.creatures.active, src_id));
}

SET_MEMORY(".map_gen")
void CopyTrainer(HardwareInterface hardware, EntityId src_id, EntityId target_id)
{
    g_core.trainers.position[target_id] = g_core.creatures.position[src_id];
    g_core.trainers.types[target_id] = g_core.creatures.types[src_id];

    g_core.trainers.metaData[target_id].unused = g_core.creatures.metaData[src_id].unused;
    g_core.trainers.senses[target_id].sight = g_core.creatures.senses[src_id].sight;
    g_core.trainers.senses[target_id].smell = g_core.creatures.senses[src_id].smell;
    g_core.trainers.senses[target_id].sound = g_core.creatures.senses[src_id].sound;
    g_core.trainers.stealth[target_id].sight = g_core.creatures.stealth[src_id].sight;
    g_core.trainers.stealth[target_id].sound = g_core.creatures.stealth[src_id].sound;
    g_core.trainers.stealth[target_id].smell = g_core.creatures.stealth[src_id].smell;

    //copy party


    SetBit(g_core.trainers.alive, target_id, GetBit(g_core.creatures.alive, src_id));
    SetBit(g_core.trainers.onMap, target_id, GetBit(g_core.creatures.onMap, src_id));
    SetBit(g_core.trainers.active, target_id, GetBit(g_core.creatures.active, src_id));
}


SET_MEMORY(".map_gen")
void CopyItem(EntityId src_id, EntityId target_id)
{
    g_core.items.position[target_id] = g_core.items.position[src_id];
    g_core.items.types[target_id] = g_core.items.types[src_id];
    g_core.items.metaData[target_id].unused = g_core.items.metaData[src_id].unused;

    SetBit(g_core.items.onMap, target_id, GetBit(g_core.items.onMap, src_id));
    SetBit(g_core.items.active, target_id, GetBit(g_core.items.active, src_id));
}


SET_MEMORY(".map_gen")
void CopyObject(EntityId src_id, EntityId target_id)
{
    g_core.items.position[target_id] = g_core.items.position[src_id];
    g_core.items.types[target_id] = g_core.items.types[src_id];
    g_core.items.metaData[target_id].unused = g_core.items.metaData[src_id].unused;

    SetBit(g_core.items.onMap, target_id, GetBit(g_core.items.onMap, src_id));
    SetBit(g_core.items.active, target_id, GetBit(g_core.items.active, src_id));
}

/*******************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
EntityId CachePlayerCreatureData(HardwareInterface hardware)
{
    EntityId player_id = GetPlayerID();

    EntityId creature_idx = 0;
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (g_core.trainers.partyID[player_id][i] != NO_ENTITY)
        {
            CopyCreature(hardware, g_core.trainers.partyID[player_id][i], creature_idx);
            g_core.trainers.partyID[player_id][i] = creature_idx;
            creature_idx++;
        }
    }

    //set player creatures to beginning of the array
    return creature_idx;
}


SET_MEMORY(".map_gen")
EntityId CachePlayerItemData(void)
{
    EntityId item_idx = 0;
    EntityId sorted_indexes[MAX_BAG_SIZE];
    EntityId p_ID = GetPlayerID();
    SortEntityArray(sorted_indexes, g_core.trainers.itemID[p_ID], MAX_BAG_SIZE);

    for (uint8_t i = 0; i < MAX_BAG_SIZE; i++)
    {
        if (sorted_indexes[i] != NO_ENTITY && sorted_indexes[i] != item_idx)
        {
            CopyItem(g_core.trainers.itemID[p_ID][i], item_idx);
            g_core.trainers.itemID[p_ID][i] = item_idx;
            item_idx++;
        }
    }

    //set player items to beginning of the array
    return item_idx;
}


SET_MEMORY(".map_gen")
EntityId CheckIfPlayerItem(EntityId item_id)
{
    EntityId p_ID = GetPlayerID();
    for (uint8_t i = 0; i < MAX_BAG_SIZE; i++)
    {
        if (g_core.trainers.itemID[p_ID][i] == item_id)
            return true;
    }

    return false;
}


SET_MEMORY(".map_gen")
EntityId CheckIfInPlayerParty(EntityId creature_id)
{
    EntityId p_ID = GetPlayerID();
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (g_core.trainers.partyID[p_ID][i] == creature_id)
            return true;
    }

    return false;
}

/**********************************************************************************************************************/
/** Reset all values of all entities on the map
 *  TODO: may add trainers later
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void ResetEntities(HardwareInterface hardware, MemoryInterface memory, bool copyPlayer)
{
    uint16_t creature_start_idx = 0;
    uint16_t item_start_idx = 0;
    EntityId player_id = GetPlayerID();

    for (uint16_t i = creature_start_idx; i < MAX_ENTITY_CREATURE_COUNT; i++)
    {
        if (!CheckIfInPlayerParty(i))
            DestroyCreature(i);
    }

    for (uint16_t i = item_start_idx; i < MAX_ENTITY_ITEM_COUNT; i++)
    {
        if (!CheckIfPlayerItem(i))
            DestroyItem(i);
    }

    for (uint16_t i = 0; i < MAX_ENTITY_OBJECT_COUNT; i++)
        DestroyObject(i);

    for (uint16_t i = 0; i < MAX_ENTITY_TRAINER_COUNT; i++)
    {
        if (i != player_id)
            DestroyTrainer(i);
    }

    g_core.creatures.total = 0;
    g_core.items.total = 0;
    g_core.objects.total = 0;
    g_core.trainers.total = 1;
}


/**********************************************************************************************************************/
/** Creates all the creatures on the map from the BIOME and THEME data
**********************************************************************************************************************/
#define INITIAL (MAP_EDGE + 28)
#define SPACING 8

SET_MEMORY(".map_gen")
void PopulateLevelTrainers(HardwareInterface hardware, MemoryInterface memory)
{
#if defined(TEST_MAP)
    Position pos = {.x = MAP_EDGE, .y = INITIAL};
    const uint8_t max_x = MAP_W - (((MAP_EDGE + 1) * 2) + 1);

    for (uint8_t i = 0; i < TRAINER_COUNT; i++)
    {
        pos.x++;
        if (i % max_x == 0)
        {
            pos.x = 14;
            pos.y += 2;
        }
        SpawnEntity(hardware, memory, TRAINER, i, pos.x, pos.y, 1);
    }

    for (uint16_t i = 0; i < g_core.trainers.total; i++)
        if (GetBit(g_core.trainers.onMap, i) && GetBit(g_core.trainers.alive, i))
            g_core.trainers.newPosition[i] = g_core.trainers.position[i];
#else
    uint8_t trainer_level = 1;
    for (uint8_t i = 0; i < NUM_MAP_TRAINERS; i++)
    {
        const ItemTypes trainer_type = hardware.GetRandom_uint8_t(0, TRAINER_COUNT);
        const Position pos = FindOpenMapLocation(hardware, TRAINER);
        if (pos.x == 0 && pos.y == 0) continue;
        SpawnEntity(hardware, memory, TRAINER, trainer_type, pos.x, pos.y, trainer_level);
    }
#endif
}


SET_MEMORY(".map_gen")
void PopulateLevelCreatures(HardwareInterface hardware, MemoryInterface memory)
{
#if defined(TEST_MAP)
    uint8_t creature_level = g_core.floor;
    Position pos = {.x = MAP_EDGE, .y = INITIAL + (SPACING)};
    uint8_t max_creatures = CREATURE_COUNT - g_core.creatures.total;
    const uint8_t max_x = MAP_W - (((MAP_EDGE + 1) * 2) + 1);
    for (uint8_t i = 0; i < max_creatures; i++)
    {
        pos.x++;
        if (i % max_x == 0)
        {
            pos.x = 14;
            pos.y += 2;
        }
        SpawnEntity(hardware, memory, CREATURE, i, pos.x, pos.y, creature_level);
    }

    for (uint16_t i = 0; i < g_core.creatures.total; i++)
        if (GetBit(g_core.creatures.onMap, i) && GetBit(g_core.creatures.alive, i))
            g_core.creatures.newPosition[i] = g_core.creatures.position[i];
#else
    uint8_t creature_level = g_core.floor;
    for (uint8_t i = 0; i < g_core.roomCount >> 2; i++)
    {
        uint8_t index = hardware.GetRandom_uint8_t(0, BIOME_MONSTER_TYPES);
        const Creature creature = Flash_GetBiomeCreature(memory, g_core.biome, index);
        const Position pos = FindOpenRoomLocation(hardware, CREATURE, i);
        if (pos.x == 0 && pos.y == 0) continue;
        SpawnEntity(hardware, memory, CREATURE, creature, pos.x, pos.y, creature_level);
    }

    for (uint8_t i = 0; i < g_core.roomCount >> 1; i++)
    {
        uint8_t index = hardware.GetRandom_uint8_t(0, THEME_MONSTER_TYPES);
        const Creature creature = Flash_GetThemeCreature(memory, g_core.theme, index);
        const Position pos = FindOpenRoomLocation(hardware, CREATURE, i);
        SpawnEntity(hardware, memory, CREATURE, creature, pos.x, pos.y, creature_level);
    }

    for (uint8_t i = 0; i < g_core.creatures.total; i++)
        if (GetBit(g_core.creatures.onMap, i) && GetBit(g_core.creatures.alive, i))
            g_core.creatures.newPosition[i] = g_core.creatures.position[i];
#endif
}

SET_MEMORY(".map_gen")
void PopulateLevelItems(HardwareInterface hardware, MemoryInterface memory)
{
#if defined(TEST_MAP)
    const uint8_t max_x = MAP_W - (((MAP_EDGE + 1) * 2) + 1);
    Position pos = {.x = MAP_EDGE + 2, .y = INITIAL + (SPACING * 2)};
    for (uint8_t i = 0; i < ITEM_COUNT; i++)
    {
        pos.x++;
        if (i % max_x == 0)
        {
            pos.x = 14;
            pos.y += 2;
        }
        SpawnEntity(hardware, memory, ITEM, i, pos.x, pos.y, 1);
    }

#else
    const uint8_t item_level = 1;
    for (uint8_t i = 0; i < g_core.roomCount; i++)
    {
        const uint8_t n = hardware.GetRandom_uint8_t(1, 3);
        for (uint8_t j = 0; j < n; j++)
        {
            const ItemTypes item_type = hardware.GetRandom_uint8_t(0, ITEM_COUNT);
            const Position pos = FindOpenRoomLocation(hardware, ITEM, i);
            if (pos.x == 0 && pos.y == 0) continue;
            SpawnEntity(hardware, memory, ITEM, item_type, pos.x, pos.y, item_level);
        }
    }
    Position tile_position = {0, 0};
    while (g_core.items.total < MAX_ENTITY_ITEM_COUNT)
    {
        tile_position = FindHallDeadEnd(ITEM, tile_position);
        if (tile_position.x == 0 && tile_position.y == 0) break;
        const ItemTypes item_type = hardware.GetRandom_uint8_t(0, ITEM_COUNT);
        const Position pos = tile_position;
        EntityId entity_id = SpawnEntity(hardware, memory, ITEM, item_type, pos.x, pos.y, item_level);
        if (entity_id == NO_ENTITY) break;
    }

#endif
}

SET_MEMORY(".map_gen")
void PopulateLevelObjects(HardwareInterface hardware, MemoryInterface memory)
{
#if defined(TEST_MAP)
    const uint8_t max_x = MAP_W - (((MAP_EDGE + 1) * 2) + 1);
    Position pos = {.x = MAP_EDGE, .y = INITIAL + (SPACING * 3)};
    for (uint8_t i = 0; i < OBJECT_COUNT; i++)
    {
        pos.x++;
        if (i % max_x == 0)
        {
            pos.x = 14;
            pos.y += 2;
        }
        SpawnEntity(hardware, memory, OBJECT, i, pos.x, pos.y, 1);
    }
#else
    uint8_t object_level = 1;
    for (uint8_t i = 0; i < g_core.roomCount; i++)
    {
        const Object object_type = hardware.GetRandom_uint8_t(0, OBJECT_COUNT);
        const Position pos = FindOpenRoomLocation(hardware, OBJECT, i);
        if (pos.x == 0 && pos.y == 0) continue;
        SpawnEntity(hardware, memory, OBJECT, object_type, pos.x, pos.y, object_level);
    }

    // Position tile_position = {0};
    // while (g_core.objects.total < MAX_ENTITY_OBJECT_COUNT)
    // {
    //     tile_position = FindHall(OBJECT, tile_position);
    //     if (tile_position.x == 0 && tile_position.y == 0) break;
    //     const Object object_type = hardware.GetRandom_uint8_t(0, OBJECT_COUNT);
    //     const Position pos = tile_position;
    //     EntityId entity_id = SpawnEntity(hardware, memory, OBJECT, object_type, pos.x, pos.y, object_level);
    //     if (tile_position.x < MAP_W)
    //     {
    //         tile_position.x++;
    //     }
    //     else
    //     {
    //         tile_position.x = 0;
    //         tile_position.y++;
    //     }
    //     if (entity_id == NO_ENTITY) break;
    // }
#endif
}


/*******************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void PlacePlayerOnMap(HardwareInterface hardware)
{
    Position pos = FindOpenMapLocation(hardware, TRAINER);
    g_core.trainers.position[g_core.player.id].x = pos.x;
    g_core.trainers.position[g_core.player.id].y = pos.y;
}

SET_MEMORY(".map_gen")
void GenerateEntities(GameInterface* spi)
{
    if (g_core.turn_count == 0)
    {
        InitPlayer(spi->hardware, spi->memory);
        PopulateLevelTrainers(spi->hardware, spi->memory);
        PopulateLevelCreatures(spi->hardware, spi->memory);
        PopulateLevelObjects(spi->hardware, spi->memory);
        PopulateLevelItems(spi->hardware, spi->memory);
        PlacePlayerOnMap(spi->hardware);
    }
}
