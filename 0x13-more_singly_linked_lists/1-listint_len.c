#include "lists.h"

/**
 * listint_len - number of elements in a linked lists
 * @h: listint_t to traverse
 * Return: nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t z = 0;

	while (h)
	{
		z++;
		h = h->next;
	}

	return (z);
}
