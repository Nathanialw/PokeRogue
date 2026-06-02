//
// Created by nathanial on 5/31/26.
//

#include "rendering.h"
#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "images.h"
#include <filesystem>

#include "text.h"
#include "ui.h"
namespace fs = std::filesystem;

bool Renderer::Init(const char* title, int width, int height)
{
    // Initialize SDL video subsystem
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window and renderer (SDL3 API)
    if (!SDL_CreateWindowAndRenderer(title, width, height, 0, &m_window, &m_renderer))
    {
        std::cerr << "Window/Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    rects[0] = {128.0f, 40.0f, 128.0f, 128.0f};
    rects[1] = {128.0f, 40.0f, 64.0f, 64.0f};
    rects[2] = {128.0f, 40.0f, 32.0f, 32.0f};
    rects[3] = {128.0f, 40.0f, 24.0f, 24.0f};
    rects[4] = {128.0f, 40.0f, 20.0f, 20.0f};
    rects[5] = {128.0f, 40.0f, 16.0f, 16.0f};

    std::string acc = src_dir + "assets/accept.png";
    std::string del = src_dir + "assets/delete.png";
    accept_texture = IMG_LoadTexture(m_renderer, acc.c_str());
    delete_texture = IMG_LoadTexture(m_renderer, del.c_str());

    // Optional: set render draw color (default is black)
    SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 255);
    return true;
}

void Renderer::Shutdown()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
}

void Renderer::CreateTextures(ImageData& images)
{
    ClearTextures();
    std::string folderPath = images.GetFolderPath();
    images.image_count = 0;
    images.images.clear();

    try
    {
        // 3. Iterate over all entries in the folder
        for (const auto& entry : fs::directory_iterator(folderPath))
        {
            // Get filename (including path) as a string
            std::string filename = entry.path().string();
            // Optionally check if it's a regular file
            if (entry.is_regular_file())
            {
                SDL_Texture* texture = IMG_LoadTexture(m_renderer, filename.c_str());
                m_textures.push_back(texture);
                images.image_count++;
                images.images.push_back(filename.c_str());
            }
            else if (entry.is_directory())
            {
                std::cout << " DIR: " << filename << '\n';
            }
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what() << '\n';
    }
}

void Renderer::DeleteTexture(ImageData& images, const uint16_t& n)
{
    std::string filepath = images.images[n];
    printf("Deleting file: %s\n", filepath.c_str());
    if (std::filesystem::exists(filepath))
        std::filesystem::remove(filepath);

    SDL_DestroyTexture(m_textures[n]);
    m_textures.erase(m_textures.begin() + n);
    images.images.erase(images.images.begin() + n);
    images.image_count--;
}


void Renderer::Render(UI& ui, Text& text, const uint16_t& entity_count, const uint16_t& image_count)
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    uint16_t count = (DISPLAYED_IMAGE_COUNT < image_count) ? DISPLAYED_IMAGE_COUNT : image_count;
    count += ui.offset_image;
    if (count > image_count) count = image_count;
    for (uint16_t j = ui.offset_image; j < count; j++)
    {
        for (uint8_t i = 0; i < IMAGE_SIZE_COUNT; i++)
        {
            if (i < IMAGE_SIZE_COUNT)
                rects[i + 1].x = (rects[i].w + rects[i].x);
            SDL_RenderTexture(m_renderer, m_textures[j], NULL, &rects[i]);
        }
        SDL_RenderTexture(m_renderer, accept_texture, NULL, &ui.accept_rects[j - ui.offset_image]);
        SDL_RenderTexture(m_renderer, delete_texture, NULL, &ui.delete_rects[j - ui.offset_image]);

        for (auto& rect : rects)
        {
            rect.x = BTN_W;
            rect.y += rects[0].h;
        }
    }

    for (auto& rect : rects)
    {
        rect.x = BTN_W;
        rect.y = BTN_H;
    }


    count = (DISPLAYED_ENTITY_COUNT < entity_count) ? DISPLAYED_ENTITY_COUNT : entity_count;
    count += ui.offset_entity_id;
    if (count > entity_count) count = entity_count;
    for (uint16_t i = ui.offset_entity_id; i < count; i++)
    {
        SDL_FRect rect = ui.entity_rect_base;
        rect.y = ui.entity_rect_base.y + (rect.h * (i - ui.offset_entity_id));
        if ((ui.selected_list_item) == (i)) SDL_SetRenderDrawColor(m_renderer, 200, 200, 230, 255);
        else SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(m_renderer, &rect);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
        SDL_RenderRect(m_renderer, &rect);
        rect.w = text.list_boxes[i].w;
        rect.h = text.list_boxes[i].h;
        SDL_RenderTexture(m_renderer, text.list_items[i], NULL, &rect);
    }

    for (uint16_t i = 0; i < NUM_ENTITY_TYPES; i++)
    {
        SDL_FRect rect = ui.entity_type_select_rects[i];
        if (ui.selected_entity_type == i) SDL_SetRenderDrawColor(m_renderer, 200, 200, 230, 255);
        else SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(m_renderer, &rect);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
        SDL_RenderRect(m_renderer, &rect);
        rect.w = text.entity_types_boxes[i].w;
        rect.h = text.entity_types_boxes[i].h;
        SDL_RenderTexture(m_renderer, text.entity_types[i], NULL, &rect);
    }


    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::SCROLL_BAR_MAIN]);
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
    SDL_RenderRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::SCROLL_BAR_MAIN]);


    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::SCROLL_BAR_LEFT]);
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
    SDL_RenderRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::SCROLL_BAR_LEFT]);


    SDL_SetRenderDrawColor(m_renderer, 155, 123, 215, 255);
    if (ui.selected_entity_type == CREATURE)
    {
        SDL_RenderFillRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
        SDL_RenderRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
    }
    else if (ui.selected_entity_type == TILE)
    {
        SDL_RenderFillRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
        SDL_RenderRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
    }
    else
    {
        SDL_RenderFillRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 255);
        SDL_RenderRect(m_renderer, &ui.hover_rects[(uint8_t)UIArea::RIGHT]);
    }

    SDL_RenderPresent(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}

void Renderer::ClearTextures()
{
    for (auto& texture : m_textures)
    {
        SDL_DestroyTexture(texture);
    }
    m_textures.clear();
}

Renderer::~Renderer()
{
    Shutdown(); // Ensure cleanup even if not called explicitly
}
