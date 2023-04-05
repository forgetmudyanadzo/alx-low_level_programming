#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a list_t list
 * @h: pointer to head of the list
 * Return: number of nodes
*/

size_t print_listint(const listint_t *h)
{
	const listint_t *count;
	unsigned int n; /* number of nodes */

	count = h;
	n = 0;
	while (count != NULL)
	{
		printf("%i\n", count->n);
		count = count->next;
			n++;
	}
	return (n);
}
