#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 if the tree is not full,0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_N, right_N;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_N = binary_tree_is_full(tree->left);
	right_N = binary_tree_is_full(tree->right);

	if (left_N == 0 || right_N == 0)
		return (0);
	return (1);
}
