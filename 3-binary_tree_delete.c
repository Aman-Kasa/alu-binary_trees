#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Delete left subtree recursively */
	binary_tree_delete(tree->left);
	/* Delete right subtree recursively */
	binary_tree_delete(tree->right);

	/* Clear the current node allocation */
	free(tree);
}
