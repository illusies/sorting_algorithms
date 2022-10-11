#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers 
 * in ascending order using the Selection sort algorithm
 * @array: pointer to array
 * @size: size of the array
 * Returns: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, val_check;
	int val_select;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		val_select = array[i];
		val_check = i;
		for (j = i; j < size; j++)
		{
			if (val_select > array[j])
			{
				val_check = j;
				val_select = array[j];
			}
		}
		if (val_select == array[i] && val_check == i)
			continue;
		array[val_check] = array[i];
		array[i] = val_select;
		print_array(array, size);
	}
}
