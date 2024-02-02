#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary_tree
 * @tree: Points to the root-node of the tree, to measure the height
 * Return: The height of the tree or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt_height, rt_height;

	if (tree == NULL)
		return (0);

	lt_height = binary_tree_height(tree->left);
	rt_height = binary_tree_height(tree->right);

	return (1 + (lt_height > rt_height ? lt_height : rt_height));
}
