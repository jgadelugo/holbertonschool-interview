#!/usr/bin/python3
"""
returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid
    @grid: list of list of integers:
        0 represents water
        1 represents land
        Each cell is square, with a side length of 1
        Cells are connected horizontally/vertically (not diagonally).
        grid is rectangular, with its width and height not exceeding 100
    Return: the perimeter of the island described in grid
    """
    result = 0

    if (len(grid) == 0 or len(grid[0]) == 0):
        return 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                result += 4
                if (i > 0 and grid[i - 1][j] == 1):
                    result -= 2
                if (j > 0 and grid[i][j - 1] == 1):
                    result -= 2
    return result
