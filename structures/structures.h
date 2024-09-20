#ifndef _STRUCTURES_H
#define _STRUCTURES_H 1

#include "IntList.h" // Has to be on top for dependencies not to break in Reverse Finds
#include "StrList.h"
#include "LongList.h"
#include "FloatList.h"
#include "DoubleList.h"
#include "Map.h"

// Just lists
#define append(L, val) _Generic((*L), \
IntList: appendToIntList, \
LongList: appendToLongList, \
FloatList: appendToFloatList, \
DoubleList: appendToDoubleList, \
StrList: appendToStrList \
)(L, val)

#define set(L, index, val) _Generic((*L), \
IntList: setToIntList, \
LongList: setToLongList, \
FloatList: setToFloatList, \
DoubleList: setToDoubleList, \
StrList: setToStrList \
) (L, index, val)

#define sort(L) _Generic((*L), \
IntList: SortIntList, \
LongList: SortLongList, \
FloatList: SortFloatList, \
DoubleList: SortDoubleList \
)(L)

#define getIndex(L, val) _Generic((L), \
IntList: ReverseFindIntList, \
LongList: ReverseFindLongList, \
FloatList: ReverseFindFloatList, \
DoubleList: ReverseFindDoubleList, \
StrList: ReverseFindStrList \
)(L, val)

// TODO: add scale feature:
    // Scale by int: scaled List conserves its type
    // Scale by long: scale List conserves its type BUT IntList --> LongList
    // Scale by float: FloatList & DoubleList conserve type, IntList & LongList --> FloatList
    // Scale by double: DoubleList conserves its type, rest --> DoubleList

// Just maps
#define addMapEntry(MAP, key, val) _Generic((*MAP), \
SIMap: addSIMapEntry, \
SLMap: addSLMapEntry, \
SFMap: addSFMapEntry,  \
SDMap: addSDMapEntry,  \
SSMap: addSSMapEntry \
) (MAP, key, val)

// Shared
#define get(L, val) _Generic((L), \
IntList: getFromIntList, \
LongList: getFromLongList, \
FloatList: getFromFloatList, \
DoubleList: getFromDoubleList, \
StrList: getFromStrList, \
SIMap: getSIMApEntry, \
SLMap: getSLMapEntry, \
SFMap: getSFMapEntry,  \
SDMap: getSDMapEntry,  \
SSMap: getSSMapEntry \
) (L, val)

#define printData(L) _Generic((L), \
IntList: printIntList, \
LongList: printLongList, \
FloatList: printFloatList, \
DoubleList: printDoubleList, \
StrList: printStrList, \
SIMap: printSIMap, \
SLMap: printSLMap, \
SFMap: printSFMap,  \
SDMap: printSDMap,  \
SSMap: printSSMap \
) (L)

#endif