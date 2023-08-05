#include "main.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
        	/* get the command */	
		command = argv[0];

        	/* generate the path to this command before passing it to execve */
        	actual_command = get_location(command);

	 	/* Create a child process using fork */
        	pid = fork();

        	if (pid == -1)
        	{
            		perror("Error in fork");
            		exit(EXIT_FAILURE);
        	}
        	else if (pid == 0) /* Child process */
        	{
        		/* execute the actual command with execve */
        		if (execve(actual_command, argv, NULL) == -1)
			{
            		perror("Error:");
        		}
    		}
		else /* Parent process (shell) */
		{
			/* Wait for child process to finish executing */
			waitpid(pid, &status, 0);
		}
	}

}
