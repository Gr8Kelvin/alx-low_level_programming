#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node
 * @head: head of the list
 * @index: index
 * Return: nth node or null
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size;
	dlistint_t *temp;

	size = 0;
	if (head == NULL)
	return (NULL);

	temp = head;
	while (temp)
	{
	if (index == size)
	return (temp);
	size++;
	temp = temp->next;
	}
	return (NULL);
}
