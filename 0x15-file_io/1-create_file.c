#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer
 * @text_content: A pointer
 * Return:  -1 - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fdef, wye, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fdef = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wye = write(fdef, text_content, len);

	if (fdef == -1 || wye == -1)
		return (-1);

	close(fdef);

	return (1);
}
