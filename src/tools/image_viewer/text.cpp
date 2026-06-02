//
// Created by nathanial on 5/31/26.
//

#include "text.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_log.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "constants.h"


void Text::InitText(SDL_Renderer* renderer)
{
    TTF_Init();
    std::string fontPath = src_dir + font_file;
    font = TTF_OpenFont(fontPath.c_str(), 12);
    if (!font)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_OpenFont: %s", SDL_GetError());
    }

    for (int i = 0; i < NUM_ENTITY_TYPES; i++)
    {
        TextTexture texture_item = CreateTextTexture(renderer, image_tables[i].c_str());
        entity_types[i] = (texture_item.texture);
        entity_types_boxes[i] = (texture_item.rect);
    }
}

TextTexture Text::CreateTextTexture(SDL_Renderer* renderer, const std::string& text)

{
    SDL_Color black = {0, 0, 0, 255};
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), 0, black);
    if (!textSurface)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_RenderText: %s", SDL_GetError());
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FRect rect = {0.0f, 0.0f, (float)textSurface->w, (float)textSurface->h};
    TextTexture texture_item;
    texture_item.texture = texture;
    texture_item.rect = rect;

    SDL_DestroySurface(textSurface);
    if (!texture)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateTextureFromSurface: %s", SDL_GetError());
    }

    return texture_item;
}


void Text::ClearTextTextures()
{
    for (const auto& item : list_items)
    {
        SDL_DestroyTexture(item);
    }
    list_items.clear();
    list_boxes.clear();
}

void Text::PopulateTextTextures(SDL_Renderer* renderer, const std::vector<std::string>& text_array)
{
    ClearTextTextures();

    for (const auto& text : text_array)
    {
        TextTexture texture_item = CreateTextTexture(renderer, text);
        list_items.push_back(texture_item.texture);
        list_boxes.push_back(texture_item.rect);
    }
}
