#include "lists.h"

/**
 * pop_listint - deletes the node
 * @head: pointer to the first element
 * Return: the data inside the elements that was deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int z;

	if (!head || !*head)
		return (0);

	z = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (z);
}
