#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - append text to a file
 * @filename: name of file
 * @text_content: string to add at the end of the file
 * Return: 1 on success, -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, status, i;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	fd = open(filename, O_APPEND | O_WRONLY);

	if (fd == -1)
		return (-1);

	for (status = 0; text_content[status]; status++)
		;
	i = write(fd, text_content, status);

	close(fd);
	return (i == -1 ? -1 : 1);
}
