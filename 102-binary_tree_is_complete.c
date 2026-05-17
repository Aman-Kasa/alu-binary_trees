#include "binary_trees.h"

/**
 * count_nodes - Counts total nodes in a tree structure.
 * @tree: A pointer to the root node.
 *
 * Return: Total node count.
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * validate_complete - Helper to validate completeness index layout.
 * @tree: A pointer to the root node.
 * @index: Current node mapping index.
 * @total: Total node count in the tree.
 *
 * Return: 1 if complete, 0 otherwise.
 */
int validate_complete(const binary_tree_t *tree, size_t index, size_t total)
{
	if (tree == NULL)
		return (1);

	if (index >= total)
		return (0);

	return (validate_complete(tree->left, 2 * index + 1, total) &&
			validate_complete(tree->right, 2 * index + 2, total));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if complete, 0 if tree is NULL or incomplete.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t total;

	if (tree == NULL)
		return (0);

	total = count_nodes(tree);
	return (validate_complete(tree, 0, total));
}
