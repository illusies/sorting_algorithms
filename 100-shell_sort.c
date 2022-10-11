#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in 
 * ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: array
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int knuth = 1, in, out, tmp;

	if (array == NULL || size < 2)
		return;
	while (knuth <= ((int)size / 3))
		knuth = (knuth * 3) + 1;

	while (knuth > 0)
	{
		for (out = knuth; out < (int)size; out++)
		{
			tmp = array[out];
			in = out;
			while (in >= knuth && array[in - knuth] > tmp)
			{
				array[in] = array[in - knuth];
				in = in - knuth;
			}
			array[in] = tmp;
		}
		knuth = (knuth - 1) / 3;
		print_array(array, size);
	}
}
