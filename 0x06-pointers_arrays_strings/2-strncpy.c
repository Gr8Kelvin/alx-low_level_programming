#include "main.h"
/**
 *_strncpy - function
 * @dest: destination
 *@src: source
 *@n: number of bytes
 *Return: pointer to destination
 */

char *_strncpy(char *dest, char *src, int n)
{
	int count;

		for (count = 0; count < n && src[count] != '\0'; count++)
			dest[count] = src[count];

	for (; count < n; count++)
		dest[count] = '\0';

	return (dest);
}
