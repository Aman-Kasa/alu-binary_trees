#include "binary_trees.h"

/**
 * node_height - Structural height evaluator logic.
 * @tree: Targeted node.
 *
 * Return: Absolute height score metrics.
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
 * node_balance - Evaluates node balance factor metrics.
 * @tree: Node target check.
 *
 * Return: Balance integer calculation.
 */
int node_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);
	lh = tree->left ? (int)node_height(tree->left) + 1 : 0;
	rh = tree->right ? (int)node_height(tree->right) + 1 : 0;
	return (lh - rh);
}

/**
 * recurse_avl_insert - Tail-recursive tracking tool matching insertions.
 * @tree: Root node double pointer reference tracking tool.
 * @parent: Tracking pointer parent data link assignments.
 * @new_n: New node memory allocation tracker storage.
 * @val: Structural payload content score.
 *
 * Return: Pointer to sub-tree configurations.
 */
avl_t *recurse_avl_insert(avl_t **tree, avl_t *parent, avl_t **new_n, int val)
{
	int b_factor;

	if (*tree == NULL)
	{
		*new_n = binary_tree_node(parent, val);
		return (*new_n);
	}
	if (val < (*tree)->n)
		(*tree)->left = recurse_avl_insert(&((*tree)->left), *tree, new_n, val);
	else if (val > (*tree)->n)
		(*tree)->right = recurse_avl_insert(&((*tree)->right), *tree, new_n, val);
	else
		return (*tree);

	b_factor = node_balance(*tree);
	if (b_factor > 1 && val < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (b_factor < -1 && val > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (b_factor > 1 && val > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (b_factor < -1 && val < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree.
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
	recurse_avl_insert(tree, NULL, &new_node, value);
	return (new_node);
}
