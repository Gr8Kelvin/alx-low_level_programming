#include "main.h"

/**
 * flip_bits - number of bits to change
 * @n: first number
 * @m: second number
 * Return: bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, co = 0;
	unsigned long int cur;
	unsigned long int exclusive = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		cur = exclusive >> a;
		if (cur & 1)
			co++;
	}

	return (co);
}
