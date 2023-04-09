#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 * @ac: argument count
 * @av: argument as array
 * Return: 0
*/

int main(int ac, char *av[])
{
	int input_fd, output_fd, istatus, ostatus;
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
	char buffer[BUFSIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	input_fd = open(av[1], O_RDONLY);

	if (input_fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	output_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, perm);

	if (output_fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	istatus = 1;
	while (istatus)
	{
		istatus = read(input_fd, buffer, BUFSIZE);
		if (istatus == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
		if (istatus > 0)
		{
			ostatus = write(output_fd, buffer, istatus);
			if (ostatus != istatus || ostatus == -1)
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
		}
	}
	if (close(input_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", input_fd), exit(100);
	if (close(output_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", output_fd), exit(100);

	return (0);
}
