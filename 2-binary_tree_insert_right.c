#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Function that inserts a node as
 *                         the right child of other node
 * @parent: a pointer to the node to insert the right child in
 * @value: The value to be stored in the new node
 * Return: The pointer to the created node
 *         or NULL if failed, or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}

	parent->right = new;

	return (new);
}
