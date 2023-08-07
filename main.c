#include "main.h"

/**
 * main - entry point
 * @ac: number of command-line arguments passed to the program.
 * @argv: the command-line arguments provided to the program.
 *
 * Return: 0
 */

int main(int ac, char **argv)
{
	char *prompt = "(SimShell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)ac;

	/*Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/*Check if the function worked or not */

		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			break;
			/*Exit loop */
		}

		/*Make space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read + 1);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_copy, lineptr);
		/*Split the string into an array */
		/*Calculate the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/*Make space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);

		/*Store each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/*Check for the exit command */
		if (strcmp(argv[0], "exit") == 0)
		{
			printf("Exiting shell....\n");
			break;
		}

		execmd(argv);

		free(lineptr_copy);
		free(lineptr);
	}

	return (0);
}
