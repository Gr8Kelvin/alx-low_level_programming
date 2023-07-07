#include "main.h"
/**
 * _memcpy - function
 * @dest: memory
 * @src: memory
 * @n: nnumber of bytes
 * Return: copied memory
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
