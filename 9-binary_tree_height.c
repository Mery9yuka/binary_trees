#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary_tree
 * @tree: Points to the root-node of the tree, to measure the height
 * Return: The height of the tree or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lef_height = 0, rt_height = 0;

	if (tree == NULL)
		return (0);

	lef_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rt_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((lef_height > rt_height) ? lef_height : rt_height);
}
