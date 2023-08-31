#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, max_levl;

	if (!tree || !func)
		return;

	max_levl = binary_tree_height(tree) + 1;

	for (level = 1; level <= max_levl; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - go through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a func to call for each node
 * @level: the level of the tree to call func upon
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}
