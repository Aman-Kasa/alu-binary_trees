#include "binary_trees.h"

/**
 * find_min - Finds the node with the minimum value in a given tree.
 * @node: Pointer to the root node of the tree.
 *
 * Return: A pointer to the node with the minimum value.
 */
static avl_t *find_min(avl_t *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * balance_avl_subtree - Inspects and balances an AVL subtree on stack pop.
 * @root: Pointer to the current local root node.
 *
 * Return: Pointer to the newly balanced root node.
 */
static avl_t *balance_avl_subtree(avl_t *root)
{
	int balance = binary_tree_balance(root);

	/* Left Heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	/* Right Heavy */
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}

/**
 * delete_node_conns - Safely handles the deletion of a node with 0 or 1 child.
 * @root: Pointer to the node to be removed.
 *
 * Return: Pointer to the child node that replaces the deleted node, or NULL.
 */
static avl_t *delete_node_conns(avl_t *root)
{
	avl_t *temp = NULL;

	if (root->left == NULL)
	{
		temp = root->right;
		if (temp)
			temp->parent = root->parent;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		temp = root->left;
		if (temp)
			temp->parent = root->parent;
		free(root);
		return (temp);
	}

	return (NULL);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removal
 *         and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *successor = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node with two children */
		if (root->left && root->right)
		{
			successor = find_min(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
		else
		{
			/* Node with one child or leaf node */
			return (delete_node_conns(root));
		}
	}

	if (root == NULL)
		return (NULL);

	return (balance_avl_subtree(root));
}
