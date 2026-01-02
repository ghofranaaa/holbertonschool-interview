#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * is_bst - Checks if a binary tree is a BST
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Checks if a binary tree is balanced
 * @tree: Pointer to the root node
 *
 * Return: 1 if balanced, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);

	balance = height(tree->left) - height(tree->right);

	if (balance > 1 || balance < -1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl(tree));
}
