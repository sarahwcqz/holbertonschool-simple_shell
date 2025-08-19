#include "simple_shell.h"

/**
 * setup - reads the line from the stdin and tokenizes it
 * @argv: arguments given by user
 * @buff: where getline stores argv
 * Return: pointer to tokenized argument line
 */
char **setup(char *argv[], char **buff)
{
	char *next;
	size_t index = 0, taille_buff = 0;

	printf("prompt everytime\n");
	printf("-> ");

	if (getline(buff, &taille_buff, stdin) == -1)
		return (NULL);

	next = strtok(*buff, " \t\n");
	if (next == NULL)
	{
		argv[0] = NULL;
		return (argv);
	}
	while (next != NULL)
	{
		argv[index] = next;
		index++;
		next = strtok(NULL, " \t\n");
	}
	argv[index] = NULL;

	return (argv);
}
