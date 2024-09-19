#ifndef _COUNT_CHAR_H
#define _COUNT_CHAR_H 1

int CountChar(const char* str, char c){
    int count = 0;
    while(*str){
        if(*str++==c) count++;
    }

    return count;
}

#endif