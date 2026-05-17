#include "binary_trees.h"

/**
 * count_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree to count.
 *
 * Return: Total number of nodes, or 0 if tree is NULL.
 */
static size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_heap_valid - Validates the complete tree structure and max heap rules.
 * @tree: Pointer to the current node being evaluated.
 * @index: Index position assigned to the current node.
 * @node_count: Total node count calculated from the tree root.
 *
 * Return: 1 if the subtree satisfies all max heap properties, 0 otherwise.
 */
static int is_heap_valid(const binary_tree_t *tree, size_t index,
			 size_t node_count)
{
	if (tree == NULL)
		return (1);

/* If a node's index matches or exceeds totalcount,a structural gapexists */
	if (index >= node_count)
		return (0);

	/* Validate left child value bounds (Parent >= Left Child) */
	if (tree->left && tree->left->n > tree->n)
		return (0);

	/* Validate right child value bounds (Parent >= Right Child) */
	if (tree->right && tree->right->n > tree->n)
		return (0);

	/* Recursively evaluate left (2i + 1) and right (2i + 2) subtrees */
	return (is_heap_valid(tree->left, (2 * index) + 1, node_count) &&
		is_heap_valid(tree->right, (2 * index) + 2, node_count));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 *         Returns 0 if tree is NULL.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t node_count;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);

	return (is_heap_valid(tree, 0, node_count));
}
