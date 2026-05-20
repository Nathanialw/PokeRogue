//
// Created by nathanial on 5/19/26.
//

#include "core_entities.h"
#include "lib_memory.h"

#include "enums.h"
#include "types.h"
#include "constants.h"

#include "core_memory_access.h"
#include "core_ram.h"


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
SET_MEMORY(".map.data")
static const char ppp1[] = "start";

SET_MEMORY(".map.data")
static const char ppp2[] = "done";

SET_MEMORY(".core")
void GetEntityTypes(MemoryInterface memory, uint8_t* typeIDs, const uint8_t* e_ids, ObjectsTypes type, uint8_t n, uint8_t offset)
{
    memory.Print(ppp1);
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

    memory.Print(ppp2);
}
