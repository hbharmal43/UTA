/******************************************************************************
 * File: HAB7588Lab3Part2eCode
 * Author: Hasnain Bharmal
 * Created on:  November 20, 2021, 11:37 PM
.*
 * UTA Student Name: Hasnain Bharmal
 * UTA ID: 1001937588
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int binaryOutput[10], inputValue;
    int i, j;

    printf("Please Enter an Integer Number You want to Convert  :  ");
    scanf("%d", &inputValue);
    for(i = 0; inputValue > 0; i++)
    {
        binaryOutput[i] = inputValue % 2;
        inputValue = inputValue / 2;
    }
    
    printf("\nBinary Output =  ");
    for(j = i - 1; j >= 0; j--)  {
        printf(" %d ", binaryOutput[j]);
    }
    return 0;
}