#include "binary_trees.h"

/**
 * sorted_array_to_avl - function creates an AVL tree from a sorted array
 * @array: it's the sorted array
 * @size: it's the size of the sorted array
 *
 * Return: The AVL tree created from the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * aux_sort - function creates an AVL tree using the elements
 * from a sorted array
 * @parent: it's the parent of the node to create
 * @array: it's the sorted array
 * @begin: it's the starting position of the array
 * @last: it's the ending position of the array
 *
 * Description: This function recursively creates an AVL tree by selecting
 * the middle element of the array as the root and splitting the array into
 * left and right halves
 *
 * Return: The root of the AVL tree
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);

		if (aux == NULL)
			return (NULL);

		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);

		return (root);
	}
	return (NULL);
}
