#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
extern char **environ;
int main(void)
{
	char *line = NULL, *argv[2];
	size_t len = 0;
	ssize_t nread;
	pid_t pid;

	while (1)
	{
        	write(1, "$ ", 2);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("See you soon!\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

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
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return 0;
}
