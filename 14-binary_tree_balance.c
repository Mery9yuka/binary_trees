#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary_tree
 * @tree: Points to the root-node of the tree, to measure the height
 * Return: The height of the tree or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lef_height, rt_height;

	if (tree == NULL)
		return (0);

	lef_height = binary_tree_height(tree->left);
	rt_height = binary_tree_height(tree->right);

	return (1 + (lef_height > rt_height ? lef_height : rt_height));
}
/**
 * binary_tree_balance - Function that measures the balance factor
 *                       of a binary_tree
 * @tree: The pointer to the root node of the tree
 * Return: The balance factor of the tree or 0 if thetree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lef_height, rt_height;

	if (tree == NULL)
		return (0);

	lef_height = (int)binary_tree_height(tree->left);
	rt_height = (int)binary_tree_height(tree->right);

	return (lef_height - rt_height);
}
