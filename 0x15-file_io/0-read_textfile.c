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
	char *uf;
	ssize_t def;
	ssize_t wes;
	ssize_t tax;

	def = open(filename, O_RDONLY);
	if (def == -1)
		return (0);
	uf = malloc(sizeof(char) * letters);
	tax = read(def, uf, letters);
	wes = write(STDOUT_FILENO, uf, tax);

	free(uf);
	close(def);
	return (wes);
}
