#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function to free list and sets head to NULL
 * @head: pointer to the pointer of the list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *freed, *value;

	value = *head;

	if (head == NULL || value != NULL)
		return;
	while (value != NULL)
	{
		freed = value;
		value = value->next;
		free(freed);
	}
	*head = NULL;
}
