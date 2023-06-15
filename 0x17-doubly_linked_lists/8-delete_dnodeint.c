#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index of a dlistint_t linked list
 * @head: double pointer to the head of linked list
 * @index: index position to remove from linked list
 * Return: value of the node deleted
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *previous, *current;

	/*check if the head pointer or the list itself is empty*/
	if (!head || !*head)
		return (-1);

	/*set a current pointer to the head of the list*/
	current = *head;
	if (index == 0)/*if index is 0, delete the head node*/
	{
		*head = (*head)->next;/*update the head pointer to next node*/
		(*head)->prev = NULL;
		free(current);/*free the memory of previous head node*/
		return (1);/*to indcate success*/
	}
	/*iterat untl the node b4 the one to b deleted, or untl end of list reched*/
	for (; index > 1 && current && current->next; index--)
		current = current->next;

	/*if curent eached the end of list or the dsired indx is out of range*/
	if (!current->next)
		return (-1);

	previous = current->next;/*set a currnt ptr to the node to b dlted*/
	current->next = previous->next ? previous->next : NULL;
	if (previous->next)
		previous->next->prev = current;
	free(previous);/*free the memory of the node to be deleted*/

	return (1);/*to indicate success*/
}
