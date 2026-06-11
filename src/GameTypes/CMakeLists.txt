add_library(GameTypes STATIC
        #   COMMON
        common/constants.h
        common/enums.h
        common/types.h


)


target_link_libraries(GameTypes
        PicoTypes
)

target_include_directories(GameTypes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/common
)


set_target_properties(GameTypes PROPERTIES LINKER_LANGUAGE C)
