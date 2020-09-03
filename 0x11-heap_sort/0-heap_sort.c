#include "sort.h"
/**
 * print_array - Prints an array of integers
 *
 * @array: Array of integers to be printed
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    int limit_index, i, first_node_index, last_node_index;

	for (i = 0; i < (int)size; i++)
    {
        limit_index = (int)size - (i + 1);

        build_heap_sort(array, limit_index, 0, size);

        /* Organize array */
		first_node_index = 0;
		last_node_index = limit_index;

        siftDown(array, first_node_index, last_node_index, size);
    }
}

/**
 * print_array - Prints an array of integers
 *
 * @array: Array of integers to be printed
 * @size: Number of elements in @array
 */
void build_heap_sort(int *array, int limit, int index, size_t size)
{
    int left = 1, right = 2, node = array[index], parent_index,
        child_left_index, child_right_index;
    
    parent_index = get_index_parent(index); /* 0 */ /* 0 */
    child_left_index = get_index_child(limit, index, left); /* 1 */ /* 0 */
    child_right_index = get_index_child(limit, index, right); /* 0 */ /* 0 */

    if (child_left_index)
        build_heap_sort(array, limit,  child_left_index, size);
    if (child_right_index)
        build_heap_sort(array, limit, child_right_index, size);
    
    if (node > array[parent_index]) /* true */
        siftDown(array, index, parent_index, size);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: Array of integers to be printed
 * @size: Number of elements in @array
 */
int get_index_parent(int index)
{
    return ((index - 1) / 2);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: Array of integers to be printed
 * @size: Number of elements in @array
 */
int get_index_child(int limit, int parent_index, int side)
{
    int child_index =  2 * parent_index + side;

    if (child_index > limit)
        return(0);
    return(child_index);
}

/**
 * print_array - Prints an array of integers
 *
 * @array: Array of integers to be printed
 * @size: Number of elements in @array
 */
void siftDown(int *array, int index_a, int index_b, size_t size)
{
    int temp;

    temp = array[index_a]; /*index: 1 (48) */
    array[index_a] = array[index_b]; /*index_b: 0 (19) */
    array[index_b] = temp; /*index_b: 1 = (48) */
    print_array(array, size);
}




