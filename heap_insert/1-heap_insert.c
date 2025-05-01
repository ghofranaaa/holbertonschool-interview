#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	heap_t *insert_parent = get_insert_parent(*root);
	heap_t *new_node = binary_tree_node(insert_parent, value);

	if (!new_node)
		return (NULL);

	if (!insert_parent->left)
		insert_parent->left = new_node;
	else
		insert_parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}
