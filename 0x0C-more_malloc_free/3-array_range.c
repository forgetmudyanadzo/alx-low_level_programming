#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to newly created array
 * NULL if malloc fails
 * NULL if min > max
*/
int *array_range(int min, int max)
{
	int size, s;
	int *ptr;

	size = 0;

	if (min > max)
		return (NULL);

	size = ((max + 1) - min);

	ptr = malloc(size * sizeof(int));

	if (ptr == NULL)
		return (NULL);

	for (s = 0; s < size; s++)
	{
		*(ptr + 1) = min + s;
	}

	return (ptr);
}
