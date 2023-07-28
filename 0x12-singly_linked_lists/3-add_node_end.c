#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new
 * @head: double
 * @str: string to put in the new node
 * Return: address,NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp = *head;
	unsigned int le = 0;

	while (str[le])
		le++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = le;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}
