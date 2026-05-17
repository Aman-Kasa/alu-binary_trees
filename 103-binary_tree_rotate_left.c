#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	parent = tree->parent;

	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->left = tree;
	tree->parent = new_root;
	new_root->parent = parent;

	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = new_root;
		else
			parent->right = new_root;
	}

	return (new_root);
}
