#include "binary_trees.h"
/**
 * binary_tree_nodes - Function that counts the nodes
 *              with at least 1 child in the binary_tree
 * @tree: It points to the root-node of the tree
 * Return: The nb of nodes with at least 1 child or 0 if the tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	else
		return (0);
}
