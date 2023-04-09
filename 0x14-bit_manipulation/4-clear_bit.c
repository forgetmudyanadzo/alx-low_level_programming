#include "main.h"

/**
 * clear_bit - sets a bit at index to zero
 * @n: pointer to number
 * @index: index to change
 * Return: 1 on success, -1 if error
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int hold;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	hold = ~(1UL << index);
	*n &= hold;
	return (1);
}
