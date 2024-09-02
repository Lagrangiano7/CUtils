#ifndef _MAP_GEMERICS_H
#define _MAP_GEMERICS_H 1

#include "Map.h"

#define addMapEntry(MAP, key, val) _Generic((*MAP), \
SIMap: addSIMapEntry, \
SLMap: addSLMapEntry, \
SDMap: addSDMapEntry  \
) (MAP, key, val)

#define getMapEntry(MAP, key) _Generic((MAP), \
SIMap: getSIMApEntry, \
SLMap: getSLMapEntry, \
SDMap: getSDMapEntry  \
) (MAP, key)

#endif