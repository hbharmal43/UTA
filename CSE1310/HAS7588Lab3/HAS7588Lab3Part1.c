/******************************************************************************
 * File: HAB7588Lab3Code
 * Author: Hasnain Bharmal
 * Created on:  November 18, 2021, 11:37 PM
.*
 * UTA Student Name: Hasnain Bharmal
 * UTA ID: 1001937588
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ROW 25
#define COL 3
const int DY=0;
const int MO=1;
const int YR=2;

int checkDate(int day, int month, int year);
int checkLeap(int yr);
void errorMsgs(int flag);
int datePrint(int day, int month, int year);
int addYear(int year);
int priorMonthDays(int month, int year);



void printAmerDate( int day, int month, int year);
void printEuroDate( int day, int month, int year);
void printISODate( int day, int month, int year);
void printSpaceDate( int day, int month, int year);

int main(int argc, char * argv[])
{
    int day[20][50];
    int month[2][50];
    int year[10][50];
    int dates[ROW][COL];
    int invalid=0;
    char line[120];
    char filename[25]="TestDatesData.txt";
    int i= 0;
    int j,r,k;
    int index;
    int c;
    int dateInvalid;
    int diff_year;
    int diff_month;
    int diff_day;
    
    
    strcpy(filename,argv[1]);
    FILE * file;    
    file = fopen(filename,"r");
    printf("The file %s is valid\n",filename);
      if (file == NULL)
    {
        printf("File %s did not open correctly\n",filename);
    }
    else
    {
        printf("File %s opened correctly\n",filename);
    }
    

while (!feof(file))
    {
        fscanf(file,"%d %d %d",&dates[i][DY],&dates[i][MO],&dates[i][YR]);
        i++;
    }

for(k=0;k<i;k++){

        checkDate(dates[k][DY],dates[k][MO],dates[k][YR]);
        checkLeap(dates[k][2]);
         

    }
    

        {
        printf("\n\n");
        printf("Valid dates in the file are:");
        printf("\n");
        printAmerDate(dates[0][DY],dates[0][MO],dates[0][YR]);
        printf("\n");
        printEuroDate(dates[1][DY],dates[1][MO],dates[1][YR]);
        printf("\n");
        printISODate(dates[2][DY],dates[2][MO],dates[2][YR]);
        printf("\n");
        printSpaceDate(dates[3][DY],dates[3][MO],dates[3][YR]);
        printf("\n\n");
        }


 
    for(r=0;r<i-1;r++){
    

    if(dates[r][YR]<dates[r+1][YR])
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR]);
    else if (dates[r][YR]>dates[r+1][YR])
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR]);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]<dates[r+1][MO]))
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR]);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]>dates[r+1][MO]))
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR]);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]==dates[r+1][MO]) || (dates[r][DY]<dates[r+1][DY]))
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR]);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]==dates[r+1][MO]) || (dates[r][DY]>dates[r+1][DY]))
        printf("The dates are %d/%d/%d and %d/%d/%d  and the earlier date is %d/%d/%d \n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR]);
    else 
        printf("The dates are %d/%d/%d and %d/%d/%d  and the both are equal \n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR]);
      

    int sum = priorMonthDays(dates[r][MO], dates[r][YR]) + dates[r][DY];
    if (dates[r+1][YR] > dates[r][YR]) // ****
    {
        sum = addYear(dates[r][YR]) - sum;
    }
     
    // int countYr = dates[r][YR] + 1;
    // while (countYr < dates[r+1][YR])
    // {
    //     sum += addYear(countYr);
    //     printf("Added year %d\n",countYr);
    //     countYr++;
    // }
    int thisYear = priorMonthDays(dates[r+1][MO], dates[r+1][YR]) + dates[r+1][DY];

    if (dates[r+1][YR] == dates[r][YR])   
    {
        sum = thisYear-sum;  
        sum=abs(sum);
    }
    else     
    {
        sum = sum +thisYear;
    }

    if(dates[r][YR]<dates[r+1][YR])
        printf("The numbers of date from later day %d/%d/%d to earlier day %d/%d/%d is %d\n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],sum);
    else if (dates[r][YR]>dates[r+1][YR])
        printf("The numbers of date from earlier day %d/%d/%d to later day %d/%d/%d is %d\n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],sum);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]<dates[r+1][MO]))
        printf("The numbers of date from later day %d/%d/%d to earlier day %d/%d/%d is %d\n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],sum);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]>dates[r+1][MO]))
        printf("The numbers of date from later day %d/%d/%d to earlier day %d/%d/%d is %d\n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],sum);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]==dates[r+1][MO]) || (dates[r][DY]<dates[r+1][DY]))
        printf("The numbers of date from later day %d/%d/%d to earlier day %d/%d/%d is %d\n",dates[r][DY],dates[r][MO],dates[r][YR],dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],sum);
    else if (dates[r][YR]==dates[r+1][YR] || (dates[r][MO]==dates[r+1][MO]) || (dates[r][DY]>dates[r+1][DY]))
        printf("The numbers of date from later day %d/%d/%d to earlier day %d/%d/%d is %d\n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR],sum);
    else 
        printf("The dates are %d/%d/%d and %d/%d/%d  and the both are equal \n",dates[r+1][DY],dates[r+1][MO],dates[r+1][YR],dates[r][DY],dates[r][MO],dates[r][YR]);
    printf("\n");
 
}
  



    
return 0;
}    
 


 int checkDate(int day, int month, int year)
{
    int dateInvalid = 0;  // dateValid will keep track of errors; 0 value indicates error
    
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
    
    if (!dateInvalid)  // This is equivalent to saying (dateInvalid == 0)
    {
        if ( ((month == 4) || (month == 6) || (month == 9) || (month == 11)) &&
                (day > 30))
            dateInvalid = 4;
           
        else if (month == 2)
        {
            if (checkLeap(year) == 0)  // if it is NOT equal to a leap year 
            {
                if (day > 28)
                    dateInvalid = 5;
            }
            else  // it is a leap year
                if (day > 29)
                    dateInvalid = 6;
        }
    }
    errorMsgs(dateInvalid);
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

    if ((yr % 4) != 0)  // yr % 4 - has possible answers of? 0, 1, 2, 3
        leap = 0;
    else if ((yr % 400) == 0)
        leap = 1;
    else if ((yr % 100) == 0)
        leap = 0;
    else
        leap = 1;
    
    return leap;
}
void printSpaceDate( int day, int month, int year)
{
    checkDate(day,month,year);
    printf("%d %d %d", day, month, year);
    return;
}
void printAmerDate( int day, int month, int year)
{
    checkDate(day,month,year);
    printf("%d/%d/%d",month, day, year);
    return;
}
void printEuroDate( int day, int month, int year)
{
    checkDate(day,month,year);
    printf("%d.%d.%d",day,month, year);
    return;
}
void printISODate( int day, int month, int year)
{
    checkDate(day,month,year);
    printf("%d-%d-%d",year, month, day);
    return ;
}
int addYear(int year)
{
    if (checkLeap(year) == 1)
        return 366;
    else 
        return 365;    
}
int priorMonthDays(int month, int year)
{
    // days in whole months
    int sum = 0;
    int lastm = month-1;
    
    if (lastm == 11)
        sum = sum + 30;
    if (lastm >= 10)
        sum = sum + 31;
    if (lastm >= 9)
        sum = sum + 30;
    if (lastm >= 8)
        sum += 31;
    if (lastm >= 7)
        sum += 31;
    if (lastm >= 6)
        sum += 30;   
    if (lastm >= 5)
        sum += 31;  
    if (lastm >= 4)
        sum += 30;  
    if (lastm >= 3)
        sum += 31;   
    if (lastm >= 2)
        if (checkLeap(year) == 1)  // checks user input year
            sum += 29;
        else
            sum += 28;
    if (lastm >= 1)
        sum += 31;
        
    // sum will be all the days in the months PRIOR to the current month in this year
    return sum;           
}
