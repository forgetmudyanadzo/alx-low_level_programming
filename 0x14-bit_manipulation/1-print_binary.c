#include "main.h"

/**
 * print_brinary - prints binary representation of a number
 * @n: decimal number to print as binary
*/

void print_binary(unsigned long int n)
{
	int total, power;

	if (n == 0)
		_putchar('0');

	/*iterate through all the bits of n,starting from most significant bit*/
	for (power = 0, total = sizeof(n) * 8 - 1; total >= 0; total--)
	{
		/* check if the current bit is set */
		if ((n >> total) & 1)
			power = 1; /* mark the  start of the printing */
		/* if we have already started printing, print the current bit */
		if (power == 1)
			((n >> total) & 1) ? _putchar('1') : _putchar('0');
	}
}
