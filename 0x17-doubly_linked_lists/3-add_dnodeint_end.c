#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * @head: head
 * @n: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *hr;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	hr = *head;

	if (hr != NULL)
	{
		while (hr->next != NULL)
			hr = hr->next;
		hr->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = hr;

	return (new);
}
