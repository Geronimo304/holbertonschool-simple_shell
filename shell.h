#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(void);
int execute_command(char *command);
int is_exit(char *command);

extern char **environ;

#endif /* SHELL_H */
