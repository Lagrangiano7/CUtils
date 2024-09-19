#ifndef _COUNT_CHAR_1
#define _COUNT_CHAR_1 1

int CountChar(const char* str, char c){
    int count = 0;
    while(*str){
        if(*str++==c) count++;
    }

    return count;
}

#endif