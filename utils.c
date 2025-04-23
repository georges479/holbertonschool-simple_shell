#include "shell.h"

/**
 * read_input - Reads a line from stdin
 *
 * Return: Pointer to the line (must be freed), or NULL on EOF
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * execute_command - Creates a child process and executes the command
 * @cmd_count: count the line of the command
 * @line: The command to execute
 */
void execute_command(char *line, int cmd_count)
{
	pid_t pid;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;

		execve(line, argv, environ);

		dprintf(STDERR_FILENO, "./hsh: %d: %s: not found\n", cmd_count, line);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * _strcmp - Compares two strings
 * @string_a: First string to compare
 * @string_b: Second string to compare
 *
 * Return: 0 if equal, difference between first non-matching
 * characters otherwise
 */
int _strcmp(const char *string_a, const char *string_b)
{
	int i = 0;

	while (string_a[i] && string_b[i])
	{
		if (string_a[i] != string_b[i])
			return (string_a[i] - string_b[i]);
		i++;
	}
	return (string_a[i] - string_b[i]);
}

/**
 * only_spaces - Checks if a string contains only spaces
 * @line: The input string
 *
 * Return: 1 if only spaces or empty, 0 otherwise
 */
int only_spaces(const char *line)
{
	int i;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);

		i++;
	}
	return (1);
}
