//
// Created by nathanial on 6/11/26.
//

#include "generate_map_memory_access.h"

#include "data_constants_memory.inc"
#include "lib_decl.h"
#include "lib_memory.h"
#include "types.h"



/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".mao_gen")
void Flash_GetTrainerData(MemoryInterface memory, TrainerData* trainer_data, TrainerId trainer_type)
{
    const uint8_t size = sizeof(TrainerData);
    memory.GetRom(GAME_DATA_TRAINER_POSITION + (trainer_type * size), trainer_data->bytes, size);
}
