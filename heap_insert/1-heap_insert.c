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
	heap_t *insert_parent;
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insert_parent = get_insert_parent(*root);
	new_node = binary_tree_node(insert_parent, value);

	if (!new_node)
		return (NULL);

	if (!insert_parent->left)
		insert_parent->left = new_node;
	else
		insert_parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}

/**
* get_insert_parent - Finds the parent node for insertion
* @root: Pointer to the root node of the heap
*
* Return: Pointer to the insert parent node
*/
heap_t *get_insert_parent(heap_t *root)
{
	heap_t *parent;
	heap_t *queue[100];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		parent = queue[front++];

		if (parent->left && parent->right)
			continue;

		return (parent);
	}

	return (NULL);
}

/**
* heapify_up - Restores the max heap property
* by moving up the newly inserted node
* @node: Pointer to the node to be moved up
*/
void heapify_up(heap_t *node)
{
	int temp;

	while (node && node->parent && node->parent->n < node->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}
