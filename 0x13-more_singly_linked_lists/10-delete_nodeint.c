#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete node at given index
 * @head: double header to the linked list
 * @index: index to delete
 * Return: 1if success, -1 if failed
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *hold = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}

	hold = temp->next;
	temp->next = hold->next;
	free(hold);

	return (1);
}
