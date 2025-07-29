#include "sort.h"
#include <unistd.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to first element
 * @b: Pointer to second element
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Maintains max heap property for a subtree
 * @array: Array of integers
 * @size: Total size of array (for print_array)
 * @n: Size of the heap (changing over time)
 * @i: Index of the root of subtree
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		sift_down(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers using Heap Sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	/* Extract elements one by one */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
