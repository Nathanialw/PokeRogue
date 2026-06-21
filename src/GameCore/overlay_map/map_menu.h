//
// Created by nathanial on 3/8/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"


void InitMainMenu(void);
bool OpenSubMenu(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory);
void HandleMenu(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, AudioInterface audio);

void OpenUseOnSpellPage(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f);

void OpenUseOnParty(HardwareInterface hardware, MemoryInterface memory, UseFrameBack f);
void BackUseOnParty(MemoryInterface memory);

bool MenuActions_R(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory);