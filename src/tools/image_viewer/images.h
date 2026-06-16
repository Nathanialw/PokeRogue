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
    std::string  default_image_path;


    int16_t GetImageIndex();
    int16_t CheckForSetImage(std::string folderPath, std::string image_path_used, uint16_t id);
    void ClearEntities();
    void ClearImages();
public:
    int16_t used_image_index;
    uint16_t image_count;
    std::string  used_image_path;
    std::vector<std::string> entity_list;
    std::vector<std::string> images;
    std::string GetFolderPath();
    ImageData();
    bool Init();
    EntityTypes GetType();
    uint16_t GetEntityCount();
    uint16_t GetImageCount();
    uint16_t GetSelectedEntity(const uint16_t& entity_num);
    bool UpdateSetImageEntity();
    bool RemoveImagePath(uint16_t n);
    void DeleteImage(uint16_t n);
    bool UpdateType(EntityTypes type);
    bool UpdateEntity(uint16_t n);
    bool UpdateImage(uint16_t n);
};
