Simple Shell
=======

The project's code consists of three C files (Execmd.c, get_location.c, and main.c) and a header file (main.h). It is a simple implementation of a shell-like program that takes user input, parses the input into commands and arguments, and then executes the specified command using the execve system call. Let's go through each file and understand their functionality: 

Project Description
-----------

**1. execmd.c**
  
This file contains the execmd function, responsible for executing a given command with its arguments using execve. The execmd function takes a 2D array of strings (char **argument) as input, where the first element (argument[0]) is the command to be executed, and the rest of the elements are arguments to that command.

**2. get_location.c**

This file contains the get_location function, which is used by execmd to find the actual path of a command before executing it. The get_location function takes a command as input and searches for its location in the system's PATH variable. If the command is found, the function returns the full path to the command; otherwise, it returns NULL.

**3. main.c**

This file contains the main function of the program, which is the entry point. It implements a simple shell-like interface, taking user input and executing the specified commands using the functions defined in Execmd.c and get_location.c.

**4. main.h**
This header file contains the function declarations for execmd, get_location, and be_gone_betty. It also includes necessary header files for the code to function correctly.



![Simple Shell Flowchart](https://github.com/chris85gillis/holbertonschool-simple_shell/assets/126268722/528b8a86-57a8-40f6-8438-798c0282eb0f)
