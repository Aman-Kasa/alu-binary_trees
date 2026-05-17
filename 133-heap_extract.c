#include "binary_trees.h"

/**
 * tree_size - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node.
 *
 * Return: Size of the tree, or 0 if NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Locates the last level-order node in a complete binary tree.
 * @root: Pointer to the root node.
 * @size: Total number of nodes in the tree.
 *
 * Return: Pointer to the last level-order node.
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t mask;
	heap_t *curr = root;

	if (size <= 1)
		return (root);

	/* Find highest bit power of 2 below size */
	mask = 1;
	while ((mask << 1) <= size)
		mask <<= 1;

	/* Use binary representation bits of size to route left or right */
	mask >>= 1;
	while (mask > 0)
	{
		if (size & mask)
			curr = curr->right;
		else
			curr = curr->left;
		mask >>= 1;
	}

	return (curr);
}

/**
 * heapify_down - Rebalances a max binary heap downwards from the root.
 * @root: Pointer to the root node of the subtree to heapify.
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	int temp;

	if (root == NULL)
		return;

	if (root->left && root->left->n > largest->n)
		largest = root->left;

	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *heap_r, *last_node;
	int value;
	size_t size;

	if (root == NULL || *root == NULL)
		return (0);

	heap_r = *root;
	value = heap_r->n;
	size = tree_size(heap_r);

	if (size == 1)
	{
		free(heap_r);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(heap_r, size);

	/* Copy value of the last node to the root */
	heap_r->n = last_node->n;

	/* Sever the last node from its parent */
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	/* Sift down the new root value to restore heap property */
	heapify_down(heap_r);

	return (value);
}
