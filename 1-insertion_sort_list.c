#include "sort.h"

/**
 * insertion_sort_list - sort a list with the insertion sort algorithm
 *
 * @list: doubly-linked list head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *curr;
	int i, n, k = 0;

	curr = *list;
	temp = NULL;
	while (curr)
	{
		n = curr->n;
		i = 0;
		temp = *list;
		while (i < k)
		{
			if (n < temp->n)
			{
				curr->prev->next = curr->next;
				curr->prev = temp->prev;
				curr->prev->next = curr;
				temp->prev = curr;
				curr->next = temp;
				print_list(*list);
				break;
			}
			i++;
			temp = temp->next;
		}
		k++;
		curr = curr->next;
	}
	print_list(*list);
}
