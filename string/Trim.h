#ifndef _TRIMLEFT_H
#define _TRIMLEFT_H 1

#include "Strinv.h"

//  Returns left-trimmed string
const char* TrimLeft(const char* str) {
    while(*str==' ') str++;
    return str;
}

const char* TrimRight(const char* str) {
    return Strinv(TrimLeft(Strinv(str)));
}

const char* Trim(const char* str){
    return TrimLeft(TrimRight(str));
}


#endif