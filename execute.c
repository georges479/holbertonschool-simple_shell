#include "shell.h"

/**
 * execute - executes a command
 * @args: array of arguments
 * @info: shell info struct
 *
 * Return: 1 to continue, 0 to exit
 */
int execute(char **args, info_t *info)
{
	int i;
	builtin_t builtins[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (args[0] == NULL)
		return (1);

	/* Check for built-in commands */
	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].func(args, info));
	}

	/* Execute external command */
	return (execute_command(args, info));
}

/**
 * execute_command - executes an external command
 * @args: array of arguments
 * @info: shell info struct
 *
 * Return: 1 to continue, 0 to exit
 */
int execute_command(char **args, info_t *info)
{
	pid_t pid;
	int status;
	char *cmd_path;

	/* Get full path of the command */
	cmd_path = get_cmd_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", info->name,
				info->line_count, args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(cmd_path, args, environ) == -1)
		{
			perror(info->name);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Fork error */
		perror(info->name);
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(cmd_path);
	return (1);
}

/**
 * get_cmd_path - gets the full path of a command
 * @cmd: the command name
 *
 * Return: full path of command or NULL if not found
 */
char *get_cmd_path(char *cmd)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	/* If command contains '/', assume it's a path */
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (stat(cmd, &buffer) == 0)
			return (_strdup(cmd));
		return (NULL);
	}

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	cmd_len = _strlen(cmd);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		dir_len = _strlen(path_token);
		file_path = malloc(cmd_len + dir_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}

		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}

	free(path_copy);
	return (NULL);
}
