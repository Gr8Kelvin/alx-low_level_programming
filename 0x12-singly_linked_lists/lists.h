#ifndef LISTS_H
#define LISTS_H

/**
 * struct list_s - single
 * @str: string - malloc
 * @len: length
 * @next: point
 * Description: singly linked list
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);

#endif

