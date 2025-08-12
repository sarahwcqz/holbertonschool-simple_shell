#include "header.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @av: arguments given by user
 * Return: always 0.
 */
int main(int ac, char **av)
{
	char *line;
	size_t n = 0;
	char *next;

	(void)ac;
	(void)av;

	printf("$ ");
	getline(&line, &n, stdin);
	next = strtok(line, " ");

	while (next != NULL)
	{
		printf("%s", next);
		next = strtok(NULL, " ");
		if (next != NULL)
			printf("\n");
	}

	free(line);
	return (0);
}
