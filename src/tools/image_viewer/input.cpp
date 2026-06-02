//
// Created by nathanial on 5/31/26.
//
#include <SDL3/SDL_events.h>

#include "globals.h"
#include "input.h"

#include <SDL3/SDL_timer.h>

#include "rendering.h"
#include "ui.h"


SDL_FPoint GetMousePoint()
{
    SDL_FPoint mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);
    return mouse;
}

/* Sets the input state struct
 */
void ProcessInput(Renderer& renderer, Text& text, ImageData& images, UI& ui)
{
    SDL_Event event;
    while (1)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_KEY_DOWN:
                {
                    break;
                }
            case SDL_EVENT_KEY_UP:
                {
                    switch (event.key.key)
                    {
                    case SDLK_ESCAPE:
                        {
                            g_sdl.Close();
                            return;
                        }
                    default:
                        {
                            break;;
                        }
                    }
                }
            case SDL_EVENT_QUIT:
                {
                    break;
                }

            case SDL_EVENT_MOUSE_MOTION:
                {
                    SDL_FPoint mouse = GetMousePoint();
                    auto area = ui.CheckMouseInUIArea(mouse);
                    if (!area.has_value()) return;

                    if (area.value() == UIArea::TOP)
                    {
                        // ui.UpdateHoverEntityType(mouse);
                    }
                    else if (area.value() == UIArea::LEFT)
                    {
                        // ui.UpdateHoverEntity(mouse);
                    }
                    else if (area.value() == UIArea::RIGHT)
                    {
                    }
                    else if (area.value() == UIArea::MAIN)
                    {
                        // hover rect highlight
                        // delete
                        // accept
                    }
                    else if (area.value() == UIArea::SCROLL_BAR_LEFT)
                    {
                    }
                    else if (area.value() == UIArea::SCROLL_BAR_MAIN)
                    {
                    }
                    break;
                }

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                {
                    SDL_FPoint mouse = GetMousePoint();
                    auto area = ui.CheckMouseInUIArea(mouse);
                    if (!area.has_value()) return;

                    if (area.value() == UIArea::TOP)
                    {
                        auto entity_type = ui.UpdateSelectedEntityType(mouse);
                        if (entity_type.has_value())
                        {
                            images.UpdateType(entity_type.value());
                            text.PopulateTextTextures(renderer.GetSDLRenderer(), images.entity_list);
                            renderer.CreateTextures(images);
                            return;
                        }
                    }
                    else if (area.value() == UIArea::LEFT)
                    {
                        const uint16_t entity_id = ui.UpdateSelectedEntity(mouse) + ui.offset_entity_id;
                        if (entity_id != images.GetSelectedEntity(entity_id))
                        {
                            images.UpdateEntity(entity_id);
                            text.PopulateTextTextures(renderer.GetSDLRenderer(), images.entity_list);
                            renderer.CreateTextures(images);
                            return;
                        }
                    }
                    else if (area.value() == UIArea::RIGHT)
                    {
                    }
                    else if (area.value() == UIArea::MAIN)
                    {
                        auto n = ui.DeleteImage(mouse);
                        if (!n.has_value()) break;
                        renderer.DeleteTexture(images, n.value());
                        return;
                    }
                    else if (area.value() == UIArea::SCROLL_BAR_LEFT)
                    {
                    }
                    else if (area.value() == UIArea::SCROLL_BAR_MAIN)
                    {
                    }
                    break;
                }

            case SDL_EVENT_MOUSE_BUTTON_UP:
                {
                    SDL_FPoint mouse = GetMousePoint();
                    break;
                }

            case SDL_EVENT_MOUSE_WHEEL:
                {
                    SDL_FPoint mouse = GetMousePoint();
                    auto area = ui.CheckMouseInUIArea(mouse);
                    if (!area.has_value()) return;

                    if (event.wheel.y > 0)
                    {
                        if (area.value() == UIArea::TOP)
                        {
                        }
                        else if (area.value() == UIArea::LEFT)
                        {
                            if (ui.offset_entity_id == 0) break;
                            ui.offset_entity_id--;
                            return;
                        }
                        else if (area.value() == UIArea::RIGHT)
                        {
                        }
                        else if (area.value() == UIArea::MAIN)
                        {
                            if (ui.offset_image == 0) break;
                            ui.offset_image--;
                            return;
                        }
                        else if (area.value() == UIArea::SCROLL_BAR_LEFT)
                        {
                        }
                        else if (area.value() == UIArea::SCROLL_BAR_MAIN)
                        {
                        }
                    }
                    else
                    {
                        if (area.value() == UIArea::TOP)
                        {
                        }
                        else if (area.value() == UIArea::LEFT)
                        {
                            if (ui.offset_entity_id + DISPLAYED_ENTITY_COUNT < images.GetEntityCount())
                            {
                                ui.offset_entity_id++;
                                return;
                            }
                        }
                        else if (area.value() == UIArea::RIGHT)
                        {
                        }
                        else if (area.value() == UIArea::MAIN)
                        {
                            if (ui.offset_image + DISPLAYED_IMAGE_COUNT < images.GetImageCount())
                            {
                                ui.offset_image++;
                                return;
                            }
                        }
                        else if (area.value() == UIArea::SCROLL_BAR_LEFT)
                        {
                        }
                        else if (area.value() == UIArea::SCROLL_BAR_MAIN)
                        {
                        }
                    }
                    break;
                }

            default:
                {
                    break;
                }
            }
        }
        else
        {
            SDL_Delay(1);
        }
    }
}
