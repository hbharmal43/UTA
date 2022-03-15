// Name:Hasnain Bharmal
// ID; 1001937588

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rowCheck(int tempvalue[5][5]);
int columnCheck(int tempvalue[5][5]);
int diagonalCheck(int tempvalue[5][5]);
void fillBingoCard(int temp[5][5]);
void printBingoCard(int temp[5][5]);
int pickNmber(int pickNumtemp[75], int cntr);
int verifyCard(int temp_2[5][5], int num);

int main()
{
    int DUP[5];
    int bingo_card[5][5];
    int pickNum;
    int pickNumber[75];
    int p_Num;
    int cntr = 0;
    char input[15];
    int over = 0;


    srand(time(0));
    fillBingoCard(bingo_card);
    printBingoCard(bingo_card);
    while (cntr < 75 && over == 0)
    {

        p_Num = pickNmber(pickNumber, cntr);
        // printf("--%d--\n",p_Num);
        cntr++;
        if (p_Num <= 15)
        {
            printf("The next number is B%d\n", p_Num);
        }
        else if (p_Num > 15 && p_Num <= 30)
        {
            printf("The next number is I%d\n", p_Num);
        }
        else if (p_Num > 30 && p_Num <= 45)
        {
            printf("The next number is N%d\n", p_Num);
        }
        else if (p_Num > 45 && p_Num <= 60)
        {
            printf("The next number is G%d\n", p_Num);
        }
        else if (p_Num > 60 && p_Num <= 75)
        {
            printf("The next number is O%d\n", p_Num);
        }
        printf("Do you have it? (Y/N)");
        scanf("%s", input);
        if (input[0] == 'Y')
        {
            if (verifyCard(bingo_card, p_Num) == 1)
            {

                printBingoCard(bingo_card);
                if (rowCheck(bingo_card) == 1 && columnCheck(bingo_card) == 1)
                {
                    printf("You filled out a row & column - BINGO!!!");
                    over = 1;
                }
                else if (columnCheck(bingo_card) == 1)
                {

                    printf("You filled out a column - BINGO!!!");
                    over = 1;
                }
                else if (rowCheck(bingo_card) == 1)
                {
                    printf("You filled out a row - BINGO!!!");
                    over = 1;
                }
                else if (diagonalCheck(bingo_card) == 1)
                {
                    printf("You filled out a diagnaol - BINGO!!!");
                    over = 1;

                }
            }
            else
            {
                printf("That value is not on your BINGO card - are you trying to cheat??\n");
                printBingoCard(bingo_card);
            }
        }
        else
        {
            printBingoCard(bingo_card);
        }
    }

    return 0;
}

void fillBingoCard(int temp[5][5])
{
    int vari;
    int DUP[5];
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 5; i++)
        {
            vari = rand() % 15 + (15 * j) + 1;

            int cntr = 0;
            while (cntr < 5)
            {
                if (DUP[cntr] == vari)
                {
                    vari = rand() % 15 + (15 * j) + 1;
                    cntr = 0;
                }
                else
                    // printf("%d",vari);
                    cntr++;
            }
            // printf("%d",vari);
            DUP[i] = vari;
            temp[i][j] = vari;
        }

    temp[2][2] = 0;
}

void printBingoCard(int temp[5][5])
{
    printf("%5c%8c%8c%8c%8c\n", 'B', 'I', 'N', 'G', 'O');
    printf("-----------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (temp[i][j] == 0)
            {
                printf("|%4c   ", 'X');
            }
            else
                printf("|%4d \t", temp[i][j]);
        }
        printf("|\n-----------------------------------------\n");
    }
}

int pickNmber(int pickNumtemp[75], int cntr)
{
    int t_cntr = 0;
    int temp_Num;
    temp_Num = rand() % 75 + 1;
    while (t_cntr < cntr)
    {
        if (pickNumtemp[t_cntr] == temp_Num)
        {
            temp_Num = rand() % 75 + 1;
            t_cntr = 0;
        }
        else
            t_cntr++;
    }
    pickNumtemp[cntr] = temp_Num;
    return temp_Num;
}

int verifyCard(int temp_2[5][5], int num)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (temp_2[j][i] == num)
            {
                temp_2[j][i] = 0;

                return 1;
            }
        }
    }
    return 0;
}

int rowCheck(int tempvalue[5][5])
{
    int variable = 0;
    for (int i = 0; i < 5; i++)
    {
        if (tempvalue[i][0] == 0 && tempvalue[i][1] == 0 && tempvalue[i][2] == 0 && tempvalue[i][3] == 0 && tempvalue[i][4] == 0)
        {
            variable = 1;
        }
    }
    return variable;
}

int columnCheck(int tempvalue[5][5])
{
    int variable = 0;
    for (int i = 0; i < 5; i++)
    {
        if (tempvalue[0][i] == 0 && tempvalue[1][i] == 0 && tempvalue[2][i] == 0 && tempvalue[3][i] == 0 && tempvalue[4][i] == 0)
        {
            variable = 1;
        }
    }
    return variable;
}

int diagonalCheck(int tempvalue[5][5])
{
    int variable = 0;

    if (tempvalue[0][0] == 0 && tempvalue[1][1] == 0 && tempvalue[2][2] == 0 && tempvalue[3][3] == 0 && tempvalue[4][4] == 0)
    {
        variable = 1;
    }
    else if (tempvalue[0][4] == 0 && tempvalue[1][3] == 0 && tempvalue[2][2] == 0 && tempvalue[3][1] == 0 && tempvalue[4][0] == 0)
    {
        variable = 1;
    }

    return variable;
}