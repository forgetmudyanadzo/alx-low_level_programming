#include "lists.h"

/**
 * sum_listint - sum all integers in a listint_t list
 * @head: pointer to the head of the list
 * Return: sum of integers in list
*/

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
