#include "binary_trees.h"

/**
 * binary_tree_is_root - Function that checks if a given node is a root
 * @node: A pointer to the node to be checked
 * Return: 1 if the node is a root or 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (node->parent == NULL);
}
