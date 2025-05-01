#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_size - Measures the size of a binary tree
* @tree: Pointer to the root node of the tree to measure
*
* Return: The size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
* heapify_up - Restores the Max Heap property by swapping nodes as necessary
* @node: Pointer to the inserted node
*
* Return: Pointer to the node after heapify
*/
heap_t *heapify_up(heap_t *node)
{
int temp;

while (node->parent && node->n > node->parent->n)
{
temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;
node = node->parent;
}
return (node);
}

/**
* find_insert_parent - Finds the parent for the next insertion
* @root: Pointer to the root node of the Heap
* @size: The current size of the Heap
*
* Return: Pointer to the parent node
*/
heap_t *find_insert_parent(heap_t *root, size_t size)
{
size_t path_bit;
size_t max_bit = (size_t)1 << (sizeof(size_t) * 8 - 2); /* Safe max bit */

/* Locate the most significant bit for the path */
for (path_bit = max_bit; !(path_bit & size); path_bit >>= 1)
;

/* Navigate down the tree to find the insertion parent */
for (path_bit >>= 1; path_bit > 1; path_bit >>= 1)
{
if (size & path_bit)
root = root->right;
else
root = root->left;
}

return (root);
}


/**
* heap_insert - Inserts a value into a Max Binary Heap
* @root: Double pointer to the root node of the Heap
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *parent;
size_t size;

if (!root)
return (NULL);

if (!*root)
return (*root = binary_tree_node(NULL, value));

size = binary_tree_size(*root) + 1;
parent = find_insert_parent(*root, size);

new_node = binary_tree_node(parent, value);
if (!new_node)
return (NULL);

if (!parent->left)
parent->left = new_node;
else
parent->right = new_node;

return (heapify_up(new_node));
}
