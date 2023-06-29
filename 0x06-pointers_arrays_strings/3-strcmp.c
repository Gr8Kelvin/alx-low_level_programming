#include "main.h"
/**
 * _strcmp - compares 2 strings
 *@s1: pointer
 *@s2: pointer
 *Return: greater, less or equal to 0
 */

int _strcmp(char *s1, char *s2)
{
	int count, compare;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0')
	{
		count++;
	}

	compare = s1[count] - s2[count];
	return (compare);
}

