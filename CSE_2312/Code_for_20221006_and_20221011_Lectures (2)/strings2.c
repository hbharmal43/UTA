#// CSE 2312 Computer Org and Assembly Language Programming
// string2 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

// returns position of first instance of character in string
// or -1 if not found
extern int32_t strFind(const char str[], char c);
 
// returns position of nth instance of character in string
// or -1 if not found
extern int32_t strFindN(const char str[], char c, uint32_t n); 

int main(void)
{
    char str[] = "Hello world";
    char match = 'o';
    uint32_t n = 2;
    int result;

    printf("str = %s\n", str);
    printf("n   = %"PRIu32"\n", n);

    result = strFind(str, match);
    if (result < 0)
        printf("'%c' not found in \"%s\"\n", match, str);
    else
        printf("First instance of '%c' in \"%s\" found at offset %d\n", match, str, result);

    result = strFindN(str, match, n);
    if (result < 0)
        printf("nth instance of '%c' not found in \"%s\"\n", match, str);
    else
        printf("nth instance of '%c' in \"%s\" found at offset %d\n", match, str, result);

    return EXIT_SUCCESS;
}


