#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 byte
 * @file: name of file buffer
 * Return: A pointer
 */
char *create_buffer(char *file)
{
	char *bufed;

	bufed = malloc(sizeof(char) * 1024);

	if (bufed == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bufed);
}

/**
 * close_file - Closes file
 * @fd: The file descriptor
 */

void close_file(int fd)
{
	int cats;

	cats = close(fd);

	if (cats == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file
 * @argc: The number of arguments
 * @argv: An array of pointers
 * Return: 0 on suc
 * Description:  97 or 98 or 99 or 100.
 */
int main(int argc, char *argv[])
{
	int frm, tops, rgt, wts;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	frm = open(argv[1], O_RDONLY);
	rgt = read(frm, buffer, 1024);
	tops = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || rgt == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wts = write(tops, buffer, rgt);
		if (tops == -1 || wts == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rgt = read(frm, buffer, 1024);
		tops = open(argv[2], O_WRONLY | O_APPEND);

	} while (rgt > 0);

	free(buffer);
	close_file(frm);
	close_file(tops);

	return (0);
}

