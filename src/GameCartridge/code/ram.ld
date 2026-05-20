/*
1MB	    1,048,576	0x00100000	0x0FFFFF (1,048,575)
2MB	    2,097,152	0x00200000	0x1FFFFF
4MB	    4,194,304	0x00400000	0x3FFFFF
8MB	    8,388,608	0x00800000	0x7FFFFF
16MB	16,777,216	0x01000000	0xFFFFFF (16,777,215)
16MB	16,777,216	0x02000000	0xFFFFFF
32MB	16,777,216	0x04000000	0xFFFFFF
64MB	16,777,216	0x08000000	0xFFFFFF
128MB	16,777,216	0x10000000	0xFFFFFF
256MB	16,777,216	0x20000000	0xFFFFFF
*/

/*16MB is used right now 16777216*/
MEMORY
{
    RAM (rwx) : ORIGIN = 0x20010000, LENGTH = 4M
}

SECTIONS
{
    /* Start at address 0 */
    . = 0x000000;

    .core 0x20000000 : AT(0x0000000)   /* example cartridge address */
    {
        KEEP(*(.core))
        KEEP(*(.core.text))    /* code */
        KEEP(*(.core.rodata))  /* read‑only data (strings, const) */
        KEEP(*(.core.data))    /* initialised data (if any) */
        KEEP(*(.core.bss))     /* zero‑initialised data (if any) */
        . = ALIGN(4);
    }

    .splash 0x20010000 : AT(0x020000)
    {
        KEEP(*(.splash_entry))   /* must come first */
        KEEP(*(.splash.text))    /* code */
        KEEP(*(.splash.rodata))  /* read‑only data (strings, const) */
        KEEP(*(.splash.data))    /* initialised data (if any) */
        KEEP(*(.splash.bss))     /* zero‑initialised data (if any) */
        KEEP(*(.splash))
        . = ALIGN(4);
    }

    .map 0x20010000 : AT(0x030000)
    {
        KEEP(*(.map_entry))
        KEEP(*(.map.text))    /* code */
        KEEP(*(.map.rodata))  /* read‑only data (strings, const) */
        KEEP(*(.map.data))    /* initialised data (if any) */
        KEEP(*(.map.bss))     /* zero‑initialised data (if any) */
        KEEP(*(.map))
        . = ALIGN(4);
    }

    .map_gen 0x20010000 : AT(0x040000)
    {
        KEEP(*(.map_gen_entry))
        KEEP(*(.map_gen.text))    /* code */
        KEEP(*(.map_gen.rodata))  /* read‑only data (strings, const) */
        KEEP(*(.map_gen.data))    /* initialised data (if any) */
        KEEP(*(.map_gen.bss))     /* zero‑initialised data (if any) */
        KEEP(*(.map_gen))
        . = ALIGN(4);
    }

    /* Battle / Map Overlays */
    .battle 0x20010000 : AT(0x050000)
    {
        KEEP(*(.battle_entry))
        KEEP(*(.battle.text))    /* code */
        KEEP(*(.battle.rodata))  /* read‑only data (strings, const) */
        KEEP(*(.battle.data))    /* initialised data (if any) */
        KEEP(*(.battle.bss))     /* zero‑initialised data (if any) */
        KEEP(*(.battle))
        . = ALIGN(4);
    }




    /* This is the critical one */
/*    . = 0x650000;*/
/*    .sprites_objects    0x900000 : { KEEP(*(.sprites_objects))    . = ALIGN(4); }*/

    __rom_end = .;
    end = .;
}
