#ifndef _FLOATLIST_H
#define _FLOATLIST_H 1

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    float* elems;
} FloatList;

FloatList makeFloatList(){
    FloatList list = {-1, (float*)malloc(sizeof(float))};
    return list;
}

/* ADDING TO LIST (SETTERS) */

void setToFloatList(FloatList *list, uint8_t index, float val){
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

void appendToFloatList(FloatList *list, float val){
    if(list->size==-1){
        list->elems[0]=val;
        list->size=1;
        return;
    }
    // Optimize memory efficiency by increasing size of elems one by one, thus losing execution speed at runtime
    list->size++;
    list->elems = (float*)realloc(list->elems, sizeof(float)*(list->size+1));
    list->elems[list->size-1]=val;
}

/* GET FROM LIST (GETTERS) */

float getFromFloatList(FloatList list, uint8_t index){
    if (index > list.size -1){
        puts("Error: index out of range");
        return -1;
    }
    return list.elems[index];
}

float popFromFloatList(FloatList *list) {
    float lastVal = list->elems[list->size-1];
    list->elems = (float*)realloc(list->elems, sizeof(float)*(list->size-1));
    list->size--;
    return lastVal;
}


/* PRINTING UTILITIES */
void printFloatList(FloatList l){
    printf("[ ");
    for(int i = 0; i < l.size; i++) printf("%f ", l.elems[i]);
    printf("]\n");
}

/* SORTING UTILITIES */

int comparefloats(const void* a, const void* b) {
    return (*(float*)a - *(float*)b);
}

void SortFloatList(FloatList *l){
    qsort(l->elems, l->size, sizeof(float), comparefloats);
}

/* FINDING UTILITIES */
IntList ReverseFindFloatList(FloatList l, float elem){
    // Find indexes of all instances of element in IntList
    IntList indexes = makeIntList();
    for(int i = 0; i < l.size; i++){
        if(l.elems[i]==elem) appendToIntList(&indexes, i);
    }
    
    return indexes;
    
}

/* ARITHMETIC UTILITIES */

// FloatList addition: return type is IntList instead of void because, otherwise, we would have to overwrite either one of the two lists. We would be deliberately losing information without the need of it
FloatList addFloatLists(FloatList l1, FloatList l2){
    FloatList temp = makeFloatList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be added");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToFloatList(&temp, l1.elems[i]+l2.elems[i]);
    }

    return temp;
    
}

FloatList subtractFloatLists(FloatList l1, FloatList l2){
    FloatList temp = makeFloatList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be subtracted");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToFloatList(&temp, l1.elems[i]-l2.elems[i]);
    }

    return temp;
    
}

FloatList multiplyFloatLists(FloatList l1, FloatList l2){
    FloatList temp = makeFloatList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be multiplied");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToFloatList(&temp, l1.elems[i]*l2.elems[i]);
    }

    return temp;
    
}

#endif