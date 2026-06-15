//
// Created by nathanial on 5/31/26.
//

#include "images.h"

#include "db.h"


#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;


ImageData::ImageData()
{
    entity_type = CREATURE;
    entity_id = 0;
    entity_count = 0;
    image_count = 0;
    used_image_path = "";
    default_image_path = "assets_raw/sprites/default/default.jpg";
}

bool ImageData::Init()
{
    if (GetImageFolders(entity_list, entity_count, entity_type) != 0)
        return false;
    return true;
}

EntityTypes ImageData::GetType()
{
    return entity_type;
}

uint16_t ImageData::GetEntityCount()
{
    return entity_count;
}

uint16_t ImageData::GetImageCount()
{
    return image_count;
}

uint16_t ImageData::GetSelectedEntity(const uint16_t& entity_num)
{
    if (entity_num > entity_count) return entity_num;
    return entity_id;
}

void ImageData::DeleteImage(uint16_t n)
{
    // image_names.erase(image_names.begin() + n);}
}

void ImageData::ClearEntities()
{
    entity_list.clear();
}

void ImageData::ClearImages()
{
    images.clear();
}

bool ImageData::CheckForSetImage(std::string folderPath, std::string image_path_used, uint16_t id)
{
    bool exists = false;

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
                if (image_path_used == filename)
                {
                    exists = true;
                    break;
                }
            }
            else if (entry.is_directory())
            {
                std::cout << " DIR: " << filename << '\n';
                std::cout << " DIR: " << filename << '\n';
            }
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what() << '\n';
    }

    if (!exists)
    {
        std::cout << " NO IMAGE SET for " << entity_list[id] << '\n';
    }

    return exists;
}

std::string ImageData::GetFolderPath()
{
    used_image_path = GetImagePath(entity_list[entity_id], entity_type);
    std::string folderPath = entity_images_path[entity_type] + entity_list[entity_id];
    bool exists = false;

    if (used_image_path != default_image_path)
    {
        if (!used_image_path.empty())
        {
            exists = CheckForSetImage(folderPath, used_image_path, entity_id);
        }

        if (used_image_path.empty() || !exists)
        {
            used_image_path = default_image_path;
            UpdateImagePath(used_image_path, entity_list[entity_id], entity_type);
        }
    }


    if (used_image_path == default_image_path)
        std::cout << " NO IMAGE SET for " << entity_list[entity_id] << '\n';


    return folderPath;
}

bool ImageData::UpdateType(EntityTypes type)
{
    entity_id = 0;
    entity_type = type;
    entity_count = 0;
    ClearEntities();
    ClearImages();


    if (GetImageFolders(entity_list, entity_count, entity_type) != 0)
        return false;

    for (uint16_t i = 0; i < entity_count; i++)
    {
        std::string folderPath = entity_images_path[entity_type] + entity_list[i];
        std::string image_path_used = GetImagePath(entity_list[i], entity_type);

        if (!CheckForSetImage(folderPath, image_path_used, i))
        {
            UpdateImagePath(default_image_path, entity_list[i], entity_type);
        }
    }


    return true;
}

bool ImageData::UpdateEntity(uint16_t n)
{
    entity_id = n;
    return true;
}

bool ImageData::UpdateImage(uint16_t n)
{
    auto& image_path = images[n];
    UpdateImagePath(image_path, entity_list[entity_id], entity_type);
    used_image_path = image_path;
    printf("Updated image path: %s\n", image_path.c_str());
    return true;
}


bool ImageData::RemoveImagePath(uint16_t n)
{
    if (used_image_path == images[n])
    {
        UpdateImagePath(default_image_path, entity_list[entity_id], entity_type);
        used_image_path = default_image_path;
    }
    return true;
}
