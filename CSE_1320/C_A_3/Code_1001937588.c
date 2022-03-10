// Name:Hasnain Bharmal
// ID; 1001937588

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fillBingoCard(int temp[5][5]);
int main()
{
    int bingo_card[5][5];
        srand(time(0));

    fillBingoCard(bingo_card);

    for (int i = 0; i < 5; i++){
        for(int j=0;j<5;j++){
        printf("%d\t", bingo_card[j][i]);
    }
printf("\n");
}

    return 0;
}

int fillBingoCard(int temp[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        temp[i][0] = rand() % 15 + 1;
        //printf("%d\n", temp[0][i]);
    }

    for (int j = 0; j < 5; j++)
    {
        temp[j][1] = rand() % 15 + 16;
        //printf("%d\t", temp[0][j]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        temp[i][2] = rand() % 15 + 31;
        //printf("%d\t", temp[0][i]);
    } 

    for (int i = 0; i < 5; i++)
    {
        temp[i][3] =rand() % 15 + 46;
        //printf("%d\t", temp[0][i]);
    }

    for (int i = 0; i < 5; i++)
    {
        temp[i][4] = rand() % 15 + 61;
       // printf("%d\t\n", temp[0][i]);
    }
}

