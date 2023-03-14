#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two strings using malloc
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to concat string
*/

char *str_concat(char *s1, char *s2)
{
	char *a;
	int x, y, k, n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (x = 0; s1[x] != '\0'; x++)
		;
	for (y = 0; s2[y] != '\0'; y++)
		;

	a = malloc((x * sizeof(*s1)) + (y * sizeof(*s2)) + 1);
	if (a == NULL)
		return (NULL);

	for (k = 0, n = 0; k < (x + y + 1); k++)
	{
		if (k < x)
			a[k] = s1[k];
		else
			a[k] = s2[n++];
	}
	return (a);
}
