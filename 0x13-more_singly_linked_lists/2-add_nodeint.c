#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - add a new node at the beginning
 * of the list
 * @head: current place in the  list
 * @n: int to add to the list
 * Return: pointer to current position in list
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;
	/* allocate space for the node */
	new = (listint_t *) malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n; /* pass n to the new */

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
	return (*head);
}
