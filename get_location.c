#include "main.h"

/**
 * duplicate_string - Duplicate a string using malloc.
 * @str: The string to duplicate.
 *
 * Return: The duplicated string.
 */
char *duplicate_string(const char *str)
{
	char *duplicate = malloc(strlen(str) + 1);
	if (duplicate)
		strcpy(duplicate, str);
	return duplicate;
}

/**
 * build_file_path - Build the full file path.
 * @path: The directory path.
 * @command: The command name.
 *
 * Return: The constructed file path.
 */
char *build_file_path(const char *path, const char *command)
{
	char *file_path;
	file_path = malloc(strlen(path) + strlen(command) + 2);
	if (file_path)
	{
		strcpy(file_path, path);
		strcat(file_path, "/");
		strcat(file_path, command);
	}
	return file_path;
}

/**
 * find_command_location - Find the location of a given command.
 * @path: The PATH environment variable.
 * @command: The name of the command.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *find_command_location(const char *path, const char *command)
{
	struct stat buffer;
	char *path_copy = duplicate_string(path);
	if (!path_copy)
		return NULL;

	const char *delim = ":";
	char *path_token = strtok(path_copy, delim);
	char *file_path;

	while (path_token)
	{
		file_path = build_file_path(path_token, command);
		if (!file_path)
			continue;

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return file_path;
		}
		free(file_path);
		path_token = strtok(NULL, delim);
	}

	free(path_copy);

	if (stat(command, &buffer) == 0)
		return duplicate_string(command);

	return NULL;
}

/**
 * get_location - Find the path of a given command.
 * @command: The name of the command.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_location(char *command)
{
	char *path = getenv("PATH");
	if (path)
		return find_command_location(path, command);

	return NULL;
}
