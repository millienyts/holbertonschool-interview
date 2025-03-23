#include "holberton.h"

/**
 * wildcmp - compares two strings recursively
 * one string can contain wildcard chracters that represent any string
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if the strings are considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    return (wildcompare(s1, s2, 0));
}

/**
 * wildcompare - compares two strings recursively with wildcard count
 * one string can contain wildcard chracters that represent any string
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 * @wildcard: flag for if wildcard has been seen
 *
 * Return: 1 if the strings are considered identical, 0 otherwise
 */
int wildcompare(char *s1, char *s2, int wildcard)
{
    size_t back_count = 0;

    if (s1 && s2 == NULL)
        return (1);
    if (s1 == NULL)
        return (0);
    if (s2 == NULL)
        return (0);
    if (s1[0] == '\0' && s2[0] == '\0')
        return (1);
    if (s2[0] == '*')
    {
        wildcard = 1;
        s2 = forward_wildcard(s2);
        s1 = forward_to_char(s1, s2[0]);
        return (wildcompare(s1, s2, wildcard));
    }
    if (s1[0] != s2[0] && wildcard)
    {
        back_count = backward_wildcard(s2, 0);
        s2 -= back_count;
        s1 -= back_count;
        if (s1[0] == '\0' || s1[1] == '\0')
            return (0);
        s1 += 2;
        return (wildcompare(s1, s2, wildcard));
    }
    else if (s1[0] != s2[0])
        return (0);
    s1++;
    s2++;
    return (wildcompare(s1, s2, wildcard));
}

/**
 * forward_wildcard - moves the second string past wildcard characters
 *
 * @s2: the second string to move
 *
 * Return: new pointer to the second string at next character after wildcards
 */
char *forward_wildcard(char *s2)
{
    if (s2[0] == '*')
    {
        s2++;
        return (forward_wildcard(s2));
    }
    return (s2);
}

/**
 * forward_to_char - moves the first string to the next matching character
 * or null byte, if there is no possible match
 *
 * @s1: the first string to move
 * @c: the character to match
 *
 * Return: new pointer to the first string at matching character or null byte
 */
char *forward_to_char(char *s1, char c)
{
    if (s1[0] != c && s1[0] != '\0')
    {
        s1++;
        return (forward_to_char(s1, c));
    }
    return (s1);
}

/**
 * backward_wildcard - counts how many characters since the last seen wildcard
 *
 * @s2: the second string to move backwards
 * @back_count: count of how many characters moving backwards to reach wildcard
 *
 * Return: the count of characters since last wildcard
 */
size_t backward_wildcard(char *s2, size_t back_count)
{
    if (s2[0] != '*')
    {
        s2--;
        back_count++;
        return (backward_wildcard(s2, back_count));
    }
    return (back_count);
}
