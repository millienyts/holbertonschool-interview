#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * draw - Determines if a character should be a # or a space.
 * @row: Row index of the character.
 * @col: Column index of the character.
 *
 * Return: '#' if the position is part of the Menger Sponge, ' ' otherwise.
 */
char draw(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}
	return ('#');
}

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: Level of the Menger Sponge.
 */
void menger(int level)
{
	if (level < 0)
	return;

	int size = pow(3, level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			putchar(draw(row, col));
		}
	putchar('\n');
	}
}
