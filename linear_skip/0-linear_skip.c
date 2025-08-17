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

    /* determine the range to search linearly */
    if (curr->express)
        printf("Value checked at index [%lu] = [%d]\n",
               curr->express->index, curr->express->n);

    if (curr->express)
        printf("Value found between indexes [%lu] and [%lu]\n",
               prev->index, curr->express->index);
    else
    {
        /* reach the end of the list */
        skiplist_t *end = curr;
        while (end->next)
            end = end->next;
        printf("Value found between indexes [%lu] and [%lu]\n",
               prev->index, end->index);
    }

    /* linear search between prev and curr->express (or end of list) */
    curr = prev;
    while (curr && curr->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        curr = curr->next;
    }

    if (curr && curr->n == value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        return (curr);
    }

    return (NULL);
}
