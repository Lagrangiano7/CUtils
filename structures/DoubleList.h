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
    printf("]\n");
}

/* SORTING UTILITIES */

int compareDoubles(const void* a, const void* b) {
    return (*(double*)a - *(double*)b);
}

void SortDoubleList(DoubleList *l){
    qsort(l->elems, l->size, sizeof(double), compareDoubles);
}

/* FINDING UTILITIES */
IntList ReverseFindDoubleList(DoubleList l, double elem){
    // Find indexes of all instances of element in IntList
    IntList indexes = makeIntList();
    for(int i = 0; i < l.size; i++){
        if(l.elems[i]==elem) appendToIntList(&indexes, i);
    }
    
    return indexes;
    
}

/* ARITHMETIC UTILITIES */

// DoubleList addition: return type is IntList instead of void because, otherwise, we would have to overwrite either one of the two lists. We would be deliberately losing information without the need of it
DoubleList addDoubleLists(DoubleList l1, DoubleList l2){
    DoubleList temp = makeDoubleList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be added");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToDoubleList(&temp, l1.elems[i]+l2.elems[i]);
    }

    return temp;
    
}

DoubleList subtractDoubleLists(DoubleList l1, DoubleList l2){
    DoubleList temp = makeDoubleList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be subtracted");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToDoubleList(&temp, l1.elems[i]-l2.elems[i]);
    }

    return temp;
    
}

DoubleList multiplyDoubleLists(DoubleList l1, DoubleList l2){
    DoubleList temp = makeDoubleList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be multiplied");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToDoubleList(&temp, l1.elems[i]*l2.elems[i]);
    }

    return temp;
    
}

#endif