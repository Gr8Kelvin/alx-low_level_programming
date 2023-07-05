#include "main.h"

/**
 * _strlen_recursion - Returns length of a string
 * @s: string
 * Return: length of the string
 */

int _strlen_recursion(char *s)
{
	int lon = 0;

	if (*s)
	{
		lon++;
		lon += _strlen_recursion(s + 1);
	}

	return (lon)
}
