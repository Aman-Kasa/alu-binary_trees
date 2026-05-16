#include "binary_trees.h"

/**
 * tree_depth_helper - Measures depth of the leftmost node path.
 * @tree: Tree checkpoint.
 *
 * Return: Leftmost baseline depth.
 */
int tree_depth_helper(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * check_perfection - Checks depth parity and structural soundness.
 * @tree: Node target.
 * @d: Baseline depth value.
 * @level: Current node processing level depth metric.
 *
 * Return: 1 if structure maps cleanly, 0 if parity breaks.
 */
int check_perfection(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfection(tree->left, d, level + 1) &&
			check_perfection(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = tree_depth_helper(tree);
	return (check_perfection(tree, d, 0));
}
