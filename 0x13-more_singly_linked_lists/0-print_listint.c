#include "lists.h"

/**
 * print_listint - prints
 * @h: listint_t to print
 * Return: nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t z = 0;

	while (h)
	{
		printf("%d\n", h->n);
		z++;
		h = h->next;
	}

	return (z);
}
