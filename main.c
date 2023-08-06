#include "main.h"

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

	/*declaring void variables */
	(void)ac;

	/*Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/*check if the getline function failed or reached */
		/*EOF or user used CTRL + D */
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			break;
			/*Exit the loop instead of returning */
			/*from the main function */
		}

		/*Allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read + 1);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/*copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);
		/*split the string (lineptr) into an array of words */
		/*calculate the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/*Allocate space to hold the array of strings */
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
			/*Exit the loop instead of executing the command */
		}

		/*execute the command */
		execmd(argv);

		/*free up allocated memory */
		free(lineptr_copy);
		free(lineptr);
	}

	return (0);
}
