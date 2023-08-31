#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 * Return: height of the tree, 0 if null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t H_left, H_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	H_left = binary_tree_height(tree->left);
	H_right = binary_tree_height(tree->right);

	if (H_right >= H_left)
		return (H_right + 1);
	return (H_left + 1);
}
