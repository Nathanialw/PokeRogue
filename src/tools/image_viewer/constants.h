//
// Created by nathanial on 5/31/26.
//

#pragma once
#include <string>

#define SCREEN_W 640
#define SCREEN_H 640
#define IMAGE_SIZE_COUNT 6
#define DISPLAYED_IMAGE_COUNT 10
#define DISPLAYED_ENTITY_COUNT 80

#define BTN_W 128
#define BTN_H 40
#define ICON_W 64
#define ICON_H 64
#define SCROLL_BAR_W 16
#define OFFSET (128 - SCROLL_BAR_W)
#define LIST_ITEM_W (128 - SCROLL_BAR_W)
#define LIST_ITEM_H 16

enum EntityTypes
{
    CREATURE,
    OBJECT,
    ITEM,
    TRAINER,
    SPELL,
    SKILL,
    TILE,
    NUM_ENTITY_TYPES,
};


const std::string src_dir = "src/tools/image_viewer/";
const std::string db_path = "scripts/game_data.db";
const std::string font_file = "assets/font.ttf";
const std::string image_tables[NUM_ENTITY_TYPES] =
{
    "creatures",
    "objects",
    "items",
    "trainers",
    "spells",
    "skills",
    "tiles",
};


// const std::string raw_image_path = "assets_raw/sprites";
const std::string entity_images_path[NUM_ENTITY_TYPES] =
{
    "assets_raw/sprites/creature/",
    "assets_raw/sprites/object/",
    "assets_raw/sprites/item/",
    "assets_raw/sprites/trainer/",
    "assets_raw/sprites/spell/",
    "assets_raw/sprites/skill/",
    "assets_raw/sprites/tile/",
};
