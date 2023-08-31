#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates right the binary tree.
 * @tree: root node of the tree
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *piv;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	piv = tree->left;
	tree->left = piv->right;
	if (piv->right != NULL)
	{
		piv->right->parent = tree;
	}
	piv->right = tree;
	piv->parent = tree->parent;
	tree->parent = piv;
	return (piv);
}
