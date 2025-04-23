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

	if (line[nread - 1] == '\n')
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
