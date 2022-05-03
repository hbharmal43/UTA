/* Coding Assignment 5 */

/* Add necessary includes */
// Name:Hasnain Bharmal ID:1001937588

#include <stdio.h>
#include "GameLib.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;
	char *check;
	/* Call StartGame and pass in Phrase */
	StartGame(Phrase);
	/* Call DashIt and pass in Phrase and DashedPhrase */
	DashIt(Phrase, DashedPhrase);
	for (i = 0; i < strlen(Phrase) + 1; i++)
	{
		UpperPhrase[i] = toupper(Phrase[i]);
	}
	printf("\nHere's the phrase you need to guess\n");

	do
	{
		/* if !(call GuessALetter and pass Phrase, DashedPhrase and UpperPhrase) */
		if (!GuessALetter(Phrase, DashedPhrase, UpperPhrase))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	} while (strchr(DashedPhrase, '-') && Strikes < STRIKES);
	/* while (call strchr() with DashedPhrase with -) AND strike counter is less than strikes define */

	if (Strikes < STRIKES)
	{
		printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
		printf("\n\nYOU WIN!!!!\n");
	}
	else
	{
		printf("\n\n");
		printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
		printf("Game over\n\n");
	}
	return 0;
}
