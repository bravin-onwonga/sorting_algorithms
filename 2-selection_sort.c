#include "sort.h"

/**
 * selection_sort - algorithm similar to selection sort
 *
 * @array: int array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, k, idx;
	int n, temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		n = array[i];
		idx = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < n)
			{
				n = array[k];
				idx = k;
			}
		}
		if (idx != i)
		{
			temp = array[i];
			array[i] = n;
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
