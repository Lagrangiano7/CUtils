/* Similar to strcmp defined in string.h but more comprehensive. Returns 0 if strings are not the same and 1 if they are.
Boolean logic is applied to simplify if statements, where there is no longer need to use the == operator */

#ifndef _STRCMP_H
#define _STRCMP_H 1

#include <stdint.h>
#include "Strlen.h"

uint8_t Strcmp(const char* str1, const char* str2){
    if (Strlen(str1) != Strlen(str2)) return 0;
    while(*str1){
        if (*str1++ != *str2++) return 0;
    }

    return 1;
}

#endif