#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the parent node to insert left-child in
 * @value: the value stored in the new_child node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (!parent)
		return (NULL);

	new_child = malloc(sizeof(binary_tree_t));
	if (!new_child)
		return (NULL);

	new_child->n = value;
	new_child->parent = parent;
	new_child->right = NULL;
	new_child->left = parent->left;
	parent->left = new_child;
	if (new_child->left)
		new_child->left->parent = new_child;
	return (new_child);
}
