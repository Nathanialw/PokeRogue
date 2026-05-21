//
// Created by nathanial on 5/20/26.
//

#include "debug.h"

#include <stdarg.h>
#include <stdio.h>


//TODO:
void PrintVar(uint32_t d)
{

    printf("0x%4x %d\n", d, d);
    // DEBUG("CART");
    // sleep_ms(10);
}

//TODO:
void Print(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args); // Print formatted message
    va_end(args);
}
