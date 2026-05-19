//
// Created by nathanial on 5/19/26.
//


#include "types.h"

/**********************************************************************************************************************/
/** FUNCTIONS
**********************************************************************************************************************/
bool WithinRange(uint8_t x, uint8_t y, uint8_t tx, uint8_t ty, uint8_t range);
bool SortEntityArray(EntityId* sorted, EntityId* unsorted, uint8_t n);
bool IsHyphenationPoint(HardwareInterface hardware, const char* word, uint8_t pos, uint8_t word_len);