

# CUtils

[![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/Lagrangiano7/Cutils?include_prereleases)](https://img.shields.io/github/v/release/Lagrangiano7/Cutils?include_prereleases)
[![GitHub last commit](https://img.shields.io/github/last-commit/Lagrangiano7/CUtils)](https://img.shields.io/github/last-commit/Lagrangiano7/CUtils)
[![GitHub issues](https://img.shields.io/github/issues-raw/Lagrangiano7/CUtils)](https://img.shields.io/github/issues-raw/Lagrangiano7/CUtils)
[![GitHub pull requests](https://img.shields.io/github/issues-pr/Lagrangiano7/CUtils)](https://img.shields.io/github/issues-pr/Lagrangiano7/CUtils)
[![GitHub](https://img.shields.io/github/license/Lagrangiano7/CUtils)](https://img.shields.io/github/license/Lagrangiano7/CUtils)

CUtils is a library that allows the user to implement in C all of the data structures contained in higher level languages, such as Lists and Maps (or Dictionaries, in Python). It does so with an elegant implementation of generic C functions and it values memory-efficiency over execution time, which is still quite low since it is fully written in C. CUtils also provides a smaller sub-module intended to make work with strings easy and intuitive.

# Quick Start Demo


<p align="center">
  <img src="https://raw.githubusercontent.com/Lagrangiano7/CUtils/refs/heads/main/logo.png" alt="logo" width="300" />
</p>


CUtils has two main goals regarding the end user: make the hasty coding process easy and prioritize memory-efficiency. Let us have a look at the most common structures you will be using:

1. IntList (expandable list of integer-type data)

```C
IntList l = makeIntList();

append(&l, 10);

append(&l, 20);

printData(l) // Yields [ 10 20 ]
```

2. SIMap (expansable String-Integer Maps / Dictionaries)
```C
SIMap m = makeSIMap();

addMapEntry(&m, "First key", 10);

addMapEntry(&m, "Second key", 20);

printData(m) // Yields {"First key" : 10, "Second key" : 20}
```

Naturally, Lists and Maps are defined for several datatypes, including numeric and strings

# Table of Contents
- [CUtils](#cutils)
- [Quick Start Demo](#quick-start-demo)
- [Table of Contents](#table-of-contents)
- [Installation](#installation)
- [Usage](#usage)
- [Development](#development)
- [Contribute](#contribute)
- [License](#license)


# Installation
[(Back to top)](#table-of-contents)

Since CUtils is, in essence, a library, it's composed of header files intended to be included in your program. Therefore, to get all the files, just clone the repo:

```shell
git clone https://github.com/Lagrangiano7/CUtils
```


# Usage
[(Back to top)](#table-of-contents)

CUtils is currently composed of two folders: "structures" and "string". Let us review them:

## Structures

Structures contains all the code necessary for the user to declare the different data structures available and manipulate them. CUtils currently supports two data structures: Lists and Maps

### Lists

Lists in CUtils are mutable arrays with some operations defined on top of them. Let us review what operations one can perform with a List:

- makeXList: acts as a constructor of X-type List (where X can be Int, Long, Float, Double or Str)
- append: adds an element to the end of the List
- get: returns specified element of the array
- set: changes a value in a specific position of the List
- size: returns the number of elements of the array
- sort: performs a quick sort on the array
- getIndex: returns a List with all the indexes where there is an occurrence of a specified element
- printData: prints the contents of the array, formatted in Matlab style
- add: returns a List whose elements are the addition of the elements of the two original Lists
- subtract: returns a List whose elements are the subtraction of the elements of the two original Lists
- multiply: returns a List whose elements are the product of the elements of the two original Lists

```C
#include  <stdio.h>
#include  "../structures/structures.h"

int  main(){ // CUtils' structures must be defined inside a function

/* This is an example file. It is NOT intended to be used */

// DECLARING AND INITIALIZING AN IntList

IntList  l  =  makeIntList();

// If the array is empty, then its size is set to -1 to indicate there is no element 0
// This helps prevent errors designed to prevent you from trying to index an empty List

printf("%d", l.size);


// APPENDING TO LIST:

append(&l, 10);

append(&l, 20);

append(&l, 10);

// Array is now [ 10 20 10 ]


// GETTING ELEMENT FROM LIST:

int  elem_0  =  get(l,0); // Returns 10


// SETTING 2nd ELEMENT TO -39 (before, it was 20)

set(&l, 1, -39);


// SORTING ARRAY

sort(&l); // Array is now [ -39 10 10 ]


// IN WHICH INDEXES IS THERE AN OCCURRENCE OF 10?

IntList  indexes  =  getIndex(l, 10); // Indexes: [ 1 2 ]

// LET US PRINT THE "INDEXES" LIST TO VISUALIZE IT

printData(indexes);


// LET'S MAKE ANOTHER INTLIST AND ADD IT TO THE ORIGINAL

IntList  l2  =  makeIntList();

append(&l2, 30);
append(&l2, 70);
append(&l2, 90);


IntList  addition  =  add(l, l2); // addition: [ -9 80 100 ]


// WE CAN ALSO SUBTRACT THEM

IntList  subtraction  =  subtract(l, l2); // subtraction: [ -69 -60 -80 ]


// AND WE CAN MULTIPLY THEM AS WELL

IntList  product  =  multiply(l, l2); // product: [ -1170 700 900 ]


// COMMENT: STRLIST DOES NOT HAVE ALL THESE FEATURES DEFINED, SINCE NOT ALL OF THEM MAKE SENSE

// IN STRINGS (i.e: YOU CANNOT TAKE THE PRODUCT OF 2 STRINGS)ç
```

### Maps

Maps in CUtils are just like those in C++ or Dictionaries in Python. All of them are defined with string-type keys, because if one wanted to use integer keys, for instance, it would be more convenient and memory-efficient to just use an IntList. Let us review the features of Maps in CUtils:

- makeSXMap: acts as a constructor for string-type keys and X-type values (where X can be Int, Float, Double or Str)
- addMapEntry: adds a pair {Key: value} to the map
- get: returns the value corresponding to a given key
- printData: prints the contents of the Map formatted in Python style

```C
// CREATING A STRING-INT MAP (SIMap)
SIMap  m  =  makeSIMap();


// ADDING ENTRY TO SIMAP

addMapEntry(&m, "First key", 10);

addMapEntry(&m, "Second key", -20);


// ACCESSING VALUE BY KEY

int  elem2  =  get(m, "First key"); // Returns 10

// PRINTING MAP

printData(m); // { First key : 10, Second key : -20 }

  

return  0;
}
```

## String

String is the second folder inside CUtils. It is not meant to substitute string.h, but rather complement it with some high-level language functionalities, such as generating substrings. Have a look at the list of features string covers:

- Slice: given a string, it returns the substring contained between the start and end point specified by the user (analogous to indexing in Python)
- Strinv: inverts string
- CountChar: returns the number of occurrences of a given character in a string
- Trim (Left/Right): removes white spaces at the beginning of a string, at the end, or both
- Strcmp: compares two strings and returns 1 if they are equal, 0 if they are not (this frees the user from having to use the equals (==) operator when using strcmp as defined in string.h)
- Strlen: same as strlen but length is stored in less memory (uint8_t)

```C
#include  <stdio.h>
#include  "../string/Slice.h"
#include  "../string/Strinv.h"
#include  "../string/CountChar.h"
#include  "../string/Trim.h"
#include  "../string/Strcmp.h"
#include  "../string/Strlen.h"

int  main(){

/* SLICE */

const  char*  str  =  "Hello world!";

const  char*  substr  =  Slice(str, 3, 8); // lo wor


/* STRINV */

const  char*  str_inverted  =  Strinv(str); // !dlrow olleH

  
/* COUNTCHAR */

int  num_of_o  =  CountChar(str, 'o'); // 2

  
/* TRIM */

const  char*  trimmed_left  =  TrimLeft(str);

const  char*  trimmed_right  =  TrimRight(str);

const  char*  trimmed  =  Trim(str);

  
/* STRCMP */

const  char*  s1  =  "Hey there, world!";

if(Strcmp(str, s1)) puts("Equal strings"); // Improved syntax since there is no need to use "=="

else  puts("Strings are not equal");

  
/* STRLEN */

uint8_t  len  =  Strlen(str); // 11

return  0;

}
```
# Contribute
[(Back to top)](#table-of-contents)

Everyone is welcome to contribute to CUtils. Please keep in mind this project is oriented towards providing C users with a solid and intuitive library combining all the positive features of high-level programming languages to the versatilty and speed of C.

If you wish to contribute to this project, please open an issue!


# License
[(Back to top)](#table-of-contents)

[GNU GPLv3 license](./LICENSE)


