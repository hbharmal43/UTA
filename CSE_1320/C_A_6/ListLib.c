//Name:Hasnain Bharmal ID:1001937588
/* ListLib-Template */

#include "ListLib.h"
#include <stdio.h>
#include <string.h>
void AddDrawCommandToList(char letter, char drawcommand[], NODE **LinkListHead)
{
	NODE *TempPtr , *NewNode;

	NewNode = malloc(sizeof(NODE));

	NewNode->Letter = letter;
	NewNode->DrawCommand = malloc(strlen(drawcommand) + 1);
	strcpy(NewNode->DrawCommand,drawcommand);

	NewNode->next_ptr = NULL;
	TempPtr = *LinkListHead;

	if (*LinkListHead == NULL)
	{
		(*LinkListHead) = NewNode;
	}
	else
	{ 
		while (TempPtr->next_ptr != NULL)
		{
			TempPtr = TempPtr->next_ptr;
		}
		TempPtr->next_ptr = NewNode;
	}
}
NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	NODE *TempPtr = LinkedListHead;

	while ((TempPtr != NULL) && (TempPtr->Letter != Letter))
	{
		TempPtr = TempPtr->next_ptr;
	}

	if (TempPtr != NULL)
	{
		strcpy(DC, TempPtr->DrawCommand);
		return TempPtr->next_ptr;
	}
	else
	{
		memset(DC, '\0', sizeof(*DC)); 
		return TempPtr;
	}
}
