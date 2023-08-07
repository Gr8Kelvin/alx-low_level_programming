#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file
 * @filename: text file
 * @letters: letters
 * Return: w- or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fdef;
	ssize_t wes;
	ssize_t tax;

	fdef = open(filename, O_RDONLY);
	if (fdef == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	tax = read(fdef, buf, letters);
	wes = write(STDOUT_FILENO, buf, tax);

	free(buf);
	close(fdef);
	return (wes);
}
