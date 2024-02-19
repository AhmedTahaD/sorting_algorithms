#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int temp_int;
	size_t i;
	size_t j;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp_int = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp_int;
				print_array(array, size);
			}
		}
	}
}
