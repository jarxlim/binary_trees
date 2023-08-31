#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates left the binary tree.
 * @tree: root node of the tree
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	piv = tree->right;
	tree->right = piv->left;
	if (piv->left != NULL)
	{
		piv->left->parent = tree;
	}
	piv->left = tree;
	piv->parent = tree->parent;
	tree->parent = piv;
	return (piv);
}
