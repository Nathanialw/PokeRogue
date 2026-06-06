//
// Created by nathanial on 5/19/26.
//

#include "map_actions.h"

#include "lib_decl.h"
#include "lib_memory.h"
#include "types.h"

#include "core_memory_access.h"
#include "core_ram.h"
#include "core_entities.h"

#include "map_memory_access.h"



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id)
{
    if (object_e_id == NO_ENTITY) return false;
    Object object_type = GetObjectType(object_e_id);
    ObjectData object_data;
    Flash_GetObjectData(memory, &object_data, object_type);
    return Flash_GetObjectEffect(memory, hardware, object_type, object_e_id, e_id, object_data);
}

