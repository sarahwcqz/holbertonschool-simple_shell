#include "simple_shell.h"

/**
 * setup - makes our shell pretty
 * @argv: arguments given by user
 * @buff: where getline stores argv
 * Return: pointer to argument line
 */
char **setup(char *argv[], char *buff)
{
	char *next;
	size_t i = 0, n = 0;

	printf("prompt\n");
	printf("-> ");

		if (getline(&buff, &n, stdin) == -1)
		{
			free(buff);
			return (NULL);
		}
		next = strtok(buff, " \t\n");
		while (next != NULL)
		{
			argv[i] = next;
			i++;
			next = strtok(NULL, " \t\n");
		}
		argv[i] = NULL;

	return (argv);
}
