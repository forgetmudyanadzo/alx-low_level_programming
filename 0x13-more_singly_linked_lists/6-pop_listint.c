#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * @head: head of the list
 * Return: head nodes data n
*/

int pop_listint(listint_t **head)
{
	int temp;
	listint_t *next_node = NULL;

	if (*head == NULL)
	{
		return (0);
	}
	next_node = (*head)->next;
	temp = (*head)->n;
	free(*head);
	*head = next_node;

	return (temp);
}
