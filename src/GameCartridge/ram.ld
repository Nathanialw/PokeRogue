MEMORY
{
    MAP(rx) : ORIGIN = 0x20000000, LENGTH = 128K
    BATTLE(rx) : ORIGIN = 0x20000000, LENGTH = 128K
    CAVE(rx) : ORIGIN = 0x20000000, LENGTH = 128K
    STRINGS(r) : ORIGIN = 0x20000000, LENGTH = 2M
    SPRITES(r) : ORIGIN = 0x20000000, LENGTH = 2M
}

SECTIONS
{
    .text : {
        __text_start__ = .;
        *(.text*)
        __text_end__ = .;
    } > RAM

    .rodata : { *(.rodata*) } > RAM
    .data   : { *(.data*)   } > RAM
    .bss    : {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    } > RAM

    end = __bss_end__;
}