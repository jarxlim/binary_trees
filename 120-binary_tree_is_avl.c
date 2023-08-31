#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * Return: 1 if tree is avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is avl, 0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int l_path, r_path;

	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	l_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(l_path - r_path) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
}
