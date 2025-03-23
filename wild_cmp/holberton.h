#ifndef HOLBERTON_H
#define HOLBERTON_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
int wildcmp(char *s1, char *s2);
int wildcompare(char *s1, char *s2, int wildcard);
char *forward_wildcard(char *s2);
char *forward_to_char(char *s1, char c);
size_t backward_wildcard(char *s2, size_t back_count);

#endif /* HOLBERTON_H */
