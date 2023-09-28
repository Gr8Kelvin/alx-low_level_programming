#include "main.h"

/**
 * binary_to_uint - binary number to unsigned int
 * @b: string
 * Return: number
 */
unsigned int binary_to_uint(const char *b)
{
	int yes;
	unsigned int d_value = 0;

	if (!b)
		return (0);

	for (yes = 0; b[yes]; yes++)
	{
		if (b[yes] < '0' || b[yes] > '1')
			return (0);
		d_value = 2 * d_value + (b[yes] - '0');
	}

	return (d_value);
}
