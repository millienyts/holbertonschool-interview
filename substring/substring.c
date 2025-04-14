#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Finds all starting indices of substrings in s that are
 * a concatenation of each word in words exactly once and without intervening characters.
 * @s: The string to search in.
 * @words: Array of words to concatenate.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of results.
 *
 * Return: Array of starting indices, or NULL if no matches.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k, index = 0;
	int *result = NULL;
	int word_len, total_len, s_len;
	char *substr;
	int *used;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);

	result = malloc(sizeof(int) * (s_len));
	if (!result)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		used = calloc(nb_words, sizeof(int));
		if (!used)
		{
			free(result);
			return (NULL);
		}

		for (j = 0; j < nb_words; j++)
		{
			int found = 0;
			int start = i + j * word_len;

			for (k = 0; k < nb_words; k++)
			{
				if (!used[k] && strncmp(s + start, words[k], word_len) == 0)
				{
					used[k] = 1;
					found = 1;
					break;
				}
			}
			if (!found)
				break;
		}

		free(used);

		if (j == nb_words)
		{
			result[index++] = i;
		}
	}

	if (index == 0)
	{
		free(result);
		*n = 0;
		return (NULL);
	}

	*n = index;
	return (result);
}
