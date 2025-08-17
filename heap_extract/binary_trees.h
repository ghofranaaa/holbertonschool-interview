#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 *


 */struct binary_tree_s
{
	int n;

	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Max Heap */
typedef struct binary_tree_s heap_t;

/* Function prototype */
int heap_extract(heap_t **root);

/* Add other prototypes if needed, e.g., insert, delete, etc. */

#endif /* BINARY_TREES_H */
