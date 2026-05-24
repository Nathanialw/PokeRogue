add_library(GameCore STATIC
        #   DATA
        overlay_data/data_rom.c


        #   COMMON
        common/constants.h
        common/enums.h
        common/types.h


        #   CORE
        overlay_core/core_memory_access.c
        overlay_core/core_ram.c
        overlay_core/core_actions.c
        overlay_core/core_map.c
        overlay_core/core_utils.c
        overlay_core/core_menu.c
        overlay_core/core_tiles.c
        overlay_core/core_graphics.c
        overlay_core/core_entities.c
        overlay_core/core_state.c
        overlay_core/core_player.c
        overlay_core/core_stats.c
        overlay_core/core_effects.c
        overlay_core/core_effects_items.c
        overlay_core/core_effects_spells.c
        overlay_core/core_save.c
        overlay_core/core_sound.c

        #   MAP
        overlay_map/map_camera.c
        overlay_map/map_ai.c
        overlay_map/map_movement.c
        overlay_map/map_actions.c
        overlay_map/map_ram.c
        overlay_map/map_collision.c
        overlay_map/map.c
        overlay_map/map_menu.c
        overlay_map/map_graphics.c
        overlay_map/map_memory_access.c
        overlay_map/map_entities.c
        overlay_map/map_animation.c
        overlay_map/map_state.c
        overlay_map/map_player.c
        overlay_map/map_stats.c
        overlay_map/map_rendering.c
        overlay_map/map_status_effects.c
        overlay_map/map_effects.c
        overlay_map/map_utils.c
        overlay_map/map_effects_objects.c


        #   BATTLES
        overlay_battle/battle_animation_skills_attack.c
        overlay_battle/battle_animation_spells_attack.c
        overlay_battle/battle_animation_items_attack.c
        overlay_battle/battle_animation_skills_struck.c
        overlay_battle/battle_animation_spells_struck.c
        overlay_battle/battle_animation_item_struck.c
        overlay_battle/battle_actions.c
        overlay_battle/battle_menu.c
        overlay_battle/battle_ram.c
        overlay_battle/battle_graphics.c
        overlay_battle/battle_memory_access.c
        overlay_battle/battle_entities.c
        overlay_battle/battle_animation.c
        overlay_battle/battle_state.c
        overlay_battle/battle_player.c
        overlay_battle/battle_stats.c
        overlay_battle/battle_animation_effects.c
        overlay_battle/battle_ui.c
        overlay_battle/battle_effects_skills.c


        #   SPLASH
        overlay_splash_screen/splash_ram.c
        overlay_splash_screen/splash_animation.c
        overlay_splash_screen/splash_state.c


        #   GENERATE_MAP
        overlay_generate_map/generate_map.c
        overlay_generate_map/generate_map_state.c
        overlay_map/tooltip.c
        overlay_map/tooltip.h
)


target_link_libraries(GameCore
        PicoTypes
)

target_include_directories(GameCore PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_core
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_battle
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_map
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_generate_map
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_populate_map
        ${CMAKE_CURRENT_SOURCE_DIR}/overlay_splash_screen
)


set_target_properties(GameCore PROPERTIES LINKER_LANGUAGE C)
