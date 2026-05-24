//
// Created by nathanial on 5/23/26.
//

#include "tooltip.h"

#include "lib_decl.h"

#include "core_graphics.h"
#include "core_memory_access.h"
#include "core_ram.h"

#include "map_ram.h"

/**********************************************************************************************************************/
/** Print information about the current cell on th bottom of the screen
**********************************************************************************************************************/
void UpdateTooltip(GraphicsInterface graphics, MemoryInterface memory)
{
    if (g_map.objectCollision == NO_OBJECT && g_map.itemCollision == NO_ITEM)
        return;

    graphics.FillRect(0, SCREEN_H - (2 * 8), SCREEN_W, (2 * 8), PAL_OFF_WHITE_GRAY);
    uint16_t x = 0;
    uint16_t y = SCREEN_H - (2 * 8);
    const uint8_t size = SCREEN_W / 8;
    g_map.clearTooltip = true;

    if (g_map.objectCollision != NO_OBJECT)
    {
        Flash_GetObjectName(memory, g_map.text, g_map.objectCollision);
        PrintLineStr(graphics, memory, x, y, FONT8x8, size, g_map.text, false);
    }

    if (g_map.itemCollision != NO_ITEM)
    {
        Flash_GetItemName(memory, g_map.text, g_map.itemCollision);
        PrintLineStr(graphics, memory, x, y, FONT8x8, size, g_map.text, false);
    }

}
