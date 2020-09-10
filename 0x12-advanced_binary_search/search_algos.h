#ifndef search_algos_H
#define search_algos_H
#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int search_advanced_binary(int *array, int value, int start, int end);
void print_search(const int *array, int start, int end);

#endif /* search_algos_H */
