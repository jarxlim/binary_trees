#include "binary_trees.h"

/**
 * t_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t t_height(const heap_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l_height = 1 + t_height(tree->left);

	if (tree->right)
		r_height = 1 + t_height(tree->right);

	if (l_height > r_height)
		return (l_height);
	return (r_height);
}
/**
 * height_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t height_size(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l_height = 1 + height_size(tree->left);

	if (tree->right)
		r_height = 1 + height_size(tree->right);

	return (l_height + r_height);
}

/**
 * pre_order - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 * Return: No Return
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (height == NULL)
		*node = tree;
	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *temp1, *temp2;

	if (root == NULL)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		val = temp1->n;
		temp1->n = temp2->n;
		temp2->n = val;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 * Return: the val stored in the root node
 */
int heap_extract(heap_t **root)
{
	int val;
	heap_t *heap_r, *node;

	if (root == NULL || !*root)
		return (0);
	heap_r = *root;
	val = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (val);
	}

	pre_order(heap_r, &node, t_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (val);
}
