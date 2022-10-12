#include "sort.h"

/**
 * counting_sort - sorting an array using counting_sort
 * algorithm
 * @array: array
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *output, i, j, k;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * ((int)size + 1));
	if (!output)
		return;
	k = find_maxnum(array, size);
	counter = malloc(sizeof(int) * (k + 1));
	for (i = 0; i < k + 1; i++)
		counter[i] = 0;

	if (!counter)
	{
		free(output);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		j = array[i];
		counter[j] += 1;
	}
	for (i = 1; i <= k + 1; i++)
		counter[i] += counter[i - 1];
	print_array(counter, k + 1);
	for (i = (int)size - 1; i >= 0; i--)
	{
		j = array[i];
		counter[j] -= 1;
		output[counter[j]] = array[i];
	}
	free(counter);
	fill_array(array, output, size);
}


/**
 * get_biggest_num - find the biggest number in an array
 * @array: the array
 * @size: size of the array
 * Return: the biggest number
 */
int find_maxnum(int *array, size_t size)
{
	int i, maxnum = 0;

	for (i = 0; i < (int)size; i++)
		maxnum = maxnum < array[i] ? array[i] : maxnum;

	return (maxnum);
}

/**
 * fill_array - fills array a with values in array b
 * @arra: array a
 * @arrb: array b
 * @size: size both arrays should be same size
 * Return: void
 */
void fill_array(int *array_a, int *array_b, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		array_a[i] = array_b[i];

	free(array_b);
}

