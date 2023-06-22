#include "main.h"

/**
 * _isupper - Check for uppercase
 * @c: The character
 * Return: 1 uppercase
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
