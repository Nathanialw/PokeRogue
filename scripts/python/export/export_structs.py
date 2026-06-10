from python.data import db_manager
from python.config import constants


def make_flags(flag0=0, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0, flag6=0, flag7=0, ):
    """Pack up to 8 boolean flags into a single integer bitmask."""

    def bit(value, shift):
        # Truthy → 1, Falsy (including None) → 0
        return (1 if value else 0) << shift

    return bit(flag0, 0) | bit(flag1, 1) | bit(flag2, 2) | bit(flag3, 3) | bit(flag4, 4) | bit(flag5, 5) | bit(flag6, 6) | bit(flag7, 7)


def creatures_skills(entity):
    filename = f"{constants.INC_FOLDER}/data_{entity}_skills.inc"
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
    filename = f"{constants.INC_FOLDER}/data_{entity}_level_up_skills.inc"
    names = db_manager.get_creatures_level_up_skills()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(names)} total used {entity}s\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")
        # for b in names:
        for b in names:
            f.write(f"//  {b[0][0]}\n")
            f.write(f"{{ .c = {{ \n")
            for i in range(16):
                if i < len(b):
                    f.write(f"  {{ .skillID = {b[i][1]}, .level = {b[i][2]}, }}, \n")
                else:
                    f.write(f"  {{ .skillID = NO_ABILITY, .level = 0, }}, \n")
            f.write(f"\n}}}},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(names)};\n")


def spells(entity):
    filename = f"{constants.INC_FOLDER}/data_{entity}s.inc"
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
        f.write(f"//                (7 bits of padding)\n")
        f.write(f"//             }}\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")

        for i, (name, power, level, mana_cost, type_0, type_enum, pp, use_on_party_member) in enumerate(spell_data):
            # Clean the types for C string
            power_str = f"0x{int(power):02x}"
            level_str = f"0x{int(level):02x}"

            data_value = (int(type_enum) << 4) | int(pp)
            data_str = f"0x{data_value:02x}"

            flags = make_flags(use_on_party_member)
            flags_str = f"0b{flags:08b}"

            f.write(f"// {i} - {name} -> .power = {power} .level = {level} .type = {type_0} .pp = {pp} .flags = {{ . use_on_party_member = {use_on_party_member} }}\n")
            f.write(f"{{ .power = {power_str}, .level = {level_str}, .data = {data_str}, .flags = {flags_str}  }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(spell_data)};\n")


def items(entity):
    filename = f"{constants.INC_FOLDER}/data_{entity}s.inc"
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

            flags = make_flags(consumable, consumable_party, consumable_spellbook)
            flags_str = f"0b{flags:08b}"

            f.write(f"// {i} - name - .power = {power}, .item_level = {item_level}, .item_type = {item_type},  flags = {{ .consumable = {consumable}, .consumable_party = {consumable_party}, .consumable_spellbook = {consumable_spellbook} }} \n")
            f.write(f"{{ .power = {power}, .data = {data_str}, .flags = {flags_str} }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(item_data)};\n")


def abilities(entity):
    filename = f"{constants.INC_FOLDER}/data_{entity}s.inc"
    skill_data = db_manager.get_abilities_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(skill_data)} total {entity}s\n\n")

        # Write individual constants
        f.write(f"// Individual {entity}s data\n")
        for i, (power, mana_cost, type_0) in enumerate(skill_data):
            # Clean the types for C string
            f.write("{" + f" .power = {power}, .manaCost = {mana_cost}, .type = {type_0} " + "},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(skill_data)};\n")


def objects(entity):
    filename = f"{constants.INC_FOLDER}/data_{entity}s.inc"
    object_data = db_manager.get_objects_data()

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"// Generated {entity} data structs\n")
        f.write(f"// Database contains {len(object_data)} total {entity}s\n\n")

        # Write individual constants
        f.write(f"//       8 bits - .power = {{ 8 bits }} \n")
        f.write(f"//    2x 4 bits - .data  = {{ .object_type = {{ 4 bits }}, .level = {{ 4 bits }} }}\n")
        f.write(f"//       8 bits - .flags = {{ pad1, pad0, .water, .nook,  .hallway, .on_step, .interactable, .consumable  }}\n\n")
        f.write(f"// total 3 bytes\n")

        f.write(f"// Individual {entity}s data - count = {len(object_data)}\n")

        for i, (name, power, object_type, level, consumable, interactable, on_step, hallway, nook, water) in enumerate(object_data):
            # Clean the types for C string
            f.write(f"//    {i} - {name}\n")

            power_str = f"0x{int(power):02x}"

            # data: type (high 4 bits) + level (low 4 bits) → matches your struct
            data_value = (int(object_type) << 4) | int(level)
            data_str = f"0x{data_value:02x}"

            # flags: build from LSB → MSB
            flags = make_flags(consumable, interactable, on_step, hallway, nook, water)
            flags_str = f"0b{flags:08b}"

            f.write(f"{{ .power = {power_str}, .data = {data_str}, .flags = {flags_str} }},\n")

        f.write("\n")
        f.write(f"//COUNT = {len(object_data)};\n")
