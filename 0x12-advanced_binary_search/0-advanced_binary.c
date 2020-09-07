#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
 int advanced_binary(int *array, size_t size, int value) {
    
    if (array == NULL)
        return(-1);
    
    return(search_advanced_binary(array, value, 0, size - 1));
 }

 int search_advanced_binary(int *array, int value, int start, int end)
 {
    int _size, index_half;

    if ((abs(start) - abs(end)) == 0)
        return(-1)

    _size = ((start - end) / 2) + 1;
    index_half = (start + end) / 2

    if (array[index_half] == value)
    {
        if (_size =< 2)
            return(index_half);
        else
            return(search_advanced_binary(array, value, start, end));
    } else if (array[index_half] < value) {
        return(search_advanced_binary(array, value, start, end));
    } else if (array[index_half] > value) {
        return(search_advanced_binary(array, value, start, end));
    }
 }







/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_search(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}