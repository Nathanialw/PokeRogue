//
// Created by nathanial on 6/22/26.
//

#include "core_input.h"

#include "core_ram.h"
#include "lib_debugging.h"
#include "lib_decl.h"
#include "lib_memory.h"

void UpdateRegions()
{


}


bool MouseInRect(int16_t m_x, int16_t m_y, Rect_16 rect)
{
    if (m_x < rect.x)
        return false;
    if (m_x > (rect.x + rect.w))
        return false;
    if (m_y < rect.y)
        return false;
    if (m_y > (rect.y + rect.h))
        return false;
    return true;
}

bool InteractPlayerFrame(GraphicsInterface graphics, InputInterface input)
{
    KeyState input_state = input.GetInputKeyState();
    Rect_16 rect = graphics.GetLeftScreenRect();
    uint16_t h = g_core.area_down_y;
    float scale = graphics.GetScale();
    if (scale > 0 && scale < 1)
        h = h / graphics.GetScale();
    rect.h = h;
    if (MouseInRect(input_state.mouse.x, input_state.mouse.y, rect))
    {
        return true;
    }
    return false;
}

bool InteractSpellFrame(GraphicsInterface graphics, InputInterface input)
{
    KeyState input_state = input.GetInputKeyState();
    Rect_16 rect = graphics.GetLeftScreenRect();
    uint16_t h = g_core.area_down_y;
    float scale = graphics.GetScale();
    if (scale > 0 && scale < 1)
        h = h / graphics.GetScale();

    rect.y += h;
    rect.h -= h;
    if (MouseInRect(input_state.mouse.x, input_state.mouse.y, rect))
    {
        return true;
    }
    return false;
}

bool InteractPartyFrame(GraphicsInterface graphics, InputInterface input)
{
    KeyState input_state = input.GetInputKeyState();
    Rect_16 rect = graphics.GetRightScreenRect();
    uint16_t h = g_core.area_down_y;
    float scale = graphics.GetScale();
    if (scale > 0 && scale < 1)
        h = h / graphics.GetScale();
    rect.h = h;
    if (MouseInRect(input_state.mouse.x, input_state.mouse.y, rect))
    {
        return true;
    }
    return false;
}

bool InteractInventoryFrame(GraphicsInterface graphics, InputInterface input)
{
    KeyState input_state = input.GetInputKeyState();
    Rect_16 rect = graphics.GetRightScreenRect();
    uint16_t h = g_core.area_down_y;
    float scale = graphics.GetScale();
    if (scale > 0 && scale < 1)
        h = h / graphics.GetScale();

    rect.y += h;
    rect.h -= h;
    if (MouseInRect(input_state.mouse.x, input_state.mouse.y, rect))
    {
        return true;
    }
    return false;
}

bool InteractMainFrame(GraphicsInterface graphics, InputInterface input)
{
    KeyState input_state = input.GetInputKeyState();
    if (MouseInRect(input_state.mouse.x, input_state.mouse.y, graphics.GetMainRect()))
    {
        return true;
    }
    return false;
}


SET_MEMORY(".core")
void InteractUI(GraphicsInterface graphics, InputInterface input)
{
    graphics.UpdateDrawAreas();

    if (InteractInventoryFrame(graphics, input))
    {
        DEBUG("InteractInventoryFrame %d", input.GetInputKeyState().mouse.y);
        return;
    }
    if (InteractPartyFrame(graphics, input))
    {
        DEBUG("InteractPartyFrame %d", input.GetInputKeyState().mouse.y);
        return;
    }
    if (InteractPlayerFrame(graphics, input))
    {
        DEBUG("InteractPlayerFrame %d", input.GetInputKeyState().mouse.y);
        return;
    }
    if (InteractSpellFrame(graphics, input))
    {
        DEBUG("InteractSpellFrame %d", input.GetInputKeyState().mouse.y);
        return;
    }
    if (InteractMainFrame(graphics, input))
    {
        DEBUG("InteractMainFrame %d", input.GetInputKeyState().mouse.y);
        return;
    }
}
