#include "holberton.h"

/**
 * wildcmp - Compares two strings recursively.
 * One string can contain wildcard characters ('*')
 * that represent any string (including an empty one).
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings are considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
    return (wildcompare(s1, s2, 0));
}

/**
 * wildcompare - Recursively compares two strings with wildcard support.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @wildcard: Flag to track wildcard occurrences.
 *
 * Return: 1 if the strings match, 0 otherwise.
 */
int wildcompare(char *s1, char *s2, int wildcard)
{
    size_t back_count = 0;

    if (s1 == NULL && s2 == NULL)
        return (1);
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s2 == '*')
    {
        wildcard = 1;
        s2 = forward_wildcard(s2);
        s1 = forward_to_char(s1, *s2);
        return (wildcompare(s1, s2, wildcard));
    }
    if (*s1 != *s2 && wildcard)
    {
        back_count = backward_wildcard(s2, 0);
        s2 -= back_count;
        s1 -= back_count;
        if (*s1 == '\0' || *(s1 + 1) == '\0')
            return (0);
        s1 += 2;
        return (wildcompare(s1, s2, wildcard));
    }
    else if (*s1 != *s2)
        return (0);
    return (wildcompare(s1 + 1, s2 + 1, wildcard));
}

/**
 * forward_wildcard - Moves the second string past '*' characters.
 *
 * @s2: The second string to move.
 *
 * Return: Pointer to the next non-'*' character in s2.
 */
char *forward_wildcard(char *s2)
{
    if (*s2 == '*')
        return (forward_wildcard(s2 + 1));
    return (s2);
}

/**
 * forward_to_char - Moves the first string to the next matching character.
 * If no match is found, it moves to the null byte.
 *
 * @s1: The first string to move.
 * @c: The character to match.
 *
 * Return: Pointer to the first occurrence of c in s1, or '\0' if not found.
 */
char *forward_to_char(char *s1, char c)
{
    if (*s1 != c && *s1 != '\0')
        return (forward_to_char(s1 + 1, c));
    return (s1);
}

/**
 * backward_wildcard - Counts characters since the last seen wildcard '*'.
 *
 * @s2: The second string to move backwards.
 * @back_count: Counter for characters moving backwards to reach '*'.
 *
 * Return: The count of characters since last '*'.
 */
size_t backward_wildcard(char *s2, size_t back_count)
{
    if (*s2 != '*')
        return (backward_wildcard(s2 - 1, back_count + 1));
    return (back_count);
}
