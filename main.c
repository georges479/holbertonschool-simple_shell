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
		write(STDOUT_FILENO, "$ ", 2);
		line = read_input();
		if (line[0] == '\0')
			continue;
		else if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		cmd_count++;
		execute_command(line, cmd_count);
	}
	free(line);
	return (0);
}
