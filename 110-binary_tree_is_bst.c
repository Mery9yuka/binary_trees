#include "binary_trees.h"

/**
 * binary_tree_is_bst - function checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: it's pointing to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_lft(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_rgt(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}

/**
 * check_sub_tree_lft - function checks if all nodes are smaller than
 * the root specified
 * @node: the node in the tree to verify condition
 * @max: the value to compare
 * Return: 1 if all nodes are smaller or equal or 0 otherwise
 */
int check_sub_tree_lft(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_lft(node->left, max);
		right = check_sub_tree_lft(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * check_sub_tree_rgt - function checks if all the nodes are bigger than the
 * root specified
 * @node: the node in the tree to verify condition
 * @min: the value to compare
 * Return: 1 if all is bigger or equal or 0 otherwise
 */
int check_sub_tree_rgt(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_rgt(node->left, min);
		right = check_sub_tree_rgt(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
