#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Returns the maximum value in an array
 * @array: The array to search
 * @size: Size of the array
 * Return: The maximum integer found
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Performs counting sort based on the digit represented by exp
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The digit position (1, 10, 100, ...)
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Update count[i] to contain actual positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array (stable sort) */
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	/* Copy the sorted elements back to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using LSD Radix Sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
