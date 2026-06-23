//
// Created by nathanial on 5/23/26.
//

#include "tooltip.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "core_graphics.h"
#include "core_memory_access.h"
#include "core_ram.h"

#include "map_ram.h"

// a

/**********************************************************************************************************************/
/** calculate the chances for each effect
 * create the lines and cache them
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateTooltip(GraphicsInterface graphics, MemoryInterface memory)
{
    if (g_map.objectCollision == NO_OBJECT && g_map.itemCollision == NO_ITEM)
        return;
    //
    // graphics.FillRect(0, SCREEN_H - (2 * TEXT_H), SCREEN_W, (2 * TEXT_H), Flash_GetColor(memory, PAL_DARK_BLUE_GRAY));
    // uint16_t x = 0;
    // uint16_t y = SCREEN_H - (2 * TEXT_H);
    // const uint8_t size = SCREEN_W / TEXT_H;
    // g_map.clearTooltip = true;
    //
    //
    //
    // if (g_map.objectCollision != NO_OBJECT)
    // {
    //     Flash_GetObjectName(memory, g_map.text, g_map.objectCollision);
    //     PrintLineStr(graphics, memory, x, y, FONT16x16, size, g_map.text, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
    // }
    //
    // if (g_map.itemCollision != NO_ITEM)
    // {
    //     Flash_GetItemName(memory, g_map.text, g_map.itemCollision);
    //     PrintLineStr(graphics, memory, x, y, FONT16x16, size, g_map.text, false, PAL_DARK_BLUE_GRAY, PAL_OFF_WHITE_GRAY_BLUE);
    // }

}
