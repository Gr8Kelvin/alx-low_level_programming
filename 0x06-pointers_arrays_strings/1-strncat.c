#include "main.h"
/**
 *_strncat - function
 *@dest: destination
 *@src: destination
 *@n: number of bytes
 *Return: pointer to destination
 */

char *_strncat(char *dest, char *src, int n)
{
	int length, z;

	length = 0;

	while (dest[length] != '\0')
	{
		length++;
	}
	for (z = 0; z < n && src[z] != '\0'; z++, length++)
	{
		dest[length] = src[z];
	}
	dest[length] = '\0';
	return (dest);
}
