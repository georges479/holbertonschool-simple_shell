#include "simple_shell.h"

/**
 * find_command_in_path - Find a command in the PATH
 * @command: Command to find
 *
 * Return: Full path to command if found, NULL otherwise
 */
char *find_command_in_path(char *command)
{
	char *path_env, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	command_length = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(directory_length + command_length + 2);
		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (file_path);
		}

		free(file_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * command_exists - Check if a command exists and is executable
 * @command: Command with path to check
 *
 * Return: 1 if exists and executable, 0 otherwise
 */
int command_exists(char *command)
{
	struct stat buffer;

	if (stat(command, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		return (1);

	return (0);
}
