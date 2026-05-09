add_executable(GameCartridge
        main.c
)

target_link_options(GameCartridge PRIVATE "--specs=nosys.specs")
target_link_libraries(GameCartridge
        "-Wl,--whole-archive"
        GameCore
        PicoTypes
        "-Wl,--no-whole-archive"
)

pico_set_binary_type(GameCartridge no_flash)
#pico_add_extra_outputs(GameCartridge) # This generates cartridge_main.bin
# Configure the *existing* GameCore library to output a raw binary

target_link_options(GameCartridge PRIVATE "-T${CMAKE_CURRENT_SOURCE_DIR}/ram.ld")