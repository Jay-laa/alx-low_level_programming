#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *output_file);
void close_file(int file_descriptor);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @output_file: The name of the output file that the buffer will be used for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *output_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", output_file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @file_descriptor: The file descriptor to be closed.
 */
void close_file(int file_descriptor)
{
	int close_result;

	close_result = close(file_descriptor);

	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_result, write_result;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	read_result = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || read_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_result = write(file_to, buffer, read_result);

		if (file_to == -1 || write_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_result = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_result > 0);

	free(buffer);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
