#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_complete - function checks if a binary tree is complete
 * @tree: It's pointing to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
			if (head->node->left == NULL)
				flag = 1;
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
/**
 * free_q - Function frees the nodes in a linked list
 * @head: The head node of the linked list
 */
void free_q(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}
/**
 * _push - function that pushes a node into the stack
 * @node: it's pointing to a binary tree node
 * @head: The head node of the stack
 * @tail: The tail node of the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 * _pop - function that pops a node from the stack
 * @head: The head node of the stack
 */
void _pop(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}
/**
 * new_node - function that creates a new node in a linked list
 * @node: it's pointing to a binary tree node
 * Return: The newly created node
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}
