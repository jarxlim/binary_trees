#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a bal tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t H_left, H_right;

	if (tree == NULL)
		return (0);

	H_left = binary_tree_height(tree->left);
	H_right = binary_tree_height(tree->right);

	if (H_left >= H_right)
		return (H_left + 1);
	return (H_right + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the tree to analyze
 * Return: the balance factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int H_left, H_right;

	if (tree == NULL)
		return (0);

	H_left = binary_tree_height(tree->left);
	H_right = binary_tree_height(tree->right);
	return (H_left - H_right);
}
