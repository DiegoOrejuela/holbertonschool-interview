#ifndef _MENGER_
#define _MENGER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void menger(int level);

/* Helpers */
void print_sponge(char *sponge, int sponge_area, int sponge_side_size);
void manager_travel_on_rows(int i, int past_sponge_side_size, int sponge_side_size, int *row_subsponge, int *row);
void reset_iteration_past_sponge_size(int i, int *j, int *temp_j, int sponge_side_size, int past_sponge_side_size);
char *copy_sponge(char *sponge);

#endif
