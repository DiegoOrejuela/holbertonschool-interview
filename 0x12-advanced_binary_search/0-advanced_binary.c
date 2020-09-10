#include "search_algos.h"

/**
 * advanced_binary - Prints an array of integers
 *
 * @array: The array to be searched the value
 * @size: Number of elements in @array
 * @value: number to search in array
 *
 * Return: If value is not present in array or if array is NULL,
 * your function must return -1
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (array == NULL)
		return (-1);

	return (search_advanced_binary(array, value, 0, size - 1));
}

/**
 * search_advanced_binary - Recursion function to search in array
 *
 * @array: The array to be searched the value
 * @value: number to search in array
 * @start: start index to search in array
 * @end: end index to search in array
 *
 * Return: If value is not present in array or if array is NULL,
 * your function must return -1
 */
int search_advanced_binary(int *array, int value, int start, int end)
{
	int temp_size, index_half;

	if ((abs(start) - abs(end)) == 0)
		return (-1);

	temp_size = ((abs(end) - abs(start)) / 2) + 1;
	index_half = (start + end) / 2;

	print_search(array, start, end);
	if (array[index_half] == value)
	{
		if (temp_size <= 2)
			return (index_half);
		else
			return (search_advanced_binary(array, value,
						       start, index_half));
	} else if (array[index_half] < value)
	{
		return (search_advanced_binary(array, value,
					       index_half + 1, end));
	} else if (array[index_half] > value)
	{
		return (search_advanced_binary(array, value, start, index_half));
	}
	return (-1);
}

/**
 * print_search - Prints search in array
 *
 * @array: The array to be printed
 * @start: start index to print in array
 * @end: end index to print in array
 */
void print_search(const int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
