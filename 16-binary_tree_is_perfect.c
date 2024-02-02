#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary_tree
 * @tree: Points to the root-node of the tree, to measure the height
 * Return: The height of the tree or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}
/**
 * binary_tree_is_perfect - Function that checks if a binary_tree is perfect
 * @tree: The pointer to the root node of the tree to be checked
 * Return: 1 if the tree is perfect or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lef_height, rt_height;

	if (tree == NULL)
		return (0);

	lef_height = binary_tree_height(tree->left);
	rt_height = binary_tree_height(tree->right);

	if (lef_height != rt_height)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
