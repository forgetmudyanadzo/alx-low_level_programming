#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
*/

char *_strncpy(char *dest, char *src, int n)

{
	int k;

	k = 0;
	while (k < n && src[k] != '\0')
	{
		dest[k] = src[k];
		k++;
	}
	while (k < n)
	{
		dest[k] = '\0';
		k++;
	}
	return (dest);
}
