#include "main.h"

/**
 * create_file - create a file with rw------- access
 * @filename: name of file to create,if NULL, retun -1
 * @text_content: string to write to file,if NULL create empty file
 * Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
	int fd, text_len, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		text_len = write(fd, text_content, i);

		if (text_len == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
