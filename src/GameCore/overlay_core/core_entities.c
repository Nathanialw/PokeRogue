//
// Created by nathanial on 5/19/26.
//

#include "core_entities.h"
#include "lib_memory.h"
#include "lib_constants.h"

#include "enums.h"
#include "types.h"
#include "constants.h"

#include "core_memory_access.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"
#include "generate_map_memory_access.h"


/**********************************************************************************************************************/
/** sets the creature position to 0,0
*   sets creature to false on the map array
*   returns the entity id of the creature
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId CaptureMonster(EntityId id)
{
    SetBit(g_core.creatures.onMap, id, false);
    Position empty_pos = {.x = 0, .y = 0};
    g_core.creatures.position[id] = empty_pos;
    return id;
}

/**********************************************************************************************************************/
/** sets the item position to 0,0
*   sets item to false on the map array
*   returns the entity id of the item
**********************************************************************************************************************/
SET_MEMORY(".core")
bool PickItem(EntityId trainer_id, EntityId item_id)
{
    if (item_id == NO_ENTITY) return false;
    for (uint8_t i = 0; i < MAX_BAG_SIZE; ++i)
    {
        if (g_core.trainers.itemID[trainer_id][i] == NO_ENTITY)
        {
            Position empty_pos = {.x = 0, .y = 0};
            g_core.items.position[item_id] = empty_pos;
            SetBit(g_core.items.onMap, item_id, false);
            g_core.trainers.itemID[trainer_id][i] = item_id;
            g_core.trainers.bag[trainer_id].occupied_slots++;
            return true;
        }
    }

    return false;
}

SET_MEMORY(".core")
bool AddCreatureToParty(EntityId trainer_id, EntityId creature_id)
{
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (g_core.trainers.partyID[trainer_id][i] == NO_ENTITY)
        {
            g_core.trainers.partyID[trainer_id][i] = creature_id;
            return true;
        }
    }
    return false;
}

SET_MEMORY(".core")
bool DeleteCreatureFromParty(EntityId trainer_id, EntityId creature_id)
{
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (g_core.trainers.partyID[trainer_id][i] == creature_id)
            g_core.trainers.partyID[trainer_id][i] = NO_ENTITY;

        if (g_core.trainers.partyID[trainer_id][i] == NO_ENTITY && i < MAX_PARTY_SIZE - 1)
            g_core.trainers.partyID[trainer_id][i] = g_core.trainers.partyID[trainer_id][i + 1];
    }
    return false;
}

SET_MEMORY(".core")
EntityId GetNextPartyCreature(EntityId trainer_id)
{
    for (uint8_t i = 0; i < MAX_PARTY_SIZE - 1; i++)
        if (g_core.trainers.partyID[trainer_id][i] == NO_ENTITY)
            g_core.trainers.partyID[trainer_id][i] = g_core.trainers.partyID[trainer_id][i + 1];

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
        if (g_core.trainers.partyID[trainer_id][i] == NO_ENTITY)
            return g_core.trainers.partyID[trainer_id][i];

    return NO_ENTITY;
}

/**********************************************************************************************************************/
/**Reset all values of the given entity ID
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyCreature(EntityId id)
{
    if (!GetBit(g_core.creatures.active, id))
        return;

    Position empty_pos = {.x = 0, .y = 0};
    g_core.creatures.position[id] = empty_pos;
    SetBit(g_core.creatures.onMap, id, false);
    g_core.creatures.types[id] = NO_ENTITY;
    g_core.creatures.metaData[id].unused = NO_ENTITY;
    SetBit(g_core.creatures.alive, id, false);
    g_core.creatures.senses[id].sight = 0;
    g_core.creatures.senses[id].smell = 0;
    g_core.creatures.senses[id].sound = 0;
    g_core.creatures.stealth[id].sight = 0;
    g_core.creatures.stealth[id].sound = 0;
    g_core.creatures.stealth[id].smell = 0;
    g_core.creatures.stats[id].attack = 0;
    g_core.creatures.stats[id].defence = 0;
    g_core.creatures.stats[id].magic = 0;
    g_core.creatures.stats[id].speed = 0;
    for (uint8_t i = 0; i < 8; ++i)
        g_core.creatures.attacks[id][i] = NO_ABILITY;
    Int999SetCurrent(&g_core.creatures.hp[id], 0);
    Int999SetMax(&g_core.creatures.hp[id], 0);
    g_core.creatures.level[id].value = 0;
    SetBit(g_core.creatures.active, id, false);
}


SET_MEMORY(".core")
void DestroyItem(EntityId id)
{
    if (!GetBit(g_core.items.active, id))
        return;

    Position empty_pos = {.x = 0, .y = 0};
    g_core.items.position[id] = empty_pos;
    SetBit(g_core.items.onMap, id, false);
    g_core.items.types[id] = NO_ENTITY;
    g_core.items.metaData[id].unused = NO_ENTITY;
    SetBit(g_core.items.active, id, false);
}


SET_MEMORY(".core")
void DestroyObject(EntityId id)
{
    if (!GetBit(g_core.objects.active, id))
        return;


    Position empty_pos = {.x = 0, .y = 0};
    g_core.objects.position[id] = empty_pos;
    SetBit(g_core.objects.onMap, id, false);
    g_core.objects.types[id] = NO_ENTITY;
    g_core.objects.metaData[id].unused = NO_ENTITY;
    SetBit(g_core.objects.active, id, false);
}

SET_MEMORY(".core")
void DestroyTrainer(EntityId id)
{
    if (!GetBit(g_core.trainers.active, id))
        return;

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        EntityId creature_id = g_core.trainers.partyID[id][i];
        if (creature_id == NO_ENTITY) continue;
        DestroyCreature(creature_id);
        g_core.trainers.partyID[creature_id][i] = NO_ENTITY;
    }


    Position empty_pos = {.x = 0, .y = 0};
    g_core.objects.position[id] = empty_pos;
    SetBit(g_core.trainers.onMap, id, false);
    g_core.trainers.types[id] = NO_ENTITY;
    SetBit(g_core.trainers.active, id, false);
}

SET_MEMORY(".core")
void DestroyPartyCreature(EntityId id)
{
    DestroyCreature(id);

    //if trainer has no more creatures, destroy the trainer
    EntityId creature_id = NO_ENTITY;
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
        creature_id = g_core.trainers.partyID[id][i];
    if (creature_id == NO_ENTITY)
    {
        DestroyTrainer(id);
        return;
    }

    //move all creatures up a party slot
    for (uint8_t i = 0; i < MAX_PARTY_SIZE - 1; i++)
        g_core.trainers.partyID[id][i] = g_core.trainers.partyID[id][i + 1];
}


/**********************************************************************************************************************/
/** Returns the type ID of the given entity ID
**********************************************************************************************************************/
SET_MEMORY(".core")
ItemTypes GetItemType(EntityId id)
{
    if (id == NO_ENTITY)
        return NO_ITEM;

    return g_core.items.types[id];
}


SET_MEMORY(".core")
Object GetObjectType(EntityId id)
{
    if (id == NO_ENTITY)
        return NO_OBJECT;

    return g_core.objects.types[id];
}


SET_MEMORY(".core")
Creature GetCreatureType(EntityId id)
{
    if (id == NO_ENTITY)
        return NO_CREATURE;

    return g_core.creatures.types[id];
}


SET_MEMORY(".core")
IntMax999 GetCreaturehp(EntityId id)
{
    return g_core.creatures.hp[id];
}

SET_MEMORY(".core")
IntMax999 GetCreaturemp(EntityId id)
{
    return g_core.creatures.mp[id];
}

SET_MEMORY(".core")
IntMax999 GetCreaturexp(EntityId id)
{
    return g_core.creatures.xp[id];
}


/**********************************************************************************************************************/
/** Fill typeIDs[] with the types of the given e_ids[] array
 *  ON SUCCESS - Returns the type ID of the given entity ID
 *  ON FAIL - sets typeIDs to NULL and returns NULL
**********************************************************************************************************************/
SET_MEMORY(".core")
void GetEntityTypes(MemoryInterface memory, uint8_t* typeIDs, const uint8_t* e_ids, ObjectsTypes type, uint8_t n, uint8_t offset)
{
    SmallStringArray text[MAX_MENU_SIZE];
    uint8_t i = offset;

    switch (type)
    {
    case CREATURE:
        {
            while (i < n)
            {
                typeIDs[i] = GetCreatureType(e_ids[i]);
                Flash_GetCreatureName(memory, g_core.menu.text[i], typeIDs[i]);
                i++;
            }
            g_core.menu.text[i][0] = '\0';
            break;
        }
    case ITEM:
        {
            while (i < n)
            {
                typeIDs[i] = GetItemType(e_ids[i]);
                Flash_GetItemName(memory, g_core.menu.text[i], typeIDs[i]);
                i++;
            }
            g_core.menu.text[i][0] = '\0';
            break;
        }
    case OBJECT:
        {
            while (i < n)
            {
                typeIDs[i] = GetObjectType(e_ids[i]);
                Flash_GetObjectName(memory, g_core.menu.text[i], typeIDs[i]);
                i++;
            }
            g_core.menu.text[i][0] = '\0';
            break;
        }
    default:
        {
            typeIDs = NULL;
        }
    }
}

EntityId SpawnMonster(HardwareInterface hardware, MemoryInterface memory, uint8_t monType, uint8_t x, uint8_t y, uint8_t l);
EntityId SpawnItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itmType, uint8_t x, uint8_t y, uint8_t l);
EntityId SpawnObject(HardwareInterface hardware, MemoryInterface memory, uint8_t shrineType, uint8_t x, uint8_t y, uint8_t l);
EntityId SpawnTrainer(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l);
typedef EntityId (*Spawn)(HardwareInterface hardware, MemoryInterface memory, uint8_t, uint8_t, uint8_t, uint8_t);

/**********************************************************************************************************************/
/** point array for creating entities
**********************************************************************************************************************/
SET_MEMORY(".core.rodata")
const Spawn spawn[TOTAL_SPAWNABLE_OBJECT_TYPES] = {SpawnMonster, SpawnTrainer, SpawnObject, SpawnItem};

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type creature
*   TODO - get all values from the db data or generate them
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnMonster(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
    if (type == NO_TRAINER) return NO_CREATURE;

    EntityId id = NO_ENTITY;
    for (uint16_t i = 0; i < MAX_ENTITY_CREATURE_COUNT; i++)
    {
        if (!GetBit(g_core.creatures.active, i))
        {
            id = i;
            SetBit(g_core.creatures.active, id, true);
            break;
        }
        if (i >= MAX_ENTITY_CREATURE_COUNT - 1)
            return NO_ENTITY;
    }

    if (l <= 0) l = 1;
    Creature monType = (Creature)type;
    Position pos = {.x = x, .y = y};
    g_core.creatures.position[id] = pos;
    g_core.creatures.level[id].value = l;
    g_core.creatures.types[id] = type;

    GetStats(hardware, memory, &g_core.creatures.stats[id], monType, l);
    SetXPToLevel(id, &g_core.creatures.xp[id]);
    g_core.creatures.hp[id] = GetHP(monType, l);
    g_core.creatures.mp[id] = GetMP(monType, l);

    g_core.creatures.senses[id].sight = 7;
    g_core.creatures.senses[id].sound = 7;
    g_core.creatures.senses[id].smell = 3;
    g_core.creatures.stealth[id].sight = 3;
    g_core.creatures.stealth[id].sound = 3;
    g_core.creatures.stealth[id].smell = 0;

    SetDefaultSkills(memory, id, type);
    SetBit(g_core.creatures.alive, id, true);
    SetBit(g_core.creatures.onMap, id, true);
    g_core.creatures.speed[id].current = 0;
    g_core.creatures.speed[id].max = 40;
    g_core.creatures.total++;

    return id;
}

void GetItemMetadata(HardwareInterface hardware, ObjectType* metadata, uint8_t type)
{
    if (type == SPELL_BOOK || type == SCROLL)
    {
        uint8_t spell_id = hardware.GetRandom_uint8_t(0, SPELL_COUNT);
        metadata->spell_id = spell_id;
    }
    else if (type == ABILITY_BOOK)
    {
        uint8_t ability_id = hardware.GetRandom_uint8_t(0, ABILITY_COUNT);
        metadata->AbilityId = ability_id;
    }
}

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type item
 *  //TODO: certain items will use metaData to store type of item, for example the spell ID of a spellbook
 *  //TODO: use 'l' to generate item of the appropriate level
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnItem(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
    if (type == NO_ITEM) return NO_ENTITY;

    EntityId id = NO_ENTITY;
    for (uint16_t i = 0; i < MAX_ENTITY_ITEM_COUNT; i++)
    {
        if (!GetBit(g_core.items.active, i))
        {
            id = i;
            SetBit(g_core.items.active, id, true);
            break;
        }
        if (i >= MAX_ENTITY_ITEM_COUNT - 1)
            return NO_ENTITY;
    }

    GetItemMetadata(hardware, &g_core.items.metaData[id], type);

    Position pos = {.x = x, .y = y};
    g_core.items.position[id] = pos;
    g_core.items.types[id] = type;
    SetBit(g_core.items.onMap, id, true);
    g_core.items.total++;
    return id;
}

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type object
 *  TODO - cahnge to a generic object spawner, we wll have 255 object types, shirne will be one
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnObject(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
    if (type == NO_OBJECT)
        return NO_ENTITY;

    EntityId id = NO_ENTITY;
    for (uint16_t i = 0; i < MAX_ENTITY_OBJECT_COUNT; i++)
    {
        if (!GetBit(g_core.objects.active, i))
        {
            id = i;
            SetBit(g_core.objects.active, id, true);
            break;
        }
        if (i >= MAX_ENTITY_OBJECT_COUNT - 1)
            return NO_ENTITY;
    }

    ObjectData objectData = {0};
    Flash_GetObjectData(memory, &objectData, type);

    SetBit(g_core.objects.onMap, id, true);
    SetBit(g_core.objects.interactable, id, objectData.interactable);
    Position pos = {.x = x, .y = y};
    g_core.objects.position[id] = pos;
    g_core.objects.types[id] = type;
    g_core.objects.metaData[id].value = (l + 10) + (l * 5);
    g_core.objects.total++;
    return id;
}

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type object
 *  TODO - cahnge to a generic object spawner, we wll have 255 object types, shirne will be one
**********************************************************************************************************************/
SET_MEMORY(".core")
void ClearSpellPage(EntityId id, uint8_t spellbook_idx)
{
    g_core.trainers.spellbook[id].page[spellbook_idx].spellData = (SpellData){0};
    g_core.trainers.spellbook[id].spell_id[spellbook_idx] = NO_SPELL;
}

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type object
 *  TODO - cahnge to a generic object spawner, we wll have 255 object types, shirne will be one
**********************************************************************************************************************/
SET_MEMORY(".core")
void AddSpellPage(MemoryInterface memory, EntityId id, Spell spell, uint8_t spellbook_idx)
{
    if (spell == NO_SPELL)
        return;

    Flash_GetSpellData(memory, &g_core.trainers.spellbook[id].page[spellbook_idx].spellData, spell);
    g_core.trainers.spellbook[id].page[spellbook_idx].pp = g_core.trainers.spellbook[id].page[spellbook_idx].spellData.pp;
    g_core.trainers.spellbook[id].spell_id[spellbook_idx] = spell;
    g_core.trainers.spellbook[id].occupied_pages++;
}

SET_MEMORY(".core")
EntityId SpawnTrainer(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
    if (type == NO_TRAINER) return NO_ENTITY;

    EntityId id = NO_ENTITY;
    for (uint16_t i = 0; i < MAX_ENTITY_TRAINER_COUNT; i++)
    {
        if (!GetBit(g_core.trainers.active, i))
        {
            id = i;

            SetBit(g_core.trainers.active, id, true);
            break;
        }

        if (i >= MAX_ENTITY_TRAINER_COUNT - 1)
            return NO_ENTITY;
    }

    SetBit(g_core.trainers.onMap, id, true);
    Position pos = {.x = x, .y = y};

    g_core.trainers.bag[id].occupied_slots = 0;
    g_core.trainers.bag[id].current_max_size = MAX_DEFAULT_TRAINER_ITEMS;


    TrainerData trainer_data = {0};
    Flash_GetTrainerData(memory, &trainer_data, type);

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (trainer_data.party[i] != NO_CREATURE)
        {
            EntityId e_id = SpawnEntity(hardware, memory, CREATURE, trainer_data.party[i], x, y, 5);
            g_core.trainers.partyID[id][i] = CaptureMonster(e_id);
        }
        else
        {
            g_core.trainers.partyID[id][i] = NO_ENTITY;
        }
    }


    g_core.trainers.spellbook[id] = (SpellBook){0};
    g_core.trainers.spellbook[id].current_max_pages = MAX_DEFAULT_TRAINER_SPELLS;
    for (uint8_t i = 0; i < MAX_SPELLBOOK_SIZE; i++)
        g_core.trainers.spellbook[id].spell_id[i] = NO_SPELL;

    for (uint8_t i = 0; i < MAX_DEFAULT_TRAINER_SPELLS; i++)
        AddSpellPage(memory, id, trainer_data.spells[i], i);


    for (uint8_t i = 0; i < MAX_BAG_SIZE; i++)
        g_core.trainers.itemID[id][i] = NO_ENTITY;

    for (uint8_t i = 0; i < MAX_DEFAULT_TRAINER_ITEMS; i++)
    {
        EntityId item_id = SpawnEntity(hardware, memory, ITEM, trainer_data.items[i], x, y, 0);
        PickItem(id, item_id);
    }


    g_core.trainers.position[id] = pos;
    g_core.trainers.types[id] = type;
    g_core.trainers.metaData[id].value = (l + 10) + (l * 5);

    SetBit(g_core.trainers.alive, id, true);
    SetBit(g_core.trainers.onMap, id, true);
    g_core.trainers.speed[id].current = 0;
    g_core.trainers.speed[id].max = 40;

    g_core.trainers.total++;
    return id;
}


/**********************************************************************************************************************
**  Sets initial data values of a given the type of object, the id of that type, position and level
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnEntity(HardwareInterface hardware, MemoryInterface memory, ObjectsTypes type, uint8_t t, uint8_t x, uint8_t y, uint8_t l)
{
    return spawn[type](hardware, memory, t, x, y, l);;
}
