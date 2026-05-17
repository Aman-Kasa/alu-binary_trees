#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the heap.
 *
 * Return: Number of nodes, or 0 if NULL.
 */
static size_t count_heap_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_heap_nodes(tree->left) + count_heap_nodes(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 *                        of integers in descending order.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A pointer to the dynamically allocated sorted array,
 *         or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	heap_t *heap_copy = heap;
	size_t total_nodes = 0, i;

	if (size == NULL)
		return (NULL);

	if (heap == NULL)
	{
		*size = 0;
		return (NULL);
	}

	total_nodes = count_heap_nodes(heap);
	*size = total_nodes;

	array = malloc(sizeof(int) * total_nodes);
	if (array == NULL)
		return (NULL);

	/* Extract max sequentially; heap_extract modifies heap_copy dynamically */
	for (i = 0; i < total_nodes; i++)
	{
		array[i] = heap_extract(&heap_copy);
	}

	return (array);
}
