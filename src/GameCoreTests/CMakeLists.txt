add_executable(GameCoreTests
        main.c
        map.c
        test_objects.c
        combat_tests.c
        creatures.c
        animation_tests.c
        hash_map_tests.c
        utils_tests.c
)

target_compile_definitions(GameCoreTests PRIVATE ENABLE_DEBUG_OUTPUT ENABLE_ASSERTS SDL)
target_compile_definitions(GameCore PRIVATE ENABLE_DEBUG_OUTPUT ENABLE_ASSERTS)

target_link_libraries(GameCoreTests
        PicoTypes
        GameCore
        SDL3::SDL3-static
        stdc++
)

target_include_directories(GameCoreTests PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)

