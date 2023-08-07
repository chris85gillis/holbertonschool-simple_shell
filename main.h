#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void execmd(char **argv);
char *get_location(char *command);
char *read_command(void);
char **tokenize_command(char *lineptr);
int execmd(char **argv);
char *duplicate_string(const char *str);
char *build_file_path(const char *path, const char *command);
char *find_command_location(const char *path, const char *command);

#endif
