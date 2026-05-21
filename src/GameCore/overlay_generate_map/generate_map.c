//
// Created by nathanial on 2/22/26.
//


#include "core_map.h"
#include "lib_debugging.h"

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

typedef void (*DungeonLayout)(HardwareInterface hardware);

#define TOTAL_DUNGEON_GEN_ALGOS 3
void DungeonBasic(HardwareInterface hardware);
void DungeonGraph(HardwareInterface hardware);
void DungeonCave(HardwareInterface hardware);

// TODO: add more dungeon layouts
SET_MEMORY(".map_gen.rodata")
const DungeonLayout GenerateMap[TOTAL_DUNGEON_GEN_ALGOS] =
{
    DungeonBasic, // trad roguelike layout
    // DungeonGraph, // almost the same as above
    // DungeonCave, // natural looking cave
};


/**********************************************************************************************************************/
/** Map Generation entry point
 *  Calls a given map generation type and populates the map cells
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void GenerateDungeon(HardwareInterface hardware, uint8_t type)
{
    GenerateMap[type](hardware);
}

/**********************************************************************************************************************/
/*
 *  MAP
 *
**********************************************************************************************************************/

/**********************************************************************************************************************/
/**Sets the cached level data
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void UpdateLevel(uint8_t floor, Biomes biome)
{
    g_core.floor = floor;
    g_core.biome = biome;
    g_core.turn_count = 0;
    g_core.turn_final = 300; //TODO: Generate a random number of turns
}




/**********************************************************************************************************************/
/** Increments floor level
 *  Gets random map biome
 *  Sets the map data to defaults
 *  Sets the fog map to defaults
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void InitMap(HardwareInterface hardware)
{
    g_core.floor++;
    g_core.biome = DESERT;
    UpdateLevel(g_core.floor, g_core.biome);
    uint8_t map_type = 0;
    GenerateDungeon(hardware, map_type);
}

/**********************************************************************************************************************/
/*
*   GENERATE BasicDungeon
*
**********************************************************************************************************************/

#define MAX_ROOMS 128

typedef struct
{
    uint16_t x, y, w, h;
} Room;


SET_MEMORY(".map_gen.data")
Room rooms[MAX_ROOMS];
SET_MEMORY(".map_gen.data")
uint8_t roomCount = 0;

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
/** Updates the tile map with ground tiles at the position and dimensions of the given room rect
**********************************************************************************************************************/
SET_MEMORY(".map_gen")
void CarveRoom(Room r)
{
    for (uint8_t y = r.y; y < r.y + r.h; y++)
        for (uint8_t x = r.x; x < r.x + r.w; x++)
            SetMapTile(x, y, GROUND);
}

/**********************************************************************************************************************/
/** Updates the tile map with ground tiles between given x1 and x2 position at the given y position
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
        SetMapTile(x, y, GROUND);
}

/**********************************************************************************************************************/
/** Updates the tile map with ground tiles between given y1 and y2 position at the given x position
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
        SetMapTile(x, y, GROUND);
}

/**********************************************************************************************************************/
/** Updates the tile map with ground tiles connecting the given room rect A and room rect B
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
 *  Creates random position and dimention rooms of ground tiles around the map
 *  Connects those rooms with corridors of ground tiles
**********************************************************************************************************************/
SET_MEMORY(".map_gen.rodata")
static const char generate_dungeon[] = "GenerateDungeon() BEGIN";
SET_MEMORY(".map_gen.rodata")
static const char generate_dungeon_reset[] = "GenerateDungeon() RESET";
SET_MEMORY(".map_gen.rodata")
static const char generate_dungeon_done[] = "GenerateDungeon() DONE";


SET_MEMORY(".map_gen")
void DungeonBasic(HardwareInterface hardware)
{
    hardware.Print(generate_dungeon);

    roomCount = 0;

    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
            SetMapTile(x, y, WALL_STONE);

    hardware.Print(generate_dungeon_reset);

    for (uint8_t i = 0; i < MAX_ROOMS; i++)
    {
        Room r;

        r.w = hardware.GetRandom_uint8_t(4, 10);
        r.h = hardware.GetRandom_uint8_t(4, 10);

        r.x = hardware.GetRandom_uint8_t(0, (MAP_W - r.w - 2) + 1);
        r.y = hardware.GetRandom_uint8_t(0, (MAP_H - r.h - 2) + 1);

        uint8_t failed = 0;

        for (uint8_t j = 0; j < roomCount; j++)
        {
            if (Intersects(r, rooms[j]))
            {
                failed = 1;
                break;
            }
        }

        if (!failed)
        {
            CarveRoom(r);

            if (roomCount > 0)
                ConnectRooms(hardware, rooms[roomCount - 1], r);

            rooms[roomCount++] = r;
        }
    }

    hardware.Print(generate_dungeon_done);
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


Edge edges[MAX_EDGES];
uint16_t edgeCount = 0;


/**********************************************************************************************************************/
/*  Returns the distance between a given x1,y1 and a given x2,y2 in number of cells to traverse axis aligned
**********************************************************************************************************************/

uint16_t Dist2(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    int16_t dx = (int16_t)x1 - (int16_t)x2;
    int16_t dy = (int16_t)y1 - (int16_t)y2;

    return dx * dx + dy * dy;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

void RoomCenter(Room r, uint8_t* cx, uint8_t* cy)
{
    *cx = r.x + r.w / 2;
    *cy = r.y + r.h / 2;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

void BuildEdges(void)
{
    edgeCount = 0;

    for (int i = 0; i < roomCount; i++)
    {
        uint8_t ax, ay;
        RoomCenter(rooms[i], &ax, &ay);

        uint8_t used[MAX_ROOMS] = {0};

        for (int k = 0; k < 6; k++) // 6 neighbors is safer
        {
            int best = -1;
            uint16_t bestDist = 0xFFFF;

            for (int j = 0; j < roomCount; j++)
            {
                if (i == j) continue;
                if (used[j]) continue;

                uint8_t bx, by;
                RoomCenter(rooms[j], &bx, &by);

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

void CarveCorridorZigZag(HardwareInterface hardware, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    int16_t x = x1;
    int16_t y = y1;

    SetMapTile(x, y, GROUND);

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

        SetMapTile(x, y, GROUND);
    }
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

void CarveCorridorLinear(HardwareInterface hardware, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    if (hardware.GetRandom_uint8_t(0, 1))
    {
        while (x1 != x2)
        {
            SetMapTile(x1, y1, GROUND);
            x1 += (x2 > x1) ? 1 : -1;
        }

        while (y1 != y2)
        {
            SetMapTile(x1, y1, GROUND);
            y1 += (y2 > y1) ? 1 : -1;
        }
    }
    else
    {
        while (y1 != y2)
        {
            SetMapTile(x1, y1, GROUND);
            y1 += (y2 > y1) ? 1 : -1;
        }

        while (x1 != x2)
        {
            SetMapTile(x1, y1, GROUND);
            x1 += (x2 > x1) ? 1 : -1;
        }
    }

    SetMapTile(x2, y2, GROUND);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

void BuildMST(HardwareInterface hardware)
{
    uint8_t visited[MAX_ROOMS] = {0};

    visited[0] = 1;
    uint8_t visitedCount = 1;

    while (visitedCount < roomCount)
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
            for (int i = 0; i < roomCount; i++)
            {
                if (visited[i]) continue;

                uint8_t ax, ay;
                RoomCenter(rooms[i], &ax, &ay);

                int best = -1;
                uint16_t bestDist = 0xFFFF;

                for (int j = 0; j < roomCount; j++)
                {
                    if (!visited[j]) continue;

                    uint8_t bx, by;
                    RoomCenter(rooms[j], &bx, &by);

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
                    RoomCenter(rooms[best], &bx, &by);

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
        RoomCenter(rooms[e.a], &ax, &ay);
        RoomCenter(rooms[e.b], &bx, &by);

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

void AddExtraConnections(HardwareInterface hardware)
{
    for (uint16_t i = 0; i < edgeCount; i++)
    {
        if (hardware.GetRandom_uint8_t(0, 100) < 15)
        {
            uint8_t ax, ay, bx, by;

            RoomCenter(rooms[edges[i].a], &ax, &ay);
            RoomCenter(rooms[edges[i].b], &bx, &by);

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
    //         case GROUND: c = '.';
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

void DungeonGraph(HardwareInterface hardware)
{
    roomCount = 0;

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

        for (uint8_t j = 0; j < roomCount; j++)
        {
            if (Intersects(r, rooms[j]))
            {
                failed = 1;
                break;
            }
        }

        if (!failed)
        {
            CarveRoom(r);
            rooms[roomCount++] = r;
        }
    }

    BuildEdges();
    BuildMST(hardware);
    AddExtraConnections(hardware);
    // DebugPrintMap();
    DEBUG("rooms %d", roomCount);
}


/**********************************************************************************************************************/
/** GENERATE DungeonDrunkard
**********************************************************************************************************************/

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

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
            SetMapTile(x, y, GROUND);
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
