#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;

	while (1)
	{
        	write(1, "$ ", 2);
		line = read_input();
		if (line == NULL)
		{
			write(1, "\n", 1);
			break;
		}
		execute_command(line);
		free(line);
	}
	return 0;
}
