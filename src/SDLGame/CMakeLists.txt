add_executable(SDLRogue
        main.c
        memory.c
        memory.h
        input.c
        input.h
        hardware.c
        hardware.h
        graphics.c
        graphics.h
        audio.c
        audio.h
        debug.c
        debug.h
)

target_compile_definitions(SDLRogue PRIVATE ENABLE_DEBUG_OUTPUT ENABLE_ASSERTS)


target_link_libraries(SDLRogue PRIVATE
        GameCore
        PicoTypes
        SDL3
)


target_include_directories(SDLRogue PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)


#cmake_minimum_required(VERSION 3.16)
#project(hello)
#
## set the output directory for built objects.
## This makes sure that the dynamic library goes into the build directory automatically.
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
#
## This assumes the SDL source is available in vendored/SDL
#add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
#
## Create your game executable target as usual
#add_executable(hello WIN32 hello.c)
#
## Link to the actual SDL3 library.
#target_link_libraries(hello PRIVATE )