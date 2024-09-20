#include <stdio.h>
#include "../string/Slice.h"
#include "../string/Strinv.h"
#include "../string/CountChar.h"
#include "../string/Trim.h"
#include "../string/Strcmp.h"
#include "../string/Strlen.h"

int main(){

    /* SLICE */
    const char* str = "Hello world!";
    const char* substr = Slice(str, 3, 8); // lo wor

    /* STRINV */
    const char* str_inverted = Strinv(str); // !dlrow olleH

    /* COUNTCHAR */
    int num_of_o = CountChar(str, 'o'); // 2

    /* TRIM */
    const char* trimmed_left = TrimLeft(str);
    const char* trimmed_right = TrimRight(str);
    const char* trimmed = Trim(str);

    /* STRCMP */
    const char* s1 = "Hey there, world!";
    if(Strcmp(str, s1)) puts("Equal strings"); // Improved syntax since there is no need to use "=="
    else puts("Strings are not equal");

    /* STRLEN */
    uint8_t len = Strlen(str); // 11

    return 0;
}