#include "sort.h"

/**
 * bubble_sort - sorting algorithm similar to bubble sort
 *
 * @array: array of integers
 * @size: number of elements in array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k = 0, n = size;
	int count, temp;

	for (k = 0; k < size; k++)
	{
		count = 0;
		for (j = 1; j < n; j++)
		{
			i = j - 1;
			if (array[i] > array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				count++;
				print_array(array, size);
			}
		}
		n--;
		if (count == 0)
			break;
	}
}
