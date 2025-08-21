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

int _fork(int id, char **argv, char *prgm_name);
int checkarg(char **argv);
void pr_env(void);
char *get_path(char **argv, char *chemin);
char *_getenv(const char *name);

#endif
