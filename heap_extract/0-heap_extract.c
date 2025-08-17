#include "binary_trees.h"
#include <stdlib.h>

/**
* swap_nodes - Swap values of two heap nodes
* @a: first node
* @b: second node
*/
void swap_nodes(heap_t *a, heap_t *b)
{
	int tmp = a->n;

	a->n = b->n;
	b->n = tmp;
}

/**
* heapify_down - Maintain Max Heap from root downwards
* @root: pointer to root node
*/
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left, *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		swap_nodes(root, largest);
		heapify_down(largest);
	}
}

/**
* get_last_node - Return the last node in level-order
* @root: root of the heap
* Return: pointer to last node
*/
heap_t *get_last_node(heap_t *root)
{
	heap_t **queue = NULL;
	int front = 0, rear = 0, size = 0;

	heap_t *node;

	if (!root)
		return (NULL);

	/* Count total nodes to allocate queue */
	size = 0;
	queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		node = queue[front++];
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}

	node = queue[rear - 1];
	free(queue);
	return (node);
}

/**
* heap_extract - Extract root node from Max Binary Heap
* @root: double pointer to root
* Return: value of root node
*/
int heap_extract(heap_t **root)
{
	heap_t *last;
	int extracted;

	if (!root || !*root)
		return (0);

	extracted = (*root)->n;
	last = get_last_node(*root);

	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (extracted);
	}

	(*root)->n = last->n;

	/* Remove last node from its parent */
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	heapify_down(*root);
	return (extracted);
}
