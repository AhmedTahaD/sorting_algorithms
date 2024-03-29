#include "sort.h"
/**
 * swap - Function swap two integers
 * @array: array to be sorted
 * @size: array size
 * @a: address of first integer
 * @b: address of second integer
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array((const int *)array, size);
	}
}
/**
 * partition - function that partitions the array
 * @array: array to be sorted
 * @size: array size
 *@low: the low index of the sort range
 *@high: the high index of the sorting range
 *
 * Return: size_t
 */
size_t partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j;
	int pivot = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i]);
			i++;
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}
/**
 * quicksorting - function sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *@low: the low index of the sort range
 *@high: the high index of the sorting range
 */
void quicksorting(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot = partition(array, size, low, high);

		quicksorting(array, size, low, pivot - 1);
		quicksorting(array, size, pivot + 1, high);
	}
}
/**
 * quick_sort - calls quicksorting
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksorting(array, size, 0, size - 1);
}
