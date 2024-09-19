#ifndef _PRINTLN_H
#define _PRINTLN_H 1

#include <stdarg.h>
#include <stdio.h>
#include "../string/CountChar.h"

void Println(const char* raw, ...){
    // First we count the number of arguments that should be passed --< then we will plug it into va_arg(ptr, n)
    int n = CountChar(raw, '%');

    va_list ptr;
    va_start(ptr, n);

    printf("%s", va_arg(ptr, char*));
    va_end(ptr);

}

#endif