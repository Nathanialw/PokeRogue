// Generated spell data structs
// Database contains 62 total spells

// layout: 
//    .power = 8 bits (uint8_t)
//    .level = 8 bits (uint8_t)
//    .data  = {  8 bits (uint8_t)
//                .type = 4 bits
//                .pp   = 4 bits
//             }

//    .flags = {  8 bits (uint8_t)
//                .use_on_party_member = 1 bits
//                (7 bits of padding)
//             }

// Individual spells data
// 0 - AWAKEN -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 1 - BLINDING_LIGHT -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 2 - BREW_POTION -> .power = 10 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xd5, .flags = 0b00000000  },
// 3 - BRILLIANCE_AURA -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 4 - BURN_HEAL -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 5 - CAPTURE -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 6 - CLAIRVOYANCE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 7 - CREATE_COMMON_ITEM -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 8 - CREATE_MAGIC_ITEM -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 9 - CREATE_PIT -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 10 - CRUSADE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 11 - CURE_CURSE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 12 - CURE_DISEASE -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 13 - CURE_POISON -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 14 - DEFEND -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 15 - DESCEND -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 16 - DISPLACEMENT -> .power = 5 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x05, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 17 - DROUGHT -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 18 - EMPOWER -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 19 - FEAR -> .power = 10 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xd5, .flags = 0b00000000  },
// 20 - FIRE_BALL -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 21 - FLAME_EATER -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 22 - FOCUS -> .power = 10 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x75, .flags = 0b00000000  },
// 23 - FORTIFY -> .power = 10 .level = 1 .type = EARTHEN .pp = 1 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf1, .flags = 0b00000000  },
// 24 - GLOWING_EMBERS -> .power = 5 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x05, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 25 - GROW_MUSCLE -> .power = 10 .level = 1 .type = PLANT .pp = 1 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x01, .flags = 0b00000000  },
// 26 - HASTE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 27 - HASTEN -> .power = 10 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x05, .flags = 0b00000000  },
// 28 - HEAL -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 29 - HEAT_WAVE -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 30 - HUNT -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 31 - HYPOTHERMIA -> .power = 10 .level = 1 .type = ICE .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x25, .flags = 0b00000000  },
// 32 - ICE_BOLT -> .power = 10 .level = 1 .type = ICE .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x25, .flags = 0b00000000  },
// 33 - INCREASE_BAG -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 34 - LEVITATE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 35 - MUD_SLING -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 36 - NERVE_REPAIR -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 37 - OPEN_CHEST -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 38 - PORTAL -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 39 - POWER_OVERWHELMING -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 40 - PURIFICATION -> .power = 10 .level = 1 .type = FEY .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x85, .flags = 0b00000000  },
// 41 - RAGE -> .power = 10 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x75, .flags = 0b00000000  },
// 42 - RAIN_STORM -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 43 - RAISE_DEAD -> .power = 10 .level = 1 .type = UNDEAD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xc5, .flags = 0b00000000  },
// 44 - RAISE_SKELETON -> .power = 10 .level = 1 .type = UNDEAD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xc5, .flags = 0b00000000  },
// 45 - RAZOR_GRASS -> .power = 10 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x05, .flags = 0b00000000  },
// 46 - REFLECT -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 47 - REPEL -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 48 - RESURRECT -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 49 - SHADOWS -> .power = 10 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xd5, .flags = 0b00000000  },
// 50 - SILENCE -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 51 - SLOW -> .power = 10 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xd5, .flags = 0b00000000  },
// 52 - SOOTHE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 53 - STRENGTHEN -> .power = 10 .level = 1 .type = EARTHEN .pp = 1 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf1, .flags = 0b00000000  },
// 54 - SUMMON_FOOD -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 55 - TELEPORT -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 56 - WALL_WALKING -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 57 - WATER_BREATHING -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 58 - WATER_WALKING -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 59 - WIZEN -> .power = 10 .level = 1 .type = PLANT .pp = 1 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x01, .flags = 0b00000000  },
// 60 - WIZEN2 -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 61 - XRAY_VISION -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },

//COUNT = 62;
