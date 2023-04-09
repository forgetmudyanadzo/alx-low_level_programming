#include "main.h"
#include <stdio.h>

/**
 * binary_to_unit - convert a binary number to an unsigned int
 * @b: string of chars
 * Return: converted number or 0 if there is more chars in string
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int uint_value, bit_position;
	int total;

	if (b == NULL)
		return (0);
	for (total = 0; b[total]; total++)
	{
		if (b[total] != '0' && b[total] != '1')
			return (0);
	}
	for (bit_position = 1, uint_value = 0, total--;
			total >= 0; total--, bit_position *= 2)
	{
		if (b[total] == '1')
			uint_value += bit_position;
	}
	return (uint_value);
}
