#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - the define function to free listint_t
 * @h: a double pointer argument to the head
 * Return: the size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
	size_t total = 0;
	listint_t *pos, *tmp;

	tmp = *h;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		pos = tmp;
		total++;
		free(pos);

		if (pos < tmp)
			break;
	}

	*h = NULL;

	return (total);
}
