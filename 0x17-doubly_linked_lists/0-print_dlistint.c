#include "lists.h"

/**
 * print_dlistint - prints all the elements
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int con;

	con = 0;

	if (h == NULL)
		return (con);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		con++;
		h = h->next;
	}

	return (con);
}
