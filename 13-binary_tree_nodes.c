#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree to count the nodes from
 * Return: number of nodes counted
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t N_left, N_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	N_left = binary_tree_nodes(tree->left);
	N_right = binary_tree_nodes(tree->right);
	return (N_left + N_right + 1);
}
