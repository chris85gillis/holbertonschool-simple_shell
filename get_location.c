#include "main.h"

/**
 * get_location -  find the path of a given command.
 * @command: the name of the command for which you want to find the full path.
 *
 * Return: NULL
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		/*Duplicate the path string */
		path_copy = strdup(path);
		command_length = strlen(command);

		/*Get all the directories available*/
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			/*make memory for the command */
			file_path = malloc(command_length + directory_length + 2);
			/*NB: we added 2 for the slash and null character */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			/*test if this file path actually exists */
			if (stat(file_path, &buffer) == 0)
			/*return value of 0 means success */
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
		/*return NULL; need to free up memory */
		free(path_copy);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);

