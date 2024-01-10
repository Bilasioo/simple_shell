#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct input - struct for execve arguments
 * @argv: command arguments
 * @path: command pathname
 * @envp: command environment variables
 * @pathFlag: command pathname flag
 *
 */

typedef struct input
{
	char **argv;
	char **envp;
	char *path;
	int pathFlag;
} input_t;

char **cmd_arg(char *str);
char *_strcpy(char *dest, char *src);
char *absolute_path(char *cwd, char *dir);
char *to_strn(long int n);
char *_strcat(char *dest, char *src);
char *com_path(char *cmd_name);
char **path_find(char **env_p);
char *_getenv(const char *name);
char *com_search(char *name);
char *get_user_input(void);
char **tokenize_input(char *input);
int execute_input(char **command, char *envp[]);
int _getline(char **str, int *size, FILE *stream);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
input_t *get_input(char **env);
int _atoi(char *s);
void free_struct(input_t *f);
void _exiting(input_t *cmd);
void _env(input_t *cmd, char **env_p);
void _chdir(input_t *cmd);
void show_prompt(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
