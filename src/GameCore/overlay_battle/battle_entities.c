//
// Created by nathanial on 5/19/26.
//

#include "battle_entities.h"
#include "lib_memory.h"

#include "types.h"

#include "core_ram.h"
#include "core_utils.h"


/**Returns true if the given entity is Alive
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckAlive(EntityId id)
{
    return GetBit(g_core.creatures.active, id);
}


