#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Compute the sum of two 3x3 sandpiles and stabilize it
 * @grid1: First 3x3 grid (will be modified in-place)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    // Step 1: Sum the two grids
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Step 2: Stabilize the grid
    while (is_unstable(grid1))
    {
        // Print the grid before toppling if unstable
        printf("=\n");
        print_grid(grid1);

        // Topple unstable cells
        topple(grid1);
    }
}

/**
 * is_unstable - Check if the grid is unstable
 * @grid: 3x3 grid
 *
 * Return: 1 if unstable, 0 otherwise
 */
static int is_unstable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 1;  // Unstable
        }
    }

    return 0;  // Stable
}

/**
 * topple - Perform one toppling operation on the grid
 * @grid: 3x3 grid (will be modified in-place)
 */
static void topple(int grid[3][3])
{
    int temp_grid[3][3] = {0};
    int i, j;

    // Copy current grid to a temporary grid for toppling
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                // Distribute the grains to neighbors
                temp_grid[i][j] -= 4;
                if (i - 1 >= 0)
                    temp_grid[i - 1][j] += 1;
                if (i + 1 < 3)
                    temp_grid[i + 1][j] += 1;
                if (j - 1 >= 0)
                    temp_grid[i][j - 1] += 1;
                if (j + 1 < 3)
                    temp_grid[i][j + 1] += 1;
            }
        }
    }

    // Add the temporary grid's values back to the original grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] += temp_grid[i][j];
        }
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
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

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}
