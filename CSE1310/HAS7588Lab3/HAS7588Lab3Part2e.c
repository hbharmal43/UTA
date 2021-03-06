/******************************************************************************
 * File: HAB7588Lab3Part2eCode
 * Author: Hasnain Bharmal
 * Created on:  November 20, 2021, 11:37 PM
.*
 * UTA Student Name: Hasnain Bharmal
 * UTA ID: 1001937588
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int REL = 0;
const int LAST = 7;
const int FIRST = 8;
const int GEN = 3;
const int DY = 4;
const int MO = 5;
const int YR = 6;
const int AGE = 2;
int k;

int checkDate(int day, int month, int year);
int checkGender(char i);
int checkLeap(int yr);
int findAge(int currentYear, int birthYear);
int findoldest(double peopAge[], int n, int currentYear, int peopDob[][YR]);

int main(int argc, char *argv[])
{
    char peopName[15][3][35];
    char peopGen[15];
    double peopAge[15];
    int peopDob[15][3];
    char filename[20] = "people.txt";
    int i = 0;
    char tempRelation[35];
    char tempFirst[25];
    char tempLast[25];
    double tempAge = 0;
    char tempGender;
    int tempDay = 0;
    int tempMonth = 0;
    int tempYear = 0;
    time_t now;
    int currentyear;

    time(&now);
    struct tm *local = localtime(&now);

    currentyear = local->tm_year + 1900; // get year since 1900

    strcpy(filename, argv[1]);
    FILE *file = fopen(filename, "r");
    FILE*OutFile = fopen("peopleOut.txt","a");

    if (file == NULL)
    {
        printf("File %s did not open correctly or file does not exist", filename);
        fprintf(OutFile,"File %s did not open correctly or file does not exist", filename);
        exit(0);
    }
    else
    {
        printf("File %s opened correctly\n", filename);
        fprintf(OutFile,"File %s opened correctly\n", filename);
    }
    while (!feof(file))
    {

        fscanf(file, "%s %lf %c %d %d %d %[^,]%s %[^\n]", &tempRelation, &tempAge, &tempGender, &tempDay, &tempMonth, &tempYear, &tempLast, &tempFirst);
        if ((tempAge > 0) && (checkGender(tempGender)) && (!checkDate(tempDay, tempMonth, tempYear)))
        {
            strcpy(peopName[i][REL], tempRelation);
            peopAge[i] = tempAge;
            peopGen[i] = tempGender;
            peopDob[i][DY] = tempDay;
            peopDob[i][MO] = tempMonth;
            peopDob[i][YR] = tempYear;
            strcpy(peopName[i][LAST], tempLast);
            strcpy(peopName[i][FIRST], tempFirst);
            i++;
        }
    }

    for (k = 0; k < i; k++)
    {

        if (!(findAge(currentyear, peopDob[k][YR]) == peopAge[k] || findAge(currentyear, peopDob[k][YR]) == peopAge[k] + 1 || findAge(currentyear, peopDob[k][YR]) == peopAge[k] - 1))
        {
            printf("\n%s %s, %s, passed away at peopAge %lf\n", peopName[k][FIRST], peopName[k][LAST], peopName[k][REL], peopAge[k]);
            fprintf(OutFile,"\n%s %s, %s, passed away at peopAge %lf\n", peopName[k][FIRST], peopName[k][LAST], peopName[k][REL], peopAge[k]);

        }
    }

    int oldestRow = findoldest(peopAge, i, currentyear, peopDob);
    printf("\nAt peopAge %lf, %s %s was born on %d/%d/%d and is the oldest living person in the file\n", peopAge[oldestRow], peopName[oldestRow][FIRST], peopName[oldestRow][LAST], peopDob[oldestRow][DY], peopDob[oldestRow][MO], peopDob[oldestRow][YR]);
    fprintf(OutFile,"\nAt peopAge %lf, %s %s was born on %d/%d/%d and is the oldest living person in the file\n", peopAge[oldestRow], peopName[oldestRow][FIRST], peopName[oldestRow][LAST], peopDob[oldestRow][DY], peopDob[oldestRow][MO], peopDob[oldestRow][YR]);

    return 0;
}

int findoldest(double peopAge[], int n, int currentyear, int peopDob[][3])
{
    double oldest = 0;
    int row = 0;
    for (int i = 0; i < n; i++)
    {

        if (oldest < peopAge[i] && (findAge(currentyear, peopDob[i][YR]) == peopAge[i] || findAge(currentyear, peopDob[i][YR]) == peopAge[i] + 1 || findAge(currentyear, peopDob[i][YR]) == peopAge[i] - 1))
        {
            oldest = peopAge[i];
            row = i;
        }
    }

    return row;
}
int findAge(int currentYear, int birthYear)
{
    return (currentYear - birthYear);
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
