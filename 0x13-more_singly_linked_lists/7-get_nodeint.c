#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of the list
 * @head: head of the list
 * @index: index to retrieve node from
 * Return: pointer to the nth node
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	n = 0;
	while (n < index)
	{
		if (head ->next == NULL)
			return (NULL);
		head = head->next;
		n++;
	}
	return (head);
}
