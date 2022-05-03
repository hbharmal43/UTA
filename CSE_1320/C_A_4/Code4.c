//Name:Hasnain Bharmal ID:1001937588

#include "DrawTool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int num1, num2, num3, num4;
    char temp_num1[1], temp_num2[1], temp_num3[1], temp_draw_command[1], temp_ch[1];
    char draw_command_input[20], ch[5], draw_command[5];
    char map_array[MAXMAPSIZE][MAXMAPSIZE];
    int MapSize;
    char *piece = NULL;

    InitializeMap(map_array, &MapSize);
    PrintInstructions();
    PrintMap(map_array, MapSize);

    printf("\nEnter draw command (enter Q to quit)");
    fgets(draw_command_input, 19, stdin);

    piece = strtok(draw_command_input, "(),");
    strcpy(draw_command, piece);
    draw_command[0] = toupper(draw_command[0]);

    while (draw_command[0] != 'Q')
    {
        piece = strtok(NULL, "(),");
        num1 = atoi(piece);

        piece = strtok(NULL, "(),");
        num2 = atoi(piece);

        piece = strtok(NULL, "(),");
        num3 = atoi(piece);

        piece = strtok(NULL, "(),");
        strcpy(ch, piece);

        if (ch[0] == '\n')
        {
            ch[0] = 'X';
        }

        if (draw_command[0] == 'P')
        {
            if (num1 >= 0 && num2 >= 0 && num1 < MapSize && num2 < MapSize)
            {
                map_array[num1][num2] = ch[0];
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
                    DrawLine(map_array, num1, num2, draw_command[0], num3, ch[0]);
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
                    DrawLine(map_array, num1, num2, draw_command[0], num3, ch[0]);
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

        PrintMap(map_array, MapSize);

        printf("Enter draw command (enter Q to quit)");
 
        fgets(draw_command_input, 19, stdin);
        piece = strtok(draw_command_input, "(),");
        strcpy(draw_command, piece);
        draw_command[0] = toupper(draw_command[0]);
    }
    return 0;
}