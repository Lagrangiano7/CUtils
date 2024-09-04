#ifndef _DOUBLELIST_H
#define _DOUBLELIST_H 1

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    double* elems;
} DoubleList;

DoubleList makeDoubleList(){
    DoubleList list = {-1, (double*)malloc(sizeof(double))};
    return list;
}

/* ADDING TO LIST (SETTERS) */

void setToDoubleList(DoubleList *list, uint8_t index, double val){
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

void appendToDoubleList(DoubleList *list, double val){
    if(list->size==-1){
        list->elems[0]=val;
        list->size=1;
        return;
    }
    // Optimize memory efficiency by increasing size of elems one by one, thus losing execution speed at runtime
    list->size++;
    list->elems = (double*)realloc(list->elems, sizeof(double)*(list->size+1));
    list->elems[list->size-1]=val;
}

/* GET FROM LIST (GETTERS) */

double getFromDoubleList(DoubleList list, uint8_t index){
    if (index > list.size -1){
        puts("Error: index out of range");
        return -1;
    }
    return list.elems[index];
}

double popFromDoubleList(DoubleList *list) {
    double lastVal = list->elems[list->size-1];
    list->elems = (double*)realloc(list->elems, sizeof(double)*(list->size-1));
    list->size--;
    return lastVal;
}

/* PRINTING UTILITIES */
void printDoubleList(DoubleList l){
    printf("[ ");
    for(int i = 0; i < l.size; i++) printf("%f ", l.elems[i]);
    printf("]");
}

#endif