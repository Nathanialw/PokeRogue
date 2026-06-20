from python.data import db_manager
from python.config import constants


def make_flags8(flag0=0, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0, flag6=0, flag7=0, ):
    """Pack up to 8 boolean flags into a single integer bitmask."""

    def bit(value, shift):
        # Truthy → 1, Falsy (including None) → 0
        return (1 if value else 0) << shift

    return bit(flag0, 0) | bit(flag1, 1) | bit(flag2, 2) | bit(flag3, 3) | bit(flag4, 4) | bit(flag5, 5) | bit(flag6, 6) | bit(flag7, 7)


def make_flags16(flag0=0, flag1=0, flag2=0, flag3=0,
                 flag4=0, flag5=0, flag6=0, flag7=0,
                 flag8=0, flag9=0, flag10=0, flag11=0,
                 flag12=0, flag13=0, flag14=0, flag15=0):
    """Pack up to 16 boolean flags into a single 16-bit integer bitmask."""

    def bit(value, shift):
        # Truthy → 1, Falsy (including None) → 0
        return (1 if value else 0) << shift

    return (bit(flag0, 0) | bit(flag1, 1) | bit(flag2, 2) | bit(flag3, 3) |
            bit(flag4, 4) | bit(flag5, 5) | bit(flag6, 6) | bit(flag7, 7) |
            bit(flag8, 8) | bit(flag9, 9) | bit(flag10, 10) | bit(flag11, 11) |
            bit(flag12, 12) | bit(flag13, 13) | bit(flag14, 14) | bit(flag15, 15))


def creatures_skills(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}_skills.inc"
    creatures_skills_arr = db_manager.get_creatures_skills()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(creatures_skills_arr)} total used {entity}s\n")
        f.write(f"// Database contains {len(creatures_skills_arr[0])} total used skills\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s learnable skill data\n")
        for skills in creatures_skills_arr:
            f.write(f"{{ ")
            v = ''
            i = 0
            for s in skills:
                v = v + str(s)
                i += 1
                if i % 8 == 0:
                    f.write(f"0b{v}, ")
                    v = ''
            f.write(f"0b{v}0 }},\n")

        f.write("\n")
        f.write(f"//ALL_CREATURES_COUNT = {len(creatures_skills_arr)};\n")
        f.write(f"//ALL_SKILLS_COUNT = {len(creatures_skills_arr[0])};\n")


def creatures_level_up_skills(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}_level_up_skills.inc"
    names = db_manager.get_creatures_level_up_skills()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(names)} total used {entity}s\n\n")

        no_ability = "NO_ABILITY"
        # Write individual constants
        f.write(f"// Individual {entity}s data\n")
        # for b in names:
        for b in names:
            f.write(f"//  {b[0][0]}\n")
            f.write(f"{{ .c = {{ \n")
            for i in range(16):
                if i < len(b):
                    f.write(f"  {{ .skillID = {b[i][1]:16}, .level = {b[i][2]:2}, }}, \n")
                else:
                    f.write(f"  {{ .skillID = {no_ability:16}, .level =  0, }}, \n")
            f.write(f"\n}}}},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(names)};\n")


def spells(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    spell_data = db_manager.get_spells_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(spell_data)} total {entity}s\n\n")

        f.write(f"// layout: \n")
        f.write(f"//    .power = 8 bits (uint8_t)\n")
        f.write(f"//    .level = 8 bits (uint8_t)\n")
        f.write(f"//    .data  = {{  8 bits (uint8_t)\n")
        f.write(f"//                .type = 4 bits\n")
        f.write(f"//                .pp   = 4 bits\n")
        f.write(f"//             }}\n\n")
        f.write(f"//    .flags = {{  8 bits (uint8_t)\n")
        f.write(f"//                .use_on_party_member = 1 bits\n")
        f.write(f"//                .use_on_enemy = 1 bits\n")
        f.write(f"//                .use_on_trainer = 1 bits\n")
        f.write(f"//                (5 bits of padding)\n")
        f.write(f"//             }}\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")

        for i, (name, power, level, type_0, type_enum, pp, use_on_party_member, use_on_enemy, use_on_trainer) in enumerate(spell_data):
            # Clean the types for C string
            power_str = f"0x{int(power):02x}"
            level_str = f"0x{int(level):02x}"

            data_value = (int(type_enum) << 4) | int(pp)
            data_str = f"0x{data_value:02x}"

            flags = make_flags8(use_on_party_member, use_on_enemy, use_on_trainer)
            flags_str = f"0b{flags:08b}"

            f.write(f"// {i} - {name} -> .power = {power} .level = {level} .type = {type_0} .pp = {pp} .flags = {{ . use_on_party_member = {use_on_party_member} }}\n")
            f.write(f"{{ .power = {power_str}, .level = {level_str}, .data = {data_str}, .flags = {flags_str}  }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(spell_data)};\n")


def trainers(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    trainer_data = db_manager.get_trainers_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(trainer_data)} total {entity}s\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n\n")

        for i, (trainer_name, party_0, party_1, party_2, party_3, party_4, party_5, spell_0, spell_1, spell_2, spell_3, spell_4, spell_5, item_0, item_1, item_2, item_3, item_4, item_5) in enumerate(trainer_data):
            f.write(f"{{//  {i} - {trainer_name}}}\n")
            f.write(f"  .party = {{\n")
            f.write(f"      {party_0},\n")
            f.write(f"      {party_1},\n")
            f.write(f"      {party_2},\n")
            f.write(f"      {party_3},\n")
            f.write(f"      {party_4},\n")
            f.write(f"      {party_5},\n")
            f.write(f"  }},\n")
            f.write(f" .spells = {{\n")
            f.write(f"      {spell_0},\n")
            f.write(f"      {spell_1},\n")
            f.write(f"      {spell_2},\n")
            f.write(f"      {spell_3},\n")
            f.write(f"      {spell_4},\n")
            f.write(f"      {spell_5},\n")
            f.write(f"  }},\n")
            f.write(f" .items = {{\n")
            f.write(f"      {item_0},\n")
            f.write(f"      {item_1},\n")
            f.write(f"      {item_2},\n")
            f.write(f"      {item_3},\n")
            f.write(f"      {item_4},\n")
            f.write(f"      {item_5},\n")
            f.write(f"  }},\n")
            f.write(f"}},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(trainer_data)};\n")


def creature(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    trainer_data = db_manager.get_creature_stats()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(trainer_data)} total {entity}s\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n\n")

        for i, (name,
                attack_min, defence_min, magic_min, speed_min, accuracy_min, loyalty_min,
                attack_max, defence_max, magic_max, speed_max, accuracy_max, loyalty_max,
                attack_growth, defence_growth, magic_growth, speed_growth,
                hp_base, hp_growth, mp_base, mp_growth
                ) in enumerate(trainer_data):
            f.write(f"{{//  {i} - {name}}}\n")
            f.write(f"      .min    = {{ .attack = {attack_min:3}, .defence = {defence_min:3}, .magic = {magic_min:3}, .speed = {speed_min:3}, .accuracy = {accuracy_min:3}, .loyalty = {loyalty_min:3}, }},\n")
            f.write(f"      .max    = {{ .attack = {attack_max:3}, .defence = {defence_max:3}, .magic = {magic_max:3}, .speed = {speed_max:3}, .accuracy = {accuracy_max:3}, .loyalty = {loyalty_max:3}, }},\n")
            f.write(f"      .growth = {{ .attack = {attack_growth:3}, .defence = {defence_growth:3}, .magic = {magic_growth:3}, .speed = {speed_growth:3}, }},\n")
            f.write(f"      .hp_base = {hp_base:3}, .hp_growth = {hp_growth:3}, .mp_base = {mp_base:3}, .mp_growth = {mp_growth:3},\n")
            f.write(f"}},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(trainer_data)};\n")


def items(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    item_data = db_manager.get_items_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(item_data)} total {entity}s\n\n")

        f.write(f"// power      8 bitsr\n")
        f.write(f"// item_level 4 bits\n")
        f.write(f"// item_type  4 bits\n")
        f.write(f"// flags\n")
        f.write(f"//    x5 padding bits\n")
        f.write(f"//    consumable\n")
        f.write(f"//    consumable_party\n")
        f.write(f"//    consumable_spellbook\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")

        for i, (name, power, item_level, item_type, type_enum, consumable, consumable_party, consumable_spellbook) in enumerate(item_data):
            data_value = (int(type_enum) << 4) | int(item_level)
            data_str = f"0x{data_value:02x}"

            flags = make_flags8(consumable, consumable_party, consumable_spellbook)
            flags_str = f"0b{flags:08b}"

            f.write(f"// {i} - name - .power = {power}, .item_level = {item_level}, .item_type = {item_type},  flags = {{ .consumable = {consumable}, .consumable_party = {consumable_party}, .consumable_spellbook = {consumable_spellbook} }} \n")
            f.write(f"{{ .power = {power}, .data = {data_str}, .flags = {flags_str} }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(item_data)};\n")


def abilities(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    skill_data = db_manager.get_abilities_data()

    with (open(filename, 'w', encoding='utf-8') as f):
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(skill_data)} total {entity}s\n\n")

        f.write(f"//    .power =            8 bits\n")
        f.write(f"//    .power_special =    8 bits\n")
        f.write(f"//    .manaCost =         8 bits\n")
        f.write(f"//    .type_0 =           4 bits\n\n")
        f.write(f"//    .buff =            16 bits\n\n")
        f.write(f"//    .debuff =          16 bits\n\n")

        f.write(f"// Individual {entity}s data\n")
        for i, (name, formatted, power, power_special, mana_cost, type_0,
                bleed, blind, burn, curse, disease, disarm, enfeeble, fear, freeze, paralyze, petrify, poison, root, sap, sleep, slow,
                berserk, fire_eating, flying, haste,
                invigorate, invisible, lifelink, magic_shield,
                reflect, regeneration, revitalize, spell_power,
                stoneskin, thorns, vampiric_aura, warded) in enumerate(skill_data):
            # Clean the types for C string
            f.write(f"// {name} - {formatted}, \n")
            debuffs = make_flags16(bleed, blind, burn, curse, disarm, disease, enfeeble, fear, freeze, paralyze, petrify, poison, root, sap, sleep, slow)
            debuffs_str = f"0b{debuffs:016b}"
            buffs = make_flags16(berserk, fire_eating, flying, haste, invigorate, invisible, lifelink, magic_shield, reflect, regeneration, revitalize, spell_power, stoneskin, thorns, vampiric_aura, warded)
            buffs_str = f"0b{buffs:016b}"
            f.write(f"{{ .power = {power:3},  .power_special = {power_special:3}, .manaCost = {mana_cost:3}, .type = {type_0:10}, .debuff_flags = {debuffs_str}, .buff_flags = {buffs_str} }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(skill_data)};\n")


def objects(entity):
    filename = f"{constants.DATA_INC_FOLDER}/data_{entity}s.inc"
    object_data = db_manager.get_objects_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(object_data)} total {entity}s\n\n")

        # Write individual constants
        f.write(f"//       8  bits - .power = {{ 8 bits }} \n")
        f.write(f"//    2x 4  bits - .data  = {{ .object_type = {{ 4 bits }}, .level = {{ 4 bits }} }}\n")
        f.write(f"//       16 bits - .flags = {{ _pad0, _pad1, consumable_spellbook, consumable_party, room_center, against_wall, on_wall, corner, water_adjacent, map_generatable, .water, .nook,  .hallway, .on_step, .interactable, .consumable, consumable_party, consumable_spellbook  }}\n\n")
        f.write(f"// total 4 bytes\n")

        f.write(f"// Individual {entity}s data - count = {len(object_data)}\n")

        for i, (name, power, object_type, level, consumable, interactable, on_step, hallway, nook, water, map_generatable, water_adjacent, corner, on_wall, against_wall, room_center, consumable_party, consumable_spellbook) in enumerate(object_data):
            # Clean the types for C string
            f.write(f"//    {i} - {name}\n")

            power_str = f"0x{int(power):02x}"

            # data: type (high 4 bits) + level (low 4 bits) → matches your struct
            data_value = (int(object_type) << 4) | int(level)
            data_str = f"0x{data_value:02x}"

            # flags: build from LSB → MSB
            flags = make_flags16(consumable, interactable, on_step, hallway, nook, water, map_generatable, water_adjacent, corner, on_wall, against_wall, room_center, consumable_party, consumable_spellbook)
            flags_str = f"0b{flags:016b}"

            f.write(f"{{ .power = {power_str}, .data = {data_str}, .flags = {flags_str} }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(object_data)};\n")
