#include "lists.h"

/**
 * free_dlistint - free a dlistint_t doubly linked list
 * @head: pointer to the head of linked list
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head)
	{
		current = head;

		head = head->next;
		current->prev = NULL;
		current->next = NULL;
		free(current);
	}
}
