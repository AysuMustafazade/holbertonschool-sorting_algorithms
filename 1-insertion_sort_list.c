#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			/* detach current */
			if (current->next)
				current->next->prev = insert;
			insert->next = current->next;

			/* move current before insert */
			current->prev = insert->prev;
			current->next = insert;

			if (insert->prev)
				insert->prev->next = current;
			else
				*list = current;

			insert->prev = current;

			print_list(*list);
			insert = current->prev;
		}
		current = tmp;
	}
}
