//Name:Hasnain Bharmal ID:1001937588
#include <stdio.h>
#include "ListLib.h"
#include "FileLib.h"
#include "DrawTool.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char temp_letters[10];
    char draw_command[MAXMAPSIZE] = {};
    char command[MAXMAPSIZE];
    char *Token = NULL;
    char ch[5];
    int num1, num2, num3, num4;
    char map_array[MAXMAPSIZE][MAXMAPSIZE];
    int MapSize = MAXMAPSIZE;
    int shift = 0;

    NODE *LinkedListHead = NULL;
    NODE *TempPtr;
    FILE *User_File;
    char DC;
    char letter;
    InitializeMap(map_array);

    User_File = OpenFile(argc, argv);
    ReadFileIntoLinkedList(User_File, &LinkedListHead);

    printf("Please enter 1-3 letters ");
    scanf("%s", temp_letters);

    while (strlen(temp_letters) < 1 || strlen(temp_letters) > 3)
    {
        printf("Invalid letter input\n");
        printf("Please enter 1-3(temp_letters ");
        scanf("%s", temp_letters);
    }


    for (int i = 0; i < strlen(temp_letters); i++)
    {
        letter = toupper(temp_letters[i]);
        TempPtr = LinkedListHead;
        TempPtr = FindLetter(TempPtr, letter, draw_command);


        while (strlen(draw_command) != 0)
        {
            Token = strtok(draw_command, "(),");
            strcpy(command, Token);
            command[0] = toupper(command[0]);

            Token = strtok(NULL, "(),");
            num1 = atoi(Token);

            Token = strtok(NULL, "(),");
            num2 = atoi(Token);

            Token = strtok(NULL, "(),");
            num3 = atoi(Token);

            Token = strtok(NULL, "(),");
            strcpy(ch, Token);

            if (ch[0] == '\n')
            {
                ch[0] = '\0';
            }

            if (draw_command[0] == 'P')
            {
                if (num1 >= 0 && num2 >= 0 && num1 < MapSize && num2 < MapSize)
                {
                    map_array[num1][num2 + shift] = letter;
                }
                else
                    printf("\n\nThat draw command is out of range");
            }

            else if (draw_command[0] == 'V')
            {
                if (num1 >= 0 && num2 >= 0 && num3 >= 0 && num1 < MapSize && num2 < MapSize)
                {
                    num4 = MapSize - num1;
                    if (num3 <= num4)
                    {
                        DrawLine(map_array, num1, num2 + shift, draw_command[0], num3, letter);
                    }
                    else
                        printf("\n\nThat draw command is out of range");
                }
                else
                    printf("\n\nThat draw command is out of range");
            }

            else if (draw_command[0] == 'H')
            {
                if (num1 >= 0 && num2 >= 0 && num3 >= 0 && num1 < MapSize && num2 < MapSize)
                {
                    num4 = MapSize - num2;
                    if (num3 <= num4)
                    {
                        DrawLine(map_array, num1, num2 + shift, draw_command[0], num3, letter);
                    }
                    else
                        printf("\n\nThat draw command is out of range");
                }
                else
                    printf("\n\nThat draw command is out of range");
            }

            else
            {
                printf("\n\nThat draw command is unknown");
            }
            TempPtr = FindLetter(TempPtr, letter, draw_command);

        }
        shift = shift + 7;
    }

    PrintMap(map_array);
    return 0;
}