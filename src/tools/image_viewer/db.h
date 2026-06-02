//
// Created by nathanial on 5/31/26.
//

#pragma once

#include <string>
#include <vector>

#include "constants.h"


/*  Reads the DB for the given entity type
 *  fills the image folders vector with the names of the image folders
 */
int GetImageFolders(std::vector<std::string>& image_folders, uint16_t& entity_count, const EntityTypes& entity_type);
