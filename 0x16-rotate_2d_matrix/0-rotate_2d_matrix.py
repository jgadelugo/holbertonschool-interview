#!/usr/bin/python3
""" Rotate a 2D matrix 90 degrees"""


def rotate_2d_matrix(matrix):
    """ Rotate a 2D matrix 90 degrees
    *you can assume the matrix will have 2 dims and not empty
    *Do not return anything. Matrix must be edited in place
    """
    matrix.reverse()
    matrix_temp = matrix.copy()

    for i in range(len(matrix)):
        matrix[i] = [row[i] for row in matrix_temp]
