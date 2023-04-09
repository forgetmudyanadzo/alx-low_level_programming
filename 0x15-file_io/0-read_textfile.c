#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and print to POSIX standard output
 * @filename: name of the file, if NULL, return 0
 * @letters: number of letters to read and print
 * Return: number of letters it could read and print, or 0 if error
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_read, bytes_written;
	int fd;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDWR);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
	{
		free(buf);
		return (0);
	}

	bytes_read = read(fd, buf, letters);

	if (bytes_read == -1)
		return (0);

	bytes_written = write(STDOUT_FILENO, buf, bytes_read);

	if (bytes_written == -1 || bytes_read != bytes_written)
		return (0);

	free(buf);

	close(fd);
	return (bytes_written);
}
