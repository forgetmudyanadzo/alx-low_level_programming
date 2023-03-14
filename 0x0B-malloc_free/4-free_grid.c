#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free up a 2d grid
 * @grid: double pointer 2d grid
 * @height: heigt of grid
*/

void free_grid(int **grid, int height)
{
	int n;

	for (n = 0; n < height; n++)
		free(grid[n]);
	free(grid);
}
