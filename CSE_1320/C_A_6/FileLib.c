//Name:Hasnain Bharmal ID:1001937588
// FileLib Template

#include <stdio.h>
#include <string.h>
#include "ListLib.h"

void get_command_line_parameter(char *argv[], char PName[], char PValue[]);

FILE *OpenFile(int argc, char *argv[])
{
	char Input[25] = {};
	FILE *File_OP;
	if (argc > 1)
	{
		get_command_line_parameter(argv, "FILENAME=", Input);
	}
	else

	{
		printf("Must be run with an input file name. ");
		printf("Enter a file name at the prompt ");
		scanf("%s", Input);
	}
	do
	{
		File_OP = fopen(Input, "r");
		if (File_OP == NULL)
		{
			printf("Could not open file named %s\n", Input);
			printf("Enter a file name at the prompt ");

			fgets(Input, sizeof(Input) - 1, stdin);
			Input[strlen(Input) - 1] = '\0';
			File_OP = fopen(Input, "r");
		}
	} while (File_OP == NULL);

	return File_OP;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	char draw_command[15];
	char draw_command_input[20];
	char *Token = NULL;
	char letter_1[5];

	char letter;

	while (fgets(draw_command_input, 19, DCFile))
	{
		if (draw_command_input[strlen(draw_command_input) - 1] == '\n')
		{
			draw_command_input[strlen(draw_command_input) - 1] = '\0';
		}

		Token = strtok(draw_command_input, "|");
		strcpy(letter_1, Token);

		Token = strtok(NULL, "|");
		strcpy(draw_command, Token);

		AddDrawCommandToList(letter_1[0], draw_command, LinkedListHead);
	}
}

void get_command_line_parameter(char *argv[], char PName[], char PValue[])
{
	int i = 1;
	while (argv[i] != NULL)
	{
		if (!strncmp(argv[i], PName, strlen(PName)))
		{
			strcpy(PValue, strchr(argv[i], '=') + 1);
		}
		i++;
	}
}
