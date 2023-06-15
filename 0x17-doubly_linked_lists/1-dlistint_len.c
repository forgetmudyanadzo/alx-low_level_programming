#include "lists.h"

/**
 * dlistint_len - find the number of nodes in a doubly linked list
 * @h: head pointer to the doubly linked list
 * Return: number of nodes in the linked list
*/

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t count;

	current = h;/*start from head of the linked list*/

	while (current && current->prev)/*travse to the first node of the list*/
		current = current->prev;
	/*count the number of nodes in the linked list*/
	for (count = 0; current; count++, current = current->next)
		;

	return (count);/*return the count of nodes*/
}
