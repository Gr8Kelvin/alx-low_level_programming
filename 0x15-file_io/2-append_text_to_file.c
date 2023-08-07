#include "main.h"

/**
 * append_text_to_file - Appends text
 * @filename: A pointer
 * @text_content: The string
 * Return: -1 otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int outd, wxw, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	outd = open(filename, O_WRONLY | O_APPEND);
	wxw = write(outd, text_content, len);

	if (outd == -1 || wxw == -1)
		return (-1);

	close(outd);

	return (1);
}
