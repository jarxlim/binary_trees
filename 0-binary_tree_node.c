#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *_newNode;

	_newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (_newNode == NULL)
	{
		return (NULL);
	}

	_newNode->parent = parent;
	_newNode->n = value;
	_newNode->left = NULL;
	_newNode->right = NULL;

	return (_newNode);
}
