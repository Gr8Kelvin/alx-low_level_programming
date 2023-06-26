#include "main.h"

/**
 * swap_int - take in 2 variables
 * @author Kelvin
 * @a: swaps address
 * @b: swaps address
 * Return: 0
 */

void swap_int(int *a, int *b)
{
	int cha;

	cha = *b;

	*b = *a;
	*a = cha;
}
