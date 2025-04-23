#include "simple_shell.h"

/**
 * main - Simple shell implementation
 *
 * Return: 0 on success
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;
	char *command;

	while (1)
	{
		/* Display prompt */
		print_prompt();

		/* Read command from stdin */
		nread = read_command(&lineptr, &n);

		/* Handle "end of file" condition (Ctrl+D) */
		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline character */
		if (lineptr[nread - 1] == '\n')
			lineptr[nread - 1] = '\0';

		/* Skip empty lines */
		if (strlen(lineptr) == 0)
			continue;

		/* Get command from line */
		command = get_command(lineptr);
		if (command == NULL)
			continue;

		/* Execute the command */
		execute_command(command);
		free(command);
	}

	/* Free allocated memory */
	free(lineptr);
	return (0);
}
