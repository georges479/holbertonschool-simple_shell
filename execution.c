#include "simple_shell.h"

/**
 * execute_command - Execute a command with or without path
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *full_path;

	/* Check if command has full path */
	if (command[0] == '/' || command[0] == '.')
	{
		/* Command with full path */
		if (!command_exists(command))
		{
			printf("./simple_shell: No such file or directory\n");
			return;
		}
		fork_and_execute(command);
	}
	else
	{
		/* Try to find command in PATH */
		full_path = find_command_in_path(command);
		if (full_path == NULL)
		{
			printf("./simple_shell: %s: command not found\n", command);
			return;
		}
		fork_and_execute(full_path);
		free(full_path);
	}
}

/**
 * fork_and_execute - Fork process and execute command
 * @path: Path to the executable
 */
void fork_and_execute(char *path)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		return;
	}

	if (child_pid == 0) /* Child process */
	{
		/* Setup argv array */
		argv[0] = path;
		argv[1] = NULL;

		/* Execute command */
		if (execve(path, argv, environ) == -1)
		{
			perror("./simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		/* Wait for child to terminate */
		wait(&status);
	}
}
