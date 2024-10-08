#ifndef _LONGLIST_H
#define _LONGLIST_H 1

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    long* elems;
} LongList;

LongList makeLongList(){
    LongList list = {-1, (long*)malloc(sizeof(long))};
    return list;
}

/* ADDING TO LIST (SETTERS) */

void setToLongList(LongList *list, uint8_t index, long val){
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

void appendToLongList(LongList *list, long val){
    if(list->size==-1){
        list->elems[0]=val;
        list->size=1;
        return;
    }
    // Optimize memory efficiency by increasing size of elems one by one, thus losing execution speed at runtime
    list->size++;
    list->elems = (long*)realloc(list->elems, sizeof(long)*(list->size+1));
    list->elems[list->size-1]=val;
}

/* GET FROM LIST (GETTERS) */

long getFromLongList(LongList list, uint8_t index){
    if (index > list.size -1){
        puts("Error: index out of range");
        return -1;
    }
    return list.elems[index];
}

long popFromLongList(LongList *list) {
    long lastVal = list->elems[list->size-1];
    list->elems = (long*)realloc(list->elems, sizeof(long)*(list->size-1));
    list->size--;
    return lastVal;
}



/* PRINTING UTILITIES */
void printLongList(LongList l){
    printf("[ ");
    for(int i = 0; i < l.size; i++) printf("%ld ", l.elems[i]);
    printf("]\n");
}

/* SORTING UTILITIES */

int compareLongs(const void* a, const void* b) {
    return (*(long*)a - *(long*)b);
}

void SortLongList(LongList *l){
    qsort(l->elems, l->size, sizeof(long), compareLongs);
}

/* FINDING UTILITIES */
IntList ReverseFindLongList(LongList l, long elem){
    // Find indexes of all instances of element in IntList
    IntList indexes = makeIntList();
    for(int i = 0; i < l.size; i++){
        if(l.elems[i]==elem) appendToIntList(&indexes, i);
    }
    
    return indexes;
    
}

/* ARITHMETIC UTILITIES */

// LongList addition: return type is IntList instead of void because, otherwise, we would have to overwrite either one of the two lists. We would be deliberately losing information without the need of it
LongList addLongLists(LongList l1, LongList l2){
    LongList temp = makeLongList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be added");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToLongList(&temp, l1.elems[i]+l2.elems[i]);
    }

    return temp;
    
}

LongList subtractLongLists(LongList l1, LongList l2){
    LongList temp = makeLongList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be subtracted");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToLongList(&temp, l1.elems[i]-l2.elems[i]);
    }

    return temp;
    
}

LongList multiplyLongLists(LongList l1, LongList l2){
    LongList temp = makeLongList();

    // Check if both lists are equal
    if (l1.size != l2.size) {
        puts("Error: Lists must be the same size to be multiplied");
        return temp;
    }

    // Check if lists are empty
    if(l1.size==-1) return temp;

    // If everything is OK, proceed with adition of elements
    
    for(int i = 0; i < l1.size; i++){
        appendToLongList(&temp, l1.elems[i]*l2.elems[i]);
    }

    return temp;
    
}

#endif