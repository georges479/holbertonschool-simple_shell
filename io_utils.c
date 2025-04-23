#include "simple_shell.h"

/**
 * print_prompt - Display the shell prompt
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	fflush(stdout);
}

/**
 * read_command - Read a command from stdin
 * @lineptr: Pointer to the line buffer
 * @n: Pointer to the size of the buffer
 *
 * Return: Number of characters read or -1 on failure/EOF
 */
ssize_t read_command(char **lineptr, size_t *n)
{
	return (getline(lineptr, n, stdin));
}

/**
 * get_command - Extract and duplicate command from input line
 * @line: Input line
 *
 * Return: Pointer to duplicated command or NULL on failure
 */
char *get_command(char *line)
{
	char *command;

	command = strdup(line);
	if (command == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	return (command);
}
