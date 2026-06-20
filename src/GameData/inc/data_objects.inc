// Generated object data structs
// Database contains 106 total objects

//       8  bits - .power = { 8 bits } 
//    2x 4  bits - .data  = { .object_type = { 4 bits }, .level = { 4 bits } }
//       16 bits - .flags = { _pad0, _pad1, consumable_spellbook, consumable_party, room_center, against_wall, on_wall, corner, water_adjacent, map_generatable, .water, .nook,  .hallway, .on_step, .interactable, .consumable, consumable_party, consumable_spellbook  }

// total 4 bytes
// Individual objects data - count = 106
//    0 - ALTAR
{ .power = 0x64, .data = 0x01, .flags = 0b0001000001000010 },
//    1 - ANVIL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    2 - BANNER_ELF
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    3 - BANNER_GOBLIN
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    4 - BANNER_ORC
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    5 - BAPTISMAL_FONT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    6 - BED_COT
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000001 },
//    7 - BED_SINGLE
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000001 },
//    8 - BED_TENT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000001 },
//    9 - BELL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    10 - BOMB_TNT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    11 - CABINET_BOOK
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011 },
//    12 - CABINET_JEWELLERY
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011 },
//    13 - CABINET_SCROLL
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011 },
//    14 - CAULDRON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    15 - COFFIN_COFFIN
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001010011 },
//    16 - COFFIN_SARCOPHAGUS
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001010011 },
//    17 - CONFESSIONAL_TREE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    18 - CORPSE_CRUCIFIED
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    19 - CORPSE_HANGING
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    20 - CORPSE_IMPALED
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    21 - CORPSE_LAID
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    22 - DOOR_BARRED
{ .power = 0x04, .data = 0x01, .flags = 0b0000000001001110 },
//    23 - DOOR_IRON
{ .power = 0x03, .data = 0x01, .flags = 0b0000000001001110 },
//    24 - DOOR_JAILBAR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001110 },
//    25 - DOOR_STONE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001110 },
//    26 - DOOR_WICKER
{ .power = 0x01, .data = 0x01, .flags = 0b0000000001001110 },
//    27 - DOOR_WOOD
{ .power = 0x02, .data = 0x01, .flags = 0b0000000001001110 },
//    28 - EGRESS_CAVE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101010010 },
//    29 - EGRESS_LADDER
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101000010 },
//    30 - EGRESS_ROPE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101000010 },
//    31 - EGRESS_STAIRS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    32 - FIRE_BONFIRE
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001000010 },
//    33 - FIRE_BRAZIER
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001000010 },
//    34 - FIRE_CAMPFIRE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000010 },
//    35 - FIRE_PYRE
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010 },
//    36 - FIRE_STANDING_TORCH
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    37 - FIRE_WALL_TORCH
{ .power = 0x64, .data = 0x01, .flags = 0b0000001001000010 },
//    38 - FORGE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    39 - FOUNTAIN_ACID
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    40 - FOUNTAIN_BLOOD
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    41 - FOUNTAIN_OOZE
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    42 - FOUNTAIN_WATER
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    43 - GEODE_CRYSTAL
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011 },
//    44 - HEADING_BLOCK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    45 - HIGH_CROSS
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    46 - ICE_BOX
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000001 },
//    47 - IDOL_OF_HERNE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    48 - INSCRIPTION
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    49 - LOOM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    50 - METEORITE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    51 - MIRROR_REVERSAL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    52 - MIRROR_STANDING
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    53 - OBELISK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    54 - PAD_DISPLACEMENT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    55 - PAD_TELEPORT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010 },
//    56 - PALANTIR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    57 - POOL_REFLECTION
{ .power = 0x05, .data = 0x01, .flags = 0b0010000001000011 },
//    58 - PORTAL_ALFHEIM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    59 - PORTAL_ATLANTIS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    60 - PORTAL_ELYSIUM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    61 - PORTAL_HEL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    62 - PORTAL_JOTUNHEIM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    63 - PORTAL_MAGE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000000 },
//    64 - PORTAL_OLYMPUS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    65 - PORTAL_TAKAMA
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    66 - PORTAL_TARTARUS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    67 - PORTAL_VALHALLA
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010 },
//    68 - POT_OF_GOLD
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    69 - RACK_ARMOR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    70 - RACK_WEAPON
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    71 - SHIPWRECK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000011 },
//    72 - SHRINE_MINERVA
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    73 - SHRINE_POSEIDON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    74 - SHRINE_SAINT_MARY
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001 },
//    75 - SIGIL_PENTAGRAM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    76 - STATUE_EXPLORER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010 },
//    77 - STATUE_HERO
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010 },
//    78 - STATUE_KING
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010 },
//    79 - STATUE_WEEPING
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    80 - STILL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011 },
//    81 - SUNDIAL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },
//    82 - TORTURE_CUCKING_STOOL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000011000011 },
//    83 - TORTURE_RACK
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    84 - TORTURE_STOCKS
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    85 - TORTURE_STRAPPADO
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    86 - TORTURE_WHIPPING_POST
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    87 - TREASURE_BARREL
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011 },
//    88 - TREASURE_BASKET
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011 },
//    89 - TREASURE_CHEST
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011 },
//    90 - TREASURE_COFFER
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011 },
//    91 - TREASURE_CRATE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011 },
//    92 - TREASURE_TRUNK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011 },
//    93 - TREASURE_URN
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011 },
//    94 - TREASURE_VAULT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011 },
//    95 - VEIN_COPPER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    96 - VEIN_GOLD
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    97 - VEIN_IRON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    98 - VEIN_SILVER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    99 - VEIN_TIN
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    100 - WAGON_BROKEN
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000001 },
//    101 - WARD
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001100 },
//    102 - WAYSTONE
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011 },
//    103 - WELL
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    104 - WELL_ANCIENT
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011 },
//    105 - WICKER_MAN
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011 },

//COUNT = 106;
