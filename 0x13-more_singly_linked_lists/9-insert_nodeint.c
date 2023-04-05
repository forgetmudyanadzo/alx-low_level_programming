#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - insert a node at index in linked list
 * @head: double pointer of the list
 * @index: location to insert node
 * @n: value to the inserted node
 * Return: pointer to head of list
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *value;
	listint_t *temp = *head;

	value = malloc(sizeof(listint_t));
	if (!value || !head)
		return (NULL);
	value->n = n;
	value->next = NULL;
	if (idx == 0)
	{
		value->next = *head;
		*head = value;
		return (value);
	}
	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			value->next = temp->next;
			temp->next = value;
			return (value);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}
