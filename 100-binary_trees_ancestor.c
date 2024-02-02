#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * of two nodes
 * @first: it's pointing to the first node
 * @second: it's pointing to the second node
 *
 * Return: The pointer to the lowest common ancestor node, or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *pr, *ch;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	pr = first->parent;
	ch = second->parent;
	if (pr == NULL || first == ch || (!pr->parent && ch))
	{
		return (binary_trees_ancestor(first, ch));
	}
	else if (ch == NULL || pr == second || (!ch->parent && pr))
	{
		return (binary_trees_ancestor(pr, second));
	}
	return (binary_trees_ancestor(pr, ch));
}
