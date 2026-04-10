#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Address of head pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *left;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			left = current->prev;
			left->next = current->next;
			if (current->next)
				current->next->prev = left;
			current->prev = left->prev;
			current->next = left;
			left->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
