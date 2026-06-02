//
// Created by nathanial on 5/31/26.
//
#pragma once
#include <vector>
#include <string>

#include "constants.h"

/*  Stores:
 *      the image folder names
 *      the image file names
 *      current entity type
 *
 *
 */
class ImageData
{
    EntityTypes entity_type;
    uint16_t entity_id;
    uint16_t entity_count;

    void ClearEntities();
    void ClearImages();
public:
    uint16_t image_count;
    std::vector<std::string> entity_list;
    std::vector<std::string> images;
    std::string GetFolderPath();
    ImageData();
    bool Init();
    EntityTypes GetType();
    uint16_t GetEntityCount();
    uint16_t GetImageCount();
    uint16_t GetSelectedEntity(const uint16_t& entity_num);
    void DeleteImage(uint16_t n);
    bool UpdateType(EntityTypes type);
    bool UpdateEntity(uint16_t n);
};
