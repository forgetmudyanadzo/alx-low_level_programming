#include "lists.h"
#include <stdio.h>

/**
 * reverse_listint -  define function to reverse a listint_t linked list
 * @head: a double pointer argument to head
 * Return: a pointer to the first node of the reversed  list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *pos, *tmp;

	if (*head == NULL)
		return (NULL);

	tmp = *head;
	*head = tmp->next;
	pos = (*head)->next;
	tmp->next = NULL;

	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}

	while (pos != NULL)
	{
		(*head)->next = tmp;
		tmp = *head;
		*head = pos;
		pos = (*head)->next;
	}

	(*head)->next = tmp;

	return (*head);
}
