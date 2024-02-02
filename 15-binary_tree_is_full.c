#include "binary_trees.h"
/**
 * binary_tree_is_full - Function that  checks if a binary_tree is full
 * @tree: The pointer to the root-node of the tree to be checked
 * Return: 1 if the tree is full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right == NULL) ||
			(tree->left != NULL && tree->right != NULL))
	{
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	}

	return (0);
}
