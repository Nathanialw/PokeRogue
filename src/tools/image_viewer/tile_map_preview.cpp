//
// Created by nathanial on 6/1/26.
//

#include "tile_map_preview.h"

#include <vector>
#include <string>
#include <SDL3/SDL_render.h>

TileMapPreview::TileMapPreview()
{
}

TileMapPreview::~TileMapPreview()
{
}

void TileMapPreview::LoadTiles()
{
}

void TileMapPreview::UpadateTiles()
{
}

void TileMapPreview::Draw(SDL_Renderer* renderer, std::vector<std::string> tile_map)
{
    float size = 16.0f;
    SDL_FRect rect = {0.0f, 0.0f, size, size};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            SDL_RenderTexture(renderer, tiles[map[j][i]], NULL, &rect);
            rect.x += size;
        }
        rect.x = 0.0f;
        rect.y += size;
    }
}
