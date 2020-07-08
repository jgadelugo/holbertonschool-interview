#include "menger.h"
#include <stdio.h>

/**
 * find_hole - finds if it should print # or hole
 * @i: row that we are on
 * @j: column that we are on
 * @check: integer used for logic
 * Return: # if no hole, or ' ' if hole
 */
char find_hole(int i, int j, int check)
{
	if (check == 0)
		return ('#');
	if ((i % (check * 3)) / check == 1)
		if ((j % (check * 3)) / check == 1)
			return (' ');
	return (find_hole(i, j, check / 3));
}


/**
 * menger - prints a 2D menger sponge
 * @level: level of menger sponge
 *
 */
void menger(int level)
{
	int i, j, levelSize;

	levelSize = pow(3, level);

	for (i = 0; i < levelSize; i++)
	{
		for (j = 0; j < levelSize; j++)
		{
			putchar(find_hole(i, j, levelSize / 3));
		}
		putchar('\n');
	}
}
