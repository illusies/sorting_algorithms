#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in 
 * ascending order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	swap(array, 0, (int)size - 1, size);
}

/**
 * swap - Function to swap elements
 * @arr: array
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: void
 */
void swap(int *arr, int low, int high, size_t size)
{
	int p;

	if (low >= high)
		return;

	p = partition(arr, low, high, size);

	if (p - low > 1)
		swap(arr, low, p - 1, size);
	if (high - p > 1)
		swap(arr, p + 1, high, size);
}

/**
 * partition - Function to find the element's position
 * @arr: array
 * @low: first index of the partition
 * @high: last index of the partition
 * @size: size of the array
 * Return: new index position
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], i = low - 1, j, tmp;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			++i;
			if (j != i)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
		}
	}
	if (i < high - 1)
	{
		if (arr[i + 1] != arr[high])
		{
			tmp = arr[high];
			arr[high] = arr[i + 1];
			arr[i + 1] = tmp;
			print_array(arr, size);
		}
		return (i + 1);
	}
	return (high);
}
