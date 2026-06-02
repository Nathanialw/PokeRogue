//
// Created by nathanial on 5/31/26.
//

#include "images.h"
#include "db.h"


ImageData::ImageData()
{
    entity_type = CREATURE;
    entity_id = 0;
    entity_count = 0;
    image_count = 0;
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
    // image_names.erase(image_names.begin() + n);
}


void ImageData::ClearEntities()
{
    entity_list.clear();
}

void ImageData::ClearImages()
{
    images.clear();
}

std::string ImageData::GetFolderPath()
{
    return entity_images_path[entity_type] + entity_list[entity_id];
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
    return true;
}

bool ImageData::UpdateEntity(uint16_t n)
{
    entity_id = n;
    return true;
}
