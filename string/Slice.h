#ifndef _SUBSTR_H
#define _SUBSTR_H 1

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

const char* Slice(const char* str, uint8_t start, uint8_t end){
    const char* tmp = str;
    uint8_t ind = start; // For max memory usage, we could use the very variable "start" as index, but the code would be more confusing

    char substr[end-start+1];
    char* substr_ptr = (char*)malloc(end-start+1);

    // Go to start
    str+=start;

    while(ind <= end){
        substr[ind-start]=*str;
        ind++;
        str++;
    }

    strcpy(substr_ptr, substr);
    return substr_ptr;
}

#endif