#!/usr/bin/python3
"""
0x16. Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees
    - Do not return anything. The matrix must be edited in-place.
    - You can assume the matrix will have 2 dimensions and will not be empty.
    """

    matrix_copy = matrix.copy()

    for iter in range(len(matrix[0])):
        temp_array = []

        for row in reversed(matrix_copy):
            temp_array.append(row[iter])

        matrix[iter] = temp_array
