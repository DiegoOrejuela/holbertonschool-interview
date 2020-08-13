#include "search.h"

/**
 *linear_skip -  Linear search in a skip list
 *
 *@list: is a pointer to the head of the skip list to search in
 *@value: value to search for
 *
 *Return: pointer on the first node where value is located,
 *or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start_node,
		*node_express = list->express,
		*previous_node = list;
	int end_index,
		size_list = lent_list(list);

	if (!list)
		return (NULL);

	for ( ; node_express; node_express = node_express->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node_express->index, node_express->n);

		if (value == node_express->n)
		{
			return (node_express);
		} else if (value < node_express->n)
		{
			start_node = previous_node;
			end_index = node_express->index;
			printf("Value found between indexes [%lu] and [%d]\n",
			       start_node->index, end_index);
			return (linear_skip_root_level(value, start_node, end_index));
		}

		previous_node = node_express;
	}
	if ((int) previous_node->index < size_list)
	{
		start_node = previous_node;
		end_index = size_list - 1;
		printf("Value found between indexes [%lu] and [%d]\n",
		       previous_node->index, end_index);
		return (linear_skip_root_level(value, start_node, end_index));
	}
	return (NULL);
}

/**
 *linear_skip_root_level -  linear skip root level
 *
 *@value: value to search for
 *@start_node: is a pointer to the head of the skip list to search in
 *@end_index: end index
 *
 *Return: pointer on the first node where value is located,
 *or NULL on failure
 */
skiplist_t *linear_skip_root_level(int value, skiplist_t *start_node,
				   int end_index)
{
	skiplist_t *node = start_node;

	for ( ; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		if (node->n == value)
			return (node);
		if ((int) node->index == end_index)
			break;
	}
	return (NULL);
}

/**
 *lent_list -  lent list
 *
 *@list: value to search for
 *
 *Return: length list
 */
int lent_list(skiplist_t *list)
{
	skiplist_t *node;
	int count = 0;

	for (node = list; node ; node = node->next)
		count++;

	return (count);
}
