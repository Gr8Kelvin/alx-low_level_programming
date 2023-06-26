#include "main.h"

/**
 * rev_string - prints
 * @s: pointer pointing to string
 * Return: 0
 */

void rev_string(char *s)
{
	int length, a, b;
	char temp;

	for (length = 0; s[length] != '\0'; length++)
		;
	a = 0;
	b = length / 2;

	while (b--)
	{
		temp = s[length - a - 1];
		s[length - a - 1] = s[a];
		s[a] = temp;
		a++;
	}
}
