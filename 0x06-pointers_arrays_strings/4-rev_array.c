#include "main.h"
/**
 *reverse_array - function
 *@a: pointer
 *@n: number of elements
 *Return: void
 */

void reverse_array(int *a, int n)
{
	int temp, c;

	n = n - 1;
	c = 0;
	while (c <= n)
	{
		temp = a[c];
		a[c++] = a[n];
		a[n--] = temp;
	}
}
