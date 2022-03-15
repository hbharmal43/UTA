#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintBingoCard(int bingocard[5][5]);
void FillBingoCard(int bingocard[5][5]);
int PickNum(int pickednums[75], int pickednumcounter);
int CheckNum(int bingocard[5][5], int pickednum);
int CheckRowBingo(int bingocard[5][5]);
int CheckColBingo(int bingocard[5][5]);
int CheckDiagBingo(int bingocard[5][5]);

int main(void)
{   
    srand(time(0));
    int bingocard[5][5] = {0};
    
    int pickednums[75] = {0}; // array to store used values 
    int pickednumcounter = 0;
    
    int win = 0;
    int rowcomplete = 0;
    int colcomplete = 0;
    int diagcomplete = 0;

    FillBingoCard(bingocard);

    int pickednum = 0;

    char answer[10];

    while (win == 0 && pickednumcounter < 75)
    {
        PrintBingoCard(bingocard);

        pickednum = PickNum(pickednums, pickednumcounter);
        pickednumcounter++;

        if (pickednum >= 0 && pickednum <= 15)
            printf("\nThe next number is B%d", pickednum);
        else if (pickednum >= 16 && pickednum <= 30)
            printf("\nThe next number is I%d", pickednum);
        else if (pickednum >= 31 && pickednum <= 45)
            printf("\nThe next number is N%d", pickednum);
        else if (pickednum >= 46 && pickednum <= 60)
            printf("\nThe next number is G%d", pickednum);
        else if (pickednum >= 61 && pickednum <= 75)
            printf("\nThe next number is O%d", pickednum);

        printf("\n\nDo you have it? (Y/N) ");
        scanf("%s", answer);

        if (answer[0] == 'Y')
        {
            if (CheckNum(bingocard, pickednum) == 1)
            {
                rowcomplete = CheckRowBingo(bingocard);
                colcomplete = CheckColBingo(bingocard);
                diagcomplete = CheckDiagBingo(bingocard);

                if (rowcomplete == 1 && colcomplete == 1)
                {  
                    PrintBingoCard(bingocard);
                    printf("\nYou filled out a row and a column - BINGO!!!");
                    win = 1; 
                }
                else if (rowcomplete == 1)
                {
                    PrintBingoCard(bingocard);
                    printf("\nYou filled out a row - BINGO!!!");
                    win = 1;
                }
                else if (colcomplete == 1)
                {
                    PrintBingoCard(bingocard);
                    printf("\nYou filled out a column - BINGO!!!");
                    win = 1;
                }
                else if (diagcomplete == 1)
                {
                    PrintBingoCard(bingocard);
                    printf("\nYou filled out a diagonal - BINGO!!!");
                    win = 1;
                }
            }
            else
                printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
        }
    }
    return 0;
}

void PrintBingoCard(int bingocard[5][5]) // function to print bingo card on screen
{
    printf("\n%6c   %6c   %6c   %6c   %6c\n", 'B', 'I', 'N', 'G', 'O');
    for (int i = 0; i < 46; i++) 
        printf("-");
    
    for (int i = 0; i < 5; i++)
    {
        printf("\n");

        for (int j = 0; j < 5; j++)
        {
            if (bingocard[i][j] == 0)
                printf("|%5c   ", 'X');
            else
                printf("|%5d   ", bingocard[i][j]);
        }
        printf("|\n");

        for (int i = 0; i < 46; i++) 
            printf("-");
    }
    printf("\n");
}

void FillBingoCard(int bingocard[5][5]) // function to fill bingo card with random values
{   
    int randnum;
    int start;
    int colnums[5];

    for(int j = 0; j < 5; j++)  
        for (int i = 0; i < 5; i++)
        {
            if (j == 0)
                start = 1;
            else if (j == 1)
                start = 16;
            else if (j == 2)
                start = 31;
            else if (j == 3)
                start = 46;
            else if (j == 4)
                start = 61;

            randnum = rand() % (15) + start;
            
            int c = 0;
            while(c < 5)
            {   
                if (colnums[c] == randnum)
                {
                    randnum = rand() % (15) + start;
                    c = 0;
                }    
                else
                    c++;
            }
            
            colnums[i] = randnum;
            bingocard[i][j] = randnum;
        }           
    
    bingocard[2][2] = 0;
}

int PickNum(int pickednums[75], int pickednumcounter) // function to pick next called number for user to check off on bingo card
{
    int newnum = rand() % 75 + 1;
    
    int c = 0;
    while (c < pickednumcounter)
    {
        if (pickednums[c] == newnum)
        {
            newnum = rand() % 75 + 1;
            c = 0;
        }
        else
            c++;
    }
    pickednums[pickednumcounter] = newnum;
    return newnum;
}

int CheckNum(int bingocard[5][5], int pickednum) // function to check user has number if user answers Y
{   
    int found = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (bingocard[i][j] == pickednum)
            {
                bingocard[i][j] = 0;
                found = 1;
            }
        }
        return found;
}

int CheckRowBingo(int bingocard[5][5]) // fucntion to check completed row
{   
    int found = 0;
    for (int i = 0; i < 5; i++)
    {
        if (bingocard[i][0] == 0 && bingocard[i][1] == 0 && bingocard[i][2] == 0 &&
            bingocard[i][3] == 0 && bingocard[i][4] == 0)
        {
            found = 1;
        }
    }
    return found;
}  

int CheckColBingo(int bingocard[5][5]) // fucntion to check completed column
{   
    int found = 0;
    for (int i = 0; i < 5; i++)
    {
        if (bingocard[0][i] == 0 && bingocard[1][i] == 0 && bingocard[2][i] == 0 &&
            bingocard[3][i] == 0 && bingocard[4][i] == 0)
        {
            found = 1;
        }
    }
    return found;
}

// ----------------- Bonus work ------------------------ 

int CheckDiagBingo(int bingocard[5][5]) // fucntion to check completed diagonal
{   
    int found = 0;
    if (bingocard[0][0] == 0 && bingocard[1][1] == 0 && bingocard[2][2] == 0 && 
        bingocard[3][3] == 0 && bingocard[4][4] == 0)
    {
        found = 1;
    }
    else if (bingocard[4][0] == 0 && bingocard[3][1] == 0 && bingocard[2][2] == 0 && 
        bingocard[1][3] == 0 && bingocard[0][4] == 0)
    {
        found = 1;
    }
    
    return found;
}