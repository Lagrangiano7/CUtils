#ifndef _INTLIST_H
#define _INTLIST_H 1

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int* elems;
} IntList;

IntList makeIntList(){
    IntList list = {-1, (int*)malloc(sizeof(int))};
    return list;
}

/* ADDING TO LIST (SETTERS) */

void setToIntList(IntList *list, uint8_t index, int val){
    if(list->size==-1){
        list->elems[0]=val;
        list->size=1;
        return;
    }
    if (index > list->size) {
        puts("Error: index out of range");
        return;
    }
    list->elems[index]=val;

}

void appendToIntList(IntList *list, int val){
    if(list->size==-1){
        list->elems[0]=val;
        list->size=1;
        return;
    }
    // Optimize memory efficiency by increasing size of elems one by one, thus losing execution speed at runtime
    list->size++;
    list->elems = (int*)realloc(list->elems, sizeof(int)*(list->size+1));
    list->elems[list->size-1]=val;
}

/* GET FROM LIST (GETTERS) */

int getFromIntList(IntList list, uint8_t index){
    if (index > list.size -1){
        puts("Error: index out of range");
        return -1;
    }
    return list.elems[index];
}

int popFromIntList(IntList *list) {
    int lastVal = list->elems[list->size-1];
    list->elems = (int*)realloc(list->elems, sizeof(int)*(list->size-1));
    list->size--;
    return lastVal;
}

/* PRINTING UTILITIES */
void printIntList(IntList l){
    printf("[ ");
    for(int i = 0; i < l.size; i++) printf("%d ", l.elems[i]);
    printf("]\n");
}

/* SORTING UTILITIES */

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void SortIntList(IntList *l){
    qsort(l->elems, l->size, sizeof(int), compareInts);
}

#endif