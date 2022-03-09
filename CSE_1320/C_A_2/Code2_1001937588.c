/*
Name:Hasnian Bharmal
Student ID:1001937588
*/

#include <stdio.h>
#define BITS 8
void ConvertDecimalToBinary(int d, char ch_array[]);
int main()
{
    int num1, num2;
    char bitop[3];
    char and = '&';
    char temp[25];
    int digit = 1;
    char num1_ch[BITS + 1];
    char num2_ch[BITS + 1];
    int answer;
    char answer_ch[BITS + 1];


    printf("\nBitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result\nand the binary result.\tThe format is\n\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n\n");
    printf("For example, enter the expression\n");
    printf("\n2 & 3\n");
    printf("\nThis calculator can used with &, |, ^, << and >>");
    printf("Please note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");

    printf("Enter expression ");
    scanf("%d %s%d", &num1, bitop, &num2);

    while (num1 < 0 || num1 > 255 || num2 < 0 || num2 > 255)
    {
        printf("\nThe entered expression contains out of range values.\nPlease reenter the expression using values between 0 and 255.\n");
        scanf("%d %s%d", &num1, bitop, &num2);
    }
    if (bitop[0] == '&')
    {
        answer = num1 & num2;
        printf("\nIn base 10...\n");
        printf("\n%d %s %d = %d\n", num1, bitop, num2, answer);
    }

    else if (bitop[0] == '|')

    {
        answer = num1 | num2;
        printf("\nIn base 10...\n");
        printf("\n%d %s %d = %d\n", num1, bitop, num2, answer);
    }

    else if (bitop[0] == '^')
    {
        answer = num1 ^ num2;
        printf("\nIn base 10...\n");
        printf("\n%d %s %d = %d\n", num1, bitop, num2, answer);
    }

    else if (bitop[0] == '<' && bitop[1] == '<')
    {
        answer = num1 << num2;
        printf("\nIn base 10...\n");
        printf("\n%d %s %d = %d\n", num1, bitop, num2, answer);
    }

    else if (bitop[0] == '>' && bitop[1] == '>')
    {
        answer = num1 >> num2;
        printf("\nIn base 10...\n");
        printf("\n%d %s %d = %d\n", num1, bitop, num2, answer);
    }
    else
    printf("\nOperator %s is not supported by this calculator", bitop);
    ConvertDecimalToBinary(num2, num2_ch);
    ConvertDecimalToBinary(num1, num1_ch);
    ConvertDecimalToBinary(answer, answer_ch);

    if (bitop[0] == '&' || bitop[0] == '|' || bitop[0] == '^')
    {
        printf("\nIn 8-bit base 2...\n");
        printf("\n %s\n", num1_ch);
        printf("%s\n", bitop);
        printf(" %s\n", num2_ch);
        printf(" ========");
        printf("\n %s\n", answer_ch);
    }
    else if (!(bitop[0] == '&' || bitop[0] == '|' || bitop[0] == '^' || bitop[0] == '<' || bitop[0] == '>'))
    {
    }
    else
    {
        printf("\nIn 8-bit base 2...\n");
        printf("\n%s   ", num1_ch);
        printf("%s ", bitop);
        printf("%d", num2);
        printf("\n\n%s\n", answer_ch);
    }

    return 0;
}

void ConvertDecimalToBinary(int d, char ch_array[])
{
    int temp[BITS];
    for (int i = 0; i < BITS; i++)
    {
        temp[i] = d;
        d = d >> 1;
    }
    int bmask = 1;
    for (int i = 0; i < BITS; i++)
    {
        temp[i] = temp[i] & bmask;
    }
    int n = 0;
    for (int i = BITS - 1; i > -1; i--, n++)
    {
        ch_array[n] = temp[i] + '0';
    }
    ch_array[n] = '\0';
}
