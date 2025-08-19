#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

char **setup(char *argv[], char **buff);
int _fork(int id, char **argv, char *prgm_name);
int checkarg(char **argv);
void pr_env(void);
char *get_path(char **argv);
char *get_dir(char **argv);
char *_getenv(const char *name);

#endif
