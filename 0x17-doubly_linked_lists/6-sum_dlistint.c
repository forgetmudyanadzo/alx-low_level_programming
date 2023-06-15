#include "lists.h"

/**
 * sum_dlistint - get the sum of all the data n of a dlistint_t linked list
 * @head: pointer of the doubly linked list
 * Return: the sum of all n or 0 if linked list is empty
*/

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;/*ptr to current node being processed*/
	int sum = 0;/*variable to store the sum of 'n' values*/

	current = head;
	/*iterate through the linked list and calculate the sum*/
	for (; current; current = current->next)
		sum += current->n;

	return (sum);
}
