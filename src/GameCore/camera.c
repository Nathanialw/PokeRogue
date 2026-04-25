//
// Created by nathanial on 2/20/26.
//

#include "camera.h"
#include <stdint.h>
#include "memory_ram.h"
#include "player.h"
#include "utils.h"


/**********************************************************************************************************************/
/** Returns the rect of the camera which holds the map position and dimensions of the camera
**********************************************************************************************************************/
Camera GetCamera(void)
{
    return g_run.camera;
}

/**********************************************************************************************************************/
/** sets the camera to the given position and dimensions
**********************************************************************************************************************/
Camera InitCamera(uint8_t x, uint8_t y, uint16_t w, uint16_t h)
{
    g_run.camera.x = x;
    g_run.camera.y = y;
    g_run.camera.w = w;
    g_run.camera.h = h;

    return g_run.camera;
}

/**********************************************************************************************************************/
/** sets the camera to the given position
 *  with default dimensions
 *  returns the camera rect
**********************************************************************************************************************/
Camera SetCamera(uint8_t x, uint8_t y)
{
    g_run.camera.x = x - CAM_OFFSET_X;
    g_run.camera.y = y - CAM_OFFSET_Y;
    return g_run.camera;
}

/**********************************************************************************************************************/
/** Sets camera position to the player position offset by the default camera size
 *  Sets camera dimensions to the default camera dimensions
**********************************************************************************************************************/
Camera SetCameraPlayer(void)
{
    Position pos = GetPlayerPosition();
    uint8_t px = pos.x;
    uint8_t py = pos.y;

    g_run.camera.x = px - CAM_OFFSET_X;
    g_run.camera.y = py - CAM_OFFSET_Y;
    return g_run.camera;
}

/**********************************************************************************************************************/
/** Check whether the given cell position  intersects with the camera rect
 *  ON SUCCESS - returns true
 *  ON FAIL - returns false
**********************************************************************************************************************/
bool CameraContains(uint8_t x, uint8_t y)
{
    if (x >= g_run.camera.x && x < (g_run.camera.x + VIEW_TW) && y >= g_run.camera.y && y < (g_run.camera.y + VIEW_TH))
        return true;
    return false;
}
