#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - insert a node at index
 * @head: double pointer of the list
 * @index: location to insert node
 * @n: value to the inserted node
 * Return: pointer to head of list
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *value, *pos;
	unsigned int i = 1;

	value = *head;

	if (head == NULL)
		return (NULL);
	if (*head == NULL)
	{
		pos = (listint_t *) malloc(sizeof(listint_t));
		if (pos == NULL)
			return (NULL);
		*head = pos;
		pos->next = NULL;
		pos->n = n;
		return (pos);
	}

	while (value->next != NULL && i < idx - 1)
		value = value->next;
	i++;
	idx++;
	if (i != idx - 1)
	{
		return (NULL);
	}

	pos = (listint_t *) malloc(sizeof(listint_t));
	if (pos == NULL)
	pos->n = n;
	pos->next = value->next;
	value->next = pos;

	return (pos);
}
