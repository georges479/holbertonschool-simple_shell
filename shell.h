#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;
char *read_input(void);
void execute_command(char *line, int cmd_count);
int _strcmp(const char *sting_a, const char *string_b);
int only_spaces(const char *line);

#endif
