#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value){

	heap_t *new_node, *temp, *inserted_node, *node = *root;
	size_t tree_height, tree_size, expected_nodes, expected_leaves, expected_later_nodes, current_leaves_last_level;

	(void)temp;
	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return(NULL);

	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL){
		new_node->parent = NULL;
		new_node->n = value;
		inserted_node = new_node;
		*root = new_node;
	} else {
		tree_height = binary_tree_height(node);
		tree_size = binary_tree_size(node);
		expected_nodes = binary_tree_expected_nodes(tree_height);
		expected_leaves = _pow_recursion(2, tree_height);

		if (value > node->n){
			new_node->left = node->left;
			new_node->right = node->right;
			new_node->parent = node->parent;
			new_node->n = node->n;
			value = node->n;
			temp = node;
			node = new_node;
			inserted_node = new_node;
			new_node = node;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->parent = NULL;
		}

		if (expected_nodes - tree_size == 0)
		{
			if (node->left){
				heap_insert(&node, value);
			} else {
				new_node->n = value;
				new_node->parent = node;
				node->left = new_node;
				inserted_node = new_node;
			}
		} else {
			expected_later_nodes = binary_tree_expected_nodes(tree_height - 1);
			current_leaves_last_level = tree_size - expected_later_nodes;

			if (current_leaves_last_level <= expected_leaves / 2) {
				if (node->left){
					heap_insert(&node, value);
				} else {
					new_node->n = value;
					new_node->parent = node;
					node->left = new_node;
					inserted_node = new_node;
				}
			} else {
				if (node->right){
					heap_insert(&node, value);
				} else {
					new_node->n = value;
					new_node->parent = node;
					node->right = new_node;
					inserted_node = new_node;
				}
			}
		}

	}

	return(inserted_node);
}

/**
 * binary_tree_expected_nodes - return the height of a node
 * @tree: pointer to binary tree
 *
 * Return: return the height of a node
 */

 size_t binary_tree_expected_nodes(size_t tree_height)
 {
	size_t i, expected_nodes;

	expected_nodes = 0;
	for (i = 0; i <= tree_height; i++)
	{
		expected_nodes =  _pow_recursion(2, i) + expected_nodes;
	}

	return(expected_nodes);
 }

/**
 *_pow_recursion - returns the value of x raised to the power of y.
 *@x: number raised.
 *@y: number power.
 *
 *Return: the result pow. If the number is less that 0, return -1.
 **/
int _pow_recursion(int x, int y)
{
	int rs = 0;

	if (y == 0)
	{
		rs = 1;
	}
	if (y == 1)
	{
		rs = x;
	}
	if (y < 0)
	{
		rs = -1;
	}
	if (y > 1)
	{
		rs = x * _pow_recursion(x, y - 1);
	}
	return (rs);
}

/**
 * binary_tree_height - return the height of a node
 * @tree: pointer to binary tree
 *
 * Return: return the height of a node
 */

size_t binary_tree_height(const heap_t *tree)
{

	int left = 0;
	int right = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		if (tree->left)
			left = (1 + binary_tree_height(tree->left));
		if (tree->right)
			right = (1 + binary_tree_height(tree->right));

		if (left > right)
			return (left);
		else
			return (right);
	}
}

/**
 * binary_tree_size - return the size of a tree
 * @tree: pointer to binary tree
 *
 * Return: return the size of a node
 */

size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}