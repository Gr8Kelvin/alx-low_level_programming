#include "main.h"

/**
 * _islower - Checks for lowercse character
 * @c: The character to be checked
 * Return: 1 for lowercse character or 0 for anything else
 */

int _islower(int c)
{
if (c >= 97 && c <= 122)
{
	return (1);
}
return (0);
}
