#include "sort.h"

void sort_everything(int *array, unsigned int start, unsigned int stop, size_t size, unsigned int left_limit, unsigned int right_limit);
unsigned int partition_array(int *array, unsigned int start, unsigned int stop);

void quick_sort(int *array, size_t size)
{
	unsigned int n, left_limit = 0, right_limit = size - 1;

	/* left side is 0 - idx */
	n = size - 1;
	sort_everything(array, 0, n, size, left_limit, right_limit);
}

void sort_everything(int *array, unsigned int start, unsigned int stop, size_t size, unsigned int left_limit, unsigned int right_limit)
{
	unsigned int idx;
	printf("Start: %d, Stop: %d, Size: %ld\n", start, stop, size);

	if (right_limit == left_limit)
	{
		return;
	}

	if (start < stop)
	{
		idx = partition_array(array, start, stop);
		if (idx == left_limit)
		{
			left_limit++;
			sort_everything(array, idx + 1, right_limit, size, left_limit, right_limit);
		}
		if (idx == right_limit)
		{
			right_limit--;
			sort_everything(array, left_limit, idx - 1, size, left_limit, right_limit);
		}
		print_array(array, size);
		printf("Idx: %d\n", idx);

		sort_everything(array, left_limit, idx - 1, size, left_limit, right_limit);
		sort_everything(array, idx + 1, right_limit, size, left_limit, right_limit);
	}
}

unsigned int partition_array(int *array, unsigned int start, unsigned int stop)
{
	int temp, pivot = array[stop];
	unsigned int idx = stop, i;

	for (i = start; i <= stop; i++)
	{
		if ((array[i] > pivot) && (i < idx))
		{
			temp = array[i];
			array[i] = pivot;
			array[idx] = temp;
			idx = i;
		}

		if ((array[i] < pivot) && (i > idx))
		{
			temp = array[i];
			array[i] = pivot;
			array[idx] = temp;
			idx = i;
		}
	}
	return (idx);
}
