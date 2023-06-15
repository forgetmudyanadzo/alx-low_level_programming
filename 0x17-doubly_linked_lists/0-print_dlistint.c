#include "lists.h"

/**
 * print_dlistint - print all the values of each node in a dlistint_t list
 * @h: pointer to the head of the doubly linked list
 * Return: number of nodes in the list
*/

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current;/*pointer to the current node*/
	size_t count;/*variable to count the number of nodes*/

	current = h;/*start at the head of the list*/
	/*find the first node by travesing backwrds thrugh the previus pontrs*/
	while (current && current->prev)
		current = current->prev;

	count = 0;/*initialize the node count to zero*/

	/*iterate through each node and print its value*/
	for (; current; count++, current = current->next)
		printf("%d\n", current->n);

	return (count);/*return the nmber of nodes in the list*/
}
