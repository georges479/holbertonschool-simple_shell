#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	int cmd_count = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		line = read_input();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}

		if (line[0] == '\0' || only_spaces(line))
		{
			free(line);
			continue;
		}

		cmd_count++;
		execute_command(line, cmd_count);
		free(line);
	}
	return (0);
}
