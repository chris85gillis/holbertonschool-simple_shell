Simple Shell (aka SimShell)
=======

The project's code consists of three C files (execmd.c, get_location.c, and main.c) and a header file (main.h). It is a simple implementation of a shell-like program that takes user input, parses the input into commands and arguments, and then executes the specified command using the execve system call.

Project Description
-----------

**1. execmd.c**
  
This file contains the execmd function, responsible for executing a given command with its arguments using execve. The execmd function takes a 2D array of strings (char **argv) as input, where the first element (argv[0]) is the command to be executed, and the rest of the elements are arguments to that command.

**2. get_location.c**

This file contains the get_location function, which is used by execmd to find the actual path of a command before executing it. The get_location function takes a command as input and searches for its location in the system's PATH variable. If the command is found, the function returns the full path to the command; otherwise, it returns NULL.

**3. main.c**

This file contains the main function of the program, which is the entry point. It implements a simple shell-like interface, taking user input and executing the specified commands using the functions defined in Execmd.c and get_location.c.

**4. main.h**

This header file contains the function declarations for execmd and get_location. It also includes necessary header files for the code to function correctly.

How to Install
-----------

The best way to install this program is to go into your terminal. First you'll have to navigate to the folder where you want your clone of the repository. Then type in the command 'git clone  https://github.com/chris85gillis/holbertonschool-simple_shell.git' and hit enter. The cloning process with start. Now go to your github desktop interface, from the menu, select file 'Clone a repositroy', browse to the destination folder and paste the URL you copied before in the box labeled 'Repository URL', and then click 'Clone'. You can also view the files and contents of this project at: https://github.com/chris85gillis/holbertonschool-simple_shell

How to Use
-----------

Once you have the repo cloned, installed and are in the actual repository you can run it by entering './hsh'. This will start up our simple shell and give you access to do a few different options. (echo, exit, ls, ls -l, ls -l -a, ls /var) Unfortunatly, we were not able to make our Shell stay open after entering any command. So after the user input it automatically kicks you out of the SimShell. 

![SimShell Example](https://github.com/chris85gillis/holbertonschool-simple_shell/assets/126268722/645ee484-d816-47a0-bef9-9d3f79f1fe7d)

Code Visualization
-----------

This visualization of our code shows how each function currently works with each other. Because we were not able to finsish this project in time it is not a fully fleshed out program but this should give you an idea of what we have at the moment.

![Simple Shell Flowchart](https://github.com/chris85gillis/holbertonschool-simple_shell/assets/126268722/528b8a86-57a8-40f6-8438-798c0282eb0f)

Authors
-----------

Chris Gillis <chris85gillis@gmail.com>
/ Alyssa McNatt <alyssa.b.mcnatt@gmail.com>
