//
// Created by nathanial on 2/24/26.
//
#pragma once
#include "types.h"


uint16_t* MainMenuTilePtr(uint16_t tile_id);

bool MenuBack(MemoryInterface memory);
void GetMenuLine(char* text, uint8_t idx);
uint8_t GetSelectorY(void);
uint8_t GetSelectorX(void);
uint16_t ListSize(uint16_t n);

bool SetMenuDelta(InputInterface input, MemoryInterface memory, Delta delta);
bool HandleMenuOverflow(InputInterface input, MemoryInterface memory, Delta delta);

bool ToggleMenu(SubMainMenuWindow menuWin, uint8_t numMenuOptions);
bool Back(SubMainMenuWindow menuWin);
void ClearMenu(void);

bool ListJump(InputInterface input, MemoryInterface memory);
void FillListByEntityID(MemoryInterface memory, uint8_t n, uint8_t type, const uint8_t* e_ids);
void FillListByTypeID(uint8_t n, uint8_t* ids);
