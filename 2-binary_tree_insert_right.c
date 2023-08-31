#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: a pointer to the node to insert the right child in
 * @value: the value contained in the new_child node
 * Return: pointer to the new_child node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (!parent)
		return (NULL);

	new_child = malloc(sizeof(binary_tree_t));
	if (!new_child)
		return (NULL);

	new_child->n = value;
	new_child->parent = parent;
	new_child->left = NULL;
	new_child->right = parent->right;
	parent->right = new_child;
	if (new_child->right)
	new_child->right->parent = new_child;
	return (new_child);
}
