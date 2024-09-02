#ifndef _TRIMLEFT_H
#define _TRIMLEFT_H 1

#include "Strinv.h"

//  Returns left-trimmed string
char* TrimLeft(char* str) {
    while(*str==' ') str++;
    return str;
}

char* TrimRight(char* str) {
    return Strinv(TrimLeft(Strinv(str)));
}

char* Trim(char* str){
    return TrimLeft(TrimRight(str));
}


#endif