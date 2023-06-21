#include "main.h"

/**
 * largest_number - returns 
 * @a: number
 * @b: number
 * @c: number
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
	int large;

	if (a > b && a > c)
	{
		large = a;
	}
	else if (a > b && c > a)
	{
		large = b;
	}
	else if (b > c)
	{
		large = b;
	}
	else
	{
		large = c;
	}

return (large);
}
