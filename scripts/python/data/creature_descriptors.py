MIN_MATCHES = 2


CREATURE_VALIDATION = {
    # Aboleth - Lovecraftian fish monster
    "ABOLETH": {
        "required_terms": ["fish", "eel", "tentacle", "tentacled", "slime", "mucous", "aquatic", "three eyes", "mind", "enslave", "ancient", "memory", "venomous", "cephalopod", "beak", "abyssal", "telepathic", "psionic", "cavern", "forgotten", "primeval"],
        "forbidden_terms": ["wing", "feather", "warm-blooded", "mammal", "fire", "fur", "hair", "legs", "bipedal", "humanoid", "benevolent", "kind"],
        "min_matches": MIN_MATCHES
    },

    # Aeon - Personification of eternity
    "AEON": {
        "required_terms": ["eternity", "time", "infinite", "cosmic", "primordial", "gnostic", "emanation", "divine", "age", "eon", "forever", "timeless", "ageless", "immortal", "personification", "concept", "abstract", "celestial", "sphere", "pleroma"],
        "forbidden_terms": ["corporeal", "physical", "mortal", "finite", "temporary", "ephemeral", "fleeting", "short-lived", "mortal", "dying", "decaying", "rotting"],
        "min_matches": MIN_MATCHES
    },

    # Akkorokamui - Ainu giant octopus god
    "AKKOROKAMUI": {
        "required_terms": ["octopus", "giant", "tentacle", "cephalopod", "ainu", "japanese", "hokkaido", "god", "kamui", "deity", "red", "crimson", "sacred", "sea", "ocean", "bay", "fisherman", "healing", "curative", "offerings", "worship", "shinto", "mythology"],
        "forbidden_terms": ["mammal", "bird", "reptile", "scales", "feathers", "fur", "hair", "legs", "wings", "evil", "malevolent", "wicked", "demon"],
        "min_matches": MIN_MATCHES
    },

    # Alp - Nightmare demon
    "ALP": {
        "required_terms": ["nightmare", "chest", "sleep", "sit", "sitting", "demon", "shadow", "night", "spirit", "hat", "pale", "gaunt", "emaciated", "incubus", "dream", "oppress", "breath", "suffocate", "paralysis", "weight", "pressure", "dark figure", "hooded", "nocturnal", "elf", "alptraum", "mara", "germanic"],
        "forbidden_terms": ["beautiful", "majestic", "divine", "angelic", "antler", "hoof", "satyr", "tall", "bat wings", "winged", "glowing red eyes", "vampire", "bloodsucking", "female", "gown"],
        "min_matches": MIN_MATCHES
    },

    # Alraune - Mandrake root creature
    "ALRAUNE": {
        "required_terms": ["mandrake", "root", "plant", "humanoid", "shrieking", "scream", "deadly", "poisonous", "germanic", "folklore", "alraun", "doll", "figure", "grown under gallows", "drops of hanged man", "semen", "blood", "familiar", "homunculus", "tiny", "small", "fortune", "treasure", "oracle"],
        "forbidden_terms": ["animal", "beast", "reptile", "bird", "fish", "insect", "arachnid", "mammal", "feathers", "scales", "fur", "hair"],
        "min_matches": MIN_MATCHES
    },

    # Alux - Mayan dwarf spirit
    "ALUX": {
        "required_terms": ["mayan", "maya", "yucatan", "mexico", "central america", "dwarf", "small", "tiny", "spirit", "elemental", "forest", "jungle", "cornfield", "milpa", "trickster", "mischievous", "playful", "prank", "whistle", "night", "whirlwind", "dust devil", "clay figure", "offering", "protection", "guardian"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "cruel", "violent", "aggressive", "harmful", "deadly", "lethal", "fatal"],
        "min_matches": MIN_MATCHES
    },

    # Ammit - Egyptian devourer
    "AMMIT": {
        "required_terms": ["crocodile", "lion", "hippopotamus", "hybrid", "egyptian", "devour", "dead", "soul", "scales", "snout", "judgment", "underworld", "duat", "weighing", "heart", "feather", "maat", "amon", "apep", "mane", "paws", "jaws", "monstrous", "female", "goddess", "triple", "three beasts", "devourer of souls"],
        "forbidden_terms": ["winged", "beautiful", "divine", "bat wings", "serpent tail", "eagle talons", "bird", "feathers", "demon", "demonic", "multi-headed", "tentacles", "slimy", "dragon", "fire-breathing"],
        "min_matches": MIN_MATCHES
    },

    # Amphiptere - Winged serpent
    "AMPHIPTERE": {
        "required_terms": ["winged", "serpent", "snake", "feather", "feathered", "wings", "no legs", "legless", "flying", "dragon", "wyvern", "avian", "bird-like", "plumage", "reptile", "scales", "beak", "forked tongue", "slender", "long", "coils", "glide", "soar", "airborne", "european", "heraldic", "two wings", "winged serpent"],
        "forbidden_terms": ["legs", "limbs", "mammal", "four legs", "six legs", "bipedal", "quadrupedal", "armored head", "fins", "aquatic", "amphibious", "massive head", "mandibles", "chitinous", "arachnid", "stinger", "horn", "claws", "talons", "fire breathing"],
        "min_matches": MIN_MATCHES
    },

    # Amphisbaena - Two-headed serpent
    "AMPHISBAENA": {
        "required_terms": ["two-headed", "both ends", "serpent", "snake", "head at each end", "dual heads", "reptile", "scales", "greek", "mythology", "ants", "ant-eater", "poison", "venom", "glows", "phosphorescent", "eyes shine", "cold", "icy", "rolls", "wheels", "circular motion", "twin heads", "double-headed"],
        "forbidden_terms": ["single head", "one head", "legs", "wings", "feathers", "fur", "hair", "mammal", "bird", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Anansi - Spider trickster god
    "ANANSI": {
        "required_terms": ["spider", "trickster", "god", "african", "ghana", "ashanti", "akan", "west african", "caribbean", "anansi", "kwaku anansi", "folklore", "stories", "spider tales", "wise", "cunning", "clever", "sly", "deceptive", "stories", "storyteller", "spider web", "eight legs", "small", "can transform", "shapeshift", "human form"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal"],
        "min_matches": MIN_MATCHES
    },

    # Angel - Divine being
    "ANGEL": {
        "required_terms": ["wing", "wings", "halo", "divine", "celestial", "holy", "light", "radiant", "golden", "feather", "feathered", "humanoid", "messenger", "god", "heaven", "glowing", "luminous", "blessed", "sacred", "seraph", "cherub", "archangel", "white", "robes", "glory", "ethereal", "graceful", "benevolent", "guardian", "choir", "harp", "trumpet", "six wings", "many eyes"],
        "forbidden_terms": ["demon", "evil", "corrupt", "undead", "hell", "infernal", "devil", "satanic", "malevolent", "wicked", "sinister", "grotesque", "monstrous", "ugly", "rotting", "decayed", "skeletal", "claw", "fang", "tusk", "horn"],
        "min_matches": MIN_MATCHES
    },

    # Ankheg - Burrowing insect
    "ANKHEG": {
        "required_terms": ["burrow", "burrowing", "insect", "insectoid", "antenna", "antennae", "mandible", "mandibles", "acid", "underground", "chitin", "chitinous", "segmented", "tunnel", "arthropod", "exoskeleton", "claws", "dig", "soil", "earth", "dirt", "predator", "ambush", "subterranean", "giant insect", "beetle-like", "ant-like", "crushing", "jaws", "pincers", "compound eyes", "six legs"],
        "forbidden_terms": ["reptile", "reptilian", "lizard", "scales", "serpentine", "snake", "armored shell", "turtle", "bipedal", "tail stinger", "scorpion tail", "fire-breathing", "flame", "elemental", "magical", "dragon", "wyrm", "mammal", "fur", "hair", "feathers", "wings", "flying", "aquatic", "fins", "gills", "glowing", "ethereal"],
        "min_matches": MIN_MATCHES
    },

    # Ankylosaurus - Armored dinosaur
    "ANKYLOSAURUS": {
        "required_terms": ["dinosaur", "prehistoric", "cretaceous", "armor", "bony plates", "osteoderms", "club tail", "tail club", "heavy", "quadrupedal", "four legs", "herbivore", "plant-eater", "low-slung", "wide body", "triangular head", "beak", "teeth", "small", "spikes", "horns", "shoulder spikes", "armored", "tank-like", "fossil", "extinct", "mesozoic"],
        "forbidden_terms": ["winged", "feathered", "flying", "soaring", "gliding", "bird", "avian", "beak of bird", "talons", "predator", "carnivore", "meat-eater", "hunter", "sharp teeth", "claws", "bipedal", "two legs", "fast", "swift", "agile"],
        "min_matches": MIN_MATCHES
    },

    # Anzu - Mesopotamian storm bird
    "ANZU": {
        "required_terms": ["bird", "eagle", "lion", "storm", "sumerian", "mesopotamian", "winged", "beak", "talon", "talons", "divine", "thunder", "lightning", "tempest", "cloud", "sky", "babylonian", "akkadian", "mythological", "massive", "enormous", "feathers", "lion-headed", "eagle-headed", "hybrid", "tablets of destiny", "steals", "thief", "zu", "imdugud", "protective", "spirit", "weather god", "ninurta"],
        "forbidden_terms": ["dragon", "serpent", "fish", "scales", "reptile", "snake", "crocodile", "amphibian", "frog", "toad", "insect", "spider", "arachnid", "chitin", "exoskeleton", "fur", "mammalian", "hooved", "deer", "antler"],
        "min_matches": MIN_MATCHES
    },

    # Arbalest - Crossbow-wielding creature
    "ARBALESTER": {
        "required_terms": ["crossbow", "arbalest", "arbalister", "archer", "ranged", "weapon", "shoot", "bolt", "quarrel", "projectile", "marksman", "sniper", "soldier", "mercenary", "medieval", "middle ages", "warfare", "siege", "castle", "fortification", "armor", "mail", "plate", "helmet", "skilled", "accurate", "deadly", "piercing", "armor-piercing"],
        "forbidden_terms": ["magic", "magical", "spell", "enchantment", "supernatural", "divine", "holy", "sacred", "mythical", "legendary", "fairy", "fae", "demon", "devil", "angel"],
        "min_matches": MIN_MATCHES
    },

    # Archon - Gnostic ruler of cosmos
    "ARCHON": {
        "required_terms": ["gnostic", "gnosticism", "ruler", "cosmic", "world", "material realm", "demiurge", "aeon", "emanations", "pleroma", "spiritual", "cosmos", "universe", "celestial", "power", "authority", "dominion", "planet", "sphere", "heavenly", "divine", "created", "lesser god", "intermediary", "sophia", "yaldabaoth", "sabaoth", "adonaius", "blind", "ignorant", "oppressive"],
        "forbidden_terms": ["physical", "corporeal", "flesh", "blood", "bone", "mortal", "earthly", "terrestrial", "animal", "beast", "creature", "monster", "demon", "devil"],
        "min_matches": MIN_MATCHES
    },

    # Baba Yaga - Slavic witch
    "BABA_YAGA": {
        "required_terms": ["witch", "hut", "chicken", "legs", "chicken legs", "mortar", "pestle", "iron teeth", "crone", "old", "slavic", "russian", "forest", "bony", "iron nose", "fence", "skulls", "dancing", "whirlwind", "broom", "wild", "cannibal", "bone", "hag", "yaga", "baba", "grandmother", "wicked", "ambiguous", "helper", "villain", "forest hut", "moving hut", "skull fence", "mortar boat", "pestle oar"],
        "forbidden_terms": ["beautiful", "young", "maiden", "pretty", "attractive", "handsome", "comely", "fair", "lovely", "gorgeous", "radiant", "glowing with youth", "innocent", "pure", "virginal", "princess-like", "delicate", "gentle", "soft-spoken"],
        "min_matches": MIN_MATCHES
    },

    # Balor - Irish demon king
    "BALOR": {
        "required_terms": ["balor", "fomorian", "irish", "celtic", "giant", "king", "evil eye", "one eye", "destructive eye", "eye that kills", "death gaze", "battle", "tuatha de danann", "second battle of mag tuired", "lugh", "grandson", "prophecy", "cyclopean", "single eye", "eyelid", "heavy eyelid", "four men lift lid", "poisonous eye", "petrifying gaze", "baleful", "malevolent"],
        "forbidden_terms": ["two-eyed", "multiple eyes", "compound eyes", "many-eyed", "four-eyed", "hundred-eyed", "argus", "extra eyes", "additional eyes", "eye stalks", "eyestalks", "small eyes", "tiny eyes", "beady eyes"],
        "min_matches": MIN_MATCHES
    },

    # Banshee - Wailing spirit
    "BANSHEE": {
        "required_terms": ["wail", "wailing", "scream", "screaming", "spirit", "woman", "female", "death", "foretell", "omen", "irish", "celtic", "hair", "comb", "gray", "pale", "white", "keening", "lament", "mourn", "mourning", "bean sidhe", "fairy", "faerie", "washerwoman", "stream", "blood", "warning", "bean-nighe", "scottish", "supernatural", "ghost", "apparition", "long hair", "silver hair", "brushing hair", "red eyes from weeping"],
        "forbidden_terms": ["winged", "small", "demon", "malevolent", "evil", "wicked", "harmful", "attacking", "violent", "aggressive", "claw", "fang", "horn", "tail", "scales", "reptile", "insect", "animal face", "beastly", "monstrous appearance", "ugly", "grotesque", "happy", "joyful", "laughing", "celebratory"],
        "min_matches": MIN_MATCHES
    },

    # Barghest - Ghostly dog
    "BARGHEST": {
        "required_terms": ["dog", "hound", "canine", "black", "ghost", "spectral", "northern", "english", "chain", "monstrous", "large", "eyes", "glowing", "red eyes", "fiery eyes", "yorkshire", "northern england", "portent", "death omen", "phantom", "apparition", "hellhound", "goblin", "demon dog", "shaggy", "enormous", "teeth", "fangs", "howl", "midnight", "lonely roads", "churchyard", "cemetery", "barguest", "gytrash", "spectral hound", "fiery breath", "sparks", "no shadow", "headless dog", "chains rattling"],
        "forbidden_terms": ["scaled", "serpent", "dragon", "reptile", "lizard", "crocodile", "snake", "turtle", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "feathers", "bird", "winged", "beak", "talons", "insect", "arachnid", "chitin"],
        "min_matches": MIN_MATCHES
    },

    # Basilisk - Snake that kills with gaze
    "BASILISK": {
        "required_terms": ["serpent", "snake", "crown", "crest", "gaze", "petrify", "stone", "deadly", "eyes", "reptile", "venomous", "king of serpents", "glance", "lethal", "rooster", "cockscomb", "hatched from egg", "toad", "frog", "cockerel", "mythical", "european", "medieval", "dragonet", "poison", "death gaze", "scales", "slither", "poisonous", "venom", "look", "basiliskos", "little king", "crown-like crest", "deadly stare", "instant death", "withered plants", "cracked earth"],
        "forbidden_terms": ["feather", "mammal", "warm-blooded", "fur", "hair", "wool", "hide", "pelt", "wing", "winged", "flight", "soaring", "beak", "talon", "avian", "bird-like", "clawed feet", "legs", "bipedal", "quadrupedal", "humanoid", "arms", "hands", "intelligent speech", "magical spells"],
        "min_matches": MIN_MATCHES
    },

    # Beholder - Floating eyeball monster
    "BEHOLDER": {
        "required_terms": ["eye", "orb", "floating", "central eye", "eyestalk", "tentacle", "tyrant", "magic", "anti-magic", "sphere", "spherical", "mouth", "fangs", "teeth", "dungeons and dragons", "d&d", "aberration", "xenophobic", "paranoid", "eye tyrant", "spheres", "levitating", "levitation", "disintegration", "fear", "death", "sleep", "charm", "slowing", "telekinetic", "rays", "floating eye", "magical rays", "dream", "nightmare", "gauth", "spectator", "ten eyestalks", "toothy maw", "underdark"],
        "forbidden_terms": ["leg", "arm", "humanoid", "winged", "bipedal", "quadrupedal", "walking", "running", "hopping", "jumping", "furry", "hairy", "feathered", "scaled", "fish-like", "aquatic", "gilled", "finned", "tail", "prehensile tail", "beautiful", "handsome", "pretty", "graceful", "elegant"],
        "min_matches": MIN_MATCHES
    },

    # Boggart - Household spirit
    "BOGGART": {
        "required_terms": ["household", "spirit", "mischief", "trickster", "small", "goblin", "brownie", "english", "fae", "fairy", "lancashire", "yorkshire", "annoying", "pranks", "mischievous", "troublesome", "invisible", "shapeshifter", "shapeshifting", "closet", "cupboard", "drawer", "moving objects", "hiding things", "domestic", "hobgoblin", "bugbear", "nuisance", "pest", "boggart", "bogeyman", "poltergeist-like", "noises", "knocking", "banging", "spilled milk", "missing items", "soured cream", "curdled milk", "cold spots", "creaking floors"],
        "forbidden_terms": ["divine", "angelic", "majestic", "noble", "grand", "glorious", "splendid", "magnificent", "impressive", "awesome", "wondrous", "marvelous", "beautiful", "handsome", "pretty", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "intelligent", "wise"],
        "min_matches": MIN_MATCHES
    },

    # Bogie - Scottish goblin
    "BOGIE": {
        "required_terms": ["bogie", "bogey", "bogy", "scottish", "northern english", "goblin", "spirit", "mischievous", "trickster", "small", "ugly", "fearsome", "scary", "frightening", "children", "fear", "bugbear", "bugaboo", "terrify", "haunt", "nocturnal", "night", "darkness", "shadows", "lurking", "hiding", "pranks", "malicious", "malevolent", "harmful", "dangerous", "shape-shifter", "shapeshifter"],
        "forbidden_terms": ["beautiful", "kind", "gentle", "helpful", "benevolent", "protective", "guardian", "friendly", "welcoming", "warm", "caring", "compassionate", "empathetic", "sympathetic", "selfless", "altruistic", "charitable", "giving"],
        "min_matches": MIN_MATCHES
    },

    # Bonnacon - Bull that burns with dung
    "BONNACON": {
        "required_terms": ["bull", "bison", "cattle", "bonnacon", "bonasus", "medieval bestiary", "physiologus", "pliny", "defense", "dung", "excrement", "feces", "burning", "fiery", "caustic", "corrosive", "flaming dung", "fart", "flatulence", "gaseous", "explosive", "defecate", "evacuate", "bowels", "intestines", "curved horns", "horse mane", "mane", "asia", "scythia", "pannonia"],
        "forbidden_terms": ["winged", "feathered", "reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin"],
        "min_matches": MIN_MATCHES
    },

    # Brag - Shapeshifting fairy
    "BRAG": {
        "required_terms": ["brag", "northern english", "shapeshifter", "fairy", "fae", "spirit", "horse", "calf", "donkey", "man", "woman", "animal form", "human form", "mischievous", "trickster", "prankster", "lure", "lead astray", "mislead", "deceive", "trick", "entice", "tempt", "ride", "riding", "tire out", "exhaust", "morning", "dawn", "disappears", "vanishes", "northumberland", "durham", "yorkshire"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Brownie - Helpful household spirit
    "BROWNIE": {
        "required_terms": ["small", "household", "spirit", "helpful", "brown", "clothes", "brown clothes", "night", "scottish", "english", "fae", "fairy", "domestic", "cleaning", "chores", "work", "invisible", "nocturnal", "offering", "bowl of milk", "cream", "porridge", "honey", "kind", "benevolent", "lone", "solitary", "attached to house", "family", "servant", "brown man", "brownie", "gruagach", "bwca", "bwbach", "hob", "barn spirit", "farm spirit", "threshing", "winnowing", "churning butter", "grateful", "appreciation"],
        "forbidden_terms": ["evil", "malevolent", "demon", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "fiery", "flaming"],
        "min_matches": MIN_MATCHES
    },

    # Bugbear - Hairy goblinoid
    "BUGBEAR": {
        "required_terms": ["hairy", "goblin", "goblinoid", "large", "shaggy", "lanky", "fur", "long arms", "stealth", "ambush", "surprise", "claws", "pointed ears", "snout", "beast-like", "dungeons and dragons", "d&d", "bugbear", "goblin-kin", "bruiser", "strong", "ferocious", "intimidating", "lurking", "skulking", "sneaky", "night raids", "kidnapping", "extortion", "bully", "brute", "hobgoblin relative", "long-limbed", "apelike", "heavy brow", "prognathous jaw", "tusks", "fangs", "yellow eyes", "glowing eyes", "darkvision"],
        "forbidden_terms": ["scaled", "feathered", "divine", "angelic", "holy", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "benevolent"],
        "min_matches": MIN_MATCHES
    },

    # Buggane - Manx ogre
    "BUGGANE": {
        "required_terms": ["buggane", "manx", "isle of man", "ogre", "giant", "troll", "monstrous", "hairy", "shaggy", "teeth", "tusks", "claws", "powerful", "strong", "fearsome", "terrifying", "church", "roof", "tear off roof", "destroy church", "st trinians", "chapel", "curse", "malevolent", "wicked", "evil", "nocturnal", "night", "darkness", "shadows", "mountain", "hill", "cave", "lair", "folklore", "celtic"],
        "forbidden_terms": ["small", "tiny", "diminutive", "miniature", "minuscule", "petite", "wee", "little", "kind", "gentle", "benevolent", "helpful", "friendly", "welcoming", "warm", "caring", "compassionate"],
        "min_matches": MIN_MATCHES
    },

    # Bulette - Land shark
    "BULETTE": {
        "required_terms": ["land shark", "burrow", "armor", "plated", "dorsal fin", "shark", "tunneling", "predator", "dinosaur", "dinosaur-like", "armored", "bony plates", "ridged back", "powerful claws", "digging", "leap", "erupt", "attack from below", "jaws", "teeth", "massive", "carnivorous", "apex predator", "eating horses", "horse hunter", "greyhawk", "shark of the earth", "plated hide", "bony dorsal fin", "powerful limbs", "clawed feet", "wide mouth", "multiple rows teeth", "triangular teeth", "serrated teeth", "erupt from ground", "burst forth", "leap attack", "unstoppable charge", "mountain mover", "territorial"],
        "forbidden_terms": ["wing", "feather", "magical", "spell-casting", "spell-like", "supernatural", "divine", "holy", "blessed", "intelligent", "wise", "cunning", "clever", "trickster", "deceptive", "scheming", "tool use", "weapon use", "armor wearing", "speech", "language", "communication"],
        "min_matches": MIN_MATCHES
    },

    # Byakhee - Lovecraftian horror
    "BYAKHEE": {
        "required_terms": ["winged", "tentacle", "lovecraftian", "star", "void", "monstrosity", "alien", "beak", "horror", "cthulhu", "hastur", "mythos", "outer god", "servitor", "interstellar", "cosmic", "nightmare", "indescribable", "bat-like", "leathery wings", "claws", "hooves", "man-like", "bird-like", "corpse", "rotting", "fetid", "stench", "from beyond", "extradimensional", "yuggoth", "great old ones", "servant race", "star-spawn", "non-euclidean", "wrong angles", "impossible anatomy", "warped", "twisted", "shrieking", "whistling cry", "cold of space", "void between stars", "riding", "mount"],
        "forbidden_terms": ["beautiful", "divine", "humanoid", "normal", "natural", "earthly", "terrestrial", "mundane", "ordinary", "commonplace", "familiar", "wholesome", "pure", "clean", "pleasant", "agreeable", "nice", "friendly", "welcoming", "warm"],
        "min_matches": MIN_MATCHES
    },

    # Cailleach - Scottish winter goddess
    "CAILLEACH": {
        "required_terms": ["cailleach", "scottish", "irish", "gaelic", "celtic", "goddess", "winter", "crone", "old", "aged", "ancient", "veiled", "blue face", "dark blue", "staff", "hammer", "weather", "storms", "snow", "ice", "frost", "mountain", "ben nevis", "highlands", "spring", "brigid", "transformation", "hag", "divine", "creator", "land shaper", "earth shaper", "loch", "island", "standing stone", "neolithic", "prehistoric", "cyclical", "seasons", "elder"],
        "forbidden_terms": ["young", "youthful", "beautiful", "pretty", "fair", "lovely", "gorgeous", "radiant", "glowing with youth", "innocent", "pure", "virginal", "princess-like", "delicate", "gentle", "soft-spoken", "malevolent", "evil", "demonic"],
        "min_matches": MIN_MATCHES
    },

    # Caladrius - Healing bird
    "CALADRIUS": {
        "required_terms": ["bird", "white", "healing", "sick", "disease", "prophet", "omen", "royal", "court", "pure", "snow-white", "roman", "mythical bird", "king's chamber", "looks at patient", "absorbs illness", "flies away", "takes sickness", "cure", "healer", "health", "prognosticate", "prognosis", "if looks away", "death omen", "prophetic", "augury", "divination", "physiologus", "bestiary", "medieval", "plover", "pure white", "snowy plumage", "golden beak", "golden legs", "royal court", "sickroom", "absorbs malady", "takes disease into self", "dies for patient", "self-sacrifice", "restorative", "curative", "miraculous", "holy"],
        "forbidden_terms": ["predatory", "evil", "dark", "black", "sinister", "malevolent", "wicked", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "poisonous", "venomous", "corrosive", "burning", "fiery", "flaming", "carnivorous", "meat-eating", "hunting", "killing", "slaughtering"],
        "min_matches": MIN_MATCHES
    },

    # Callicantzaros - Greek Christmas goblin
    "CALLICANTZARO": {
        "required_terms": ["callicantzaros", "kallikantzaros", "greek", "christmas", "twelve days", "yule", "goblin", "dwarf", "mischievous", "trickster", "malevolent", "wicked", "ugly", "grotesque", "black", "dark", "hairy", "shaggy", "long tail", "red eyes", "glowing eyes", "fireplace", "chimney", "enter home", "cause trouble", "mess", "chaos", "disorder", "epiphany", "holy water", "incense", "blessing", "leave", "disappear", "underground", "subterranean", "saw", "woodcutter", "tree of life", "world tree"],
        "forbidden_terms": ["beautiful", "handsome", "pretty", "attractive", "comely", "fair", "lovely", "gorgeous", "radiant", "glowing", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "kind", "gentle", "benevolent", "helpful"],
        "min_matches": MIN_MATCHES
    },

    # Cambion - Half-demon offspring
    "CAMBION": {
        "required_terms": ["cambion", "half-demon", "half-human", "hybrid", "offspring", "child", "demon father", "human mother", "succubus", "incubus", "demon parent", "mortal parent", "mixed blood", "tainted", "cursed", "dark heritage", "supernatural", "powers", "abilities", "magical", "spellcasting", "evil tendencies", "conflicted", "struggle", "inner demon", "outcast", "outsider", "rejected", "feared", "persecuted", "medieval legend", "folklore", "occult"],
        "forbidden_terms": ["pure", "innocent", "virtuous", "righteous", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "holy", "divine", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Cat Sith - Fairy cat
    "CAT_SITH": {
        "required_terms": ["cat", "fairy", "fae", "scottish", "gaelic", "highlands", "black", "white spot", "chest", "large", "enormous", "size of dog", "witch", "transformation", "shape-shifter", "steal souls", "souls", "newly dead", "before burial", "vigil", "wake", "keep watch", "keep away", "music", "games", "cat sith", "cat-sìth", "cat-sídhe", "fairy cat", "supernatural", "nocturnal", "night", "highland", "mythology", "folklore"],
        "forbidden_terms": ["small", "tiny", "diminutive", "miniature", "minuscule", "petite", "wee", "little", "ordinary", "normal", "common", "domestic", "pet", "tame", "friendly", "gentle", "soft", "cuddly", "affectionate"],
        "min_matches": MIN_MATCHES
    },

    # Catoblepas - African monster
    "CATOBLEPAS": {
        "required_terms": ["buffalo", "boar", "heavy", "head", "gaze", "petrify", "stone", "african", "ethiopian", "scaly", "back", "pliny", "elder", "natural history", "catoblepas", "gorgon", "downward-looking", "ever weighing down", "poison breath", "venomous", "deadly stare", "scaly back", "wild boar-like", "heavy head", "lagging head", "difficulty lifting", "poisonous", "lethal gaze", "catoblepon", "gaze kills", "breath kills", "small eyes", "bloodshot eyes", "shaggy mane", "thin body", "thick neck", "always looking down", "grazing on poisonous plants", "toxic diet", "venomous exhalation"],
        "forbidden_terms": ["winged", "graceful", "beautiful", "elegant", "refined", "delicate", "slim", "slender", "lithe", "nimble", "agile", "swift", "fast", "quick", "rapid", "speedy", "hurried", "hasty", "brisk", "fleet", "flying"],
        "min_matches": MIN_MATCHES
    },

    # Catoblepas (duplicate - skip)

    # Centaur - Horse-human hybrid
    "CENTAUR": {
        "required_terms": ["horse", "human", "torso", "equine", "hybrid", "four-legged", "hooves", "greek", "mythological", "half-man", "half-horse", "upper body", "lower body", "archer", "bow", "wild", "thessalian", "sagittarius", "constellation", "chiron", "pholus", "nessus", "wise", "tutor", "healer", "man-horse", "barbarian", "tribal", "herd", "galloping", "hippocentaur", "centaurides", "female centaur", "centauress", "thessaly", "pelion", "centauromachy", "lapiths", "wine", "wildness", "civilization vs wildness", "dual nature", "horse body", "human chest", "human arms", "human head"],
        "forbidden_terms": ["scaled", "feathered", "reptile", "snake", "serpent", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton", "antennae", "mandibles", "pincers", "stinger", "wings", "winged", "flying", "soaring"],
        "min_matches": MIN_MATCHES
    },

    # Cerberus - Three-headed dog
    "CERBERUS": {
        "required_terms": ["three-headed", "three heads", "dog", "hound", "heads", "underworld", "gate", "guardian", "hell", "greek", "hades", "mythological", "serpent tail", "serpent mane", "bronze throat", "barking", "hellhound", "kerberos", "entrance to underworld", "styx", "acheron", "hercules", "twelfth labor", "captured", "adamantine chain", "multi-headed", "three throats", "three barks", "snake-headed tail", "snake mane", "snake around neck", "bronze-voiced", "brazen-throated", "souls entrance", "prevents escape", "prevents return", "hound of hades", "orthrus brother"],
        "forbidden_terms": ["one-headed", "single-headed", "dragon", "reptile", "lizard", "scales only", "bird", "feathers", "winged", "flying", "soaring", "gliding", "humanoid", "bipedal", "upright", "two-legged", "talking", "speaking", "intelligent speech"],
        "min_matches": MIN_MATCHES
    },

    # Changeling - Fairy substitute
    "CHANGELING": {
        "required_terms": ["changeling", "fairy", "fae", "substitute", "replacement", "swap", "exchange", "human child", "baby", "infant", "stolen", "abducted", "taken", "left behind", "sickly", "ill", "weak", "frail", "deformed", "ugly", "screaming", "crying", "constant", "demanding", "hungry", "eating", "never satisfied", "wood", "log", "enchanted", "glamour", "illusion", "reveal", "trick", "test", "hot iron", "eggshell", "brew", "pot", "folklore", "celtic", "norse", "germanic"],
        "forbidden_terms": ["healthy", "strong", "robust", "hearty", "vigorous", "well", "normal", "ordinary", "typical", "average", "common", "natural", "real", "genuine", "authentic", "true"],
        "min_matches": MIN_MATCHES
    },

    # Chimera - Hybrid monster
    "CHIMERA": {
        "required_terms": ["lion", "goat", "dragon", "snake", "tail", "heads", "multiple", "hybrid", "greek", "fire-breathing", "lycia", "asia minor", "bellerophon", "pegasus", "three animals", "lion front", "goat middle", "snake back", "composite", "monstrous", "terrifying", "flame", "breath weapon", "homer", "iliad", "mythological", "chimeric", "hybrid creature", "lion head", "goat head rising", "serpent tail", "lion body", "goat torso", "serpent for tail", "fire from mouth", "invulnerable", "impossible beast", "slain by bellerophon", "lycian monster"],
        "forbidden_terms": ["single head", "simple", "uniform", "consistent", "pure", "unmixed", "non-hybrid", "single species", "natural", "normal", "ordinary", "commonplace", "familiar", "everyday", "mundane", "unremarkable"],
        "min_matches": MIN_MATCHES
    },

    # Chupacabra - Bloodsucker
    "CHUPACABRA": {
        "required_terms": ["blood", "goat", "sucker", "goat sucker", "reptile", "spikes", "spined", "back", "canine", "alien", "legend", "puerto rican", "latin america", "mystery", "cryptid", "livestock", "drains blood", "three puncture wounds", "vampire", "hairless", "dog-like", "kangaroo-like", "jumping", "eyes", "red eyes", "glowing eyes", "bipedal", "hopping", "puerto rico", "mexico", "latin american", "cryptozoology", "unexplained", "mysterious creature", "livestock mutilation", "exsanguinated animals", "puncture wounds", "leathery skin", "gray skin", "greenish skin", "spines down back", "quills", "glowing red eyes", "alien-like", "hopping gait", "kangaroo legs"],
        "forbidden_terms": ["divine", "angelic", "holy", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "benevolent", "charitable", "giving", "selfless", "altruistic"],
        "min_matches": MIN_MATCHES
    },

    # Cluricaun - Irish solitary fairy
    "CLURICAUN": {
        "required_terms": ["cluricaun", "cluricaune", "irish", "fairy", "fae", "solitary", "loner", "drunk", "drunken", "wine", "whiskey", "liquor", "alcohol", "intoxicated", "mischievous", "trickster", "prankster", "cellar", "wine cellar", "tavern", "pub", "steal", "rob", "drink", "sip", "guzzle", "carouse", "revel", "party", "night", "nocturnal", "small", "diminutive", "tiny", "green", "red cap", "buckled shoes", "leather apron", "cobbler", "shoemaker", "leprechaun cousin", "folklore"],
        "forbidden_terms": ["sober", "temperate", "abstinent", "teetotal", "serious", "solemn", "grave", "earnest", "somber", "gloomy", "morose", "melancholy", "sad", "unhappy", "depressed"],
        "min_matches": MIN_MATCHES
    },

    # Cockatrice - Rooster-dragon
    "COCKATRICE": {
        "required_terms": ["rooster", "chicken", "cockscomb", "dragon", "wings", "lizard", "tail", "gaze", "petrify", "bird", "reptile", "hybrid", "serpent", "scales", "feathers", "beak", "claws", "crow", "deadly stare", "turn to stone", "basilisk cousin", "hatched from egg", "toad egg", "cockerel", "seven years old", "cockatrice", "regulus", "little king", "wyvern-like", "two legs", "leathery wings", "feathered body", "scaly tail", "spur", "poisonous spur", "lethal touch", "fatal glance", "weasel enemy", "weasel kills it", "rue plant", "medieval bestiary"],
        "forbidden_terms": ["mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats", "placental", "marsupial", "pouched", "monotreme", "egg-laying mammal", "platypus", "echidna", "primate", "ape", "monkey"],
        "min_matches": MIN_MATCHES
    },

    # Cu Sith - Fairy hound
    "CU_SITH": {
        "required_terms": ["cu sith", "cù-sìth", "scottish", "gaelic", "highlands", "fairy hound", "fairy dog", "fae", "dog", "hound", "green", "dark green", "emerald", "shaggy", "shaggy coat", "long tail", "braided tail", "plaited tail", "large", "size of cow", "cattle", "nocturnal", "night", "silent", "soundless", "quiet", "stealthy", "sneaky", "hunt", "hunting", "stalk", "stalker", "lair", "cave", "mountain", "isle of sky", "highland", "folklore", "supernatural"],
        "forbidden_terms": ["small", "tiny", "diminutive", "miniature", "minuscule", "petite", "wee", "little", "brown", "gray", "black", "white", "ordinary", "normal", "common", "domestic", "pet", "tame", "friendly", "gentle", "soft", "cuddly", "affectionate"],
        "min_matches": MIN_MATCHES
    },

    # Cwn Annwn - Welsh otherworld hounds
    "CWN_ANNWN": {
        "required_terms": ["cwn annwn", "welsh", "cymru", "annwn", "otherworld", "underworld", "hounds", "dogs", "white", "red ears", "blood red", "glowing", "gleaming", "spectral", "ghostly", "spirit", "apparition", "phantom", "wild hunt", "fairy", "fae", "supernatural", "nocturnal", "night", "sky", "flying", "soaring", "honking", "cackling", "laughing", "geese", "wild geese", "omen", "death", "doom", "harbinger", "foretell", "herald", "cymru", "wales", "celtic", "mythology"],
        "forbidden_terms": ["brown", "black", "gray", "ordinary", "normal", "common", "domestic", "pet", "tame", "friendly", "gentle", "soft", "cuddly", "affectionate", "helpful", "benevolent", "kind", "caring", "compassionate"],
        "min_matches": MIN_MATCHES
    },

    # Cyclops - One-eyed giant
    "CYCLOPS": {
        "required_terms": ["one-eyed", "single eye", "giant", "large", "greek", "forge", "shepherd", "eyebrow", "huge", "massive", "colossal", "towering", "humanoid", "brontes", "steropes", "arges", "polyphemus", "odysseus", "homer", "hesiod", "theogony", "hephaestus", "thunderbolt", "lightning", "forge", "smith", "metalworker", "craftsman", "blacksmith", "cyclopean", "masonry", "massive stones", "shepherd", "sheep", "flocks", "cave-dwelling", "sicily", "thrace", "forehead eye", "central eye", "round eye", "fearsome", "man-eating"],
        "forbidden_terms": ["two-eyed", "multiple eyes", "compound eyes", "many-eyed", "four-eyed", "hundred-eyed", "argus", "extra eyes", "additional eyes", "eye stalks", "eyestalks", "eyes on stalks", "small eyes", "tiny eyes", "beady eyes"],
        "min_matches": MIN_MATCHES
    },

    # Demon - Generic evil spirit
    "DEMON": {
        "required_terms": ["demon", "evil", "infernal", "hell", "horn", "wing", "claw", "malevolent", "chaos", "darkness", "corruption", "sin", "damnation", "soul", "temptation", "possession", "fiend", "devil", "fallen", "abyssal", "demonic", "hellish", "wicked", "sinister", "malicious", "cruel", "savage", "brutal", "vicious", "monstrous", "grotesque", "hideous", "fearsome", "terrifying", "dreadful", "supernatural", "spirit", "entity", "being", "force", "power", "dark one"],
        "forbidden_terms": ["holy", "divine", "angelic", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "benevolent", "charitable", "giving", "selfless", "altruistic", "heavenly"],
        "min_matches": MIN_MATCHES
    },

    # Deva - Buddhist deity
    "DEVA": {
        "required_terms": ["deva", "deity", "god", "hindu", "buddhist", "jain", "celestial", "heavenly", "divine", "radiant", "glowing", "luminous", "shining", "benevolent", "kind", "compassionate", "wisdom", "knowledge", "power", "strength", "beautiful", "youthful", "immortal", "long-lived", "heaven", "svarga", "indra", "agui", "vayu", "surya", "chandra", "varuna", "yama", "kama", "gandharva", "apsara", "spirit", "supernatural", "asian", "indian"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "demonic", "infernal", "hellish", "abyssal"],
        "min_matches": MIN_MATCHES
    },

    # Dobbie - English house spirit
    "DOBBIE": {
        "required_terms": ["dobbie", "dobie", "english", "northern england", "household", "spirit", "fairy", "fae", "brownie", "hob", "helpful", "benevolent", "kind", "cleaning", "chores", "work", "night", "nocturnal", "invisible", "offering", "bowl of milk", "cream", "porridge", "honey", "grateful", "appreciation", "gift", "reward", "offend", "insult", "offended", "angered", "annoyed", "leave", "depart", "abandon", "move", "mischief", "prank", "trickster", "domestic", "home", "hearth", "fireplace"],
        "forbidden_terms": ["evil", "malevolent", "demon", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "fiery", "flaming"],
        "min_matches": MIN_MATCHES
    },
    # Dobhran - Scottish otter spirit
    "DOBHRAN": {
        "required_terms": ["dobhran", "otter", "scottish", "gaelic", "highlands", "water", "river", "loch", "stream", "spirit", "fairy", "fae", "shape-shifter", "shapeshifter", "transformer", "human form", "animal form", "sleek", "smooth", "dark fur", "brown", "web feet", "webbed paws", "swim", "dive", "fish", "hunt", "elusive", "rare", "sighting", "glimpse", "protective", "guardian", "water guardian", "river guardian", "loch guardian", "celtic", "mythology", "folklore"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Dolor - Personification of pain
    "DOLOR": {
        "required_terms": ["dolor", "dolour", "pain", "suffering", "anguish", "agony", "grief", "sorrow", "misery", "woe", "torment", "torture", "personification", "embodiment", "allegory", "roman", "latin", "mythology", "abstract", "concept", "emotion", "feeling", "human condition", "mortal", "life", "existence", "shadow", "dark", "gloom", "mourning", "lament", "weeping", "tears", "crying", "despair", "hopelessness"],
        "forbidden_terms": ["joy", "happiness", "pleasure", "delight", "bliss", "ecstasy", "euphoria", "contentment", "satisfaction", "fulfillment", "peace", "calm", "serenity", "tranquility", "quiet", "still", "rest", "comfort", "ease", "relief", "solace", "consolation"],
        "min_matches": MIN_MATCHES
    },

    # Domovoi - Slavic household spirit
    "DOMOVOI": {
        "required_terms": ["household", "spirit", "slavic", "beard", "old man", "home", "protector", "domestic", "fireplace", "hearth", "ancestral", "ancestor spirit", "grandfather", "domovoy", "russian", "ukrainian", "polish", "czech", "slovak", "house spirit", "house elf", "brownie-like", "bearded", "gray beard", "covered in fur", "small", "tiny", "nocturnal", "invisible", "murmuring", "moaning", "predicts death", "warns of misfortune", "favored family", "dislikes lazy", "dislikes messy", "punishes disrespect", "protects livestock"],
        "forbidden_terms": ["evil", "malevolent", "demon", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "fiery", "flaming"],
        "min_matches": MIN_MATCHES
    },

    # Doppelganger - Evil twin
    "DOPPELGANGER": {
        "required_terms": ["shapeshifter", "copy", "mirror", "double", "imitate", "form", "changeling", "identical", "appearance", "duplicate", "replica", "look-alike", "twin", "evil twin", "dark twin", "shadow self", "other self", "double walker", "fetch", "co-walker", "vardogr", "germanic", "folklore", "supernatural", "spirit", "entity", "being", "impostor", "pretender", "usurper", "replaces", "assumes identity", "mimics voice", "mimics mannerisms", "knows your thoughts", "knows your memories", "harbinger of death", "bad omen"],
        "forbidden_terms": ["single form", "fixed appearance", "static", "unchanging", "immutable", "permanent", "constant", "consistent", "uniform", "invariable", "stable", "steady", "regular", "predictable", "reliable", "dependable", "trustworthy"],
        "min_matches": MIN_MATCHES
    },

    # Dracolich - Undead dragon
    "DRACOLICH": {
        "required_terms": ["undead", "dragon", "skeletal", "lich", "bones", "necromancy", "soul", "phylactery", "immortal", "decay", "skeleton", "skull", "ribs", "spine", "tail bones", "wing bones", "hollow eyes", "glowing eyes", "soul gems", "dracolich", "dragon lich", "undead dragon", "lich dragon", "corporeal undead", "intelligent undead", "spellcasting", "magical", "evil", "malevolent", "terrifying", "dread", "fearsome", "ancient", "powerful", "mighty", "dungeons and dragons", "d&d", "forgotten realms", "dragonlance", "krynn"],
        "forbidden_terms": ["living", "alive", "flesh", "skin", "muscle", "tissue", "organs", "heart", "lungs", "stomach", "intestines", "blood", "veins", "arteries", "circulatory", "respiratory", "digestive", "metabolism", "warm-blooded", "living tissue"],
        "min_matches": MIN_MATCHES
    },

    # Dragon - Legendary reptile
    "DRAGON": {
        "required_terms": ["dragon", "wing", "scale", "reptile", "fire", "breath", "claw", "tail", "horn", "majestic", "serpentine", "wyrm", "wyvern", "draco", "draconic", "reptilian", "scaly", "armored", "powerful", "mighty", "ancient", "legendary", "mythical", "mythological", "treasure", "hoard", "gold", "gems", "lair", "cave", "mountain", "volcano", "forest", "lake", "sea", "sky", "airborne", "flying", "soaring", "gliding", "fearsome", "terrifying", "dreadful"],
        "forbidden_terms": ["mammal", "fur", "feather", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats", "placental", "marsupial", "pouched", "monotreme", "egg-laying mammal", "platypus"],
        "min_matches": MIN_MATCHES
    },

    # Drake - Dragon relative
    "DRAKE": {
        "required_terms": ["drake", "dragon", "four legs", "winged", "lesser", "reptile", "scale", "tail", "beast", "draconic", "reptilian", "scaly", "lizard-like", "serpentine", "primitive", "animalistic", "feral", "wild", "untamed", "predator", "carnivorous", "hunter", "stalker", "ambush", "lair", "cave", "mountain", "forest", "swamp", "desert", "arctic", "elemental", "fire", "ice", "poison", "lightning", "breath weapon", "claws", "fangs", "jaws", "talons"],
        "forbidden_terms": ["humanoid", "intelligent", "wise", "cunning", "clever", "scheming", "plotting", "planning", "speech", "language", "communication", "spellcasting", "magical", "supernatural", "divine", "holy", "sacred", "blessed", "pure"],
        "min_matches": MIN_MATCHES
    },

    # Draugr - Norse undead
    "DRAUGR": {
        "required_terms": ["undead", "norse", "viking", "warrior", "tomb", "burial", "decay", "rotting", "weapon", "guardian", "draugr", "haugbui", "aptrgangr", "scandinavian", "icelandic", "saga", "edda", "barrow", "mound", "burial mound", "grave goods", "treasure guardian", "revenant", "risen dead", "walking dead", "corpse", "blue-black", "swollen", "hideous", "fearsome", "superhuman strength", "shape-shifting", "increased size", "magical", "cursed", "malevolent", "killed by beheading", "cremate to destroy", "burning", "fire", "sunlight"],
        "forbidden_terms": ["living", "alive", "holy", "divine", "angelic", "blessed", "sacred", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle"],
        "min_matches": MIN_MATCHES
    },

    # Dryad - Tree nymph
    "DRYAD": {
        "required_terms": ["tree", "nymph", "forest", "wood", "bark", "leaf", "green", "spirit", "greek", "nature", "dryad", "hamadryad", "oak", "tree spirit", "wood nymph", "female", "beautiful", "ethereal", "graceful", "delicate", "immortal", "long-lived", "bound to tree", "tree life", "dies if tree dies", "protector of trees", "forest guardian", "woodland", "grove", "sacred grove", "wild", "untamed", "shy", "elusive", "rarely seen", "dances in moonlight", "plays with satyrs"],
        "forbidden_terms": ["undead", "evil", "demonic", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Duergar - Dark dwarves
    "DUERGAR": {
        "required_terms": ["dwarf", "dark", "gray", "gray skin", "underdark", "subterranean", "underground", "cavern", "tunnel", "mine", "evil", "malevolent", "cruel", "vicious", "grim", "stern", "hard", "unyielding", "smith", "forge", "metalwork", "craftsman", "artisan", "invisible", "invisibility", "enlarge", "grow", "increase size", "shadow", "darkness", "hate", "hatred", "surface dwellers", "elves", "norse", "germanic", "dungeons and dragons", "d&d", "forgotten realms"],
        "forbidden_terms": ["light", "surface", "sun", "sunlight", "bright", "radiant", "luminous", "golden", "fair", "blonde", "sun-kissed", "outdoors", "forest", "woodland", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Dullahan - Headless horseman
    "DULLAHAN": {
        "required_terms": ["headless", "horseman", "rider", "horse", "irish", "head", "carry", "spine", "whip", "death", "dullahan", "dulachan", "gan ceann", "fairy", "faerie", "headless rider", "head under arm", "head held high", "grinning head", "decayed head", "rotting head", "hollow eyes", "black horse", "black steed", "fiery eyes", "flaming eyes", "human spine whip", "spine whip", "bucket of blood", "blood", "sprinkle blood", "death omen", "calls out name", "person dies", "cannot be stopped", "gates open", "locks fall", "no appeal", "fearless"],
        "forbidden_terms": ["has head", "complete", "whole", "intact", "unharmed", "uninjured", "normal", "ordinary", "commonplace", "familiar", "everyday", "mundane"],
        "min_matches": MIN_MATCHES
    },

    # Dunnie - Scottish horse spirit
    "DUNNIE": {
        "required_terms": ["dunnie", "scottish", "highlands", "horse", "pony", "spirit", "fairy", "fae", "nocturnal", "night", "darkness", "shadows", "stream", "river", "water", "ford", "crossing", "lure", "tempt", "entice", "attract", "ride", "mount", "back", "leap on", "carry off", "abduct", "take", "disappear", "vanish", "mountain", "hill", "moor", "wild", "untamed", "elusive", "rare", "sighting", "glimpse", "folklore", "celtic"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Dwarf - Short humanoid
    "DWARF": {
        "required_terms": ["dwarf", "short", "beard", "forge", "smith", "miner", "stone", "metal", "stocky", "strong", "sturdy", "muscular", "broad", "wide", "hearty", "hardy", "rugged", "tough", "resilient", "durable", "enduring", "long-lived", "underground", "mountain", "cavern", "tunnel", "mine", "gems", "gold", "silver", "iron", "steel", "mithril", "adamantine", "craftsman", "artisan", "weaponsmith", "armorsmith", "jeweler", "miner", "delver", "deep", "underdark"],
        "forbidden_terms": ["tall", "elf", "slender", "slim", "thin", "lithe", "willowy", "graceful", "elegant", "delicate", "refined", "cultured", "sophisticated", "educated"],
        "min_matches": MIN_MATCHES
    },

    # Ebon - Dark creature
    "EBON": {
        "required_terms": ["dark", "black", "shadow", "midnight", "void", "darkness", "pitch black", "jet black", "coal black", "sable", "inky", "murky", "gloomy", "tenebrous", "stygian", "cimmerian", "lightless", "unlit", "unilluminated", "darkened", "shaded", "shadowy", "obscure", "hidden", "concealed", "veiled", "shrouded", "cloaked"],
        "forbidden_terms": ["light", "bright", "radiant", "luminous", "incandescent", "fluorescent", "phosphorescent", "glowing", "gleaming", "shining", "sparkling", "glittering", "twinkling", "scintillating", "effulgent", "refulgent", "brilliant"],
        "min_matches": MIN_MATCHES
    },

    # Efreet - Fire genie
    "EFREET": {
        "required_terms": ["efreet", "fire", "flame", "genie", "djinn", "elemental", "hot", "smoke", "arabian", "brass", "ifrit", "efrit", "afrit", "islamic", "arabian nights", "jinn", "jinni", "demon", "spirit", "powerful", "malevolent", "wrathful", "cunning", "deceptive", "wish-granter", "wishes twisted", "fire form", "made of fire", "smoke form", "brass lamp", "brass vessel", "imprisoned", "servant", "master", "fire magic", "pyrokinesis", "heat aura", "desert"],
        "forbidden_terms": ["cold", "water", "ice", "snow", "frost", "arctic", "winter", "freezing", "frigid", "glacial", "polar", "north", "alpine", "chilly", "cool"],
        "min_matches": MIN_MATCHES
    },

    # Elemental Air - Air elemental
    "ELEMENTAL_AIR": {
        "required_terms": ["air", "wind", "storm", "cloud", "sky", "atmosphere", "elemental", "primordial", "elemental being", "elemental spirit", "air spirit", "wind spirit", "living air", "living wind", "animated air", "moving air", "flowing wind", "gust", "gale", "breeze", "draft", "zephyr", "cyclone", "hurricane", "typhoon", "tornado", "whirlwind", "invisible", "unseen", "formless", "shapeless", "gaseous", "vaporous", "mist", "fog"],
        "forbidden_terms": ["earth", "stone", "rock", "ground", "soil", "dirt", "clay", "mud", "water", "liquid", "fluid", "fire", "flame", "burning", "heat", "hot", "solid", "hard", "dense", "heavy", "massive"],
        "min_matches": MIN_MATCHES
    },

    # Elemental Earth - Earth elemental
    "ELEMENTAL_EARTH": {
        "required_terms": ["earth", "stone", "rock", "clay", "mud", "ground", "soil", "mountain", "elemental", "primordial", "elemental being", "elemental spirit", "earth spirit", "living rock", "living stone", "animated earth", "moving earth", "shifting ground", "boulder", "pebble", "gravel", "sand", "dust", "dirt", "loam", "mineral", "crystal", "gem", "ore", "metal", "heavy", "solid", "dense", "massive"],
        "forbidden_terms": ["fire", "air", "water", "flame", "wind", "wave", "cloud", "smoke", "steam", "mist", "fog", "vapor", "gas", "liquid", "fluid", "flowing", "fluid motion"],
        "min_matches": MIN_MATCHES
    },

    # Elemental Fire - Fire elemental
    "ELEMENTAL_FIRE": {
        "required_terms": ["fire", "flame", "burn", "heat", "ember", "smoke", "spark", "inferno", "elemental", "primordial", "elemental being", "elemental spirit", "fire spirit", "living flame", "living fire", "animated flame", "moving fire", "shifting flame", "blaze", "conflagration", "wildfire", "bonfire", "campfire", "fireball", "firestorm", "pyre", "combustion", "ignition", "hot", "scorching", "searing"],
        "forbidden_terms": ["water", "ice", "cold", "earth", "air", "liquid", "fluid", "wave", "stream", "river", "ocean", "sea", "lake", "pond", "puddle", "rain", "snow", "hail"],
        "min_matches": MIN_MATCHES
    },

    # Elemental Water - Water elemental
    "ELEMENTAL_WATER": {
        "required_terms": ["water", "wave", "liquid", "current", "tide", "ocean", "river", "sea", "fluid", "elemental", "primordial", "elemental being", "elemental spirit", "water spirit", "living water", "living liquid", "animated water", "moving water", "flowing water", "stream", "brook", "creek", "lake", "pond", "pool", "puddle", "rain", "dew", "mist", "fog", "vapor", "steam", "cloud", "ice", "snow", "hail", "sleet"],
        "forbidden_terms": ["fire", "earth", "rock", "stone", "boulder", "mountain", "hill", "valley", "cave", "cavern", "tunnel", "mine", "underground", "subterranean", "ground"],
        "min_matches": MIN_MATCHES
    },

    # Elf Dark - Dark elf
    "ELF_DARK": {
        "required_terms": ["dark", "black", "drow", "underdark", "evil", "spider", "nocturnal", "pale", "white hair", "elf", "elven", "humanoid", "pointed ears", "slender", "graceful", "agile", "dexterous", "nimble", "quick", "fast", "stealthy", "sneaky", "magical", "arcane", "spellcaster", "wizard", "sorcerer", "cleric", "priestess", "lolth", "spider goddess", "web", "poison", "darkvision", "sunlight sensitivity", "underground city", "cavern", "cave", "tunnel", "forgotten realms"],
        "forbidden_terms": ["light", "surface", "day", "sun", "sunlight", "bright", "radiant", "luminous", "golden", "fair", "blonde", "sun-kissed", "outdoors", "forest", "woodland"],
        "min_matches": MIN_MATCHES
    },

    # Elf Forest - Wood elf
    "ELF_FOREST": {
        "required_terms": ["forest", "wood", "green", "nature", "tree", "leaf", "bow", "wild", "camouflage", "elf", "elven", "humanoid", "pointed ears", "slender", "graceful", "agile", "dexterous", "nimble", "quick", "fast", "stealthy", "sneaky", "ranger", "archer", "tracker", "hunter", "woodland", "forest", "grove", "treehouse", "nature magic", "druid", "animal friend", "wilderness", "untamed"],
        "forbidden_terms": ["underground", "dark", "evil", "cave", "cavern", "tunnel", "underdark", "drow", "spider", "pale", "white hair", "black", "shadow", "umbra"],
        "min_matches": MIN_MATCHES
    },

    # Elf High - High elf
    "ELF_HIGH": {
        "required_terms": ["high", "noble", "elegant", "magic", "ancient", "golden", "regal", "wise", "graceful", "elf", "elven", "humanoid", "pointed ears", "slender", "tall", "beautiful", "fair", "blonde", "silver hair", "golden hair", "pale skin", "arcanist", "wizard", "sorcerer", "mage", "spellcaster", "magical", "arcane", "civilized", "cultured", "sophisticated", "refined", "educated", "learned"],
        "forbidden_terms": ["primitive", "savage", "wild", "untamed", "feral", "barbaric", "rude", "crude", "coarse", "rough", "uncivilized", "uncultured", "uneducated"],
        "min_matches": MIN_MATCHES
    },

    # Enfield - Irish hybrid
    "ENFIELD": {
        "required_terms": ["enfield", "irish", "heraldic", "coat of arms", "crest", "emblem", "hybrid", "composite", "fox", "head", "chest", "greyhound", "body", "wolf", "hindquarters", "eagle", "talons", "mythical", "legendary", "celtic", "ireland", "dublin", "county dublin", "enfield", "london", "middlesex", "chimerical", "beast", "creature", "symbol", "icon"],
        "forbidden_terms": ["dragon", "serpent", "snake", "reptile", "scales", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills"],
        "min_matches": MIN_MATCHES
    },

    # Erinyes - Greek furies
    "ERINYES": {
        "required_terms": ["erinyes", "fury", "furies", "eumenides", "greek", "vengeance", "retribution", "justice", "punishment", "goddess", "female", "winged", "snake", "serpent", "hair", "writhing", "torch", "whip", "scourge", "blood", "dripping", "hunt", "pursue", "torment", "torture", "curse", "oath", "broken oath", "murder", "patricide", "matricide", "family crime", "underworld", "hades", "tartarus", "alecto", "megaera", "tisiphone", "dread", "fear", "horror"],
        "forbidden_terms": ["kind", "gentle", "merciful", "forgiving", "compassionate", "sympathetic", "benevolent", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "good"],
        "min_matches": MIN_MATCHES
    },

    # Erpching - German dwarf
    "ERPCHING": {
        "required_terms": ["erpching", "german", "germanic", "dwarf", "small", "tiny", "diminutive", "underground", "subterranean", "mountain", "hill", "cavern", "mine", "miner", "smith", "forge", "metalwork", "craftsman", "artisan", "treasure", "gold", "silver", "gems", "hoard", "guardian", "protector", "elusive", "rare", "sighting", "folklore", "mythology", "teutonic", "alpine", "bavarian", "swabian", "black forest"],
        "forbidden_terms": ["tall", "elf", "slender", "slim", "thin", "lithe", "willowy", "graceful", "elegant", "delicate", "refined", "cultured", "sophisticated", "educated", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel"],
        "min_matches": MIN_MATCHES
    },

    # Fachan - Scottish one-sided giant
    "FACHAN": {
        "required_terms": ["fachan", "scottish", "gaelic", "highlands", "giant", "monstrous", "grotesque", "one-eyed", "single eye", "one-armed", "single arm", "one-legged", "single leg", "protruding from chest", "central", "middle", "asymmetrical", "misshapen", "deformed", "malformed", "ugly", "hideous", "fearsome", "terrifying", "iron claws", "sharp claws", "powerful", "strong", "malevolent", "wicked", "cruel", "violent", "aggressive", "hateful", "malicious", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["beautiful", "symmetrical", "balanced", "proportional", "normal", "ordinary", "typical", "average", "common", "two-eyed", "two-armed", "two-legged", "bilateral", "symmetric"],
        "min_matches": MIN_MATCHES
    },

    # Fairy - Tiny winged being
    "FAIRY": {
        "required_terms": ["fairy", "tiny", "small", "wing", "magic", "glow", "sparkle", "flower", "fae", "delicate", "faerie", "faery", "fay", "wee folk", "little people", "diminutive", "minuscule", "miniature", "pixie", "sprite", "elfin", "ethereal", "gossamer", "translucent", "transparent", "iridescent", "rainbow", "butterfly wings", "dragonfly wings", "glowing", "luminous", "sparkling", "shimmering", "glittering", "twinkling", "magical dust", "fairy dust"],
        "forbidden_terms": ["large", "massive", "giant", "huge", "enormous", "colossal", "gargantuan", "towering", "mountainous", "immense", "vast", "prodigious", "monstrous size"],
        "min_matches": MIN_MATCHES
    },

    # Far Darrig - Irish practical joker
    "FAR_DARRIG": {
        "required_terms": ["far darrig", "fear darrig", "fear dearg", "irish", "fairy", "fae", "solitary", "loner", "red", "red cap", "red clothes", "red hair", "mischievous", "trickster", "prankster", "joker", "practical jokes", "cruel", "mean", "spiteful", "malicious", "horrible", "awful", "nightmare", "terror", "fear", "dread", "bag", "sack", "carry off", "abduct", "kidnap", "victims", "prey", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["kind", "gentle", "benevolent", "helpful", "caring", "compassionate", "empathetic", "sympathetic", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "good"],
        "min_matches": MIN_MATCHES
    },

    # Fenoderee - Manx fairy servant
    "FENODEREE": {
        "required_terms": ["fenoderee", "fynnoderee", "manx", "isle of man", "fairy", "fae", "servant", "helper", "brownie-like", "brownie", "ugly", "grotesque", "hideous", "hairy", "shaggy", "strong", "powerful", "mighty", "work", "labor", "chores", "farm work", "field work", "harvest", "threshing", "winnowing", "reaping", "mowing", "plowing", "night", "nocturnal", "invisible", "unseen", "offended", "angered", "insulted", "leave", "depart", "abandon", "sad", "mournful", "melancholy"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Fenrir - Norse wolf
    "FENRIR": {
        "required_terms": ["wolf", "fenrir", "norse", "giant", "mythological", "chain", "gleipnir", "ragnarok", "monstrous", "fenris", "fenris wolf", "fenrisúlfr", "loki son", "angrboda son", "jotunn", "giant wolf", "enormous", "massive", "colossal", "fearsome", "terrifying", "dreadful", "devouring", "swallowing", "odin eater", "bound", "shackled", "chained", "magic chain", "ribbon", "unbreakable", "breaks free", "ragnarok", "end of world", "twilight of gods"],
        "forbidden_terms": ["good", "benevolent", "small", "tiny", "diminutive", "minor", "lesser", "weak", "frail", "delicate", "fragile", "puny", "feeble", "powerless"],
        "min_matches": MIN_MATCHES
    },

    # Fetch - Irish spirit double
    "FETCH": {
        "required_terms": ["fetch", "irish", "celtic", "spirit", "double", "apparition", "phantom", "ghost", "specter", "doppelganger", "double walker", "co-walker", "death omen", "harbinger", "foretell", "predict", "warn", "warning", "sighting", "seen by friend", "seen by family", "seen by self", "impending death", "near death", "mortal danger", "illness", "sickness", "doom", "fate", "destiny", "supernatural", "paranormal", "folklore", "mythology"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living", "alive"],
        "min_matches": MIN_MATCHES
    },

    # Fir Darrig - Irish red man
    "FIR_DARRIG": {
        "required_terms": ["fir darrig", "fear darrig", "fear dearg", "irish", "fairy", "fae", "solitary", "loner", "red", "red cap", "red clothes", "red hair", "mischievous", "trickster", "prankster", "joker", "practical jokes", "cruel", "mean", "spiteful", "malicious", "horrible", "awful", "nightmare", "terror", "fear", "dread", "bag", "sack", "carry off", "abduct", "kidnap", "victims", "prey", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["kind", "gentle", "benevolent", "helpful", "caring", "compassionate", "empathetic", "sympathetic", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "good"],
        "min_matches": MIN_MATCHES
    },

    # Follet - French goblin
    "FOLLET": {
        "required_terms": ["follet", "french", "goblin", "spirit", "fairy", "fae", "mischievous", "trickster", "prankster", "small", "tiny", "diminutive", "nocturnal", "night", "darkness", "shadows", "lights", "will-o-wisp", "feu follet", "flickering", "glowing", "dancing lights", "marsh", "swamp", "bog", "fen", "forest", "woods", "rural", "countryside", "folklore", "mythology", "lure", "lead astray", "mislead", "deceive", "trick", "confuse", "disorient"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Fomorian - Irish giant
    "FOMORIAN": {
        "required_terms": ["fomorian", "giant", "irish", "celtic", "misshapen", "one-eyed", "monstrous", "sea", "demon", "fomor", "fomori", "fomorians", "fomhoire", "irish mythology", "ulster cycle", "mythological cycle", "balor", "balor of the evil eye", "eye that kills", "death gaze", "petrifying gaze", "deformed", "grotesque", "hideous", "ugly", "misshapen", "malformed", "deformed", "twisted", "crooked", "giant size", "massive", "powerful", "strong", "brutal", "savage", "wild"],
        "forbidden_terms": ["beautiful", "perfect", "handsome", "pretty", "attractive", "comely", "fair", "lovely", "gorgeous", "radiant", "glowing", "graceful", "elegant"],
        "min_matches": MIN_MATCHES
    },

    # Forest Spirit - Nature spirit
    "FOREST_SPIRIT": {
        "required_terms": ["forest", "spirit", "nature", "wood", "tree", "green", "guardian", "ancient", "moss", "woods", "wilderness", "wildwood", "grove", "copse", "thicket", "forest guardian", "woodland guardian", "protector of trees", "protector of animals", "nature spirit", "wood spirit", "tree spirit", "plant spirit", "leaf", "branch", "root", "bark", "fern", "moss", "lichen", "fungus", "mushroom", "flower"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Fossegrim - Scandinavian water spirit
    "FOSSEGRIM": {
        "required_terms": ["fossegrim", "grim", "scandinavian", "norwegian", "swedish", "water", "spirit", "waterfall", "foss", "cascade", "river", "stream", "fiddle", "violin", "music", "musician", "player", "melody", "tune", "song", "teach", "lessons", "offerings", "food", "meat", "silver", "coin", "throw", "waterfall", "haunting", "beautiful", "entrancing", "captivating", "lure", "attract", "entice", "tempt", "folklore", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Gabriel Hound - Welsh death hound
    "GABRIEL_HOUND": {
        "required_terms": ["gabriel hound", "gabriel's hound", "welsh", "cymru", "hounds", "dogs", "spectral", "ghostly", "spirit", "apparition", "phantom", "death omen", "harbinger", "foretell", "predict", "warn", "warning", "death", "doom", "fate", "destiny", "howl", "howling", "night", "nocturnal", "darkness", "shadows", "mist", "fog", "wild hunt", "fairy", "fae", "supernatural", "paranormal", "folklore", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Gallybeg - Orcadian sea creature
    "GALLYBEG": {
        "required_terms": ["gallybeg", "gally-beg", "orcadian", "orkney", "scottish", "sea", "ocean", "creature", "monster", "small", "tiny", "diminutive", "dark", "black", "sleek", "smooth", "seal-like", "otter-like", "slippery", "elusive", "rare", "sighting", "glimpse", "coastal", "shore", "rocks", "caves", "tide pools", "nocturnal", "night", "darkness", "shadows", "folklore", "mythology"],
        "forbidden_terms": ["large", "massive", "giant", "huge", "enormous", "colossal", "gargantuan", "towering", "mountainous", "immense", "vast", "prodigious", "monstrous size", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel"],
        "min_matches": MIN_MATCHES
    },

    # Gallytrot - Orcadian sea creature
    "GALLYTROT": {
        "required_terms": ["gallytrot", "gally-trot", "orcadian", "orkney", "scottish", "sea", "ocean", "creature", "monster", "larger", "bigger", "gallybeg", "counterpart", "dark", "black", "sleek", "smooth", "seal-like", "otter-like", "slippery", "elusive", "rare", "sighting", "glimpse", "coastal", "shore", "rocks", "caves", "tide pools", "nocturnal", "night", "darkness", "shadows", "folklore", "mythology"],
        "forbidden_terms": ["small", "tiny", "diminutive", "miniature", "minuscule", "petite", "wee", "little", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Gancanogh - Irish love fairy
    "GANCANOGH": {
        "required_terms": ["gancanogh", "geancánach", "irish", "fairy", "fae", "love", "lust", "desire", "passion", "seduction", "seducer", "romance", "romantic", "charmer", "charming", "handsome", "beautiful", "attractive", "alluring", "enticing", "tempting", "pipe", "tobacco", "smoking", "lure", "entice", "tempt", "attract", "women", "maidens", "girls", "affections", "heart", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["ugly", "hideous", "grotesque", "repulsive", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive"],
        "min_matches": MIN_MATCHES
    },

    # Gargoyle - Stone creature
    "GARGOYLE": {
        "required_terms": ["gargoyle", "stone", "rock", "carved", "grotesque", "wing", "perch", "cathedral", "statue", "gothic", "architecture", "building", "church", "notre dame", "medieval", "stone carving", "sculpture", "effigy", "figure", "gargouille", "water spout", "rain spout", "waterspout", "drainage", "protector", "guardian", "ward off evil", "apotropaic", "fearsome", "hideous", "ugly", "deformed", "monstrous", "animal-like", "humanoid", "bat-like wings"],
        "forbidden_terms": ["living flesh", "organic", "biological", "cellular", "tissue", "muscle", "skin", "fur", "hair", "feathers", "scales", "blood", "veins", "arteries", "heart", "lungs", "stomach", "intestines", "digestive", "metabolism"],
        "min_matches": MIN_MATCHES
    },

    # Ghost - Spirit of dead
    "GHOST": {
        "required_terms": ["ghost", "spirit", "apparition", "specter", "translucent", "haunt", "dead", "soul", "ethereal", "phantom", "wraith", "shade", "revenant", "spook", "spectre", "visitation", "manifestation", "appearance", "materialization", "incorporeal", "disembodied", "bodiless", "intangible", "impalpable", "insubstantial", "immaterial", "nonphysical", "spiritual", "otherworldly", "mist", "fog", "vapor", "smoke", "shadow", "gloom", "darkness", "light"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living"],
        "min_matches": MIN_MATCHES
    },

    # Ghoul - Undead flesh-eater
    "GHOUL": {
        "required_terms": ["ghoul", "undead", "flesh", "eat", "grave", "rotten", "decay", "corpse", "cannibal", "carrion", "carrion eater", "corpse eater", "flesh eater", "grave robber", "tomb robber", "necrophage", "necrophagous", "scavenger", "rotting", "putrid", "putrefying", "decomposing", "decaying", "rancid", "fetid", "stinking", "malodorous", "reeking", "foul", "noxious", "rank", "hideous", "ugly", "grotesque", "monstrous", "animalistic", "bestial"],
        "forbidden_terms": ["holy", "divine", "living", "alive", "fresh", "clean", "pure", "wholesome", "healthy", "hearty", "robust", "vigorous", "strong", "vital", "animated"],
        "min_matches": MIN_MATCHES
    },

    # Ghul - Arabian ghoul
    "GHUL": {
        "required_terms": ["ghul", "arabian", "desert", "shape-shifter", "corpse", "grave", "demon", "islamic", "ghoul", "arabian nights", "jinn", "djinn", "ifrit", "marid", "shapechanger", "shapeshifter", "transformer", "hyena", "hyena form", "desert spirit", "wasteland", "sands", "dunes", "oasis", "caravan", "traveler", "lure", "lead astray", "mislead", "deceive", "trick", "entrap", "capture", "eat flesh", "consume dead", "grave robber", "tomb robber", "cannibal"],
        "forbidden_terms": ["holy", "benevolent", "kind", "gentle", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Giant Frost - Ice giant
    "GIANT_FROST": {
        "required_terms": ["frost", "ice", "giant", "white", "blue", "cold", "snow", "jotun", "norse", "jotunn", "frost giant", "hrímþursar", "rime giant", "ice giant", "jötunn", "ymir", "thrym", "skadi", "niflheim", "niflheimr", "ice realm", "frozen", "freezing", "frigid", "glacial", "polar", "arctic", "tundra", "blizzard", "snowstorm", "hail", "icicle", "ice shard", "ice axe", "ice weapon"],
        "forbidden_terms": ["fire", "hot", "lava", "volcano", "magma", "molten", "burning", "blazing", "scorching", "searing", "heat", "warm", "tropical", "desert", "arid", "dry"],
        "min_matches": MIN_MATCHES
    },

    # Giant Stone - Stone giant
    "GIANT_STONE": {
        "required_terms": ["stone", "rock", "giant", "gray", "mountain", "cave", "stone-like", "stone giant", "rock giant", "mountain giant", "cavern giant", "cave giant", "rocky", "stony", "craggy", "rugged", "jagged", "sharp", "hard", "solid", "dense", "durable", "tough", "strong", "resilient", "sturdy", "stout", "earth-colored", "gray", "brown", "tan", "sand-colored", "granite", "basalt"],
        "forbidden_terms": ["fire", "ice", "flame", "frost", "hot", "cold", "burning", "freezing", "lava", "magma", "molten", "volcano", "volcanic", "glacier", "glacial"],
        "min_matches": MIN_MATCHES
    },

    # Gilly Dhu - Scottish tree spirit
    "GILLY_DHU": {
        "required_terms": ["gilly dhu", "ghillie dhu", "scottish", "gaelic", "highlands", "tree", "forest", "spirit", "fairy", "fae", "guardian", "protector", "wood", "woods", "woodland", "birch", "birch tree", "moss", "lichen", "leaves", "bark", "green", "brown", "wild", "untamed", "elusive", "rare", "sighting", "glimpse", "shy", "solitary", "loner", "male", "man", "humanoid", "human-like", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Glashtig - Manx water horse
    "GLASHTIG": {
        "required_terms": ["glashtig", "glashtyn", "manx", "isle of man", "water", "horse", "kelpie", "each-uisge", "water horse", "mythical", "creature", "shapeshifter", "transformer", "human form", "man", "handsome", "attractive", "seductive", "alluring", "lure", "entice", "tempt", "attract", "women", "maidens", "girls", "water", "stream", "river", "lake", "pool", "nocturnal", "night", "darkness", "shadows", "folklore", "celtic"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Gnome - Small humanoid
    "GNOME": {
        "required_terms": ["gnome", "small", "beard", "pointed hat", "garden", "trickster", "fae", "earth", "gnomish", "gnomelike", "diminutive", "tiny", "wee", "little", "pointed ears", "pointed shoes", "colorful clothes", "red hat", "blue hat", "gardener", "tinkerer", "inventor", "craftsman", "artisan", "jeweler", "clockmaker", "mechanic", "engineer", "alchemist", "herbalist", "potioneer", "jovial", "cheerful", "merry", "happy", "playful", "mischievous", "prankster"],
        "forbidden_terms": ["tall", "large", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal"],
        "min_matches": MIN_MATCHES
    },

    # Goannotgh - Irish fairy
    "GOANNOTGH": {
        "required_terms": ["goannotgh", "irish", "fairy", "fae", "solitary", "loner", "mischievous", "trickster", "prankster", "joker", "playful", "fun-loving", "merry", "cheerful", "happy", "joyful", "music", "song", "dance", "revelry", "celebration", "party", "festival", "green", "clothes", "pointed hat", "pointed shoes", "small", "tiny", "diminutive", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "moonlight", "starlight", "folklore", "celtic"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Goblin - Small evil humanoid
    "GOBLIN": {
        "required_terms": ["goblin", "small", "green", "ugly", "pointy ears", "long nose", "greedy", "mischievous", "goblinoid", "goblinkin", "goblinesque", "diminutive", "tiny", "wee", "little", "grotesque", "hideous", "homely", "unattractive", "wicked", "evil", "malevolent", "malicious", "mean-spirited", "cruel", "greedy", "avaricious", "covetous", "acquisitive", "rapacious", "voracious", "sneaky", "sly", "cunning", "crafty", "tricky", "devious", "underhanded"],
        "forbidden_terms": ["beautiful", "good", "benevolent", "handsome", "pretty", "attractive", "comely", "fair", "lovely", "gorgeous", "radiant", "glowing", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned"],
        "min_matches": MIN_MATCHES
    },

    # Golem - Animated construct
    "GOLEM": {
        "required_terms": ["golem", "construct", "animated", "clay", "stone", "metal", "jewish", "rabbi", "servant", "automaton", "robot", "android", "mechanical", "artificial", "man-made", "crafted", "created", "fashioned", "built", "forged", "sculpted", "molded", "shaped", "formed", "constructed", "lifeless", "inert", "inactive", "dormant", "motionless", "still", "animated by magic", "animated by runes", "animated by word", "shem"],
        "forbidden_terms": ["living", "breathing", "organic", "biological", "flesh", "blood", "bone", "muscle", "tissue", "organ", "heart", "lung", "brain", "nerve", "cell"],
        "min_matches": MIN_MATCHES
    },

    # Grim Reaper - Death personified
    "GRIM_REAPER": {
        "required_terms": ["grim reaper", "death", "reaper", "scythe", "cloak", "hood", "robe", "black", "dark", "skeleton", "skull", "bones", "hollow eyes", "glowing eyes", "soul", "spirit", "afterlife", "underworld", "dead", "dying", "mortality", "mortal", "inevitable", "unstoppable", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "harvest", "cut down", "collect", "gather", "souls", "spirits", "personification", "embodiment"],
        "forbidden_terms": ["living", "alive", "flesh", "skin", "muscle", "tissue", "organ", "heart", "lung", "brain", "blood", "veins", "arteries", "circulatory", "respiratory", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Grindylow - English water demon
    "GRINDYLOW": {
        "required_terms": ["grindylow", "english", "yorkshire", "lancashire", "water", "demon", "spirit", "creature", "monster", "pond", "pool", "marsh", "swamp", "bog", "fen", "grab", "grasp", "clutch", "pull", "drag", "drown", "drowning", "victims", "children", "kids", "young", "long arms", "long fingers", "grasping", "reaching", "slimy", "slippery", "green", "scaly", "frog-like", "toad-like", "web feet", "webbed hands", "nocturnal", "night", "folklore"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Groac'h - Breton fairy
    "GROAC_H": {
        "required_terms": ["groac'h", "groac", "breton", "brittany", "france", "fairy", "fae", "water", "spirit", "lake", "pond", "pool", "spring", "well", "beautiful", "lovely", "fair", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "lure", "entice", "tempt", "attract", "men", "victims", "prison", "capture", "imprison", "trap", "web", "net", "magic", "enchantment", "spell", "curse", "folklore", "celtic"],
        "forbidden_terms": ["ugly", "hideous", "grotesque", "repulsive", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive"],
        "min_matches": MIN_MATCHES
    },

    # Gruagach - Scottish female spirit
    "GRUAGACH": {
        "required_terms": ["gruagach", "scottish", "gaelic", "highlands", "fairy", "fae", "female", "woman", "maiden", "beautiful", "lovely", "fair", "radiant", "glowing", "long hair", "flowing hair", "golden hair", "red hair", "comb", "combing", "brushing", "cattle", "herd", "protector", "guardian", "offerings", "milk", "porridge", "cream", "field", "pasture", "meadow", "hills", "glen", "glen", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Gruaghair - Scottish hairy spirit
    "GRUAGHAIR": {
        "required_terms": ["gruaghair", "scottish", "gaelic", "highlands", "spirit", "fairy", "fae", "hairy", "shaggy", "hirsute", "wild", "untamed", "feral", "savage", "primal", "ancient", "old", "primordial", "forest", "woods", "woodland", "wilderness", "mountain", "hill", "moor", "heath", "solitary", "loner", "elusive", "rare", "sighting", "glimpse", "nocturnal", "night", "darkness", "shadows", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Gruff - Welsh spirit
    "GRUFF": {
        "required_terms": ["gruff", "welsh", "cymru", "spirit", "fairy", "fae", "mischievous", "trickster", "prankster", "joker", "playful", "fun-loving", "merry", "cheerful", "happy", "joyful", "small", "tiny", "diminutive", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "moonlight", "starlight", "forest", "woods", "woodland", "glen", "valley", "hill", "mountain", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Gwillion - Welsh goblin
    "GWILLION": {
        "required_terms": ["gwillion", "gwyllion", "welsh", "cymru", "goblin", "spirit", "fairy", "fae", "female", "woman", "maiden", "ugly", "hideous", "grotesque", "hag", "crone", "old", "aged", "wicked", "malevolent", "malicious", "cruel", "mean", "spiteful", "nasty", "dark", "black", "shadow", "night", "nocturnal", "darkness", "lonely roads", "mountain pass", "valley", "glen", "folklore", "celtic", "mythology", "lure", "lead astray", "mislead", "deceive", "trick", "confuse", "disorient"],
        "forbidden_terms": ["beautiful", "handsome", "pretty", "attractive", "comely", "fair", "lovely", "gorgeous", "radiant", "glowing", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "good", "benevolent", "kind", "gentle"],
        "min_matches": MIN_MATCHES
    },

    # Gwyllgi - Welsh dark dog
    "GWYLLGI": {
        "required_terms": ["gwyllgi", "welsh", "cymru", "dog", "hound", "black", "dark", "shadow", "spectral", "ghostly", "spirit", "apparition", "phantom", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "large", "massive", "enormous", "glowing eyes", "red eyes", "fiery eyes", "night", "nocturnal", "darkness", "lonely roads", "mountain pass", "valley", "glen", "omen", "death", "doom", "harbinger", "foretell", "predict", "warn", "warning", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Hob - English house spirit
    "HOB": {
        "required_terms": ["hob", "english", "northern england", "household", "spirit", "fairy", "fae", "brownie", "helpful", "benevolent", "kind", "cleaning", "chores", "work", "night", "nocturnal", "invisible", "offering", "bowl of milk", "cream", "porridge", "honey", "grateful", "appreciation", "gift", "reward", "offend", "insult", "offended", "angered", "annoyed", "leave", "depart", "abandon", "move", "mischief", "prank", "trickster", "domestic", "home", "hearth", "fireplace"],
        "forbidden_terms": ["evil", "malevolent", "demon", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "fiery", "flaming"],
        "min_matches": MIN_MATCHES
    },

    # Hobgoblin - Mischievous goblin
    "HOBGOBLIN": {
        "required_terms": ["hobgoblin", "hobgob", "english", "fairy", "fae", "goblin", "mischievous", "trickster", "prankster", "joker", "playful", "fun-loving", "merry", "cheerful", "happy", "joyful", "helpful", "benevolent", "kind", "friendly", "welcoming", "warm", "household", "domestic", "home", "hearth", "fireplace", "brownie-like", "brownie", "small", "tiny", "diminutive", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "folklore", "celtic"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Hou - Chinese dog spirit
    "HOU": {
        "required_terms": ["hou", "chinese", "china", "mythology", "dog", "canine", "spirit", "guardian", "protector", "temple", "shrine", "gate", "door", "entrance", "statue", "carving", "stone", "marble", "fu dogs", "lion dogs", "foo dogs", "paired", "pair", "male", "female", "yang", "yin", "ferocious", "fearsome", "terrifying", "ward off evil", "apotropaic", "protect", "guard", "defend", "imperial", "palace", "forbidden city", "buddhist", "confucian", "taoist"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Huldra - Scandinavian forest spirit
    "HULDRA": {
        "required_terms": ["huldra", "hulder", "skogsrå", "skogsfru", "tallemaja", "scandinavian", "norwegian", "swedish", "forest", "spirit", "fairy", "fae", "woman", "female", "beautiful", "lovely", "fair", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "lure", "entice", "tempt", "attract", "men", "hollow back", "tree hollow", "cow tail", "fox tail", "hidden tail", "concealed tail", "folklore", "norse", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "ugly", "hideous", "grotesque"],
        "min_matches": MIN_MATCHES
    },

    # Iguana - Lizard
    "IGUANA": {
        "required_terms": ["iguana", "lizard", "reptile", "scales", "spines", "tail", "green", "common iguana", "green iguana", "american iguana", "lizard", "reptile", "scaly", "scales", "spiny", "spines", "crest", "dewlap", "throat fan", "long tail", "prehensile tail", "claws", "sharp claws", "grasping claws", "climbing", "arboreal", "tree-dweller", "herbivore", "plant-eater", "vegetarian", "green", "brown", "gray"],
        "forbidden_terms": ["mammal", "fur", "feather", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats", "placental"],
        "min_matches": MIN_MATCHES
    },

    # Illithid - Mind flayer
    "ILLITHID": {
        "required_terms": ["mind flayer", "tentacle", "face", "brain", "psionic", "underdark", "cerebral", "slug", "illithid", "mindflayer", "brain eater", "brain consumer", "psionic", "telepathic", "telepathy", "mind control", "mind domination", "enslave", "enslavement", "thrall", "slave", "servant", "minion", "lackey", "tentacles", "four tentacles", "octopus-like", "cephalopod-like", "slimy", "pale skin", "gray skin", "purple skin", "bulbous head", "large brain case", "dungeons and dragons", "d&d", "forgotten realms", "underdark dweller"],
        "forbidden_terms": ["beautiful", "divine", "holy", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful"],
        "min_matches": MIN_MATCHES
    },

    # Imp - Small demon
    "IMP": {
        "required_terms": ["imp", "small", "demon", "mischievous", "horn", "tail", "winged", "trickster", "lesser demon", "minor demon", "lesser fiend", "minor fiend", "diminutive", "tiny", "wee", "little", "petite", "miniature", "minuscule", "mischievous", "playful", "prankish", "tricky", "cunning", "sly", "crafty", "pointed ears", "pointed horns", "barbed tail", "leathery wings", "bat wings", "red skin", "orange skin", "brown skin", "glowing eyes", "yellow eyes", "red eyes"],
        "forbidden_terms": ["large", "massive", "powerful", "mighty", "strong", "potent", "grand", "glorious", "splendid", "magnificent", "impressive", "awesome", "majestic"],
        "min_matches": MIN_MATCHES
    },

    # Jackal - Canine
    "JACKAL": {
        "required_terms": ["jackal", "canine", "dog", "wild", "desert", "egyptian", "anubis", "golden jackal", "black-backed jackal", "side-striped jackal", "canine", "canid", "dog-like", "wild dog", "wild canine", "scavenger", "carrion eater", "opportunistic", "adaptable", "cunning", "sly", "crafty", "pointed ears", "pointed snout", "bushy tail", "paws", "claws", "fur", "yellow-brown", "golden-brown", "gray-brown", "black", "white", "tan"],
        "forbidden_terms": ["reptile", "scales", "fish", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Jackalope - Horned rabbit
    "JACKALOPE": {
        "required_terms": ["jackalope", "rabbit", "hare", "antlers", "horns", "taxidermy", "american", "folk", "jack rabbit", "antelope jackrabbit", "horned rabbit", "rabbit body", "hare body", "leporid", "long ears", "long hind legs", "antlers", "deer antlers", "pronghorn horns", "small antlers", "small horns", "taxidermy", "mounted", "stuffed", "display", "trophy", "folk art", "american west", "frontier", "cowboy", "tall tale", "mythical", "legendary"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Jinn - Genie
    "JINN": {
        "required_terms": ["jinn", "genie", "djinn", "spirit", "arabian", "lamp", "wish", "elemental", "jinni", "ifrit", "marid", "shaitan", "qareen", "islamic", "arabian nights", "pre-islamic", "spirit", "entity", "being", "fire", "smokeless fire", "created from fire", "elemental", "shape-shifter", "shapeshifter", "transformer", "invisible", "unseen", "hidden", "concealed", "lamp", "bottle", "vessel", "container", "imprisoned", "bound", "servant"],
        "forbidden_terms": ["undead", "corpse", "rotten", "decayed", "skeletal", "ghost", "specter", "phantom", "wraith", "revenant", "zombie", "ghoul", "lich", "dracolich"],
        "min_matches": MIN_MATCHES
    },

    # Jormungand - World serpent
    "JORMUNGAND": {
        "required_terms": ["jormungandr", "serpent", "snake", "world", "midgard", "norse", "sea", "giant", "thor", "jörmungandr", "jormungand", "midgard serpent", "world serpent", "sea serpent", "ocean serpent", "great serpent", "enormous serpent", "encircles midgard", "encircles world", "bites own tail", "ouroboros", "loki's child", "loki's son", "angrboda's child", "fenrir's brother", "hel's brother", "thor's enemy", "ragnarok", "end of world", "twilight of gods", "poisonous", "venomous", "deadly venom", "poison breath", "venomous breath"],
        "forbidden_terms": ["winged", "small", "tiny", "diminutive", "minor", "lesser", "weak", "frail", "delicate", "fragile", "puny", "feeble", "powerless", "impotent"],
        "min_matches": MIN_MATCHES
    },

    # Jotun - Norse giant
    "JOTUN": {
        "required_terms": ["giant", "norse", "jotunn", "frost", "mountain", "enemy", "gods", "jotun", "jötunn", "jotnar", "frost giant", "mountain giant", "hrímþursar", "rime giant", "ice giant", "fire giant", "eldjötnar", "ymir", "thrym", "skadi", "gerd", "gymir", "geirrod", "utgard-loki", "niflheim", "muspelheim", "jotunheim", "utgard", "giant realm", "enemy of aesir", "enemy of vanir", "opponent of gods", "god opponent"],
        "forbidden_terms": ["small", "human-sized", "dwarf", "dwarven", "dwarfish", "dwarflike", "diminutive", "tiny", "wee", "little", "petite", "miniature", "minuscule"],
        "min_matches": MIN_MATCHES
    },

    # Jumbie - Caribbean spirit
    "JUMBIE": {
        "required_terms": ["jumbie", "jimbi", "caribbean", "west indies", "trinidad", "jamaica", "spirit", "ghost", "apparition", "phantom", "ancestor", "dead", "deceased", "restless", "unquiet", "malevolent", "wicked", "evil", "harmful", "dangerous", "night", "nocturnal", "darkness", "shadows", "forest", "woods", "graveyard", "cemetery", "tomb", "grave", "folklore", "mythology", "african diaspora", "obeah", "voodoo", "hoodoo", "supernatural"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Kappa - Japanese water imp
    "KAPPA": {
        "required_terms": ["kappa", "japanese", "water", "turtle", "dish", "head", "river", "cucumber", "kawataro", "kawako", "mizushi", "komahiki", "water imp", "water sprite", "water demon", "river imp", "pond imp", "lake imp", "turtle-like", "tortoise-like", "reptilian", "scaly", "amphibian", "webbed hands", "webbed feet", "beak", "turtle beak", "shell", "carapace", "dish on head", "water dish", "water basin", "water-filled dish", "spills water loses power", "mischievous", "trickster", "prankster"],
        "forbidden_terms": ["winged", "feathered", "european", "western", "christian", "biblical", "angelic", "demonic", "infernal", "hellish", "abyssal", "underworld"],
        "min_matches": MIN_MATCHES
    },

    # Kelpie - Water horse
    "KELPIE": {
        "required_terms": ["kelpie", "each-uisge", "water horse", "scottish", "lake", "river", "drown", "shape-shift", "celtic", "waterhorse", "river horse", "lake horse", "loch horse", "scottish", "irish", "celtic", "gaelic", "beautiful horse", "alluring horse", "enticing horse", "tempting horse", "lure riders", "lure travelers", "attract victims", "trap victims", "drown victims", "eat victims", "devour victims", "consume victims", "sticky skin", "adhesive skin", "trapped rider", "can't dismount"],
        "forbidden_terms": ["reptile", "scales", "fish", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Kirin - Japanese unicorn
    "KIRIN": {
        "required_terms": ["kirin", "japanese", "chinese", "qilin", "unicorn", "hooved", "scales", "flames", "body", "deer", "horse", "dragon", "ox", "tail", "majestic", "graceful", "elegant", "beautiful", "radiant", "glowing", "luminous", "shimmering", "wise", "intelligent", "sagacious", "just", "fair", "righteous", "benevolent", "kind", "gentle", "protector", "guardian", "omen", "good fortune", "prosperity", "success", "happiness", "mythology", "legendary"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Kitsune - Fox spirit
    "KITSUNE": {
        "required_terms": ["kitsune", "fox", "japanese", "spirit", "tail", "multiple tails", "nine-tailed", "shapeshift", "fox spirit", "fox demon", "kyūbi no kitsune", "nine-tailed fox", "multiple tails", "many tails", "increased tails with age", "wise", "intelligent", "cunning", "clever", "shrewd", "astute", "sharp", "shape-shifter", "shapeshifter", "transformer", "human form", "beautiful woman", "seductive", "alluring", "enticing", "tempting", "playful", "mischievous", "trickster", "prankster", "joker", "jester", "foxfire", "kitsunebi"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Kobold - Small reptilian
    "KOBOLD": {
        "required_terms": ["kobold", "small", "reptile", "scaly", "trap", "miner", "cave", "german", "dragon", "kobolt", "cobold", "kobalt", "germanic", "folklore", "mythology", "diminutive", "tiny", "wee", "little", "petite", "miniature", "minuscule", "reptilian", "scaly", "scales", "lizard-like", "dragon-like", "draconic", "pointed ears", "snout", "tail", "claws", "sharp claws", "grasping claws", "trap maker", "trap setter", "tunnel digger", "miner", "cave dweller"],
        "forbidden_terms": ["large", "beautiful", "majestic", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent"],
        "min_matches": MIN_MATCHES
    },

    # Korred - Celtic dwarf
    "KORRED": {
        "required_terms": ["korred", "corred", "celtic", "breton", "brittany", "dwarf", "small", "tiny", "diminutive", "underground", "subterranean", "cavern", "cave", "mine", "miner", "smith", "forge", "metalwork", "craftsman", "artisan", "jeweler", "goldsmith", "silversmith", "treasure", "gold", "silver", "gems", "hoard", "guardian", "protector", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "darkness", "shadows", "folklore", "mythology"],
        "forbidden_terms": ["tall", "elf", "slender", "slim", "thin", "lithe", "willowy", "graceful", "elegant", "delicate", "refined", "cultured", "sophisticated", "educated", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel"],
        "min_matches": MIN_MATCHES
    },

    # Korrigan - Breton fairy
    "KORRIGAN": {
        "required_terms": ["korrigan", "corrigan", "breton", "brittany", "fairy", "fae", "female", "woman", "maiden", "beautiful", "lovely", "fair", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "long hair", "flowing hair", "golden hair", "red hair", "dance", "dancing", "circle", "ring", "moonlight", "night", "nocturnal", "fountain", "spring", "well", "stone", "megalith", "menhir", "dolmen", "ancient", "old", "primordial", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Koschei - Russian immortal
    "KOSCHEI": {
        "required_terms": ["koschei", "koshchei", "russian", "slavic", "immortal", "death", "egg", "needle", "skeleton", "kashchei", "koshchey", "koshchei the deathless", "immortal", "undying", "cannot die", "cannot be killed", "immortal soul", "soul hidden", "hidden soul", "egg", "needle", "duck", "hare", "chest", "oak", "layered protection", "nested protection", "multiple layers", "nested dolls", "skeleton", "bony", "gaunt", "emaciated", "thin", "wasted", "haggard", "evil", "malevolent", "wicked", "cruel", "vicious", "savage", "brutal"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous"],
        "min_matches": MIN_MATCHES
    },

    # Kraken - Giant squid
    "KRAKEN": {
        "required_terms": ["kraken", "squid", "octopus", "tentacle", "sea", "monster", "ship", "norwegian", "giant", "krake", "krabben", "sea monster", "ocean monster", "deep-sea monster", "cephalopod", "squid-like", "octopus-like", "tentacles", "many tentacles", "giant", "enormous", "colossal", "massive", "huge", "immense", "titanic", "ship destroyer", "ship sinker", "vessel destroyer", "boat destroyer", "whirlpool creator", "maelstrom creator", "ocean depths", "sea floor", "norwegian", "scandinavian", "norse", "icelandic", "greenlandic"],
        "forbidden_terms": ["winged", "feathered", "land", "terrestrial", "ground", "earth", "soil", "dirt", "sand", "rock", "stone", "mountain", "hill", "valley", "forest"],
        "min_matches": MIN_MATCHES
    },

    # Lamassu - Assyrian bull-lion-bird
    "LAMASSU": {
        "required_terms": ["lamassu", "assyrian", "mesopotamian", "winged", "bull", "lion", "human", "head", "guardian", "shedu", "alad", "lammasu", "mesopotamian", "assyrian", "babylonian", "sumerian", "akkadian", "persian", "winged bull", "winged lion", "human head", "bearded head", "crown", "tiara", "horned crown", "divine crown", "guardian spirit", "protective spirit", "temple guardian", "palace guardian", "gate guardian", "door guardian", "entrance guardian", "warden", "sentinel"],
        "forbidden_terms": ["evil", "malevolent", "demon", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Lamia - Snake woman
    "LAMIA": {
        "required_terms": ["lamia", "snake", "serpent", "woman", "female", "lower", "body", "greek", "child-eater", "lamiae", "greek mythology", "lybian myth", "libyan myth", "upper body woman", "lower body serpent", "snake lower body", "serpent lower body", "beautiful face", "beautiful upper body", "ugly lower body", "monstrous lower body", "child devourer", "child eater", "infant killer", "baby killer", "youth devourer", "jealous", "envious", "spiteful", "vengeful", "bitter", "resentful", "angry"],
        "forbidden_terms": ["bird", "winged", "feathered", "beak", "talons", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth"],
        "min_matches": MIN_MATCHES
    },

    # Leanan Sidhe - Irish fairy lover
    "LEANAN_SIDHE": {
        "required_terms": ["leanan sidhe", "leannán sídhe", "irish", "fairy", "fae", "lover", "mistress", "beautiful", "lovely", "fair", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "inspiration", "muse", "artist", "poet", "musician", "creative", "genius", "talent", "gift", "curse", "drain", "life force", "energy", "vitality", "waste away", "die young", "tragic", "doomed", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "ugly", "hideous", "grotesque", "repulsive"],
        "min_matches": MIN_MATCHES
    },

    # Lemure - Roman spirit
    "LEMURE": {
        "required_terms": ["lemure", "lemures", "larva", "roman", "ancient rome", "spirit", "ghost", "apparition", "phantom", "dead", "deceased", "restless", "unquiet", "malevolent", "wicked", "evil", "harmful", "dangerous", "night", "nocturnal", "darkness", "shadows", "haunt", "haunting", "torment", "torture", "frighten", "scare", "terrify", "lemuria", "festival", "exorcism", "beans", "black beans", "ritual", "appease", "placate"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Leprechaun - Irish shoemaker
    "LEPRECHAUN": {
        "required_terms": ["leprechaun", "lobaircin", "irish", "fairy", "fae", "shoemaker", "cobbler", "shoe", "boot", "leather", "craftsman", "artisan", "small", "tiny", "diminutive", "old man", "beard", "wrinkled", "wizened", "green", "red", "clothes", "hat", "pointed hat", "buckle", "shoes", "apron", "hammer", "awl", "treasure", "gold", "coin", "pot of gold", "hidden", "buried", "rainbow", "end", "capture", "catch", "release", "trick", "deceive", "escape"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Leshy - Slavic forest spirit
    "LESHY": {
        "required_terms": ["leshy", "leshiy", "slavic", "russian", "forest", "spirit", "tree", "wood", "guardian", "shape-shift", "lesovik", "leshak", "lesny", "lesnoy", "borovoy", "forest spirit", "woodland spirit", "forest guardian", "woodland guardian", "tree spirit", "wood spirit", "nature spirit", "wild spirit", "untamed spirit", "shape-shifter", "shapeshifter", "transformer", "tree height", "grass height", "can change size", "size changer", "size shifter", "voice mimics forest sounds", "leads travelers astray", "misleads wanderers", "confuses hikers", "disorients"],
        "forbidden_terms": ["evil", "demon", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Leviathan - Sea monster
    "LEVIATHAN": {
        "required_terms": ["leviathan", "sea", "monster", "biblical", "serpent", "whale", "giant", "ocean", "livyatan", "biblical monster", "hebrew monster", "old testament", "sea serpent", "ocean serpent", "sea dragon", "ocean dragon", "sea beast", "great whale", "giant whale", "enormous whale", "colossal whale", "massive whale", "chaos monster", "primordial chaos", "primeval monster", "ancient evil", "untameable", "uncontrollable", "unconquerable", "invincible", "unbeatable", "god's creation", "divine creation", "divine beast", "sacred monster"],
        "forbidden_terms": ["small", "tiny", "diminutive", "minor", "lesser", "weak", "frail", "delicate", "fragile", "puny", "feeble", "powerless", "impotent", "ineffective"],
        "min_matches": MIN_MATCHES
    },

    # Lich - Undead wizard
    "LICH": {
        "required_terms": ["lich", "undead", "wizard", "skeleton", "phylactery", "soul", "magic", "immortal", "liche", "litch", "undead spellcaster", "undead wizard", "undead sorcerer", "skeletal", "bony", "bones", "skull", "ribs", "spine", "skeleton", "hollow eyes", "glowing eyes", "soul gems", "soul jar", "soul container", "phylactery", "horcrux", "soul vessel", "immortality", "eternal life", "necromancy", "dark magic", "forbidden magic", "evil magic", "corrupted magic"],
        "forbidden_terms": ["living", "alive", "flesh", "skin", "muscle", "tissue", "organ", "heart", "lung", "brain", "blood", "veins", "arteries", "circulatory", "respiratory"],
        "min_matches": MIN_MATCHES
    },

    # Lilitu - Mesopotamian wind spirit
    "LILITU": {
        "required_terms": ["lilitu", "lilith", "mesopotamian", "sumerian", "akkadian", "babylonian", "wind", "spirit", "demon", "female", "woman", "night", "nocturnal", "darkness", "shadows", "winged", "bird", "owl", "talons", "claws", "predator", "hunter", "strikes", "attacks", "men", "children", "infants", "babies", "dangerous", "harmful", "malevolent", "wicked", "evil", "folklore", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Lindworm - Wingless serpent
    "LINDWORM": {
        "required_terms": ["lindworm", "serpent", "snake", "dragon", "wingless", "two legs", "scandinavian", "wyrm", "lindorm", "lindwurm", "lindwyrm", "serpent dragon", "snake dragon", "wingless dragon", "legless dragon", "two-legged dragon", "bipedal dragon", "scaly", "scales", "reptilian", "serpentine", "long body", "elongated body", "poisonous", "venomous", "poison breath", "venomous breath", "constrictor", "coiling", "wrapping", "squeezing", "crushing", "strangling", "choking", "norse", "germanic", "scandinavian", "teutonic", "medieval", "legendary"],
        "forbidden_terms": ["winged", "four legs", "six legs", "eight legs", "many legs", "bird", "feathered", "beak", "talons", "mammal", "fur", "hair", "wool", "hide"],
        "min_matches": MIN_MATCHES
    },

    # Lizardfolk - Lizard people
    "LIZARDFOLK": {
        "required_terms": ["lizard", "reptile", "humanoid", "scales", "tail", "swamp", "primitive", "tribe", "lizardfolk", "lizard man", "lizard woman", "lizard people", "lizard race", "reptilian humanoid", "scaly humanoid", "reptile person", "saurian", "scales", "scaly skin", "reptilian features", "snout", "pointed teeth", "sharp teeth", "fangs", "long tongue", "forked tongue", "tail", "prehensile tail", "claws", "sharp claws", "webbed hands", "webbed feet", "swamp dweller", "marsh dweller", "bog dweller", "fen dweller", "aquatic", "amphibious"],
        "forbidden_terms": ["mammal", "fur", "feather", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats", "placental"],
        "min_matches": MIN_MATCHES
    },

    # Loup Garou - French werewolf
    "LOUP_GAROU": {
        "required_terms": ["loup garou", "werewolf", "wolf", "french", "lycanthrope", "transformation", "moon", "loup-garou", "wolfman", "lycanthrope", "therianthrope", "french folklore", "french legend", "french mythology", "francophone", "wolf transformation", "wolf shape", "wolf form", "beast form", "animal form", "full moon", "moonlight", "lunar cycle", "moon transformation", "silver vulnerability", "silver weakness", "silver weapon", "silver bullet", "howl", "howling", "pack", "wolf pack", "predator", "hunter", "stalker"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Lutin - French goblin
    "LUTIN": {
        "required_terms": ["lutin", "french", "goblin", "spirit", "fairy", "fae", "mischievous", "trickster", "prankster", "joker", "playful", "fun-loving", "merry", "cheerful", "happy", "joyful", "small", "tiny", "diminutive", "pointed ears", "pointed hat", "pointed shoes", "red", "green", "clothes", "nocturnal", "night", "darkness", "shadows", "household", "domestic", "home", "hearth", "fireplace", "farm", "barn", "stable", "folklore", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Ly Erg - Scottish water spirit
    "LY_ERG": {
        "required_terms": ["ly erg", "scottish", "gaelic", "highlands", "water", "spirit", "fairy", "fae", "river", "stream", "ford", "crossing", "red", "red hair", "red beard", "red clothes", "red cap", "rowan", "rowan berry", "rowan branch", "protective", "ward off", "dangerous", "harmful", "malevolent", "wicked", "evil", "drown", "drowning", "victims", "travelers", "lure", "entice", "tempt", "attract", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Manticore - Lion-scorpion-dragon
    "MANTICORE": {
        "required_terms": ["manticore", "lion", "scorpion", "tail", "spikes", "human", "face", "persian", "winged", "mantichora", "manticora", "martichoras", "persian monster", "lion body", "human head", "human face", "man face", "bearded face", "three rows teeth", "triple teeth rows", "multiple teeth rows", "sharp teeth", "scorpion tail", "scorpion stinger", "venomous tail", "poisonous tail", "tail spikes", "tail spines", "shoot spikes", "fire spikes", "volley spikes", "bat wings", "leathery wings", "winged lion", "flying lion", "aerial predator"],
        "forbidden_terms": ["snake", "serpent", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "mammal fur only", "no scales", "no chitin"],
        "min_matches": MIN_MATCHES
    },

    # Mantis Shrimp Devil - Crustacean demon
    "MANTIS_SHRIMP_DEVIL": {
        "required_terms": ["mantis shrimp", "stomatopod", "crustacean", "arthropod", "exoskeleton", "chitin", "chitinous", "segmented body", "appendages", "thorax", "abdomen", "raptorial claw", "smashing claw", "spearing claw", "powerful punch", "cavitation bubble", "sonic boom", "shockwave", "underwater punch", "rainbow colors", "colorful", "vibrant", "iridescent", "polarized vision", "complex eyes", "trinocular vision", "demon", "devil", "infernal", "hellish"],
        "forbidden_terms": ["mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "bird", "feathered", "beak", "talons", "reptile", "scales", "snake", "lizard"],
        "min_matches": MIN_MATCHES
    },

    # Marid - Water djinn
    "MARID": {
        "required_terms": ["marid", "djinn", "water", "genie", "arabian", "elemental", "ocean", "powerful", "jinn", "arabian nights", "islamic mythology", "water spirit", "water elemental", "ocean spirit", "sea spirit", "river spirit", "powerful djinn", "strong djinn", "mighty djinn", "great djinn", "ancient djinn", "shape-shifter", "shapeshifter", "transformer", "invisible", "unseen", "lamp", "bottle", "vessel", "container", "imprisoned", "bound", "servant", "wish-granter", "wish fulfillment", "grant wishes", "fulfill desires"],
        "forbidden_terms": ["fire", "flame", "burning", "blazing", "scorching", "searing", "heat", "hot", "warm", "desert", "sand", "dune", "arid", "dry", "drought"],
        "min_matches": MIN_MATCHES
    },

    # Marool - Scottish sea spirit
    "MAROOL": {
        "required_terms": ["marool", "scottish", "gaelic", "highlands", "sea", "ocean", "spirit", "fairy", "fae", "storm", "tempest", "waves", "tide", "current", "shipwreck", "drown", "drowning", "sailors", "fishermen", "dangerous", "harmful", "malevolent", "wicked", "evil", "nocturnal", "night", "darkness", "shadows", "coastal", "shore", "rocks", "cliffs", "caves", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Medusa - Snake-haired woman
    "MEDUSA": {
        "required_terms": ["medusa", "snake", "hair", "greek", "woman", "female", "gaze", "petrify", "stone", "gorgon", "stheno", "euryale", "greek mythology", "mythological", "snake hair", "serpent hair", "snakes for hair", "living hair snakes", "beautiful face", "hideous face", "beautiful originally", "cursed beauty", "petrifying gaze", "stone gaze", "turn to stone", "stone touch", "fatal glance", "winged", "brass claws", "brass hands", "sharp teeth", "boar tusks", "perseus", "perseus slayer", "reflective shield", "mirror shield", "bronze shield"],
        "forbidden_terms": ["bird", "feather", "reptile body", "scales body", "snake lower body", "lamia-like", "naga-like", "fish tail", "mermaid-like", "aquatic", "fins"],
        "min_matches": MIN_MATCHES
    },

    # Menehune - Hawaiian dwarf
    "MENEHUNE": {
        "required_terms": ["menehune", "hawaiian", "hawaii", "polynesian", "dwarf", "small", "tiny", "diminutive", "ancient", "old", "primordial", "people", "race", "tribe", "forest", "woods", "mountain", "valley", "hidden", "secret", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "darkness", "shadows", "craftsman", "artisan", "builder", "constructor", "fishpond", "temple", "heiau", "road", "path", "stonework", "masonry", "folklore", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Mermaid - Fish-woman
    "MERMAID": {
        "required_terms": ["mermaid", "fish", "tail", "woman", "female", "sea", "ocean", "scales", "aquatic", "merman", "merfolk", "merpeople", "sea people", "ocean people", "upper body human", "lower body fish", "human torso", "fish tail", "scales", "scaly tail", "colorful scales", "silver scales", "blue scales", "green scales", "long hair", "flowing hair", "beautiful", "lovely", "fair", "siren", "siren song", "enchanting voice", "luring song", "enticing melody", "ocean dweller", "sea dweller", "underwater", "subaquatic", "marine"],
        "forbidden_terms": ["legs", "feet", "land", "terrestrial", "ground", "earth", "soil", "dirt", "mountain", "hill", "valley", "forest", "wood", "tree", "grass", "field"],
        "min_matches": MIN_MATCHES
    },

    # Merrow - Irish mermaid
    "MERROW": {
        "required_terms": ["merrow", "murúch", "irish", "gaelic", "mermaid", "merman", "sea", "ocean", "spirit", "fairy", "fae", "green", "hair", "green hair", "red cap", "cochull", "magic cap", "seal", "seal-like", "webbed", "fingers", "toes", "scales", "fish tail", "beautiful", "lovely", "fair", "enchanting", "song", "voice", "lure", "entice", "tempt", "sailors", "fishermen", "coastal", "shore", "rocks", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "ugly", "hideous", "grotesque", "repulsive"],
        "min_matches": MIN_MATCHES
    },

    # Migo - Lovecraftian fungi
    "MIGO": {
        "required_terms": ["migo", "mi-go", "lovecraftian", "cthulhu mythos", "fungus", "fungal", "mushroom", "alien", "extraterrestrial", "outer god", "servitor", "cosmic", "nightmare", "indescribable", "horror", "terrifying", "fearsome", "dreadful", "winged", "crab-like", "crustacean", "arachnid", "multiple limbs", "tentacles", "antennae", "intelligent", "advanced", "technology", "brain cylinder", "brain extraction", "brain preservation", "yuggoth", "pluto", "from beyond", "extradimensional", "non-euclidean", "wrong angles", "impossible anatomy"],
        "forbidden_terms": ["beautiful", "divine", "humanoid", "normal", "natural", "earthly", "terrestrial", "mundane", "ordinary", "commonplace", "familiar", "wholesome", "pure", "clean", "pleasant", "agreeable", "nice", "friendly", "welcoming", "warm"],
        "min_matches": MIN_MATCHES
    },

    # Mimic - Shapeshifting treasure
    "MIMIC": {
        "required_terms": ["mimic", "treasure", "chest", "object", "shape-shift", "teeth", "tongue", "ambush", "mimicry", "imitator", "copycat", "shapeshifter", "transformer", "treasure chest", "wooden chest", "metal chest", "locked chest", "treasure box", "furniture", "door", "statue", "object form", "inanimate form", "object disguise", "teeth", "sharp teeth", "rows of teeth", "multiple teeth", "fang", "maw", "tongue", "long tongue", "sticky tongue", "grasping tongue", "adhesive tongue", "ambush predator", "ambusher", "surprise attack", "waiting predator"],
        "forbidden_terms": ["beautiful", "majestic", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent", "cunning"],
        "min_matches": MIN_MATCHES
    },

    # Minotaur - Bull-headed man
    "MINOTAUR": {
        "required_terms": ["minotaur", "bull", "head", "human", "body", "labyrinth", "crete", "greek", "minoan", "cretan", "greek mythology", "bull head", "bull's head", "bovine head", "bull face", "human body", "man body", "muscular body", "powerful body", "strong body", "maze", "crete labyrinth", "knossos", "minoan palace"],
        "forbidden_terms": ["axe", "double axe", "labrys", "great axe", "massive axe", "battle axe", "weapon", "club", "sword", "hammer", "spear", "blade", "warrior", "fighter", "soldier", "gladiator", "brute", "hoof", "hooves", "fur", "matted fur", "shaggy", "mane", "horse", "centaur", "serpent", "dragon", "wing", "forest", "field", "mountain", "plains", "swamp", "frankish", "merovingian", "celtic", "norse", "viking", "theseus slayer", "slayer of theseus"],
        "min_matches": MIN_MATCHES
    },


    # Mole People - Underground dwellers
    "MOLE_PEOPLE": {
        "required_terms": ["mole", "people", "humanoid", "underground", "burrow", "blind", "claw", "tunnel", "mole people", "mole men", "mole humanoids", "subterranean humanoids", "underground dwellers", "cavern dwellers", "cave dwellers", "tunnel dwellers", "burrowing", "digging", "tunneling", "excavating", "mining", "large claws", "digging claws", "powerful claws", "sharp claws", "blind", "sightless", "no eyes", "vestigial eyes", "poor eyesight", "pale skin", "colorless skin", "white skin", "albino", "no pigment", "sensitive whiskers", "vibrissae", "touch sensitivity", "vibration sense"],
        "forbidden_terms": ["winged", "scaled", "reptile", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "surface", "above ground", "sky"],
        "min_matches": MIN_MATCHES
    },

    # Morgen - Welsh sea spirit
    "MORGEN": {
        "required_terms": ["morgen", "morgan", "welsh", "cymru", "sea", "ocean", "spirit", "fairy", "fae", "female", "woman", "maiden", "beautiful", "lovely", "fair", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "siren", "song", "voice", "lure", "entice", "tempt", "attract", "sailors", "fishermen", "waves", "tide", "current", "coastal", "shore", "rocks", "cliffs", "caves", "folklore", "celtic", "mythology", "arthurian", "morgan le fay"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "ugly", "hideous", "grotesque", "repulsive"],
        "min_matches": MIN_MATCHES
    },

    # Moroi - Vampire
    "MOROI": {
        "required_terms": ["moroi", "romanian", "vampire", "undead", "blood", "slavic", "strigoi", "night", "moroi", "romanian vampire", "slavic vampire", "eastern european vampire", "undead", "living dead", "risen dead", "returned dead", "revenant", "blood drinker", "blood sucker", "blood consumer", "hematophage", "night stalker", "nocturnal predator", "night hunter", "darkness dweller", "pale skin", "corpse-like", "decayed", "rotting", "decaying", "putrid", "sharp teeth", "fangs", "elongated canines", "pointed canines", "fear of sunlight", "sunlight vulnerability", "sunlight burns"],
        "forbidden_terms": ["living", "alive", "holy", "divine", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Mummy - Preserved corpse
    "MUMMY": {
        "required_terms": ["mummy", "egyptian", "bandage", "wrapped", "undead", "tomb", "ancient", "curse", "mummified", "preserved corpse", "embalmed body", "ancient dead", "egyptian", "pharaonic", "ancient egypt", "old kingdom", "new kingdom", "linen wrappings", "bandages", "wrapped in cloth", "sarcophagus", "coffin", "tomb", "pyramid", "burial chamber", "sepulcher", "crypt", "catacomb", "curse", "mummy's curse", "deadly curse", "fatal curse", "vengeful spirit", "slow movement", "shambling", "lurching", "staggering", "lumbering"],
        "forbidden_terms": ["living", "alive", "fresh", "new", "modern", "contemporary", "recent", "young", "youthful", "healthy", "hearty", "robust", "vigorous", "strong"],
        "min_matches": MIN_MATCHES
    },

    # Muryan - Cornish fairy
    "MURYAN": {
        "required_terms": ["muryan", "cornish", "cornwall", "fairy", "fae", "small", "tiny", "diminutive", "ant", "ant-like", "insect", "tiny people", "little people", "wee folk", "elusive", "rare", "sighting", "glimpse", "night", "nocturnal", "moonlight", "starlight", "ancient", "old", "primordial", "burial mound", "tomb", "barrow", "cairn", "stone circle", "megalith", "menhir", "dolmen", "guardian", "protector", "folklore", "celtic", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Myrmidon - Ant warrior
    "MYRMIDON": {
        "required_terms": ["myrmidon", "ant", "warrior", "greek", "achilles", "soldier", "insect", "chitin", "myrmidones", "achilles warriors", "achilles soldiers", "ant people", "ant warriors", "ant soldiers", "ant-like warriors", "greek mythology", "trojan war", "homer", "iliad", "thessaly", "aegina", "insectoid", "insect-like", "chitinous", "exoskeleton", "segmented body", "antennae", "mandibles", "compound eyes", "six limbs", "powerful jaws", "disciplined", "loyal", "obedient", "faithful", "devoted", "dedicated"],
        "forbidden_terms": ["mammal", "fur", "feather", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats", "placental"],
        "min_matches": MIN_MATCHES
    },

    # Nacken - Scandinavian water spirit
    "NACKEN": {
        "required_terms": ["nacken", "näcken", "strömkarl", "scandinavian", "norwegian", "swedish", "water", "spirit", "fiddle", "violin", "music", "musician", "player", "melody", "tune", "song", "entrancing", "captivating", "beautiful", "haunting", "lure", "entice", "tempt", "attract", "children", "women", "drown", "drowning", "victims", "river", "stream", "waterfall", "cascade", "pool", "deep water", "night", "nocturnal", "moonlight", "folklore", "mythology"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "ugly", "hideous", "grotesque", "repulsive"],
        "min_matches": MIN_MATCHES
    },

    # Naga - Snake-human hybrid
    "NAGA": {
        "required_terms": ["naga", "snake", "serpent", "human", "hindu", "buddhist", "cobra", "hood", "nagas", "nagini", "female naga", "serpent people", "snake people", "hindu mythology", "buddhist mythology", "indian mythology", "southeast asian", "upper body human", "lower body serpent", "snake lower body", "cobra hood", "spread hood", "hooded cobra", "reptilian", "scaly", "scales", "forked tongue", "divine", "semi-divine", "spiritual", "sacred", "holy", "worshipped", "guardian", "protector", "treasure guardian", "water guardian", "temple guardian"],
        "forbidden_terms": ["bird", "mammal", "fur", "feather", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "milk", "udder", "teats"],
        "min_matches": MIN_MATCHES
    },

    # Naiad - Freshwater nymph
    "NAIAD": {
        "required_terms": ["naiad", "nymph", "water", "freshwater", "spring", "river", "greek", "female", "naiades", "water nymph", "freshwater nymph", "spring nymph", "river nymph", "stream nymph", "brook nymph", "well nymph", "fountain nymph", "greek mythology", "nature spirit", "nature deity", "lesser goddess", "beautiful woman", "beautiful maiden", "lovely female", "fair maiden", "long hair", "flowing hair", "youthful", "young", "eternal youth", "water-associated", "aquatic", "freshwater", "clear water", "pure water"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Nereid - Sea nymph
    "NEREID": {
        "required_terms": ["nereid", "nymph", "sea", "ocean", "greek", "female", "nereids", "sea nymph", "ocean nymph", "salt water nymph", "mediterranean", "aegean", "poseidon", "amphitrite", "thetis", "achilles mother", "galatea", "fifty sisters", "daughters of nereus", "sea goddess", "marine deity", "lesser goddess", "beautiful woman", "beautiful maiden", "lovely female", "fair maiden", "long hair", "flowing hair", "youthful", "young", "eternal youth", "dolphin", "hippocamp", "sea creature companion"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Nightgaunt - Lovecraftian creature
    "NIGHTGAUNT": {
        "required_terms": ["nightgaunt", "night-gaunt", "lovecraftian", "cthulhu mythos", "dream cycle", "dreamlands", "unknown kadath", "randolph carter", "winged creature", "leathery wings", "bat wings", "membranous wings", "tentacles", "prehensile tentacles", "grasping tentacles", "curling tentacles", "faceless", "no face", "featureless face", "smooth head", "featureless head", "black", "glossy black", "sleek black", "dark", "shadowy", "tenebrous", "silent", "noiseless", "soundless", "quiet", "stealthy", "sneaky"],
        "forbidden_terms": ["face", "eyes", "mouth", "nose", "ears", "eyebrows", "eyelashes", "lips", "teeth", "tongue", "cheeks", "chin", "forehead", "facial features"],
        "min_matches": MIN_MATCHES
    },

    # Nightmare - Evil horse
    "NIGHTMARE": {
        "required_terms": ["nightmare", "night mare", "demon horse", "fiendish horse", "infernal horse", "black horse", "coal-black horse", "ebony horse", "midnight horse", "fiery eyes", "burning eyes", "glowing eyes", "red eyes", "orange eyes", "smoking nostrils", "smoldering breath", "fiery breath", "flaming breath", "burning hooves", "flaming hooves", "hooves leave fire", "hooves leave smoke", "mane of fire", "tail of fire", "fiery mane", "flaming mane", "burning tail", "hellish steed", "infernal mount", "demon mount", "evil mount", "dark steed"],
        "forbidden_terms": ["reptile", "scales", "fish", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Nuckelavee - Orcadian monster
    "NUCKELAVEE": {
        "required_terms": ["nuckelavee", "nuckalavee", "orkney", "orcadian", "scottish", "horse", "human", "skinless", "sea", "plague", "nuckelavee", "nuckelavee", "nuckalavee", "orkney", "orcadian mythology", "scottish folklore", "norse mythology influence", "scottish islands", "horse body", "human torso", "human torso growing from back", "centaur-like", "skinless", "no skin", "flayed", "raw flesh", "exposed muscles", "visible veins", "single eye", "one eye", "cyclopean", "huge mouth", "gaping maw", "fiery breath", "poisonous breath", "plague bringer", "disease bringer", "blight", "crop failure", "drought", "famine", "sickness", "illness"],
        "forbidden_terms": ["beautiful", "skin", "fur", "hair", "hide", "pelt", "scales", "feathers", "attractive", "handsome", "pretty", "lovely", "gorgeous", "radiant"],
        "min_matches": MIN_MATCHES
    },

    "PERINDENS": {
        "required_terms": ["tree", "serpent", "dragon", "medieval", "bestiary", "physiologus", "eden", "garden", "paradise", "fruit", "tree of knowledge", "serpent guarding", "dragon guarding", "winged serpent", "scaly", "scales", "guardian", "protector"],
        "forbidden_terms": ["humanoid", "human", "man", "woman", "person", "face", "antler", "antlers", "hoof", "hooves", "moss", "mossy", "bark", "spectral", "ghost", "shadow", "skeletal", "mischievous", "furry", "fur", "six wings", "feathered wings", "peacock", "jellyfish", "ethereal"],
        "min_matches": MIN_MATCHES
    },

    "SAURA": {
        "required_terms": ["lizard", "reptile", "scaly", "scales", "classical", "bestiary", "pliny", "lizard-like", "small lizard", "desert", "sand", "venomous", "poison", "bite", "venom", "toxic"],
        "forbidden_terms": ["humanoid", "human", "man", "woman", "person", "face", "antler", "antlers", "hoof", "hooves", "moss", "mossy", "mischievous", "furry", "fur", "wing", "wings", "feathered", "serpentine", "serpent", "snake", "six-limbed", "fox-like", "firefly", "hypnotic", "enchanted flame", "crackling", "melodic"],
        "min_matches": MIN_MATCHES
    },

    "SEPS": {
        "required_terms": ["serpent", "snake", "venomous", "venom", "poison", "bite", "decay", "putrefy", "rot", "flesh", "tissue", "corpse", "corruption", "bestiary", "medieval", "classical", "pliny", "lucan", "africa", "desert"],
        "forbidden_terms": ["humanoid", "human", "man", "woman", "person", "face", "antler", "antlers", "hoof", "hooves", "moss", "mossy", "mischievous", "furry", "fur", "wing", "wings", "webbed", "lantern", "glowing eyes", "forest", "woodland", "garden", "jellyfish", "spectral", "ethereal"],
        "min_matches": MIN_MATCHES
    },

    "TARAND": {
        "required_terms": ["color", "change", "changing", "coat", "fur", "hide", "shifting", "blend", "camouflage", "disguise", "surroundings", "environment", "bestiary", "medieval", "classical", "pliny", "scythia", "reindeer", "deer", "antler", "elk", "stag", "deer-like", "reindeer-like"],
        "forbidden_terms": ["glowing", "embers", "fire", "flame", "smoke", "molten", "golden antlers", "twisted gold", "burning", "crackling", "hooves of fire", "smoldering", "spectral", "ghost", "mist", "shapeshift", "humanoid", "human", "man", "woman", "person", "face", "hooves that never touch", "obsidian hooves"],
        "min_matches": MIN_MATCHES
    },

    "NURIKABE": {
        "required_terms": ["nurikabe", "yokai", "wall", "barrier", "invisible", "path", "traveler", "night", "japanese", "japanese folklore", "japanese myth", "japanese yokai", "block", "blocking", "blocks path", "invisible wall", "impassable", "dispelled", "strike", "striking"],
        "forbidden_terms": ["ghost", "specter", "spirit", "phantom", "shadow", "skeletal", "skeleton", "humanoid", "human", "person", "figure", "face", "eyes", "glowing eyes", "hollow eyes", "cloak", "tattered", "whisper", "whispers", "secrets", "graveyard", "cemetery", "memories", "life drain", "life force", "touch", "clings", "ceiling", "fox", "kitsune", "cat", "animal", "fur", "horn", "spiraled horn", "water", "drown", "river", "well", "underwater"],
        "min_matches": MIN_MATCHES
    },

    # Nymph - Nature spirit
    "NYMPH": {
        "required_terms": ["nymph", "nymphai", "nature spirit", "nature deity", "lesser goddess", "greek mythology", "hellenic", "ancient greece", "classical mythology", "beautiful woman", "beautiful maiden", "lovely female", "fair maiden", "youthful", "young", "eternal youth", "immortal", "long-lived", "ageless", "associated with nature", "nature location", "specific location bound", "dryad", "tree nymph", "naiad", "water nymph", "oread", "mountain nymph", "oceanid", "sea nymph", "nereid", "salt water nymph", "limoniad", "meadow nymph"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Ochre Jelly - Gelatinous cube variant
    "OCHRE_JELLY": {
        "required_terms": ["ochre", "jelly", "ooze", "gelatinous", "slime", "acid", "dungeon", "amorphous", "ochre jelly", "ochre-colored jelly", "yellow-brown jelly", "amber jelly", "ooze", "gelatinous cube variant", "gelatinous creature", "gelatinous monster", "slime", "slime monster", "slime creature", "amorphous", "formless", "shapeless", "liquid", "fluid", "semi-liquid", "semi-solid", "viscous", "thick liquid", "acidic", "corrosive", "dissolving", "melting", "eating away", "consuming", "dungeon dweller", "underground", "cavern", "tunnel", "ruins", "abandoned place"],
        "forbidden_terms": ["solid", "hard", "structured", "organized", "formed", "shaped", "sculpted", "carved", "built", "constructed", "fashioned", "molded", "designed"],
        "min_matches": MIN_MATCHES
    },

    # Ogre - Large ugly humanoid
    "OGRE": {
        "required_terms": ["ogre", "large", "ugly", "humanoid", "stupid", "club", "giant", "fairy tale", "ogre", "fairy tale giant", "fairy tale monster", "folk tale monster", "large humanoid", "big humanoid", "oversized humanoid", "giant-like", "ugly", "hideous", "grotesque", "repulsive", "frightening appearance", "stupid", "dim-witted", "dull", "slow-witted", "unintelligent", "simple", "club", "wooden club", "great club", "massive club", "tree branch club", "fairy tale", "folk tale", "children's story", "legend", "myth", "folklore", "man-eater", "people eater", "human consumer", "cannibal", "flesh eater"],
        "forbidden_terms": ["beautiful", "smart", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent", "cunning"],
        "min_matches": MIN_MATCHES
    },

    # Oni - Japanese demon
    "ONI": {
        "required_terms": ["japanese", "demon", "ogre", "horn", "club", "tiger skin", "red", "blue", "kanabō", "spiked club", "iron club", "massive club", "tiger fur", "tiger pelt", "tiger pattern", "red skin", "blue skin", "green skin", "black skin", "yellow skin", "sharp claws", "sharp teeth", "fangs", "wild hair", "unkempt hair", "horned", "horns", "one horn", "two horns", "multiple horns", "sharp horns", "folklore", "mythology", "buddhist influence", "nihon ryōiki", "konjaku monogatarishū", "otogizōshi"],
        "forbidden_terms": ["european", "greek", "norse", "celtic", "slavic", "christian", "biblical", "angelic", "divine", "holy", "sacred", "blessed", "pure", "innocent"],
        "min_matches": MIN_MATCHES
    },

    # Ooze - Amorphous blob
    "OOZE": {
        "required_terms": ["slime", "gelatinous", "amorphous", "liquid", "dissolve", "acid", "blob", "gelatinous creature", "gelatinous monster", "gelatinous blob", "formless", "shapeless", "unformed", "structureless", "fluid", "semi-liquid", "semi-solid", "viscous", "thick liquid", "acidic", "corrosive", "dissolving", "melting", "eating away", "consuming", "transparent", "translucent", "clear", "semi-clear", "cloudy", "murky", "dungeon dweller", "underground", "cavern", "tunnel", "ruins", "abandoned place", "engulf", "envelop", "surround", "consume", "absorb", "digest"],
        "forbidden_terms": ["solid", "hard", "structured", "organized", "formed", "shaped", "sculpted", "carved", "built", "constructed", "fashioned", "molded", "designed", "skeleton", "bones", "organs", "limbs", "appendages", "features"],
        "min_matches": MIN_MATCHES
    },

    # Oracle - Prophet
    "ORACLE": {
        "required_terms": ["prophet", "seer", "future", "predict", "divine", "wisdom", "priest", "prophetess", "seeress", "diviner", "augur", "fortune teller", "soothsayer", "foreteller", "predictor", "prognosticator", "future teller", "future seer", "foreseer", "prophecy", "prediction", "foretelling", "augury", "divination", "soothsaying", "sacred", "holy", "divine connection", "god connection", "goddess connection", "temple", "shrine", "sacred place", "holy place", "sanctuary", "delphi", "pythia", "sibyl", "prophetic trance", "divine inspiration", "god speaking"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Orc - Brutal humanoid
    "ORC": {
        "required_terms": ["brutal", "savage", "green", "tusks", "muscular", "warrior", "tribe", "goblinoid", "brutish", "powerful", "mighty", "muscular", "well-built", "heavily built", "green skin", "gray skin", "dusky skin", "dark skin", "mottled skin", "tusks", "boar tusks", "lower tusks", "protruding tusks", "ivory tusks", "savage", "ferocious", "fierce", "wild", "untamed", "barbaric", "primitive", "weapon", "axe", "sword", "club", "mace", "spear", "bow", "shield", "tribe", "clan", "horde", "warlike", "aggressive", "warmongering"],
        "forbidden_terms": ["beautiful", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent", "cunning", "clever", "peaceful", "gentle", "kind"],
        "min_matches": MIN_MATCHES
    },

    # Oread - Mountain nymph
    "OREAD": {
        "required_terms": ["mountain", "nymph", "hill", "rock", "stone", "greek", "female", "nature", "oreas", "oreades", "mountain nymph", "hill nymph", "grotto nymph", "greek mythology", "nature spirit", "nature deity", "lesser goddess", "beautiful woman", "beautiful maiden", "lovely female", "fair maiden", "youthful", "young", "eternal youth", "immortal", "long-lived", "ageless", "mountain dweller", "mountain resident", "peak inhabitant", "cliff dweller", "rocky terrain", "rocky area", "stone area", "mountain landscape", "associated with mountains", "connected to mountains", "bound to mountain"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Owlbear - Owl-bear hybrid
    "OWLBEAR": {
        "required_terms": ["owl", "bear", "hybrid", "beak", "feather", "fur", "claw", "ferocious", "owl bear", "bear owl", "strange hybrid", "magical hybrid", "owl head", "owl face", "round face", "large eyes", "forward-facing eyes", "beak", "hooked beak", "sharp beak", "powerful beak", "tearing beak", "feathers", "feathery", "feathered body parts", "feather mane", "bear body", "powerful bear body", "muscular bear form", "ursine body", "fur", "shaggy fur", "thick fur", "brown fur", "gray fur", "tawny fur", "claws", "sharp claws", "powerful claws", "tearing claws", "grasping claws", "ferocious", "savage", "wild", "untamed", "aggressive", "dangerous"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect"],
        "min_matches": MIN_MATCHES
    },

    # Pegasus - Winged horse
    "PEGASUS": {
        "required_terms": ["winged", "horse", "white", "flying", "greek", "mythological", "winged horse", "flying horse", "divine horse", "greek mythology", "mythological creature", "legendary beast", "white", "snow-white", "pure white", "ivory white", "milky white", "wings", "feathered wings", "bird-like wings", "eagle-like wings", "flying", "flight", "soaring", "gliding", "hovering", "airborne", "born from medusa", "medusa's blood", "poseidon's son", "poseidon offspring", "bellerophon's mount", "bellerophon rider", "hero's steed", "mount of heroes", "constellation", "stars", "night sky", "heavens", "sky dweller"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect"],
        "min_matches": MIN_MATCHES
    },

    # Peryton - Winged deer
    "PERYTON": {
        "required_terms": ["winged", "deer", "stag", "bird", "shadow", "human", "heart", "winged deer", "winged stag", "bird-deer hybrid", "deer body", "stag body", "cervine body", "antlers", "branching antlers", "bird wings", "feathered wings", "avian wings", "eagle-like wings", "shadow of a man", "human shadow", "man-shaped shadow", "human silhouette", "heart", "human heart", "steals hearts", "eats hearts", "heart consumer", "iberian mythology", "spanish folklore", "medieval bestiary", "bestiary", "omen of death", "death omen", "bad omen", "ill omen", "harbinger"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect"],
        "min_matches": MIN_MATCHES
    },

    # Phantom - Ghost
    "PHANTOM": {
        "required_terms": ["ghost", "spirit", "apparition", "specter", "ethereal", "haunt", "spectre", "wraith", "ethereal", "incorporeal", "disembodied", "bodiless", "intangible", "insubstantial", "immaterial", "nonphysical", "spiritual", "otherworldly", "translucent", "transparent", "see-through", "vaporous", "misty", "fog-like", "haunt", "haunting", "appear", "materialize", "manifest", "show", "reveal", "haunted place", "haunted location", "spooky place", "creepy place", "nocturnal", "night", "darkness", "shadow", "gloom", "dim light"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living"],
        "min_matches": MIN_MATCHES
    },

    # Phaya Nak - Thai naga
    "PHAYA_NAK": {
        "required_terms": ["thai", "thailand", "southeast asian", "serpent", "snake", "dragon", "water", "river", "mekong", "guardian", "protector", "temple", "shrine", "scales", "scaly", "reptilian", "long body", "elongated", "coiling", "hood", "cobra-like", "multiple heads", "multi-headed", "crown", "regal", "majestic", "divine", "sacred", "holy", "worshipped", "offerings", "festival", "naga fireballs", "mekong lights", "luminous", "glowing", "buddhist", "hindu", "mythology", "legendary"],
        "forbidden_terms": ["european", "western", "christian", "biblical", "greek", "norse", "celtic", "slavic", "egyptian", "mesopotamian", "persian", "evil", "malevolent", "wicked", "sinister", "malicious"],
        "min_matches": MIN_MATCHES
    },

    # Phoenix - Fire bird
    "PHOENIX": {
        "required_terms": ["bird", "fire", "rebirth", "immortal", "flame", "golden", "red", "egyptian", "fire bird", "sun bird", "mythical bird", "legendary bird", "greek mythology", "egyptian mythology", "persian mythology", "chinese mythology", "red", "golden", "orange", "crimson", "scarlet", "vermilion", "fiery colors", "fire", "flame", "flames", "fire aura", "flame aura", "fire surrounding", "rebirth", "resurrection", "renewal", "regeneration", "reincarnation", "immortal", "eternal", "undying", "everlasting", "perpetual", "endless", "rises from ashes", "born from ashes", "emerges from ashes", "ashes to life", "tears heal", "healing tears", "curative tears", "restorative tears"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "mammal"],
        "min_matches": MIN_MATCHES
    },

    # Pit Fiend - Powerful devil
    "PIT_FIEND": {
        "required_terms": ["devil", "demon", "infernal", "winged", "horn", "tail", "baator", "pit devil", "archdevil", "baatezu", "greater devil", "dungeons and dragons", "d&d", "forgotten realms", "planes", "hell", "infernal", "hellish", "fiendish", "diabolical", "satanic", "demonic", "winged", "bat wings", "leathery wings", "great wings", "powerful wings", "horned", "large horns", "curving horns", "spiral horns", "multiple horns", "tail", "barbed tail", "spiked tail", "lashing tail", "prehensile tail", "red skin", "crimson skin", "scarlet skin", "fiery skin", "hot skin", "powerful", "mighty", "strong", "formidable", "intimidating", "fearsome"],
        "forbidden_terms": ["holy", "divine", "angelic", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful"],
        "min_matches": MIN_MATCHES
    },

    # Pixie - Small fairy
    "PIXIE": {
        "required_terms": ["small", "fairy", "winged", "magic", "mischievous", "pointed ears", "pixy", "piskie", "pigsie", "little fairy", "wee fairy", "diminutive", "tiny", "wee", "little", "petite", "miniature", "minuscule", "winged", "butterfly wings", "dragonfly wings", "gossamer wings", "iridescent wings", "magic", "magical", "enchanting", "spell-casting", "charming", "bewitching", "mischievous", "playful", "prankish", "tricky", "cunning", "sly", "crafty", "pointed ears", "elven ears", "leaf-shaped ears", "tapered ears", "cornwall", "devon", "somerset", "west country", "celtic folklore"],
        "forbidden_terms": ["large", "evil", "demonic", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Poltergeist - Noisy ghost
    "POLTERGEIST": {
        "required_terms": ["noisy ghost", "noisy spirit", "racket", "din", "clamor", "pandemonium", "uproar", "commotion", "move objects", "throw objects", "hurl objects", "levitate objects", "knocking", "banging", "rapping", "tapping", "pounding", "thumping", "invisible", "unseen", "hidden", "concealed", "not visible", "cannot see", "haunt", "haunting", "disturb", "torment", "harass", "plague", "bother", "adolescent focus", "teenager connection", "youth association", "german folklore", "germanic", "teutonic", "central european"],
        "forbidden_terms": ["solid", "visible", "physical", "corporeal", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood"],
        "min_matches": MIN_MATCHES
    },

    # Pseudodragon - Tiny dragon
    "PSEUDODRAGON": {
        "required_terms": ["false dragon", "dragonet", "miniature dragon", "tiny dragon", "diminutive", "tiny", "wee", "little", "petite", "miniature", "minuscule", "scaled", "scaly", "scales", "reptilian", "draconic", "dragon-like", "tail", "long tail", "prehensile tail", "barbed tail", "stinger tail", "stinger", "poison stinger", "venom stinger", "paralytic venom", "telepathic", "telepathy", "mind communication", "mental communication", "intelligent", "smart", "clever", "cunning", "wise", "sagacious", "dungeons and dragons", "d&d", "familiar", "wizard's familiar", "companion"],
        "forbidden_terms": ["large", "massive", "giant", "huge", "enormous", "colossal", "gargantuan", "towering", "mountainous", "immense", "vast", "prodigious", "monstrous size"],
        "min_matches": MIN_MATCHES
    },

    # Qat - Plant creature
    "QAT": {
        "required_terms": ["plant", "leaves", "chewed", "stimulant", "euphoric", "sentient", "deadly", "shrub", "catha", "edulis", "conscious", "venomous", "tea", "tobacco", "khat", "arabian tea", "somali tea", "ethiopian tea", "plant creature", "plant monster", "botanical being", "flora being", "green leaves", "leafy", "foliage", "leaf-covered", "leafy growth", "chewing", "mastication", "consumed orally", "oral consumption", "stimulating", "energizing", "invigorating", "activating", "euphoria-inducing", "pleasure-giving", "happiness-causing", "conscious", "aware", "thinking", "intelligent", "self-aware", "lethal", "fatal", "dangerous", "poisonous", "toxic"],
        "forbidden_terms": ["benevolent", "healing", "peaceful", "passive", "animal", "beast", "flying", "swimming", "mineral", "stone", "metal", "friendly", "docile", "harmless", "medicinal", "curative", "restorative", "therapeutic", "remedial"],
        "min_matches": MIN_MATCHES
    },

    # Quetzalcoatl - Feathered serpent
    "QUETZALCOATL": {
        "required_terms": ["feathered", "serpent", "snake", "aztec", "mesoamerican", "god", "winged", "kukulkan", "gukumatz", "feathered serpent", "plumed serpent", "aztec mythology", "mayan mythology", "toltec", "mesoamerican deity", "serpent body", "snake body", "reptilian form", "serpentine form", "feathers", "quetzal feathers", "bright feathers", "green feathers", "winged", "feathered wings", "bird-like wings", "soaring serpent", "wind god", "wind deity", "ehecatl aspect", "wind bringer", "culture hero", "civilization bringer", "knowledge bringer", "arts patron", "morning star", "venus", "planet venus", "sky deity", "heavenly serpent"],
        "forbidden_terms": ["mammal", "fur", "european", "christian", "biblical", "judeo-christian", "greek", "norse", "celtic", "slavic", "egyptian", "african", "asian"],
        "min_matches": MIN_MATCHES
    },

    # Quinotaur - Five-horned bull
    "QUINOTAUR": {
        "required_terms": [ "five", "horn", "bull", "bovine", "taurine", "frankish", "merovingian", "frankish myth", "merovingian legend", "sea", "sea creature", "marine", "ocean", "salt water" ],
        "forbidden_terms": [ "human", "humanoid", "man", "woman", "person", "torso", "face", "horse", "equine", "serpent", "serpentine", "snake", "dragon", "legs", "five legs", "limbs", "antler", "antlers", "kelp", "barnacle", "algae", "weapon", "axe", "sword", "club", "forest", "wood", "marsh", "river" ],
        "min_matches": MIN_MATCHES
    },

    # Rakshasa - Hindu demon
    "RAKSHASA": {
        "required_terms": ["hindu", "demon", "tiger", "animal", "head", "backward", "hands", "rakshas", "rakshasi", "female rakshasa", "hindu mythology", "indian mythology", "ramayana", "mahabharata", "puranas", "vedic", "evil spirit", "malevolent being", "dark entity", "tiger", "tiger features", "tiger-like", "feline features", "animal head", "beast head", "predator head", "wild animal head", "backward hands", "reversed palms", "palms reversed", "hands backwards", "shape-shifter", "shapeshifter", "illusion caster", "magic user", "cannibal", "man-eater", "flesh eater", "corpse eater"],
        "forbidden_terms": ["holy", "divine", "good", "angelic", "benevolent", "kind", "gentle", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent"],
        "min_matches": MIN_MATCHES
    },

########################################
    # Rat - Rodent
    "RAT": {
        "required_terms": ["rodent", "vermin", "tail", "whiskers", "teeth", "brown rat", "black rat", "norway rat", "roof rat", "rattus", "rodent", "murid", "muroid", "mouse-like", "mouselike", "vermin", "pest", "nuisance", "menace", "problem", "infestation", "long tail", "naked tail", "scaly tail", "prehensile tail", "whiskers", "vibrissae", "sensitive whiskers", "facial whiskers", "incisors", "front teeth", "gnawing teeth", "sharp teeth", "small", "diminutive", "tiny", "wee", "little", "petite", "urban", "city dweller", "sewer dweller", "underground"],
        "forbidden_terms": ["scaled", "feathered", "reptile", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "bird", "beak", "talons"],
        "min_matches": MIN_MATCHES
    },

    # Redcap - Murderous goblin
    "REDCAP": {
        "required_terms": ["red cap", "bloody cap", "blood cap", "goblin", "border", "scottish", "murder", "dye", "blood", "border goblin", "border reiver", "anglo-scottish border", "scottish folklore", "border folklore", "lowland scottish", "evil fairy", "malevolent fae", "wicked sprite", "kill", "slay", "massacre", "butcher", "dispatch", "cap dipped in blood", "blood-soaked cap", "iron-shod boots", "iron boots", "boots with iron", "iron-tipped boots", "iron pike", "iron staff", "iron weapon", "metal weapon", "castle ruins", "tower ruins", "abandoned fortress", "border castle"],
        "forbidden_terms": ["good", "kind", "benevolent", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous"],
        "min_matches": MIN_MATCHES
    },

    # Remorhaz - Arctic centipede
    "REMORHAZ": {
        "required_terms": ["arctic", "centipede", "insect", "ice", "heat", "back", "tunnel", "arctic centipede", "ice centipede", "polar centipede", "dungeons and dragons", "d&d", "forgotten realms", "greyhawk", "arctic", "polar", "frozen", "glacial", "snow", "ice", "tundra", "centipede", "many-legged", "segmented body", "elongated body", "insectoid", "insect-like", "chitinous", "exoskeleton", "segmented plates", "fiery back", "glowing back", "hot carapace", "burning ridge", "tunnel", "burrow", "dig", "excavate", "subterranean", "under ice", "polar predator", "arctic hunter", "ice stalker", "snow lurker"],
        "forbidden_terms": ["mammal", "fur", "bird", "feathered", "beak", "talons", "reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise"],
        "min_matches": MIN_MATCHES
    },

    # Revenant - Vengeful undead
    "REVENANT": {
        "required_terms": ["vengeful", "undead", "returned", "vengeance", "revenge", "justice", "wronged", "murdered", "killed", "slain", "unfinished business", "unavenged", "restless", "corpse", "decayed", "rotting", "decomposed", "risen from grave", "return from death", "hunt", "pursue", "track", "stalk", "kill", "destroy", "torment", "terrify", "fearsome", "dreadful", "horrifying", "implacable", "unstoppable", "relentless", "persistent", "night", "darkness", "shadows", "haunt", "haunting", "folklore", "legend"],
        "forbidden_terms": ["living", "alive", "peaceful", "calm", "forgiving", "merciful", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful"],
        "min_matches": MIN_MATCHES
    },

    # River Serpent - Water snake
    "RIVER_SERPENT": {
        "required_terms": ["river", "water", "snake", "serpent", "aquatic", "long", "water serpent", "freshwater serpent", "aquatic serpent", "snake", "serpent", "reptile", "scaly", "scales", "elongated", "long body", "elongated form", "serpentine", "snake-like", "aquatic", "water-dwelling", "river-dwelling", "stream-dwelling", "freshwater", "river water", "stream water", "lake water", "swimmer", "undulates in water", "water movement", "aquatic locomotion", "ambush predator", "hidden hunter", "water stalker", "submerged lurker", "legendary", "mythical", "folkloric", "mythological", "tales", "stories"],
        "forbidden_terms": ["winged", "feathered", "fur", "hair", "wool", "hide", "pelt", "mammal", "bird", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Roc - Giant bird
    "ROC": {
        "required_terms": ["giant", "bird", "eagle", "arabian", "elephant", "carry", "massive", "rukh", "rok", "rukhkh", "arabian mythology", "persian mythology", "giant bird", "enormous bird", "colossal bird", "massive bird", "eagle-like", "raptor-like", "bird of prey", "massive raptor", "elephant carrier", "lifts elephants", "carries elephants", "elephant prey", "massive", "enormous", "colossal", "gigantic", "immense", "titanic", "wingspan enormous", "blocking sun", "darkening sky", "shadow coverer", "sinbad", "sinbad the sailor", "arabian nights", "thousand and one nights", "mountain nest", "cliff nest", "peak nest", "high nest", "inaccessible nest"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "mammal"],
        "min_matches": MIN_MATCHES
    },

    # Rusalka - Slavic water spirit
    "RUSALKA": {
        "required_terms": ["slavic", "water", "spirit", "drowned", "woman", "female", "river", "rusalki", "slavic mythology", "east slavic", "russian", "ukrainian", "polish", "czech", "slovak", "serbian", "bulgarian", "water spirit", "river spirit", "lake spirit", "pond spirit", "drowned woman", "drowned maiden", "drowned girl", "untimely death", "beautiful woman", "pale beauty", "ethereal beauty", "alluring maiden", "long hair", "green hair", "flowing hair", "wet hair", "water hair", "naked", "undressed", "unclothed", "bare", "without clothes", "lure men", "entice men", "attract men", "seduce men", "drown men"],
        "forbidden_terms": ["good", "benevolent", "holy", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Satyr - Goat-man
    "SATYR": {
        "required_terms": ["goat", "man", "hooves", "horns", "greek", "pan", "flute", "wine", "satyrs", "satyress", "female satyr", "greek mythology", "goat-like", "caprine", "bovid features", "goat legs", "goat hooves", "horns", "goat horns", "small horns", "curving horns", "horned", "human torso", "man's body", "human upper body", "muscular chest", "pointed ears", "elven ears", "animal ears", "furry ears", "pan pipes", "syrinx", "flute", "pipe", "musical instrument", "wine", "dionysus", "bacchus", "revelry", "party", "celebration", "wild", "untamed", "woodland", "forest", "rural", "pastoral"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Scylla - Multi-headed sea monster
    "SCYLLA": {
        "required_terms": ["sea", "monster", "greek", "heads", "dogs", "tentacles", "strait", "skylla", "greek mythology", "odyssey", "homer", "odysseus", "sea monster", "ocean monster", "marine monster", "cliff-dweller", "six heads", "multiple heads", "many heads", "multi-headed", "dog heads", "canine heads", "wolf heads", "snarling heads", "tentacles", "tentacle limbs", "octopus-like", "squid-like", "fish body", "fish tail", "dolphin-like", "whale-like", "strait of messina", "sicily", "italy", "charybdis counterpart", "sailor devourer", "ship destroyer", "vessel wrecker", "seafarer threat"],
        "forbidden_terms": ["land", "mountain", "forest", "wood", "tree", "grass", "field", "terrestrial", "ground", "earth", "soil", "dirt", "rock", "stone"],
        "min_matches": MIN_MATCHES
    },

    # Sea Serpent - Sea snake
    "SEA_SERPENT": {
        "required_terms": ["sea", "ocean", "serpent", "snake", "marine", "long", "scaly", "ocean serpent", "marine serpent", "saltwater serpent", "snake-like", "serpentine", "elongated", "long body", "coiling", "scaly", "scales", "reptilian", "fish-like scales", "smooth scales", "ocean", "sea", "deep sea", "open ocean", "marine", "saltwater", "sea monster", "ocean monster", "marine monster", "legendary sea creature", "sightings", "sea reports", "mariner tales", "sailor stories", "large", "giant", "enormous", "massive", "colossal", "immense", "mythical", "legendary", "folkloric", "cryptozoological"],
        "forbidden_terms": ["feather", "fur", "hair", "wool", "hide", "pelt", "mammal", "bird", "insect", "arachnid", "chitin", "exoskeleton", "land", "terrestrial"],
        "min_matches": MIN_MATCHES
    },

    # Selkie - Seal-folk
    "SELKIE": {
        "required_terms": ["seal", "skin", "folk", "celtic", "scottish", "irish", "shape-shift", "selchie", "seal folk", "seal people", "seal-folk", "scottish folklore", "irish folklore", "celtic mythology", "gaelic", "orkney", "shetland", "hebrides", "scottish islands", "coastal", "seal form", "seal shape", "animal form", "marine form", "human form", "human shape", "land form", "skin shed", "seal skin", "animal skin", "magic skin", "transformation skin", "skin hidden", "skin stolen", "cannot return to sea", "trapped on land", "beautiful", "comely", "fair", "lovely", "attractive", "handsome"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons"],
        "min_matches": MIN_MATCHES
    },

    # Shade - Ghostly spirit
    "SHADE": {
        "required_terms": ["shadow", "dark", "spirit", "ghost", "apparition", "phantom", "underworld", "hades", "dead", "soul", "restless", "unquiet", "mournful", "sad", "melancholy", "gloomy", "tenebrous", "stygian", "cimmerian", "lightless", "unlit", "unilluminated", "darkened", "shadowy", "obscure", "hidden", "concealed", "veiled", "shrouded", "cloaked", "incorporeal", "disembodied", "bodiless", "intangible", "insubstantial", "ethereal", "misty", "vaporous", "faint", "dim", "barely visible"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living", "bright", "luminous", "radiant"],
        "min_matches": MIN_MATCHES
    },

    # Shadow - Dark spirit
    "SHADOW": {
        "required_terms": ["dark", "shade", "umbra", "spirit", "incorporeal", "darkness", "lightless", "tenebrous", "gloom", "entity", "being", "presence", "manifestation", "disembodied", "bodiless", "intangible", "insubstantial", "black", "pitch black", "jet black", "coal black", "sable", "inky", "murky", "formless", "shapeless", "amorphous", "fluid form", "flowing shape", "drains life", "life drain", "energy drain", "vitality sapper", "cold touch", "freezing touch", "icy grasp", "chilling contact", "fear aura", "terror aura", "dread presence", "horror manifestation"],
        "forbidden_terms": ["solid", "corporeal", "bright", "luminous", "radiant", "incandescent", "fluorescent", "phosphorescent", "glowing", "gleaming", "shining", "sparkling", "glittering", "twinkling", "scintillating", "brilliant"],
        "min_matches": MIN_MATCHES
    },

    # Siren - Seductive bird-woman
    "SIREN": {
        "required_terms": ["song", "voice", "lure", "sailor", "sea", "greek", "bird", "woman", "seiren", "greek mythology", "odyssey", "homer", "odysseus", "bird-like", "avian", "bird body", "bird legs", "bird wings", "woman head", "woman torso", "female upper body", "beautiful face", "enchanting song", "beautiful voice", "luring melody", "enticing music", "lure sailors", "attract sailors", "draw ships", "tempt seafarers", "shipwreck", "crash boats", "destroy vessels", "kill sailors", "meadow", "flowery meadow", "coastal", "shore", "island", "rocky outcrop", "sirenomelia", "mermaid confusion", "fish tail variant later"],
        "forbidden_terms": ["reptile", "scales", "fish tail", "mermaid", "aquatic mammal", "fins", "gills", "smooth skin", "scaly lower body", "serpentine"],
        "min_matches": MIN_MATCHES
    },

    # Skeleton - Animated bones
    "SKELETON": {
        "required_terms": ["bones", "undead", "skull", "ribs", "animate", "dead", "skeletal", "bony", "osseous", "bone structure", "cranium", "jawbone", "teeth", "vertebrae", "spine", "rib cage", "ribcage", "sternum", "pelvis", "femur", "undead", "animated dead", "risen dead", "walking bones", "animate", "moving", "active", "mobile", "ambulatory", "hollow eyes", "empty sockets", "vacant gaze", "eye holes", "clattering", "rattling", "clacking", "clicking", "noisy movement", "necromancy", "dark magic", "death magic", "raised by magic"],
        "forbidden_terms": ["flesh", "skin", "muscle", "tissue", "organ", "heart", "lung", "brain", "blood", "veins", "arteries", "circulatory", "respiratory", "living"],
        "min_matches": MIN_MATCHES
    },

    # Specter - Ghost
    "SPECTER": {
        "required_terms": ["ghost", "spirit", "apparition", "ethereal", "translucent", "haunt", "spectre", "phantom", "wraith", "ethereal", "incorporeal", "disembodied", "bodiless", "intangible", "insubstantial", "immaterial", "nonphysical", "spiritual", "otherworldly", "translucent", "transparent", "see-through", "vaporous", "misty", "fog-like", "haunt", "haunting", "appear", "materialize", "manifest", "show", "reveal", "pale", "white", "gray", "shadowy", "dim", "faint", "barely visible", "dread", "fear", "terror", "horror", "unease", "discomfort", "chill"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living"],
        "min_matches": MIN_MATCHES
    },

    # Sphynx - Egyptian guardian
    "SPHYNX": {
        "required_terms": ["lion", "human", "head", "egyptian", "guardian", "riddle", "greek", "winged", "sphinx", "ande", "greek mythology", "egyptian mythology", "lion body", "human head", "pharaoh head", "king's head", "royal head", "male", "female", "riddle", "question", "puzzle", "enigma", "answer", "solve", "devour", "strangle", "kill", "temple guardian", "tomb guardian", "pyramid guardian", "giza", "great sphinx", "monumental", "stone", "carved", "sculpted", "statue", "mythical", "legendary"],
        "forbidden_terms": ["bird body", "bird head", "eagle", "falcon", "reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad"],
        "min_matches": MIN_MATCHES
    },

    # Spider - Arachnid
    "SPIDER": {
        "required_terms": ["arachnid", "web", "eight legs", "fangs", "venom", "silken", "araneae", "eight-legged", "8 legs", "spider web", "cobweb", "orb web", "tangle web", "funnel web", "silk", "silken", "spinneret", "silk gland", "silk production", "fangs", "chelicerae", "venom fangs", "poison delivery", "venom", "poison", "toxic", "venomous", "poisonous", "deadly bite", "multiple eyes", "eight eyes", "multiple lenses", "compound eyes", "cephalothorax", "abdomen", "two body segments", "jointed legs", "predator", "hunter", "ambusher", "web trapper", "active hunter"],
        "forbidden_terms": ["six legs", "insect", "beetle", "ant", "bee", "wasp", "fly", "butterfly", "moth", "dragonfly", "grasshopper", "cricket", "mantis", "roach"],
        "min_matches": MIN_MATCHES
    },

    # Spider Giant - Large spider
    "SPIDER_GIANT": {
        "required_terms": ["giant", "large", "arachnid", "web", "eight legs", "venom", "monstrous", "giant spider", "monstrous spider", "huge spider", "large", "giant", "enormous", "massive", "colossal", "immense", "towering", "eight legs", "8 legs", "massive legs", "thick legs", "powerful legs", "web", "giant web", "massive web", "strong web", "thick silk", "fangs", "giant fangs", "massive fangs", "deadly fangs", "venom", "poison", "toxic", "venomous", "poisonous", "deadly bite", "multiple eyes", "eight eyes", "gleaming eyes", "glowing eyes", "predator", "hunter", "man-eater", "human prey", "large prey hunter", "cave dweller", "forest dweller", "dark place", "lair", "den"],
        "forbidden_terms": ["small", "tiny", "diminutive", "miniature", "minuscule", "petite", "wee", "little", "compact", "pocket-sized", "small-scale", "undersized"],
        "min_matches": MIN_MATCHES
    },

    # Spriggan - Cornish fairy
    "SPRIGGAN": {
        "required_terms": ["cornish", "cornwall", "fairy", "fae", "guardian", "ancient", "tomb", "shape-shift", "spriggans", "cornish folklore", "west country", "fairy", "fae", "faerie", "fairy folk", "little people", "guardian", "protector", "warden", "sentinel", "watchman", "ancient sites", "burial mounds", "tombs", "standing stones", "ancient ruins", "treasure guardian", "hidden treasure", "ancient wealth", "buried gold", "shape-shifter", "shapeshifter", "size changer", "grow larger", "become huge", "ugly", "grotesque", "wrinkled", "wizened", "old appearance", "carry off children", "kidnap children", "steal children", "child thief", "mischievous", "malevolent", "dangerous", "harmful", "wicked"],
        "forbidden_terms": ["evil", "demonic", "undead", "holy", "divine", "angelic", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle"],
        "min_matches": MIN_MATCHES
    },

    # Stone Golem - Stone construct
    "STONE_GOLEM": {
        "required_terms": ["stone", "rock", "construct", "animated", "carved", "masonry", "rock golem", "granite", "marble", "limestone", "sandstone", "basalt", "quartz", "flint", "slate", "rocky", "stony", "craggy", "rugged", "golem", "construct", "animated statue", "living stone", "animated rock", "hard", "solid", "dense", "durable", "tough", "strong", "resilient", "sturdy", "carved", "sculpted", "chiseled", "hewn", "fashioned", "formed", "shaped", "masonry", "stone blocks", "fitted stone", "mortar", "stonework", "slow moving", "ponderous", "heavy-footed", "deliberate", "measured"],
        "forbidden_terms": ["flesh", "organic", "living", "biological", "muscle", "tissue", "skin", "blood", "bone", "soft", "malleable", "pliable", "flexible", "bendable"],
        "min_matches": MIN_MATCHES
    },

    # Storm Giant - Giant of storms
    "STORM_GIANT": {
        "required_terms": ["storm", "giant", "lightning", "thunder", "cloud", "tempest", "sky", "norse", "cloud giant", "sky giant", "tempest giant", "thunder giant", "lightning giant", "jotunn", "jotun", "norse mythology", "germanic", "electrical", "electric", "thunderbolt", "thunderclap", "lightning bolt", "thunderstorm", "hurricane", "cyclone", "typhoon", "tornado", "whirlwind", "weather", "elemental", "sky-dweller", "cloud-dweller", "mountain peak", "blue skin", "blue-gray skin", "storm-colored", "cloud-colored", "mighty", "powerful", "majestic", "awe-inspiring", "terrifying", "trident", "lightning weapon", "thunder weapon", "storm weapon"],
        "forbidden_terms": ["earth", "stone", "rock", "ground", "soil", "dirt", "clay", "mud", "sand", "underground", "subterranean", "cave", "cavern", "tunnel", "mine", "deep"],
        "min_matches": MIN_MATCHES
    },

    # Striga - Vampiric witch
    "STRIGA": {
        "required_terms": ["vampire", "witch", "slavic", "blood", "night", "bird", "undead", "strigoi", "strigon", "slavic vampire", "romanian vampire", "eastern european", "slavic folklore", "balkan", "carpathian", "undead", "revenant", "risen dead", "walking dead", "blood drinker", "blood sucker", "blood consumer", "hematophage", "sorceress", "dark magic user", "evil spellcaster", "night stalker", "nocturnal", "darkness dweller", "moonlight hunter", "bird form", "transform to bird", "bird shape", "avian shape", "pale skin", "corpse-like", "decayed", "rotting", "foul appearance"],
        "forbidden_terms": ["holy", "divine", "good", "angelic", "benevolent", "kind", "gentle", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent"],
        "min_matches": MIN_MATCHES
    },

    # Succubus - Female demon of lust
    "SUCCUBUS": {
        "required_terms": ["female", "demon", "seductive", "lust", "dream", "wing", "tail", "succubi", "demoness", "devil woman", "seductive", "alluring", "enticing", "tempting", "irresistible", "beautiful", "gorgeous", "stunning", "ravishing", "breathtaking", "lust", "desire", "passion", "carnal", "sensual", "erotic", "sexual", "dream visitor", "night visitor", "sleep invader", "dream demon", "life drain", "energy drain", "vitality drain", "soul drain", "bat wings", "leathery wings", "demon wings", "winged", "tail", "pointed tail", "spade-tipped tail", "prehensile tail", "horns", "small horns", "curving horns", "demon horns"],
        "forbidden_terms": ["holy", "divine", "innocent", "pure", "virginal", "chaste", "virtuous", "righteous", "good", "benevolent", "kind", "gentle", "soft", "tender"],
        "min_matches": MIN_MATCHES
    },

    # Tarasque - French dragon-turtle
    "TARASQUE": {
        "required_terms": ["french", "dragon", "turtle", "lion", "bear", "six legs", "provence", "tarasque", "french mythology", "provence legend", "southern france", "dragon-like", "draconic", "reptilian", "serpentine features", "turtle shell", "tortoise shell", "carapace", "armored back", "lion head", "lion face", "leonine features", "feline head", "bear body", "ursine body", "powerful body", "muscular torso", "six legs", "6 legs", "multiple legs", "many legs", "tail", "long tail", "serpent tail", "scorpion tail", "saint Martha", "tamed by saint", "christian legend", "miracle", "river rhone", "tarascon", "ville de tarascon", "provence town"],
        "forbidden_terms": ["small", "weak", "harmless", "tame", "gentle", "docile", "friendly", "kind", "benevolent", "nice", "pleasant", "agreeable", "inoffensive"],
        "min_matches": MIN_MATCHES
    },

    # Thunderbird - Native American storm bird
    "THUNDERBIRD": {
        "required_terms": ["bird", "thunder", "lightning", "storm", "native american", "wings", "thunder bird", "native american mythology", "indian legend", "first nations", "plains tribes", "woodland tribes", "pacific northwest", "giant bird", "enormous bird", "massive bird", "colossal bird", "thunder", "thunderous wings", "wings create thunder", "thunder sound", "lightning", "lightning eyes", "lightning strike", "lightning bolts", "storm bringer", "storm creator", "rain bringer", "weather controller", "wings", "massive wings", "enormous wingspan", "powerful wings", "eagle-like", "raptor-like", "bird of prey", "majestic raptor", "sky dweller", "cloud dweller", "mountain nest", "high peak"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "mammal"],
        "min_matches": MIN_MATCHES
    },

    # Titan - Greek primordial giant
    "TITAN": {
        "required_terms": ["giant", "greek", "primordial", "ancient", "colossal", "powerful", "titans", "titanes", "greek mythology", "hesiod", "theogony", "primordial deities", "elder gods", "before olympians", "first gods", "giant", "colossal", "enormous", "massive", "immense", "towering", "cronus", "rhea", "oceanus", "tethys", "hyperion", "theia", "coeus", "phoebe", "crius", "iapetus", "mnemosyne", "themis", "atlas", "prometheus", "epimetheus", "menoecious", "let", "asteria", "perses", "pallas", "ancient power", "primal force", "cosmic being", "elemental force", "overthrown", "titanomachy", "war with olympians", "defeated by zeus"],
        "forbidden_terms": ["small", "weak", "insignificant", "minor", "lesser", "petty", "trivial", "unimportant", "ordinary", "common", "average", "typical", "normal"],
        "min_matches": MIN_MATCHES
    },

    # Tomb Wraith - Undead guardian
    "TOMB_WRAITH": {
        "required_terms": ["tomb", "grave", "undead", "guardian", "spirit", "ethereal", "ancient", "sepulcher", "crypt", "burial chamber", "mausoleum", "wraith", "ghost", "spirit", "specter", "apparition", "phantom", "undead", "restless dead", "unquiet spirit", "risen dead", "guardian", "protector", "warden", "sentinel", "watchman", "ancient", "old", "ages-old", "centuries-old", "long-dead", "ethereal", "incorporeal", "disembodied", "intangible", "insubstantial", "drain life", "life drain", "energy drain", "vitality sapper", "cold touch", "freezing touch", "icy grasp", "chilling contact", "hollow eyes", "glowing eyes", "burning gaze", "piercing stare"],
        "forbidden_terms": ["living", "alive", "solid", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "flesh and blood"],
        "min_matches": MIN_MATCHES
    },

    # Treant - Tree guardian
    "TREANT": {
        "required_terms": ["tree", "ent", "wood", "bark", "roots", "branches", "forest", "guardian", "tree shepherd", "tree herder", "tree guardian", "tree-like", "arboreal", "wooden", "ligneous", "bark-covered", "bark", "tree bark", "rough bark", "mossy bark", "lichen-covered", "roots", "root feet", "root legs", "ground roots", "anchoring roots", "branches", "branch arms", "leafy limbs", "twig fingers", "leaves", "leafy hair", "foliage crown", "green leaves", "forest", "woods", "grove", "woodland", "old growth", "ancient forest", "guardian", "protector", "defender", "watcher", "keeper of woods", "slow moving", "patient", "deliberate", "ancient", "wise", "old"],
        "forbidden_terms": ["reptile", "scales", "animal", "mammal", "bird", "feathered", "beak", "talons", "fur", "hide", "pelt", "flesh", "skin", "muscle"],
        "min_matches": MIN_MATCHES
    },

    # Troll - Regenerating giant
    "TROLL": {
        "required_terms": ["giant", "ugly", "regenerate", "cave", "mountain", "bridge", "slow-witted", "large", "hideous", "grotesque", "strong", "powerful", "regeneration", "healing", "rapid healing", "recovery", "cave dweller", "mountain dweller", "bridge dweller", "under bridge", "tunnel", "cavern", "dark", "nocturnal", "night", "stone", "rock", "boulder", "club", "weapon", "stupid", "dim-witted", "dull", "unintelligent", "simple", "folklore", "scandinavian", "norse", "germanic"],
        "forbidden_terms": ["beautiful", "graceful", "elegant", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent", "cunning", "clever", "peaceful", "gentle", "kind", "small", "tiny"],
        "min_matches": MIN_MATCHES
    },

    # Umber Hulk - Burrowing insectoid
    "UMBER_HULK": {
        "required_terms": ["burrow", "insect", "chitin", "claws", "confusing", "eyes", "tunnel", "umber hulk", "dungeons and dragons", "d&d", "forgotten realms", "burrow", "tunnel", "dig", "excavate", "underground movement", "insectoid", "insect-like", "beetle-like", "ant-like", "arthropod", "chitin", "chitinous plates", "armored hide", "exoskeleton", "large claws", "powerful claws", "digging claws", "crushing claws", "confusing gaze", "confusion", "mind confusion", "confusing effect", "multiple eyes", "compound eyes", "many eyes", "complex eyes", "subterranean", "underdark", "underground", "cavern", "tunnel network", "powerful", "strong", "formidable", "dangerous", "deadly", "fearsome"],
        "forbidden_terms": ["mammal", "fur", "feather", "bird", "reptile", "snake", "lizard", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills"],
        "min_matches": MIN_MATCHES
    },

    # Undine - Water elemental
    "UNDINE": {
        "required_terms": ["water", "elemental", "nymph", "female", "spirit", "wave", "aquatic", "ondine", "water elemental", "water spirit", "water nymph", "female", "woman", "maiden", "goddess-like", "beautiful", "elemental", "elemental being", "elemental spirit", "primordial", "water", "aquatic", "marine", "freshwater", "river", "lake", "sea", "wave", "current", "tide", "flow", "stream", "surge", "translucent", "water-like", "fluid", "liquid", "flowing form", "shape-shift", "shapeshifter", "change form", "water manipulation", "fountain", "spring", "well", "water source", "body of water"],
        "forbidden_terms": ["fire", "earth", "air", "flame", "burn", "heat", "warm", "hot", "stone", "rock", "mountain", "ground", "soil", "dirt", "clay", "mud"],
        "min_matches": MIN_MATCHES
    },

    # Unicorn - Horned horse
    "UNICORN": {
        "required_terms": ["horse", "horn", "white", "pure", "magical", "healing", "maiden", "unicornis", "horned horse", "single horn", "spiral horn", "white", "snow-white", "pure white", "ivory white", "milky white", "horse", "equine", "steed", "stallion", "mare", "foal", "spiral horn", "twisted horn", "alicorn", "magical horn", "pure", "chaste", "virtuous", "innocent", "untainted", "uncorrupted", "magical", "mythical", "legendary", "fabulous", "fantastical", "healing", "curative", "restorative", "purifying", "cleansing", "maiden", "virgin", "pure maiden", "only approachable by maidens", "forest", "woodland", "glade", "meadow", "wild", "untamed"],
        "forbidden_terms": ["evil", "dark", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Urias - Romanian giant guardian
    "URIAS": {
        "required_terms": ["giant", "romanian", "transylvania", "oltenia", "muntenia", "jidovi", "novaci", "carpathian", "mountains", "forest", "supernatural", "legendary", "mythological", "folklore", "ancient", "guardian", "protector", "defender", "nature", "earth", "land", "created by gods", "divine creation", "supernatural origin", "powerful", "strong", "mighty", "immense", "colossal", "towering", "benevolent", "kind", "helpful", "temperamental", "moody", "malevolent", "dangerous", "wrathful", "regional", "local legend"],
        "forbidden_terms": ["skeleton", "undead", "ghost", "spirit", "spectral", "ethereal", "incorporeal", "demonic", "infernal", "hellish", "abyssal", "angelic", "divine", "holy", "sacred", "blessed", "saint", "dragon", "serpent", "reptile", "scaled", "feathered", "winged"],
        "min_matches": MIN_MATCHES
    },

    # Uruk - Mesopotamian demon
    "URUK": {
        "required_terms": ["mesopotamian", "sumerian", "akkadian", "babylonian", "demon", "spirit", "evil", "malevolent", "underworld", "kur", "irkalla", "night", "darkness", "shadows", "chaos", "destruction", "death", "disease", "plague", "famine", "suffering", "pain", "anguish", "terrifying", "fearsome", "dreadful", "horrifying", "monstrous", "grotesque", "hideous", "animal features", "hybrid", "composite", "lion", "eagle", "snake", "scorpion", "winged", "horned", "clawed", "fanged"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Valkyrie - Norse warrior maiden
    "VALKYRIE": {
        "required_terms": ["norse", "warrior", "maiden", "winged", "horse", "fallen", "odin", "valkyrja", "valkyries", "norse mythology", "viking", "warrior maiden", "shield maiden", "battle maiden", "female warrior", "choose slain", "choose fallen", "select heroes", "choose worthy dead", "fallen warriors", "einherjar", "valhalla", "odin's hall", "winged", "feathered wings", "swan wings", "bird-like wings", "horse", "flying horse", "winged horse", "steed", "mount", "armor", "battle armor", "helmet", "shield", "spear", "sword", "beautiful", "fair", "radiant", "shining", "glorious", "majestic"],
        "forbidden_terms": ["evil", "demonic", "undead", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning"],
        "min_matches": MIN_MATCHES
    },

    # Vampire - Blood-drinking undead
    "VAMPIRE": {
        "required_terms": ["blood", "undead", "fangs", "night", "coffin", "bat", "immortal", "stake", "vampyre", "vampiric", "undead", "living dead", "risen dead", "returned dead", "revenant", "blood drinker", "blood sucker", "blood consumer", "hematophage", "fangs", "elongated canines", "sharp teeth", "piercing teeth", "night", "nocturnal", "darkness", "moonlight", "evening", "midnight", "coffin", "sarcophagus", "burial casket", "sleep in coffin", "bat", "bat form", "transform to bat", "bat shape", "immortal", "eternal", "undying", "ageless", "timeless", "stake through heart", "wooden stake", "vulnerability to stake", "garlic", "cross", "crucifix", "holy symbol", "holy water", "sunlight", "sunlight vulnerability", "sunlight burns", "sunlight destroys"],
        "forbidden_terms": ["living", "alive", "holy", "divine", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "good", "kind", "gentle", "soft", "tender", "caring"],
        "min_matches": MIN_MATCHES
    },

    # Vetala - Indian vampire
    "VETALA": {
        "required_terms": ["corpse", "possess", "animate", "hanging", "tree", "graveyard", "hindu", "indian", "baital", "pachisi", "vikram", "stories", "riddles", "wisdom", "corpse-dweller", "body-occupier", "flesh-inhabiter", "dead-host", "cremation ground", "burning ghat", "funeral pyre", "death site", "bat", "vampire bat", "nocturnal", "night-wanderer", "darkness-haunter", "upside-down", "inverted", "suspended", "dangling", "pendant"],
        "forbidden_terms": ["european", "western", "holy", "divine", "angelic", "blessed", "sacred", "church", "cathedral", "cross", "crucifix", "stake", "garlic", "sunlight"],
        "min_matches": MIN_MATCHES
    },

    # Vodyanoi - Slavic water spirit
    "VODYANOI": {
        "required_terms": ["water", "river", "lake", "pond", "slavic", "russian", "drown", "green", "beard", "mud", "algae", "weed", "frog", "fish", "catfish", "moss", "water mill", "mill wheel", "dam", "deep water", "whirlpool", "naked", "slimy", "slippery", "webbed", "paddle", "bubbles", "drowning victim", "underwater", "submerged", "watery grave"],
        "forbidden_terms": ["fire", "air", "earth", "mountain", "desert", "forest", "wood", "winged", "feathered", "furry", "hairy", "warm-blooded", "mammal"],
        "min_matches": MIN_MATCHES
    },

    # Void Wraith - Space ghost
    "VOID_WRAITH": {
        "required_terms": ["void", "space", "cosmic", "vacuum", "star", "galaxy", "nebula", "astral", "cold", "silence", "soundless", "airless", "zero-g", "floating", "dark matter", "black hole", "singularity", "event horizon", "astronaut", "spaceship", "derelict", "abandoned vessel", "star-crossed", "lost in space", "cosmic horror", "eldritch", "translucent", "faint", "twinkling", "starlight", "cosmic dust"],
        "forbidden_terms": ["light", "life", "living", "atmosphere", "breath", "oxygen", "warmth", "heat", "planet", "earth", "terrestrial", "ground", "soil"],
        "min_matches": MIN_MATCHES
    },

    # Warg - Evil wolf
    "WARG": {
        "required_terms": ["wolf", "dire", "oversized", "savage", "feral", "pack", "howl", "mount", "goblin wolf", "orc wolf", "fell beast", "carnivorous", "predator", "gray fur", "black fur", "shaggy", "mane", "glowing eyes", "snarl", "growl", "snap", "bite", "tear", "rend", "maul", "battle", "war", "bloodthirsty", "merciless", "cruel", "vicious"],
        "forbidden_terms": ["good", "friendly", "tame", "domestic", "loyal", "faithful", "companion", "pet", "guardian", "protector", "helpful", "gentle", "kind", "benevolent"],
        "min_matches": MIN_MATCHES
    },

    # Wendigo - Cannibal spirit
    "WENDIGO": {
        "required_terms": ["cannibal", "hunger", "starvation", "gaunt", "emaciated", "ice", "antlers", "algonquian", "native american", "great lakes", "forest", "winter", "insatiable", "consuming", "devouring", "gluttony", "greed", "transformation", "curse", "taboo", "forbidden", "sin", "ashen", "pale", "gray", "rotting", "decaying", "putrid", "heart of ice", "frozen heart", "cold blood", "no warmth"],
        "forbidden_terms": ["good", "kind", "benevolent", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous"],
        "min_matches": MIN_MATCHES
    },

    # Werewolf - Wolf shapeshifter
    "WEREWOLF": {
        "required_terms": ["wolf", "human", "hybrid", "transformation", "moon", "full moon", "lycanthrope", "bite", "curse", "infection", "affliction", "disease", "contagion", "howl", "pack", "hunt", "predator", "feral", "beast", "fur", "snout", "ears", "claws", "fangs", "tail", "hackles", "silver", "vulnerability", "weakness", "bane", "lethal", "moonlight", "night", "woods", "forest", "wilderness", "hunt"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Wight - Undead warrior
    "WIGHT": {
        "required_terms": ["barrow", "mound", "tumulus", "burial", "tomb", "cairn", "grave goods", "cold", "chill", "frost", "rime", "icy touch", "freezing", "ancient warrior", "old king", "forgotten lord", "restless dead", "treasure guardian", "mound-guardian", "hoard-watcher", "barrow-dweller", "corpse-candle", "ghost-light", "will-o-wisp", "haunt", "rusty sword", "cracked shield", "rotting mail", "crumbling armor"],
        "forbidden_terms": ["living", "alive", "flesh", "skin", "muscle", "tissue", "organ", "heart", "lung", "brain", "blood", "veins", "arteries", "circulatory", "respiratory"],
        "min_matches": MIN_MATCHES
    },

    # Will O Wisp - Ghostly light
    "WILL_O_WISP": {
        "required_terms": ["light", "flickering", "floating", "marsh", "swamp", "bog", "night", "will-o'-the-wisp", "jack-o'-lantern", "corpse candle", "fairy fire", "ghost light", "ignis fatuus", "foolish fire", "hinkypunk", "spooklight", "swamp gas", "methane", "phosphorescent", "glowing", "luminous", "hovering", "drifting", "floating", "mislead", "lead astray", "lure", "entice", "tempt", "dangerous", "deadly", "fatal", "folklore", "european", "celtic", "germanic"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living"],
        "min_matches": MIN_MATCHES
    },

    # Witch - Magic user
    "WITCH": {
        "required_terms": ["magic", "spell", "curse", "hex", "charm", "enchantment", "potion", "cauldron", "brew", "concoction", "mixture", "elixir", "philter", "broom", "besom", "broomstick", "flight", "fly", "soar", "familiar", "cat", "toad", "owl", "crow", "raven", "black cat", "sabbath", "coven", "gathering", "circle", "ritual", "ceremony", "pointed hat", "black robe", "cloak", "staff", "wand", "grimoire"],
        "forbidden_terms": ["divine", "holy", "angelic", "sacred", "blessed", "pure", "innocent", "virtuous", "righteous", "church", "temple", "priest", "nun", "monk"],
        "min_matches": MIN_MATCHES
    },

    # Wood Wose - Wild man
    "WOOD_WOSE": {
        "required_terms": ["wild man", "hairy", "shaggy", "unkempt", "naked", "primitive", "forest", "wood", "wilderness", "untamed", "savage", "feral", "club", "branch", "tree limb", "rock", "stone", "simple tool", "moss", "leaves", "vines", "foliage", "greenery", "natural", "elusive", "rare", "sighting", "glimpse", "rumor", "legend", "green man", "leafy", "bark-like", "woodland spirit", "nature being"],
        "forbidden_terms": ["civilized", "tame", "clothed", "refined", "cultured", "sophisticated", "educated", "learned", "wise", "intelligent", "cunning", "clever"],
        "min_matches": MIN_MATCHES
    },

    # Wraith - Ghost
    "WRAITH": {
        "required_terms": ["shadow", "darkness", "gloom", "tenebrous", "umbral", "hate", "malice", "spite", "vengeance", "wrath", "anger", "drain", "siphon", "consume", "devour", "feed", "hunger", "cold", "chill", "frost", "ice", "freezing", "numb", "ringwraith", "nazgul", "fell spirit", "dark rider", "soul", "spirit", "essence", "being", "entity", "presence"],
        "forbidden_terms": ["solid", "corporeal", "physical", "tangible", "palpable", "substantial", "material", "bodily", "fleshy", "fleshly", "flesh and blood", "living"],
        "min_matches": MIN_MATCHES
    },

    # Wyrm - Wingless dragon
    "WYRM": {
        "required_terms": ["serpent", "dragon", "wingless", "legless", "limbless", "elongated", "snake-like", "reptile", "scales", "scaly", "coiling", "constricting", "crushing", "poisonous", "venomous", "poison breath", "venomous breath", "burrow", "tunnel", "underground", "cave", "cavern", "lair", "treasure hoard", "gold", "gems", "ancient", "old", "primordial", "primitive", "bestial", "ferocious", "fearsome", "terrifying", "dreadful", "mythical", "legendary", "european", "norse", "germanic"],
        "forbidden_terms": ["wings", "winged", "feathered", "bird-like", "flying", "soaring", "gliding", "hovering", "airborne", "legs", "limbs", "feet", "claws", "talons"],
        "min_matches": MIN_MATCHES
    },

    # Wyvern - Two-legged dragon
    "WYVERN": {
        "required_terms": ["two legs", "bipedal", "hind legs", "no forelegs", "wings", "bat-like", "leathery", "membranous", "tail", "barbed", "spiked", "venomous", "poison", "raptor", "bird of prey", "eagle-like", "hawkish", "lesser dragon", "drake-kin", "pseudo-dragon", "heraldic", "medieval", "coat of arms", "emblem", "claws", "talons", "hind claws", "foot claws"],
        "forbidden_terms": ["four legs", "six legs", "eight legs", "many legs", "humanoid", "arms", "hands", "fingers", "speech", "language", "intelligent", "magical", "spellcasting", "arcane", "divine", "holy", "sacred"],
        "min_matches": MIN_MATCHES
    },

    # Xana - French fairy
    "XANA": {
        "required_terms": ["asturian", "spanish", "northern spain", "cantabrian", "iberian", "cave", "grotto", "cavern", "spring", "fountain", "well", "beautiful", "lovely", "fair", "radiant", "glowing", "shimmering", "golden hair", "long hair", "flowing locks", "tresses", "fairy", "fae", "faerie", "sprite", "nymph", "spirit", "mischievous", "playful", "trickster", "prankster", "elusive", "gift-giver", "reward", "blessing", "fortune", "luck"],
        "forbidden_terms": ["evil", "demonic", "ugly", "grotesque", "hideous", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal"],
        "min_matches": MIN_MATCHES
    },

    # Xanthus - Achilles' horse
    "XANTHUS": {
        "required_terms": ["achilles", "greek hero", "trojan war", "iliad", "homer", "epic", "immortal", "deathless", "divine", "god-born", "heavenly", "speak", "speech", "prophecy", "foretell", "predict", "warn", "tears", "weep", "mourn", "grief", "sorrow", "lament", "west wind", "zephyrus", "wind-born", "swift", "fleet", "fast", "chariot", "war chariot", "battle", "combat", "warrior steed"],
        "forbidden_terms": ["evil", "demonic", "ugly", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal"],
        "min_matches": MIN_MATCHES
    },

 # Xorn - Earth elemental
    "XORN": {
        "required_terms": ["three legs", "tripedal", "three arms", "trilateral", "triangular", "gem", "crystal", "mineral", "ore", "metal", "precious stone", "earth", "rock", "stone", "boulder", "clay", "soil", "dirt", "tunnel", "burrow", "swim through rock", "stone glide", "central eye", "top eye", "dome eye", "circular gaze", "hunger", "appetite", "consume", "devour", "digest", "absorb", "elemental plane", "inner plane", "earth plane", "geode"],
        "forbidden_terms": ["air", "water", "fire", "wind", "wave", "flame", "smoke", "steam", "mist", "fog", "vapor", "gas", "liquid", "fluid", "flowing", "fluid motion"],
        "min_matches": MIN_MATCHES
    },

    # Yale - Boar-goat hybrid
    "YALE": {
        "required_terms": ["boar", "pig", "swine", "porcine", "tusks", "snout", "goat", "caprine", "ibex", "beard", "cloven hooves", "swiveling horns", "rotating horns", "moveable horns", "adjustable", "spiral horns", "twisted horns", "curved horns", "tapered", "black", "dark", "ebony", "midnight", "shadowy", "heraldic", "coat of arms", "medieval bestiary", "emblem", "great size", "elephant-sized", "large", "massive", "colossal"],
        "forbidden_terms": ["reptile", "scales", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton"],
        "min_matches": MIN_MATCHES
    },

    # Yeth - English death hound
    "YETH": {
        "required_terms": ["yeth hound", "yeth dog", "wish hound", "english", "devon", "cornwall", "dog", "hound", "headless", "spectral", "ghostly", "spirit", "apparition", "phantom", "black", "dark", "shadowy", "glowing eyes", "red eyes", "fiery eyes", "night", "nocturnal", "darkness", "shadows", "howl", "howling", "silent", "noiseless", "soundless", "death omen", "harbinger", "foretell", "predict", "warn", "warning", "doom", "fate", "destiny", "folklore"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous"],
        "min_matches": MIN_MATCHES
    },

    # Yeti - Abominable snowman
    "YETI": {
        "required_terms": ["himalayas", "mountains", "nepal", "tibet", "bhutan", "asia", "snow", "ice", "glacier", "frozen", "alpine", "high altitude", "ape", "primate", "great ape", "hominid", "humanoid", "white fur", "shaggy", "thick coat", "insulated", "snow-white", "footprint", "track", "trace", "evidence", "sighting", "encounter", "elusive", "rare", "cryptid", "myth", "legend", "unknown", "yeti", "migoi", "meh-teh", "dzu-teh", "kang admi"],
        "forbidden_terms": ["desert", "hot", "tropical", "jungle", "rainforest", "equator", "south", "heat", "warm", "burning", "blazing", "scorching", "searing"],
        "min_matches": MIN_MATCHES
    },

    # Yokai - Japanese spirit
    "YOKAI": {
        "required_terms": ["japanese", "nippon", "shinto", "buddhist", "folk belief", "supernatural", "paranormal", "mysterious", "inexplicable", "shape-shifter", "transformer", "illusionist", "trickster", "animal form", "human form", "object form", "natural phenomenon", "mischief", "playful", "prank", "joke", "tease", "bother", "dangerous", "harmful", "scary", "fearsome", "terrifying", "ancient", "old", "traditional", "classical", "folkloric", "kitsune", "tanuki", "kappa", "tengu", "oni", "yurei"],
        "forbidden_terms": ["european", "western", "christian", "biblical", "greek", "norse", "celtic", "slavic", "egyptian", "mesopotamian", "persian"],
        "min_matches": MIN_MATCHES
    },

    # Zaratan - Giant sea turtle
    "ZARATAN": {
        "required_terms": ["turtle", "tortoise", "chelonia", "testudine", "reptile", "sea", "ocean", "marine", "saltwater", "deep sea", "abyssal", "island-sized", "island-like", "landmass", "floating island", "shell", "carapace", "plastron", "bony plates", "armored", "vegetation", "trees", "plants", "soil", "earth on back", "mistaken for land", "sailors land", "settle on back", "ancient", "primordial", "primeval", "first", "oldest"],
        "forbidden_terms": ["small", "bird", "feathered", "winged", "flying", "soaring", "gliding", "freshwater", "river", "lake", "pond", "stream", "brook"],
        "min_matches": MIN_MATCHES
    },

    # Ziburinis - Lithuanian death omen
    "ZIBURINIS": {
        "required_terms": ["skeleton", "bones", "ribcage", "skull", "phosphorescent", "glowing", "flickering", "wavering", "glimmer", "flame", "fire", "candle", "lantern", "forest", "woods", "wilderness", "remote", "isolated", "omen", "harbinger", "portent", "warning", "foretell", "death", "doom", "destruction", "calamity", "catastrophe", "lithuanian", "baltic", "pagan", "ancient", "folk belief", "vengeful", "malevolent", "wrathful"],
        "forbidden_terms": ["benevolent", "friendly", "protective", "guardian", "helpful", "angel", "holy", "sacred", "blessed", "salvation", "healing", "good luck", "fortune", "blessing", "daylight", "dawn", "sunrise", "joy", "celebration", "birth", "rebirth", "resurrection"],
        "min_matches": MIN_MATCHES
    },

    # Ziz - Giant bird
    "ZIZ": {
        "required_terms": ["bird", "avian", "raptor", "soarer", "flyer", "hebrew", "jewish", "judaic", "old testament", "biblical", "sky", "heavens", "firmament", "clouds", "atmosphere", "leviathan counterpart", "behemoth counterpart", "triad", "kosher", "clean bird", "mighty wings", "powerful flight", "blocks sun", "darkens sky", "shadow over land", "primordial", "creation", "genesis", "first creatures"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "mammal"],
        "min_matches": MIN_MATCHES
    },

    # Zmey - Slavic dragon
    "ZMEY": {
        "required_terms": ["slavic", "russian", "ukrainian", "polish", "czech", "serbian", "multiple heads", "three heads", "seven heads", "many heads", "fire-breathing", "flame", "inferno", "conflagration", "mountain", "cave", "cavern", "rocky lair", "cliff nest", "kidnap", "abduct", "carry off", "steal", "take", "maiden", "princess", "beautiful woman", "royal daughter", "bogatyr", "hero", "knight", "warrior", "champion", "winged", "serpentine", "draconic", "lizard-like", "scaly"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous"],
        "min_matches": MIN_MATCHES
    },

    # Zombie - Animated corpse
    "ZOMBIE": {
        "required_terms": ["corpse", "dead body", "cadaver", "remains", "rotting", "decaying", "putrid", "decomposing", "foul", "shamble", "lurch", "stagger", "stumble", "drag feet", "hunger", "craving", "appetite", "desire", "need", "flesh", "brains", "tissue", "organs", "viscera", "moan", "groan", "gurgle", "rasp", "gasp", "bite", "scratch", "claw", "grab", "clutch", "voodoo", "houngan", "bokor", "zombification", "powder"],
        "forbidden_terms": ["living", "alive", "intelligent", "wise", "cunning", "clever", "speech", "language", "communication", "thought", "reason", "logic", "emotion", "feeling", "compassion", "empathy", "sympathy", "love"],
        "min_matches": MIN_MATCHES
    },

    # Impundulu - South African lightning bird
    "IMPUNDULU": {
        "required_terms": ["lightning", "bird", "thunder", "storm", "south african", "zulu", "xhosa", "black and white", "raptor", "wings", "talons", "vampire", "blood", "immortal", "witch familiar", "witch doctor", "servant", "evil", "malevolent", "summon lightning", "strike with wings", "beautiful young man", "seductive", "human form", "shape-shift", "hyena rider", "bats", "firefly", "disease", "sickness", "death", "coughing blood", "tuberculosis", "outlives master", "passed down", "mother to daughter", "fearsome", "terrifying", "folklore", "african"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Dingonek - East African cryptid
    "DINGONEK": {
        "required_terms": ["cryptid", "african", "kenya", "congo", "tanzania", "river", "lake", "aquatic", "scaly", "scales", "pangolin-like", "mottled skin", "red", "gray", "spotted", "long tail", "tail dart", "poisonous", "venomous", "stinger", "scorpion tail", "saber-toothed", "saber canines", "walrus tusks", "long tusks", "curved tusks", "square head", "horn", "single horn", "reptilian claws", "large", "18 feet", "massive", "territorial", "aggressive", "dangerous", "kills hippos", "kills crocodiles", "attacks fishermen", "nests", "cave painting", "bushman", "rock art", "legendary", "mythical", "folklore"],
        "forbidden_terms": ["bird", "feathered", "winged", "flying", "soaring", "gliding", "hovering", "airborne", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young"],
        "min_matches": MIN_MATCHES
    },

    # Grootslang - South African elephant-serpent
    "GROOTSLANG": {
        "required_terms": ["giant", "serpent", "snake", "elephant", "hybrid", "african", "south african", "richtersveld", "cave", "bottomless pit", "wonder hole", "primordial", "ancient", "older than world", "created by gods", "too powerful", "split by gods", "escaped", "intelligent", "cunning", "strong", "massive", "40 feet", "50 feet", "15 meters", "diamonds", "eye sockets", "treasure", "hoard", "gold", "gems", "river", "pool", "waterfall", "augrabies", "guardian", "protector", "evil presence", "sense of evil", "khoikhoi", "bushmen", "folklore", "legendary", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Adze - West African vampire firefly
    "ADZE": {
        "required_terms": ["vampire", "firefly", "insect", "glowing", "light", "night", "nocturnal", "african", "west african", "ghana", "togo", "ewe", "shape-shift", "transformation", "human form", "beautiful", "alluring", "possess", "possession", "witch", "sorcerer", "sorceress", "evil", "malevolent", "blood", "blood-sucking", "keyhole", "crack", "under door", "closed door", "sleep", "victims", "sickness", "disease", "death", "jealousy", "envy", "poor", "rich", "old", "young", "family", "curse", "folklore", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Mapinguari - Amazonian giant sloth
    "MAPINGUARI": {
        "required_terms": ["amazon", "rainforest", "brazil", "bolivia", "south american", "cryptid", "giant", "sloth", "ground sloth", "megatherium", "mylodon", "prehistoric", "living fossil", "extinct", "surviving", "large", "6 feet", "2 meters", "bipedal", "stands upright", "long arms", "powerful claws", "tear palm trees", "red fur", "brown fur", "shaggy", "thick fur", "matted", "caiman skin", "alligator hide", "armored", "bulletproof", "one eye", "cyclops", "single eye", "second mouth", "belly mouth", "foul odor", "stench", "putrid", "fetid", "terrible smell", "loud shriek", "frightening roar", "nocturnal", "elusive", "rare", "avoids water", "folklore", "indigenous", "legend"],
        "forbidden_terms": ["bird", "feathered", "winged", "flying", "soaring", "gliding", "hovering", "airborne", "snake", "serpent", "reptile scales", "smooth skin", "hairless", "naked", "small", "tiny", "diminutive", "harmless", "gentle", "docile", "tame"],
        "min_matches": MIN_MATCHES
    },

    # Chonchón - Mapuche vampire bird
    "CHONCHON": {
        "required_terms": ["chile", "chilean", "argentina", "mapuche", "araucanian", "south american", "head", "human head", "severed head", "detached head", "flying head", "floating head", "ears", "enormous ears", "wing ears", "fly with ears", "feathers", "plumage", "gray", "ash-gray", "talons", "claws", "bird", "owl", "barn owl", "lechuza", "búho", "nocturnal", "night", "darkness", "moonless night", "cry", "call", "tue tue", "chue chue", "death omen", "harbinger", "foretell death", "announce death", "bad luck", "evil omen", "ill omen", "disease", "illness", "sick", "enfermo", "hover", "circle house", "enter home", "fight spirit", "suck blood", "vampire", "blood drinker", "kill sick", "cause death", "calcu", "kalku", "sorcerer", "witch", "brujo", "transformation", "magic ointment",
                           "unguent", "throat", "neck", "detach head", "body left behind", "wekufe", "evil spirit", "sin dios ni santa maría", "invocation", "spell", "curse", "reunion", "gathering", "aquelarre", "folklore", "legend", "mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "healing", "curative", "restorative", "therapeutic", "remedial", "day", "daylight", "sun", "sunlight", "morning", "noon", "afternoon"],
        "min_matches": MIN_MATCHES
    },

    # Harpy - Winged wind spirit
    "HARPY": {
        "required_terms": ["bird", "woman", "female", "winged", "claw", "talon", "greek", "wind", "screech", "harpyia", "snatcher", "storm spirit", "wind spirit", "bird-like", "avian", "feathered", "feathers", "wings", "beak", "talons", "claws", "sharp claws", "grasping claws", "snatching", "grabbing", "seizing", "ugly", "grotesque", "hideous", "foul", "filthy", "loathsome", "repulsive", "aello", "ocypete", "celaeno", "podarge", "hesiod", "virgil", "aeneid", "odyssey", "argonautica", "torment", "torture", "steal food", "defecate", "filth", "stench", "putrid smell", "fast", "swift", "aggressive", "violent", "cruel", "merciless"],
        "forbidden_terms": ["reptile", "scales", "fish", "aquatic", "fins", "gills", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "kind", "gentle", "benevolent", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "good"],
        "min_matches": MIN_MATCHES
    },

    # Hippogriff - Horse-eagle hybrid
    "HIPPOGRIFF": {
        "required_terms": ["horse", "eagle", "hybrid", "winged", "beak", "talon", "front", "back", "equine", "hippogryph", "hippogriffin", "horse-eagle", "eagle-horse", "eagle head", "eagle wings", "eagle forelegs", "horse body", "horse hindquarters", "majestic", "graceful", "noble", "beautiful", "swift", "fast", "agile", "flyer", "flier", "aerial", "airborne", "soaring", "gliding", "swooping", "ariosto", "orlando furioso", "ludovico", "medieval romance", "chivalry", "knight", "rider", "mount", "steed", "impossible love", "griffin father", "mare mother", "rare", "legendary", "mythical"],
        "forbidden_terms": ["lion", "snake", "scales", "reptile", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal"],
        "min_matches": MIN_MATCHES
    },

    # Eloko - Congolese dwarf bell spirits
    "ELOKO": {
        "required_terms": ["congo", "democratic republic of congo", "central african", "dwarf", "small", "tiny", "diminutive", "humanoid", "forest", "jungle", "wilderness", "bell", "ringing", "tinkling", "enchanted bell", "magic bell", "charm", "lure", "entice", "attract", "hunters", "travelers", "cannibal", "man-eater", "flesh eater", "devour", "consume", "invisible", "unseen", "hidden", "stealthy", "sneaky", "dangerous", "deadly", "lethal", "malevolent", "wicked", "evil", "nkundo", "mongo people", "folklore", "legend", "mythology", "spirit", "supernatural"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "healing"],
        "min_matches": MIN_MATCHES
    },

    # Ninki Nanka - West African dragon cryptid
    "NINKI_NANKA": {
        "required_terms": ["west african", "gambia", "senegal", "guinea", "dragon", "serpent", "reptile", "crocodile", "lizard", "giant", "enormous", "massive", "colossal", "long neck", "long tail", "spines", "spikes", "crest", "horns", "antelope-like", "horse-like head", "chameleon colors", "iridescent", "rainbow", "shiny", "glittering", "scales", "scaly", "armored", "swamp", "marsh", "bog", "river", "mangrove", "elusive", "rare", "sighting", "glimpse", "death omen", "bad luck", "curse", "poison", "toxic", "venomous", "breath", "fatal", "cryptid", "legendary", "mythical"],
        "forbidden_terms": ["bird", "feathered", "winged", "flying", "soaring", "gliding", "hovering", "airborne", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "good", "benevolent", "kind", "gentle"],
        "min_matches": MIN_MATCHES
    },

    # Kongamato - Zambian pterosaur cryptid
    "KONGAMATO": {
        "required_terms": ["zambia", "zimbabwe", "congo", "angola", "central african", "pterosaur", "pterodactyl", "prehistoric", "dinosaur", "reptile", "flying reptile", "winged", "leathery wings", "bat-like", "membranous wings", "wingspan", "large", "giant", "enormous", "massive", "beak", "toothed beak", "teeth", "sharp teeth", "long beak", "red", "reddish", "black", "dark", "scaly", "scales", "featherless", "smooth skin", "cave", "rocky outcrop", "river", "swamp", "marsh", "attack boats", "capsize canoes", "kill", "fatal", "dangerous", "aggressive", "territorial", "cryptid", "living fossil", "legendary", "mythical", "kaonde", "mwinilunga", "jiundu", "swamp"],
        "forbidden_terms": ["bird", "feathered", "feathers", "avian", "beak without teeth", "modern", "contemporary", "common", "ordinary", "normal", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young"],
        "min_matches": MIN_MATCHES
    },

    # Mokele-mbembe - Congolese dinosaur cryptid
    "MOKELE_MBEMBE": {
        "required_terms": ["congo", "central african", "sauropod", "dinosaur", "reptile", "giant", "enormous", "massive", "colossal", "long neck", "long tail", "small head", "four legs", "quadrupedal", "elephant-like", "hippopotamus-like", "gray", "brown", "reddish", "smooth skin", "hairless", "scales", "armored", "spines", "spikes", "herbivore", "plant-eater", "river", "lake", "tele", "likouala", "swamp", "marsh", "rainforest", "jungle", "water dweller", "aquatic", "elusive", "rare", "sighting", "glimpse", "cryptid", "living fossil", "legendary", "mythical", "pygmy", "baka", "bangombe", "folklore"],
        "forbidden_terms": ["bird", "feathered", "winged", "flying", "soaring", "gliding", "hovering", "airborne", "mammal", "fur", "hair", "wool", "hide", "pelt", "warm-blooded", "live birth", "nursing young", "carnivore", "meat-eater", "predator", "hunter"],
        "min_matches": MIN_MATCHES
    },

    # Popobawa - Zanzibar shapeshifting bat
    "POPOBAWA": {
        "required_terms": ["zanzibar", "tanzania", "east african", "bat", "winged", "leathery wings", "shapeshifter", "shape-shift", "transformation", "human form", "man", "attractive", "seductive", "lure", "entice", "tempt", "attack", "assault", "sexual assault", "night", "nocturnal", "darkness", "fearsome", "terrifying", "dreadful", "horrifying", "smell", "odor", "stench", "foul smell", "sulfur", "brimstone", "demon", "djinn", "sheitani", "spirit", "evil", "malevolent", "wicked", "vicious", "cruel", "violent", "aggressive", "panic", "mass hysteria", "epidemic", "outbreak", "folklore", "legend", "mythical", "cryptid"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "healing"],
        "min_matches": MIN_MATCHES
    },

    # Tokoloshe - Zulu water spirit
    "TOKOLOSHE": {
        "required_terms": ["zulu", "xhosa", "south african", "ndebele", "swazi", "water", "spirit", "dwarf", "small", "tiny", "diminutive", "humanoid", "hairy", "shaggy", "ugly", "grotesque", "hideous", "long arms", "long fingers", "large eyes", "glowing eyes", "red eyes", "green eyes", "bewitching gaze", "hypnotic", "mesmerizing", "magic", "sorcery", "witchcraft", "witch doctor", "sangoma", "inyanga", "summon", "control", "send", "attack", "torment", "harass", "bite", "suck blood", "vampire", "night", "nocturnal", "darkness", "shadows", "water", "river", "stream", "pool", "protect", "guard", "punish", "vengeful", "malevolent", "dangerous", "deadly", "lethal", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel"],
        "min_matches": MIN_MATCHES
    },

    # Each-Uisge - Scottish water horse
    "EACH_UISGE": {
        "required_terms": ["scottish", "highlands", "water", "horse", "kelpie", "each uisge", "each-uisge", "eachuisge", "water horse", "lake", "loch", "sea", "ocean", "salt water", "seaweed", "kelp", "beautiful horse", "magnificent steed", "lure", "entice", "tempt", "attract", "riders", "victims", "mount", "jump on", "sticky skin", "adhesive skin", "cannot dismount", "gallop", "rush", "drown", "drowning", "devour", "eat", "consume", "organs", "liver", "heart", "entrails", "more dangerous than kelpie", "deadly", "lethal", "fatal", "malevolent", "wicked", "evil", "nocturnal", "night", "shapeshifter", "human form", "handsome man", "beautiful woman", "folklore", "celtic", "gaelic"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "freshwater only", "pond", "stream", "brook"],
        "min_matches": MIN_MATCHES
    },

    # Bean-Nighe - Scottish washerwoman spirit
    "BEAN_NIGHE": {
        "required_terms": ["scottish", "highlands", "washerwoman", "spirit", "fairy", "fae", "banshee", "bean nighe", "bean-nighe", "bean nighte", "little washerwoman", "washing", "laundry", "stream", "river", "ford", "bloody clothes", "shroud", "death omen", "harbinger", "foretell", "predict", "warn", "impending death", "dying person", "clothes", "garments", "battle", "war", "massacre", "pale", "green", "webbed feet", "web feet", "one nostril", "single nostril", "one eye", "single eye", "large teeth", "protruding teeth", "long breasts", "throw over shoulder", "wash", "scrub", "beat", "lament", "keen", "mourn", "prophecy", "ask three questions", "answer truthfully", "folklore", "celtic", "gaelic"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "helpful", "joyful", "happy", "celebration", "birth", "rebirth", "resurrection", "life", "living", "alive"],
        "min_matches": MIN_MATCHES
    },

    # Baobhan Sith - Scottish vampire fairy
    "BAOBHAN_SITH": {
        "required_terms": ["scottish", "highlands", "vampire", "fairy", "fae", "baobhan sith", "baobhan-sith", "banshee", "beautiful woman", "fair maiden", "lovely", "radiant", "glowing", "alluring", "enticing", "tempting", "seductive", "green dress", "white dress", "long hair", "golden hair", "red hair", "night", "nocturnal", "darkness", "moonlight", "hunters", "travelers", "men", "lure", "entice", "tempt", "attract", "dance", "invite to dance", "embrace", "kiss", "bite", "fangs", "drain blood", "blood drinker", "blood sucker", "hematophage", "victim", "corpse", "dead", "die", "dawn", "sunlight", "vulnerability", "iron", "cold iron", "ward off", "protect", "circle", "folklore", "celtic", "gaelic"],
        "forbidden_terms": ["ugly", "hideous", "grotesque", "repulsive", "fearsome appearance", "monstrous", "deformed", "malformed", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Nix/Nixe - Germanic water spirit
    "NIX": {
        "required_terms": ["germanic", "german", "teutonic", "water", "spirit", "nix", "nixe", "nixie", "nixy", "nixie", "male", "female", "beautiful", "alluring", "enticing", "tempting", "seductive", "river", "stream", "lake", "pond", "pool", "waterfall", "deep water", "whirlpool", "drown", "drowning", "lure", "entice", "tempt", "attract", "victims", "children", "fishermen", "sailors", "musician", "fiddle", "harp", "music", "song", "enchanting melody", "beautiful voice", "human form", "green hair", "wet hair", "webbed fingers", "webbed toes", "fish tail", "merge", "shape-shift", "shapeshifter", "prophecy", "foretell", "predict", "warn", "folklore", "mythology", "legend"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "demon", "demonic", "infernal", "hellish", "abyssal"],
        "min_matches": MIN_MATCHES
    },

    # Perchta - Alpine female spirit
    "PERCHTA": {
        "required_terms": ["alpine", "austrian", "bavarian", "german", "swiss", "tyrolean", "female", "spirit", "goddess", "perchta", "berchta", "percht", "white lady", "bright", "radiant", "beautiful", "kind", "benevolent", "generous", "gift", "reward", "good children", "hard workers", "spinners", "weavers", "twelfth night", "epiphany", "christmas", "winter", "snow", "ice", "cold", "mountain", "forest", "wilderness", "dual nature", "two forms", "old hag", "ugly", "grotesque", "hideous", "wrinkled", "hooked nose", "warts", "tattered clothes", "punish", "vengeful", "cruel", "wicked", "evil", "bad children", "lazy", "slothful", "disobedient", "cut open belly", "stuff with straw", "rocks", "garbage", "folklore", "mythology"],
        "forbidden_terms": ["single nature", "only good", "only evil", "consistent", "unchanging", "monochrome", "simple", "uncomplicated", "straightforward", "one-dimensional", "flat", "shallow"],
        "min_matches": MIN_MATCHES
    },

    # Krampus - Austrian Christmas demon
    "KRAMPUS": {
        "required_terms": ["austrian", "bavarian", "alpine", "german", "swiss", "christmas", "st nicholas", "saint nicholas", "december 5", "krampusnacht", "night", "demon", "devil", "horned", "horns", "curved horns", "goat-like", "caprine", "shaggy", "black fur", "dark fur", "brown fur", "chains", "clanking chains", "bells", "ringing bells", "birch branches", "switch", "rod", "whip", "bundle of sticks", "punish", "beat", "switch bad children", "wicked", "naughty", "disobedient", "basket", "sack", "burlap sack", "carry off", "abduct", "kidnap", "take away", "devour", "eat", "consume", "children", "victims", "fearsome", "terrifying", "dreadful", "horrifying", "grotesque", "hideous", "ugly", "long tongue", "fangs", "sharp teeth", "cloven hooves", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "rewards", "presents", "gifts", "treats", "candy", "sweets", "toys", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Frau Holle - Germanic goddess/witch
    "FRAU_HOLLE": {
        "required_terms": ["german", "germanic", "teutonic", "goddess", "witch", "spirit", "female", "woman", "frau holle", "holda", "holle", "perchta", "winter", "snow", "ice", "cold", "make snow", "shake feather bed", "feathers", "snowflakes", "clouds", "sky", "heavens", "mountain", "well", "spring", "water", "protector", "guardian", "children", "spinners", "weavers", "hard workers", "reward", "gift", "gold", "treasure", "prosperity", "fortune", "luck", "punish", "lazy", "slothful", "disobedient", "unkind", "dark", "shadow", "hag", "crone", "old woman", "wrinkled", "bent", "hunched", "staff", "cauldron", "magic", "enchantment", "spell", "curse", "blessing", "folklore", "mythology", "grimms fairy tales", "brothers grimm"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "demon", "demonic", "infernal", "hellish", "abyssal"],
        "min_matches": MIN_MATCHES
    },

    # Tengu - Japanese bird-like mountain spirit
    "TENGU": {
        "required_terms": ["japanese", "shinto", "mountain", "forest", "spirit", "bird", "avian", "wings", "feathered", "feathers", "beak", "long nose", "red face", "red skin", "humanoid", "mountain man", "yamabushi", "monk", "ascetic", "priest", "cloak", "robes", "sandals", "staff", "magic fan", "feather fan", "wind", "storm", "create wind", "cause storms", "mischievous", "trickster", "prankster", "playful", "dangerous", "malevolent", "vengeful", "proud", "arrogant", "teach", "instruct", "martial arts", "swordsmanship", "strategy", "tactics", "ninja", "warrior", "guardian", "protector", "mountain temple", "shrine", "folklore", "mythology", "karasu tengu", "crow tengu", "konoha tengu", "daitengu", "kotengu"],
        "forbidden_terms": ["european", "western", "christian", "biblical", "greek", "norse", "celtic", "slavic", "egyptian", "mesopotamian", "persian", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "sympathetic", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed"],
        "min_matches": MIN_MATCHES
    },

    # Yuki-onna - Japanese snow woman
    "YUKI_ONNA": {
        "required_terms": ["japanese", "snow", "winter", "cold", "ice", "frost", "blizzard", "storm", "night", "moonlight", "woman", "female", "spirit", "yōkai", "beautiful", "pale", "white", "pale skin", "white kimono", "long hair", "black hair", "blue lips", "ghostly", "ethereal", "translucent", "fading", "no feet", "floating", "hovering", "silent", "quiet", "noiseless", "lure", "entice", "tempt", "attract", "travelers", "hikers", "mountains", "pass", "path", "trail", "ask for help", "carry baby", "lullaby", "sing", "voice", "beautiful voice", "breathe on victim", "frost breath", "freeze", "kill", "drain life", "suck life force", "vampire", "blood", "soul", "spirit", "dangerous", "deadly", "lethal", "fatal", "folklore", "mythology", "legend"],
        "forbidden_terms": ["warm", "hot", "summer", "spring", "autumn", "heat", "burning", "blazing", "scorching", "searing", "fire", "flame", "lava", "magma", "volcano", "tropical", "desert", "arid", "dry", "good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "helpful", "selfless", "altruistic"],
        "min_matches": MIN_MATCHES
    },

    # Jorogumo - Japanese spider woman
    "JOROGUMO": {
        "required_terms": ["japanese", "spider", "woman", "female", "shape-shifter", "shapeshifter", "transformation", "spider form", "giant spider", "enormous spider", "human form", "beautiful woman", "alluring", "enticing", "tempting", "seductive", "courtesan", "prostitute", "geisha", "lure", "entice", "tempt", "attract", "men", "samurai", "travelers", "house", "teahouse", "brothel", "inn", "lodging", "music", "string instrument", "biwa", "shamisen", "harp", "song", "voice", "enchanting", "mesmerizing", "hypnotic", "web", "spider web", "silk thread", "bind", "trap", "capture", "victim", "paralyze", "poison", "venom", "venomous bite", "eat", "consume", "devour", "folklore", "mythology", "yōkai"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Nukekubi - Japanese detachable head vampire
    "NUKEKUBI": {
        "required_terms": ["japanese", "vampire", "undead", "yōkai", "head", "detachable head", "separate head", "flying head", "floating head", "neck", "severed neck", "red line", "red ring", "red marks", "neck marks", "human body", "sleeping body", "body asleep", "head flies", "head detaches at night", "nocturnal", "night", "darkness", "moonlight", "hunt", "search", "prey", "victims", "blood", "suck blood", "blood drinker", "drain blood", "lifeforce", "energy", "evil", "malevolent", "wicked", "dangerous", "deadly", "lethal", "fatal", "attack", "kill", "destroy", "hidden", "disguised", "appear normal", "daytime", "detect", "exposed", "move body", "hide body", "folklore", "mythology", "legend"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Rokurokubi - Japanese stretching neck spirit
    "ROKUROKUBI": {
        "required_terms": ["japanese", "yōkai", "spirit", "human", "humanoid", "appear normal", "normal by day", "daytime", "ordinary", "common", "unremarkable", "night", "nocturnal", "darkness", "midnight", "transform", "change", "neck", "stretch", "elongate", "extend", "long neck", "very long neck", "impossibly long", "flexible neck", "stretch neck", "reach", "look around", "spy", "eavesdrop", "peek", "watch", "observe", "listen", "hear", "secrets", "private moments", "mischief", "prank", "trick", "playful", "mischievous", "malevolent", "evil", "wicked", "scare", "frighten", "terrify", "horrify", "folklore", "mythology", "legend"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Bakemono - General Japanese shapeshifter
    "BAKEMONO": {
        "required_terms": ["japanese", "yōkai", "spirit", "demon", "shape-shifter", "shapeshifter", "transformer", "change form", "transformation", "animal form", "human form", "object form", "plant form", "supernatural", "paranormal", "mysterious", "inexplicable", "strange", "bizarre", "weird", "odd", "peculiar", "unnatural", "monstrous", "grotesque", "hideous", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "mischievous", "trickster", "prankster", "playful", "dangerous", "harmful", "malevolent", "wicked", "evil", "folklore", "mythology", "legend", "folktale", "tradition", "ancient", "old", "classical", "pre-modern", "traditional"],
        "forbidden_terms": ["european", "western", "christian", "biblical", "greek", "norse", "celtic", "slavic", "egyptian", "mesopotamian", "persian", "normal", "ordinary", "common", "typical", "average", "usual", "standard", "regular", "everyday", "mundane"],
        "min_matches": MIN_MATCHES
    },

    # Huli Jing - Chinese fox spirit
    "HULI_JING": {
        "required_terms": ["chinese", "fox", "spirit", "fox spirit", "nine-tailed", "multiple tails", "tails", "wisdom", "intelligence", "knowledge", "long life", "immortal", "immortality", "shape-shifter", "shapeshifter", "transformation", "human form", "beautiful woman", "beautiful man", "seductive", "alluring", "enticing", "tempting", "lure", "entice", "tempt", "attract", "marry", "relationship", "union", "couple", "life force", "energy", "qi", "chi", "drain", "suck", "absorb", "vampire", "vampiric", "dangerous", "harmful", "malevolent", "wicked", "evil", "benevolent", "kind", "good", "helpful", "protector", "guardian", "blessing", "curse", "dual nature", "folklore", "mythology", "legend", "chinese mythology", "daoist", "taoist"],
        "forbidden_terms": ["japanese", "korean", "vietnamese", "western", "european", "christian", "biblical", "greek", "norse", "celtic", "slavic", "egyptian", "mesopotamian", "persian", "single nature", "only good", "only evil", "consistent", "unchanging"],
        "min_matches": MIN_MATCHES
    },

    # Jiangshi - Chinese hopping vampire
    "JIANGSHI": {
        "required_terms": ["chinese", "vampire", "undead", "hopping", "jumping", "rigid", "stiff", "corpse", "dead body", "reanimated", "risen dead", "zombie", "rotting", "decaying", "putrid", "foul", "green skin", "white skin", "pale", "glowing eyes", "green eyes", "red eyes", "long arms", "stiff arms", "outstretched arms", "fangs", "sharp teeth", "long nails", "claws", "talisman", "paper talisman", "yellow paper", "seal", "forehead", "priest", "taoist priest", "daoshi", "exorcism", "exorcist", "qi", "chi", "life force", "energy", "drain", "suck", "absorb", "vampire", "vampiric", "night", "nocturnal", "darkness", "moonlight", "avoid", "sunlight", "daylight", "mirror", "reflection", "rice", "salt", "vinegar", "folklore", "mythology", "legend", "chinese mythology"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Aswang - Filipino shapeshifting monster
    "ASWANG": {
        "required_terms": ["filipino", "philippines", "visayan", "tagalog", "mythology", "shape-shifter", "shapeshifter", "transformer", "vampire", "ghoul", "witch", "monster", "night", "nocturnal", "darkness", "moonlight", "shadow", "hide", "conceal", "lurk", "human form", "animal form", "dog", "cat", "pig", "bird", "crow", "bat", "lizard", "beautiful by day", "normal by day", "ordinary", "common", "unremarkable", "night form", "monstrous", "grotesque", "hideous", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "long tongue", "proboscis", "needle-like", "sharp", "piercing", "suck blood", "drain blood", "blood drinker", "hematophage", "eat flesh", "devour flesh", "consume organs", "liver", "heart", "entrails", "corpse", "dead", "funeral", "grave", "tomb", "pregnant women",
                           "unborn child", "fetus", "baby", "infant", "victim", "prey", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Manananggal - Filipino detachable torso vampire
    "MANANANGGAL": {
        "required_terms": ["filipino", "philippines", "visayan", "tagalog", "vampire", "monster", "detachable", "separate", "upper body", "torso", "fly", "flying", "wings", "bat-like wings", "leathery wings", "membranous wings", "night", "nocturnal", "darkness", "moonlight", "midnight", "pregnant women", "unborn child", "fetus", "baby", "infant", "long tongue", "proboscis", "needle-like", "sharp", "piercing", "suck blood", "drain blood", "suck fetus", "devour", "consume", "eat", "victim", "prey", "lower body", "legs", "feet", "left behind", "hide", "conceal", "salt", "ash", "garlic", "vinegar", "discover", "find", "destroy", "kill", "return", "cannot reattach", "die", "perish", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "day", "daylight", "sun", "sunlight", "morning", "noon", "afternoon"],
        "min_matches": MIN_MATCHES
    },

    # Penanggalan - Malaysian detachable head vampire
    "PENANGGALAN": {
        "required_terms": ["malaysian", "malay", "indonesian", "southeast asian", "vampire", "demon", "spirit", "female", "woman", "beautiful woman", "attractive", "alluring", "seductive", "enticing", "tempting", "normal by day", "ordinary", "common", "unremarkable", "night", "nocturnal", "darkness", "moonlight", "midnight", "head", "detach", "separate", "flying head", "floating head", "neck", "entrails", "intestines", "organs", "dangling", "trailing", "glowing", "bioluminescent", "glowing entrails", "vinegar", "soak", "preserve", "compress", "shrink", "fit back", "body", "torso", "left behind", "hide", "conceal", "pregnant women", "unborn child", "fetus", "baby", "infant", "birth", "mother", "suck blood", "drain blood", "suck fetus", "devour", "consume", "eat", "victim", "prey",
                           "sharp teeth", "fangs", "long tongue", "thorny", "spiky", "spines", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "day", "daylight", "sun", "sunlight", "morning", "noon", "afternoon"],
        "min_matches": MIN_MATCHES
    },

    # Pukwudgie - Wampanoag trickster dwarf
    "PUKWUDGIE": {
        "required_terms": ["wampanoag", "native american", "algonquian", "massachusetts", "new england", "northeastern", "dwarf", "small", "tiny", "diminutive", "humanoid", "trickster", "mischievous", "prankster", "playful", "dangerous", "harmful", "malevolent", "wicked", "evil", "magic", "magical", "supernatural", "spirit", "invisible", "unseen", "hidden", "shape-shifter", "shapeshifter", "transformer", "porcupine", "quills", "shoot quills", "poison", "venom", "poisonous", "venomous", "fog", "mist", "create fog", "confuse", "disorient", "lead astray", "lure", "entice", "tempt", "attack", "kill", "deadly", "lethal", "fatal", "forest", "woods", "wilderness", "remote", "isolated", "folklore", "legend", "mythical", "hobbomock", "maushop"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic"],
        "min_matches": MIN_MATCHES
    },

    # Skinwalker - Navajo witch
    "SKINWALKER": {
        "required_terms": ["navajo", "diné", "native american", "southwest", "arizona", "new mexico", "utah", "colorado", "witch", "sorcerer", "shapeshifter", "transformer", "animal form", "coyote", "wolf", "bear", "fox", "owl", "crow", "raven", "bird", "predator", "evil", "malevolent", "wicked", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "curse", "hex", "spell", "magic", "dark magic", "forbidden", "taboo", "taboo breaker", "wear animal skin", "animal pelt", "transform", "change shape", "run fast", "jump far", "climb walls", "ceilings", "enter home", "night", "nocturnal", "darkness", "shadows", "glowing eyes", "red eyes", "yellow eyes", "attack", "kill", "torture", "torment", "possess", "control", "nightmare", "terror", "fear",
                           "dread", "horror", "skinwalker ranch", "folklore", "legend", "mythical", "sacred", "secret", "private", "do not speak", "do not name"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "day", "daylight", "sun", "sunlight"],
        "min_matches": MIN_MATCHES
    },

    # Hodag - Wisconsin lumberjack cryptid
    "HODAG": {
        "required_terms": ["wisconsin", "rhinelander", "midwest", "lumberjack", "logger", "timber", "forest", "woods", "logging camp", "cryptid", "monster", "fearsome", "terrifying", "dreadful", "horrifying", "grotesque", "hideous", "ugly", "large", "big", "giant", "bull head", "ox head", "horns", "large horns", "curved horns", "spikes", "spines", "back", "dinosaur-like", "reptilian", "scales", "scaly", "armored", "thick hide", "tough skin", "long tail", "powerful tail", "claws", "sharp claws", "talons", "fangs", "sharp teeth", "glowing eyes", "red eyes", "green eyes", "green", "black", "brown", "dark", "carnivore", "meat-eater", "predator", "hunter", "attack", "kill", "destroy", "livestock", "cattle", "sheep", "goat", "chicken", "farm animal", "hoax", "prank", "joke", "tall tale", "folklore",
                           "legend", "mythical", "gene shepard", "1903", "discovery", "capture", "display", "showman", "promoter", "publicity", "stunt"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "real", "genuine", "authentic", "actual", "true", "verified", "confirmed", "proven"],
        "min_matches": MIN_MATCHES
    },

    # Sasquatch - Pacific Northwest hominid
    "SASQUATCH": {
        "required_terms": ["pacific northwest", "washington", "oregon", "california", "british columbia", "canada", "united states", "cryptid", "bigfoot", "hominid", "primate", "ape", "great ape", "humanoid", "giant", "large", "enormous", "massive", "tall", "7 feet", "8 feet", "9 feet", "10 feet", "hairy", "shaggy", "thick fur", "dark fur", "brown fur", "black fur", "reddish fur", "muscular", "powerful", "strong", "broad shoulders", "long arms", "bipedal", "walks upright", "footprint", "track", "trace", "impression", "large footprint", "15 inches", "16 inches", "20 inches", "sasquatch", "bigfoot", "skookum", "omah", "forest", "woods", "wilderness", "remote", "isolated", "mountain", "valley", "wooded area", "elusive", "rare", "sighting", "glimpse", "encounter", "eyewitness", "report",
                           "evidence", "photograph", "video", "film", "patterson film", "1967", "bluff creek", "folklore", "legend", "mythical", "cryptozoology", "cryptozoological", "unknown", "unidentified", "mysterious", "enigmatic"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "dangerous", "deadly", "lethal", "fatal"],
        "min_matches": MIN_MATCHES
    },

    # Bunyip - Australian cryptid
    "BUNYIP": {
        "required_terms": ["australian", "australia", "aboriginal", "indigenous", "cryptid", "water", "spirit", "monster", "swamp", "marsh", "bog", "billabong", "waterhole", "river", "creek", "lake", "night", "nocturnal", "darkness", "drown", "drowning", "attack", "kill", "devour", "eat", "consume", "victims", "women", "children", "travelers", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "large", "big", "giant", "enormous", "massive", "colossal", "variable appearance", "many descriptions", "seal-like", "dog-like", "horse-like", "cow-like", "flippers", "flippers", "tusks", "large tusks", "walrus tusks", "long neck", "mane", "shaggy mane", "feathers", "feathery", "scales", "scaly", "fur", "hairy", "shaggy", "slippery", "slimy", "roar", "bellow", "growl", "loud cry",
                           "terrible cry", "blood-curdling", "haunting", "echo", "folklore", "legend", "mythical", "dreamtime", "dreaming", "creation story", "guardian", "protector", "punish", "wrongdoers", "taboo", "forbidden"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tenderoug", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "day", "daylight", "sun", "sunlight", "morning", "noon", "afternoon"],
        "min_matches": MIN_MATCHES
    },

    # Yowie - Australian Bigfoot
    "YOWIE": {
        "required_terms": ["australian", "australia", "cryptid", "bigfoot", "sasquatch", "hominid", "primate", "ape", "great ape", "humanoid", "giant", "large", "enormous", "massive", "tall", "7 feet", "8 feet", "9 feet", "10 feet", "hairy", "shaggy", "thick fur", "dark fur", "brown fur", "black fur", "reddish fur", "muscular", "powerful", "strong", "broad shoulders", "long arms", "bipedal", "walks upright", "footprint", "track", "trace", "impression", "large footprint", "forest", "woods", "wilderness", "bush", "outback", "remote", "isolated", "mountain", "valley", "wooded area", "rainforest", "elusive", "rare", "sighting", "glimpse", "encounter", "eyewitness", "report", "evidence", "photograph", "video", "film", "aboriginal", "indigenous", "dreamtime", "dreaming", "spirit",
                           "supernatural", "magical", "dangerous", "harmful", "attack", "kill", "victim", "prey", "folklore", "legend", "mythical", "cryptozoology", "cryptozoological", "unknown", "unidentified", "mysterious", "enigmatic"],
        "forbidden_terms": ["reptile", "scales", "snake", "lizard", "crocodile", "turtle", "tortoise", "amphibian", "frog", "toad", "bird", "feathered", "beak", "talons", "fish", "aquatic", "fins", "gills", "insect", "arachnid", "chitin", "exoskeleton", "evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "deadly", "lethal", "fatal"],
        "min_matches": MIN_MATCHES
    },

    # Tiddalik - Australian frog spirit
    "TIDDALIK": {
        "required_terms": ["australian", "australia", "aboriginal", "indigenous", "dreamtime", "dreaming", "creation story", "mythology", "legend", "frog", "giant frog", "enormous frog", "massive frog", "amphibian", "water", "thirst", "drink", "drank all water", "drank everything", "all fresh water", "rivers", "creeks", "streams", "billabongs", "waterholes", "lakes", "ponds", "swamps", "drought", "dry", "arid", "parched", "thirsty", "animals", "creatures", "suffering", "dying", "thirst", "water", "no water", "laugh", "make laugh", "tickle", "joke", "prank", "trick", "entertain", "amuse", "mirth", "joy", "laughter", "happy", "merry", "cheerful", "release water", "spill water", "water returns", "flood", "restore", "revive", "life", "living", "survival", "cooperation", "teamwork", "together",
                           "community", "lesson", "moral", "teaching", "story", "tale", "folktale"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "demon", "demonic", "infernal", "hellish", "abyssal"],
        "min_matches": MIN_MATCHES
    },

    # Mimi - Australian slender rock spirits
    "MIMI": {
        "required_terms": ["australian", "australia", "aboriginal", "indigenous", "arnhem land", "northern territory", "rock", "spirit", "supernatural", "slender", "thin", "elongated", "willowy", "fragile", "delicate", "graceful", "elegant", "tall", "very tall", "thin limbs", "long arms", "long legs", "long fingers", "rock painting", "rock art", "cave painting", "ancient", "old", "primordial", "first people", "creation time", "dreamtime", "dreaming", "wind", "breezy day", "windy", "breeze", "blow away", "disappear", "vanish", "fragile in wind", "need shelter", "cave", "rock shelter", "cliff", "escarpment", "rocky outcrop", "hunter", "gatherer", "hunting", "gathering", "food", "bush tucker", "teach", "instruct", "guide", "show", "demonstrate", "first hunters", "first gatherers",
                           "knowledge", "wisdom", "tradition", "culture", "ancestral", "ancestor", "spirit being", "folklore", "legend", "mythical"],
        "forbidden_terms": ["evil", "malevolent", "wicked", "sinister", "malicious", "cruel", "violent", "aggressive", "harmful", "dangerous", "deadly", "lethal", "fatal", "poisonous", "venomous", "corrosive", "acidic", "burning", "demon", "demonic", "infernal", "hellish", "abyssal"],
        "min_matches": MIN_MATCHES
    },

    # Sphinx - Greek winged lion with woman's head
    "SPHINX": {
        "required_terms": ["greek", "egyptian", "mythology", "legendary", "winged", "lion", "woman", "female", "human head", "woman's head", "female head", "breasts", "eagle wings", "feathered wings", "bird wings", "serpent tail", "snake tail", "riddle", "question", "puzzle", "enigma", "challenge", "answer", "solve", "correct answer", "wrong answer", "devour", "eat", "consume", "kill", "strangle", "throttle", "sphinx", "greek sphinx", "thebes", "boeotian", "phix", "oidipous", "oedipus", "three heads", "lion head", "goat head", "snake head", "variant", "composite", "hybrid", "monstrous", "fearsome", "terrifying", "dreadful", "horrifying", "guardian", "protector", "temple", "tomb", "gate", "entrance", "portal", "statue", "sculpture", "carving", "monumental", "stone", "marble", "granite"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "simple", "easy", "trivial", "insignificant", "minor", "unimportant"],
        "min_matches": MIN_MATCHES
    },

    # Empusa - Greek shapeshifting demon
    "EMPUSA": {
        "required_terms": ["greek", "mythology", "demon", "specter", "spirit", "female", "woman", "shapeshifter", "transformer", "shape-shift", "transform", "change form", "beautiful woman", "alluring", "enticing", "tempting", "seductive", "lure", "entice", "tempt", "attract", "men", "travelers", "victims", "ugly", "grotesque", "hideous", "monstrous", "one leg", "single leg", "one foot", "single foot", "bronze leg", "bronze foot", "donkey leg", "ass leg", "mule leg", "animal leg", "claw", "talon", "clawed foot", "fiery hair", "flaming hair", "burning hair", "fire hair", "night", "nocturnal", "darkness", "moonlight", "crossroads", "highway", "road", "path", "attack", "kill", "devour", "eat", "consume", "flesh", "blood", "victim", "prey", "hecate", "hecate's servant", "hecate's attendant",
                           "underworld", "hades", "tartarus", "folklore", "legend", "mythical"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "two legs", "two feet", "both legs same", "symmetrical", "balanced", "normal", "ordinary", "common"],
        "min_matches": MIN_MATCHES
    },

    # Mormolyce - Greek female demon
    "MORMOLYCE": {
        "required_terms": ["greek", "mythology", "demon", "spirit", "female", "woman", "mormo", "mormolyke", "mormolykeion", "fearsome", "terrifying", "dreadful", "horrifying", "horrific", "frightening", "scary", "monstrous", "grotesque", "hideous", "ugly", "child-eater", "eats children", "devour children", "consume children", "threaten children", "scare children", "frighten children", "night", "nocturnal", "darkness", "shadows", "lurk", "hide", "conceal", "underworld", "hades", "tartarus", "hecate", "hecate's retinue", "hecate's attendant", "companion", "follower", "servant", "lesser demon", "minor demon", "spirit", "specter", "apparition", "phantom", "ghost", "wraith", "shade", "folklore", "legend", "mythical", "nursery tale", "children's story", "cautionary tale", "warning", "threat",
                           "danger", "harm", "injury", "death", "dying", "dead"],
        "forbidden_terms": ["good", "benevolent", "kind", "gentle", "soft", "tender", "caring", "compassionate", "empathetic", "sympathetic", "helpful", "selfless", "altruistic", "charitable", "giving", "pure", "innocent", "virtuous", "righteous", "holy", "divine", "sacred", "blessed", "angel", "angelic", "loving", "nurturing", "protective", "guardian", "savior", "rescuer", "redeemer"],
        "min_matches": MIN_MATCHES
    },

}
# Creature-specific validation patterns