//Name:Hasnain Bharmal
//ID: 1001937588
// command to compile-> gcc -o hab7588_3318_lab1 hab7588_3318_lab1.c
/* To get input from other file
 First file: ./hab7588_3318_lab1 < a.dat
 Second file: ./hab7588_3318_lab1 < b.dat */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <

void Swap(int *array, int i, int swap);
int binSearchFirst(int *a, int n, int key);
int binSearchLast(int *a, int n, int key);

int main(void)
{
    char line[10];
    printf("How many counters do you want ? ");
    fgets(line, 9, stdin);
    line[strlen(line) - 1] = '\0';
//  line[strlen(line) - 1] = '\n';

    int aarray_n = 0;
    sscanf(line, "%d", &aarray_n);
    int map[aarray_n], index[aarray_n], count[aarray_n];
    int i;
    for (i = 0; i < aarray_n; i++)
    {
        map[i] = i;
        index[i] = i;
        count[i] = 0;
    }
    printf("\nEnter operations : \n");
    while (fgets(line, 9, stdin))
    {
        line[strlen(line) - 1] = '\0';

        int operation = 0;
        sscanf(line, "%d", &operation);
        //sscanf(line1, "%d", operation);

        if (operation == 0) //<-- Operation 0
        {
            return 0;
        }
        else if (operation == 1)  //<-- Operation 1
        {
            printf("print by index\n");
            int i;
            for (i = 0; i < aarray_n; i++)
            {
                printf("%d %d\n", i, count[map[i]]);
            }
            printf("---------\n");
        }
        else if (operation == 2)   //<-- Operation 2
        {
            printf("print by count\n");
            int i;
            for (i = 0; i < aarray_n; i++)
            {
                printf("%d %d\n", index[i], count[i]);
            }
            printf("---------\n");
        }
        else if (operation == 3)  //<-- Operation 3
        {
            int i;
            sscanf(line, "%d %d", &operation, &i);
            int second = binSearchLast(count, aarray_n, count[map[i]]);
            count[map[i]]++;
            int mapswap = index[second];
            Swap(index, map[i], second);
            Swap(count, map[i], second);
            Swap(map, i, mapswap);
        }
        else if (operation == 4)   //<-- Operation 4
        {
            int i;
            sscanf(line, "%d %d", &operation, &i);
            int second = binSearchFirst(count, aarray_n, count[map[i]]);
            count[map[i]]--;
            int mapswap = index[second];
            Swap(index, map[i], second);
            Swap(count, map[i], second);
            Swap(map, i, mapswap);
        }
        else if (operation == 5)  //<-- Operation 5
        {
            int smaller;
            int larger;
            sscanf(line, "%d %d %d", &operation, &smaller, &larger);
            int counter = 0;
            int i;
            for (i = 0; i < aarray_n; i++)
            {
                if (count[i] >= smaller && count[i] <= larger)
                {
                    counter++;
                }
            }
            printf("%d counter valued between %d and %d\n", counter, smaller, larger);
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    return 0;
}

void Swap(int *array, int i, int second) //Swapping function
{
    int temp = array[i];
    array[i] = array[second];
    array[second] = temp;
    return;
}
int binSearchFirst(int *a, int n, int key) // binary search first
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int binSearchLast(int *a, int n, int key) // binary search last
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] <= key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
