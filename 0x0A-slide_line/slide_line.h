#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_line_to_left(int *line, int size_i);
void slide_line_to_rigth(int *line, int size_i);

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

#endif /* SLIDE_LINE */
