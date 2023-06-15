#include "lists.h"

/**
 * add_dnodeint_end - add new node at the end of a dlistint_t list
 * @head: a double pointer to the head node
 * @n: the value to store in new node
 * Return: the address of new element, or NULL if failed
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current, *new_node;

	new_node = malloc(sizeof(dlistint_t));/*alocate mmory for new node*/

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;/*assign value and next pnter for new node*/
	new_node->next = NULL;

	current = *head;/*set curnt to point to head of list*/
	/*traverse the list until the last node*/
	while (current && current->next)
		current = current->next;

	if (current)
	{
		/*if lst not epty,setnew nods prev ptr to crnt & crnt nxt ptr to new*/
		new_node->prev = current;
		current->next = new_node;
	}
	else
	{
		/*if list is epty,updte headto ptr to newnod &set new prev ptr to NULL*/
		*head = new_node;
		new_node->prev = NULL;
	}
	return (new_node);/*return the address of new element (new node)*/
}
