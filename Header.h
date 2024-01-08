#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

char *get_user_input(void);
char **tokenize_input(char *input);
int execute_input(char **command, char *envp[]);
void show_prompt(void);
#endif

