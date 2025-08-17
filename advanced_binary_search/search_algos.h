#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int advanced_binary(int *array, size_t size, int value);
void print_array(int *array, size_t size);
int advanced_binary_recursive(
	int *array, size_t left, size_t right, int value);

#endif
