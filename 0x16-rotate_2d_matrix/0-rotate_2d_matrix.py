#!/usr/bin/python3

def rotate_2d_matrix(matrix):
    """ Rotate a 2D matrix 90 degrees
    *you can assume the matrix will have 2 dims and not empty
    *Do not return anything. Matrix must be edited in place
    """
    N = len(matrix)
    for i in range(int(N / 2)):
        for j in range(N - i - 1):
            temp = matrix[i][j]
            # print(f"[{i}][{j}] <- [{N-1-j}][{i}]")
            matrix[i][j] = matrix[N-1-j][i]
            # print(f"[{N-1-j}][{i}] <- [{N-1-i}][{N-1-j}]")
            matrix[N-1-j][i] = matrix[N-1-i][N-1-j]
            # print(f"[{N-1-i}][{N-1-j}] <- [{j}][{N-1-i}]")
            matrix[N-1-i][N-1-j] = matrix[j][N-1-i]
            # print(f"[{j}][{N-1-i}] <- [{i}][{j}]")
            matrix[j][N-1-i] = temp
            # print("----------")
