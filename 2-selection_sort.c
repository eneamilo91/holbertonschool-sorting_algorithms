#include"sort.h"
#include<stddef.h>

/**
 * selection_sort - sorts an array of integers using selection sort
 * @array: - points to the respective array
 * @size: - holds the value of the size
 */

void selection_sort(int *array, size_t size)
{
	int min_val;
	int i;
	int j;
	int min_val_index;
	int tmp;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_val = array[i];
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				min_val_index = j;
			}
		}
		if (min_val < array[i])
		{
			tmp = array[i];
			array[i] = min_val;
			array[min_val_index] = tmp;
			print_array(array, size);
		}
	}
}
