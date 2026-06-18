// Generated spell data structs
// Database contains 86 total spells

// layout: 
//    .power = 8 bits (uint8_t)
//    .level = 8 bits (uint8_t)
//    .data  = {  8 bits (uint8_t)
//                .type = 4 bits
//                .pp   = 4 bits
//             }

//    .flags = {  8 bits (uint8_t)
//                .use_on_party_member = 1 bits
//                .use_on_enemy = 1 bits
//                .use_on_trainer = 1 bits
//                (5 bits of padding)
//             }

// Individual spells data
// 0 - AWAKEN -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 1 - BLINDING_LIGHT -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 2 - BREW_POTION -> .power = 10 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xd5, .flags = 0b00000000  },
// 3 - BRILLIANCE_AURA -> .power = 2 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x02, .level = 0x01, .data = 0x95, .flags = 0b00000100  },
// 4 - BURN_HEAL -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 5 - CAPTURE -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000100  },
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
// 11 - CURE_CURSE -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 12 - CURE_DISEASE -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 13 - CURE_POISON -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 14 - DEFEND -> .power = 1 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xf5, .flags = 0b00000001  },
// 15 - DESCEND -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 16 - DISPLACEMENT -> .power = 5 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x05, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 17 - DROUGHT -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 18 - EMPOWER -> .power = 1 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xf5, .flags = 0b00000001  },
// 19 - FEAR -> .power = 1 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0xd5, .flags = 0b00000100  },
// 20 - FIRE_BALL -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000100  },
// 21 - FLAME_EATER -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000001  },
// 22 - FOCUS -> .power = 1 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0x75, .flags = 0b00000000  },
// 23 - FORTIFY -> .power = 1 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xf5, .flags = 0b00000001  },
// 24 - GAIN_ACCURACY -> .power = 1 .level = 1 .type = DRAGONS .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x55, .flags = 0b00000001  },
// 25 - GAIN_LOYALTY -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 26 - GLOWING_EMBERS -> .power = 1 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0x15, .flags = 0b00000100  },
// 27 - GROW_MUSCLE -> .power = 1 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x05, .flags = 0b00000001  },
// 28 - HASTE -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 29 - HASTEN -> .power = 1 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x05, .flags = 0b00000001  },
// 30 - HEAL -> .power = 25 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x19, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 31 - HEAT_WAVE -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 32 - HUNT -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 33 - HYPOTHERMIA -> .power = 1 .level = 1 .type = ICE .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0x25, .flags = 0b00000100  },
// 34 - ICE_BOLT -> .power = 10 .level = 1 .type = ICE .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x25, .flags = 0b00000100  },
// 35 - INCREASE_BAG -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 36 - LEVITATE -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 37 - MUD_SLING -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000100  },
// 38 - NERVE_REPAIR -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 39 - OPEN_CHEST -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 40 - PORTAL -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 41 - POWER_OVERWHELMING -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 42 - PURIFICATION -> .power = 10 .level = 1 .type = FEY .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x85, .flags = 0b00000000  },
// 43 - RAGE -> .power = 1 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0x75, .flags = 0b00000000  },
// 44 - RAIN_STORM -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 45 - RAISE_AGILITY -> .power = 1 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x75, .flags = 0b00000001  },
// 46 - RAISE_DEAD -> .power = 10 .level = 1 .type = UNDEAD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xc5, .flags = 0b00000000  },
// 47 - RAISE_DEXTERITY -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 48 - RAISE_EARTH_RESIST -> .power = 10 .level = 1 .type = TOXIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xe5, .flags = 0b00000000  },
// 49 - RAISE_FIRE_RESIST -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 50 - RAISE_FORTITUDE -> .power = 1 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xf5, .flags = 0b00000001  },
// 51 - RAISE_ICE_RESIST -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 52 - RAISE_INTELLIGENCE -> .power = 1 .level = 1 .type = FEY .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x85, .flags = 0b00000001  },
// 53 - RAISE_MAGIC_RESIST -> .power = 10 .level = 1 .type = ANCIENT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xb5, .flags = 0b00000000  },
// 54 - RAISE_MAX_HP -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 55 - RAISE_MAX_MP -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 56 - RAISE_SKELETON -> .power = 10 .level = 1 .type = UNDEAD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xc5, .flags = 0b00000000  },
// 57 - RAISE_STAMINA -> .power = 1 .level = 1 .type = BEAST .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x75, .flags = 0b00000001  },
// 58 - RAISE_STRENGTH -> .power = 1 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xa5, .flags = 0b00000001  },
// 59 - RAISE_TOXIC_RESIST -> .power = 10 .level = 1 .type = UNDEAD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xc5, .flags = 0b00000000  },
// 60 - RAISE_WATER_RESIST -> .power = 10 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x05, .flags = 0b00000000  },
// 61 - RAISE_XP -> .power = 100 .level = 1 .type = ANCIENT .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x64, .level = 0x01, .data = 0xb5, .flags = 0b00000001  },
// 62 - RAZOR_GRASS -> .power = 10 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x05, .flags = 0b00000100  },
// 63 - REFLECT -> .power = 1 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x35, .flags = 0b00000001  },
// 64 - REPEL -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 65 - RESTORE_MANA -> .power = 20 .level = 1 .type = FEY .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x14, .level = 0x01, .data = 0x85, .flags = 0b00000001  },
// 66 - RESURRECT -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 67 - SHADOWS -> .power = 1 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xd5, .flags = 0b00000001  },
// 68 - SILENCE -> .power = 1 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x35, .flags = 0b00000001  },
// 69 - SLOW -> .power = 1 .level = 1 .type = DEMONIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x01, .level = 0x01, .data = 0xd5, .flags = 0b00000100  },
// 70 - SOOTHE -> .power = 1 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x95, .flags = 0b00000001  },
// 71 - SPAWN_ACID -> .power = 10 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x05, .flags = 0b00000000  },
// 72 - SPAWN_FLOOR -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 73 - SPAWN_LAVA -> .power = 10 .level = 1 .type = FLAME .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x15, .flags = 0b00000000  },
// 74 - SPAWN_PITS -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 75 - SPAWN_WATER -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 76 - STRENGTHEN -> .power = 1 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0xf5, .flags = 0b00000001  },
// 77 - SUMMON_FOOD -> .power = 10 .level = 1 .type = HUMANOID .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xa5, .flags = 0b00000000  },
// 78 - SUMMON_WARD -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 79 - TELEPORT -> .power = 10 .level = 1 .type = DEMIGOD .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x95, .flags = 0b00000000  },
// 80 - WALL_WALKING -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },
// 81 - WATER_BREATHING -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 82 - WATER_WALKING -> .power = 10 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0x35, .flags = 0b00000000  },
// 83 - WIZEN -> .power = 1 .level = 1 .type = PLANT .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x05, .flags = 0b00000001  },
// 84 - WIZEN2 -> .power = 1 .level = 1 .type = AQUATIC .pp = 5 .flags = { . use_on_party_member = 1 }
{ .power = 0x01, .level = 0x01, .data = 0x35, .flags = 0b00000001  },
// 85 - XRAY_VISION -> .power = 10 .level = 1 .type = EARTHEN .pp = 5 .flags = { . use_on_party_member = 0 }
{ .power = 0x0a, .level = 0x01, .data = 0xf5, .flags = 0b00000000  },

//COUNT = 86;
