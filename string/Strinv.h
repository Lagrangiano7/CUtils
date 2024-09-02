/* This file's code is taken from https://www.geeksforgeeks.org/how-to-reverse-a-string-in-c/ */

#ifndef _STRINV_H
#define _STRINV_H 1

#include "Strlen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Strinv(char* str_ptr){

    char str[Strlen(str_ptr)];
    strcpy(str, str_ptr);

    char* start = str;

    char* end = str + strlen(str) - 1;

    // Reverse the string
    while (start < end) {

        // perform swap
        char temp = *start;
        *start = *end;
        *end = temp;
        // increment start
        start++;
        // decrement end
        end--;
    }

    // Print the reversed string
    char* rev = (char*)malloc(strlen(str)*sizeof(char));
    strcpy(rev, str);
    return rev;
}

#endif