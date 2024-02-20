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
size_t partition(int *array, size_t size, size_t low, size_t high)
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
	swap(array, size, &array[i], &array[high]);
	return (i);
}
/**
 * quick_sorting - function sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *@low: the low index of the sort range
 *@high: the high index of the sorting range
*/
void quick_sorting(int *array, size_t size, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pivot = partition(array, size, low, high);
		quick_sorting(array, size, low, pivot - 1);
		quick_sorting(array, size, pivot + 1, high);
	}
}
/**
 * quick_sort - calls quicksort
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sorting(array, size, 0, size - 1);
}
