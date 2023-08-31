#include "binary_trees.h"
/**
 * inheriter - get the next inheriter
 * @node: tree to use
 * Return: the min value of the tree
 */
int inheriter(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = inheriter(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}
/**
 * double_child - function that gets the next inheriter
 * @root: node with two children
 * Return: the value gotten
 */
int double_child(bst_t *root)
{
	int new_val = 0;

	new_val = inheriter(root->right);
	root->n = new_val;
	return (new_val);
}
/**
 *remover - removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remover(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (double_child(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int typ = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		typ = remover(root);
		if (typ != 0)
			bst_remove(root->right, typ);
	}
	else
		return (NULL);
	return (root);
}
