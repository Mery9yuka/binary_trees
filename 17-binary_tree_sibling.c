#include "binary_trees.h"
/**
 * binary_tree_sibling - Function that finds the sibling of a node
 * @node: The pointer to the node to find the sibling
 * Return: The pointer to the sibling node, NULL if the node is NULL or
 *         if the parent is NULL, or the node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}
