#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PROMPT "$ "
#define BUFFER_SIZE 1024

/* Function prototypes */
void print_prompt(void);
ssize_t read_command(char **lineptr, size_t *n);
char *get_command(char *line);
void execute_command(char *command);
char *find_command_in_path(char *command);
int command_exists(char *command);
void fork_and_execute(char *path);

extern char **environ;

#endif /* SIMPLE_SHELL_H */
