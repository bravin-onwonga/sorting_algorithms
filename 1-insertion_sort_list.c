#include "sort.h"

void swap_nodes(listint_t *curr, listint_t *prev);

/**
 * insertion_sort_list - sort a list with the insertion sort algorithm
 *
 * @list: doubly-linked list head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *hold, *temp;
	int n;

	curr = *list;
	while (curr)
	{
		n = curr->n;
		hold = curr->next;
		if (curr->prev)
		{
			if (n < curr->prev->n)
			{
				while (curr->n < curr->prev->n)
				{
					temp = curr;
					swap_nodes(curr, curr->prev);
					if (curr->prev == NULL)
					{
						*list = curr;
						print_list(*list);
						break;
					}
					print_list(*list);
					curr = temp;
				}
			}
		}
		curr = hold;
	}
}

/**
 * swap_nodes - swaps two nodes
 *
 * @curr: current node
 * @prev: node before curr to swap with
 */

void swap_nodes(listint_t *curr, listint_t *prev)
{
	prev->next = curr->next;
	if (curr->next)
		curr->next->prev = prev;
	curr->prev = prev->prev;
	if (curr->prev != NULL)
		curr->prev->next = curr;
	prev->prev = curr;
	curr->next = prev;
}
