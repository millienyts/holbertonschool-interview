#include <stdio.h>
#include "sandpiles.h"

/**
 * is_stable - checks if the sandpile grid is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 if not stable
 */
int is_stable(int grid[3][3]);

/**
 * toppling - topples the sandpile grid
 * @grid: 3x3 grid to topple
 */
void toppling(int grid[3][3]);

/**
 * print_grid - prints a 3x3 grid of integers
 * @grid: 3x3 grid to print
 *
 * Description: The grid is printed row by row with
 * a space between each number.
 */
static void print_grid(int grid[3][3]);

/**
 * sandpiles_sum - computes the sum of two 3x3 sandpile grids
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 *
 * Description: The grids are added element by element.
 * If the resulting grid is unstable, it will topple until stable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

    /* Sum the grids */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

    /* Check stability and apply toppling if necessary */
	while (!is_stable(grid1))
	{
		/* Print '=' only if the grid is unstable */
		printf("=\n");
		print_grid(grid1);
		toppling(grid1);
	}
}

/**
 * is_stable - checks if the grid is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 if not
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0); /* Not stable */
		}
	}
	return (1); /* Stable */
}

/**
 * toppling - topples the unstable cells in the grid
 * @grid: 3x3 grid to topple
 */
void toppling(int grid[3][3])
{
	int temp[3][3] = {0};
	int i, j;

    /* Topple the unstable cells */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1; /* Up */
				if (i < 2)
					temp[i + 1][j] += 1; /* Down */
				if (j > 0)
					temp[i][j - 1] += 1; /* Left */
				if (j < 2)
					temp[i][j + 1] += 1; /* Right */
			}
		}
	}

	/* Apply the toppling changes to the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
 * print_grid - prints a 3x3 grid of integers
 * @grid: 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
