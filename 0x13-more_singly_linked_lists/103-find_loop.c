#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - the defined function to find the loop
 * @head: the argument head of the linked list
 * Return: the address of the node where the starts, or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp, *pos;

	if (head == NULL)
		return (NULL);

	tmp = pos = head;
	
	do{
		if (tmp->next)
			tmp = tmp->next;
		
		else
			return (NULL);

		if (pos->next->next)
			pos = pos->next->next;

		else
			return (NULL);
	}

	while (pos != tmp);
		tmp = head;

	while (pos != tmp)
	{
		pos = pos->next;
		tmp = tmp->next;
	}

	return (tmp);
}
