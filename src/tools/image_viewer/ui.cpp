//
// Created by nathanial on 5/31/26.
//

#include "ui.h"


void UI::Init()
{
    active_area = UIArea::NONE;

    hover_rects[(uint8_t)UIArea::TOP] = {0.0f, 0.0f, BTN_W * NUM_ENTITY_TYPES, BTN_H};
    hover_rects[(uint8_t)UIArea::LEFT] = {0.0f, BTN_H, BTN_W, 128 * DISPLAYED_IMAGE_COUNT};
    hover_rects[(uint8_t)UIArea::SCROLL_BAR_LEFT] = {hover_rects[(uint8_t)UIArea::LEFT].x + hover_rects[(uint8_t)UIArea::LEFT].w - SCROLL_BAR_W, hover_rects[(uint8_t)UIArea::LEFT].y, SCROLL_BAR_W, hover_rects[(uint8_t)UIArea::LEFT].h};
    hover_rects[(uint8_t)UIArea::MAIN] = {BTN_W, BTN_H, (BTN_W * 4), 128 * DISPLAYED_IMAGE_COUNT};
    hover_rects[(uint8_t)UIArea::SCROLL_BAR_MAIN] = {hover_rects[(uint8_t)UIArea::MAIN].x + hover_rects[(uint8_t)UIArea::MAIN].w - SCROLL_BAR_W, hover_rects[(uint8_t)UIArea::MAIN].y, SCROLL_BAR_W, hover_rects[(uint8_t)UIArea::MAIN].h};
    hover_rects[(uint8_t)UIArea::RIGHT] = {BTN_W * 5, BTN_H, 128 * DISPLAYED_IMAGE_COUNT, 128 * DISPLAYED_IMAGE_COUNT};

    entity_type_select_rects[CREATURE] = {CREATURE * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[OBJECT] = {OBJECT * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[ITEM] = {ITEM * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[TRAINER] = {TRAINER * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[SPELL] = {SPELL * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[SKILL] = {SKILL * BTN_W, 0.0f, BTN_W, BTN_H};
    entity_type_select_rects[TILE] = {TILE * BTN_W, 0.0f, BTN_W, BTN_H};


    entity_rect_base = {0.0f, BTN_H, LIST_ITEM_W, LIST_ITEM_H};
    for (uint8_t i = 0; i < DISPLAYED_IMAGE_COUNT; i++)
    {
        accept_rects[i] = {hover_rects[(uint8_t)UIArea::MAIN].x + (128.0f + 256.0f) - SCROLL_BAR_W, float(BTN_H + (128.0f * i) + (ICON_H * 0.5f)), ICON_W, ICON_H};
        delete_rects[i] = {hover_rects[(uint8_t)UIArea::MAIN].x + (128.0f + 256.0f) - SCROLL_BAR_W + ICON_W, float(BTN_H + (128.0f * i) + (ICON_H * 0.5f)), ICON_W, ICON_H};
    }

    offset_entity_id = 0;
    offset_image = 0;
    hover_rect = 0;
    hover_list_item = 0;
    selected_list_item = 0;
    selected_entity_type = 0;
}

std::optional<SDL_FRect> UI::GetHoverRect()
{
    if (active_area == UIArea::NONE)
        return std::nullopt;

    return hover_rects[(uint8_t)active_area];
}

std::optional<EntityTypes> UI::UpdateSelectedEntityType(const SDL_FPoint& mouse)
{
    for (uint8_t i = 0; i < NUM_ENTITY_TYPES; i++)
        if (SDL_PointInRectFloat(&mouse, &entity_type_select_rects[i]))
        {
            offset_entity_id = 0;
            offset_image = 0;
            selected_list_item = 0;
            selected_entity_type = i;
            return (EntityTypes)i;
        }
    return std::nullopt;
}

uint16_t UI::UpdateSelectedEntity(const SDL_FPoint& mouse)
{
    SDL_FRect rect = entity_rect_base;
    for (uint8_t i = 0; i < DISPLAYED_ENTITY_COUNT; i++)
    {
        if (SDL_PointInRectFloat(&mouse, &rect))
        {
            offset_image = 0;
            selected_list_item = i + offset_entity_id;
            return i;
        }
        rect.y += LIST_ITEM_H;
    }
    return 0;
}

std::optional<uint16_t> UI::UpdateHoverEntityType(const SDL_FPoint& mouse)
{
    for (uint8_t i = 0; i < NUM_ENTITY_TYPES; i++)
        if (SDL_PointInRectFloat(&mouse, &entity_type_select_rects[i]))
        {
            hover_list_item = i;
            return i;
        }
    return std::nullopt;
}

std::optional<uint16_t> UI::UpdateHoverEntity(const SDL_FPoint& mouse)
{
    SDL_FRect rect = entity_rect_base;
    for (uint8_t i = 0; i < DISPLAYED_ENTITY_COUNT; i++)
    {
        if (SDL_PointInRectFloat(&mouse, &rect))
        {
            hover_list_item = i;
            return i;
        }
        rect.y += LIST_ITEM_H;
    }
    return std::nullopt;
}

std::optional<UIArea> UI::CheckMouseInUIArea(const SDL_FPoint& mouse)
{
    for (uint8_t i = 0; i < UI_AREA_COUNT; i++)
    {
        if (SDL_PointInRectFloat(&mouse, &hover_rects[i]))
        {
            hover_rect = i;
            return (UIArea)i;
        }
    }

    hover_rect = (uint8_t)UIArea::NONE;
    return std::nullopt;
}

std::optional<uint16_t> UI::DeleteImage(const SDL_FPoint& mouse)
{
    for (uint8_t i = 0; i < DISPLAYED_IMAGE_COUNT; i++)
    {
        if (SDL_PointInRectFloat(&mouse, &delete_rects[i]))
        {
            return offset_image + i;
        }
    }
    return std::nullopt;
}


UI::~UI()
{
}
