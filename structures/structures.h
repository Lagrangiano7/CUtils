#ifndef _STRUCTURES_H
#define _STRUCTURES_H 1

#include "IntList.h"
#include "StrList.h"
#include "LongList.h"
#include "DoubleList.h"
#include "Map.h"

// Just lists
#define append(L, val) _Generic((*L), \
IntList: appendToIntList, \
LongList: appendToLongList, \
DoubleList: appendToDoubleList, \
StrList: appendToStrList \
)(L, val)

#define set(L, index, val) _Generic((*L), \
IntList: setToIntList, \
LongList: setToLongList, \
DoubleList: setToDoubleList, \
StrList: setToStrList \
) (L, index, val)

// Just maps
#define addMapEntry(MAP, key, val) _Generic((*MAP), \
SIMap: addSIMapEntry, \
SLMap: addSLMapEntry, \
SDMap: addSDMapEntry,  \
SSMap: addSSMapEntry \
) (MAP, key, val)

// Shared
#define get(L, val) _Generic((L), \
IntList: getFromIntList, \
LongList: getFromLongList, \
DoubleList: getFromDoubleList, \
StrList: getFromStrList, \
SIMap: getSIMApEntry, \
SLMap: getSLMapEntry, \
SDMap: getSDMapEntry,  \
SSMap: getSSMapEntry \
) (L, val)

#define printData(L) _Generic((L), \
IntList: printIntList, \
LongList: printLongList, \
DoubleList: printDoubleList, \
StrList: printStrList, \
SIMap: printSIMap, \
SLMap: printSLMap, \
SDMap: printSDMap,  \
SSMap: printSSMap \
) (L)

#endif