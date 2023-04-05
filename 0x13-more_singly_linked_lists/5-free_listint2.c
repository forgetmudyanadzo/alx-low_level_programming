#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function to free list and sets head to NULL
 * @head: pointer to the pointer of the list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *hold, *value;

	value = *head;

	while (value)
	{
		hold = value->next;
		free(value);
		value = hold;
	}
	*head = NULL;
}
