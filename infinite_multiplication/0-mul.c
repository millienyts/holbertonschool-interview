#include "holberton.h"

/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
    char *error = "Error\n";
    int i;

    if (argc != 3 || !is_a_number(argv[1]) || !is_a_number(argv[2]))
    {
        for (i = 0; error[i] != '\0'; i++)
        {
            _putchar(error[i]);
        }
        exit(98);
    }

    multiply(argv[1], argv[2]);
    return (0);
}

/**
 * multiply - Multiplies two numbers represented as strings
 * Arguments
 * @num_1: string representing the first number in base 10
 * @num_2: string representing the second number in base 10
 */
void multiply(char *num_1, char *num_2)
{
    char mul[10][MAX1], answer[MAX1][MAX2];
    int tag, i, j, len_1, len_2, res, value, pos_1, pos_2, row, z;

    for (len_1 = str_len(num_1), len_2 = str_len(num_2), i = 0; i < 10; i++)      
        for (j = 0; j < MAX1; j++)
            mul[i][j] = '.';

    for (i = 0; i < MAX1; i++)
        for (j = 0; j < MAX2; j++)
            answer[i][j] = '.';

    /* 1. Creating multiplication table */
    for (tag = 0, i = 0; i < 10; i++)
    {
        for (j = 0; j <= len_1; j++)
        {
            pos_1 = len_1 - j - 1;
            if (pos_1 >= 0)
            {
                res = ((num_1[pos_1] - 48) * i) + tag;
                value = res % 10;
                mul[i][j] = (value + '0');
                tag = res / 10;
            }
            else
            {
                mul[i][j] = (tag != 0) ? tag + 48 : '.';
                tag = 0;
            }
        }
    }

    /* 2. Creating answer table */
    for (j = 0; j < len_2; j++)
    {
        pos_2 = len_2 - j - 1;
        row = num_2[pos_2] - 48;
        for (z = 0; z < len_1 + 1; z++)
            answer[j][z + j] = mul[row][z];
    }
    sum_and_print(answer, len_1, len_2);
}

/**
 * is_a_number - Indicates if a string represents a number in base 10
 * Arguments
 * @a_str: string representing a number in base 10
 * Return: 1 if true, 0 if not
 */
int is_a_number(char *a_str)
{
    while (*a_str != '\0')
    {
        if (*a_str < '0' || *a_str > '9')
            return (_FALSE_);
        a_str++;
    }
    return (_TRUE_);
}

/**
 * sum_and_print - Adds the numbers in the multiplication table and prints the result
 * Arguments
 * @a: matrix with multiplication results
 * @len_1: length of the first number
 * @len_2: length of the second number
 */
void sum_and_print(char a[MAX1][MAX2], int len_1, int len_2)
{
    int tag = 0, sum, value;
    char total[MAX2];
    int j = 0;

    // 3. Add each column from left to right
    for (int i = 0; i <= (len_1 + len_2); i++) {
        sum = 0;
        for (int k = 0; k < len_2; k++) {
            if (a[k][i] >= '0' && a[k][i] <= '9') 
                sum += a[k][i] - '0';
        }
        value = (sum + tag) % 10;
        total[i] = (value + '0');
        tag = (sum + tag) / 10;
    }

    // Find first non-zero character
    while (j < len_1 + len_2 && total[j] == '0') 
        j++;

    if (j == len_1 + len_2) 
        _putchar('0'); // handle "0" case

    for (; j < len_1 + len_2; j++) 
        _putchar(total[j]);

    putchar('\n');
}

/**
 * str_len - Calculates the length of a string
 * Arguments
 * @a: string to calculate the length of
 * Return: the length of the string
 */
int str_len(char *a)
{
    int i;

    for (i = 0; a[i] != '\0'; i++)
    {
    }
    return (i);
}
