#include "menger.h"


/**
 * copy_sponge - copy array sponge
 *
 * @sponge: pointer sponge
 */
char *copy_sponge(char *sponge) {
    int i, length_sponge = strlen(sponge) ;
    char *sponge_copy;

    sponge_copy = malloc(length_sponge);

    for (i = 0; i < length_sponge; i++)
    {
        sponge_copy[i] = sponge[i];
    }

    return (sponge);
}

/**
 * slide_line - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
    char *sponge = "#", *temp_sponge;
    int i, j, limit, sub_level, sponge_area, past_sponge_side_size, 
    temp_j, iteration, sponge_side_size, row, row_subsponge;

    if (level < 0)
        return;
    if (level == 0) {
        printf("%s\n", sponge);
        return;
    }

    for (sub_level = 1; sub_level <= level; sub_level++){ /*level = 1*/
        sponge_side_size  = (int) pow(3, sub_level); /* = 3 Lado de la esponja */
        sponge_area = sponge_side_size * sponge_side_size; /* = 9 Area de la esponja*/

        past_sponge_side_size = limit = (int) pow(3, sub_level - 1); /* = 1 Lado de la pasada esponja */
        /*past_sponge_area = past_sponge_side_size * past_sponge_side_size;*/ /* = 1 Area de la pasada esponja*/

        temp_sponge = copy_sponge(sponge); /* = '#' Copia de la esponja*/
        sponge = malloc((sizeof(char) * sponge_area)); /* 9 espacios en memoria */

        temp_j = j = 0;
        iteration = row_subsponge = row = 1; 
        for (i = 0, j = 0; i < sponge_area; i++, j++) {

            if (i % past_sponge_side_size == 0 && i != 0) {
                iteration++;

                /*reset_iteration_past_sponge_size*/
                if (i % past_sponge_side_size == 0) { 
                    j = temp_j;
                }                    

                if (past_sponge_side_size != 1){
                    if (i % sponge_side_size == 0)
                    {
                        j += limit;
                        temp_j += limit;
                    }

                    if (i % (sponge_side_size * past_sponge_side_size) == 0 )
                    {
                        j = 0;
                        temp_j = 0;
                    }
                }

                /* count travel on rows */
                if (i % past_sponge_side_size == 0 && i != 0)
                    row_subsponge++;

                if (i % sponge_side_size == 0)
                    row_subsponge = 1;
                
                if (i % (sponge_side_size * past_sponge_side_size) == 0 )
                    row++;
            }

            sponge[i] = row != 2 || row_subsponge != 2 ? temp_sponge[j] : ' ';
        }
    }

    /* print sponge */
    for (i = 0; i < sponge_area; i++) { 
        putchar(sponge[i]);
        
        if ((i + 1) % sponge_side_size == 0) {
            putchar('\n');
        }
    }

    

}