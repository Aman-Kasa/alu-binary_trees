#include "binary_trees.h"

/**
 * find_min_avl - Locates successor tracking boundaries.
 * @node: Targeted verification starting point pointer.
 *
 * Return: Target minimum structural tracker element.
 */
bst_t *find_min_avl(bst_t *node)
{
	while (node && node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * structural_rebalance - Rebalances a node based on its balance factor.
 * @root: Target tree reference context root point.
 *
 * Return: Adjusted balanced pointer layout output reference.
 */
avl_t *structural_rebalance(avl_t *root)
{
	int balance;

	if (root == NULL)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL, *successor = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (structural_rebalance(temp));
		}
		successor = find_min_avl(root->right);
		root->n = successor->n;
		root->right = avl_remove(root->right, successor->n);
	}

	return (structural_rebalance(root));
}
