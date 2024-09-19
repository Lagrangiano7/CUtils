#ifndef _STRLIST_H
#define _STRLIST_H 1

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../string/Strcmp.h"

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

char* popFromStrList(StrList *list){
    char* lastVal = list->elems[list->size-1];
    list->elems[list->size-1]="";
    list->size--;
    return lastVal;
}

/* PRINTING UTILITIES */
void printStrList(StrList l){
    printf("[ ");
    for(int i = 0; i < l.size-1; i++) printf("%s, ", l.elems[i]);
    printf("%s ]\n", l.elems[l.size-1]);
}

/* FINDING UTILITIES */
IntList ReverseFindStrList(StrList l, const char* elem){
    // Find indexes of all instances of element in IntList
    IntList indexes = makeIntList();
    for(int i = 0; i < l.size; i++){
        if(Strcmp(l.elems[i], elem)) appendToIntList(&indexes, i);
    }
    
    return indexes;
    
}

#endif