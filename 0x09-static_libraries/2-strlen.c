#include "main.h"
/**
 * _strlen - returns
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int lonig = 0;

	while (*s != '\0')
	{
		lonig++;
		s++;
	}

	return (lonig);
}
