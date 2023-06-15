#include "lists.h"

/**
 * get_dnodeint_at_index - get nth node of a dlistint_t doubly linked list
 * @head: the pointer to the head of linked list
 * @index: the to be returned
 * Return: the node at given index, or NULL if node does not exist
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;/*pointer to traverse the list*/
	unsigned int i;/*variable to keep track of the current index*/

	current = head;/*start from the head of the list*/

	/*travrse list untl reching the desired indx or the end of list*/
	for (i = 0; current && i < index; current = current->next, i++)
		;/*empty loop body*/

	return (current);/*retrn nodeat gven indx,or NUll if doesn't exist*/
}
