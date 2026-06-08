//
// Created by nathanial on 5/19/26.
//

#include "core_entities.h"
#include "lib_memory.h"

#include "enums.h"
#include "types.h"
#include "constants.h"

#include "core_memory_access.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"


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
EntityId PickItem(EntityId id)
{
    Position empty_pos = {.x = 0, .y = 0};
    g_core.items.position[id] = empty_pos;
    SetBit(g_core.items.onMap, id, false);
    return id;
}

SET_MEMORY(".core")
bool AddCreatureToParty(EntityId creature_id)
{
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
    {
        if (g_core.trainers.partyID[GetPlayerID()][i] == NO_ENTITY)
        {
            g_core.trainers.partyID[GetPlayerID()][i] = creature_id;
            return true;
        }
    }
    return false;
}

/**********************************************************************************************************************/
/**Reset all values of the given entity ID
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyCreature(EntityId id)
{
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
const Spawn spawn[TOTAL_SPAWNABLE_OBJECT_TYPES] = {SpawnMonster, SpawnObject, SpawnItem, SpawnTrainer};

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type creature
*   TODO - get all values from the db data or generate them
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnMonster(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
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
        {
            return NO_ENTITY;
        }
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

    GetSkills(memory, id, type);
    SetBit(g_core.creatures.alive, id, true);
    SetBit(g_core.creatures.onMap, id, true);
    g_core.creatures.speed[id].current = 0;
    g_core.creatures.speed[id].max = 40;
    g_core.creatures.total++;

    return id;
}

/**********************************************************************************************************************/
/** Sets initial data values of a given entity ID of type item
 *  //TODO: certain items will use metaData to store type of item, for example the spell ID of a spellbook
 *  //TODO: use 'l' to generate item of the appropriate level
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId SpawnItem(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
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
        {
            return NO_ENTITY;
        }
    }

    Position pos = {.x = x, .y = y};
    g_core.items.position[id] = pos;
    g_core.items.types[id] = type;
    SetBit(g_core.items.onMap, id, true);
    g_core.items.metaData[id].value = (l + 10) + (l * 5);
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
        {
            return NO_ENTITY;
        }
    }

    SetBit(g_core.objects.onMap, id, true);
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
EntityId SpawnTrainer(HardwareInterface hardware, MemoryInterface memory, uint8_t type, uint8_t x, uint8_t y, uint8_t l)
{
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
        {
            return NO_ENTITY;
        }
    }

    SetBit(g_core.trainers.onMap, id, true);
    Position pos = {.x = x, .y = y};

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; i++)
        g_core.trainers.partyID[id][i] = NO_ENTITY;

    for (uint8_t i = 0; i < MAX_BAG_SIZE; i++)
        g_core.trainers.itemID[id][i] = NO_ENTITY;

    for (uint8_t i = 0; i < MAX_SPELLBOOK_SIZE; i++)
        g_core.trainers.spellID[id][i] = NO_SPELL; //spells are no entities


    //  TODO: load trainer spell data from the database flash
    g_core.trainers.spellID[id][0] = HEAL;
    g_core.trainers.spellID[id][1] = DESCEND;
    g_core.trainers.spellID[id][2] = CLAIRVOYANCE;
    g_core.trainers.spellID[id][3] = DISPLACEMENT;

    //  TODO: set party from trainer data in the database flash
    EntityId e_id = SpawnEntity(hardware, memory, CREATURE, BANSHEE, x, y, 5);
    g_core.trainers.partyID[id][0] = CaptureMonster(e_id);

    g_core.trainers.position[id] = pos;
    g_core.trainers.types[id] = type;
    g_core.trainers.metaData[id].value = (l + 10) + (l * 5);

    SetBit(g_core.trainers.alive, id, true);
    SetBit(g_core.trainers.onMap, id, true);
    g_core.trainers.speed[id].current = 0;
    g_core.trainers.speed[id].max = 40;


    //  TODO: set from trainer data in the database flash
    EntityId item_id = SpawnEntity(hardware, memory, ITEM, POTION_VISION, x, y, 0);
    PlayerPickItem(id, item_id);

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
