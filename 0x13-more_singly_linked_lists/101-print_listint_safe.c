#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - the define function of print_listint_safe
 * @head: the argument of the print_listint_safe
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t total = 0;
	const listint_t *pos, *tmp;

	tmp = head;

	if (tmp == NULL)
		exit(98);

	while (tmp != NULL)
	{
		pos = tmp;
		tmp = tmp->next;
		total++;

		printf("[%p] %d\n", (void *)pos, pos->n);

		if (pos < tmp)
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
			break;
		}
	}

	return (total);
}
