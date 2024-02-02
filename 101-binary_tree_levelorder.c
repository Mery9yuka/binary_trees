#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Function that traverse a binary tree
 * using level-order traversal
 * @tree: It's pointing to the root node of the tree to traverse
 * @func: It's pointing to a function to call for each node
 *
 * Returns: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	const binary_tree_t **nodes = malloc(sizeof(binary_tree_t *) * 1024);
	size_t frt = 0, rr = 0;

	if (!nodes)
		return;

	nodes[rr++] = tree;

	while (frt < rr)
	{
		const binary_tree_t *crt = nodes[frt++];

		func(crt->n);

		if (crt->left)
			nodes[rr++] = crt->left;

		if (crt->right)
			nodes[rr++] = crt->right;
	}

	free(nodes);
}

