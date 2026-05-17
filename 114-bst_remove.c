#include "binary_trees.h"

/**
 * find_min - Locates the leftmost node of a subtree.
 * @node: Tree starting point.
 *
 * Return: The minimum node element.
 */
bst_t *find_min(bst_t *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * delete_node - Internal structure routing for target deletion.
 * @curr: Selected deletion node.
 *
 * Return: The adjusted replacement pointer context.
 */
bst_t *delete_node(bst_t *curr)
{
	bst_t *succ, *child;

	if (curr->left != NULL && curr->right != NULL)
	{
		succ = find_min(curr->right);
		curr->n = succ->n;
		curr->right = bst_remove(curr->right, succ->n);
		return (curr);
	}

	child = curr->left ? curr->left : curr->right;
	if (child != NULL)
		child->parent = curr->parent;

	free(curr);
	return (child);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->parent == NULL)
			return (delete_node(root));
		if (root->parent->left == root)
			root->parent->left = delete_node(root);
		else
			root->parent->right = delete_node(root);
	}
	return (root);
}
