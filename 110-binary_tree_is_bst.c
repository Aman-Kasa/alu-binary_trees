#include "binary_trees.h"
#include <limits.h>

/**
 * validate_bst - Helper mapping min/max value bounds across all nodes.
 * @tree: Target node trace.
 * @min: Minimum boundary allowance.
 * @max: Maximum boundary allowance.
 *
 * Return: 1 if valid BST sequence, 0 if out of bounds.
 */
int validate_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (validate_bst(tree->left, min, tree->n) &&
			validate_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if valid, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (validate_bst(tree, INT_MIN, INT_MAX));
}
