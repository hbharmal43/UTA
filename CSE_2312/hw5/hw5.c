// Toolchain:
// Default align: gcc -o hw5 hw5.c hw5.s
// Packed:        gcc -o hw5 hw5.c hw5.s -D PACK

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#ifdef PACK
#pragma pack(push)
#pragma pack(1)
#endif

typedef struct _BUSINESS2
{
    uint32_t taxId;
    char name[26+1];
    char direction;
    char street[34+1];
    uint32_t addNo;
    char city[29+1];
    char state[2+1];
    uint32_t zip;
} BUSINESS2;

#ifdef PACK
#pragma pack(pop)
#endif

extern int32_t sumS32(const int32_t x[], uint32_t count);
// returns sum of the values in the array (x) containing count entries.
extern int32_t dotpS32(const int32_t x[], const int32_t y[], uint32_t count);
// returns the dot product of the values in the arrays (x and y) containing count entries.
extern uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count);
// returns number of values in the array (x) containing count entries that are > limit
extern int32_t findCityAligned (const char city[], const BUSINESS2 business[], uint32_t count);
// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
// If the city is not found, return a value of -1. You can assume that C default alignment is used for this problem.
extern int32_t findCityPacked (const char city[], const BUSINESS2 business[], uint32_t count);
// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
// If the city is not found, return a value of -1. You can assume that C packing is used for this problem



#define COUNT 3

int main()
{
    uint32_t i;
    BUSINESS2 business[COUNT] = {
        {12342332, "Home Depot", 'W', "Road to Six Flags", 201, "Arlington", "TX", 76011},
        {18091123, "Kroger", 'W', "Lamar Blvd", 945, "Arlington", "TX", 76012},
        {81927322, "Round1", 'S', "Cooper St", 945, "Dallas", "TX", 76015} };
    printf("Addresses of selected record entries:\r\n");

    int32_t y = 0;
    int32_t array_x[] = {127, 150, 200, 350, 10, 5};
    int32_t array_y[] = {5, 127, 150, 200, 350, 10};

    for (int i = 0; i < 4; i++){
        y += array_x[i];
    }
    printf("sums32 student answer = %d\n", sumS32(array_x, 4));
    printf("sums32 correct answer = %d\n", y);

    
    
    printf("dotp = %d\n", dotpS32(array_x, array_y, 6));
    int32_t z = 0;
    for (int i = 0 ; i < 6; i++){
        z += array_x[i] * array_y[i];
    }
        printf("correct answer = %d\n", z);
        
    int32_t x = 0;
    uint32_t c = 6;
    for (int i = 0; i < 6; i++){
        if (array_x[i] > 100)
         x+=1;
    }
    printf("countAboveLimit student answer = %d\n", countAboveLimit(array_x, 100, c));
    printf("countAboveLimit correct answer = %d\n", x);
    uint32_t b = 3;
    char searchCity[] = "Dallas";
#ifndef PACK   
    printf("findCityAligned student answer %d\n", findCityAligned(searchCity, business, b));
    printf("findCityAligned correct answer %d\n", 2);
#endif
#ifdef PACK
    printf("findCityPacked student answer %d\n", findCityPacked(searchCity, business, b));
    printf("findCityPacked correct answer %d\n", 2);
#endif
    return 0;
}
