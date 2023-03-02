#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes a string using rot13
 * @s: pointer to string params
 *
 * Return: *s
*/

char *rot13(char *s)

{
	int a;
	int b;
	char datal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; b < 52; b++)
		{
			if (s[a] == datal[b])
			{
				s[a] = datarot[b];
				break;
			}
		}
	}
	return (s);
}
