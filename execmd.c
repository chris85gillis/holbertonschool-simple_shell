#include "main.h"

/**
 * execmd - execute a given command.
 * @argv: a pointer to an array of strings.
 *
 * Return: NULL
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		/* Get the command */
		command = argv[0];

		/* Generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		/* Execute the actual command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:\n");
		}
	}
}
