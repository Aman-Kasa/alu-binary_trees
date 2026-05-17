#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure or duplication.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	curr = *tree;
	while (curr != NULL)
	{
		if (value == curr->n)
			return (NULL);
		if (value < curr->n)
		{
			if (curr->left == NULL)
			{
				new_node = binary_tree_node(curr, value);
				curr->left = new_node;
				return (new_node);
			}
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
			{
				new_node = binary_tree_node(curr, value);
				curr->right = new_node;
				return (new_node);
			}
			curr = curr->right;
		}
	}
	return (NULL);
}
