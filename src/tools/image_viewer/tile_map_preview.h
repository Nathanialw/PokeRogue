//
// Created by nathanial on 6/1/26.
//

#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <SDL3/SDL_render.h>


class TileMapPreview
{
private:
    std::uint8_t map[10][10] = {};
    SDL_Texture* tiles[16] = {};

public:
    TileMapPreview();
    ~TileMapPreview();
    void LoadTiles();
    void UpadateTiles();

    void Draw(SDL_Renderer* renderer, std::vector<std::string> tile_map);
};
