#include "main.h"

/**
 * flips_bits - calculates the number of bits needed
 * to get from number to another
 * @n: base number
 * @m: number to transform to
 * Return: the number of bit transformations needed
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int hold = n ^ m;
	unsigned int count = 0;

	while (hold)
	{
		/* count the number of set bits in hold */
		count += hold & 1;
		hold >>= 1; /* shift right to process the next bit */
	}
	return (count);
}
