#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints grid
 * @grid: grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * fix_sandpile - stabilizes sandpile
 * @new_grid: grid to stabilize into a sandpile
 *
 */
void fix_sandpile(int new_grid[3][3])
{
	int i, j, left, right, up, down;

	print_grid(new_grid);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (new_grid[i][j] > 3)
			{
				new_grid[i][j] -=  4;
				left = j - 1;
				right = j + 1;
				up = i - 1;
				down = i + 1;
				if (left > -1)
					new_grid[i][left] += 1;
				if (right < 3)
					new_grid[i][right] += 1;
				if (up > -1)
					new_grid[up][j] += 1;
				if (down < 3)
					new_grid[down][j] += 1;
			}
}

/**
 * sandpiles_sum - Calculaes the sum of two sandpiles
 * @grid1: double array (sandpile)
 * @grid2: double array (sandpile)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				fix_sandpile(grid1);

}
