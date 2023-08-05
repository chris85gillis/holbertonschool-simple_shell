#include "main.h"

/* Function to handle the interactive mode */
void interactive_mode();

/* Function to handle the non-interactive mode */
void non_interactive_mode();

/* Function to execute the command */
void execute_command(char **argv);

/* Function to free allocated memory for argv */
void free_argv(char **argv, int num_tokens);

int main(void)
{
    if (!isatty(fileno(stdin)))
    {
        non_interactive_mode();
    }
    else
    {
        interactive_mode();
    }

    return 0;
}

void interactive_mode()
{
    char *prompt = "(SimShell) $ ";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    char *lineptr_copy = NULL;
    int i;

    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            break;
        }

        char *lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            break;
        }

        strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        **argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        if (strcmp(argv[0], "exit") == 0)
        {
            printf("Exiting shell....\n");
            break;
        }

        execute_command(argv);
        free_argv(argv, num_tokens);
        free(lineptr_copy);
    }

    free(lineptr);
}

void non_interactive_mode()
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    while ((nchars_read = getline(&lineptr, &n, stdin)) != -1)
    {
        char *lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            break;
        }

        strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        **argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        if (strcmp(argv[0], "exit") == 0)
        {
            printf("Exiting shell....\n");
            break;
        }

        execute_command(argv);
        free_argv(argv, num_tokens);
        free(lineptr_copy);
    }

    free(lineptr);
}

void execute_command(char **argv)
{
    // Implement your command execution logic here
    // For now, let's just print the command and arguments
    for (int i = 0; argv[i] != NULL; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}

void free_argv(char **argv, int num_tokens)
{
    for (int i = 0; i < num_tokens; i++)
    {
        free(argv[i]);
    }
    free(argv);
}
