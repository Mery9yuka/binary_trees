#include "binary_trees.h"

/**
 * array_to_bst - function turns an array to a BST tree
 * @array: it's array to turns to BST tree
 * @size: the size of array
 * Return: The BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		if (i == 0)
		{
			bst_insert(&root, array[i]);
		}
		else
		{
			bst_insert(&root, array[i]);
		}
	}
	return (root);
}
