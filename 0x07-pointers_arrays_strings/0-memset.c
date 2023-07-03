#include "main.h"

/**
 * *_memset - function
 * @s: memory area
 * @b: char to copy
 * @n: number of times
 *
 * Return: pointer to memory
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
