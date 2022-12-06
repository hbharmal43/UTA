/*
Name: Hasnain Bharmal
ID: 1001937588
Commands for compiling:
1) gcc -o lab3 lab3.c
2) ./lab3 < input.txt
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void subsetSum(int n, int total_1, int total_2, int *S, int ***C)
{
  int j, pS, leftover;

  (*C)[0][0] = 0;

  for (pS = 1; pS <= total_2; pS++)
  {
    for (j = 1; j <= n; j++)
    {
      leftover = pS - S[j];
      if (leftover >= 0 && (*C)[0][leftover] < j)
        break;
    }
    (*C)[0][pS] = j;
  }

  for (pS = 1; pS <= total_1; pS++)
  {
    for (j = 1; j <= n; j++)
    {
      leftover = pS - S[j];
      if (leftover >= 0 && (*C)[leftover][0] < j)
        break;
    }
    (*C)[pS][0] = j;
  }
}

void make2darray(int total_1, int total_2, int ***C)
{
  *C = (int **)malloc(sizeof(int *) * (total_1 + 1));
  int i;
  for (i = 0; i <= total_1; i++)
  {
    (*C)[i] = (int *)malloc(sizeof(int) * (total_2 + 1));
  }
}

void backtrace(int n, int total_1, int total_2, int *S, int **CM)
{
  int m1 = total_1;
  int m2 = total_2;

  if (CM[total_1][total_2] == (n + 1))
  {
    printf("No solution\n");
  }
  else
  {
    int solutions1[total_1];
    int solutions2[total_2];
    int solution1count = 0, solution2count = 0;

    while (total_1 > 0 || total_2 > 0)
    {
      if (total_2 - S[CM[total_1][total_2]] >= 0)
      {
        solutions2[solution2count] = CM[total_1][total_2];
        solution2count++;
        total_2 = total_2 - S[CM[total_1][total_2]];
      }

      else if (total_1 - S[CM[total_1][total_2]] >= 0)
      {
        solutions1[solution1count] = CM[total_1][total_2];
        solution1count++;
        total_1 = total_1 - S[CM[total_1][total_2]];
      }
    }

    int i;
    printf("subsequence for %d : \n", m2);
    for (i = solution2count - 1; i > -1; i--)
    {
      printf("%d %d\n", solutions2[i], S[solutions2[i]]);
    }
    printf("subsequence for %d : \n", m1);
    for (i = solution1count - 1; i > -1; i--)
    {
      printf("%d %d\n", solutions1[i], S[solutions1[i]]);
    }
  }
}

void matrix(int n, int total_1, int total_2, int *S, int ***C)
{
  int i, j, k;
  for (i = 1; i <= total_1; i++)
  {
    for (j = 1; j <= total_2; j++)
    {
      for (k = 1; k <= n; k++)
      {
        if ((i - S[k]) >= 0 && (j - S[k]) >= 0)
        {
          if ((*C)[i - S[k]][j] < k)
          {
            break;
          }
          else if ((*C)[i][j - S[k]] < k)
          {
            break;
          }
        }

        else if ((i - S[k]) >= 0 && !(j - S[k]) >= 0)
        {
          if ((*C)[i - S[k]][j] < k)
          {
            break;
          }
        }

        else if ((j - S[k]) >= 0 && !(i - S[k]) >= 0)
        {
          if ((*C)[i][j - S[k]] < k)
          {
            break;
          }
        }
      }
      (*C)[i][j] = k;
    }
  }
}

int main(void)
{
  char line[20];
  fgets(line, 19, stdin);
  line[strlen(line) - 1] = '\0';

  int n, total_1, total_2;
  sscanf(line, "%d %d %d", &n, &total_1, &total_2);

  int *sequence = malloc(sizeof(int) * (n + 1));
  int i;

  sequence[0] = 0;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &sequence[i]);
  }

  printf("total_gets are %d and %d\n", total_1, total_2);
  printf(" i    S\n------\n");

  for (i = 0; i <= n; i++)
  {
    printf(" %d   %d\n", i, sequence[i]);
  }

  int **C;
  make2darray(total_1, total_2, &C);
  subsetSum(n, total_1, total_2, sequence, &C);
  matrix(n, total_1, total_2, sequence, &C);

  backtrace(n, total_1, total_2, sequence, C);

  free(sequence);
  free(C);
  return 0;
}
