#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicate a string using malloc
 * @str: string to duplicate
 * Return: Pointer to a new duped string
*/

char *_strdup(char *str)
{
	char *a;
	int s, c;

	if (str == NULL)
		return (NULL);

	for (s = 0; str[s] != '\0'; s++)
		;

	a = malloc(s * sizeof(*a) + 1);

	if (a == NULL)
		return (NULL);

	for (c = 0; c < s; c++)
		a[c] = str[c];
	a[c] = '\0';

	return (a);
}
