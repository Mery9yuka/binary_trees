#include "binary_trees.h"
/**
 * binary_tree_leaves - Function that counts the leaves in a binary_tree
 * @tree: The pointer to the root node of the tree
 * Return: the nb of leaves in the tree or 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL) /*verify if the tree is NULL return 0*/
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
