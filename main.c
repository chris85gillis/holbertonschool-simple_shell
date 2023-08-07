#include "main.h"

/**
 * read_command - Read a command from the user.
 *
 * Return: The entered command.
 */
char *read_command(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;

	printf("(SimShell) $ ");
	nchars_read = getline(&lineptr, &n, stdin);

	if (nchars_read == -1)
	{
		printf("Exiting shell....\n");
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

/**
 * tokenize_command - Tokenize a command string into arguments.
 * @command: The command string to tokenize.
 *
 * Return: An array of argument strings.
 */
char **tokenize_command(char *command)
{
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	char **cmd_argv;
	int i = 0;

	token = strtok(command, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	cmd_argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(command, delim);

	for (i = 0; token != NULL; i++)
	{
		cmd_argv[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	cmd_argv[i] = NULL;

	return (cmd_argv);
}

/**
 * main - Entry point.
 * @ac: Number of command-line arguments passed to the program.
 * @cmd_argv: The command-line arguments provided to the program.
 *
 * Return: 0
 */
int main(int ac, char **cmd_argv)
{
	char *command;

	(void)ac;

	while (1)
	{
		command = read_command();

		if (command == NULL)
		break;

		cmd_argv = tokenize_command(command);

		if (cmd_argv == NULL)
		{
			free(command);
			continue;
		}

		if (strcmp(cmd_argv[0], "exit") == 0)
		{
			printf("Exiting shell....\n");
			break;
		}

		execmd(cmd_argv);

		free(command);
		free(cmd_argv);
	}

	return (0);
}
