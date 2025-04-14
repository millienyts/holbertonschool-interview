#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - Checks if substring at index matches all words.
 * @s: The string to search in.
 * @start: Starting index in s.
 * @words: Array of words.
 * @nb_words: Number of words.
 * @word_len: Length of each word.
 *
 * Return: 1 if valid substring, 0 otherwise.
 */
int is_valid_substring(char const *s, int start, char const **words,
		       int nb_words, int word_len)
{
	int *used = calloc(nb_words, sizeof(int));
	int i, j, pos, found = 0;

	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		pos = start + i * word_len;
		found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(s + pos, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}

	free(used);
	return (found && i == nb_words);
}

/**
 * find_substring - Finds all starting indices of substrings in s that are
 * a concatenation of each word in words once, with no intervening chars.
 * @s: The string to search in.
 * @words: Array of words.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of results.
 *
 * Return: Array of starting indices, or NULL if no match.
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	int *result, word_len, total_len, s_len, i, index = 0;

	*n = 0;
	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);
	result = malloc(sizeof(int) * s_len);

	if (!result)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (is_valid_substring(s, i, words, nb_words, word_len))
			result[index++] = i;
	}

	if (index == 0)
	{
		free(result);
		return (NULL);
	}

	*n = index;
	return (result);
}
