#include "sort.h"

/**
 * merge_sort - function that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: integer
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size + 1);
	if (!b)
		return;

	topdownmergesort(array, b, size);
	free(b);
}

/**
 * topdownmergesort - function that prepares the list to be sorted
 * @a: array a
 * @b: array b
 * @n: size of array
 * Return: void
 */
void topdownmergesort(int *array_a, int *array_b, int size)
{
	topdownsplitmerge(a, b, n, 0, n);
	copyarray(a, b, n, 0);
}

/**
 * topdownsplitmerge - function that sorts the list from array b to array a
 * @array: array a
 * @array_c: arrayb
 * @size: start index
 * @l: end index
 * @r: array a
 * Return: void
 */
void topdownsplitmerge(int *array_a, int *array_b, size_t size, size_t left, size_t right)
{
	size_t i, mid;

	if ((right - left) <= 1)
		return;
	mid = (left + right) / 2;
	topdownsplitmerge(array_a, array_b, size, left, mid);
	topdownsplitmerge(array_a, array_b, size, mid, right);
	for (i = left; i <= right + (right == size ? -1 : 0); i++)
		array_b[i] = array_a[i];
	topdownmerge(array_a, array_b, left, mid, right);
}

/**
 * topdownmerge - function that merges the array that has been split
 * using the top-down approach.
 * @array: The array to merge.
 * @array_c: The temporary array.
 * @l: The left index of the split-array.
 * @m: The mid-point of the split-array.
 * @r: The right index of the split-array.
 */
void topdownmerge(int *array_a, int *array_b, size_t size, size_t left, size_t mid, size_t right)
{
	size_t a = left, b = mid, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_a + left, mid - left);
	printf("[right]: ");
	print_array(array_a + (mid), right - mid);
	for (c = left; c < right; c++)
	{
		if ((a < mid) && ((b >= right) || (array_b[a] <= array_b[b])))
		{
			array_a[c] = array_b[a++];
		}
		else
		{
			array_a[c] = array_b[b++];
		}
	}
	printf("[Done]: ");
	print_array(array_a + left, right - left);
}

/**
 * copyarray - function that copies array a to array b
 * @a: array a
 * @ibegin: start index
 * @iend: end index
 * @b: array b
 * Return: void
 */
void copyarray(int *array_a, int ibegin, int iend, int *array_b)
{
	int k;

	for (k = ibegin; k < iend; k++)
		array_b[k] = array_a[k];
}
