#include "binary_trees.h"

/**
 * measure_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node.
 *
 * Return: Height of the tree.
 */
size_t measure_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + measure_height(tree->left) : 0;
	right_h = tree->right ? 1 + measure_height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * execute_level - Executes a given function on all nodes at a specific level.
 * @tree: A pointer to the root node.
 * @level: The target level to execute on.
 * @func: A pointer to the function to execute.
 */
void execute_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		execute_level(tree->left, level - 1, func);
		execute_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = measure_height(tree);
	for (i = 0; i <= height; i++)
	{
		execute_level(tree, i, func);
	}
}
