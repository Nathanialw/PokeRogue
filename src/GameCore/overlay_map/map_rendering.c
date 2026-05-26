//
// Created by nathanial on 4/11/26.
//
#include "map_rendering.h"

#include "lib_types.h"
#include "lib_decl.h"
#include "lib_memory.h"

#include "core_map.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_utils.h"

#include "map_camera.h"
#include "map_graphics.h"
#include "map_ram.h"


SET_MEMORY(".map")
bool CheckVision(uint8_t x, uint8_t y)
{
    return g_map.view.vision[y][x];
}

SET_MEMORY(".map")
bool CheckVisionMap(uint8_t x, uint8_t y)
{
    Camera c = GetCamera();
    if (GetPlayerEffects(P_EFFECTS_MAP_VISION_CREATURES)) return true;
    if (x < c.x || x > c.x + VIEW_TW || y < c.y || y > c.y + VIEW_TH) return false;
    return g_map.view.vision[y - c.y][x - c.x];
}


SET_MEMORY(".map")
bool CheckFogCleared(uint8_t x, uint8_t y)
{
    return g_core.fog[y][x];
}


SET_MEMORY(".map")
void UpdateVision(GraphicsInterface graphics, HardwareInterface hardware)
{
    uint8_t vision_radius = 5;
    Camera c = GetCamera();

    for (uint8_t i = 0; i < VIEW_TH; i++)
    {
        for (uint8_t j = 0; j < VIEW_TW; j++)
        {
            if (j > CAM_OFFSET_X - vision_radius && i > CAM_OFFSET_Y - vision_radius && i < CAM_OFFSET_Y + vision_radius && j < CAM_OFFSET_X + vision_radius)
            {
                g_map.view.vision[i][j] = 1;
                g_core.fog[c.y + i][c.x + j] = 1;
            }
            else
            {
                graphics.FillRect(j * TILE_W, i * TILE_H, TILE_W, TILE_H, (Color){.color = 0x0000});
            }
        }
    }
}

/**********************************************************************************************************************/
/**  sorts units into the order they are drawn into the partial frame buffer for the minimap
**********************************************************************************************************************/
SET_MEMORY(".map")
void OrderUnitsByBufferLine(GraphicsInterface graphics, EntityId* units, uint8_t* meta)
{
    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        units[id] = NO_ENTITY;
        meta[id] = 0;
    }

    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        if (!GetBit(g_core.creatures.onMap, id)) continue;
        Position pos = g_core.creatures.position[id];
        uint8_t row = pos.y / BUFFER_W;

        uint16_t cursor = 0;
        for (uint8_t i = 0; i <= row; i++)
            cursor += meta[i];

        EntityId cache1 = units[cursor];
        units[cursor] = id;
        meta[row]++;

        for (uint16_t i = cursor + 1; i < MAX_ENTITY_CREATURE_COUNT; i++)
        {
            if (cache1 == NO_ENTITY) break;
            EntityId cache2 = units[i];
            units[i] = cache1;
            cache1 = cache2;
        }
    }
}

/**********************************************************************************************************************/
/**  Draws each tile as a pixel on the screen
 *  colour coded
 *  draws creature position pixels on top of their tile position
**********************************************************************************************************************/
SET_MEMORY(".map.rodata")
static const uint8_t colors[16] =
{
    PAL_PEACH_SKIN,
    PAL_MEDIUM_BROWN,
    PAL_PALE_GREEN,
    PAL_GRAYISH_GREEN,
    PAL_DIRTY_YELLOW_GRN,
    PAL_BROWNISH_RED,
    PAL_LIGHT_TAN,
    PAL_GRAY_BLUE,
    PAL_DULL_ORANGE,
    PAL_DARK_BROWN,
    PAL_MUTED_GREEN,
    PAL_DARK_GRAY_GREEN,
    PAL_ICE_BLUE,
    PAL_LIGHT_GRAY,
    PAL_TAN_BROWN,
    PAL_BRIGHT_LIGHT_GRN,
};

void DrawMinimapEntities(GraphicsInterface graphics, MemoryInterface memory, Position* positions, uint16_t y, uint8_t palette_color)
{
    // DRAW CREATURES
    uint16_t start_pos = (TFT_W - MAP_W) >> 1;
    uint16_t margins = TFT_W - MAP_W;
    uint16_t cursor = 0;
    Color enemy_color = Flash_GetColor(memory, palette_color);

    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        Position pos = positions[id];
        if (!CheckVisionMap(pos.x, pos.y))
            continue;

        uint8_t row = pos.y - y;
        Color color = enemy_color;

        cursor = start_pos + (row * margins) + (row * MAP_W) + pos.x;
        graphics.GetFrameBuffer2bytes()[cursor] = color.color;
    }
}

/**********************************************************************************************************************/
/**  Redraws all map tiles and entities ion the camera view to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawMiniMap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    uint8_t buffer_lines = TFT_H / BUFFER_H;

    OrderUnitsByBufferLine(graphics, g_map.units, g_map.meta);
    Camera c = GetCamera();

    uint16_t cursor = 0;
    Color transparency = Flash_GetColor(memory, PAL_KEY);
    for (uint16_t y = 0; y < MAP_H; y += BUFFER_H)
    {
        graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_OFF_WHITE_GRAY));

        cursor = (TFT_W - MAP_W) >> 1; //reset position
        for (uint16_t row = 0; row < BUFFER_H; row++)
        {
            uint16_t cy = y + row;
            if (cy >= MAP_H) break;
            Color color;
            for (uint16_t x = 0; x < MAP_W; x++)
            {
                if (!CheckFogCleared(x, cy))
                    color.color = 0x0000;
                else
                {
                    color = Flash_GetColor(memory, colors[GetMapTile(x, cy)]);
                    if (cy < c.y || cy >= c.y + VIEW_TH || x < c.x || x >= c.x + VIEW_TW)
                    {
                        color.r = (color.r >> 1);
                        color.g = (color.g >> 1);
                        color.b = (color.b >> 1);
                    }
                }
                if (color.color == transparency.color) continue;
                graphics.GetFrameBuffer2bytes()[cursor++] = color.color;
            }
            cursor += (TFT_W - MAP_W);
        }

        DrawMinimapEntities(graphics, memory, g_core.creatures.position, y, PAL_BRIGHT_RED);
        DrawMinimapEntities(graphics, memory, g_core.items.position, y, PAL_BRIGHT_VINE_GRN);
        DrawMinimapEntities(graphics, memory, g_core.objects.position, y, PAL_DARK_BROWN);
        DrawMinimapEntities(graphics, memory, g_core.trainers.position, y, PAL_DARK_BLUE_GRAY);

        graphics.Draw(0, y, TFT_W, BUFFER_H, graphics.GetFrameBuffer1byte());
    }
}

/**********************************************************************************************************************/
/**  Redraws all map tiles and entities ion the camera view to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void FullRedraw(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    Camera cam = GetCamera();
    UpdateVision(graphics, hardware);

    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
    {
        uint16_t my = cam.y + sy;
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
        {
            uint16_t mx = cam.x + sx;
            uint16_t id = GetMapTile(mx, my);
            if (CheckVision(sx, sy))
            {
                //Draw normal
                DrawTile(graphics, memory, sx, sy, id, 15);
                g_map.view.viewTiles[sy][sx] = id;
            }
            else if (CheckFogCleared(cam.x + sx, cam.y + sy))
            {
                //draw darkened
                DrawTile(graphics, memory, sx, sy, id, -50);
                g_map.view.viewTiles[sy][sx] = id;
            }
        }
    }

    for (uint16_t i = 0; i < g_core.items.total; i++)
    {
        if (g_core.items.types[i] == NO_ITEM) continue;

        uint8_t x = g_core.items.position[i].x;
        uint8_t y = g_core.items.position[i].y;
        if (GetBit(g_core.items.onMap, i) && CameraContains(x, y))
        {
            uint8_t rx = (x - cam.x);
            uint8_t ry = (y - cam.y);
            if (!CheckVision(rx, ry)) continue;
            DrawSprite(graphics, memory, rx, ry, g_core.items.types[i], ITEM);
            g_map.view.viewItems.viewEntities[ry][rx] = g_core.items.types[i];
        }
    }

    for (uint16_t i = 0; i < g_core.objects.total; i++)
    {
        if (g_core.objects.types[i] == NO_OBJECT) continue;

        uint8_t x = g_core.objects.position[i].x;
        uint8_t y = g_core.objects.position[i].y;
        if (GetBit(g_core.objects.onMap, i) && CameraContains(x, y))
        {
            uint8_t rx = (x - cam.x);
            uint8_t ry = (y - cam.y);
            if (!CheckVision(rx, ry)) continue;
            DrawSprite(graphics, memory, rx, ry, g_core.objects.types[i], OBJECT);
            g_map.view.viewObjects.viewEntities[ry][rx] = g_core.objects.types[i];
        }
    }

    for (uint16_t i = 0; i < g_core.creatures.total; i++)
    {
        if (g_core.creatures.types[i] == NO_CREATURE) continue;

        uint8_t x = g_core.creatures.position[i].x;
        uint8_t y = g_core.creatures.position[i].y;
        if (GetBit(g_core.creatures.onMap, i) && CameraContains(x, y))
        {
            uint8_t rx = (x - cam.x);
            uint8_t ry = (y - cam.y);
            if (!CheckVision(rx, ry)) continue;
            DrawSprite(graphics, memory, rx, ry, g_core.creatures.types[i], CREATURE);
            g_map.view.viewCreatures.viewEntities[ry][rx] = g_core.creatures.types[i];
        }
    }

    for (uint16_t i = 0; i < g_core.trainers.total; i++)
    {
        if (g_core.trainers.types[i] == NO_TRAINER) continue;

        uint8_t x = g_core.trainers.position[i].x;
        uint8_t y = g_core.trainers.position[i].y;
        if (GetBit(g_core.trainers.onMap, i) && CameraContains(x, y))
        {
            uint8_t rx = (x - cam.x);
            uint8_t ry = (y - cam.y);
            if (!CheckVision(rx, ry)) continue;
            DrawSprite(graphics, memory, rx, ry, g_core.trainers.types[i], TRAINER);
            g_map.view.viewTrainers.viewEntities[ry][rx] = g_core.trainers.types[i];
        }
    }
}


/**********************************************************************************************************************/
/** Clears the dirtyTiles array to false
 * Clears the newSprites array to NO_CREATURE
**********************************************************************************************************************/
SET_MEMORY(".map")
void ResetRenders(ViewEntities* view, uint8_t count)
{
    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
            view->newSprites[sy][sx] = count;
}

/**********************************************************************************************************************/
/** Checks whether the tiles on the newTiles array has changed
 * Save changes as dirty bool in the dirtyTiles array
**********************************************************************************************************************/
SET_MEMORY(".map")
void CheckForTileChanges(Camera cam)
{
    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
    {
        uint16_t my = cam.y + sy;
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
        {
            uint16_t mx = cam.x + sx;
            uint8_t tile = GetMapTile(mx, my);
            if (g_map.view.viewTiles[sy][sx] != tile)
                SetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx, true);

            g_map.view.viewTiles[sy][sx] = tile; //cache
        }
    }
}

/**********************************************************************************************************************/
/**  Retrieves all entities in the camera view
 *  Saves their types into newSprites array at the reletive tile position
**********************************************************************************************************************/
SET_MEMORY(".map")
void GetEntitiesInView(Camera cam, BitFieldUint8* onMap, ViewEntities* view, Position* pos, const uint8_t* types, uint8_t count)
{
    for (uint16_t id = 0; id < count; id++)
    {
        if (GetBit(*onMap, id))
        {
            uint8_t x = pos[id].x;
            uint8_t y = pos[id].y;
            if (CameraContains(x, y))
            {
                uint8_t sx = (x - cam.x);
                uint8_t sy = (y - cam.y);
                if (!g_map.view.vision[sy][sx]) continue;
                view->newSprites[sy][sx] = types[id];
            }
        }
    }
}

/**********************************************************************************************************************/
/** Checks whether the sprites in the viewObjects array has changed
 * Save changes as dirty bool in the dirtyTiles array
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetDirty(ViewEntities* view)
{
    for (uint8_t sy = 0; sy < VIEW_TH; sy++)
    {
        for (uint8_t sx = 0; sx < VIEW_TW; sx++)
        {
            if (view->viewEntities[sy][sx] != view->newSprites[sy][sx])
                SetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx, true);

            view->viewEntities[sy][sx] = view->newSprites[sy][sx]; //cache
        }
    }
}

/**********************************************************************************************************************/
/**  Redraws only the dirty map tiles to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void ReDrawTiles(GraphicsInterface graphics, MemoryInterface memory, Camera cam)
{
    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
    {
        uint16_t my = cam.y + sy;
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
        {
            uint16_t mx = cam.x + sx;
            uint16_t id = GetMapTile(mx, my);

            // DrawTileCached(graphics, memory, sx, sy, map_id);

            if (CheckVision(sx, sy))
            {
                if (!GetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx) || !g_map.view.vision[sy][sx])
                    continue;
                //Draw normal
                DrawTile(graphics, memory, sx, sy, id, 15);
                g_map.view.viewTiles[sy][sx] = id;
            }
            else if (CheckFogCleared(cam.x + sx, cam.y + sy))
            {
                //draw darkened
                DrawTile(graphics, memory, sx, sy, id, -50);
                g_map.view.viewTiles[sy][sx] = id;
            }
        }
    }
}

/**********************************************************************************************************************/
/**     Redraws only the dirty map sprites to the screen
 *      Objects then Items then Creatures
**********************************************************************************************************************/
SET_MEMORY(".map")
void ReDrawSprites(GraphicsInterface graphics, MemoryInterface memory)
{
    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
    {
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
        {
            if (!GetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx))
                continue;

            if (g_map.view.viewItems.viewEntities[sy][sx] != NO_ITEM)
            {
                uint8_t item_type = g_map.view.viewItems.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, item_type, ITEM);
            }

            if (g_map.view.viewObjects.viewEntities[sy][sx] != NO_OBJECT)
            {
                uint8_t object_type = g_map.view.viewObjects.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, object_type, OBJECT);\
            }

            if (g_map.view.viewCreatures.viewEntities[sy][sx] != NO_CREATURE)
            {
                uint8_t creature_type = g_map.view.viewCreatures.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, creature_type, CREATURE);
            }

            if (g_map.view.viewTrainers.viewEntities[sy][sx] != NO_TRAINER)
            {
                uint8_t trainer_type = g_map.view.viewTrainers.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, trainer_type, TRAINER);
            }
        }
    }
}


/**********************************************************************************************************************/
/**  Routine that runs the dirty tile update
 *  Handles the alternate smooth scrolling animation mode as well
**********************************************************************************************************************/
SET_MEMORY(".map")
void RenderObjects(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    UpdateVision(graphics, hardware);
    // if (g_core.btns.gameSpeed < 5)
    // AnimationMovement(graphics, hardware, memory);

    for (uint8_t i = 0; i < (VIEW_TH * VIEW_TW) >> 3; i++)
        g_map.view.dirtyTiles[i] = 0;


    ResetRenders(&g_map.view.viewItems, NO_ITEM);
    ResetRenders(&g_map.view.viewObjects, NO_OBJECT);
    ResetRenders(&g_map.view.viewCreatures, NO_CREATURE);
    ResetRenders(&g_map.view.viewTrainers, NO_TRAINER);


    Camera cam = GetCamera();
    if (g_core.btns.gameSpeed >= 5)
        CheckForTileChanges(cam);

    GetEntitiesInView(cam, &g_core.items.onMap, &g_map.view.viewItems, g_core.items.position, g_core.items.types, g_core.items.total);
    GetEntitiesInView(cam, &g_core.objects.onMap, &g_map.view.viewObjects, g_core.objects.position, g_core.objects.types, g_core.objects.total);
    GetEntitiesInView(cam, &g_core.creatures.onMap, &g_map.view.viewCreatures, g_core.creatures.position, g_core.creatures.types, g_core.creatures.total);
    GetEntitiesInView(cam, &g_core.trainers.onMap, &g_map.view.viewTrainers, g_core.trainers.position, g_core.trainers.types, g_core.trainers.total);

    SetDirty(&g_map.view.viewItems);
    SetDirty(&g_map.view.viewObjects);
    SetDirty(&g_map.view.viewCreatures);
    SetDirty(&g_map.view.viewTrainers);

    if (g_map.clearTooltip)
    {
        g_map.clearTooltip = false;
        for (uint16_t i = (VIEW_TW * VIEW_TH) - VIEW_TW; i < VIEW_TW * VIEW_TH; i++)
            SetBit(g_map.view.dirtyTiles, i, true);
    }

    ReDrawTiles(graphics, memory, cam);
    ReDrawSprites(graphics, memory);
}
