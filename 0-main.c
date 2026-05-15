#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);

	/* Use the variable to satisfy the -Werror flag */
	if (root != NULL)
		printf("Successfully created node with value: %d\n", root->n);

	return (0);
}
