//
// Created by nathanial on 5/31/26.
//

#pragma once
#include <SDL3/SDL_rect.h>
#include <optional>
#include <constants.h>

enum class UIArea
{
    TOP,
    LEFT,
    MAIN,
    RIGHT,
    SCROLL_BAR_LEFT,
    SCROLL_BAR_MAIN,
    NONE,
};

#define UI_AREA_COUNT (uint8_t)UIArea::NONE


class UI
{
public:
    UI() = default;
    ~UI();

    void Init();
    std::optional<SDL_FRect> GetHoverRect();
    std::optional<EntityTypes> UpdateSelectedEntityType(const SDL_FPoint& mouse);
    uint16_t UpdateSelectedEntity(const SDL_FPoint& mouse);
    std::optional<uint16_t> UpdateHoverEntityType(const SDL_FPoint& mouse);
    std::optional<uint16_t> UpdateHoverEntity(const SDL_FPoint& mouse);
    std::optional<UIArea> CheckMouseInUIArea(const SDL_FPoint& mouse);
    std::optional<uint16_t> DeleteImage(const SDL_FPoint& mouse);

    uint16_t hover_rect;
    uint16_t hover_list_item;
    uint16_t selected_list_item;
    uint16_t selected_entity_type;
    uint16_t offset_entity_id;
    uint16_t offset_image;
    SDL_FRect accept_rects[DISPLAYED_IMAGE_COUNT];
    SDL_FRect delete_rects[DISPLAYED_IMAGE_COUNT];
    SDL_FRect entity_rect_base;
    SDL_FRect hover_rects[UI_AREA_COUNT] = {};
    SDL_FRect entity_type_select_rects[NUM_ENTITY_TYPES] = {};

private:
    UIArea active_area;
};
