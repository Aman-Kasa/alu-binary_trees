#include "binary_trees.h"

/**
 * create_avl_from_segment - Recursively builds an AVL tree from an array segment.
 * @array: Pointer to the first element of the original array.
 * @start: The starting index of the current array segment.
 * @end: The ending index of the current array segment.
 * @parent: Pointer to the parent node of the current subtree.
 *
 * Return: A pointer to the root node of the created subtree, or NULL.
 */
static avl_t *create_avl_from_segment(int *array, int start, int end,
				      avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;

	root = binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = create_avl_from_segment(array, start, mid - 1, root);
	root->right = create_avl_from_segment(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_avl_from_segment(array, 0, (int)size - 1, NULL));
}
