//
// Created by nathanial on 5/19/26.
//
#include "core_ram.h"

#include "lib_memory.h"
#include "constants.h"

SET_MEMORY(".core.rodata")
uint16_t sounds_creatures[CREATURE_COUNT] = {
#include "inc/data_sounds_creature.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_skills[ABILITY_COUNT] = {
#include "inc/data_sounds_skill.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_spells[SPELL_COUNT] = {
#include "inc/data_sounds_spell.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_items[ITEM_COUNT] = {
#include "inc/data_sounds_item.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_objects[OBJECT_COUNT] = {
#include "inc/data_sounds_object.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_trainers[TRAINER_COUNT] = {
#include "inc/data_sounds_trainer.inc"
};
SET_MEMORY(".core.rodata")
uint16_t sounds_tiles[TILE_COUNT] = {
#include "inc/data_sounds_tile.inc"
};




SET_MEMORY(".core.data")
CoreRunState g_core = {
    .floor = 1,
    .initialized = false,
    .btns.defaultGameLoopRate = 10,
    .update_text = true,
    .update_right_inventory = true,
    .update_right_party = true,
    .update_right_text = true,
    .update_left_spellbook = true,
    .update_left_player = true,
    .update_left_text = true,
    .area_down_y = 416,
    // .player.currentSpellbookSize = 0,
    // .player.currentSpellbookMaxSize = DEFAULT_SPELLBOOK_SIZE,
    .player.vision_radius = DEFAULT_LIGHT_RADIUS,

    // .player.occupiedBagSlots = 0,
    // .player.currentBagMaxSize = DEFAULT_BAG_SIZE,

    .state.running = 1,
    .player.id = NO_ENTITY,
    .battleMode.enemy_trainer_id = NO_ENTITY,
};


uint8_t GetCreatureSoundId(uint8_t creature_id)
{
    return sounds_creatures[creature_id];
}

uint8_t GetSpellSoundId(uint8_t spell_id)
{
    return sounds_spells[spell_id];
}

uint8_t GetItemSoundId(uint8_t item_id)
{
    return sounds_items[item_id];
}

uint8_t GetTileSoundId(uint8_t tile_id)
{
    return sounds_tiles[tile_id];
}

uint8_t GetTrainerSoundId(uint8_t trainer_id)
{
    return sounds_trainers[trainer_id];
}

uint8_t GetObjectSoundId(uint8_t object_id)
{
    return sounds_objects[object_id];
}

uint8_t GetSkillSoundId(uint8_t skill_id)
{
    return sounds_skills[skill_id];
}

uint8_t GetMenuSoundId(MenuSounds mune_sound)
{
    return sounds_skills[mune_sound];
}
