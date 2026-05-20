//
// Created by nathanial on 5/19/26.
//

#include "map_utils.h"
#include "lib_memory.h"

#include "types.h"



/**********************************************************************************************************************/
/** STRING MANIPULATION
**********************************************************************************************************************/
bool IsHyphenationPoint(HardwareInterface hardware, const char* word, uint8_t pos, uint8_t word_len);


/**********************************************************************************************************************/
/** Checks whether tx, ty is with the range of x,y
 *  ON SUCCESS - returns true
 *  ON FAIL - returns false
**********************************************************************************************************************/
SET_MEMORY(".map")
bool WithinRange(uint8_t x, uint8_t y, uint8_t tx, uint8_t ty, uint8_t range)
{
    if (tx >= x - range && tx < (x + range) && ty >= y - range && ty < (y + range))
        return true;
    return false;
}


/**********************************************************************************************************************/
/** handles line breaks on:
 *      -double letter pattern words
 *      -syllable
**********************************************************************************************************************/
SET_MEMORY(".map")
bool IsHyphenationPoint(HardwareInterface hardware, const char* word, uint8_t pos, uint8_t word_len)
{
    // Don't hyphenate at beginning or end
    if (pos < 2 || pos > word_len - 2) return false;

    // Simple rule: hyphenate between double consonants or after prefix
    char c1 = word[pos - 1];
    char c2 = word[pos];
    char c3 = word[pos + 1];

    // Common consonant pairs
    if ((c1 == 'b' && c2 == 'b') || (c1 == 'd' && c2 == 'd') ||
        (c1 == 'l' && c2 == 'l') || (c1 == 'm' && c2 == 'm') ||
        (c1 == 'n' && c2 == 'n') || (c1 == 'p' && c2 == 'p') ||
        (c1 == 'r' && c2 == 'r') || (c1 == 's' && c2 == 's') ||
        (c1 == 't' && c2 == 't'))
    {
        return true;
    }

    // Vowel-consonant patterns (very simplified)
    char vowels[] = "aeiou";
    bool is_vowel_c1 = (hardware.StrChr(vowels, c1) != NULL);
    bool is_vowel_c2 = (hardware.StrChr(vowels, c2) != NULL);

    // Vowel followed by consonant is often a syllable break
    if (is_vowel_c1 && !is_vowel_c2 && pos < word_len - 2)
    {
        // Check if next is vowel (makes it a good break)
        bool is_vowel_c3 = (hardware.StrChr(vowels, c3) != NULL);
        if (is_vowel_c3) return true;
    }

    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SortEntityArray(EntityId* sorted, EntityId* unsorted, uint8_t n)
{
    // Copy unsorted to sorted first
    for (uint8_t i = 0; i < n; i++)
    {
        sorted[i] = unsorted[i];
    }

    // Selection sort
    for (uint8_t i = 0; i < n - 1; i++)
    {
        uint8_t min_idx = i;
        for (uint8_t j = i + 1; j < n; j++)
        {
            if (sorted[j] < sorted[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap if needed
        if (min_idx != i)
        {
            EntityId temp = sorted[i];
            sorted[i] = sorted[min_idx];
            sorted[min_idx] = temp;
        }
    }

    return true;
}
