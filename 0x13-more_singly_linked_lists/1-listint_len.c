#include "lists.h"

/**
 * listint_len - number of elements in a list
 * @h: singly linked list to print
 * Return: number of nodes in the list
 */

size_t listint_len(const listint_t *h)
{
	const listint_t *count;
	unsigned int n; /* number of nodes */

	count = h;
	n = 0;
	while (count != NULL)
	{
		count = count->next;
		n++;
	}
	return (n);
}

