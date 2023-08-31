#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "4-binary_tree_is_leaf.c"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect,
 *         0 otherwise.
 *         If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left_C, *right_C;

	if (tree == NULL)
		return (0);

	left_C = tree->left;
	right_C = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);
	if (left_C == NULL || right_C == NULL)
		return (0);
	if (binary_tree_height(left_C) == binary_tree_height(right_C))
	{
		if (binary_tree_is_perfect(left_C) &&
		    binary_tree_is_perfect(right_C))
			return (1);
	}
	return (0);
}
