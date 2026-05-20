//
// Created by nathanial on 5/14/26.
//
#pragma once


#if defined(CARTRIDGE_CODE)
#define SET_MEMORY(fmt) __attribute__((section(fmt), used, aligned(4)))
#elif defined(CARTRIDGE_DATA)
#define SET_MEMORY(fmt) __attribute__((section(fmt), used, aligned(4)))
#else
#define SET_MEMORY(fmt)
#endif

