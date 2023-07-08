#include <stdio.h>
#include "main.h"

/**
 * main - print the number of arguments
 * @argc: number
 * @argv: array
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
