#include "binary_trees.h"

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
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 * Return: the generated array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = height_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (index = 0; heap; index++)
		a[index] = heap_extract(&heap);

	return (a);
}
