#include "main.h"

/**
 * _memcpy - function
 * @n: function copies
 * @src: bytes
 * @dest: to memory
 * Return: a pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
