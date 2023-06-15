#include "lists.h"

/**
 * add_dnodeint -add a new node at the beginning of a dlistint_t list
 * @head: double pointer to head node
 * @n: value to store in node
 * Return: address of new node, or NULL if failed
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *current_head, *new_node;

	current_head = *head;/*store the currnt head in a tmp varble*/
	new_node = malloc(sizeof(dlistint_t));/*alocate memory for new node*/

	if (new_node == NULL)
		return (NULL);/*return NULL if memory alocation faled*/

	new_node->n = n;/*assign the value to the new node*/
	new_node->prev = NULL;/*set the prvs pointr of  new node to NULL*/

	/*if crrent head is NULL, set nxt pointr of new node to NULL as well*/
	if (current_head == NULL)
		new_node->next = NULL;

	else
	{
		/*traverse the list to find the first node (head node)*/
		while (current_head->prev)
			current_head = current_head->prev;

		/*set the prvous pontr of the first node to the new node*/
		current_head->prev = new_node;
		/*set the next pointer of the new node to the first node*/
		new_node->next = current_head;
	}
	*head = new_node;/*update the head to point to the new node*/

	return (*head);/*return the new head node*/
}
