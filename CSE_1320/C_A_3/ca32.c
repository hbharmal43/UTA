#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillBingoCard(int temp[5][5]);
int main()
{

    int Bingo_card[5][5];
    srand(time(0));
    //fillBingoCard(Bingo_card);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        printf("%d",i);
        }
    }

    return 0;
}

void fillBingoCard(int temp[5][5])
{

    int DUP[5] = {};
    int c = 0;
    int vari;
    for (int i = 0; i < 5; i++)
    {
        printf("-%d-", i);
        while (c < 5)
        {
            vari = rand() % 15 + (15 * c) + 1;
            if (DUP[c] == vari)
            {
                vari = rand() % 15 + (15 * c) + 1;
                c = 0;
            }
            else
            {
                c++;
            }
            DUP[c] = rand() % 15 + (15 * c) + 1;
            printf("-%d-", i);
        }
    }
}


