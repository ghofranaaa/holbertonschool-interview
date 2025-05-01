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

	/* Find the parent node where the new node should be inserted */
	insert_parent = get_insert_parent(*root);
	if (!insert_parent)
		return (NULL);

	/* Create the new node */
	new_node = binary_tree_node(insert_parent, value);
	if (!new_node)
		return (NULL);

	/* Insert the new node as a left or right child */
	if (!insert_parent->left)
		insert_parent->left = new_node;
	else
		insert_parent->right = new_node;

	/* Heapify up to ensure the heap property is maintained */
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

	/* Perform a level-order traversal to find the first available parent node */
	queue[rear++] = root;

	while (front < rear)
	{
		parent = queue[front++];

		if (!parent->left || !parent->right)
			return (parent);

		/* Add children to the queue */
		if (parent->left)
			queue[rear++] = parent->left;
		if (parent->right)
			queue[rear++] = parent->right;
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

	/* Move the node up until the max-heap property is restored */
	while (node && node->parent && node->parent->n < node->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move the node to its parent for the next iteration */
		node = node->parent;
	}
}
