#include "main.h"

/**
 * print_rev - function to print
 * @s: string
 * Return: 0
 */

void print_rev(char *s)
{
	int start = 0;

	while (s[start])
		start++;
	while (start--)
		_putchar(s[start]);
	_putchar('\n');
}
