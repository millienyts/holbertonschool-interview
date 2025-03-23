#ifndef HOLBERTON_H
#define HOLBERTON_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
/* function to compare two strings recursively */
int wildcmp(char *s1, char *s2);
/* helper function to compare two strings with flag for wildcards */
int wildcompare(char *s1, char *s2, int wildcard);
/* helper function to move second string past wildcards recursively */
char *forward_wildcard(char *s2);
/* helper function to move first string to next matching char or null byte */
char *forward_to_char(char *s1, char c);
/* helper function to count back to last seen wildcard */
size_t backward_wildcard(char *s2, size_t back_count);

#endif
