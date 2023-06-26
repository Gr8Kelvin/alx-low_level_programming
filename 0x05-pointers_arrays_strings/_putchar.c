#include <unistd.h>

/**
 * _putchar - writes a character
 * @c: The character
 *
 * Return: successs 1
 * on error, -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
