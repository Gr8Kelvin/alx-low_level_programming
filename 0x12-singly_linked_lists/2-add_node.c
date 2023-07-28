#include <string.h>
#include "lists.h"
#include <stdlib.h>

/**
 * add_node - adds a new node
 * @head: double pointer to the list_t list
 * @str: new string
 * Return: the address
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int le = 0;

	while (str[le])
		le++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = le;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
