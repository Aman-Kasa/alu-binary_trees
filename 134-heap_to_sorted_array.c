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
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array of ints.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: A pointer to store the size of the array.
 *
 * Return: A pointer to the dynamically allocated sorted array,
 *         or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	heap_t *heap_copy = heap;
	size_t heap_size, i;

	if (size == NULL)
		return (NULL);

	if (heap == NULL)
	{
		*size = 0;
		return (NULL);
	}

	heap_size = count_heap_nodes(heap);
	*size = heap_size;

	array = malloc(sizeof(int) * heap_size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < heap_size; i++)
	{
		/* Successive extractions yield elements in descending order */
		array[i] = heap_extract(&heap_copy);
	}

	return (array);
}
