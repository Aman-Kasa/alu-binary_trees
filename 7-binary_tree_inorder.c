#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traverse left */
	binary_tree_inorder(tree->left, func);
	/* Process parent node context */
	func(tree->n);
	/* Traverse right */
	binary_tree_inorder(tree->right, func);
}
