#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * Return: Always return 0 (Success)
 */
int main(void)
{
	char a;

	for (a = '0'; a <= '9'; a++)
	{
		putchar(a);
	}

	for (a = 'a'; a <= 'f'; a++)
	{
		putchar(a);
	}

	putchar('\n');

	return (0);
}
