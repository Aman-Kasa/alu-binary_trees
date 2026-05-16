#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the LCA node, or NULL if no common ancestor found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	const binary_tree_t *temp_f, *temp_s;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	/* Trace lineage loops matching pointers manually */
	for (temp_f = first; temp_f != NULL; temp_f = temp_f->parent)
	{
		for (temp_s = second; temp_s != NULL; temp_s = temp_s->parent)
		{
			if (temp_f == temp_s)
				return ((binary_tree_t *)temp_f);
		}
	}

	return (NULL);
}
