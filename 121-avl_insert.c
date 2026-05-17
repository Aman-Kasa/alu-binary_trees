#include "binary_trees.h"

/**
 * node_height - Measures the height of a binary tree node.
 * @tree: Pointer to the node to measure.
 *
 * Return: Height of the node, 0 if NULL.
 */
size_t node_height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree == NULL)
		return (0);

	lh = tree->left ? 1 + node_height(tree->left) : 0;
	rh = tree->right ? 1 + node_height(tree->right) : 0;
	return (lh > rh ? lh : rh);
}

/**
 * avl_insert_recursive - Recursively inserts a value and rebalances the tree.
 * @tree: Double pointer to the current root of the subtree.
 * @parent: Pointer to the parent node.
 * @new_node: Double pointer to store the newly created node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new root of the subtree after rebalancing.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new_node, int value)
{
	int balance;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}
	if (value < (*tree)->n)
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree,
						     new_node, value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert_recursive(&((*tree)->right), *tree,
						      new_node, value);
	else
		return (*tree);

	balance = (int)node_height((*tree)->left) - (int)node_height((*tree)->right);
	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree for insertion.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	*tree = avl_insert_recursive(tree, NULL, &new_node, value);
	return (new_node);
}
