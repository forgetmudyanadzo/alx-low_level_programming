#include <stdio.h>

/**
 * main - prints first 50 Fibonacci numbers, starting with 1 and 2
 * separatedby a comma followed by a space
 *
 * Return: Always 0
*/

int main(void)
{
	int count = 2;

	lont int i = 1, j = 2;
	long int k;

	printf("%lu, ", i);
	while (count <= 50)

	{
		if (count == 50)
		{
			printf("%lu\n", j);
		}
		else
		{
			printf("%lu, ", j);
		}

		k = j;
		j += i;
		i = k;
		count++;
	}
	return (0);
}
