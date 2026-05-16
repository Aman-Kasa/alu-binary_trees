#include "binary_trees.h"

/**
 * absolute_height - Measures actual tree height including the leaf node factor.
 * @tree: Target tree tracking point.
 *
 * Return: Pure structural height calculation.
 */
int absolute_height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = absolute_height(tree->left);
	right_h = absolute_height(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: Balance factor value. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = absolute_height(tree->left);
	right_h = absolute_height(tree->right);

	return (left_h - right_h);
}
