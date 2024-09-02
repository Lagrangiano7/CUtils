#ifndef _STRLIST_H
#define _STRLIST_H 1

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t size;
    char* elems[127];
} StrList;

StrList makeStrList(){
    StrList list = {1, {}};
    return list;
}

void appendToStrList(StrList *list, char* str){
    if(list->elems[0]==NULL){
        list->elems[0]=str;
        return;
    }

    list->elems[list->size] = str;
    list->size++;
}

void setToStrList(StrList *list, uint8_t index, char* val){

    if (index > 127){
        printf("Error: due to memory constraints, StrList can only store up to 127 strings");
    }

    if(list->elems[index] == NULL) list->size++;
    list->elems[index] = val;
}

char* getFromStrList(StrList list, int index){
    return list.elems[index];
}

#endif