//
// Created by nathanial on 5/31/26.
//

#pragma once
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <constants.h>
#include <vector>


struct TextTexture
{
    SDL_Texture* texture;
    SDL_FRect rect;
};


class Text
{
    TTF_Font* font = nullptr;

    TextTexture CreateTextTexture(SDL_Renderer* renderer, const std::string &text);
    void ClearTextTextures();
public:
    SDL_Texture* entity_types[NUM_ENTITY_TYPES] = {nullptr};
    SDL_FRect entity_types_boxes[NUM_ENTITY_TYPES];
    std::vector<SDL_Texture*> list_items;
    std::vector<SDL_FRect> list_boxes;
    void InitText(SDL_Renderer* renderer);
    void PopulateTextTextures(SDL_Renderer* renderer, const std::vector<std::string>& text_array);
};
