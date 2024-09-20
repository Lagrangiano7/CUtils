#include <stdio.h>
#include "../structures/structures.h"

int main(){ // CUtils' structures must be defined inside a function


/* This is an example file. It is NOT intended to be used */

// DECLARING AND INITIALIZING AN IntList
IntList l = makeIntList();

// If the array is empty, then its size is set to -1 to indicate there is no element 0
// This helps prevent errors designed to prevent you from trying to index an empty List
printf("%d", l.size);

// APPENDING TO LIST:
append(&l, 10);
append(&l, 20); 
append(&l, 10);
// Array is now [ 10 20 10 ]

// GETTING ELEMENT FROM LIST:
int elem_0 = get(l,0); // Returns 10

// SETTING 2nd ELEMENT TO -39 (before, it was 20)
set(&l, 1, -39);

// SORTING ARRAY
sort(&l); // Array is now [ -39 10 10 ]

// IN WHICH INDEXES IS THERE AN OCCURRENCE OF 10?
IntList indexes = getIndex(l, 10); // Indexes: [ 1 2 ]

// LET US PRINT THE "INDEXES" LIST TO VISUALIZE IT
printData(indexes);

// LET'S MAKE ANOTHER INTLIST AND ADD IT TO THE ORIGINAL
IntList l2 = makeIntList();
append(&l2, 30);
append(&l2, 70);
append(&l2, 90);

IntList addition = add(l, l2); // addition: [ -9 80 100 ]

// WE CAN ALSO SUBTRACT THEM
IntList subtraction = subtract(l, l2); // subtraction: [ -69 -60 -80 ]

// AND WE CAN MULTIPLY THEM AS WELL
IntList product = multiply(l, l2); // product: [ -1170 700 900 ]

// COMMENT: STRLIST DOES NOT HAVE ALL THESE FEATURES DEFINED, SINCE NOT ALL OF THEM MAKE SENSE
// IN STRINGS (i.e: YOU CANNOT TAKE THE PRODUCT OF 2 STRINGS)


/* MAPS */

// CREATING A STRING-INT MAP (SIMap)

SIMap m = makeSIMap();

// ADDING ENTRY TO SIMAP
addMapEntry(&m, "First key", 10);
addMapEntry(&m, "Second key", -20);

// ACCESSING VALUE BY KEY
int elem2 = get(m, "First key"); // Returns 10

// PRINTING MAP
printData(m); // { First key : 10, Second key : -20 }

return 0;

}

