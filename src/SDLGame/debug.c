//
// Created by nathanial on 5/20/26.
//

#include "debug.h"

#include <stdarg.h>

#include "lib_debugging.h"


//TODO:
void PrintVar(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args); // Print formatted message
    va_end(args);
}

//TODO:
void Print(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args); // Print formatted message
    va_end(args);
}
