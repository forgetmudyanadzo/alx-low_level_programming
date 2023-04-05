#include "lists.h"
#include <stdlib.h>

/**
 * add_node_end - add new node at the end of the list
 * @head: current in the list
 * @n: int to add to the list
 * Return: pointer to the current position in list
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *value;

	new = (listint_t *) malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{

		value = *head;
	}
	while (value->next != NULL)
	{
		value = value->next;
	}
	value->next = new;

	return (*head);
}
