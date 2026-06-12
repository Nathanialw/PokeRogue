//
// Created by nathanial on 4/11/26.
//
#include "map_rendering.h"

#include <stdlib.h>

#include "lib_types.h"
#include "lib_decl.h"
#include "lib_memory.h"

#include "core_map.h"
#include "core_memory_access.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_utils.h"

#include "map_camera.h"
#include "map_entities.h"
#include "map_graphics.h"
#include "map_ram.h"


void ReDrawTiles(GraphicsInterface graphics, MemoryInterface memory, Camera cam);


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


/*  filter the objects that are light emitting in the view area
 *  take in each object and calculate the tiles they illuminate
 */
SET_MEMORY(".map")
bool LineOfSightClear(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1)
    {
        // Stop *before* the destination tile (the check is done on the caller side)
        if (x0 == x1 && y0 == y1) break;

        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }

        uint8_t tile = GetMapTile(x0, y0);
        if (tile == WALL_STONE)
            return false;
    }
    return true;
}

// Traces a ray from (x0,y0) towards (x1,y1), marking all passed tiles as visible
// Stops when a wall is encountered (the wall tile itself is also marked)
SET_MEMORY(".map")
void MarkVisibilityRay(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, Camera c)
{
    int dx = abs((int)x1 - (int)x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs((int)y1 - (int)y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    uint8_t cx = x0, cy = y0; // current tile being walked

    while (1)
    {
        // Mark the current tile as visible (screen coordinates)
        int16_t sx_screen = (int16_t)cx - (int16_t)c.x;
        int16_t sy_screen = (int16_t)cy - (int16_t)c.y;
        if (sx_screen >= 0 && sx_screen < VIEW_TW &&
            sy_screen >= 0 && sy_screen < VIEW_TH)
        {
            g_map.view.vision[sy_screen][sx_screen] = 1;
        }
        // Permanently reveal it
        g_core.fog[cy][cx] = 1;

        // Stop if we've reached the target tile
        if (cx == x1 && cy == y1)
            break;

        // Walk one step
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            cx += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            cy += sy;
        }


        // Check the *new* tile for a wall
        uint8_t tile = GetMapTile(cx, cy);
        if (tile == WALL_STONE)
        {
            // Mark this wall tile as visible, then stop
            sx_screen = (int16_t)cx - (int16_t)c.x;
            sy_screen = (int16_t)cy - (int16_t)c.y;
            if (sx_screen >= 0 && sx_screen < VIEW_TW &&
                sy_screen >= 0 && sy_screen < VIEW_TH)
            {
                g_map.view.vision[sy_screen][sx_screen] = 1;
            }
            g_core.fog[cy][cx] = 1;
            if (!g_core.creatures.status.lineOfSight[GetPlayerID()])
                break; // vision ends here
        }
    }
}

SET_MEMORY(".map")
void UpdateVision(GraphicsInterface graphics)
{
    (void)graphics;

    const uint8_t vision_radius = g_core.player.vision_radius;
    const uint32_t R4 = (uint32_t)vision_radius * vision_radius * vision_radius * vision_radius;
    Camera c = GetCamera();

    // Clear the viewport vision array (y, x order)
    for (uint8_t y = 0; y < VIEW_TH; y++)
        for (uint8_t x = 0; x < VIEW_TW; x++)
            g_map.view.vision[y][x] = 0;

    uint8_t player_x = c.x + CAM_OFFSET_X;
    uint8_t player_y = c.y + CAM_OFFSET_Y;

    // Player's own tile
    g_map.view.vision[CAM_OFFSET_Y][CAM_OFFSET_X] = 1;
    g_core.fog[player_y][player_x] = 1;


    // Try to see every tile inside the rounded square
    for (int8_t dy = -vision_radius; dy <= vision_radius; dy++)
    {
        int32_t dy4 = (int32_t)dy * dy * dy * dy;
        for (int8_t dx = -vision_radius; dx <= vision_radius; dx++)
        {
            int32_t dx4 = (int32_t)dx * dx * dx * dx;
            if (dx4 + dy4 > R4) continue;

            int16_t mx = (int16_t)player_x + dx;
            int16_t my = (int16_t)player_y + dy;

            if (mx < 0 || my < 0 || mx >= MAP_W || my >= MAP_H)
                continue;

            // This call will mark every tile along the ray, including any wall that blocks it
            MarkVisibilityRay(player_x, player_y, (uint8_t)mx, (uint8_t)my, c);
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

#define MM_SCALE (SCREEN_W / MAP_W)

SET_MEMORY(".map")
void DrawMinimapEntities(GraphicsInterface graphics, MemoryInterface memory, ObjectsTypes type, uint16_t y, uint8_t palette_color)
{
    // DRAW CREATURES
    uint16_t start_pos = (SCREEN_W * MM_SCALE);
    Color enemy_color = Flash_GetColor(memory, palette_color);

    uint8_t* onMap = GetEntitiesOnMap(type);
    Position* positions = GetEntityPositions(type);

    for (uint16_t entity_id = 0; entity_id < MAX_ENTITY_CREATURE_COUNT; entity_id++)
    {
        if (!GetBit(onMap, entity_id))
            continue;

        Position pos = positions[entity_id];
        if (!CheckVisionMap(pos.x, pos.y))
            continue;

        Color color = enemy_color;
        uint32_t screen_y = pos.y * MM_SCALE * SCREEN_W;
        uint32_t screen_x = pos.x * MM_SCALE;
        uint32_t margin = (SCREEN_W - (MAP_W * MM_SCALE)) >> 1;

        uint32_t cursor = start_pos + screen_y + screen_x + margin;

        for (uint8_t i = 0; i < MM_SCALE; i++)
        {
            for (uint8_t j = 0; j < MM_SCALE; j++)
                graphics.GetFrameBuffer2bytes()[cursor++] = color.color;
            cursor += (SCREEN_W - MM_SCALE);
        }
    }
}

/**********************************************************************************************************************/
/**  Redraws all map tiles and entities in the camera view to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void DrawMiniMap(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    OrderUnitsByBufferLine(graphics, g_map.units, g_map.meta);
    Camera c = GetCamera();

    uint32_t cursor = (SCREEN_W * MM_SCALE);
    Color transparency = Flash_GetColor(memory, PAL_KEY);

    for (uint32_t y = 0; y < MAP_H; y += BUFFER_H)
    {
        graphics.SetFrameBuffer(Flash_GetColor(memory, PAL_BROWNISH_RED));

        cursor += (SCREEN_W - (MAP_W * MM_SCALE)) >> 1; //reset position
        for (uint32_t row = 0; row < BUFFER_H; row++)
        {
            for (uint16_t j = 0; j < MM_SCALE; j++)
            {
                uint16_t cy = y + row;
                if (cy >= MAP_H) break;
                Color color;
                for (uint32_t x = 0; x < MAP_W; x++)
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

                    for (uint8_t i = 0; i < MM_SCALE; i++)
                        graphics.GetFrameBuffer2bytes()[cursor++] = color.color;
                }
                cursor += (SCREEN_W - (MAP_W * MM_SCALE));
            }
        }

        DrawMinimapEntities(graphics, memory, CREATURE, y, PAL_BRIGHT_RED);
        DrawMinimapEntities(graphics, memory, ITEM, y, PAL_BRIGHT_VINE_GRN);
        DrawMinimapEntities(graphics, memory, OBJECT, y, PAL_DARK_BROWN);
        DrawMinimapEntities(graphics, memory, TRAINER, y, PAL_DARK_BLU_PURP);

        Rect_16 render_rect = {0, y, SCREEN_W, BUFFER_H};
        graphics.Draw16(NULL, &render_rect, graphics.GetFrameBuffer2bytes());
    }
}

/**********************************************************************************************************************/
/**  Redraws all map tiles and entities ion the camera view to the screen
**********************************************************************************************************************/
SET_MEMORY(".map")
void FullRedraw(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    Camera cam = GetCamera();
    UpdateVision(graphics);

    ReDrawTiles(graphics, memory, cam);

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
/** TODO: full redraw is fine for noe, but eventually chage to only the player cell
**********************************************************************************************************************/
SET_MEMORY(".map")
void RedrawPlayerCell(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory)
{
    FullRedraw(graphics, hardware, memory);
}


/**********************************************************************************************************************/
/** Clears the dirtyTiles array to false
 * Clears the newSprites array to NO_CREATURE
**********************************************************************************************************************/
SET_MEMORY(".map")
void ResetRenders(ViewEntities* view, uint8_t no_entity)
{
    for (uint16_t sy = 0; sy < VIEW_TH; sy++)
        for (uint16_t sx = 0; sx < VIEW_TW; sx++)
            view->newSprites[sy][sx] = no_entity;
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
                // if (!GetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx))
                // continue;
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
            else
            {
                graphics.FillRect(sx * MAP_TILE_W, sy * MAP_TILE_H, MAP_TILE_W, MAP_TILE_H, Flash_GetColor(memory, PAL_BLACK));
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
            // if (!GetBit(g_map.view.dirtyTiles, (sy * VIEW_TH) + sx))
            // continue;

\
            if (g_map.view.viewObjects.viewEntities[sy][sx] != NO_OBJECT)
            {
                uint8_t object_type = g_map.view.viewObjects.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, object_type, OBJECT);\
            }

            if (g_map.view.viewItems.viewEntities[sy][sx] != NO_ITEM)
            {
                uint8_t item_type = g_map.view.viewItems.viewEntities[sy][sx];
                DrawSpriteCached(graphics, memory, sx, sy, item_type, ITEM);
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

    UpdateVision(graphics);
    ReDrawTiles(graphics, memory, cam);
    ReDrawSprites(graphics, memory);
}
