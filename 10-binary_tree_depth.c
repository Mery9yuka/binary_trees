#include "binary_trees.h"

/**
 * binary_tree_depth - Function that measures the depth
 *                 of a node in a binary_tree
 * @tree: It points to the node that need to measure the depth
 * Return: The depth of the node or 0 if the tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_node = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth_node++;
		tree = tree->parent;
	}

	return (depth_node);
}
