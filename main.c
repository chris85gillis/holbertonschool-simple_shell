#include "main.h"

/* main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char *prompt = "(SimShell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;
	const int max_tokens = 100;

	char **tokens = malloc(sizeof(char *) * max_tokens);
		if (tokens == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
	
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
		num_tokens = 0;

		while (token != NULL && num_tokens < max_tokens)
		{
			tokens[num_tokens] = strdup(token);
			if (tokens[num_tokens] == NULL)
			{
				perror("tsh: memory allocation error");
				return (-1);
			}
			num_tokens++;
			token = strtok(NULL, delim);
		}
		tokens[num_tokens] = NULL;
		if (tokens[0] && strcmp(tokens[0], "exit") == 0)
		{
			printf("Exiting shell....\n");
			break;
		}
		execmd(tokens);

		for (i = 0; i < num_tokens; i++)
		{
			free(tokens[i]);
			tokens[i] = NULL;
		}
		free(tokens);
		free(lineptr_copy);
		lineptr_copy = NULL;
	}
free(lineptr);
return (0);
}
