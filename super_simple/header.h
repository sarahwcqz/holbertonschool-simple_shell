#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern char **environ;
int print_path(void);
char **setup(char *argv[], char *buff);

/**
 * struct directory - directory from PATH
 * @prev: previous directory
 * @next: next directory
 * @pathdir: directory as a string
 *
 * Description: contains all directories from PATH
 * one per struct
 */
typedef struct directory
{
	struct directory *prev;
	struct directory *next;
	char *pathdir;
} dir;

#endif
