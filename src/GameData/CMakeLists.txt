add_library(GameData STATIC
        overlay_data/data_rom.c
)


target_compile_definitions(PicoTypes PRIVATE CARTRIDGE_DATA CARTRIDGE)
#target_compile_definitions(GameTypes PRIVATE CARTRIDGE_DATA CARTRIDGE)


target_link_libraries(GameData
        PicoTypes
        GameTypes
)

target_include_directories(GameData PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)


set_target_properties(GameData PROPERTIES LINKER_LANGUAGE C)

