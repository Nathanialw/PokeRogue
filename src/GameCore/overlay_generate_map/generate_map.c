//
// Created by nathanial on 2/22/26.
//

#include "generate_map.h"

#include "lib_memory.h"

#include "core_map.h"
#include "core_ram.h"

/**********************************************************************************************************************/
/** Runs All game init functions in order
 *      -> Game data
 *      -> Sets entities to default state
 *      -> Creates the map
 *      -> inits player data
 *      -> creates map entities
 *      -> sets camera to player position
**********************************************************************************************************************/


/**********************************************************************************************************************/
/**Map constant values
**********************************************************************************************************************/

#define MAP_MIN_X 8
#define MAP_MIN_Y 6
#define MAP_MAX_X (MAP_W - MAP_MIN_X - 2)
#define MAP_MAX_Y (MAP_H - MAP_MIN_Y - 1)

/**********************************************************************************************************************/
/**MAP GENERATION
**********************************************************************************************************************/
//

void ResetMap();


#define TOTAL_DUNGEON_GEN_ALGOS 3
void DungeonBasic(HardwareInterface hardware);
void DungeonGraph(HardwareInterface hardware);
void DungeonCave(HardwareInterface hardware);
void DungeonPredefined(HardwareInterface hardware);

typedef void (*DungeonLayout)(HardwareInterface hardware);

// TODO: add more dungeon layouts
SET_MEMORY(".map_gen.rodata")
const DungeonLayout GenerateMap[TOTAL_DUNGEON_GEN_ALGOS] =
{
#if defined(TEST_MAP)
    DungeonPredefined, // trad roguelike layout
#endif
    DungeonBasic, // trad roguelike layout
    DungeonGraph, // almost the same as above
    DungeonCave, // natural looking cave
};


/**********************************************************************************************************************/
/** Map Generation entry point
 *  Calls a given map generation type and populates the map cells
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void GenerateDungeon(HardwareInterface hardware, uint8_t type)
{
    ResetMap();
    GenerateMap[type](hardware);
}




/**********************************************************************************************************************/
/** Searches map for a random empty tile
 *  returns tile position when it is found
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
Position FindOpenRoomLocation(HardwareInterface hardware, ObjectsTypes type, uint8_t n)
{
    while (1)
    {
        Room room = g_core.rooms[n];
        Position pos;
        pos.x = hardware.GetRandom_uint8_t(room.x + 1, room.x + room.w - 1);
        pos.y = hardware.GetRandom_uint8_t(room.y + 1, room.y + room.h - 1);


        if (GetMapTile(pos.x, pos.y) == FLOOR_CASTLE && CheckTileForEntity(type, NO_ENTITY, pos) == NO_ENTITY)
        {
            return pos;
        }
    }
}


/**********************************************************************************************************************/
/*
 *  MAP
 *
**********************************************************************************************************************/


/**********************************************************************************************************************/
/** Increments floor level
 *  Gets random map biome
 *  Sets the map data to defaults
 *  Sets the fog map to defaults
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void InitMap(HardwareInterface hardware)
{
    g_core.turn_count = 0;
    g_core.turn_final = 300;
    g_core.biome = DESERT;
    g_core.layout_type = hardware.GetRandom_uint8_t(0, TOTAL_DUNGEON_GEN_ALGOS - 1);
    GenerateDungeon(hardware, g_core.layout_type);
}

/**********************************************************************************************************************
*   GENERATE BasicDungeon
*****************************************************************************************************************/
SET_MEMORY(".map_gen")
void ResetMap(void)
{
    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
            SetMapTile(x, y, WALL_STONE);
}


SET_MEMORY(".map_gen")
void SetMapBorder(void)
{
    for (uint16_t y = 0; y < MAP_H; y++)
    {
        SetMapTile(16, y, WALL_STONE);
        SetMapTile(MAP_W - 16, y, WALL_STONE);
    }

    for (uint16_t x = 0; x < MAP_W; x++)
    {
        SetMapTile(x, 16, WALL_STONE);
        SetMapTile(x, MAP_H - 16, WALL_STONE);
    }

}


/**********************************************************************************************************************/
/*
*   GENERATE GeneratePredefinedMap
*
**********************************************************************************************************************/

/**********************************************************************************************************************
*   create a predefined map for testing
*   generate:
*       -one of each item
*       -one of each object
*       -one of each object
*       -one of each trainer
*       -one of each tile
*
*   disable movement other than player
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void DungeonPredefined(HardwareInterface hardware)
{
    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
        {
            //border wall at 12
            if (x == 12 || x == MAP_W - 12 || y == 12 || y == MAP_H - 12)
                SetMapTile(x, y, WALL_STONE);
            else if (x > 12 && x < MAP_W - 12 && y > 12 && y < MAP_H - 12)
                SetMapTile(x, y, FLOOR_CASTLE);
            else
                SetMapTile(x, y, WATER);
        }


    uint8_t index = 0;
    for (uint16_t j = 0; j < 2; j++)
    {
        for (uint16_t i = 0; i < 8; i++)
        {
            const uint8_t source_y = 14 + (j * 10);
            const uint8_t source_size = 6;
            const uint8_t y_size = source_y + 6;

            for (uint16_t y = source_y; y < y_size; y++)
                for (uint16_t x = (i * 10 + 4); x < (i * 10 + 4) + source_size; x++)
                    SetMapTile(x + 14, y, index);
            index++;
        }
    }
}


/**********************************************************************************************************************/
/*
*   GENERATE BasicDungeon
*
**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Checks whether given room rect A intersects with room rect A
 *  ON SUCCESS - return true
 *  ON FAIL - return false
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
int Intersects(Room a, Room b)
{
    return (a.x <= b.x + b.w + 1 &&
        a.x + a.w + 1 >= b.x &&
        a.y <= b.y + b.h + 1 &&
        a.y + a.h + 1 >= b.y);
}

/**********************************************************************************************************************/
/** Updates the tile map with FLOOR_CASTLE tiles at the position and dimensions of the given room rect
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveRoom(Room r)
{
    for (uint8_t y = r.y; y < r.y + r.h; y++)
        for (uint8_t x = r.x; x < r.x + r.w; x++)
            SetMapTile(x, y, FLOOR_CASTLE);
}

/**********************************************************************************************************************/
/** Updates the tile map with FLOOR_CASTLE tiles between given x1 and x2 position at the given y position
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveHorizontal(uint8_t x1, uint8_t x2, uint8_t y)
{
    if (x2 < x1)
    {
        uint8_t t = x1;
        x1 = x2;
        x2 = t;
    }

    for (uint8_t x = x1; x <= x2; x++)
        SetMapTile(x, y, FLOOR_CASTLE);
}

/**********************************************************************************************************************/
/** Updates the tile map with FLOOR_CASTLE tiles between given y1 and y2 position at the given x position
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveVertical(uint8_t y1, uint8_t y2, uint8_t x)
{
    if (y2 < y1)
    {
        uint8_t t = y1;
        y1 = y2;
        y2 = t;
    }

    for (uint8_t y = y1; y <= y2; y++)
        SetMapTile(x, y, FLOOR_CASTLE);
}

/**********************************************************************************************************************/
/** Updates the tile map with FLOOR_CASTLE tiles connecting the given room rect A and room rect B
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void ConnectRooms(HardwareInterface hardware, Room a, Room b)
{
    uint8_t ax = a.x + a.w / 2;
    uint8_t ay = a.y + a.h / 2;

    uint8_t bx = b.x + b.w / 2;
    uint8_t by = b.y + b.h / 2;

    if (hardware.GetRandom_uint8_t(0, 1))
    {
        CarveHorizontal(ax, bx, ay);
        CarveVertical(ay, by, bx);
    }
    else
    {
        CarveVertical(ay, by, ax);
        CarveHorizontal(ax, bx, by);
    }
}

/**********************************************************************************************************************/
/** Core basic Map Generation algrithm
 *  Creates random position and dimention rooms of FLOOR_CASTLE tiles around the map
 *  Connects those rooms with corridors of FLOOR_CASTLE tiles
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void DungeonBasic(HardwareInterface hardware)
{
    g_core.roomCount = 0;

    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
            SetMapTile(x, y, WALL_STONE);


    for (uint8_t i = 0; i < MAX_ROOMS; i++)
    {
        Room r;

        r.w = hardware.GetRandom_uint8_t(4, 10);
        r.h = hardware.GetRandom_uint8_t(4, 10);

        r.x = hardware.GetRandom_uint8_t(0, (MAP_W - r.w - 2) + 1);
        r.y = hardware.GetRandom_uint8_t(0, (MAP_H - r.h - 2) + 1);

        uint8_t failed = 0;

        for (uint8_t j = 0; j < g_core.roomCount; j++)
        {
            if (Intersects(r, g_core.rooms[j]))
            {
                failed = 1;
                break;
            }
        }

        if (!failed)
        {
            CarveRoom(r);

            if (g_core.roomCount > 0)
                ConnectRooms(hardware, g_core.rooms[g_core.roomCount - 1], r);

            g_core.rooms[g_core.roomCount++] = r;
        }
    }
}

/**********************************************************************************************************************/
/*
 *  GENERATE DungeonGraph
 *
**********************************************************************************************************************/

#define MAX_ROOMS 128
#define MAX_EDGES (MAX_ROOMS * 6)

typedef struct
{
    uint8_t a;
    uint8_t b;
    uint16_t dist;
} Edge;


SET_MEMORY(".map_gen.data")
static Edge edges[MAX_EDGES];
SET_MEMORY(".map_gen.data")
uint16_t edgeCount = 0;


/**********************************************************************************************************************/
/*  Returns the distance between a given x1,y1 and a given x2,y2 in number of cells to traverse axis aligned
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
uint16_t Dist2(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    int16_t dx = (int16_t)x1 - (int16_t)x2;
    int16_t dy = (int16_t)y1 - (int16_t)y2;

    return dx * dx + dy * dy;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void RoomCenter(Room r, uint8_t* cx, uint8_t* cy)
{
    *cx = r.x + r.w / 2;
    *cy = r.y + r.h / 2;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void BuildEdges(void)
{
    edgeCount = 0;

    for (int i = 0; i < g_core.roomCount; i++)
    {
        uint8_t ax, ay;
        RoomCenter(g_core.rooms[i], &ax, &ay);

        uint8_t used[MAX_ROOMS] = {0};

        for (int k = 0; k < 6; k++) // 6 neighbors is safer
        {
            int best = -1;
            uint16_t bestDist = 0xFFFF;

            for (int j = 0; j < g_core.roomCount; j++)
            {
                if (i == j) continue;
                if (used[j]) continue;

                uint8_t bx, by;
                RoomCenter(g_core.rooms[j], &bx, &by);

                uint16_t d = Dist2(ax, ay, bx, by);

                if (d < bestDist)
                {
                    bestDist = d;
                    best = j;
                }
            }

            if (best >= 0 && edgeCount < MAX_EDGES)
            {
                edges[edgeCount].a = i;
                edges[edgeCount].b = best;
                edges[edgeCount].dist = bestDist;
                edgeCount++;

                used[best] = 1;
            }
        }
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveCorridorZigZag(HardwareInterface hardware, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    int16_t x = x1;
    int16_t y = y1;

    SetMapTile(x, y, FLOOR_CASTLE);

    while (x != x2 || y != y2)
    {
        if (hardware.GetRandom_uint8_t(0, 1))
        {
            if (x < x2) x++;
            else if (x > x2) x--;
        }
        else
        {
            if (y < y2) y++;
            else if (y > y2) y--;
        }

        SetMapTile(x, y, FLOOR_CASTLE);
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveCorridorLinear(HardwareInterface hardware, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    if (hardware.GetRandom_uint8_t(0, 1))
    {
        while (x1 != x2)
        {
            SetMapTile(x1, y1, FLOOR_CASTLE);
            x1 += (x2 > x1) ? 1 : -1;
        }

        while (y1 != y2)
        {
            SetMapTile(x1, y1, FLOOR_CASTLE);
            y1 += (y2 > y1) ? 1 : -1;
        }
    }
    else
    {
        while (y1 != y2)
        {
            SetMapTile(x1, y1, FLOOR_CASTLE);
            y1 += (y2 > y1) ? 1 : -1;
        }

        while (x1 != x2)
        {
            SetMapTile(x1, y1, FLOOR_CASTLE);
            x1 += (x2 > x1) ? 1 : -1;
        }
    }

    SetMapTile(x2, y2, FLOOR_CASTLE);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void BuildMST(HardwareInterface hardware)
{
    uint8_t visited[MAX_ROOMS] = {0};

    visited[0] = 1;
    uint8_t visitedCount = 1;

    while (visitedCount < g_core.roomCount)
    {
        int16_t bestEdge = -1;
        uint16_t bestDist = 0xFFFF;

        for (int i = 0; i < edgeCount; i++)
        {
            Edge e = edges[i];

            if (visited[e.a] && !visited[e.b] && e.dist < bestDist)
            {
                bestEdge = i;
                bestDist = e.dist;
            }

            if (visited[e.b] && !visited[e.a] && e.dist < bestDist)
            {
                bestEdge = i;
                bestDist = e.dist;
            }
        }

        if (bestEdge == -1)
        {
            // force connect nearest unvisited room
            for (int i = 0; i < g_core.roomCount; i++)
            {
                if (visited[i]) continue;

                uint8_t ax, ay;
                RoomCenter(g_core.rooms[i], &ax, &ay);

                int best = -1;
                uint16_t bestDist = 0xFFFF;

                for (int j = 0; j < g_core.roomCount; j++)
                {
                    if (!visited[j]) continue;

                    uint8_t bx, by;
                    RoomCenter(g_core.rooms[j], &bx, &by);

                    uint16_t d = Dist2(ax, ay, bx, by);

                    if (d < bestDist)
                    {
                        bestDist = d;
                        best = j;
                    }
                }

                if (best >= 0)
                {
                    uint8_t bx, by;
                    RoomCenter(g_core.rooms[best], &bx, &by);

                    CarveCorridorLinear(hardware, ax, ay, bx, by);

                    visited[i] = 1;
                    visitedCount++;
                    break;
                }
            }

            continue;
        }

        Edge e = edges[bestEdge];

        uint8_t ax, ay, bx, by;
        RoomCenter(g_core.rooms[e.a], &ax, &ay);
        RoomCenter(g_core.rooms[e.b], &bx, &by);

        CarveCorridorLinear(hardware, ax, ay, bx, by);

        if (!visited[e.a])
        {
            visited[e.a] = 1;
            visitedCount++;
        }
        if (!visited[e.b])
        {
            visited[e.b] = 1;
            visitedCount++;
        }
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void AddExtraConnections(HardwareInterface hardware)
{
    for (uint16_t i = 0; i < edgeCount; i++)
    {
        if (hardware.GetRandom_uint8_t(0, 100) < 15)
        {
            uint8_t ax, ay, bx, by;

            RoomCenter(g_core.rooms[edges[i].a], &ax, &ay);
            RoomCenter(g_core.rooms[edges[i].b], &bx, &by);

            CarveCorridorLinear(hardware, ax, ay, bx, by);
        }
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
void DebugPrintMap(void)
{
#ifdef ENABLE_DEBUG_OUTPUT
    // for (uint16_t y = 0; y < MAP_H; y++)
    // {
    //     for (uint16_t x = 0; x < MAP_W; x++)
    //     {
    //         TileType t = GetMapTile(x, y);
    //
    //         char c = '?';
    //
    //         switch (t)
    //         {
    //         case WALL_STONE: c = '#';
    //             break;
    //         case FLOOR_CASTLE: c = '.';
    //             break;
    //         default: c = '?';
    //             break;
    //         }
    //         PRINT("%c", c);
    //     }
    //     PRINT("\n");
    // }
#endif
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void DungeonGraph(HardwareInterface hardware)
{
    g_core.roomCount = 0;

    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
            SetMapTile(x, y, WALL_STONE);

    for (uint8_t i = 0; i < MAX_ROOMS; i++)
    {
        Room r;

        r.w = hardware.GetRandom_uint8_t(5, 10);
        r.h = hardware.GetRandom_uint8_t(5, 10);

        r.x = hardware.GetRandom_uint8_t(0, (MAP_W - r.w - 2) + 1);
        r.y = hardware.GetRandom_uint8_t(0, (MAP_H - r.h - 2) + 1);

        uint8_t failed = 0;

        for (uint8_t j = 0; j < g_core.roomCount; j++)
        {
            if (Intersects(r, g_core.rooms[j]))
            {
                failed = 1;
                break;
            }
        }

        if (!failed)
        {
            CarveRoom(r);
            g_core.rooms[g_core.roomCount++] = r;
        }
    }

    BuildEdges();
    BuildMST(hardware);
    AddExtraConnections(hardware);
}


/**********************************************************************************************************************/
/** GENERATE DungeonDrunkard
**********************************************************************************************************************/

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void DungeonCave(HardwareInterface hardware)
{
    uint16_t x = MAP_W / 2;
    uint16_t y = MAP_H / 2;

    uint32_t carved = 0;
    uint32_t target = (MAP_W * MAP_H) / 3; // 33% open space

    // fill map with walls
    for (uint16_t yy = 0; yy < MAP_H; yy++)
        for (uint16_t xx = 0; xx < MAP_W; xx++)
            SetMapTile(xx, yy, WALL_STONE);

    while (carved < target)
    {
        if (GetMapTile(x, y) == WALL_STONE)
        {
            SetMapTile(x, y, FLOOR_CASTLE);
            carved++;
        }

        switch (hardware.GetRandom_uint8_t(0, 4))
        {
        case 0: if (x > 1) x--;
            break;
        case 1: if (x < MAP_W - 2) x++;
            break;
        case 2: if (y > 1) y--;
            break;
        case 3: if (y < MAP_H - 2) y++;
            break;
        }
    }

    // DebugPrintMap();
}
