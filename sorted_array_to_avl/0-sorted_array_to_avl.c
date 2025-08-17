#include "binary_trees.h"
#include <stdlib.h>

/**
* new_node - Creates a new AVL node
* @parent: Pointer to parent node
* @value: Value to store in the node
* Return: Pointer to the new node or NULL on failure
*/
avl_t *new_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
* build_avl - Recursively builds AVL tree from a subarray
* @array: Sorted array of integers
* @start: Starting index
* @end: Ending index
* @parent: Pointer to parent node
* Return: Pointer to the root node of the subtree
*/
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;

	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = new_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
* sorted_array_to_avl - Converts a sorted array to an AVL tree
* @array: Pointer to the first element of the array
* @size: Number of elements in the array
* Return: Pointer to the root of the AVL tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1, NULL));
}
