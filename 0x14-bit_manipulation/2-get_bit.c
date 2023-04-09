#include "main.h"

/**
 * get_bit - get the value of int at an index
 * @n: long int
 * @index: index to start at
 * Return: value of bit at index or -1 if error
*/

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int value;

	/* checks if the given index is greater than 64 */
	if (index > 64)
		return (-1);
	/* right shift the input number n */
	value = n >> index;

	return (value & 1);
}
