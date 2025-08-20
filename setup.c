#include "simple_shell.h"

/**
 * setup - reads the line from the stdin and tokenizes it
 * @argv: arguments given by user
 * @buff: where getline stores argv
 * Return: pointer to tokenized argument line
 */
char **setup(char *argv[], char **buff)
{
	size_t index = 0, taille_buff = 0, max_arg = 64;
	char *next, **cmd_line = NULL;
	(void)argv;

	printf("-> ");

	if (getline(buff, &taille_buff, stdin) == -1)
		return (NULL);

	cmd_line = malloc(sizeof(char *) * max_arg);
	next = strtok(*buff, " \t\n");
	if (next == NULL)
	{
		cmd_line[0] = NULL;
		return (cmd_line);
	}
	while (next != NULL)
	{
		cmd_line[index] = next;
		index++;
		next = strtok(NULL, " \t\n");
	}
	cmd_line[index] = NULL;

	return (cmd_line);
}
