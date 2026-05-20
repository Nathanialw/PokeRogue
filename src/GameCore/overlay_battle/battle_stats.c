//
// Created by nathanial on 5/19/26.
//

#include "battle_stats.h"
#include "lib_memory.h"

#include "core_utils.h"


/**********************************************************************************************************************/
/** modifies a char array with the formatted values of "min/max" of a resource
**********************************************************************************************************************/
SET_MEMORY(".battle")
void GetStatLine(HardwareInterface hardware, uint16_t cur, uint16_t max, uint8_t max_chars, char* dest, const StatusPrefix prefix)
{
    memset(dest, '\0', max_chars);

    for (int i = 0; i < 3 && prefix[i]; i++)
    {
        dest[i] = prefix[i];
    }

    CharStr_max999 hp_str;
    GetAsChars_Max999(cur, &hp_str);

    CharStr_max999 max_hp_str;
    GetAsChars_Max999(max, &max_hp_str);

    uint8_t i = 0;
    uint8_t j = 3;
    bool prepend_zeroes = false;
    while (i < 3)
    {
        char c = hp_str[i];
        if (c == '0' && !prepend_zeroes)
        {
            dest[j] = ' ';
        }
        else
        {
            prepend_zeroes = true;
            dest[j] = c;
        }

        i++;
        j++;
    }

    dest[6] = '/';

    i = 0;
    j = 7;
    prepend_zeroes = false;
    while (i < 3)
    {
        char c = max_hp_str[i];
        if (c == '0' && !prepend_zeroes)
        {
        }
        else
        {
            prepend_zeroes = true;
            dest[j] = c;
            j++;
        }
        i++;
    }
}
