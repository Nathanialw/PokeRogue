//
// Created by nathanial on 5/31/26.
//

#pragma once

#include <SDL3/SDL.h>

#include "images.h"
#include "text.h"
#include "ui.h"

class Renderer
{
public:
    Renderer() = default;
    ~Renderer();

    // Disable copying
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    bool Init(const char* title, int width, int height);
    void Shutdown();
    void CreateTextures(ImageData& images);
    void DeleteTexture(ImageData& images, const uint16_t& n);
    void Render(UI& ui, Text& text, const uint16_t& entity_count, const uint16_t& image_count);

    SDL_Renderer* GetSDLRenderer() const { return m_renderer; }

private:
    void ClearTextures();

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;

    SDL_Texture* delete_texture = nullptr;
    SDL_Texture* accept_texture = nullptr;
    std::vector<SDL_Texture*> m_textures;

    SDL_FRect rects[IMAGE_SIZE_COUNT];
};
