#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - Function that creates a binary_tree node
 * @parent: pointer to the parent node
 * @value: Value to be put in the new node (new)
 * Return: The pointer to the new node or NULL if failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
