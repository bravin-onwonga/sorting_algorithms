#include "sort.h"

/**
 * insertion_sort_list - sort a list with the insertion sort algorithm
 *
 * @list: doubly-linked list head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *curr, *hold;
	int n, i, k = 0;

	curr = *list;
	temp = NULL;
	while (curr)
	{
		n = curr->n;
		temp = *list;
		i = 0;
		hold = curr->next;
		while (i < k)
		{
			if (n < temp->n)
			{
				curr->prev->next = curr->next;
				if (curr->next)
					curr->next->prev = curr->prev;
				curr->prev = temp->prev;
				if (curr->prev == NULL)
					*list = curr;
				else
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
		curr = hold;
	}
	print_list(*list);
}
