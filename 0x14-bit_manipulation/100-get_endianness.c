#include "main.h"

/**
 * get_endianness - little or big endian
 * Return: 0 big, 1 little
 */
int get_endianness(void)
{
	unsigned int z = 1;
	char *c = (char *) &z;

	return (*c);
}
