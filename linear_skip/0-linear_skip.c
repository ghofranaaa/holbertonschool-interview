#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 *         or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *prev = list, *curr = list;

    if (!list)
        return (NULL);

    /* traverse using express lane */
    while (curr->express && curr->express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               curr->express->index, curr->express->n);
        prev = curr->express;
        curr = curr->express;
    }

    if (curr->express)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               curr->express->index, curr->express->n);
        printf("Value found between indexes [%lu] and [%lu]\n",
               prev->index, curr->express->index);
        curr = prev;
        while (curr && curr->index <= curr->express->index)
        {
            printf("Value checked at index [%lu] = [%d]\n",
                   curr->index, curr->n);
            if (curr->n == value)
                return (curr);
            curr = curr->next;
        }
        return (NULL);
    }

    /* express lane ended, search remaining nodes */
    while (curr->next)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        if (curr->n == value)
            return (curr);
        curr = curr->next;
    }

    if (curr->n == value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        return (curr);
    }

    return (NULL);
}
