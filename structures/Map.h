#ifndef _MAP_H
#define _MAP_H 1

#include <stdint.h>
#include "Lists.h"
#include "../string/Strcmp.h"

typedef struct {
    StrList keys;
    IntList vals;
    uint8_t size;
    
} SIMap;

SIMap makeSIMap(){
    SIMap m;
    m.keys = makeStrList();
    m.vals = makeIntList();
    m.size = 0;
    return m;
}

void addSIMapEntry(SIMap *m, char* key, int val){
    append(&(m->keys), key);
    append(&(m->vals) ,val);
    m->size++;
}

int getSIMApEntry(SIMap m, char* key){
    // Get index of key in the StrList
    for(int i = 0; i < m.size; i++){
        if (Strcmp(key, m.keys.elems[i])) {
            return m.vals.elems[i];
        }
    }

    printf("Key not found: %s", key);
    return -1;
}

void printSIMap(SIMap m){
    printf("{ ");
    for(int i = 0; i < m.size-1; i++) printf("%s : %d, ", m.keys.elems[i], m.vals.elems[i]);
    printf("%s : %d }", m.keys.elems[m.size-1], m.vals.elems[m.size-1]);
}

/* String-Long Map */

typedef struct {
    StrList keys;
    LongList vals;
    uint8_t size;
    
} SLMap;

SLMap makeSLMap(){
    SLMap m;
    m.keys = makeStrList();
    m.vals = makeLongList();
    m.size = 0;
    return m;
}

void addSLMapEntry(SLMap *m, char* key, long val){
    appendToStrList(&(m->keys), key);
    appendToLongList(&(m->vals) ,val);
    m->size++;
}

long getSLMapEntry(SLMap m, char* key){
    // Get index of key in the StrList
    for(int i = 0; i < m.size; i++){
        if (Strcmp(key, m.keys.elems[i])) {
            return m.vals.elems[i];
        }
    }

    printf("Key not found: %s", key);
    return -1;
}

void printSILap(SLMap m){
    printf("{ ");
    for(int i = 0; i < m.size-1; i++) printf("%s : %ld, ", m.keys.elems[i], m.vals.elems[i]);
    printf("%s : %ld }", m.keys.elems[m.size-1], m.vals.elems[m.size-1]);
}

/*String-Double Map*/
typedef struct {
    StrList keys;
    DoubleList vals;
    uint8_t size;
    
} SDMap;

SDMap makeSDMap(){
    SDMap m;
    m.keys = makeStrList();
    m.vals = makeDoubleList();
    m.size = 0;
    return m;
}

void addSDMapEntry(SDMap *m, char* key, double val){
    append(&(m->keys), key);
    append(&(m->vals) ,val);
    m->size++;
}

double getSDMapEntry(SDMap m, char* key){
    // Get index of key in the StrList
    for(int i = 0; i < m.size; i++){
        if (Strcmp(key, m.keys.elems[i])) {
            return m.vals.elems[i];
        }
    }

    printf("Key not found: %s", key);
    return -1;
}

void printSDMap(SDMap m){
    printf("{ ");
    for(int i = 0; i < m.size-1; i++) printf("%s : %f, ", m.keys.elems[i], m.vals.elems[i]);
    printf("%s : %f }", m.keys.elems[m.size-1], m.vals.elems[m.size-1]);
}

/*String-String Map*/
typedef struct {
    StrList keys;
    StrList vals;
    uint8_t size;
    
} SSMap;

SSMap makeSSMap(){
    SSMap m;
    m.keys = makeStrList();
    m.vals = makeStrList();
    m.size = 0;
    return m;
}

void addSSMapEntry(SSMap *m, char* key, char* val){
    append(&(m->keys), key);
    append(&(m->vals) ,val);
    m->size++;
}

char* getSSMapEntry(SSMap m, char* key){
    // Get index of key in the StrList
    for(int i = 0; i < m.size; i++){
        if (Strcmp(key, m.keys.elems[i])) {
            return m.vals.elems[i];
        }
    }

    printf("Key not found: %s", key);
    return "";
}

void printSSMap(SSMap m){
    printf("{ ");
    for(int i = 0; i < m.size-1; i++) printf("%s : %s, ", m.keys.elems[i], m.vals.elems[i]);
    printf("%s : %s }", m.keys.elems[m.size-1], m.vals.elems[m.size-1]);
}

#endif