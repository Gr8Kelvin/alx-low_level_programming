#include "main.h"

/**
 * binary_to_uint - binary number to unsigned int
 * @b: string
 * Return: number
 */
unsigned int binary_to_uint(const char *b)
{
	int y;
	unsigned int d_val = 0;

	if (!b)
		return (0);

	for (y = 0; b[y]; y++)
	{
		if (b[y] < '0' || b[y] > '1')
			return (0);
		d_val = 2 * d_val + (b[y] - '0');
	}

	return (d_val);
}
