#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - calculate and return string length
 * @string: string
 * Return: string length
*/
int _strlen(char *string)
{
	int a;

	for (a = 0; string[a] != '\0'; a++)
		;
	return (a);
}
/**
 * string_nconcat - concatenate s1 and n bytes of s2; return ptr to string
 * @s1: string 1 to append to
 * @s2: string 2 to concatenate from
 * @n: n bytes to concat from string 2
 * Return: pointer to concatenated string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	int num, len, a, y;

	num = n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (num < 0)
		return (NULL);
	if (num >= _strlen(s2))
		num = _strlen(s2);

	len = strlen(s1) + num + 1;

	ptr = malloc(sizeof(*ptr) * len);
	if (ptr == NULL)
		return (NULL);

	for (a = 0; s1[a] != '\0'; a++)
		ptr[a] = s1[a];
	for (y = 0; y < num; y++)
		ptr[a + y] = s2[y];
	ptr[a + y] = '\0';

	return (ptr);
}
