#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *read_line(void);
int execute_command(char *command);
int is_exit(char *command);
char *get_path(void);
char *find_command(char *command);

extern char **environ;

#endif /* SHELL_H */
