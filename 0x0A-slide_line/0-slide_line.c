#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: Points to an array of integers containing size elements
 * @size: Number of elements in @array
 * @direction: merged direction
 *
 * Return: return 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int size_i = size;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	switch (direction)
	{
	case SLIDE_LEFT:
		slide_line_to_left(line, size_i);
		break;
	case SLIDE_RIGHT:
		slide_line_to_rigth(line, size_i);
		break;
	}

	return (1);
}

/**
 * slide_line_to_left - Slides and merges an array of integers to left
 * @line: Points to an array of integers containing size elements
 * @size_i: Number of elements in @array
 */
void slide_line_to_left(int *line, int size_i)
{
	int i, j, temp;

	j = 0;
	temp = line[0];
	for (i = 0; i < size_i; i++)
	{
		if (line[i])
		{
			if (i != 0)
			{
				if (line[i] == temp)
				{
					line[j] = line[i] + temp;
					temp = 0;
					j++;
				}
				else
				{
					if (temp != 0)
					{
						line[j] = temp;
						j++;
					}
					if (i == size_i - 1)
					{
						line[j] = line[i];
						j++;
					}
					temp = line[i];
				}
			}
		}
	}

	/* fill with 0 of rest spaces line */
	for (; j < size_i; j++)
		line[j] = 0;
}

/**
 * slide_line_to_rigth - Slides and merges an array of integers to rigth
 * @line: Points to an array of integers containing size elements
 * @size_i: Number of elements in @array
 */
void slide_line_to_rigth(int *line, int size_i)
{
	int i, j, temp;

	j = size_i - 1;
	temp = line[j];
	for (i = size_i - 1 ; i >= 0; i--)
	{
		if (line[i])
		{
			if (i != size_i - 1)
			{
				if (line[i] == temp)
				{
					line[j] = line[i] + temp;
					temp = 0;
					j--;
				} else
				{
					if (temp != 0)
					{
						line[j] = temp;
						j--;
					}
					if (i == 0)
					{
						line[j] = line[i];
						j--;
					}
					temp = line[i];
				}
			}
		}
	}

	/* fill with 0 of rest spaces line */
	for (; j >= 0; j--)
		line[j] = 0;
}
