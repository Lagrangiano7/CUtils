#ifndef _MAP_GEMERICS_H
#define _MAP_GEMERICS_H 1

#include "Map.h"

#define addMapEntry(MAP, key, val) _Generic((*MAP), \
SIMap: addSIMapEntry, \
SLMap: addSLMapEntry, \
SDMap: addSDMapEntry,  \
SSMap: addSSMapEntry \
) (MAP, key, val)

#define getMapEntry(MAP, key) _Generic((MAP), \
SIMap: getSIMApEntry, \
SLMap: getSLMapEntry, \
SDMap: getSDMapEntry,  \
SSMap: getSSMapEntry \
) (MAP, key)

#define printMap(L) _Generic((L), \
SIMap: printIntList, \
SLMap: printLongList, \
SDMap: printDoubleList, \
SSMap: printSSMap \
) (L) // Add SSMap

#endif