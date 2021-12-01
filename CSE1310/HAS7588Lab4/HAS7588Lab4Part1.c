/******************************************************************************
 * File: HAB7588Lab3Part2Code
 * Author: Hasnain Bharmal
 * Created on:  November 20, 2021, 11:37 PM
.*
 * UTA Student Name: Hasnain Bharmal
 * UTA ID: 1001937588
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



//Constants
const int REL = 0;
const int LAST = 1;
const int FIRST = 2;
const int DY = 0;
const int MO = 1;
const int YR = 2;
//Max constants
const int MAXR = 25;
const int MAXC = 3;
const int MAXLEN = 35;

int filerows = 0;

int checkDate(int day, int month, int year);
int checkGender(char i);
int checkLeap(int yr);
void swap(int rw, char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);
void printTable(char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);
void sortAge(int k, char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);
void sortRel(int size, char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);
void sortName(int size ,char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);
void sortDate(int size ,char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC]);


int main(int argc, char *argv[])
{
    //Data Arrays

    char peopName[MAXR][MAXC][MAXLEN]; //contains first name and last name
    char peopGen[MAXR];                //contains people's gender
    double peopAge[MAXR];              //contains people's Age
    int peopDob[MAXR][MAXC];           //contains people's Date of Birth

    char filename[20] = "people.txt";
    int i = 0;
    int k;
    char tempRelation[35];
    char tempFirst[25];
    char tempLast[25];
    double tempAge = 0;
    char tempGender;
    int tempDay = 0;
    int tempMonth = 0;
    int tempYear = 0;
    char comma =' ';
    strcpy(filename, argv[1]);
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("File %s did not open correctly or file does not exist", filename);
        exit(0);
    }
    else
    {
        printf("File %s opened correctly\n", filename);
    }
    while (!feof(file))
    {

        fscanf(file, "%s %lf %c %d %d %d %s %[^\n]", &tempRelation, &tempAge, &tempGender, &tempDay, &tempMonth, &tempYear, &tempLast, &tempFirst);   
         if ((tempAge > 0) && (checkGender(tempGender)) && (!checkDate(tempDay, tempMonth, tempYear)))
        {
            strcpy(peopName[i][REL], tempRelation);
            peopAge[i] = tempAge;
            peopGen[i] = toupper(tempGender);
            peopAge[i] = tempAge;
            peopGen[i] = tempGender;
            peopDob[i][DY] = tempDay;
            peopDob[i][MO] = tempMonth;
            peopDob[i][YR] = tempYear;
            strcpy(peopName[i][LAST], tempLast);
            strcpy(peopName[i][FIRST], tempFirst);
            // toupper(peopName[i][REL][0]);
            i++;
            filerows = i;
        }
    }
    // printTable(peopName, peopGen, peopAge, peopDob);

    //swap(1, peopName, peopGen, peopAge, peopDob);
    // BubbleSortDay(peopAge,filerows);
    //printTable(peopName, peopGen, peopAge, peopDob);
   sortAge(filerows, peopName, peopGen, peopAge, peopDob);
    //printTable(peopName, peopGen, peopAge, peopDob);
    //printTable(peopName, peopGen, peopAge, peopDob);
  //  sortRel(filerows, peopName, peopGen, peopAge, peopDob);
   //sortAge(filerows, peopName, peopGen, peopAge, peopDob);
    //printTable(peopName, peopGen, peopAge, peopDob);
    //printTable(peopName, peopGen, peopAge, peopDob);
    //sortRel(filerows, peopName, peopGen, peopAge, peopDob);
    // sortName(filerows, peopName, peopGen, peopAge, peopDob);
    //sortDate(filerows, peopName, peopGen, peopAge, peopDob);
    printTable(peopName, peopGen, peopAge, peopDob);


    return 0;
}

void swap(int rw, char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    char peopFirstNameTemp[MAXLEN];
    char peopRelationTemp[MAXLEN];
    char peopLastNameTemp[MAXLEN];
    char peopGenTemp;
    double peopAgeTemp;
    int peopDobDay, peopDobMonth, peopDobYear;
    //Swapping peopName array elements
    //Swapping FirstName
    strcpy(peopFirstNameTemp, peopName[rw][FIRST]);       //Store rw index firstName in temp
    strcpy(peopName[rw][FIRST], peopName[rw + 1][FIRST]); // Store rw+1 data in rw element
    strcpy(peopName[rw + 1][FIRST], peopFirstNameTemp);   //Store temp
    //Swapping Lastname
    strcpy(peopLastNameTemp, peopName[rw][LAST]);       //Store rw index lastName in temp
    strcpy(peopName[rw][LAST], peopName[rw + 1][LAST]); // Store rw+1 data in rw element
    strcpy(peopName[rw + 1][LAST], peopLastNameTemp);   //Store temp
    //swapping relationship
    strcpy(peopRelationTemp, peopName[rw][REL]);       //Store rw index lastName in temp
    strcpy(peopName[rw][REL], peopName[rw + 1][REL]); // Store rw+1 data in rw element
    strcpy(peopName[rw + 1][REL], peopRelationTemp);
    
    
    
    //swapping Age
    peopAgeTemp = peopAge[rw];     // storing rw age in temp
    peopAge[rw] = peopAge[rw + 1]; //storing rw age in rw+1 age
    peopAge[rw + 1] = peopAgeTemp; // storing tem age in rw age
    //swawpping Gender
    peopGenTemp = peopGen[rw];
    peopGen[rw] = peopGen[rw + 1];
    peopGen[rw + 1] = peopGenTemp;
    // swapping day
    peopDobDay = peopDob[rw][DY];
    peopDob[rw][DY] = peopDob[rw + 1][DY];
    peopDob[rw + 1][DY] = peopDobDay;
    // swapping month
    peopDobMonth = peopDob[rw][MO];
    peopDob[rw][MO] = peopDob[rw + 1][MO];
    peopDob[rw + 1][MO] = peopDobMonth;
    //swapping year
    peopDobYear = peopDob[rw][YR];
    peopDob[rw][YR] = peopDob[rw + 1][YR];
    peopDob[rw + 1][YR] = peopDobYear;
}

void printTable(char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    printf("==============================================================================================================");
    printf("\nRelationship  \t Age \t Gender \t DD/MM/YY\tLastname\tFirstname\n");
    for (int k = 0; k < filerows; k++)
    {   //printf("%s",toupper(peopName[k][REL][0]));
        printf("%-15s  %4.2f %7c %12d/%d/%d \t %-20s %-20s\n", peopName[k][REL], peopAge[k], peopGen[k], peopDob[k][DY], peopDob[k][MO], peopDob[k][YR], peopName[k][LAST], peopName[k][FIRST]);

    }
    printf("==============================================================================================================");
}

void sortAge(int size, char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    // printf("\n<sortAge> Entered\n");
    // printf("\n<sortAge> size = %d\n",size);
    for (int step = 0; step < size - 1; step++)
    {
        // printf("\n<sortAge> Pass = %d\n",step);
        // printTable(peopName, peopGen, peopAge, peopDob);
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++)
        {
            // printf("\n<sortAge> I = %d\n",i);
            // compare two adjacent elements
            // change > to < to sort in descending order
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i,peopAge[i]);
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i+1,peopAge[i+1]);
            if (peopAge[i] > peopAge[i + 1])
            {
                // printf("\n<sortAge> peopAge[%d] > peopAge[%d]",i,i+1);
                swap(i, peopName, peopGen, peopAge, peopDob);
            }
        }
    }
}

 void sortRel(int size ,char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    // printf("%c\n",peopGen[0]);
    // printf("%c\n",peopGen[1]);
    // printf("%c\n",peopGen[2]);

for (int step = 0; step < size - 1; step++)
    {
        // printf("\n<sortAge> Pass = %d\n",step);
        // printTable(peopName, peopGen, peopAge, peopDob);
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++)
        {
            //printf("\n<sortAge> I = %d\n",i);
            // compare two adjacent elements
            //printf("%s and %s\n",peopName[i],peopName[i+1]);
            // change > to < to sort in descending order
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i,peopAge[i]);
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i+1,peopAge[i+1]);
            if (strcmp(peopName[i][REL],peopName[i + 1][REL])>0)
            {
                swap(i, peopName, peopGen, peopAge, peopDob);

            }
        }
    }
}

 void sortName(int size ,char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    // printf("%c\n",peopGen[0]);
    // printf("%c\n",peopGen[1]);
    // printf("%c\n",peopGen[2]);

for (int step = 0; step < size - 1; step++)
    {
        // printf("\n<sortAge> Pass = %d\n",step);
        // printTable(peopName, peopGen, peopAge, peopDob);
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++)
        {
            //printf("\n<sortAge> I = %d\n",i);
            // compare two adjacent elements
            //printf("%s and %s\n",peopName[i],peopName[i+1]);
            // change > to < to sort in descending order
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i,peopAge[i]);
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i+1,peopAge[i+1]);
            if (strcmp(peopName[i][LAST],peopName[i + 1][LAST])<0 )
            {
                //printf("what");
                swap(i, peopName, peopGen, peopAge, peopDob);

            }
            else{
                if (strcmp(peopName[i][FIRST],peopName[i + 1][FIRST])>0)
            {
                //printf("what");
                swap(i, peopName, peopGen, peopAge, peopDob);

            }
            }
        }
    }
}

 void sortDate(int size ,char peopName[][MAXC][MAXLEN], char peopGen[], double peopAge[], int peopDob[][MAXC])
{
    // printf("%c\n",peopGen[0]);
    // printf("%c\n",peopGen[1]);
    // printf("%c\n",peopGen[2]);

for (int step = 0; step < size - 1; step++)
    {
        // printf("\n<sortAge> Pass = %d\n",step);
        // printTable(peopName, peopGen, peopAge, peopDob);
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++)
        {
            //printf("\n<sortAge> I = %d\n",i);
            // compare two adjacent elements
            //printf("%s and %s\n",peopName[i],peopName[i+1]);
            // change > to < to sort in descending order
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i,peopAge[i]);
            // printf("\n<sortAge> peopAge[%d] = %lf\n",i+1,peopAge[i+1]);
            if (peopDob[i][MO]>peopDob[i+1][MO])
            {   
                swap(i, peopName, peopGen, peopAge, peopDob);
            }
            else if (peopDob[i][MO]==peopDob[i+1][MO] && peopDob[i][DY]>peopDob[i+1][DY])
            {
                swap(i, peopName, peopGen, peopAge, peopDob);          
            }
        }
    }
}

int checkGender(char i)
{
    if (i == 'M' || i == 'F' || i == 'N' || i == 'U')
    {
        return 1;
    }
    return 0;
}

int checkDate(int day, int month, int year)
{
    int dateInvalid = 0; // dateValid will keep track of errors; 0 value indicates error

    if ((year < 1000) || (year > 9999))
        dateInvalid = 1;

    else if ((month < 1) || (month > 12))
        dateInvalid = 2;

    else if ((day < 1) || (day > 31))
        dateInvalid = 3;

    /* 
     * At this point, if dateInvalid 1= 0, then there is an error
     * Therefore, we only want to continue if there are no errors
     * At this point, we now need to check if days and months are valid with each other
     * For example, we can't have Sept 31 or Feb 30
     */

    if (!dateInvalid) // This is equivalent to saying (dateInvalid == 0)
    {
        if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) &&
            (day > 30))
            dateInvalid = 4;

        else if (month == 2)
        {
            if (checkLeap(year) == 0) // if it is NOT equal to a leap year
            {
                if (day > 28)
                    dateInvalid = 5;
            }
            else // it is a leap year
                if (day > 29)
                dateInvalid = 6;
        }
    }
    //errorMsgs(dateInvalid);
    return dateInvalid;
}

void errorMsgs(int flag)
{
    switch (flag)
    {
    case 1:
        printf("\nError: Year is out of 4 digit range  ");
        break;
    case 2:
        printf("\nError: Month is out of valid range  ");
        break;
    case 3:
        printf("\nError: Day is out of valid range  ");
        break;
    case 4:
        printf("\nError: Day is out of range for given month with 30 days  ");
        break;
    case 5:
        printf("\nError: Day is out of range for given month and year  ");
        break;
    case 6:
        printf("\nError: Day is out of range for given month and leap year  ");
        break;
    default:
        break;
    }
}

int checkLeap(int yr)
{
    /*
     * A year is a leap year if 
     * it is divisible by 4 and NOT divisible by 100 
     * UNLESS it is divisible by 400
     */
    int leap = 0;

    if ((yr % 4) != 0) // yr % 4 - has possible answers of? 0, 1, 2, 3
        leap = 0;
    else if ((yr % 400) == 0)
        leap = 1;
    else if ((yr % 100) == 0)
        leap = 0;
    else
        leap = 1;

    return leap;
}
