#include "main.h"

/**
 * print_binary - prints
 * @n: number
 */
void print_binary(unsigned long int n)
{
	int a, co = 0;
	unsigned long int cur;

	for (a = 63; a >= 0; a--)
	{
		cur = n >> a;

		if (cur & 1)
		{
			_putchar('1');
			co++;
		}
		else if (co)
			_putchar('0');
	}
	if (!co)
		_putchar('0');
}
