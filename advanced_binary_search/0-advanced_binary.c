#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
* print_array - prints an array of integers
* @array: pointer to the first element of the array to print
* @size: number of elements in the array
*
* Return: void
*/
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
* advanced_binary_recursive - recursive helper function for advanced binary
* @array: pointer to the first element of the array to search in
* @left: starting index of the current subarray
* @right: ending index of the current subarray
* @value: value to search for
*
* Return: index where value is located, or -1 if not found
*/
int advanced_binary_recursive(int *array, size_t left, size_t right,

			      int value)
{
		size_t mid;

	if (left > right)
		return (-1);

	/* Print current subarray */
	print_array(array + left, right - left + 1);

	/* Calculate middle index */
	mid = left + (right - left) / 2;

	/* If we found the value */
	if (array[mid] == value)
	{
		/* Check if this is the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		/* Search in the left half to find first occurrence */
		return (advanced_binary_recursive(array, left, mid - 1, value));
	}

	/* If value is smaller, search left half */
	if (array[mid] > value)
		return (advanced_binary_recursive(array, left, mid - 1, value));

	/* If value is larger, search right half */
		return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
* advanced_binary - searches for a value in a sorted array using advanced
*                   binary search
* @array: pointer to the first element of the array to search in
* @size: number of elements in array
* @value: value to search for
*
* Return: index where value is located, or -1 if not found or array is NULL
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
