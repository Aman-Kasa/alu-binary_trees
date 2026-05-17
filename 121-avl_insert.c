#include "binary_trees.h"

/**
 * avl_balance_node-Evaluatesandexecutes necessary rotations to balance anode.
 * @node: Pointer to the node to evaluate.
 * @value: The value that was inserted, used to identify the rotation case.
 *
 * Return: Pointer to the newly balanced node (or old node if no rotation).
 */
avl_t *avl_balance_node(avl_t *node, int value)
{
	int balance = binary_tree_balance(node);

	/* Case 1: Left Left Case */
	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));

	/* Case 2: Right Right Case */
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));

	/* Case 3: Left Right Case */
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	/* Case 4: Right Left Case */
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * avl_insert_recursive - Recursively traverses a tree to insert a value
 *                        and balances the nodes on the way back up.
 * @tree: Double pointer to the current root of the subtree.
 * @parent: Pointer to the parent node of the current subtree.
 * @new_node: Double pointer to store the newly created node reference.
 * @value: The value to insert.
 *
 * Return: Pointer to the new subtree root node, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new_node, int value)
{
	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree,
						     new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&((*tree)->right), *tree,
						      new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree); /* Value already exists */
	}

	/* Run balance routines on every single node during recursive unwind */
	return (avl_balance_node(*tree, value));
}

/**
 * avl_insert - Inserts a value into an AVL Tree.
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
