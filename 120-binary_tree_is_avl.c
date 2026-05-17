#include "binary_trees.h"
#include <limits.h>

/**
 * avl_height - Measures tracking height parameters.
 * @tree: Root node measure target.
 *
 * Return: Height count metric.
 */
int avl_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);
	lh = avl_height(tree->left);
	rh = avl_height(tree->right);
	return (1 + (lh > rh ? lh : rh));
}

/**
 * avl_helper - Recursively checks BST boundaries and balance factors.
 * @tree: Target node.
 * @min: Min bound.
 * @max: Max bound.
 *
 * Return: 1 if valid AVL properties apply, 0 if broken.
 */
int avl_helper(const binary_tree_t *tree, int min, int max)
{
	int lh, rh, diff;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	lh = avl_height(tree->left);
	rh = avl_height(tree->right);
	diff = lh - rh;

	if (diff < -1 || diff > 1)
		return (0);

	return (avl_helper(tree->left, min, tree->n) &&
			avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if valid AVL, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX));
}
