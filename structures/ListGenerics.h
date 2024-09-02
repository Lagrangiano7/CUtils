#ifndef _LIST_GENERIC_H
#define _LIST_GENERIC_H 1

#include "IntList.h"
#include "StrList.h"
#include "LongList.h"
#include "DoubleList.h"

// Append
#define append(L, val) _Generic((*L), \
IntList: appendToIntList, \
LongList: appendToLongList, \
DoubleList: appendToDoubleList, \
StrList: appendToStrList \
)(L, val)

#define get(L, val) _Generic((L), \
IntList: getFromIntList, \
LongList: getFromLongList, \
DoubleList: getFromDoubleList, \
StrList: getFromStrList \
) (L, val)

#define set(L, index, val) _Generic((*L), \
IntList: setToIntList, \
LongList: setToLongList, \
DoubleList: setToDoubleList, \
StrList: setToStrList \
) (L, index, val)

#endif