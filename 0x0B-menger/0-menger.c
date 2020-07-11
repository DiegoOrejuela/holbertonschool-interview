#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	char *sponge = malloc(1), *temp_sponge;
	int i, j, sub_level, sponge_area, past_sponge_side_size,
		temp_j, iteration, sponge_side_size, row, row_subsponge;
	sponge[0] = '#';
	if (level < 0)
		return;
	if (level == 0)
	{
		printf("%s\n", sponge);
		return;
	}
	for (sub_level = 1; sub_level <= level; sub_level++) /*level = 1*/
	{
		sponge_side_size  = (int) pow(3, sub_level);
		sponge_area = sponge_side_size * sponge_side_size;
		past_sponge_side_size = (int) pow(3, sub_level - 1);

		temp_sponge = copy_sponge(sponge);
		sponge = realloc(sponge, sizeof(char) * sponge_area);

		temp_j = j = 0;
		iteration = row_subsponge = row = 1;
		for (i = 0, j = 0; i < sponge_area; i++, j++)
		{
			if (i % past_sponge_side_size == 0 && i != 0)
			{
				iteration++;
				reset_iteration_past_sponge_size(i, &j, &temp_j,
								 sponge_side_size, past_sponge_side_size);
				manager_travel_on_rows(i, past_sponge_side_size,
						       sponge_side_size,
						       &row_subsponge, &row);
			}
			sponge[i] = row != 2 || row_subsponge != 2 ? temp_sponge[j] : ' ';
		}
		free(temp_sponge);
	}
	free(sponge);
	print_sponge(sponge, sponge_area, sponge_side_size);
}

/**
 * copy_sponge - copy array sponge
 *
 * @sponge: pointer sponge
 *
 * Return: copy sponge
 */
char *copy_sponge(char *sponge)
{
	int i, length_sponge = strlen(sponge);
	char *sponge_copy;

	sponge_copy = malloc(length_sponge);

	for (i = 0; i < length_sponge; i++)
	{
		sponge_copy[i] = sponge[i];
	}

	return (sponge_copy);
}

/**
 * reset_iteration_past_sponge_size - reset iteration past sponge size
 *
 * @i: iterator sponge
 * @j: iterator subsponge
 * @temp_j: temp iterator subsponge
 * @sponge_side_size: sponge side size
 * @past_sponge_side_size: past sponge side size
 */
void reset_iteration_past_sponge_size(int i, int *j, int *temp_j,
				      int sponge_side_size,
				      int past_sponge_side_size)
{
	if (i % past_sponge_side_size == 0)
	{
		(*j) = (*temp_j);
	}

	if (past_sponge_side_size != 1)
	{
		if (i % sponge_side_size == 0)
		{
			(*j) += past_sponge_side_size;
			(*temp_j) += past_sponge_side_size;
		}

		if (i % (sponge_side_size * past_sponge_side_size) == 0)
		{
			(*j) = 0;
			(*temp_j) = 0;
		}
	}
}


/**
 * manager_travel_on_rows - manager travel on rows
 *
 * @i: iterator sponge
 * @past_sponge_side_size: past sponge side size
 * @sponge_side_size: sponge side size
 * @row_subsponge: row subsponge pointer
 * @row: row pointer
 */
void manager_travel_on_rows(int i, int past_sponge_side_size,
			    int sponge_side_size, int *row_subsponge, int *row)
{
	if (i % past_sponge_side_size == 0 && i != 0)
		(*row_subsponge)++;

	if (i % sponge_side_size == 0)
		(*row_subsponge) = 1;

	if (i % (sponge_side_size * past_sponge_side_size) == 0)
		(*row)++;
}




/**
 * print_sponge - print sponge
 *
 * @sponge: pointer sponge
 * @sponge_area: size sponge
 * @sponge_side_size: sponge side size
 */
void print_sponge(char *sponge, int sponge_area, int sponge_side_size)
{
	int i;

	for (i = 0; i < sponge_area; i++)
	{
		putchar(sponge[i]);

		if ((i + 1) % sponge_side_size == 0)
		{
			putchar('\n');
		}
	}
}
