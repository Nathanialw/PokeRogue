//
// Created by nathanial on 2/24/26.
//
#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "types.h"


uint16_t* MainMenuTilePtr(uint16_t tile_id);
bool OpenSubMenu(void);
bool MenuBack(void);
const char* GetMenuLine(uint8_t idx);
uint8_t GetSelectorY(void);
uint8_t GetSelectorX(void);
bool SetMenuDelta(Delta delta);
uint16_t ListSize(uint16_t n);

bool ToggleMenu(SubMainMenuWindow menuWin, uint8_t numMenuOptions);
bool HandleMenuOverflow(Delta delta);
bool Back(SubMainMenuWindow menuWin);
void ClearMenu(void);

bool ListJump();
void FillListByEntityID(uint8_t n, uint8_t type, const uint8_t* e_ids);
void FillListByTypeID(uint8_t n, const SmallStringArray* text, uint8_t* ids);
