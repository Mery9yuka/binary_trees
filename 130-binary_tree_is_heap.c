#include "binary_trees.h"

/**
 * binary_tree_is_heap - function checks if a binary tree
 * is a valid Max Binary Heap
 * @tree: The binary tree to be checked
 *
 * Return: 1 if it is a Max Binary Heap, or 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bval;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);
	bval = binary_tree_balance(tree);
	if (bval == 0)
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	if (bval == 1)
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	else
		return (0);
}

/**
 * binary_tree_height - function measures the height of a binary tree
 * @tree: it's the binary tree to measure
 *
 * Return: The height of that binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - function measures the balance factor of a binary tree
 * @tree: The binary tree to be measured
 *
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * tree_is_perfect - function checks if a binary tree is perfect
 * @tree: The binary tree to be checked
 *
 * Return: The level of height if perfect, or otherwise 0
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - function checks if a binary tree is perfect
 * @tree: The binary tree to be checked
 *
 * Return: 1 if it is perfect, or 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
			return (1);
		return (0);
	}
}
