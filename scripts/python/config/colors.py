#
#
# # custom palette defined in RGB565
# CUSTOM_PALETTE_565 = [
#     0xF81F, #// PAL_KEY(magenta)
#     0xEE9A, #// FG_PEACH_SKIN
#     0xA145, #// FG_MEDIUM_BROWN
#     0x8FE4, #// FG_PALE_GREEN
#     0x4A60, #// FG_GRAYISH_GREEN
#     0x8E60, #// FG_DIRTY_YELLOW_GRN
#     0xCA20, #// FG_BROWNISH_RED
#     0xDDE0, #// FG_LIGHT_TAN
#     0x8418, #// FG_GRAY_BLUE
#     0xF9A0, #// FG_DULL_ORANGE
#     0x6200, #// FG_DARK_BROWN
#     0x03A0, #// FG_MUTED_GREEN
#     0x0220, #// FG_DARK_GRAY_GREEN
#     0x8A20, #// FG_GRAY_BROWN
#     0xBDD7, #// FG_LIGHT_GRAY
#     0xD340, #// FG_TAN_BROWN
#
#       #         // 16–31
#     #Forest / nature
#     0x07E0, #// FG_BRIGHT_LIGHT_GRN
#     0x03C0, #// FG_DEEP_FOREST_GRN
#     0x05E0, #// FG_VIVID_GREEN
#     0x06E0, #// FG_LIME_GREEN
#     0x9FC8, #// FG_PASTEL_GREEN
#     0x0120, #// FG_VERY_DARK_GREEN
#     0x4A40, #// FG_DARK_OLIVE
#     0x5B20, #// FG_GRAY_GREEN
#     0x8A40, #// FG_BROWN_GREEN
#     0xD5E0, #// FG_TAN_GREEN
#     0x03E0, #// FG_EMERALD_GREEN
#     0x0200, #// FG_DARK_GRN_BLACK
#     0x0460, #// FG_SICKLY_GREEN
#     0x9FE8, #// FG_PALE_MINT
#     0x04E0, #// FG_BRIGHT_VINE_GRN
#     0x8C60, #// FG_PURPLE_GREEN
#
#      #          // 32–47
#     #Fire / warm
#     0xF9E4, #// FG_ORANGISH_RED
#     0xFD60, #// FG_BRIGHT_ORANGE
#     0xF800, #// FG_RED_ORANGE
#     0xF000, #// FG_DEEP_RED
#     0xF81C, #// FG_FIERY_MAGENTA(adjusted)
#     0xA000, #// FG_DARK_RED
#     0xF804, #// FG_BRIGHT_RED
#     0x8000, #// FG_BLACK_RED
#     0xC920, #// FG_REDDISH_BROWN(shifted)
#     0xF5A0, #// FG_SANDY_ORANGE
#     0xE7E0, #// FG_GREEN_ORANGE(fixed
#     #to
#     #actual
#     #yellow - orange)
#     0xD320, #// FG_TAN_RED(shifted)
#     0xF9C0, #// FG_BRIGHT_ORN_RED
#     0xFDA0, #// FG_GLOWING_ORANGE
#     0xFFE0, #// FG_YELLOW_ORN_RED
#     0xF960, #// FG_DARK_ORANGE
#
#      #          // 48–63
#     # cold / magic
#     0xC618, #// FG_OFF_WHITE_GRAY
#     0x8FC8, #// FG_SICKLY_GRN_GRAY
#     0x781C, #// FG_PALE_BLU_PURP
#     0x700C, #// FG_DARK_PURP_RED
#     0xFFFF, #// FG_WHITE_BLUE
#     0x4208, #// FG_DARK_BLUE_GRAY
#     0x07DF, #// FG_PALE_CYAN
#     0x041F, #// FG_ICE_BLUE
#     0xfea0, #// FG_LIGHT_CYAN
#     0x05FF, #// FG_BRIGHT_CYAN
#     0x001F, #// FG_DEEP_BLUE
#     0x701F, #// FG_DARK_BLU_PURP
#     0x03FF, #// FG_TEAL
#     0xF01F, #// FG_PURPLE_BLUE
#     0x7818, #// FG_MEDIUM_PURPLE
#     0x680F  #// FG_DEEP_VIOLET
# ]
#





PALETTE_4 = [
    0xF81F, # magenta key
    0xDDE0, # light tan
    0x6200, # dark brown
    0x4208  # dark blue gray
]


PALETTE_8 = [
    0xF81F, # key
    0xDDE0, # light tan
    0xEE9A, # peach skin
    0x6200, # dark brown
    0x8418, # gray blue
    0x03A0, # muted green
    0xF000, # deep red
    0xFFFF  # white blue
]


PALETTE_16 = [
    0xF81F, # // 0 - Magenta            0xF81F,
    0xCE59, # // 1 - Medium Gray        0xEE9A,
    0xEFBF, # // 2 - Alice Blue         ZOMBIE_SHAMBLER,
    0xE9A4, # // 3 - Dark Red           0xDDE0,
    0xF3AE, # // 4 - Pinkish            0x6200,
    0x49B2, # // 5 - Dark Brown         0x8418,
    0xA511, # // 6 - Brown/Orange       0xBDD7,
    0xF586, # // 7 - Orange             0x03A0,
    0xFBAD, # // 8 - Light Yellow       0x0220,
    0x14A7, # // 9 - Dark Teal          0x07E0,
    0x2244, # // 10 - Green             0xF000,
    0x5673, # // 11 - Light Green       0xFD60,
    0x08C5, # // 12 - Very Dark Blue    0xF9A0,
    0x02C1, # // 13 - Medium Blue       0x001F,
    0x1D71, # // 14 - Bright Blue       0x07DF,
    0xDEDB,  # // 15 - Light Cyan/Blue  0xFFFF,
]

PALETTE_32 = [
# base 16
    0xF81F,0xEE9A,0xA145,0xDDE0,
    0x6200,0x8418,0xBDD7,0x03A0,
    0x0220,0x07E0,0xF000,0xFD60,
    0xF9A0,0x001F,0x07DF,0xFFFF,

    # greens
    0x03C0,0x05E0,0x06E0,0x9FC8,
    0x4A40,0x5B20,0x8A40,0xD5E0,

    # warm colors
    0xF9E4,0xF800,0xA000,0xF804,
    0xC920,0xF5A0,0xD320,0xF9C0
]

PALETTE_64 = [
    0xF81F,0xEE9A,0xA145,0x8FE4,0x4A60,0x8E60,0xCA20,0xDDE0,
    0x8418,0xF9A0,0x6200,0x03A0,0x0220,0x8A20,0xBDD7,0xD340,

    0x07E0,0x03C0,0x05E0,0x06E0,0x9FC8,0x0120,0x4A40,0x5B20,
    0x8A40,0xD5E0,0x03E0,0x0200,0x0460,0x9FE8,0x04E0,0x8C60,

    0xF9E4,0xFD60,0xF800,0xF000,0xF81C,0xA000,0xF804,0x8000,
    0xC920,0xF5A0,0xE7E0,0xD320,0xF9C0,0xFDA0,0xFFE0,0xF960,

    0xC618,0x8FC8,0x781C,0x700C,0xFFFF,0x4208,0x07DF,0x041F,
    0xFEA0,0x05FF,0x001F,0x701F,0x03FF,0xF01F,0x7818,0x680F
]


PALETTE_256 = [

    0xefbf,	#aliceblue
    0xf75a,	#antiquewhite
    0x07ff,	#aqua
    0x7ffa,	#aquamarine
    0xefff,	#azure
    0xf7bb,	#beige
    0xff18,	#bisque
    0x0000,	#black
    0xff59,	#blanchedalmond
    0x001f,	#blue
    0x897b,	#blueviolet
    0xa145,	#brown
    0xddb0,	#burlywood
    0x64f3,	#cadetblue
    0x7fe0,	#chartreuse
    0xd344,	#chocolate
    0xfbea,	#coral
    0x64bd,	#cornflowerblue
    0xffbb,	#cornsilk
    0xd8a7,	#crimson
    0x07ff,	#cyan
    0x0011,	#darkblue
    0x0451,	#darkcyan
    0xb421,	#darkgoldenrod
    0xad55,	#darkgray
    0x0320,	#darkgreen
    0xad55,	#darkgrey
    0xbdad,	#darkkhaki
    0x8811,	#darkmagenta
    0x5346,	#darkolivegreen
    0xfc60,	#darkorange
    0x9999,	#darkorchid
    0x8800,	#darkred
    0xe4af,	#darksalmon
    0x8dd1,	#darkseagreen
    0x49f1,	#darkslateblue
    0x328a,	#darkslategray
    0x328a,	#darkslategrey
    0x0679,	#darkturquoise
    0x901a,	#darkviolet
    0xf8b2,	#deeppink
    0x05ff,	#deepskyblue
    0x6b4d,	#dimgray
    0x6b4d,	#dimgrey
    0x249f,	#dodgerblue
    0xb104,	#firebrick
    0xffdd,	#floralwhite
    0x2444,	#forestgreen
    0xf81f,	#fuchsia
    0xdedb,	#gainsboro
    0xf7bf,	#ghostwhite
    0xfea0,	#gold
    0xdd24,	#goldenrod
    0x8410,	#gray
    0x0400,	#green
    0xafe6,	#greenyellow
    0x8410,	#grey
    0xeffd,	#honeydew
    0xfb56,	#hotpink
    0xcaeb,	#indianred
    0x4810,	#indigo
    0xfffd,	#ivory
    0xef31,	#khaki
    0xe73e,	#lavender
    0xff7e,	#lavenderblush
    0x7fc0,	#lawngreen
    0xffd9,	#lemonchiffon
    0xaebc,	#lightblue
    0xec10,	#lightcoral
    0xdfff,	#lightcyan
    0xf7da,	#lightgoldenrodyellow
    0xd69a,	#lightgray
    0x9772,	#lightgreen
    0xd69a,	#lightgrey
    0xfdb7,	#lightpink
    0xfd0f,	#lightsalmon
    0x2595,	#lightseagreen
    0x867e,	#lightskyblue
    0x7453,	#lightslategray
    0x7453,	#lightslategrey
    0xae1b,	#lightsteelblue
    0xfffb,	#lightyellow
    0x07e0,	#lime
    0x3666,	#limegreen
    0xf77c,	#linen
    0xf81f,	#magenta
    0x8000,	#maroon
    0x6675,	#mediumaquamarine
    0x0019,	#mediumblue
    0xbaba,	#mediumorchid
    0x939b,	#mediumpurple
    0x3d8e,	#mediumseagreen
    0x7b5d,	#mediumslateblue
    0x07d3,	#mediumspringgreen
    0x4e99,	#mediumturquoise
    0xc0b0,	#mediumvioletred
    0x18ce,	#midnightblue
    0xf7fe,	#mintcream
    0xff1b,	#mistyrose
    0xff16,	#moccasin
    0xfef5,	#navajowhite
    0x0010,	#navy
    0xffbc,	#oldlace
    0x8400,	#olive
    0x6c64,	#olivedrab
    0xfd20,	#orange
    0xfa20,	#orangered
    0xdb9a,	#orchid
    0xef35,	#palegoldenrod
    0x97d2,	#palegreen
    0xaf7d,	#paleturquoise
    0xdb92,	#palevioletred
    0xff7a,	#papayawhip
    0xfed6,	#peachpuff
    0xcc28,	#peru
    0xfdf9,	#pink
    0xdd1b,	#plum
    0xaefc,	#powderblue
    0x8010,	#purple
    0xf800,	#red
    0xbc71,	#rosybrown
    0x435b,	#royalblue
    0x8a22,	#saddlebrown
    0xf40e,	#salmon
    0xf52c,	#sandybrown
    0x344b,	#seagreen
    0xffbd,	#seashell
    0x9a85,	#sienna
    0xbdf7,	#silver
    0x867d,	#skyblue
    0x6ad9,	#slateblue
    0x7412,	#slategray
    0x7412,	#slategrey
    0xffde,	#snow
    0x07ef,	#springgreen
    0x4c16,	#steelblue
    0xd591,	#tan
    0x0410,	#teal
    0xd5fa,	#thistle
    0xfb09,	#tomato
    0x46f9,	#turquoise
    0xec1d,	#violet
    0xf6f6,	#wheat
    0xffff,	#white
    0xf7be,	#whitesmoke
    0xffe0,	#yellow
    0x9e66,	#yellowgreen
]

PALETTES = {
    4:  PALETTE_4,
    8:  PALETTE_8,
    16: PALETTE_16,
    32: PALETTE_32,
    64: PALETTE_64,
    256: PALETTE_256,
}

NUM_COLORS = 16      # used only if MODE == "optimum"
CUSTOM_PALETTE_565 = PALETTES[NUM_COLORS]