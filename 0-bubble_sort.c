#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: integer
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int big_val, flag;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				big_val = array[n];
				array[n] = array[n + 1];
				array[n + 1] = big_val;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			return;
	}
}
