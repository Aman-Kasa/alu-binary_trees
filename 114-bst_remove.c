#include "binary_trees.h"

/**
 * find_min - Finds the node with the minimum value in a given BST subtree.
 * @node: A pointer to the root of the subtree to search.
 *
 * Return: A pointer to the node containing the minimum value.
 */
bst_t *find_min(bst_t *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * delete_node - Handles the structural cleanup and link adjustments
 *               for a node slated for deletion.
 * @curr: A pointer to the node to delete.
 *
 * Return: A pointer to the child node that replaces the deleted node,
 *         or NULL if the deleted node was a leaf.
 */
bst_t *delete_node(bst_t *curr)
{
	bst_t *succ, *child;

	/* Case 3: Node has two children */
	if (curr->left != NULL && curr->right != NULL)
	{
		succ = find_min(curr->right);
		curr->n = succ->n;
		curr->right = bst_remove(curr->right, succ->n);
		return (curr);
	}

	/* Case 1 & 2: Node has one child or is a leaf */
	child = curr->left ? curr->left : curr->right;
	if (child != NULL)
		child->parent = curr->parent;

	free(curr);
	return (child);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree where a node will be removed.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	/* Navigate the tree to find the node to remove */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node found: update parent's child reference before freeing */
		if (root->parent == NULL)
			return (delete_node(root));

		if (root->parent->left == root)
			root->parent->left = delete_node(root);
		else
			root->parent->right = delete_node(root);
	}
	return (root);
}
