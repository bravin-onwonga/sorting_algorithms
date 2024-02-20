#include "sort.h"

void quick_sort(int *array, size_t size);
void sort_everything(int *array, int start, int stop, size_t size);
int partition_array(int *array, int start, int stop);

/**
 * quick_sort - function similar to quick sort
 *
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	sort_everything(array, 0, size - 1, size);
}

/**
 * sort_everything - sorts the array
 *
 * @array: array to sort
 * @start: where to begin the sorting
 * @stop: where to end the sorting
 * @size: size of the array
 */

void sort_everything(int *array, int start, int stop, size_t size)
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

/**
 * partition_array - sorts the array
 *
 * @array: array to sort
 * @start: where to begin the sorting
 * @stop: where to end the sorting
 * Return: index of pivot
 */

int partition_array(int *array, int start, int stop)
{
	int pivot = array[stop], temp;
	int i = start - 1, j;

	for (j = start; j < stop; j++)
	{
		if (array[j] < pivot)
		{
			i++;
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
