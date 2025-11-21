#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
* build_word_map - builds list of unique words and their expected counts
* @words: array of words
* @nb_words: number of words
* @unique: pointer to store unique words array
* @expected: pointer to store expected frequency array
*
* Return: number of unique words, or -1 on failure
*/
static int build_word_map(char const **words, int nb_words,
char ***unique, int **expected)
{
int i, j, unique_count = 0;

*unique = malloc(sizeof(char *) * nb_words);
*expected = calloc(nb_words, sizeof(int));
if (!*unique || !*expected)
return (-1);
for (i = 0; i < nb_words; i++)
{
int found = -1;
for (j = 0; j < unique_count; j++)
{
if (strcmp(words[i], (*unique)[j]) == 0)
{
found = j;
break;
}
}
if (found == -1)
{
(*unique)[unique_count] = (char *)words[i];
(*expected)[unique_count] = 1;
unique_count++;
}
else
{
(*expected)[found]++;
}
}
return (unique_count);
}
/**
* is_valid_substring - checks if substring at index is valid concatenation
* @s: the string
* @start: starting index
* @word_len: length of each word
* @nb_words: number of words
* @unique: array of unique words
* @expected: expected word counts
* @unique_count: number of unique words
* @seen: helper array to track counts
*
* Return: 1 if valid, 0 otherwise
*/
static int is_valid_substring(char const *s, int start, int word_len,
int nb_words, char **unique,
int *expected, int unique_count, int *seen)
{
int i, j;
for (i = 0; i < unique_count; i++)
seen[i] = 0;
for (i = 0; i < nb_words; i++)
{
const char *sub = s + start + i * word_len;
int matched = 0;
for (j = 0; j < unique_count; j++)
{
if (strncmp(sub, unique[j], word_len) == 0)
{
seen[j]++;
if (seen[j] > expected[j])
return (0);
matched = 1;
break;
}
}
if (!matched)
return (0);
}
return (1);
}
/**
* find_substring - finds all starting indices where \
concatenation of words appear
* @s: the string to scan
* @words: array of words
* @nb_words: number of words
* @n: pointer to number of results
*
* Return: allocated array of indices, or NULL if none
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int word_len, total_len, s_len, i, unique_count, *indices, *expected, *seen;
char **unique;
*n = 0;
word_len = strlen(words[0]);
s_len = strlen(s);
total_len = word_len *nb_words;
if (s_len < total_len || word_len == 0)
return (NULL);
indices = malloc(sizeof(int) * s_len);
if (!indices)
return (NULL);
unique_count = build_word_map(words, nb_words, &unique, &expected);
if (unique_count == -1)
{
free(indices);
return (NULL);
}
seen = calloc(unique_count, sizeof(int));
if (!seen)
{
free(indices);
free(unique);
free(expected);
return (NULL);
}
for (i = 0; i <= s_len - total_len; i++)
{
if (is_valid_substring(s, i, word_len, nb_words,
unique, expected, unique_count, seen))
indices[(*n)++] = i;
}
free(unique);
free(expected);
free(seen);
if (*n == 0)
{
free(indices);
return (NULL);
}
return (indices);
}
