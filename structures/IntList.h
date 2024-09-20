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

/* FINDING UTILITIES */
IntList ReverseFindIntList(IntList l, int elem){
    // Find indexes of all instances of element in IntList
    IntList indexes = makeIntList();
    for(int i = 0; i < l.size; i++){
        if(l.elems[i]==elem) appendToIntList(&indexes, i);
    }
    
    return indexes;
    
}

/* ARITHMETIC UTILITIES */

// IntList addition: return type is IntList instead of void because, otherwise, we would have to overwrite either one of the two lists. We would be deliberately losing information without the need of it
IntList addIntLists(IntList l1, IntList l2){
    IntList temp = makeIntList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be added");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToIntList(&temp, l1.elems[i]+l2.elems[i]);
    }

    return temp;
    
}

IntList subtractIntLists(IntList l1, IntList l2){
    IntList temp = makeIntList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: IntLists must be the same size to be subtracted");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToIntList(&temp, l1.elems[i]-l2.elems[i]);
    }

    return temp;
    
}

IntList multiplyIntLists(IntList l1, IntList l2){
    IntList temp = makeIntList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: IntLists must be the same size to be multiplied");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToIntList(&temp, l1.elems[i]*l2.elems[i]);
    }

    return temp;
    
}

#endif