#include "lists.h"

/**
 * sum_listint - sum of all the data
 * @head: first node
 * Return: total sum
 */
int sum_listint(listint_t *head)
{
	int abc = 0;
	listint_t *temp = head;

	while (temp)
	{
		abc += temp->n;
		temp = temp->next;
	}

	return (abc);
}
