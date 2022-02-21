
/*
Name:Hasnian Bharmal
Student ID:1001937588
*/

#include <stdio.h>

int main()
{

int i;
int j;
int k;
int h;
int b;
int x;

printf("\nEnter i's starting value ");
scanf("%d",&i);

printf("\nEnter i's ending value ");
scanf("%d",&h);

printf("\nEnter j's starting value ");
scanf("%d",&j);

printf("\nEnter j's ending value ");
scanf("%d",&b);

printf("\nEnter k's starting value ");
scanf("%d",&k);

printf("\nEnter k's ending value ");
scanf("%d",&x);
printf("\n\n");


for(int p=i;p<h;p++){
    for(int q=j;q<b;q++){
        for(int r=k;r<x;r++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}

 return 0;
}