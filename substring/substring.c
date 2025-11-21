#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

/* Helper to compare two arrays of word counts */
int compare_counts(int *a, int *b, int size)
{
    for (int i = 0; i < size; i++)
        if (a[i] != b[i])
            return 0;
    return (1);
}

/* Main function */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    if (!s || !words || nb_words == 0)
    {
        *n = 0;
        return (NULL);
    }

    int word_len = strlen(words[0]);
    int sub_len = word_len * nb_words;
    int s_len = strlen(s);

    int *res = malloc(sizeof(int) * s_len);
    if (!res)
        return (NULL);

    int count = 0;

    for (int i = 0; i <= s_len - sub_len; i++)
    {
        int found = 1;
        int *used = calloc(nb_words, sizeof(int));
        if (!used)
        {
            free(res);
            return (NULL);
        }

        for (int j = 0; j < nb_words; j++)
        {
            int matched = 0;
            char *substr = strndup(s + i + j * word_len, word_len);
            if (!substr)
            {
                free(used);
                free(res);
                return (NULL);
            }

            for (int k = 0; k < nb_words; k++)
            {
                if (!used[k] && strcmp(substr, words[k]) == 0)
                {
                    used[k] = 1;
                    matched = 1;
                    break;
                }
            }
            free(substr);

            if (!matched)
            {
                found = 0;
                break;
            }
        }

        free(used);

        if (found)
            res[count++] = i;
    }

    if (count == 0)
    {
        free(res);
        *n = 0;
        return (NULL);
    }

    *n = count;
    return (res);
}
			