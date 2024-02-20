#include "sort.h"

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, j, k;
	int n;

	while (gap < (size) / 3)
	{
		gap = 3 * gap + 1;
	}

	while (gap > 0)
	{
		for (k = gap; k < size; k++)
		{
			n = array[k];
			j = k;

			while (j < gap - 1 && array[j - gap] >= n)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = n;
		}
		print_array(array, size);
		gap = ((gap - 1) / 3);
	}
}
