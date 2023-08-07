#include "main.h"

/* execmd - execute a given command.
 *
 * Return: NULL
 */

void execmd(char **cmd_argv)
{
	char *command = NULL, *actual_command = NULL;

	if (cmd_argv)
	{
		/* get the command */
		command = cmd_argv[0];

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		/* execute the actual command with execve */
		if (execve(actual_command, cmd_argv, NULL) == -1)
			perror("Error:\n");
		}
	}
}
