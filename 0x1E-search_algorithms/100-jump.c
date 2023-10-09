#include "search_algos.h"
#include <math.h>

size_t min(size_t a, size_t b);

/**
 * min - returns minimum of two size_t values
 * @a: first value
 * @b: second value
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}
/**
 * jump_search - searche value in sorted array of integers using
 * jump search algorithm
 * @array: pointer to first element of array to search for
 * @size: number of elements in array
 * @value: value to search
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t low, high, jump;

	if (!array || size == 0)
		return (-1);

	jump = sqrt(size);

	for (high = 0; high < size && array[high] < value;
	     low = high, high += jump)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       high, array[high]);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	for (; low <= min(high, size - 1); low++)
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
		if (array[low] == value)
			return (low);
	}

	return (-1);
}