#include "main.h"

/**
 * _strlen - Checks length
 * @s: string
 * Return: the length
 */

int _strlen(char *s)
{
	int string_len = 0;

	while (s[string_len])
		string_len++;
	return (string_len);
}
