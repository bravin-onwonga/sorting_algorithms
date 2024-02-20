#include "sort.h"

void swap_nodes(listint_t *curr, listint_t *prev);

/**
 * insertion_sort_list - sort a list with the insertion sort algorithm
 *
 * @list: doubly-linked list head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *hold;

	if (!(*list) || !(list))
		return;

	curr = (*list)->next;
	while (curr)
	{
		hold = curr;

		while (hold->prev && hold->n < hold->prev->n)
		{
			swap_nodes(hold, hold->prev);
			if (curr->prev == NULL)
			{
				*list = curr;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		curr = curr->next;
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
	if (!curr || !prev)
		return;

	prev->next = curr->next;
	if (curr->next)
		curr->next->prev = prev;
	curr->prev = prev->prev;
	if (curr->prev != NULL)
		curr->prev->next = curr;
	prev->prev = curr;
	curr->next = prev;
}
