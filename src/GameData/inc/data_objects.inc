// Generated object data structs
// Database contains 108 total objects

//       8  bits - .power = { 8 bits } 
//    2x 4  bits - .data  = { .object_type = { 4 bits }, .level = { 4 bits } }
//       16 bits - .flags = { _pad0, _pad1, consumable_spellbook, consumable_party, room_center, against_wall, on_wall, corner, water_adjacent, map_generatable, .water, .nook,  .hallway, .on_step, .interactable, .consumable, consumable_party, consumable_spellbook  }

//       64 bits - .effects = { .effects = [ { 8 bits x 6 } ], .chance { 16 bits } } 
// total 12 bytes
// Individual objects data - count = 108

//    0 - ALTAR
{ .power = 0x64, .data = 0x01, .flags = 0b0001000001000010, .effects = { .effects = { EFFECT_SACRIFICE_CREATURE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    1 - BANNER_ELF
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001, .effects = { .effects = { EFFECT_RAISE_AGILITY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    2 - BANNER_GOBLIN
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001, .effects = { .effects = { EFFECT_RAISE_DEXTERITY     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    3 - BANNER_ORC
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000001, .effects = { .effects = { EFFECT_RAISE_STRENGTH      , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    4 - BAPTISMAL_FONT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_RAISE_PIETY_CATHOLIC, NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    5 - BED_COT
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_REST                , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    6 - BED_SINGLE
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_REST                , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    7 - BED_TENT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000011, .effects = { .effects = { EFFECT_REST                , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    8 - BELL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    9 - BOAT_RAFT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001100100, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    10 - BOAT_ROWBOAT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001100100, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    11 - BOMB_TNT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    12 - CABINET_BOOK
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_BOOK    , EFFECT_CREATE_ITEM_SCROLL  , EFFECT_NO_OBJECT_EFFECT    , EFFECT_NO_OBJECT_EFFECT    , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(3, 1, 0, 0, 0, 0) } },
//    13 - CABINET_JEWELLERY
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_MAGIC   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    14 - CABINET_SCROLL
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_SCROLL  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    15 - CAULDRON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_POTION  , EFFECT_SUMMON_HAG          , EFFECT_MELT_ITEM_RANDOM    , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    16 - COFFIN_COFFIN
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    17 - COFFIN_SARCOPHAGUS
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    18 - CONFESSIONAL_TREE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_RAISE_PIETY_CATHOLIC, NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    19 - CORPSE_CRUCIFIED
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    20 - CORPSE_HANGING
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    21 - CORPSE_IMPALED
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    22 - CORPSE_LAID
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_ZOMBIE       , EFFECT_SUMMON_SKELETON     , EFFECT_SUMMON_SKELETON     , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(3, 1, 1, 1, 0, 0) } },
//    23 - DOOR_BARRED
{ .power = 0x04, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    24 - DOOR_IRON
{ .power = 0x03, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    25 - DOOR_JAILBAR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    26 - DOOR_STONE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    27 - DOOR_WICKER
{ .power = 0x01, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    28 - DOOR_WOOD
{ .power = 0x02, .data = 0x01, .flags = 0b0000000001001110, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    29 - EGRESS_CAVE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101010010, .effects = { .effects = { EFFECT_LATERAL_ONE_LEVEL   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    30 - EGRESS_LADDER
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101000010, .effects = { .effects = { EFFECT_ASCEND_ONE_LEVEL    , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    31 - EGRESS_ROPE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000101000010, .effects = { .effects = { EFFECT_ASCEND_ONE_LEVEL    , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    32 - EGRESS_STAIRS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010, .effects = { .effects = { EFFECT_DESCEND_ONE_LEVEL   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    33 - FIRE_BONFIRE
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    34 - FIRE_BRAZIER
{ .power = 0x64, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    35 - FIRE_CAMPFIRE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    36 - FIRE_PYRE
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    37 - FIRE_STANDING_TORCH
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    38 - FIRE_WALL_TORCH
{ .power = 0x64, .data = 0x01, .flags = 0b0000001001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    39 - FORGE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010, .effects = { .effects = { EFFECT_SMELT_ORE           , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    40 - FOUNTAIN_ACID
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_RESTORE_MP          , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    41 - FOUNTAIN_BLOOD
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_RESTORE_MP          , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    42 - FOUNTAIN_OOZE
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_RESTORE_MP          , EFFECT_SUMMON_OOZE         , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    43 - FOUNTAIN_WATER
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_RESTORE_MP          , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    44 - GEODE_CRYSTAL
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_CREATE_ORE_CRYSTAL  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    45 - HEADING_BLOCK
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_SACRIFICE_CREATURE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    46 - HIGH_CROSS
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_SUMMON_ANGEL        , EFFECT_RAISE_PIETY_CATHOLIC, EFFECT_SUMMON_DEMON        , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    47 - ICE_BOX
{ .power = 0x05, .data = 0x01, .flags = 0b0000010001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_FOOD    , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    48 - IDOL_OF_HERNE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    49 - INSCRIPTION
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    50 - LOOM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    51 - METEORITE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ORE_CRYSTAL  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    52 - MIRROR_REVERSAL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    53 - MIRROR_STANDING
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , EFFECT_LOWER_INTELLIGENCE  , EFFECT_NO_OBJECT_EFFECT    , EFFECT_NO_OBJECT_EFFECT    , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    54 - OBELISK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    55 - PAD_DISPLACEMENT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    56 - PAD_TELEPORT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000010, .effects = { .effects = { EFFECT_DISPLACEMENT        , EFFECT_DESCEND_ONE_LEVEL   , EFFECT_ASCEND_ONE_LEVEL    , EFFECT_LATERAL_ONE_LEVEL   , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 1, 0, 0) } },
//    57 - PALANTIR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_SHOW_MAP            , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    58 - POOL_REFLECTION
{ .power = 0x05, .data = 0x01, .flags = 0b0010000001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , EFFECT_MELT_ITEM_RANDOM    , EFFECT_DESCEND_ONE_LEVEL   , EFFECT_RESTORE_MP          , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 1, 0, 0) } },
//    59 - PORTAL_ALFHEIM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    60 - PORTAL_ATLANTIS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    61 - PORTAL_ELYSIUM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    62 - PORTAL_HEL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    63 - PORTAL_JOTUNHEIM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    64 - PORTAL_MAGE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    65 - PORTAL_OLYMPUS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    66 - PORTAL_TAKAMA
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    67 - PORTAL_TARTARUS
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    68 - PORTAL_VALHALLA
{ .power = 0x05, .data = 0x01, .flags = 0b0000000000000010, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    69 - POT_OF_GOLD
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , EFFECT_SUMMON_LEPRECHAUN   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    70 - RACK_ARMOR
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    71 - RACK_WEAPON
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    72 - SHIPWRECK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000011000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    73 - SHRINE_MINERVA
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    74 - SHRINE_POSEIDON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    75 - SHRINE_SAINT_MARY
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    76 - SIGIL_PENTAGRAM
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_SUMMON_DEMON        , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    77 - STATUE_EXPLORER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , EFFECT_RAISE_STAMINA       , EFFECT_GAIN_BAG_SLOT       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    78 - STATUE_HERO
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , EFFECT_RAISE_STRENGTH      , EFFECT_RAISE_FORTITUDE     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    79 - STATUE_KING
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000010, .effects = { .effects = { EFFECT_RAISE_STRENGTH      , EFFECT_RAISE_FORTITUDE     , EFFECT_RAISE_INTELLIGENCE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 1, 0, 0, 0) } },
//    80 - STATUE_WEEPING
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    81 - STATUE_WIZARD
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , EFFECT_GAIN_SPELL_PAGE     , EFFECT_NO_OBJECT_EFFECT    , EFFECT_NO_OBJECT_EFFECT    , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    82 - STILL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_POTION  , EFFECT_RAISE_STAMINA       , EFFECT_NO_OBJECT_EFFECT    , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 1, 0, 0, 0, 0) } },
//    83 - SUNDIAL
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    84 - TORTURE_CUCKING_STOOL
{ .power = 0x05, .data = 0x01, .flags = 0b0001000011000011, .effects = { .effects = { EFFECT_RAISE_LOYALTY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    85 - TORTURE_RACK
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_LOYALTY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    86 - TORTURE_STOCKS
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_LOYALTY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    87 - TORTURE_STRAPPADO
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_LOYALTY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    88 - TORTURE_WHIPPING_POST
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_LOYALTY       , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    89 - TREASURE_BARREL
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    90 - TREASURE_BASKET
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    91 - TREASURE_CHEST
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    92 - TREASURE_COFFER
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    93 - TREASURE_CRATE
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    94 - TREASURE_TRUNK
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    95 - TREASURE_URN
{ .power = 0x64, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    96 - TREASURE_VAULT
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001010011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    97 - VEIN_COPPER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ORE_COPPER   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    98 - VEIN_GOLD
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ORE_GOLD     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    99 - VEIN_IRON
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ORE_IRON     , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    100 - VEIN_SILVER
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ORE_SILVER   , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    101 - VEIN_TIN
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_CREATE_ORE_TIN      , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    102 - WAGON_BROKEN
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_CREATE_ITEM_COMMON  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    103 - WARD
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001001100, .effects = { .effects = { NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    104 - WAYSTONE
{ .power = 0x05, .data = 0x01, .flags = 0b0000100001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    105 - WELL
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    106 - WELL_ANCIENT
{ .power = 0x05, .data = 0x01, .flags = 0b0001100001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },
//    107 - WICKER_MAN
{ .power = 0x05, .data = 0x01, .flags = 0b0000000001000011, .effects = { .effects = { EFFECT_RAISE_INTELLIGENCE  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                  , NO_EFFECT                   }, .chance = EFFECT_CHANCE(1, 0, 0, 0, 0, 0) } },

//COUNT = 108;
