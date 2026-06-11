//
// Created by nathanial on 5/19/26.
//
#include "lib_memory.h"
#include "types.h"

#include "core_effects.h"
#include "core_ram.h"
#include "core_stats.h"
#include "lib_debugging.h"

#include "map_player.h"
#include "map_camera.h"
#include "map_effects.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapNoAttack_PLACEHOLDER(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome PlaceholderSpell(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


// Heal selected Creature

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
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
ActionOutcome CastMapLevitate(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Hover(caster_id, spellData.power);
    return true;
}

// teleport to random empty cell on the map

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapDisplacement(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return Reposition(hardware, caster_id);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapWaterWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WaterWalking(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapWaterBreathing(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WaterBreathing(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapTeleport(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Position random_tile_pos = GetSelectedTile(hardware, true);
    // Reposition(caster_id, random_tile_pos);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapResurrect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Revive(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRaiseDead(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return GoNextLevel(MAP_LEVEL_DOWN);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapFlameEater(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    FireEating(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapPortal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
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
ActionOutcome CastMapBrewPotion(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRepel(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Repel(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCapture(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    if (Capture(hardware, caster_id, target_id, spellData.power))
    {
        return true;
    }
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCurePoison(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemovePoison(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCureDisease(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveDisease(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCureCurse(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveCurse(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCreateFood(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    uint8_t x = g_core.creatures.position[caster_id].x;
    uint8_t y = g_core.creatures.position[caster_id].y;
    uint8_t l = 1;
    return CreateItemCommon(hardware, memory, ITEM, x, y, l);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCreateCommon(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    uint8_t x = g_core.creatures.position[caster_id].x;
    uint8_t y = g_core.creatures.position[caster_id].y;
    uint8_t l = 1;
    return CreateItemCommon(hardware, memory, ITEM, x, y, l);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapFireball(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Attack(caster_id, target_id, spellData);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapIceBolt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRazorGrass(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapMudSling(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCreateMagicItem(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    uint8_t x = g_core.creatures.position[caster_id].x;
    uint8_t y = g_core.creatures.position[caster_id].y;
    uint8_t l = 1;
    return CreateItemCommon(hardware, memory, ITEM, x, y, l);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapAwaken(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveSleep(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapNerveRepair(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapBlindingLight(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapSoothe(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveFear(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapFear(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyFear(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHaste(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyHaste(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapSlow(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplySlow(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHypervision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHypothermia(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyFrozen(target_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapBurnHeal(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveBurn(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapFocus(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseAccuracy(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRage(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseStrength(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapOpenChest(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    DEBUG("CastMapOpenChest Faileod to open chest");
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapIncreaseBag(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // TODO: temorary increase bag slots, add field for onlt the player
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapGlowingEmbers(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    StatusLesserLight(caster_id, spellData.power);
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapBrillianceAura(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    StatusGreaterLight(caster_id, spellData.power);
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapReflect(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapSilence(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapPowerOverwhelming(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    MakeInvulnerable(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapShadows(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    Invisibility(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapEmpower(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapDefend(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseDefence(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapWizen2(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHasten(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    ApplyHaste(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapStrengthen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseStrength(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapFortify(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseDefence(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapWizen(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseMagic(caster_id);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapGrowMuscle(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RaiseSpeed(caster_id);
    return true;
}


/**********************************************************************************************************************/
/* removes the dark black fog of the map
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapClairvoyance(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    RemoveMapFog();
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapWallWalking(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    WallWalking(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCreatePit(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // Position pos = GetSelectedTile(hardware, true);
    // MapModifyTile(pos, PIT);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapXRayVision(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    XRayVision(caster_id, spellData.power);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRainStorm(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against FLAME for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHeatWave(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against ICE for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapDrought(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    //increases efficacy of attacks against WATER for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapCrusade(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against DEMONS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapHunt(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against BEASTS for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapPurification(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // increases efficacy of attacks against TOXIC for a duration
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRaiseSkeleton(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    // TileHasCorpse(GetPlayerPosition());
    // Summon(SKELETON);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastMapRaiseXP(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    if (target_id == NO_ENTITY) return ACTION_CANNOT;
    GainXP(target_id, spellData.power);
    return ACTION_SUCCEEDED;
}
