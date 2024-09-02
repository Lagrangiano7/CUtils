/* Similar to strlen defined in string.h but more memory efficient, using the least memory possible.
If the string is longer than 127 characters, then you can use LongStrlen */

#ifndef _STRLEN_H
#define _STRLEN_H 1

#include <stdint.h> 

// Use only for small strings (127 characters max)
uint8_t Strlen(const char* str){
    uint8_t count = 0;
    while(*str++) count++;
    return count;
}

uint16_t LongStrlen(char* str){
    uint16_t count = 0;
    while(*str++) count++;
    return count;
}

#endif