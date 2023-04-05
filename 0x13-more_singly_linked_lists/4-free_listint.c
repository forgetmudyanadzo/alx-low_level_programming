#include "lists.h"
#include <stdlib.h>

/**
 * free_listint -  free a listint list
 * @head: head of the linked list
*/

void free_listint(listint_t *head)
{
	listint_t *hold;

	while (head != NULL)
	{
		hold = head->next;
		free_listint(head);
			free (hold);
	}
}
