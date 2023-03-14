#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstorstr - concatenate all arguments of your program with newline
 * @ac: argument count
 * @av: double pointer to array of strings passed to main
 * Return: Null if fail, else return pointer to new string
*/

char *argstostr(int ac, char **av)
{
	char *a, *retp;
	int y, n, total;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (y = 0, total = 0; y < ac; y++)
	{
		for (n = 0; *(*(av + y) + n) != '\0'; n++, total++)
			;
		total++;
	}
	total++;

	a = malloc(total * sizeof(char));
	if (a == NULL)
		return (NULL);

	retp = a;
	for (y = 0; y < ac; y++)
	{
		for (n = 0; av[y][n] != '\0'; n++)
		{
			*a = av[y][n];
			a++;
		}
		*a = '\n';
		a++;
	}
	return (retp);
}
