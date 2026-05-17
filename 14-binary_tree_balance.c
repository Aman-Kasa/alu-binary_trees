#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree
 *                        for a balance factor calculation.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree, or 0 if NULL.
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return ((l > r) ? l : r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The balance factor, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = (int)binary_tree_height_b(tree->left);
	right_h = (int)binary_tree_height_b(tree->right);

	return (left_h - right_h);
}
