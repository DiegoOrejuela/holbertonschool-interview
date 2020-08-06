#include "binary_trees.h"

/**
 *sorted_array_to_avl - build an AVL tree from array
 *
 *@array: first element pointer array
 *@size: size array
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_tree;

	if (size == 0 || !array)
		return (NULL);

	new_tree = build_avl_tree(NULL, array, 0, size - 1);

	return (new_tree);
}


/**
 *build_avl_tree - build in fact an AVL tree
 *
 *@parent: parent pointer
 *@array: array pointer
 *@start: index to start
 *@end: index to end
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *build_avl_tree(avl_t *parent, int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t index;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	index = (start + end) / 2;

	node->n = array[index];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (index != start)
		node->left = build_avl_tree(node, array, start, index - 1);

	if (index != end)
		node->right = build_avl_tree(node, array, index + 1, end);

	return (node);
}
