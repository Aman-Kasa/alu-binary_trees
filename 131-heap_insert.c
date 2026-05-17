#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree, or 0 if NULL.
 */
static size_t count_heap_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_heap_nodes(tree->left) + count_heap_nodes(tree->right));
}

/**
 * find_insertion_parent - Uses binary bit routingto locatetheinsertion point.
 * @root: Pointer to the root node of the heap.
 * @target_size: The structural sizeposition of thenew node (total nodes + 1).
 *
 * Return: Pointer to the parent node where the leaf should be attached.
 */
static heap_t *find_insertion_parent(heap_t *root, size_t target_size)
{
	size_t mask;
	heap_t *curr = root;

	/* Find the highest bit power of 2 just below target_size */
	mask = 1;
	while ((mask << 1) <= target_size)
		mask <<= 1;

	/* Shift mask past the highest bit since it represents the root node */
	mask >>= 1;

	/* Follow bits down to the exact parent node level */
	while (mask > 1)
	{
		if (target_size & mask)
			curr = curr->right;
		else
			curr = curr->left;
		mask >>= 1;
	}

	return (curr);
}

/**
 * bubble_up - Rebalances the Max Binary Heap upwards by swapping values.
 * @node: Pointer to the newly inserted node.
 *
 * Return: Pointer to the node where the inserted value ends up resting.
 */
static heap_t *bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent = NULL, *new_node = NULL;
	size_t target_size;

	if (root == NULL)
		return (NULL);

	/* Handle empty heap initialization */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	target_size = count_heap_nodes(*root) + 1;
	parent = find_insertion_parent(*root, target_size);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Attach to left or right child depending on the final bit of the size */
	if (target_size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	/* Rebalance values and return node reference */
	return (bubble_up(new_node));
}
