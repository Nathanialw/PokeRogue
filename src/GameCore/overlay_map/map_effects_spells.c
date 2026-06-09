//
// Created by nathanial on 5/19/26.
//
#include "map_effects_spells.h"

#include "lib_memory.h"
#include "types.h"

#include "core_effects.h"

#include "map_player.h"
#include "map_ram.h"
#include "map_camera.h"
#include "map_effects.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapNoAttack_PLACEHOLDER(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool PlaceholderSpell(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    if (caster_id == NO_ENTITY) return false;
    HealTarget(caster_id, spellData.power);
    return true;
}


// no interaction effect for lava, water, acid or pits

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapLevitate(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Hover(caster_id, spellData.power);
    return true;
}

// teleport to random empty cell on the map

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return Reposition(hardware, caster_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WaterWalking(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapWaterBreathing(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WaterBreathing(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(caster_id, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapResurrect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Revive(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRaiseDead(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return GoNextLevel(MAP_LEVEL_DOWN);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapFlameEater(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    FireEating(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapPortal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // uint8_t n = hardware.GetRandom_uint8_t(1, 3);
    // if (n == 1)
    //     MapDescend(hardware, memory, caster_id);
    // else if (n == 2)
    //     MapAscend(hardware, memory, caster_id);
    // else
    //     MapLateral(hardware, memory, caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapBrewPotion(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRepel(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Repel(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCapture(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Capture(hardware, target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCurePoison(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemovePoison(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCureDisease(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveDisease(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCureCurse(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveCurse(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    CreateItemFood();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCreateCommon(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapFireball(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Attack(caster_id, target_id, spellData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapIceBolt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRazorGrass(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapMudSling(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCreateMagicItem(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    CreateItemCommon();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapAwaken(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveSleep(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapNerveRepair(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapBlindingLight(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapSoothe(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveFear(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapFear(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyFear(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHaste(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyHaste(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapSlow(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplySlow(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHypothermia(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyFrozen(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapBurnHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveBurn(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapFocus(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseAccuracy(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRage(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseStrength(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapOpenChest(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapIncreaseBag(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapGlowingEmbers(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    StatusLesserLight(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapBrillianceAura(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    StatusGreaterLight(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapReflect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapSilence(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapPowerOverwhelming(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    MakeInvulnerable(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapShadows(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Invisibility(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapEmpower(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapDefend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseDefence(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapWizen2(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHasten(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyHaste(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapStrengthen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseStrength(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapFortify(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseDefence(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapWizen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapGrowMuscle(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseSpeed(caster_id);
    return true;
}


/**********************************************************************************************************************/
/* removes the dark black fog of the map
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapClairvoyance(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveMapFog();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapWallWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WallWalking(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCreatePit(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Position pos = GetSelectedTile(hardware, true);
    // MapModifyTile(pos, PIT);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapXRayVision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    XRayVision(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRainStorm(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapDrought(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapCrusade(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapHunt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapPurification(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastMapRaiseSkeleton(EntityId attackerID, EntityId defenderID, SkillData abilityData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}
