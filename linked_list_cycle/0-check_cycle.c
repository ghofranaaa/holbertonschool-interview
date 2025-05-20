#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 * @list: Pointer to the head of the linked list
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	if (list == NULL || list->next == NULL)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;         /* move slow by 1 */
		fast = fast->next->next;   /* move fast by 2 */

		if (slow == fast)          /* they met = cycle */
			return (1);
	}

	return (0);
}
