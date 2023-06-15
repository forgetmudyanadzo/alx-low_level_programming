#include "lists.h"

/**
 * insert_dnodeint_at_index - insrt new node at gven pstn in doubly lnked list
 * @h: double pointer to the head of the list
 * @idx: index to insert into
 * @n: value to store in new node
 * Return: Address of the new node, or NULL if failed
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *newNode;

	newNode = malloc(sizeof(dlistint_t));/*alocate mmory for new node*/
	if (!newNode)
		return (NULL);
	newNode->n = n;
	current = *h;
	if (!current)
	{
		newNode->prev = NULL;
		newNode->next = NULL;
		*h = newNode;
		return (newNode);
	}
	if (idx == 0)
	{
		newNode->prev = NULL;
		newNode->next = current;
		current->prev = newNode;
		*h = newNode;
		return (newNode);
	}
	for (; idx > 1 && current->next; idx--)
		current = current->next;
	if (idx > 1 && !current->next)
		return (NULL);
	newNode->prev = current;
	newNode->next = current->next ? current->next : NULL;
	if (current->next)
		current->next->prev = newNode;
	current->next = current->next && idx > 1 ? NULL : newNode;
	return (newNode);
}
