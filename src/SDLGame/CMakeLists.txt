add_executable(SDLRogue
        main.c
)


target_link_libraries(SDLRogue
        GameCore
)


target_include_directories(SDLRogue PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)




