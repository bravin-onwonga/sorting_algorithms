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

#include "sort.h"

void sort_everything(int *array, unsigned int start, unsigned int stop, size_t size);
unsigned int partition_array(int *array, unsigned int start, unsigned int stop);

void quick_sort(int *array, size_t size)
{
	unsigned int n = size - 1;

	sort_everything(array, 0, n, size);
}

void sort_everything(int *array, unsigned int start, unsigned int stop, size_t size)
{
	unsigned int idx;

	if (start < stop)
	{
		idx = partition_array(array, start, stop);
		print_array(array, size);

		sort_everything(array, start, idx - 1, size);
		sort_everything(array, idx + 1, stop, size);
	}
}

unsigned int partition_array(int *array, unsigned int start, unsigned int stop)
{
	int pivot = array[stop], temp;
	unsigned int i, j;

	i = start - 1;

	for (j = start; j < stop; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[stop];
	array[stop] = temp;

	return (i + 1);
}
