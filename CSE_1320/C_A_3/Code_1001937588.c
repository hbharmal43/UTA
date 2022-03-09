// Name:Hasnain Bharmal
//ID; 1001937588

#include <stdio.h>
#include <time.h>
void fillBingoCard(int temp);
int main()
{
int bingo_card[4][4];
fillBingoCard(bingo_card);
}

void fillBingoCard(int temp[4][4])
{
srand(time(0));
for(int i=0;i<5;i++){
    temp[0][i]=rand() % 15+1;
    printf("%d",temp[0][i]);
}

}

